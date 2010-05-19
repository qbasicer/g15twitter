#include <cstdlib>
#include <cstdio>
#include "CanvasManager.hpp"
#include <poll.h>
#include <unistd.h>

extern "C" {
	void *keyHandlerThread(void *obj){
		CanvasManager *cm = (CanvasManager*)obj;
		int fd = cm->getFD();
		int keystate = 0;
		struct pollfd fds;
		char ver[5];
		strncpy(ver,G15DAEMON_VERSION,3);
		float g15v;
		sscanf(ver,"%f",&g15v);
	
		fds.fd = fd;
		fds.events = POLLIN;
	
		while(!cm->isQuitting()){
			keystate = 0;
			if((g15v*10)<=18) {
				keystate = g15_send_cmd (fd, G15DAEMON_GET_KEYSTATE, 0);
			} else {
				if ((poll(&fds, 1, 5)) > 0)
					read (fd, &keystate, sizeof (keystate));
			}
		
			if (keystate){
				if(cm->getKeyHandler()){
					cm->getKeyHandler()->G15HandleKeypress(keystate);
				}
			}
		}
		return NULL;
	}
}

CanvasManager::CanvasManager(){
	canvas = (g15canvas *) malloc (sizeof (g15canvas));
	memset(canvas->buffer, 0, G15_BUFFER_LEN);
	canvas->mode_cache = 0;
	canvas->mode_reverse = 0;
	canvas->mode_xor = 0;
	width = G15_LCD_WIDTH;
	height = G15_LCD_HEIGHT;
	g15screen_fd = new_g15_screen(G15_G15RBUF);
	keyHandler = NULL;
	quitflag = 0;
	
	int rc = pthread_create(&keyThread, NULL, keyHandlerThread, (void *)this);
	if (rc){
		exit(-1);
	}
	
}

CanvasManager::~CanvasManager(){
	void *status;
	quitflag = 1;
	printf("Shutting down.  Waiting for keyserver.\n");
	int rc = pthread_join(keyThread, &status);
	if(rc){
		printf("Shutting down.  Keyserver not down though.\n");
	}
	printf("Shutting down.  Keyserver is down.\n");
	
}

void CanvasManager::render(){
	for(unsigned int i = 0; i < renderObject.size(); i++){
		renderObject[i]->render();
	}
	send();
}

int CanvasManager::registerRendering(Renderable *obj){
	renderObject.push_back(obj);
	return 0;
}

int CanvasManager::removeRendering(Renderable *obj){
	for(unsigned int i = 0; i < renderObject.size(); i++){
		if(renderObject[i] == obj){
			renderObject.erase(renderObject.begin()+i);
			return 0;
		}
	}
	return 1;
}

void CanvasManager::send(){
	g15_send(g15screen_fd,(char *)canvas->buffer,G15_BUFFER_LEN);
}


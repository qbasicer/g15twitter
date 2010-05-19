#ifndef _CANVAS_MANAGER_HPP_
#define _CANVAS_MANAGER_HPP_

#include <g15daemon_client.h>
#include <libg15.h>
#include <libg15render.h>
#include <pthread.h>

#include "Renderable.hpp"
#include "G15Inputtable.hpp"
#include <vector>

using namespace std;

class CanvasManager{
	public:
		CanvasManager();
		~CanvasManager();
		inline g15canvas *getCanvas(){return canvas;}
		inline int getWidth(){return width;}
		inline int getHeight(){return height;}
		inline void setXorMode(int mode){canvas->mode_xor = mode;}
		int registerRendering(Renderable *obj);
		int removeRendering(Renderable *obj);
		void setKeyHandler(G15Inputtable *input){keyHandler = input;}
		G15Inputtable *getKeyHandler(){return keyHandler;}
		void send();
		void render();
		int getFD(){return g15screen_fd;}
		int isQuitting(){return quitflag;}
	protected:
		g15canvas *canvas;
		int width;
		int height;
		int g15screen_fd;
		G15Inputtable *keyHandler;
		pthread_t keyThread;
		vector<Renderable*> renderObject;
		int quitflag;
};

#endif

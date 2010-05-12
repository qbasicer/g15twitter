#include <cstdlib>
#include "CanvasManager.hpp"


CanvasManager::CanvasManager(){
	canvas = (g15canvas *) malloc (sizeof (g15canvas));
	memset(canvas->buffer, 0, G15_BUFFER_LEN);
	canvas->mode_cache = 0;
	canvas->mode_reverse = 0;
	canvas->mode_xor = 0;
	width = G15_LCD_WIDTH;
	height = G15_LCD_HEIGHT;
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


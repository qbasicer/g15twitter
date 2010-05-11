#include <cstdlib>
#include "CanvasManager.hpp"


CanvasManager::CanvasManager(){
	canvas = (g15canvas *) malloc (sizeof (g15canvas));
	memset(canvas->buffer, 0, G15_BUFFER_LEN);
	canvas->mode_cache = 0;
	canvas->mode_reverse = 0;
	canvas->mode_xor = 0;
	

}


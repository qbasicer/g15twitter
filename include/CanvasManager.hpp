#ifndef _CANVAS_MANAGER_HPP_
#define _CANVAS_MANAGER_HPP_

#include <g15daemon_client.h>
#include <libg15.h>
#include <libg15render.h>

class CanvasManager{
	public:
		CanvasManager();
		inline g15canvas *getCanvas(){return canvas;}
		inline int getWidth(){return width;}
		inline int getHeight(){return height;}
		inline void setXorMode(int mode){canvas->mode_xor = mode;}
	protected:
		g15canvas *canvas;
		int width;
		int height;
};

#endif

#ifndef _G15Widget_HPP_
#define _G15Widget_HPP_

class G15Widget;

#include "VirtualCanvas.hpp"

class G15Widget : public VirtualCanvas{
	public:
		G15Widget(CanvasManager *cm);
		G15Widget(VirtualCanvas *vcanvas);
		~G15Widget();
		inline VirtualCanvas *getCanvas(){return canvas;}
		virtual int render() = 0;
		inline int getHeight(){return canvas->getHeight();}
		inline int getWidth(){return canvas->getWidth();}
	private:
		void init(VirtualCanvas *vcanvas);
		VirtualCanvas *canvas;
};


#endif

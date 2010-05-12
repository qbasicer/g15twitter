#ifndef _G15Widget_HPP_
#define _G15Widget_HPP_

#include "VirtualCanvas.hpp"

class G15Widget {
	public:
		G15Widget(CanvasManager *cm);
		G15Widget(VirtualCanvas *vcanvas);
	private:
		void init(VirtualCanvas *vcanvas);
		VirtualCanvas *canvas;
};


#endif

#ifndef _G15Widget_HPP_
#define _G15Widget_HPP_

class G15Widget;

#include "VirtualCanvas.hpp"

class G15Widget : public Renderable{
	public:
		G15Widget(CanvasManager *cm);
		G15Widget(VirtualCanvas *vcanvas);
		~G15Widget();
		inline VirtualCanvas *getCanvas(){return canvas;}
		virtual int render() = 0;
	private:
		void init(VirtualCanvas *vcanvas);
		VirtualCanvas *canvas;
};


#endif

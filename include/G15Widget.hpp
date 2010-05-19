#ifndef _G15Widget_HPP_
#define _G15Widget_HPP_

class G15Widget;

#include "VirtualCanvas.hpp"

class G15Widget : public VirtualCanvas{
	public:
		G15Widget(CanvasManager *cm);
		G15Widget(VirtualCanvas *vcanvas);
		~G15Widget();
	private:
		void init(VirtualCanvas *vcanvas);
};


#endif

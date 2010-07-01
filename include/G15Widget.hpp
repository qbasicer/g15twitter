#ifndef _G15Widget_HPP_
#define _G15Widget_HPP_

class G15Widget;

#include "VirtualCanvas.hpp"

class G15Widget : public VirtualCanvas{
	public:
		G15Widget(CanvasManager *cm);
		G15Widget(VirtualCanvas *vcanvas);
		G15Widget(G15Widget *vcanvas);
		G15Widget *getRootWidget();
		~G15Widget();
	private:
		int isRoot;
		G15Widget* parent;
		void init(VirtualCanvas *vcanvas);
};


#endif

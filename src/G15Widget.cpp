#include "G15Widget.hpp"

G15Widget::G15Widget(CanvasManager *cm){
	VirtualCanvas *vcanvas = new VirtualCanvas(cm);
	init(vcanvas);
}

G15Widget::G15Widget(VirtualCanvas *vcanvas){
	init(vcanvas);
}

void G15Widget::init(VirtualCanvas *vcanvas){
	canvas = vcanvas;
}
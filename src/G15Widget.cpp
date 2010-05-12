#include "G15Widget.hpp"

G15Widget::G15Widget(CanvasManager *cm):VirtualCanvas(cm){
	init(this);
}

G15Widget::G15Widget(VirtualCanvas *vc):VirtualCanvas(vc){
	init(this);
}

G15Widget::~G15Widget(){
	canvas->deleteWidget(this);
}

void G15Widget::init(VirtualCanvas *vcanvas){
	canvas = vcanvas;
	if(canvas != this){
		canvas->addWidget(this, 0);
	}
}


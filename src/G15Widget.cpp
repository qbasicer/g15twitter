#include "G15Widget.hpp"

#include <cstdio>

G15Widget::G15Widget(CanvasManager *cm):VirtualCanvas(cm){
	parent = NULL;
	init(this);
}

G15Widget::G15Widget(VirtualCanvas *vc):VirtualCanvas(vc){
	parent = NULL;
	init(this);
}

G15Widget::G15Widget(G15Widget *gw):VirtualCanvas(gw){
	parent = gw;
	init(this);
}

G15Widget::~G15Widget(){
}

void G15Widget::init(VirtualCanvas *vcanvas){
	
}

G15Widget *G15Widget::getRootWidget(){
	if(parent){
		return parent->getRootWidget();
	}
	printf("I am my own root widget\n");
	return this;
}
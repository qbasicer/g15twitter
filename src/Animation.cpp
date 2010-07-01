#include "Animation.hpp"

#include <iostream>

using namespace std;

Animation::Animation(G15Widget *widget, ATTRIBUTES attr, int start, int end, int paintMode, G15Widget *custom){
	
	this->widget = widget;
	this->attr = attr;
	this->start = start;
	this->end = end;
	this->paintMode = paintMode;
	this->custom = custom;
	last = 242384239;
}

void Animation::tick(float perc){
	float diff = end-start;
	diff = perc*diff;
	int value = diff+start;
	if(last != value){
		widget->setAttribute(attr,value);
		if(paintMode == PAINT_MODE_RENDER_ROOT){
			widget->getRootWidget()->render();
			widget->getCanvas()->send();
		}else if(paintMode == PAINT_MODE_RENDER_CUSTOM){
			custom->render();
			widget->getCanvas()->send();
		}else if(paintMode == PAINT_MODE_PAINT_CUSTOM){
			custom->render();
			widget->getCanvas()->send();
		}
		last = value;
	}
	
}
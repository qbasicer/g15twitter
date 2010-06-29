#include "Animation.hpp"

Animation::Animation(G15Widget *widget, ATTRIBUTES attr, int start, int end){
	this->widget = widget;
	this->attr = attr;
	this->start = start;
	this->end = end;
}

void Animation::tick(float perc){
	//Nothing yet
}
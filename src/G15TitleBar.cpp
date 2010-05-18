#include "G15TitleBar.hpp"

G15TitleBar::G15TitleBar(const char* value, G15Widget *parent):G15Widget(parent){
	text = new G15TextLabel(value,this);
	text->setXorMode(1);
	text->move(0,1);
	addWidget(text,0);
}

int G15TitleBar::paint(){
	drawBar(0, 0, getWidth(), 7, G15_PIXEL_FILL, 1, 1, 0);
}
#include "G15Button.hpp"
#include <iostream>

G15Button::G15Button(const char* text, G15Widget *parent) : G15Widget(parent){
	label = new G15TextLabel(text,this);
	label->move(3,2);
	addWidget(label,0);
}

int G15Button::paint(){
	drawRoundedBox(0, 0, getWidth(), getHeight(), G15_PIXEL_NOFILL, G15_PIXEL_FILL);
	return 0;
}

void G15Button::setText(const char* text){
	label->setText(text);
}

const char *G15Button::getText(){
	return label->getText();
}
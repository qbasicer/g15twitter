#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "G15TextLabel.hpp"


G15TextLabel::G15TextLabel(const char* value, G15Widget *parent):G15Widget(parent){
	text = NULL;
	setText(value);
}

void G15TextLabel::setText(const char* value){
	if(text)
		free(text);
	
	text = (char*)malloc(strlen(value)+1);
	snprintf(text,strlen(value)+1,"%s",value);
}

const char* G15TextLabel::getText(){
	return text;
}

int G15TextLabel::paint(){
	drawText(0,0,G15_TEXT_MED,text);
	return 0;
}

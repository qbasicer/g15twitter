#include <cstdio>
#include "VirtualCanvas.hpp"

VirtualCanvas::VirtualCanvas(CanvasManager *cm){
	this->cm = cm;
	this->parent = NULL;
	width = cm->getWidth();
	height = cm->getHeight();
	init();	
	getCanvas()->registerRendering(this);
}

VirtualCanvas::VirtualCanvas(VirtualCanvas *parent){
	this->cm = NULL;
	this->parent = parent;\
	width = parent->getWidth();
	height = parent->getHeight();
	init();	
}

VirtualCanvas::~VirtualCanvas(){
	getCanvas()->removeRendering(this);
}

void VirtualCanvas::init(){
	xor_mode = offset_x = offset_y = 0;
	
	
}

void VirtualCanvas::drawRoundedBox(int x1, int y1, int x2, int y2, int dofill, int fill){
	internalSetXorMode(xor_mode);
	
	x1 += getGlobalXOffset();
	x2 += getGlobalXOffset();
	y1 += getGlobalYOffset();
	y2 += getGlobalYOffset();
	
	g15r_drawRoundBox (getCanvas()->getCanvas(), x1, y1, x2, y2, dofill, fill);
	
	internalSetXorMode(0);
}

void VirtualCanvas::drawBox(int x1, int y1, int x2, int y2, int color, int thick, int fill){
	internalSetXorMode(xor_mode);
	
	x1 += getGlobalXOffset();
	x2 += getGlobalXOffset();
	y1 += getGlobalYOffset();
	y2 += getGlobalYOffset();
	g15r_pixelBox (cm->getCanvas(), x1, y1, x2, y2, color, thick, fill);
	
	internalSetXorMode(0);
}

void VirtualCanvas::drawCircle(int x, int y, int r, int fill, int color){
	internalSetXorMode(xor_mode);
	
	x += getGlobalXOffset();
	y += getGlobalYOffset();
	g15r_drawCircle (cm->getCanvas(), x, y, r, fill, color);
	
	internalSetXorMode(0);
}

void VirtualCanvas::drawText(int x, int y, int size, const char* msg){
	internalSetXorMode(xor_mode);
	
	x += getGlobalXOffset();
	y += getGlobalYOffset();
	unsigned int i;
	int row = 0;
	int col = 0;
	for(i = 0; i < strlen(msg); i++){
		if(msg[i] == '\n'){
			col = 0;
			row++;
		}else{
			switch(size){
				case G15_TEXT_SMALL:
					g15r_renderCharacterSmall(getCanvas()->getCanvas(),col,row,msg[i],x,y);
					break;
				default:
				case G15_TEXT_MED:
					g15r_renderCharacterMedium(getCanvas()->getCanvas(),col,row,msg[i],x,y);
					break;
				case G15_TEXT_LARGE:
					g15r_renderCharacterLarge(getCanvas()->getCanvas(),col,row,msg[i],x,y);
					break;
			}
				
			col++;
		}
		
	}
	
	internalSetXorMode(0);
}

void VirtualCanvas::drawChar(int x, int y, int row, int col, int size, char c){
	internalSetXorMode(xor_mode);
	x += getGlobalXOffset();
	y += getGlobalYOffset();
	switch(size){
		case G15_TEXT_SMALL:
			g15r_renderCharacterSmall(getCanvas()->getCanvas(),col,row,c,x,y);
			break;
		default:
		case G15_TEXT_MED:
			g15r_renderCharacterMedium(getCanvas()->getCanvas(),col,row,c,x,y);
			break;
		case G15_TEXT_LARGE:
			g15r_renderCharacterLarge(getCanvas()->getCanvas(),col,row,c,x,y);
			break;
	}
	internalSetXorMode(0);
}

void VirtualCanvas::drawBar(int x1, int y1, int x2, int y2, int col, int val, int max, int type){
	internalSetXorMode(xor_mode);
	
	x1 += getGlobalXOffset();
	x2 += getGlobalXOffset();
	y1 += getGlobalYOffset();
	y2 += getGlobalYOffset();

	g15r_drawBar(getCanvas()->getCanvas(), x1, y1, x2, y2, col, val, max, type);
	internalSetXorMode(0);
}

void VirtualCanvas::clearScreen(int col){
	internalSetXorMode(xor_mode);
	
	//If we ask to actually clear the screen with the g15render API,
	//we will destroy the entire screen not just our 'virtual' screen
	int x1 = getGlobalXOffset();
	int y1 = getGlobalYOffset();
	int x2 = getGlobalXOffset() + getWidth();
	int y2 = getGlobalYOffset() + getHeight();
	drawBox(x1, y1, x2, y2, col, 0, 1);
	
	internalSetXorMode(0);
}

void VirtualCanvas::internalSetXorMode(int mode){
	if(parent){
		parent->getCanvas()->setXorMode(mode);
	}else{
		cm->setXorMode(mode);
	}
}

void VirtualCanvas::setXorMode(int mode){
	xor_mode = mode;	
}

void VirtualCanvas::setOffset(int x, int y){
	offset_x = x;
	offset_y = y;
}

int VirtualCanvas::getGlobalXOffset(){
	if(parent){
		return getLocalXOffset() + parent->getGlobalXOffset();
	}
	return getLocalXOffset();
}

int VirtualCanvas::getGlobalYOffset(){
	if(parent){
		return getLocalYOffset() + parent->getGlobalYOffset();
	}
	return getLocalYOffset();

}

int VirtualCanvas::render(){
	paint();
	paintChildren();
	return 0;
}

int VirtualCanvas::paintChildren(){
	
	for(unsigned int i = 0; i < renderObject.size(); i++){
		renderObject[i]->render();
	}
	return 0;
}

int VirtualCanvas::paint(){
	return 0;
}

void VirtualCanvas::addWidget(VirtualCanvas *obj, int layer){
	renderObject.push_back(obj);
}

void VirtualCanvas::deleteWidget(VirtualCanvas *obj){
	for(unsigned int i = 0; i < renderObject.size(); i++){
		if(renderObject[i] == obj){
			renderObject.erase(renderObject.begin()+i);
			return;
		}
	}
	return;
}

CanvasManager *VirtualCanvas::getCanvas(){
	if(parent){
		return parent->getCanvas();
	}
	return cm;
}


void VirtualCanvas::setAttribute(ATTRIBUTES attr, int value){
	switch(attr){
		case ATTRIBUTE_X_OFFSET:
			move(value,getLocalYOffset());
			break;
		case ATTRIBUTE_Y_OFFSET:
			move(getLocalXOffset(),value);
			break;
		case ATTRIBUTE_HEIGHT:
			resize(value,getWidth());
			break;
		case ATTRIBUTE_WIDTH:
			resize(getHeight(),value);
			break;
		default:
			break;
	}
}

int VirtualCanvas::getAttribute(ATTRIBUTES attr){
	switch(attr){
		case ATTRIBUTE_HEIGHT:
			return getHeight();
		case ATTRIBUTE_WIDTH:
			return getWidth();
		default:
			return -1;
	}
}


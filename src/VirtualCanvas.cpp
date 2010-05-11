#include "VirtualCanvas.hpp"

VirtualCanvas::VirtualCanvas(CanvasManager *cm){
	this->cm = cm;
	xor_mode = offset_x = offset_y = 0;
	parent = NULL;
}

VirtualCanvas::VirtualCanvas(VirtualCanvas *parent){
	cm = NULL;
	xor_mode = offset_x = offset_y = 0;
	this->parent = parent;
}


void VirtualCanvas::drawRoundedBox(int x1, int y1, int x2, int y2, int dofill, int fill){
	x1 += offset_x;
	x2 += offset_x;
	y1 += offset_y;
	y2 += offset_y;
	g15r_drawRoundBox (cm->getCanvas(), x1, y1, x2, y2, dofill, fill);
}

void VirtualCanvas::drawBox(int x1, int y1, int x2, int y2, int color, int thick, int fill){
	x1 += offset_x;
	x2 += offset_x;
	y1 += offset_y;
	y2 += offset_y;
	g15r_pixelBox (cm->getCanvas(), x1, y1, x2, y2, color, thick, fill);
}

void VirtualCanvas::drawCircle(int x, int y, int r, int fill, int color){
	x += offset_x;
	y += offset_y;
	g15r_drawCircle (cm->getCanvas(), x, y, r, fill, color);
}

void VirtualCanvas::drawText(int x, int y, int size, const char* msg){
	x += offset_x;
	y += offset_y;
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
					g15r_renderCharacterSmall(cm->getCanvas(),col,row,msg[i],x,y);
					break;
				default:
				case G15_TEXT_MED:
					g15r_renderCharacterMedium(cm->getCanvas(),col,row,msg[i],x,y);
					break;
				case G15_TEXT_LARGE:
					g15r_renderCharacterLarge(cm->getCanvas(),col,row,msg[i],x,y);
					break;
			}
				
			col++;
		}
		
	}
}

void VirtualCanvas::drawChar(int x, int y, int row, int col, int size, char c){
	x += offset_x;
	y += offset_y;
	switch(size){
		case G15_TEXT_SMALL:
			g15r_renderCharacterSmall(cm->getCanvas(),col,row,c,x,y);
			break;
		default:
		case G15_TEXT_MED:
			g15r_renderCharacterMedium(cm->getCanvas(),col,row,c,x,y);
			break;
		case G15_TEXT_LARGE:
			g15r_renderCharacterLarge(cm->getCanvas(),col,row,c,x,y);
			break;
	}
}

void VirtualCanvas::drawBar(int x1, int y1, int x2, int y2, int col, int val, int max, int type){
	x1 += offset_x;
	x2 += offset_x;
	y1 += offset_y;
	y2 += offset_y;

	g15r_drawBar(cm->getCanvas(), x1, y1, x2, y2, col, val, max, type);

}

void VirtualCanvas::clearScreen(int col){
	//If we ask to actually clear the screen with the g15render API,
	//we will destroy the entire screen not just our 'virtual' screen
	int x1 = offset_x;
	int y1 = offset_y;
	int x2 = offset_x + G15_LCD_WIDTH;
	int y2 = offset_y + G15_LCD_HEIGHT;
	drawBox(x1, y1, x2, y2, col, 0, 1);
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
		return getLocalXOffset() + parent->getLocalXOffset();
	}
	return getLocalXOffset();
}

int VirtualCanvas::getGlobalYOffset(){
	if(parent){
		return getLocalYOffset() + parent->getLocalYOffset();
	}
	return getLocalYOffset();

}

CanvasManager *VirtualCanvas::getCanvas(){
	if(parent){
		return parent->getCanvas();
	}
	return cm;
}


#include "VirtualCanvas.hpp"

VirtualCanvas::VirtualCanvas(CanvasManager *cm){
	this->cm = cm;
	xor_mode = offset_x = offset_y = 0;
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

void VirtualCanvas::setXorMode(int mode){
	xor_mode = mode;
}

void VirtualCanvas::setOffset(int x, int y){
	offset_x = x;
	offset_y = y;
}
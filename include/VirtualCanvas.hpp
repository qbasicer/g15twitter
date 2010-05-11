#ifndef _VIRTUALCANVAS_HPP_
#define _VIRTUALCANVAS_HPP_

#include "CanvasManager.hpp"

class VirtualCanvas{
	public:
		VirtualCanvas(CanvasManager *cm);
		void drawRoundedBox(int x1, int y1, int x2, int y2, int border, int fill);
		void drawBox(int x1, int y1, int x2, int y2, int color, int thick, int fill);
		void drawCircle(int x, int y, int r, int fill, int color);
		void drawText(int x, int y, int size, const char* msg);
		void drawChar(int x, int y, int row, int col, int size, char c);
		void setXorMode(int mode);
		void setOffset(int x, int y);
	protected:
		CanvasManager *cm;
		int xor_mode;
		int offset_x;
		int offset_y;
};

#endif
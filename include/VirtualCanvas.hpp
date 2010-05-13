#ifndef _VIRTUALCANVAS_HPP_
#define _VIRTUALCANVAS_HPP_

#include "CanvasManager.hpp"
#include "Renderable.hpp"

class VirtualCanvas : public Renderable{
	public:
		VirtualCanvas(CanvasManager *cm);
		VirtualCanvas(VirtualCanvas *parent);
		~VirtualCanvas();
		
		void drawRoundedBox(int x1, int y1, int x2, int y2, int border, int fill);
		void drawBox(int x1, int y1, int x2, int y2, int color, int thick, int fill);
		void drawCircle(int x, int y, int r, int fill, int color);
		void drawText(int x, int y, int size, const char* msg);
		void drawChar(int x, int y, int row, int col, int size, char c);
		void drawBar(int x1, int y1, int x2, int y2, int col, int val, int max, int type);
		void clearScreen(int col);
		void setXorMode(int mode);
		inline void move(int x, int y){setOffset(x,y);}
		inline int getLocalXOffset(){return offset_x;}
		inline int getLocalYOffset(){return offset_y;}
		int getGlobalXOffset();
		int getGlobalYOffset();
		CanvasManager *getCanvas();
		inline int getWidth(){return width;}
		inline int getHeight(){return height;}
		inline void setWidth(int height){this->height = height;}
		inline void setHeight(int width){this->width = width;}
		virtual int render();
		
	protected:
		void setOffset(int x, int y);
		void addWidget(VirtualCanvas *obj, int layer);
		void deleteWidget(VirtualCanvas *obj);
		inline void internalSetXorMode(int mode);
		virtual int paintChildren();
		virtual int paint();
		
		VirtualCanvas *parent;
		CanvasManager *cm;
		int xor_mode;
		int offset_x;
		int offset_y;
		int height;
		int width;
		
	private:
		vector<Renderable*> renderObject;
		void init();
};

#endif

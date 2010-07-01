#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include "G15Widget.hpp"


#define PAINT_MODE_RENDER_ROOT		0
#define PAINT_MODE_RENDER_CUSTOM	1
#define PAINT_MODE_PAINT_CUSTOM		2

class Animation {
	public:
		Animation(G15Widget *widget, ATTRIBUTES attr, int start, int end, int paintMode = PAINT_MODE_RENDER_ROOT, G15Widget *custom = NULL);
		void tick(float perc);
	private:
		G15Widget *widget;
		G15Widget *custom;
		int start;
		int end;
 		int last;
		ATTRIBUTES attr;
		int paintMode;
};

#endif
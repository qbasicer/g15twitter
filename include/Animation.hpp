#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include "G15Widget.hpp"


class Animation {
	public:
		Animation(G15Widget *widget, ATTRIBUTES attr, int start, int end);
		void tick(float perc);
	private:
		G15Widget *widget;
		int start;
		int end;
		ATTRIBUTES attr;
};

#endif
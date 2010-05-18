#ifndef _G15TITLEBAR_HPP_
#define _G15TITLEBAR_HPP_

#include "G15TextLabel.hpp"

class G15TitleBar : public G15Widget{
	public:
		G15TitleBar(const char* value, G15Widget *parent);
		virtual int paint();
	private:
		G15Widget *text;
};


#endif

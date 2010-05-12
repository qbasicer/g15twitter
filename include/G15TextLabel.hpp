#ifndef _G15TEXTLABEL_HPP_
#define _G15TEXTLABEL_HPP_

#include "G15Widget.hpp"

class G15TextLabel : public G15Widget {
	public:
		G15TextLabel(const char* value, G15Widget *parent);
		void setText(const char* value);
		const char* getText();
		virtual int paint();
	private:
		char* text;
};

#endif

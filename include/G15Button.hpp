#ifndef _G15BUTTON_HPP_
#define _G15BUTTON_HPP_

#include "G15Widget.hpp"
#include "G15TextLabel.hpp"

class G15Button : public G15Widget {
	public:
		G15Button(const char* text, G15Widget *parent);
		void setText(const char* text);
		const char *getText();
		virtual int paint();
	private:
		G15TextLabel *label;
};


#endif

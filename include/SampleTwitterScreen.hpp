#ifndef _SAMPLETWITTERSCREEN_HPP_
#define _SAMPLETWITTERSCREEN_HPP_

#include "G15Widget.hpp"
#include "G15TextLabel.hpp"
#include "G15StandardLayout.hpp"
#include "G15Inputtable.hpp"
#include "G15Button.hpp"

class SampleTwitterScreen : public G15Widget,G15Inputtable {
	public:
		SampleTwitterScreen(CanvasManager *cm);
		SampleTwitterScreen(VirtualCanvas *vc);
		~SampleTwitterScreen();
		virtual int G15HandleKeypress(int key);
	protected:
		virtual int paint();
	private:
		void init();
		int quit;
		G15TextLabel *body;
		G15StandardLayout *layout;
		G15Button *testBtn;
};



#endif

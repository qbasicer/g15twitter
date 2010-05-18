#ifndef _SAMPLETWITTERSCREEN_HPP_
#define _SAMPLETWITTERSCREEN_HPP_

#include "G15Widget.hpp"
#include "G15TextLabel.hpp"
#include "G15StandardLayout.hpp"

class SampleTwitterScreen : public G15Widget {
	public:
		SampleTwitterScreen(CanvasManager *cm);
		SampleTwitterScreen(VirtualCanvas *vc);
	protected:
		virtual int paint();
	private:
		
		void init();
;
		G15TextLabel *body;
		G15StandardLayout *layout;
};



#endif

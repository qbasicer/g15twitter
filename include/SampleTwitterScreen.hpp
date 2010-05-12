#ifndef _SAMPLETWITTERSCREEN_HPP_
#define _SAMPLETWITTERSCREEN_HPP_

#include "G15Widget.hpp"

class SampleTwitterScreen : public G15Widget {
	public:
		SampleTwitterScreen(CanvasManager *cm);
		SampleTwitterScreen(VirtualCanvas *vc);
		virtual int render();
};



#endif

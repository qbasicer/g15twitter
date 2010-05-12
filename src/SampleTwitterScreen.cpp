#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include "SampleTwitterScreen.hpp"

SampleTwitterScreen::SampleTwitterScreen(CanvasManager *cm):G15Widget(cm){
	
}

SampleTwitterScreen::SampleTwitterScreen(VirtualCanvas *vc):G15Widget(vc){
	
}

int SampleTwitterScreen::render(){
	VirtualCanvas *vc = getCanvas();
	int i;
	char* str = "Testing string\n";
	int lines = 1;
	int eend = 0;
	int scrolls = lines - 3;
	if (scrolls > 0){
		eend = 0-(scrolls*7);
	}
	for(i = 0; i >= eend; i--){
		vc->clearScreen(G15_PIXEL_NOFILL);
		vc->drawText(0, 9+i, G15_TEXT_MED, str);
		vc->drawBar(0, 0, 160, 7, G15_PIXEL_FILL, 1, 1, 0);
		vc->setXorMode(1);
		vc->drawText(0, 1, G15_TEXT_MED, "<NobodyActually> (2h)");
		vc->setXorMode(1);
		vc->drawBar(0, 34, 160, 42, G15_PIXEL_NOFILL, 1, 1, 0);
		vc->drawRoundedBox(0, 35, 38, 50, G15_PIXEL_NOFILL, G15_PIXEL_FILL);
		vc->drawText(5,37,G15_TEXT_MED,"PREV");
		vc->getCanvas()->send();
		if(i % 7){
			usleep(50000);
		}else{
			sleep(3);
		}
	}
}
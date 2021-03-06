#include <iostream>
#include <cstdlib>
#include "CanvasManager.hpp"
#include "AnimationManager.hpp"
#include "SampleTwitterScreen.hpp"

int main(int argc, char* argv[]){
	CanvasManager *cm = new CanvasManager();
	AnimationManager *am = new AnimationManager(cm);
	{
		SampleTwitterScreen sts(cm);
		cm->render();
		sleep(50);
	}
	delete cm;
	exit(0);
}
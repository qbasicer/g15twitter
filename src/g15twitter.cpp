#include <iostream>
#include <cstdlib>
#include "CanvasManager.hpp"
#include "AnimationManager.hpp"
#include "SampleTwitterScreen.hpp"

int main(int argc, char* argv[]){
	CanvasManager *cm = new CanvasManager();
	AnimationManager *am = new AnimationManager(cm);
	SampleTwitterScreen sts(cm);
	cm->render();
	exit(0);
}
#include <iostream>
#include <cstdlib>
#include "CanvasManager.hpp"
#include "AnimationManager.hpp"

int main(int argc, char* argv[]){
	CanvasManager *cm = new CanvasManager();
	AnimationManager *am = new AnimationManager(cm);
	
	exit(0);
}
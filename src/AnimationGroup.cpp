#include "AnimationGroup.hpp"
#include <iostream>
using namespace std;

AnimationGroup::AnimationGroup(){
}

AnimationGroup::~AnimationGroup(){
}

void AnimationGroup::addAnimation(Animation *anim){
	animations.push_back(anim);
}

void AnimationGroup::tick(float perc){
	for(unsigned int i = 0; i < animations.size(); i++){
		animations[i]->tick(perc);
	}
}

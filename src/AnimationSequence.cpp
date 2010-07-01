#include <unistd.h>
#include <cstdlib>
#include "AnimationSequence.hpp"
#include <iostream>

using namespace std;

AnimationSequence::AnimationSequence(int fps, int start, int stop, float seconds){
	this->fps = fps;
	this->length = seconds;
	this->startValue = start;
	this->stopValue = stop;
	currentFrame = 0;
	started = 0;
}

AnimationSequence::~AnimationSequence(){
}

int AnimationSequence::hasStarted(){
	return started;
}

int AnimationSequence::hasFinished(){
	if(currentFrame >= fps * length){
		return true;
	}
	return false;
}

int AnimationSequence::getFPS(){
	return fps;
}

void AnimationSequence::setFPS(int fps){
	this->fps = fps;
}

void AnimationSequence::setProgress(float perc){
	float loc = perc * length * fps;
	currentFrame = loc;
}

float AnimationSequence::getProgress(){
	return (float)currentFrame/(float)fps/length;
}

float AnimationSequence::getLength(){
	return length;
}

void AnimationSequence::setLength(float seconds){
	length = seconds;
}

void AnimationSequence::addTrigger(AnimationSequence *seq){
	triggers.push_back(seq);
}

void AnimationSequence::addAnimation(Animation *anim){
	groups.push_back(anim);
}

void AnimationSequence::addNotify(NotifyInterface *note){
	if(note)
		return;
}

void AnimationSequence::tick(){
	float perc = getProgress();
	for(unsigned int i = 0; i < groups.size(); i++){
		groups[i]->tick(perc);
	}
	if(hasFinished()){
		for(unsigned int i = 0; i < triggers.size(); i++){
			triggers[i]->start();
		}
	}
	currentFrame++;
}


static void* run_seq_thread(void* obj){
	if(obj == NULL){
		return NULL;
	}
	AnimationSequence *seq = (AnimationSequence*)obj;
	int sleepTime = (1/(float)seq->getFPS())*1000000;
	while(!seq->hasFinished()){
		seq->tick();
		usleep(sleepTime);
	}
	seq->tick();
	return NULL;	
}

void AnimationSequence::start(){
	int rc = pthread_create(&thread, NULL, run_seq_thread, (void *)this);
	if (rc){
		exit(-1);
	}
	started = 1;
}



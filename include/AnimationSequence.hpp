#ifndef _ANIMATIONSEQUENCE_HPP_
#define _ANIMATIONSEQUENCE_HPP_

#include "Animation.hpp"
#include "NotifyInterface.hpp"
#include <vector>

class AnimationSequence {
	public:
		AnimationSequence(int fps, int start, int stop, float seconds);
		~AnimationSequence();
		int hasStarted();
		int hasFinished();
		int getFPS();
		void setFPS(int fps);
		void setProgress(float perc);
		float getProgress();
		float getLength();
		void setLength(float seconds);
		void addTrigger(AnimationSequence *seq);
		void addAnimation(Animation *anim);
		void addNotify(NotifyInterface *note);
		void tick();
		void start();
	private:
		int fps;
		float length;
		int startValue;
		int stopValue;
		float current;
		vector<AnimationSequence*> triggers;
		vector<Animation*> groups;
		vector<NotifyInterface*> notifyList;
		int currentFrame;
		int started;
		pthread_t thread;
		
		struct started;
};
#endif



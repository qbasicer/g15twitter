#ifndef _ANIMATIONGROUP_HPP_
#define _ANIMATIONGROUP_HPP_

#include "Animation.hpp"
#include <vector>

class AnimationGroup{
	public:
		AnimationGroup();
		~AnimationGroup();
		void addAnimation(Animation *anim);
		void tick(float perc);
	protected:
		vector<Animation*> animations;
};

#endif

#ifndef _ANIMATION_MANAGER_HPP_
#define _ANIMATION_MANAGER_HPP_

#include "CanvasManager.hpp"
#include "AnimationSequence.hpp"

class AnimationManager{
	public:
		AnimationManager(CanvasManager *cm);
		void registerSequence(AnimationSequence *anim, int transfer = 0);
	protected:
		CanvasManager* cm;

};

#endif

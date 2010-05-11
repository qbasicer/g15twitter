#ifndef _ANIMATION_MANAGER_HPP_
#define _ANIMATION_MANAGER_HPP_

#include "CanvasManager.hpp"

class AnimationManager{
	public:
		AnimationManager(CanvasManager *cm);
	protected:
		CanvasManager* cm;
};

#endif

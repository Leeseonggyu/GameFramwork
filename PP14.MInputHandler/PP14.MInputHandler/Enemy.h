#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	void handleInput();
	virtual void draw();
	virtual void update();
	virtual void clean();
};

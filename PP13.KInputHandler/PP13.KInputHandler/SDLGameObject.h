#pragma once
#include "Game.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "TextureManager.h"

class SDLGameObject : public SDLGameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};
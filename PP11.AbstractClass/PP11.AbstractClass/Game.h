#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include "LoaderParams.h"

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	std::vector<GameObject*> m_gameObjects;


	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;


private:
	static Game* s_pInstance;
	typedef Game TheGame;
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;
	int m_currentFrame2;

	//TextureManager m_textureManager;

	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // 원본 사각형 
	//SDL_Rect m_destinationRectangle; // 대상 사각형 
};
Game* Game::s_pInstance = 0;

SDL_Renderer* getRenderer() const { return m_pRenderer; }
#include"Game.h"
//

Game* Game::s_pInstance = 0;

SDL_Renderer* getRenderer() const { return m_pRenderer; }

static Game* Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new Game();
		return s_pInstance;
	}
	return s_pInstance;
}

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
	// Game::render ���� �ʿ� 
	//m_go = new GameObject();
	//m_player = new Player();
	//m_enemy = new Enemy();

	m_go->load(100, 100, 128, 82, "animate");
	m_player->load(300, 300, 128, 82, "animate");
	m_enemy->load(0, 0, 128, 82, "animate");

	//m_gameObjects.push_back(m_go);
	//m_gameObjects.push_back(m_player);
	//m_gameObjects.push_back(m_enemy);
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		//m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		//if (m_pWindow != 0)
		//{
		//m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		//}

		m_bRunning = true;

		// load �κ� ��ġ   
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

		//m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);
		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	}
	else {
		return false; // sdl could not initialize
	}
	return true;
}


void Game::render()
{
	//SDL_RenderClear(m_pRenderer); // clear to the draw colour
	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//m_gameObjects[i]->draw(m_pRenderer);
	//}
	//SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
	//for (std::vector<GameObject*>::size_type i = 0;
	//i != m_gameObjects.size(); i++)
	//{
	//m_gameObjects[i]->update();
	//}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	//SDL_DestroyWindow(m_pWindow);
	//SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;

		}
	}
}
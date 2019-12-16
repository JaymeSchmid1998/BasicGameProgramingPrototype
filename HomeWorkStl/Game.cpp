#include "Game.h"
#include<iostream>


//page number 3

Game::Game()
{
	SdlWindow = nullptr;
	SdlRenderer = nullptr;
	LastUpadateTimer = SDL_GetTicks();

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		IsTheGameOver = true;

		std::cout << "error initalizing " << std::endl;

	}
	else
	{
		IsTheGameOver = false;

		std::cout << "inialized " << std::endl;

	}

	

}
bool Game::start() {
	SdlRenderer = SDL_CreateRenderer(SdlWindow, 0, -1);
	if (SdlRenderer != nullptr) {
		UserInput = new Input();
		std::cout << "render created " << std::endl;


		/*Texture* playertexture = new Texture();
		playertexture->LoadImgFromFile("../assets/v3.bmp",SdlRenderer);

		M_Position1.X = 10;
		M_Position1.Y = 200;
		GameObject*player = new Player(playertexture,M_Position1);
		M_GameObjects.push_back(player);*/


		Texture* playerSpacetexture = new Texture();
		playerSpacetexture->LoadImgFromFile("../assets/v3.bmp", SdlRenderer);

		M_Position1.X = 10;
		M_Position1.Y = 200;
		GameObject*playerSpaceS = new PlayerSpaceShip(playerSpacetexture, M_Position1);
		M_GameObjects.push_back(playerSpaceS);

		//Texture * enemytexture = new Texture();
		//enemytexture->LoadImgFromFile("../assets/v1.bmp", SdlRenderer);

	/*	m_position1.x = 10;
		m_position1.y = 20;
		GameObject*enemy1 = new Enemy(enemytexture, m_position1);
		m_gameobjects.push_back(enemy1);


		Texture * enemytexture1 = new Texture();
		enemytexture1->loadImgFromF("../assets/v1.bmp", sdlRenderer);

		m_position1.x = 25;
		m_position1.y = 100;
		GameObject*enemy2 = new  Enemy(enemytexture1, m_position1);
		m_gameobjects.push_back(enemy2);*/
	/*	
	//this is correct	
		m_ptexture = new Texture();
		//C:\Users\zbook j\Desktop\year 3 sem3\game prog\program\backups\2.0\HomeWorkStl\assets
		if (m_ptexture->loadImgFromF("../assets/v3.bmp", sdlRenderer)) {
			std::cout << "texture loaded " << std::endl;
			
		
			ani = new Animation(m_ptexture, 10, 0.1f);
			m_player = new Player();
		}
		else
		{
			std::cout << "texture not loaded  " << std::endl;
			return false;
		}*/
		

		LastUpadateTimer = SDL_GetTicks();

		return true;
	}
	else
	{
		std::cout << "render failed " << std::endl;
		return false;
	}
	


}
void Game::run(char* title, int width, int height, bool fullscreen) {
	int creationFlag = 0;

	if (!fullscreen)
	{
		creationFlag = SDL_WINDOW_SHOWN;
	}
	else
	{
		creationFlag = SDL_WINDOW_FULLSCREEN;
	}
	SdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, creationFlag);


	if (SdlWindow !=nullptr && start())
	{
		std::cout << "created window" << std::endl;
		while (!IsTheGameOver)
		{
			processinput();

			update();
			draw();
		}



	}
	else
	{
		std::cout << "not created window" << std::endl;
		shutdown();
		destroy();
	
	}


}

void Game::draw() {

	SDL_SetRenderDrawColor(SdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(SdlRenderer);
	
	
	
	//ani->draw(sdlRenderer, 0, 0);
	
	//m_player->Draw(sdlRenderer);

	for (int i = 0; i < M_GameObjects.size(); ++i)
	{
		M_GameObjects[i]->Draw(SdlRenderer);
	}
	
	SDL_RenderPresent(SdlRenderer);
}
void Game::destroy() {
	SDL_DestroyWindow(SdlWindow);
	SDL_DestroyRenderer(SdlRenderer);
	SDL_Quit();
}
void Game::processinput() {
	//m_player->Input();

	UserInput->UpdateInput();
	
	if (UserInput->IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		SDL_Log("ifring");

	}

	if (UserInput->IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
		SDL_Log("did not press te left buttton");

	}

	if (UserInput->IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		SDL_Log("ALT ifring");

	}

	for (int i = 0; i < M_GameObjects.size(); ++i)
	{
		M_GameObjects[i]->UserInput1();
		M_GameObjects[i]->HandleUserInput(UserInput);
	}
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type==SDL_QUIT)
		{
			IsTheGameOver = true;
		}

	
	}

	



}
void Game::update() {
	//calculate delta time. 
	unsigned int ticks = SDL_GetTicks() - LastUpadateTimer;
	float deltaTime = ticks / 1000.0f;
	LastUpadateTimer = SDL_GetTicks();
	
	//this displays the delta time 
	//std::cout << "time" << deltaTime<< std::endl;

//	ani->Update(deltaTime);
	//m_player->Update(deltaTime);
	
	for (int i = 0; i < M_GameObjects.size(); ++i)
	{
		M_GameObjects[i]->Update(deltaTime);
	}

}
void Game::shutdown() {

}

Game::~Game()
{
}

#pragma once

#include "Texture.h"

#include"PlayerSpaceShip.h"
#include<vector>
#include"Vector2.h"
#include"Input.h"
class Game
{
private:
	SDL_Window* SdlWindow;
	SDL_Renderer *SdlRenderer;
	bool IsTheGameOver;
	unsigned int LastUpadateTimer;
	Texture* M_Texture;
	std::vector<GameObject*>M_GameObjects;
	PlayerSpaceShip * M_Player_SpaceShip;
	Texture* playerBullets;
	Input *UserInput;
	Vector2 M_Position1;
	
public:
	Game();
	
	bool start();
	void processinput();
	SDL_Event e;
	void update();
	void draw();
	void shutdown();
	void run(char* title,int width,int height,bool fullscreen);
	void destroy();
	
	

	
	
	
	//upto page number 4
	~Game();
};


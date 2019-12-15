#pragma once
#include "GameObject.h"
class Player :public GameObject 
{
private:
	Vector2 M_Velocity;
	Vector2 M_Acceleration;

public:
	Player();
	Player(Texture * texture, Vector2 position);

	 void AddPlayerForce(Vector2 force);
	 void Draw(SDL_Renderer*renderer);
	 void Update(float delraTime);
	 void UserInput1();
	 void HandleUserInput(Input*input);


	~Player();
};


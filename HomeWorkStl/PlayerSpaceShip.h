#pragma once
#include "GameObject.h"
#include"Bullet1.h"
class PlayerSpaceShip : public GameObject
{
private:
	Vector2 M_Velocity;
	Vector2 M_Acceleration;
public:
	PlayerSpaceShip();
	Bullet1 * m_bullet;
	PlayerSpaceShip(Texture * texture, Vector2 position);
	void AddPlayerForce(Vector2 force);
	void ReducePlayerForce(Vector2 force);
	void Draw(SDL_Renderer*renderer);
	void Update(float delraTime);
	void UserInput1();
	void HandleUserInput(Input*input);
	~PlayerSpaceShip();
};


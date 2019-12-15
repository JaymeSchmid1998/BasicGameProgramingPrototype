#include "Player.h"
#include<iostream>


Player::Player()
{

	M_Texture = nullptr;
std::cout << "playerconstructor" << std:: endl;
}

Player::Player(Texture * texture, Vector2 position)
{ 
	M_Position = position;
	M_Texture = texture;
	M_Velocity = Vector2(0, 0);
	M_Acceleration = Vector2(0, 0);

}

void Player::AddPlayerForce(Vector2 force)
{
	M_Acceleration += force;
}

void Player::Draw(SDL_Renderer * renderer)
{
	M_Texture->Draw(renderer, M_Position.X, M_Position.Y);

}

void Player::Update(float delraTime)
{
	M_Velocity += M_Acceleration *delraTime;
	M_Position += M_Velocity*delraTime;
	 
}

void Player::UserInput1()
{
	//AddForce(Vector2(0, 2));
}

void Player::HandleUserInput(Input * input)
{
	
	if (input->IsKeyDown(SDL_SCANCODE_W))
	{
		AddPlayerForce(Vector2(0, -2));
	}


	if (input->IsKeyDown(SDL_SCANCODE_S))
	{
		AddPlayerForce(Vector2(0, 2));
	}


	if (input->IsKeyDown(SDL_SCANCODE_A))
	{
		AddPlayerForce(Vector2(-2, 0));
	}


	if (input->IsKeyDown(SDL_SCANCODE_D))
	{
		AddPlayerForce(Vector2(2, 0));
	}
}


Player::~Player()
{
	std::cout << "player destructor" << std::endl;
}

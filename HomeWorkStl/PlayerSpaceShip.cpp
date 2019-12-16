#include "PlayerSpaceShip.h"



PlayerSpaceShip::PlayerSpaceShip()
{
	//on construction of the player it sets their texture to a nullptr
	M_Texture = nullptr;
	std::cout << "playerconstructor" << std::endl;
}

PlayerSpaceShip::PlayerSpaceShip(Texture * texture, Vector2 position)
{
	//this part initalizes the players position,texture,velocity and also acceleration.
	M_Position = position;
	M_Texture = texture;
	M_Velocity = Vector2(0, 0);
	M_Acceleration = Vector2(0, 0);
}

void PlayerSpaceShip::AddPlayerForce(Vector2 force)
{
	//this part increases the players acceleration in a direction by adding the players force to their acceleration 

	if (M_Acceleration.X<4 ||M_Acceleration.Y<4)
	{
		M_Acceleration += force;
	}
	
}

void PlayerSpaceShip::ReducePlayerForce(Vector2 force)
{

	if (M_Acceleration.X>-10 || M_Acceleration.Y>-10)
	{
		M_Acceleration += force;
	}

}

void PlayerSpaceShip::Draw(SDL_Renderer * renderer)
{
	//this part points to the draw function in the texture class and draws te player on the screen 
	M_Texture->Draw(renderer, M_Position.X, M_Position.Y);
}

void PlayerSpaceShip::Update(float delraTime)
{
	//this part updates the players posution and also their velocity
	M_Velocity += M_Acceleration *delraTime;
	/*if (M_Position.X>=200 &&M_Velocity.X>0)
	{
		
	}
	else if(M_Position.X <= 0 && M_Velocity.X<0)
	{
		
	}
	else  { */
		M_Position += M_Velocity*delraTime;
	//}
	
}

void PlayerSpaceShip::UserInput1()
{
}

void PlayerSpaceShip::HandleUserInput(Input * input)
{
	//this part handles the users input when they press a key down the keyboard, when they press a button down it will add to the players force in the coresponding direction
	if (input->IsKeyDown(SDL_SCANCODE_W))
	{
		ReducePlayerForce(Vector2(0, -2));
	}


	if (input->IsKeyDown(SDL_SCANCODE_S))
	{
		AddPlayerForce(Vector2(0, 2));
	}


	if (input->IsKeyDown(SDL_SCANCODE_A))
	{
		
		AddPlayerForce(Vector2(-1, 0));
	}


	if (input->IsKeyDown(SDL_SCANCODE_D))
	{
		//if (M_Position.X <= 200 && M_Velocity.X>=0)
		//{
			AddPlayerForce(Vector2(1, 0));
		//}
		
	}
}


PlayerSpaceShip::~PlayerSpaceShip()
{
	std::cout << "player destructor" << std::endl;

}

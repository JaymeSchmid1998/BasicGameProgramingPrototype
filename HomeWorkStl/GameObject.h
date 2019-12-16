#pragma once

#include"Texture.h"
#include"Vector2.h"
#include"Input.h"
class GameObject
{
public:
	GameObject();
	~GameObject();
	
	virtual void Draw(SDL_Renderer*renderer);
	virtual void Update(float delraTime);
	virtual void UserInput1();
	virtual void HandleUserInput(Input*input);
	Vector2 M_Position;
	Texture*M_Texture;
protected:
	
};


#include "Animation.h"

Animation::Animation()
{
	switchTime = 0;
	currentTexture = 0;
	currentTime = 0;
	amount = 0;
}

Animation::Animation(string path, int amount, float switchTime)
{
	for (int i = 0; i < amount; i++)
	{
		textures.push_back(DATA->getTexture(path+ to_string(i)));
	}
	this->switchTime = switchTime;
	currentTexture = 0;
	currentTime = 0;
	this->amount = amount;
}

void Animation::update(float deltaTime)
{
	currentTime += deltaTime;
	if (currentTime >= switchTime)
	{
		currentTexture++;
		currentTime -= switchTime;
		if (currentTexture == amount)
			currentTexture = 0;
	}
}

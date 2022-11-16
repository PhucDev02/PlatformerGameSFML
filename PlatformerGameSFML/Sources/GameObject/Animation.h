#pragma once
#include"SFML/Graphics.hpp"
#include <vector>
#include "../GameManager/ResourceManager.h"
using namespace std;
using namespace sf;
class Animation
{
private:
	vector<Texture*> textures;
	float switchTime,currentTime;
	int currentTexture;
	int amount;
public:
	Animation();
	Animation(string path, int amount, float switchTime);
	void update(float deltaTime);
	Texture* getTexture()
	{
		return textures[currentTexture];
	}
};


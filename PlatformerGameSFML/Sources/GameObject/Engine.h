#pragma once
#include "../GameConfig.h"
#include "SFML/Graphics.hpp"
#include "../GameState/GameplayState.h"
#include "../GameManager/ResourceManager.h"
using namespace sf;
class Engine
{
public:
	State state;
	GameplayState gameplayState;
	Block block;
	//All state
public:
	Engine();
	void init();
	void update(float deltaTime);
	void draw(RenderWindow& window);
};
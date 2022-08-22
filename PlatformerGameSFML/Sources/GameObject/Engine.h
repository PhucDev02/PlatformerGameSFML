#pragma once
#include "../GameConfig.h"
#include "SFML/Graphics.hpp"
#include "../GameState/GameplayState.h"
using namespace sf;
class Engine
{
public:
	State state;
	GameplayState gameplayState;
	//All state
public:
	Engine() {};
	void init();
	void update(float deltaTime);
	void draw(RenderWindow& window);
};
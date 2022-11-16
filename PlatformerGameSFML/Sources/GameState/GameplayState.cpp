#include "GameplayState.h"
#include <math.h>
#include <iostream>
GameplayState::GameplayState()
{
	map = GameMap(1);
	player = Player();
}
void GameplayState::update(float deltaTime)
{
	player.update(deltaTime);
	map.update(deltaTime,player);
	player.updateAnimation(deltaTime);
}
void GameplayState::draw(RenderWindow& window)
{
	//
	map.drawBlock(window);
	player.draw(window);
	map.drawGrass(window);
}


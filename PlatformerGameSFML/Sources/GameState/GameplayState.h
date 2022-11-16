#pragma once
#include <SFML/Graphics.hpp>
#include "../GameConfig.h"
#include "../GameManager/ResourceManager.h"
#include "../GameObject/Player.h"
#include "../GameObject/Block.h"
#include "../GameObject/GameMap.h"
#include <vector>
using namespace std;
using namespace sf;
class GameplayState
{
private:
	Player player;
	GameMap map;
public:
	GameplayState();
	void update(float deltaTime);
	void draw(RenderWindow& window);
};
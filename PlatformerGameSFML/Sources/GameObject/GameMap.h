#pragma once
#include "SFML/Graphics.hpp"
#include "Block.h"
#include"../GameConfig.h"
#include "../GameManager/ResourceManager.h"
#include "Player.h"
#include <vector>
using namespace sf;
using namespace std;
class GameMap
{
private:
	Sprite background;
	vector<RectangleShape> grasses;
	RectangleShape baseGrass;
	vector<Block> blocks;
	void generateMap(int matrix[mapRow+1][mapColumn+1]);
public:
	GameMap() {};
	GameMap(int mapID);
	void update(float deltaTime,Player &player);
	void drawBlock(RenderWindow& window);
	void drawGrass(RenderWindow& window);
};


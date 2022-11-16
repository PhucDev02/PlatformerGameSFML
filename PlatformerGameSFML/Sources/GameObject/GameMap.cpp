#include "GameMap.h"

void GameMap::generateMap(int matrix[mapRow + 1][mapColumn + 1])
{
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			if (matrix[i][j] == 13 || matrix[i][j] == 14)
			{
				baseGrass.setPosition(j * widthBlock, i * widthBlock);
				if (matrix[i][j] == 13)
					baseGrass.setTexture(DATA->getTexture("environment/grass2"));
				if (matrix[i][j] == 14)
					baseGrass.setTexture(DATA->getTexture("environment/grass1"));
				grasses.push_back(baseGrass);
			}
			else
			{
				switch (matrix[i][j])
				{
				case 2:
					blocks.push_back(Block(DATA->getTexture("environment/block"), Vector2f(j * widthBlock, i * widthBlock)));
					break;
				case 6:
					blocks.push_back(Block(DATA->getTexture("environment/ground"), Vector2f(j * widthBlock, i * widthBlock)));
					break;
				case 8: 
					blocks.push_back(Block(DATA->getTexture("environment/woodBox"), Vector2f(j * widthBlock, i * widthBlock)));
					break;
				/*default:
					blocks.push_back(Block(DATA->getTexture("environment/block"), Vector2f(j * widthBlock, i * widthBlock)));
					break;*/
				}
			}
		}
	}
}

GameMap::GameMap(int mapID)
{
	baseGrass.setTexture(DATA->getTexture("environment/grass1"));
	baseGrass.setSize(Vector2f(widthBlock, widthBlock));
	baseGrass.setOrigin(baseGrass.getSize() / 2.0f);
	int matrix[16][61] = map1;
	generateMap(matrix);
	//switch (mapID)	//{
	//case 1:
	//	generateMap(matrix);
	//	break;
	//default:
	//	int matrix[16][61] = map1;
	//	generateMap(matrix);
	//	break;
	//}

}
void GameMap::update(float deltaTime, Player& player)
{
	int direction = 0;
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].getCollider().checkCollisionVsPlayer(player.getCollider(), direction);
	}
	player.OnCollision(direction);
}

void GameMap::drawBlock(RenderWindow& window)
{
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].draw(window);
	}
}

void GameMap::drawGrass(RenderWindow& window)
{
	for (int i = 0; i < grasses.size(); i++)
	{
		window.draw(grasses[i]);
	}
}

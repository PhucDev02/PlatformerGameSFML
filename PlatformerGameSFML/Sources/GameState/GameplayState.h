#pragma once
#include <SFML/Graphics.hpp>
#include "../GameConfig.h"
#include "../GameManager/ResourceManager.h"
#include <vector>
using namespace std;
using namespace sf;
class GameplayState
{
private:
public:
	GameplayState();
	void update(float deltaTime);
	void draw(RenderWindow& window);
};
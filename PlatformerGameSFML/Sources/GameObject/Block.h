#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"
using namespace sf;
class Block
{
private:
	RectangleShape body;
public:
	Block() {};
	Block(Texture* texture, Vector2f position);
	void draw(RenderWindow& window);
	Collider getCollider();
};
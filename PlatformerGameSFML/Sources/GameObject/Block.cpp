#pragma once
#include "Block.h"
#include "../GameConfig.h"

Block::Block(Texture* texture, Vector2f position)
{
	body.setTexture(texture);
	body.setSize((Vector2f)texture->getSize());
	body.setOrigin((Vector2f)texture->getSize() / 2.0f);
	body.setPosition(position);
}

void Block::draw(RenderWindow& window)
{
	window.draw(body);
}

Collider Block::getCollider()
{
	return Collider(body);
}

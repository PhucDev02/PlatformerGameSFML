#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Collider
{
private:
	RectangleShape& body;
public:
	Collider(RectangleShape& body);
	bool checkCollisionVsPlayer(Collider other,int &direction);
	Vector2f getPosition() { return body.getPosition(); }
	Vector2f getHalfSize()
	{
		return body.getSize() / 2.0f;
	}
	void move(float dx, float dy) {
		body.move(dx, dy);
	}
};


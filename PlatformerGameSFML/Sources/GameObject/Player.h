#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "../GameConfig.h"
#include "Collider.h"
using namespace sf;
enum class Status {
	RUN,IDLE,JUMP,FALL
};
class Player
{
private:
	RectangleShape body;
	Animation run, idle,jump,fall;
	Vector2f velocity;
	Status status;
	float speed ,jumpHeight;
	bool isOnGround;
public:
	Player();
	void update(float deltaTime);
	void draw(RenderWindow& window);
	void updateAnimation(float deltaTime);
	void OnCollision(int direction);
	Collider getCollider();
};


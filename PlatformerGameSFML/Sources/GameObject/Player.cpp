#include "Player.h"
#include <iostream>
Player::Player()
{
	status = Status::RUN;
	idle = Animation("player/idle/", 4, 0.2f);
	run = Animation("player/run/", 6, 0.1f);
	jump = Animation("player/jump/", 1, 5.f);
	fall = Animation("player/fall/", 1, 5.f);
	
	body.setTexture(idle.getTexture());
	body.setSize((Vector2f)idle.getTexture()->getSize());
	body.setPosition(100, 200);
	body.setOrigin(body.getSize() / 2.0f);

	isOnGround = false;
	jumpHeight = 200.f;
	speed = 300.f;
}

void Player::update(float deltaTime)
{
#pragma region Horizontal movement

	velocity.x = 0;
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		velocity.x -= speed;
	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		velocity.x += speed;

	if (velocity.x != 0)
		if (velocity.x > 0) body.setScale(1, 1);
		else body.setScale(-1, 1);
	body.move(velocity.x * deltaTime, 0);

#pragma endregion

#pragma region Vertical movement
	//jump
	if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && isOnGround == true)
	{
		isOnGround = false;
		velocity.y = -sqrt(gravity * 2.0f * jumpHeight);
	}
	//fall
	velocity.y += gravity * deltaTime;
	body.move(0, velocity.y * deltaTime);
	if (body.getPosition().y > 700)
	{
		velocity.y = 0;
		body.setPosition(body.getPosition().x, 700);
		isOnGround = true;
	}
#pragma endregion

}
void Player::draw(RenderWindow& window)
{
	window.draw(body);
}

void Player::updateAnimation(float deltaTime)
{
	//call this function after update() func
	if (velocity.y != 0)
		if (velocity.y < 0)
			status = Status::JUMP;
		else
			status = Status::FALL;
	else if (velocity.x != 0)
		status = Status::RUN;
	else
		status = Status::IDLE;
	switch (status)
	{
	case Status::RUN:
		run.update(deltaTime);
		body.setTexture(run.getTexture());
		break;
	case Status::IDLE:
		idle.update(deltaTime);
		body.setTexture(idle.getTexture());
		break;
	case Status::JUMP:
		jump.update(deltaTime);
		body.setTexture(jump.getTexture());
		break;
	case Status::FALL:
		fall.update(deltaTime);
		body.setTexture(fall.getTexture());
	default:
		break;
	}
}

Collider Player::getCollider()
{
	return Collider(body);
}

void Player::OnCollision(int direction)
{
	if (direction == 1) //stand on
	{
		isOnGround = true;
		velocity.y = 0;
		status = Status::IDLE;
	}
	if (direction == -1)
	{
		velocity.y = 0;
	}
	if (direction == 0)  isOnGround = false;
}

#include "Collider.h"

Collider::Collider(RectangleShape& body)
	:body(body)
{
}

bool Collider::checkCollisionVsPlayer(Collider player,int &direction)
{
	//only effect on player 
	Vector2f playerPosition = player.getPosition();
	Vector2f playerHalfSize = player.getHalfSize();
	Vector2f thisPosition = getPosition();
	Vector2f thisHalfSize = getHalfSize();

	float deltaX = playerPosition.x - thisPosition.x;
	float deltaY = playerPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (playerHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (playerHalfSize.y + thisHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f) 
	{
		if ((intersectX) > (intersectY)) // response at right or left
		{
			if (playerPosition.x > thisPosition.x) //player collide at right
			{
				player.move(-intersectX, 0.0f);
			}
			else
			{
				player.move(intersectX, 0.0f);
			}
			direction = 0;
		}
		else
		{
			if (playerPosition.y > thisPosition.y)
			{
				player.move(0.0f, -intersectY);
				direction = -1;
			}
			else//standOn
			{
				player.move(0.0f, intersectY);
				direction = 1;
			}
		}
		return true;
	}
	return false;
}

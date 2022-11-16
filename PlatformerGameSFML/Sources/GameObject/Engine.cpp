#include "Engine.h"
Engine::Engine()
{
	state = State::GAMEPLAY;
}
void Engine::init()
{
	state = State::GAMEPLAY;
}

void Engine::update(float deltaTime)
{
	if (state == State::GAMEPLAY)
	{
		gameplayState.update(deltaTime);
		
	}
}

void Engine::draw(RenderWindow& window)
{
	if (state == State::GAMEPLAY)
	{
		gameplayState.draw(window);
	}
}

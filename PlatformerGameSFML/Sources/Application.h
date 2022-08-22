#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject/Engine.h"
#include "GameConfig.h"
using namespace sf;
class Application {
private:
	void Init();
	void Update(float deltaTime);
	void Render();

	//all object of game
	Image icon;
	Engine engine;
	RenderWindow* window;
public:
	void Run();
	~Application();
	Application();

};
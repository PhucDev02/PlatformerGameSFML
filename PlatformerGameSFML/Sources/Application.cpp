#include"Application.h"
Application::Application()
{
	srand(time(NULL));
}
void Application::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);
	window->setFramerateLimit(fpsLimit);
	window->setVerticalSyncEnabled(false);

	engine.init();
}
void Application::Update(float deltaTime)
{
	//update sth
	engine.update(deltaTime);
}
void Application::Render()
{
	window->clear();
	//draw sth
	engine.draw(*window);
	//
	window->display();
}
Application::~Application()
{
	if (window != nullptr)
		delete window;
}
void Application::Run()
{
	Init();
	sf::Clock clock;
	float deltaTime = 0.f;
	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event event;
		while (window->pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{

				window->close();
			}
			if (event.type == Event::Closed)
				window->close();
		}
		Update(deltaTime);
		Render();
	}
}
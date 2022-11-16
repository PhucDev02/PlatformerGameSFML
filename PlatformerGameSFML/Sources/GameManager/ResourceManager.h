#pragma once
#include <map>
#include <list>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Singleton.h"
#include <cstdlib>
#include <ctime>

#define DATA ResourceManager::GetInstance()

class ResourceManager :public CSingleton<ResourceManager> {
public:
	ResourceManager();
	~ResourceManager();

	sf::Texture* getTexture(std::string name);

	sf::Font* getFont(std::string name);

	sf::Sound* getSound(std::string name);

	sf::Music* getMusic(std::string name);

	void playMusic(std::string name);
	void playSound(std::string name);
	void changeAllowMusic();




private:
	std::map<std::string, sf::Texture*> m_MapTexture;
	std::map<std::string, sf::Font*> m_MapFont;
	std::map<std::string, sf::Sound*> m_MapSound;
	std::map<std::string, sf::Music*> m_MapMusic;

	std::string m_Path;
	std::string m_TexturePath;
	std::string m_FontPath;
	std::string m_SoundPath;

	bool m_allowSound;
};
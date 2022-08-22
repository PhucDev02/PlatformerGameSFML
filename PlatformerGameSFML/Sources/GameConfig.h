#pragma once
#define pi 3.14159
#define screenWidth 1920
#define screenHeight 1080
#define mapWidth 6000
#define titleGame "PlatformerGameSFML"
#define widthBlock 48
#define fpsLimit 500
enum class State {
	MENU, GAME_OVER, GAMEPLAY, ABOUT, HOW_TO_PLAY, SETTING, VICTORY, CHOOSE_MAP
};
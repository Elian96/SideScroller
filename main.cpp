#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "GameMenu/GameMenu.h"
#include "StateMachine/StateMachine.h"
#include "GlobalVars.h"
#include "Levels/Levels.h"
#include "Level1/Level1.h"

using namespace std;

bool fullScreen = false;
bool sound = true;
bool music = true;
int level;
sf::RenderWindow window(sf::VideoMode(width, height), "Platformer");

int main() {


    window.setView(window.getDefaultView());
    GameMenu gameMenu(width, height);
    StateMachine stateMachine;
    stateMachine.SendSignal(Signals::menu, window, fullScreen, sound, music, level);

    return 0;
}

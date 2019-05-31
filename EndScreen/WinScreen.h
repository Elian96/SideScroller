#ifndef ASSIGNMENT_6_WINSCREEN_H
#define ASSIGNMENT_6_WINSCREEN_H


#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>

class WinScreen {
public:

    WinScreen();
    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    sf::Font font;
    sf::Sprite menuPanel;
    sf::Texture MenuPanel;
    sf::Sprite Background;
    int moneyTotal = 0 ;
    int coinTotal = 0;
    sf::Text MoneyText;
    int score=0;
    sf::Text scoreText;
    sf::Sprite buttons;
    std::string str[8];
    std::ifstream LevelScore;
    std::ifstream Score;
    int NewScore;
};



#endif //ASSIGNMENT_6_WINSCREEN_H

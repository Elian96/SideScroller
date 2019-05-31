#ifndef ASSIGNMENT_6_LOSESCREEN_H
#define ASSIGNMENT_6_LOSESCREEN_H


#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

class LoseScreen {

public:
    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    void MoveUp();

    void MoveDown();

    int GetItemSelect() { return ItemSelect; }


    int ItemSelect;
    sf::Font font;
    sf::Sprite menuPanel;
    sf::Texture MenuPanel;
    sf::Texture BackBtn;
    sf::Texture RetryBtn;
    sf::Texture ExitBtn;
    sf::Texture BtnHighlight;
    sf::Texture BtnNotHighlight;
    sf::Sprite Background;
    sf::Sprite buttons[3];
    sf::Sprite btnHighligh[3];
};



#endif //ASSIGNMENT_6_LOSESCREEN_H

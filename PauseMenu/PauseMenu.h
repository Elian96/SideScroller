//
// Created by elyan on 11/16/2018.
//

#ifndef ASSIGNMENT_6_PAUSEMENU_H
#define ASSIGNMENT_6_PAUSEMENU_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

class PauseMenu {

public:
    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    void MoveUp();

    void MoveDown();

    int GetItemSelect() { return ItemSelect; }


    int ItemSelect;
    sf::Font font;
    sf::Sprite menuPanel;
    sf::Texture MenuPanel;
    sf::Texture ResumeBtn;
    sf::Texture BackBtn;
    sf::Texture ExitBtn;
    sf::Texture BtnHighlight;
    sf::Texture BtnNotHighlight;

    sf::Sprite btnHighligh[3];
    sf::Sprite buttons[3];
};




#endif //ASSIGNMENT_6_PAUSEMENU_H

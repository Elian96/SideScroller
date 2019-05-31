#ifndef ASSIGNMENT_6_GAMEMENU_H
#define ASSIGNMENT_6_GAMEMENU_H

#include <SFML/Graphics.hpp>

class GameMenu {
public:
    GameMenu(float width, float height);

    ~GameMenu();

    void draw(sf::RenderWindow &window);

    void MoveUp();

    void MoveDown();

    int GetItemSelect() { return ItemSelect; }

private:
    int ItemSelect;
    sf::Font font;
    sf::Texture MenuPanel;
    sf::Texture PlayButton;
    sf::Texture ScoreButton;
    sf::Texture UpgradesButton;
    sf::Texture SettingButton;
    sf::Texture ExitButton;
    sf::Texture BtnHighlight;
    sf::Texture BtnNotHighlight;
    sf::Sprite buttons[5];
    sf::Sprite btnHighligh[5];

};

#endif //ASSIGNMENT_6_GAMEMENU_H

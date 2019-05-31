#ifndef ASSIGNMENT_6_UPGRADES_H
#define ASSIGNMENT_6_UPGRADES_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../GlobalVars.h"

class Upgrades {

public:

    Upgrades();
    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    void MoveUp();

    void MoveDown();

    int GetItemSelect() { return ItemSelect; }

private:
    int ItemSelect;
    int HealthLevel = 1;
    int StrengthLevel = 1;
    int SpeedLevel = 1;
    sf::Font font;
    sf::Texture UpgradesPanel;
    sf::Texture Health;
    sf::Texture Strength;
    sf::Texture Speed;
    sf::Texture Jump;
    sf::Texture Money;
    sf::Texture Back;
    sf::Texture BtnHighlight;
    sf::Texture BtnNotHighlight;
    sf::Sprite btnHighligh[4];
    sf::Sprite buttons[4];
    sf::Sprite money;

    int moneyTotal = 0 ;
    sf::Text MoneyText;
    int healthCost = 50;
    sf::Text HealthText;
    int strengthCost = 50;
    sf::Text StrengthText;
    int speedCost = 50;
    sf::Text SpeedText;
    std::string upg[4];


};


#endif //ASSIGNMENT_6_UPGRADES_H

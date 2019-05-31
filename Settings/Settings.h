#ifndef ASSIGNMENT_6_SETTINGS_H
#define ASSIGNMENT_6_SETTINGS_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>

class Settings {

public:
    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    void MoveUp();

    void MoveDown();

    int GetItemSelect() { return ItemSelect; }

private:
    int ItemSelect;
//    bool sound= true;
//    bool music=true;
    sf::Font font;
    sf::Texture MenuPanel;
    sf::Texture MuteSound;
    sf::Texture MuteMusic;
    sf::Texture FullScreen;
    sf::Texture MutedSound;
    sf::Texture MutedMusic;
    sf::Texture ClearButton;
    sf::Texture WindowScreen;
    sf::Texture Back;
    sf::Texture BtnHighlight;
    sf::Texture BtnNotHighlight;

    sf::Sprite btnHighligh[6];
    sf::Sprite buttons[6];

    std::ofstream CleanMoney;
    std::ofstream CleanUpgrades;
    std::ofstream CleanScore;

    void ClearProgress();
};


#endif //ASSIGNMENT_6_SETTINGS_H

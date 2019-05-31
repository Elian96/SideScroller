#ifndef ASSIGNMENT_6_LEVELS_H
#define ASSIGNMENT_6_LEVELS_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Levels {

public:
    Levels(float width, float height);

    ~Levels();

    void draw(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    void MoveUp();

    void MoveDown();

    int GetLevelSelect() { return LevelSelect; }

private:

    int LevelSelect;
    sf::Texture LevelsPanel;
    sf::Font font;
    sf::Texture level1;
    sf::Texture level2;
    sf::Texture level3;
    sf::Texture level4;
    sf::Texture level5;
    sf::Texture level6;
    sf::Texture level7;
    sf::Texture level8;
    sf::Texture LevelHighlight;
    sf::Texture LevelNotHighlight;

    sf::Sprite levelChoice[8];
    sf::Sprite levelHighlight[8];
};


#endif //ASSIGNMENT_6_LEVELS_H

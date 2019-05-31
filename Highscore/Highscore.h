#ifndef ASSIGNMENT_6_HIGHSCORE_H
#define ASSIGNMENT_6_HIGHSCORE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../GlobalVars.h"


class Highscore {

public:

    Highscore();

    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    int GetItemSelect() { return ItemSelect; }

private:
    int ItemSelect = 0;                 //Variable to check which button are we on
    int level1Score = 0;                //Variable to save the score for level 1
    int level2Score = 0;                //Variable to save the score for level 2
    int level3Score = 0;                //Variable to save the score for level 3
    int level4Score = 0;                //Variable to save the score for level 4
    int level5Score = 0;                //Variable to save the score for level 5
    int level6Score = 0;                //Variable to save the score for level 6
    int level7Score = 0;                //Variable to save the score for level 7
    int level8Score = 0;                //Variable to save the score for level 8

    sf::Font font;                      //Font for the text showed on the screen
    sf::Texture HighscorePanel;         //Texture for the graphics of the panel behind the scores
    sf::Texture level1;                 //Texture for the graphics of level 1 score
    sf::Texture level2;                 //Texture for the graphics of level 2 score
    sf::Texture level3;                 //Texture for the graphics of level 3 score
    sf::Texture level4;                 //Texture for the graphics of level 4 score
    sf::Texture level5;                 //Texture for the graphics of level 5 score
    sf::Texture level6;                 //Texture for the graphics of level 6 score
    sf::Texture level7;                 //Texture for the graphics of level 7 score
    sf::Texture level8;                 //Texture for the graphics of level 8 score
    sf::Sprite levels[9];               //Sprites that will be shown on the screen
    sf::Texture Back;                   //Texture for the back button
    sf::Texture highlighter;            //Texture for the highlight icon for the button
    sf::Sprite highlight;               //Sprite that will show the highlight icon on the screen
    std::string str[8];                 //A string that contains the scores from the text file
    sf::Sprite highscorepanel;          //Sprite that will show the panel behind the scores
    sf::Texture textureBackground;      //Texture for the graphics of the background image
    sf::Sprite background;              //Sprite that will show the background image


};


#endif //ASSIGNMENT_6_HIGHSCORE_H

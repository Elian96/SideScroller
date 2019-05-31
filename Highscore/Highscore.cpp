#include "Highscore.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "../GlobalVars.h"
#include "../StateMachine/StateMachine.h"

using namespace std;

Highscore::Highscore() {

    std::ifstream Score("Highscore/score.txt");     //Open a txt file that contains the scores of eac level

    for (int j = 0; j < 8; ++j) {
        Score >> str[j];                            //Put each line from the text file into an element in the strin

    }
    level1Score = stoi(
            str[0]);                    //Appoint the first line from the text file as an integer to a new integer to save it
    level2Score = stoi(
            str[1]);                    //Appoint the second line from the text file as an integer to a new integer to save it
    level3Score = stoi(
            str[2]);                    //Appoint the third line from the text file as an integer to a new integer to save it
    level4Score = stoi(
            str[3]);                    //Appoint the fourth line from the text file as an integer to a new integer to save it
    level5Score = stoi(
            str[4]);                    //Appoint the fifth line from the text file as an integer to a new integer to save it
    level6Score = stoi(
            str[5]);                    //Appoint the sixth line from the text file as an integer to a new integer to save it
    level7Score = stoi(
            str[6]);                    //Appoint the seventh line from the text file as an integer to a new integer to save it
    level8Score = stoi(
            str[7]);                    //Appoint the eighth line from the text file as an integer to a new integer to save it
    Score.close();                      //Close the file so the memory won't leak

    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");                      //The font used for the texts on the screen
    level1.loadFromFile("Highscore/level1score0.png");                      //The icon for level 1 score
    level2.loadFromFile("Highscore/level2score0.png");                      //The icon for level 2 score
    level3.loadFromFile("Highscore/level3score0.png");                      //The icon for level 3 score
    level4.loadFromFile("Highscore/level4score0.png");                      //The icon for level 4 score
    level5.loadFromFile("Highscore/level5score0.png");                      //The icon for level 5 score
    level6.loadFromFile("Highscore/level6score0.png");                      //The icon for level 6 score
    level7.loadFromFile("Highscore/level7score0.png");                      //The icon for level 7 score
    level8.loadFromFile("Highscore/level8score0.png");                      //The icon for level 8 score
    highlighter.loadFromFile("UpgradeButtons/UpgradeHighlight.png");        //The icon for the highlighter
    Back.loadFromFile("Buttons/BackBtn.png");                               //The image for the back button

    HighscorePanel.loadFromFile("Highscore/ScorePanel.png");                //The image for the panel behind the scores
    highscorepanel.setPosition(width / 2 - 290, height / 8);                //The position for the panel on the screen
    highscorepanel.setTexture(HighscorePanel);                              //The sprite for the panel
    textureBackground.loadFromFile("data/MainBackground.png");              //The image for the background
    background.setTexture(textureBackground);                               //The sprite for the background
}

bool Highscore::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {

    if (level1Score >= 200 && level1Score < 450) {                  //Put the limits for the 1 star score
        level1.loadFromFile("Highscore/level1score1.png");          //Change to image for the chosen level

    } else if (level1Score >= 450 && level1Score < 1000) {          //Put the limits for the 2 star score
        level1.loadFromFile("Highscore/level1score2.png");          //Change to image for the chosen level

    } else if (level1Score >= 1000) {                               //Put the limits for the 3 star score
        level1.loadFromFile("Highscore/level1score3.png");          //Change to image for the chosen level
    }

    if (level2Score >= 200 && level2Score < 450) {                  //Put the limits for the 1 star score
        level2.loadFromFile("Highscore/level2score1.png");          //Change to image for the chosen level

    } else if (level2Score >= 450 && level2Score < 1000) {          //Put the limits for the 2 star score
        level2.loadFromFile("Highscore/level2score2.png");          //Change to image for the chosen level

    } else if (level2Score >= 1000) {                               //Put the limits for the 3 star score
        level2.loadFromFile("Highscore/level2score3.png");          //Change to image for the chosen level
    }

    if (level3Score >= 200 && level3Score < 450) {                  //Put the limits for the 1 star score
        level3.loadFromFile("Highscore/level3score1.png");          //Change to image for the chosen level

    } else if (level3Score >= 450 && level3Score < 1000) {          //Put the limits for the 2 star score
        level3.loadFromFile("Highscore/level3score2.png");          //Change to image for the chosen level

    } else if (level3Score >= 1000) {                               //Put the limits for the 3 star score
        level3.loadFromFile("Highscore/level3score3.png");          //Change to image for the chosen level
    }

    if (level4Score >= 200 && level4Score < 450) {                  //Put the limits for the 1 star score
        level4.loadFromFile("Highscore/level4score1.png");          //Change to image for the chosen level

    } else if (level4Score >= 450 && level4Score < 1000) {          //Put the limits for the 2 star score
        level4.loadFromFile("Highscore/level4score2.png");          //Change to image for the chosen level

    } else if (level4Score >= 1000) {                               //Put the limits for the 3 star score
        level4.loadFromFile("Highscore/level4score3.png");          //Change to image for the chosen level
    }

    if (level5Score >= 200 && level5Score < 450) {                  //Put the limits for the 1 star score
        level5.loadFromFile("Highscore/level5score1.png");          //Change to image for the chosen level

    } else if (level5Score >= 450 && level5Score < 1000) {          //Put the limits for the 2 star score
        level5.loadFromFile("Highscore/level5score2.png");          //Change to image for the chosen level

    } else if (level5Score >= 1000) {                               //Put the limits for the 3 star score
        level5.loadFromFile("Highscore/level5score3.png");          //Change to image for the chosen level
    }

    if (level6Score >= 200 && level6Score < 450) {                  //Put the limits for the 1 star score
        level6.loadFromFile("Highscore/level6score1.png");          //Change to image for the chosen level

    } else if (level6Score >= 450 && level6Score < 1000) {          //Put the limits for the 2 star score
        level6.loadFromFile("Highscore/level6score2.png");          //Change to image for the chosen level

    } else if (level6Score >= 1000) {                               //Put the limits for the 3 star score
        level6.loadFromFile("Highscore/level6score3.png");          //Change to image for the chosen level
    }

    if (level7Score >= 200 && level7Score < 450) {                  //Put the limits for the 1 star score
        level7.loadFromFile("Highscore/level7score1.png");

    } else if (level7Score >= 450 && level7Score < 1000) {          //Put the limits for the 2 star score
        level7.loadFromFile("Highscore/level7score2.png");

    } else if (level7Score >= 1000) {                               //Put the limits for the 3 star score
        level7.loadFromFile("Highscore/level7score3.png");
    }

    if (level8Score >= 200 && level8Score < 450) {                  //Put the limits for the 1 star score
        level8.loadFromFile("Highscore/level8score1.png");

    } else if (level8Score >= 450 && level8Score < 1000) {          //Put the limits for the 2 star score
        level8.loadFromFile("Highscore/level8score2.png");

    } else if (level8Score >= 1000) {                               //Put the limits for the 3 star score
        level8.loadFromFile("Highscore/level8score3.png");
    }


    levels[0].setTexture(level1);                                   //Set the texture for level 1
    levels[0].setPosition(width / 2 - 250, height / 8 * 2);         //Set the position for the level 1

    levels[1].setTexture(level2);                                   //Set the texture for level 2
    levels[1].setPosition(width / 2 - 250, height / 8 * 3);         //Set the position for the level 2

    levels[2].setTexture(level3);                                   //Set the texture for level 3
    levels[2].setPosition(width / 2 - 250, height / 8 * 4);         //Set the position for the level 3

    levels[3].setTexture(level4);                                   //Set the texture for level 4
    levels[3].setPosition(width / 2 - 250, height / 8 * 5);         //Set the position for the level 4

    levels[4].setTexture(level5);                                   //Set the texture for level 5
    levels[4].setPosition(width / 2 + 20, height / 8 * 2);          //Set the position for the level 5

    levels[5].setTexture(level6);                                   //Set the texture for level 6
    levels[5].setPosition(width / 2 + 20, height / 8 * 3);          //Set the position for the level 6

    levels[6].setTexture(level7);                                   //Set the texture for level 7
    levels[6].setPosition(width / 2 + 20, height / 8 * 4);          //Set the position for the level 7

    levels[7].setTexture(level8);                                   //Set the texture for level 8
    levels[7].setPosition(width / 2 + 20, height / 8 * 5);          //Set the position for the level 8

    levels[8].setTexture(Back);                                     //Set the texture for the back button
    levels[8].setPosition(width / 2 - 180, height / 8 * 6);         //Set the position for the back button
    highlight.setTexture(highlighter);                              //Set the texture for the highlight icon
    highlight.setPosition(width / 2 - 220, height / 8 * 6);         //Set the position for the highlight icon


    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Return:

                            switch (GetItemSelect()) {              //Check what number is the itemselect variable is on

                                case 0:                             //If the itemselect variable is 0
                                    StateMachine StateMachine;      //Call the state machine
                                    //Send the signal to go back
                                    StateMachine.SendSignal(Signals::menu, window, fullScreen, sound, music, level);
                                    break;
                            }
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.draw(background);                //Draw tha background image on the screen
        window.draw(highscorepanel);            //Draw tha panel image on the screen

        for (int i = 0; i < 9; ++i) {
            window.draw(levels[i]);
        }
        window.draw(highlight);                 //Draw tha highlight icon on the screen
        window.display();                       //Show on the screen
    }


    return true;
}

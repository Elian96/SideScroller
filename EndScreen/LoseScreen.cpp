#include "LoseScreen.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <fstream>
#include "../GlobalVars.h"
#include "../StateMachine/StateMachine.h"

bool LoseScreen::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {

    StateMachine StateMachine;
    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    BackBtn.loadFromFile("PauseMenu/BackBtn.png");
    RetryBtn.loadFromFile("Buttons/RetryBtn.png");
    ExitBtn.loadFromFile("Buttons/ExitBtn.png");
    BtnHighlight.loadFromFile("PauseMenu/BtnHighlight.png");
    BtnNotHighlight.loadFromFile("PauseMenu/BtnNotHighlight.png");
    MenuPanel.loadFromFile("EndScreen/LosePanel.png");

    std::ofstream CleanLevelScore;
    CleanLevelScore.open("Highscore/LevelScore.txt", std::ofstream::trunc);
    CleanLevelScore.close();

    buttons[0].setTexture(RetryBtn);
    buttons[0].setPosition(width / 2 - 165, height / 7 * 3-100);

    btnHighligh[0].setTexture(BtnHighlight);
    btnHighligh[0].setPosition(width / 2 + 220, height / 7 * 3 -100);

    buttons[1].setTexture(BackBtn);
    buttons[1].setPosition(width / 2 - 165, height / 7 * 3 -5);

    btnHighligh[1].setTexture(BtnNotHighlight);
    btnHighligh[1].setPosition(width / 2 + 220, height / 7 * 3 -5);

    buttons[2].setTexture(ExitBtn);
    buttons[2].setPosition(width / 2 - 165, height / 7 * 3 + 90);

    btnHighligh[2].setTexture(BtnNotHighlight);
    btnHighligh[2].setPosition(width / 2 + 220, height / 7 * 3 + 90);

    ItemSelect = 0;

    menuPanel.setPosition(width / 2-280, height / 5-10);
    menuPanel.setTexture(MenuPanel);

    sf::Texture textureBackground;
    textureBackground.loadFromFile("data/MainBackground.png");
    Background.setTexture(textureBackground);
    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            MoveUp();
                            break;
                            //Get the function MoveDown from the GameMenu class
                        case sf::Keyboard::Down:
                            MoveDown();
                            break;
                        case sf::Keyboard::Return:

                            switch (GetItemSelect()) {
                                case 0:
                                    std::cout << "Retry Level" << std::endl;
                                    if (level == 1) {
                                        StateMachine.SendSignal(Signals::level1, window, fullScreen, sound, music, level);
                                    }else if (level == 2) {
                                        StateMachine.SendSignal(Signals::level2, window, fullScreen, sound, music, level);
                                    } else if (level == 3) {
                                        StateMachine.SendSignal(Signals::level3, window, fullScreen, sound, music, level);
                                    }else if (level == 4) {
                                        StateMachine.SendSignal(Signals::level4, window, fullScreen, sound, music, level);
                                    }
                                    break;
                                case 2:
                                    window.close();
                                    exit(0);
                                case 1:
                                    StateMachine.SendSignal(Signals::menu, window, fullScreen, sound, music, level);
                                    break;
                            }
                            break;

                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }

        }

        window.setView(window.getDefaultView());
        window.draw(Background);
        window.draw(menuPanel);
        window.draw(menuPanel);
        for (int i = 0; i < 3; ++i) {
            window.draw(buttons[i]);
            window.draw(btnHighligh[i]);
        }
        window.display();
    }


    return true;
}

void LoseScreen::MoveUp() {
    if (ItemSelect - 1 >= 0) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect--;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}

void LoseScreen::MoveDown() {
    if (ItemSelect + 1 < 3) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect++;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}
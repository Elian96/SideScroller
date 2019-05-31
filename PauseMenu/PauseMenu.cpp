#include "PauseMenu.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "../GlobalVars.h"
#include "../StateMachine/StateMachine.h"

bool PauseMenu::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {

    StateMachine StateMachine;
    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    ResumeBtn.loadFromFile("PauseMenu/ResumeBtn.png");
    ExitBtn.loadFromFile("PauseMenu/ExitBtn.png");
    BackBtn.loadFromFile("PauseMenu/BackBtn.png");
    BtnHighlight.loadFromFile("PauseMenu/BtnHighlight.png");
    BtnNotHighlight.loadFromFile("PauseMenu/BtnNotHighlight.png");

    buttons[0].setTexture(ResumeBtn);
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
    sf::Texture textureBackground;
    textureBackground.loadFromFile("data/MainBackground.png");

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
                                    std::cout << "Resume Game" << std::endl;
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

        //window.draw(background);
        MenuPanel.loadFromFile("PauseMenu/pausePanel.png");
        menuPanel.setPosition(width / 2-280, height / 4);
        menuPanel.setTexture(MenuPanel);

        window.setView(window.getDefaultView());
        window.draw(menuPanel);
        for (int i = 0; i < 3; ++i) {
            window.draw(buttons[i]);
            window.draw(btnHighligh[i]);
        }
        window.display();
    }


    return true;
}

void PauseMenu::MoveUp() {
    if (ItemSelect - 1 >= 0) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect--;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}

void PauseMenu::MoveDown() {
    if (ItemSelect + 1 < 3) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect++;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}
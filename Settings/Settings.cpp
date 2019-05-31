#include <iostream>
#include "Settings.h"
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
#include "../GlobalVars.h"
#include "../StateMachine/StateMachine.h"


bool Settings::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {


    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    MuteSound.loadFromFile("Buttons/MuteSound.png");
    MuteMusic.loadFromFile("Buttons/MuteMusic.png");
    MutedSound.loadFromFile("Buttons/SoundMuted.png");
    MutedMusic.loadFromFile("Buttons/MusicMuted.png");
    WindowScreen.loadFromFile("Buttons/WindowScreen.png");
    FullScreen.loadFromFile("Buttons/FullScreen.png");
    ClearButton.loadFromFile("Buttons/ClearBtn.png");
    Back.loadFromFile("Buttons/BackBtn.png");
    BtnHighlight.loadFromFile("Buttons/BtnHighlight.png");
    BtnNotHighlight.loadFromFile("Buttons/BtnNotHighlight.png");

    if (sound) {
        buttons[0].setTexture(MuteSound);
        buttons[0].setPosition(width / 2 - 180, height / 7 * 2);
    } else if (!sound) {
        buttons[0].setTexture(MutedSound);
        buttons[0].setPosition(width / 2 - 180, height / 7 * 2);
    }

    btnHighligh[0].setTexture(BtnHighlight);
    btnHighligh[0].setPosition(width / 2 - 220, height / 7 * 2);

    if (music) {
        buttons[1].setTexture(MuteMusic);
        buttons[1].setPosition(width / 2 - 180, height / 7 * 3 - 50);
    } else if (!music) {
        buttons[1].setTexture(MutedMusic);
        buttons[1].setPosition(width / 2 - 180, height / 7 * 3 - 50);
    }

    btnHighligh[1].setTexture(BtnNotHighlight);
    btnHighligh[1].setPosition(width / 2 - 220, height / 7 * 3 - 50);

    if (!fullScreen) {
        buttons[2].setTexture(WindowScreen);
        buttons[2].setPosition(width / 2 - 180, height / 7 * 4 - 100);
    } else if (fullScreen) {
        buttons[2].setTexture(FullScreen);
        buttons[2].setPosition(width / 2 - 180, height / 7 * 4 - 100);
    }
    btnHighligh[2].setTexture(BtnNotHighlight);
    btnHighligh[2].setPosition(width / 2 - 220, height / 7 * 4 - 100);

    buttons[3].setTexture(ClearButton);
    buttons[3].setPosition(width / 2 - 220, height / 7 * 5 - 150);

    btnHighligh[3].setTexture(BtnNotHighlight);
    btnHighligh[3].setPosition(width / 2 - 220, height / 7 * 5 - 150);

    buttons[4].setTexture(Back);
    buttons[4].setPosition(width / 2 - 180, height / 7 * 6 - 200);

    btnHighligh[4].setTexture(BtnNotHighlight);
    btnHighligh[4].setPosition(width / 2 - 220, height / 7 * 6 - 200);

    ItemSelect = 0;
    sf::Texture textureBackground;
    textureBackground.loadFromFile("data/MainBackground.png");
    sf::Sprite background(textureBackground);

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
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::Return:

                            switch (GetItemSelect()) {
                                case 0:
                                    if (sound) {
                                        sound = false;
                                        buttons[0].setTexture(MutedSound);
                                    } else if (!sound) {
                                        sound = true;
                                        buttons[0].setTexture(MuteSound);
                                    }

                                    break;
                                case 1:
                                    if (music) {
                                        music = false;
                                        buttons[1].setTexture(MutedMusic);
                                    } else if (!music) {
                                        music = true;
                                        buttons[1].setTexture(MuteMusic);
                                    }
                                    break;
                                case 2:
                                    if (fullScreen) {
                                        fullScreen = false;
                                        window.create(sf::VideoMode(width, height), "Scroller");
                                        buttons[2].setTexture(WindowScreen);
                                    } else if (!fullScreen) {
                                        fullScreen = true;
                                        window.create(sf::VideoMode(width, height), "Scroller", sf::Style::Fullscreen);
                                        buttons[2].setTexture(FullScreen);
                                    }
                                    break;
                                case 3:
                                    ClearProgress();
                                case 4:
                                    StateMachine StateMachine;
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

        window.draw(background);
        MenuPanel.loadFromFile("Settings/SettingsPanel.png");
        sf::Sprite menuPanel;
        menuPanel.setPosition(width / 2 - 290, height / 8);
        menuPanel.setTexture(MenuPanel);
        window.setView(window.getDefaultView());
        window.draw(menuPanel);
        for (int i = 0; i < 5; ++i) {
            window.draw(buttons[i]);
            window.draw(btnHighligh[i]);
        }
        window.display();
    }


    return true;
}

void Settings::MoveUp() {
    if (ItemSelect - 1 >= 0) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect--;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}

void Settings::MoveDown() {
    if (ItemSelect + 1 < 5) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect++;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}

void Settings::ClearProgress() {

    CleanMoney.open("Upgrades/money.txt", std::ofstream::trunc);
    CleanMoney.close();
    CleanMoney.open("Upgrades/Upgrade.txt", std::ofstream::trunc);
    CleanMoney.close();;
    CleanMoney.open("Highscore/score.txt", std::ofstream::trunc);
    CleanMoney.close();
    std::ofstream ScoreWrite;
    ScoreWrite.open("Highscore/score.txt");
    for (int i = 0; i < 8; ++i) {
        ScoreWrite << 0 << std::endl;
    }

    ScoreWrite.close();

}

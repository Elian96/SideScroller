#include "WinScreen.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <fstream>
#include "../GlobalVars.h"
#include "../StateMachine/StateMachine.h"
#include "../Levels/LevelBuild.h"

WinScreen::WinScreen() {
    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    MenuPanel.loadFromFile("EndScreen/win0Stars.png");
    std::ifstream MoneyFile("Upgrades/money.txt");
    while (!MoneyFile.eof()) {
        MoneyFile >> moneyTotal;
    }
    MoneyFile.close();

    std::ifstream CoinFile("Upgrades/coin.txt");
    while (!CoinFile.eof()) {
        CoinFile >> coinTotal;

    }
    CoinFile.close();
    Score.open("Highscore/score.txt");     //Open a txt file that contains the scores of eac level
    for (int j = 0; j < 8; ++j) {
        Score >> str[j];                            //Put each line from the text file into an element in the strin
    }
    Score.close();
    LevelScore.open("Highscore/LevelScore.txt");
    while (!LevelScore.eof()){
        LevelScore >> NewScore;
    }
    moneyTotal += coinTotal;

    std::ofstream coin;
    coin.open("Upgrades/coin.txt", std::ofstream::trunc);
    coin.close();
    std::ofstream CleanMoney;
    CleanMoney.open("Upgrades/money.txt", std::ofstream::trunc);
    CleanMoney.close();

    std::ofstream AddMoney;
    AddMoney.open("Upgrades/money.txt");
    AddMoney << moneyTotal;
    AddMoney.close();

}

bool WinScreen::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {
    StateMachine StateMachine;
    std::ofstream LevelScoreWr;
    LevelScoreWr.open("Highscore/LevelScore.txt", std::ofstream::trunc);
    LevelScoreWr.close();

    std::ofstream ScoreWrite;
    ScoreWrite.open("Highscore/score.txt");
    for (int i = 0; i <8 ; ++i) {
        if (std::to_string(NewScore) > str[0] && level == 1){
            str[0] = std::to_string(NewScore);
        }else if (std::to_string(NewScore) > str[1] && level == 2){
            str[1] = std::to_string(NewScore);
        }else if (std::to_string(NewScore) > str[2] && level == 3){
            str[2] = std::to_string(NewScore);
        }else if (std::to_string(NewScore) > str[3] && level == 4){
            str[3] = std::to_string(NewScore);
        }
        ScoreWrite << str[i] << std::endl;
    }
    ScoreWrite.close();

    if (level == 1) {
        score = stoi(str[0]);
    } else if (level == 2) {
        score = stoi(str[1]);
    } else if (level == 3) {
        score = stoi(str[2]);
    } else if (level == 4) {
        score = stoi(str[3]);
    }
    if (score < 200) {
        MenuPanel.loadFromFile("EndScreen/win0Stars.png");

    } else if (score >= 200 && score < 450) {
        MenuPanel.loadFromFile("EndScreen/win1Stars.png");

    } else if (score >= 450 && score < 1000) {
        MenuPanel.loadFromFile("EndScreen/win2Stars.png");

    } else if (score >= 1000) {
        MenuPanel.loadFromFile("EndScreen/win3Stars.png");
    }
    scoreText.setFont(font);
    scoreText.setString(std::to_string(NewScore));
    scoreText.setPosition(width / 2 + 50, height / 7 * 3 + 42);

    MoneyText.setFont(font);
    MoneyText.setString(std::to_string(moneyTotal));
    MoneyText.setPosition(width / 2, height / 7 * 3 - 30);


    menuPanel.setPosition(width / 2 - 280, height / 5 - 10);
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
                        case sf::Keyboard::Return:
                            StateMachine.SendSignal(Signals::levels, window, fullScreen, sound, music, level);
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
        window.draw(MoneyText);
        window.draw(scoreText);
        window.display();
    }


    return true;
}


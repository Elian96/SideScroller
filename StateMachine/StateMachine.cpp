#include <iostream>
#include "StateMachine.h"
#include <SFML/Audio.hpp>
#include "../GlobalVars.h"
#include "../GameMenu/GameMenu.h"
#include "../Levels/Levels.h"
#include "../GameMenu/GameMenu.h"
#include "../Level1/Level1.h"
#include "../Settings/Settings.h"
#include "../Upgrades/Upgrades.h"
#include "../Highscore/Highscore.h"
#include "../Levels/LevelBuild.h"
#include "../PauseMenu/PauseMenu.h"
#include "../EndScreen/WinScreen.h"
#include "../EndScreen/LoseScreen.h"
#include "../Collectors/Collectors.h"

LevelBuild levelBuild;

StateMachine::StateMachine() {
    this->state = State::MENU;
}

StateMachine::~StateMachine() {

}

void StateMachine::SendSignal(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                              int level) {
    window.setView(window.getDefaultView());

    switch (state) {
        case State::MENU:
            state = StateMenu(signals, window, fullScreen, sound, music, level);
            break;
        case State::LEVELS:
            state = StateLevels(signals, window, fullScreen, sound, music, level);
            break;
        case State::HIGHSCORE:
            state = StateHighscore(signals, window, fullScreen, sound, music, level);
            break;
        case State::UPGRADES:
            state = StateUpgrades(signals, window, fullScreen, sound, music, level);
            break;
        case State::SETTINGS:
            state = StateSetting(signals, window, fullScreen, sound, music, level);
            break;
        case State::PAUSE:
            state = StatePause(signals, window, fullScreen, sound, music, level);
            break;

        case State::LEVEL1:
            //state = StateLevel1(signals, window);
            state = StateLevels(signals, window, fullScreen, sound, music, level);
            break;

        case State::LEVEL2:
            state = StateLevels(signals, window, fullScreen, sound, music, level);
            break;

        case State::LEVEL3:
            state = StateLevels(signals, window, fullScreen, sound, music, level);
            break;

        case State::LEVEL4:
            state = StateLevels(signals, window, fullScreen, sound, music, level);
            break;
        case State::WINSCREEN:
            state = StateWinScreen(signals, window, fullScreen, sound, music, level);
            break;
        case State::LOSESCREEN:
            state = StateLoseScreen(signals, window, fullScreen, sound, music, level);
            break;
    }
}

State
StateMachine::StateMenu(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {
    switch (signals) {
        case Signals::menu: {
            //Make a new window
            sf::Texture textureBackground;
            textureBackground.loadFromFile("data/MainBackground.png");
            sf::Sprite background(textureBackground);

            //Make vectors to use as 2 dim sizes for window and the texture
            sf::Vector2u TextureSize;
            sf::Vector2u WindowSize;
            //
            TextureSize = textureBackground.getSize();
            WindowSize = window.getSize();

            float ScaleX = (float) WindowSize.x / TextureSize.x;
            float ScaleY = (float) WindowSize.y / TextureSize.y;

            background.setScale(ScaleX, ScaleY);

            //Make an object of the class GameMenu
            GameMenu GameMenu(WindowSize.x, WindowSize.y);
            while (window.isOpen()) {

                sf::Event event;
                while (window.pollEvent(event)) {
                    switch (event.type) {
                        case sf::Event::KeyPressed:
                            switch (event.key.code) {
                                //Get the function MoveUp from the GameMenu class
                                case sf::Keyboard::Up:
                                    GameMenu.MoveUp();
                                    break;
                                    //Get the function MoveDown from the GameMenu class
                                case sf::Keyboard::Down:
                                    GameMenu.MoveDown();
                                    break;
                                case sf::Keyboard::Escape:
                                    window.close();
                                    break;
                                case sf::Keyboard::Return:
                                    switch (GameMenu.GetItemSelect()) {
                                        case 0:
                                            SendSignal(Signals::levels, window, fullScreen, sound, music, level);
                                            break;
                                        case 1:
                                            SendSignal(Signals::highscore, window, fullScreen, sound, music, level);
                                            break;
                                        case 2:
                                            SendSignal(Signals::upgrades, window, fullScreen, sound, music, level);
                                            break;
                                        case 3:
                                            SendSignal(Signals::settings, window, fullScreen, sound, music, level);
                                            break;
                                        case 4:
                                            window.close();
                                            exit(0);
                                    }
                            }

                            break;
                        case sf::Event::Closed:
                            window.close();

                            break;
                    }

                }

                window.draw(background);
                GameMenu.draw(window);
                window.display();
            }
        }

        case Signals::levels:
            return StateLevels(signals, window, fullScreen, sound, music, level);
        case Signals::highscore:
            return StateHighscore(signals, window, fullScreen, sound, music, level);
        case Signals::settings:
            return StateSetting(signals, window, fullScreen, sound, music, level);
        case Signals::upgrades:
            return StateUpgrades(signals, window, fullScreen, sound, music, level);
        case Signals::pause:
            return StatePause(signals, window, fullScreen, sound, music, level);
        case Signals::level1:
            //return StateLevel1(signals, window);
            return StateLevels(signals, window, fullScreen, sound, music, level);
        case Signals::level2:
            return StateLevels(signals, window, fullScreen, sound, music, level);
        case Signals::level3:
            return StateLevels(signals, window, fullScreen, sound, music, level);
        case Signals::level4:
            return StateLevels(signals, window, fullScreen, sound, music, level);
        case Signals::winscreen:
            return StateWinScreen(signals, window, fullScreen, sound, music, level);
        case Signals::losescreen:
            return StateLoseScreen(signals, window, fullScreen, sound, music, level);
    }
    return State::MENU;
}

State StateMachine::StateLevels(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                int level) {

    switch (signals) {

        case Signals::levels: {
            Levels Levels(width, height);
            window.clear();
            Levels.draw(window, fullScreen, sound, music, level);
            window.display();

            break;
        }
        case Signals::level1:
            window.clear();
            levelBuild.objects.clear();
            levelBuild.map.loadFromFile("Levels/level1.json");
            for (int i = 0; i < levelBuild.CoinX.size(); ++i) {
                levelBuild.CoinX = {655, 1245, 1185, 1920, 2940, 2305, 3570, 1440, 2100, 3070, 3130, 3190, 3250, 4690,
                                    4750, 5220, 5280, 5340, 5720, 5780};
                levelBuild.CoinY = {455, 450, 450, 350, 480, 645, 805, 770, 620, 805, 805, 805, 805, 510, 510, 770, 770,
                                    770, 640, 640};
            }
            for (int i = 0; i < levelBuild.PxPos.size(); ++i) {
                levelBuild.PxPos = {630, 1310, 1465, 2700, 3150};
                levelBuild.PyPos = {667, 604, 762, 704, 794};

                levelBuild.BxPos = {630, 1220, 1850, 4630, 5870};
                levelBuild.ByPos = {442, 442, 442, 512, 682};

            }
            for (int i = 0; i < levelBuild.WyPosL1.size(); ++i) {
                levelBuild.WxPosL1 = {3870, 4450};
                levelBuild.WyPosL1 = {727, 727};
            }
            levelBuild.init(window, fullScreen, sound, music, 1);
            levelBuild.run(window, fullScreen, sound, music, 1);
            window.display();
            break;
        case Signals::level2:
            window.clear();
            levelBuild.objects.clear();
            levelBuild.map.loadFromFile("Levels/level2.json");
            for (int k = 0; k < levelBuild.CoinX.size(); ++k) {
                levelBuild.CoinX = {655, 1245, 1185, 1920, 2940, 2305, 3570, 1440, 2100, 3070, 3130, 3190, 3250, 4690, 4750, 5220, 5280, 5340, 5720, 5780};
                levelBuild.CoinY = {455, 450, 450, 350, 480, 645, 805, 770, 620, 805, 805, 805, 805, 510, 510, 770, 770, 770, 640, 640};
            }
            for (int i = 0; i < levelBuild.PxPos.size(); ++i) {
                levelBuild.PxPos = {1670, 2120, 3040, 4210, 5580};
                levelBuild.PyPos = {668, 538, 608, 508, 698};
            }
            for (int i = 0; i < levelBuild.BrWxPosL2.size(); ++i) {
                levelBuild.BrWxPosL2 = {590, 2530, 4680, 5320};
                levelBuild.BrWyPosL2 = {607, 710, 550, 580};
            }
            levelBuild.init(window, fullScreen, sound, music, 2);
            levelBuild.run(window, fullScreen, sound, music, 2);
            window.display();
            break;
        case Signals::level3:
            window.clear();
            levelBuild.objects.clear();
            levelBuild.map.loadFromFile("Levels/level3.json");
            levelBuild.CoinX = {655, 1185, 1245, 1470, 1830, 2220, 2540, 2900, 3130, 3190, 3250, 3570, 4000, 4060, 4120, 4910, 4970, 5030, 5500, 5560};
            levelBuild.CoinY = {580, 690 , 690 , 770 , 520 , 680 , 625 , 520 , 795 , 795 , 795 , 610 , 710 , 710 , 710 , 865 , 865 , 865 , 830 , 830 };
            levelBuild.init(window, fullScreen, sound, music, 3);
            levelBuild.run(window, fullScreen, sound, music, 3);
            window.display();
            break;
        case Signals::level4:
            window.clear();
            levelBuild.objects.clear();
            levelBuild.map.loadFromFile("Levels/level4.json");
            levelBuild.init(window, fullScreen, sound, music, 4);
            levelBuild.run(window, fullScreen, sound, music, 4);
            window.display();
            break;
    }

    return State::LEVELS;
}

State StateMachine::StateUpgrades(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                  int level) {

    switch (signals) {

        case Signals::upgrades:
            Upgrades upgrades;
            window.clear();
            upgrades.init(window, fullScreen, sound, music, level);
            window.display();
            break;
    }
    return State::UPGRADES;
}

State StateMachine::StateSetting(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                 int level) {

    switch (signals) {

        case Signals::settings:
            Settings settings;
            window.clear();
            settings.init(window, fullScreen, sound, music, level);
            window.display();
            break;
    }
    return State::SETTINGS;
}


State StateMachine::StateHighscore(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                   int level) {

    switch (signals) {

        case Signals::highscore:
            Highscore highscore;
            window.clear();
            highscore.init(window, fullScreen, sound, music, level);
            window.display();
            break;
    }
    return State::HIGHSCORE;
}

//State StateMachine::StateLevel1(Signals signals, sf::RenderWindow &window) {
//
//    switch (signals) {
//
//        case Signals::level1:
//            Level1 Level1(width, height);
//            window.clear();
//            Level1.draw(window);
//            window.display();
//            break;
//    }
//
//    return State::LEVEL1;
//}

State StateMachine::StatePause(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                               int level) {

    switch (signals) {

        case Signals::pause:
            PauseMenu pauseMenu;
            pauseMenu.init(window, fullScreen, sound, music, level);
            window.display();
            break;
    }

    return State::PAUSE;
}

State StateMachine::StateWinScreen(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                   int level) {

    switch (signals) {

        case Signals::winscreen:
            window.clear();
            WinScreen winScreen;
            winScreen.init(window, fullScreen, sound, music, level);
            window.display();
            break;
    }

    return State::WINSCREEN;
}

State StateMachine::StateLoseScreen(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                    int level) {

    switch (signals) {

        case Signals::losescreen:
            window.clear();
            LoseScreen loseScreen;
            loseScreen.init(window, fullScreen, sound, music, level);
            window.display();
            break;
    }

    return State::WINSCREEN;
}
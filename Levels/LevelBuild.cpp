#include "LevelBuild.h"
#include <memory>
#include <iostream>
#include <sstream>
#include <SFML/Window.hpp>
#include <unordered_set>
#include <fstream>

#include "../map/map.h"
#include "../objects/object.h"
#include "../objects/layer.h"
#include "../objects/sprite.h"
#include "../PauseMenu/PauseMenu.h"
#include "../StateMachine/StateMachine.h"
#include "../Collectors/Collectors.h"
#include "../Enemy/EnemyBee.h"
#include "../Enemy/EnemyPerson.h"
#include "../Enemy/EnemyBlackWolf.h"
#include "../EndScreen/WinScreen.h"
#include "../Enemy/Enemy.h"
#include "../Enemy/EnemyBrownWolf.h"

using namespace std;

LevelBuild::LevelBuild() {
    map.loadFromFile("");                                   //Set the levelmap to an empty level so we can change the map from the statemachine
    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");      //The font used for the texts in the levels
    Money.loadFromFile("UpgradeButtons/MoneyBase.png");     //A hud element to view the amount of money on
    ScoreBase.loadFromFile("Highscore/scorebase.png");

    std::ofstream CleanLevelScore;
    CleanLevelScore.open("Highscore/LevelScore.txt", std::ofstream::trunc);
    CleanLevelScore.close();

    MoneyText.setFont(font);                                //Set a font for the Money text
    MoneyText.setPosition(70, 22);                          //Set the location of the Money Text
    MoneyText.setScale(0.7, 0.7);                           //Change the size of the Money Text to make it fit better on the screen

    money.setTexture(Money);                                //Set the money texture into the sprite
    money.setPosition(10, 10);                              //Set the position of the sprite
    money.setScale(0.5, 0.5);                               //Make the sprite smaller

    scorebase.setTexture(ScoreBase);                        //Set texture for the score sprite
    scorebase.setPosition(10, 40);                          //Set the position of the sprite
    scorebase.setScale(0.7, 0.7);                           //Make the sprite smaller

    ScoreText.setFont(font);                                //Set the font for the score
    ScoreText.setPosition(150, 56);

    //Load the textures for the 3 clouds
    textureCloud01.loadFromFile("data/cloud01.png");
    textureCloud02.loadFromFile("data/cloud02.png");
    textureCloud03.loadFromFile("data/cloud03.png");

    //Sett the textures of the clouds into the sprites of the clouds
    spriteCloud[0].setTexture(textureCloud01);
    spriteCloud[1].setTexture(textureCloud02);
    spriteCloud[2].setTexture(textureCloud03);

    //Sett the starting position of the clouds
    spriteCloud[0].setPosition(0, 0);
    spriteCloud[1].setPosition(200, 300);
    spriteCloud[2].setPosition(600, 50);

    std::ofstream LevelScoreWr;
    LevelScoreWr.open("Highscore/LevelScore.txt", std::ofstream::trunc);
    LevelScoreWr.close();


}

bool LevelBuild::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {

    // Copy layer references from map object to Game list
    std::copy(map.getLayers().begin(), map.getLayers().end(), std::back_inserter(objects));

    // Copy sprite references from map object to Game list
    std::copy(map.getSprites().begin(), map.getSprites().end(), std::back_inserter(objects));

    camera = window.getDefaultView();           //Get the screen view and appoint it to the moveable camera view
    UI = window.getDefaultView();               //Get the screen view an appoint it the Hud view where there won't be any movement

    window.setView(camera);                     //Put the camera view into the window
    window.setView(UI);                         //Put the UI view into the window
    window.setVerticalSyncEnabled(true);        //Limit the amount of frames displayed on the screen (depends on each computer)
    window.setFramerateLimit(60);               //Set the maximum screen frame rate displayed

    myPlayer.setScale(0.5, 0.5);                //Change the player size so it fit the screen
    moneyCollect = 0;                           //On start of the level put the amount of collected money to 0 so it can be different for each level


    return true;
}

void LevelBuild::run(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {
    float deltaTime = 0;
    clock.restart();
    // Game loop
    while (gameTick(window, fullScreen, sound, music, level, objects, deltaTime)) {
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

// Process and draws one frame of the game
bool LevelBuild::gameTick(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level,
                          std::list<std::shared_ptr<Object>> &objects, float deltaTime) {
    Enemy enemy = Enemy();                                      //Reference to Enemy header file that contains information on the different enemies
    Collectors collectors(window, CoinX, CoinY);                //Reference to the Collector class and send the positions of the coins so it can be drawn to the screen
    EnemyBee enemyBee(window, BxPos, ByPos);                    //Reference to the EnemyBee class with the positions so it can be drawn at these positions on the screen
    EnemyPerson enemyPerson(window, PxPos, PyPos);              //Reference to the EnemyPerson class with the positions so it can be drawn at these positions on the screen
    EnemyBlackWolf enemyBlackWolf(window, WxPosL1, WyPosL1);    //Reference to the EnemyBlackWolf class with the positions so it can be drawn at these positions on the screen
    EnemyBrownWolf enemyBrownWolf(window, BrWxPosL2, BrWyPosL2);  //Reference to the EnemyBrownWolf class with the positions so it can be drawn at these positions on the screen

    traveler = new MC(map);                                     //Reference to main player and send the current map there

    window.setView(window.getDefaultView());                    //Set the window view to the view shown on the screen


    while (window.isOpen()) {
        sf::Event event;

        traveler->MC_Events(event, window);                         // USING TRAVELER
        traveler->MC_MoveCharacter();
        // Process events from the OS
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    return false;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::W) {
                        StateMachine StateMachine;
                        std::ofstream coin;
                        coin.open("Upgrades/coin.txt");
                        coin << moneyCollect;
                        coin.close();
                        std::ofstream levelscore;
                        levelscore.open("Highscore/LevelScore.txt");
                        levelscore << score;
                        levelscore.close();
                        StateMachine.SendSignal(Signals::winscreen, window, fullScreen, sound, music, level);
                    }
                    if (event.key.code == sf::Keyboard::L) {
                        StateMachine StateMachine;
                        StateMachine.SendSignal(Signals::losescreen, window, fullScreen, sound, music, level);
                    }

                    break;
                case sf::Event::KeyReleased:

                    if (event.key.code == sf::Keyboard::Escape) {
                        StateMachine StateMachine;
                        StateMachine.SendSignal(Signals::pause, window, fullScreen, sound, music, level);
                    }
                    break;

                default:
                    // Ignore the other events
                    break;

            }
        }

        //Managing camera view so it's following the MC
        if (traveler->MC_Sprite.getPosition().x <= camera.getCenter().x + 200) {
            traveler->MC_Sprite.setPosition(traveler->MC_Sprite.getPosition().x, traveler->MC_Sprite.getPosition().y);
        }
        else if (traveler->MC_Sprite.getPosition().x >= window.getPosition().x + 500 && traveler->MC_Sprite.getPosition().x <= window.getPosition().x + 5600) {
            traveler->MC_Sprite.setPosition(traveler->MC_Sprite.getPosition().x, traveler->MC_Sprite.getPosition().y);
            camera.move(3.f, 0.f);
        }


        //When getting to the end on level 1.. You win.
        if (level == 1) {
            if (traveler->MC_Sprite.getPosition().x >= 6301 &&
                (traveler->MC_Sprite.getPosition().y >= 700 &&
                 traveler->MC_Sprite.getPosition().y <= 740)) {
                StateMachine StateMachine;
                std::ofstream coin;
                coin.open("Upgrades/coin.txt");
                coin << moneyCollect;
                coin.close();
                std::ofstream levelscore;
                levelscore.open("Highscore/LevelScore.txt");
                levelscore << score;
                levelscore.close();
                StateMachine.SendSignal(Signals::winscreen, window, fullScreen, sound, music, level);
            }
        }else if (level == 2) {
            if (traveler->MC_Sprite.getPosition().x >= 6280 &&
                (traveler->MC_Sprite.getPosition().y >= 680 &&
                 traveler->MC_Sprite.getPosition().y <= 740)) {
                StateMachine StateMachine;
                std::ofstream coin;
                coin.open("Upgrades/coin.txt");
                coin << moneyCollect;
                coin.close();
                std::ofstream levelscore;
                levelscore.open("Highscore/LevelScore.txt");
                levelscore << score;
                levelscore.close();
                StateMachine.SendSignal(Signals::winscreen, window, fullScreen, sound, music, level);
            }
        }

        //manage the clouds
        //cloud 1
        sf::Time dt = clock.restart();
        if (!cloud1Active) {
            //how fast is the cloud
            srand(static_cast<unsigned int>((int) time(0) * 10));
            cloud1Speed = (rand() % 200);

            //How high is the cloud
            srand(static_cast<unsigned int>((int) time(nullptr) % 10));
            float height = (rand() % 150);
            spriteCloud[0].setPosition(6000, height);
            cloud1Active = true;
        } else {
            spriteCloud[0].setPosition(
                    spriteCloud[0].getPosition().x -
                    (cloud1Speed * dt.asSeconds()),
                    spriteCloud[0].getPosition().y
            );
            //Has the  clould reached the right hand edge of the screen
            if (spriteCloud[0].getPosition().x < -100) {
                //set it up ready to be a whole new cloud next frame
                cloud1Active = false;
            }
        }
        //cloud 2

        if (!cloud2Active) {
            //permanet speed of cloud02
            cloud2Speed = 50;

            //how high is the cloud
            srand(static_cast<unsigned int>((int) time(nullptr) * 20));
            float height = ((rand() % 300) - 150);
            spriteCloud[1].setPosition(6000, height);
            cloud2Active = true;
        } else {
            spriteCloud[1].setPosition(
                    spriteCloud[1].getPosition().x -
                    (cloud2Speed * dt.asSeconds()),
                    spriteCloud[1].getPosition().y
            );
            //Has the  clould reached the right hand edge of the screen
            if (spriteCloud[1].getPosition().x < -100) {
                //set it up ready to be a whole new cloud next frame
                cloud2Active = false;
            }
        }

        //cloud 3
        if (!cloud3Active) {
            //how fast is the cloud
            srand(static_cast<unsigned int>(time(nullptr) * 20));
            cloud3Speed = (rand() % 200);

            //how high is the cloud
            srand(static_cast<unsigned int>((int) time(nullptr) * 30));
            float height = ((rand() % 450) - 150);
            spriteCloud[2].setPosition(6000, height);
            cloud3Active = true;
        } else {
            spriteCloud[2].setPosition(
                    spriteCloud[2].getPosition().x -
                    (cloud3Speed * dt.asSeconds()),
                    spriteCloud[2].getPosition().y
            );
            //Has the  cloud reached the right hand edge of the screen
            if (spriteCloud[2].getPosition().x < -100) {
                //set it up ready to be a whole new cloud next frame
                cloud3Active = false;
            }
        }

        window.clear(sf::Color::Cyan);


        // Process and render each object
        for (auto &object: objects) {
            object->process(deltaTime);
            object->draw(window);
        }

        if (level == 1) {
            for (const auto &i : spriteCloud) {
                window.draw(i);
            }

        }

        if(level == 2){
            traveler->MC_Velocity.y -=100;
            traveler->MC_Velocity.x +=100;
        }

        if(level == 1 || level == 3) {
            traveler->MC_DrawCharacter(window, map);
        }

        for (int i = 0; i <= collectors.CoinsTotal.size(); i++) {
            while (traveler->MC_Sprite.getPosition().x >= collectors.CoinsTotal[i].getPosition().x &&
                   traveler->MC_Sprite.getPosition().x <= collectors.CoinsTotal[i].getPosition().x + 63
                   && traveler->MC_Sprite.getPosition().y >= collectors.CoinsTotal[i].getPosition().y &&
                   traveler->MC_Sprite.getPosition().y <= collectors.CoinsTotal[i].getPosition().y + 63) {
                collectors.CoinsTotal[i].setPosition(-100, -100);
                moneyCollect += 15;
                score += 10;
                i++;
            }
        }
        StateMachine stateMachine;
        for (auto &j : enemyPerson.spritePersonEnemy) {
            if (traveler->MC_Sprite.getPosition().x >= j.getPosition().x &&
                traveler->MC_Sprite.getPosition().x <= j.getPosition().x + 70 &&
                traveler->MC_Sprite.getPosition().y >= j.getPosition().y &&
                traveler->MC_Sprite.getPosition().y <= j.getPosition().y + 70)
                stateMachine.SendSignal(Signals::losescreen, window, fullScreen, sound, music, level);
        }for (auto &e : enemyBlackWolf.spriteBlackWolfEnemy) {
            if (traveler->MC_Sprite.getPosition().x >= e.getPosition().x &&
                traveler->MC_Sprite.getPosition().x <= e.getPosition().x + 70 &&
                traveler->MC_Sprite.getPosition().y >= e.getPosition().y &&
                traveler->MC_Sprite.getPosition().y <= e.getPosition().y + 70)
                stateMachine.SendSignal(Signals::losescreen, window, fullScreen, sound, music, level);
        }for (auto &k : enemyBrownWolf.spriteBrownWolfEnemy) {
            if (traveler->MC_Sprite.getPosition().x >= k.getPosition().x &&
                traveler->MC_Sprite.getPosition().x <= k.getPosition().x + 70 &&
                traveler->MC_Sprite.getPosition().y >= k.getPosition().y &&
                traveler->MC_Sprite.getPosition().y <= k.getPosition().y + 70)
                stateMachine.SendSignal(Signals::losescreen, window, fullScreen, sound, music, level);
        }for (auto &l : enemyBee.spriteBeeEnemy) {
            if (traveler->MC_Sprite.getPosition().x >= l.getPosition().x &&
                traveler->MC_Sprite.getPosition().x <= l.getPosition().x + 60 &&
                traveler->MC_Sprite.getPosition().y >= l.getPosition().y &&
                traveler->MC_Sprite.getPosition().y <= l.getPosition().y + 60)
                stateMachine.SendSignal(Signals::losescreen, window, fullScreen, sound, music, level);
        }


        MoneyText.setString(to_string(moneyCollect));
        ScoreText.setString(to_string(score));
        window.setView(UI);
        window.draw(money);
        window.draw(MoneyText);
        window.draw(scorebase);
        window.draw(ScoreText);
        window.setView(window.getDefaultView());
        window.setView(camera);
        collectors.drawCoins(window);
        //window.draw(myPlayer);

        if (level == 1) {
            enemyPerson.drawEnemyPerson(window, PxPos, PyPos, level);
            enemyBee.drawEnemyBee(window, BxPos, ByPos);
            enemyBlackWolf.drawEnemyBlackWolf(window, WxPosL1, WyPosL1);
        } else if (level == 2) {
            enemyPerson.drawEnemyPerson(window, PxPos, PyPos, level);
            enemyBrownWolf.drawEnemyBrownWolf(window, BrWxPosL2, BrWyPosL2);
        }

        window.display();

    }
    return true;
}




#include "Levels.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../GlobalVars.h"
#include "../StateMachine/StateMachine.h"

StateMachine stateMachine;

Levels::Levels(float width, float height) {
    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    level1.loadFromFile("LevelIcons/level1.png");
    level2.loadFromFile("LevelIcons/level2.png");
    level3.loadFromFile("LevelIcons/level3.png");
    level4.loadFromFile("LevelIcons/level4.png");
    level5.loadFromFile("LevelIcons/level5.png");
    level6.loadFromFile("LevelIcons/level6.png");
    level7.loadFromFile("LevelIcons/level7.png");
    level8.loadFromFile("LevelIcons/level8.png");
    LevelHighlight.loadFromFile("LevelIcons/levelhighlight.png");
    LevelNotHighlight.loadFromFile("LevelIcons/levelnothighlight.png");


    levelChoice[0].setTexture(level1);
    levelChoice[0].setPosition(width / 8 * 2, 250);

    levelHighlight[0].setTexture(LevelHighlight);
    levelHighlight[0].setPosition(width / 8 * 2, 170);

    levelChoice[1].setTexture(level2);
    levelChoice[1].setColor(sf::Color::White);
    levelChoice[1].setPosition(width / 8 * 3, 250);

    levelHighlight[1].setTexture(LevelNotHighlight);
    levelHighlight[1].setPosition(width / 8 * 3, 170);

    levelChoice[2].setTexture(level3);
    levelChoice[2].setPosition(width / 8 * 4, 250);

    levelHighlight[2].setTexture(LevelNotHighlight);
    levelHighlight[2].setPosition(width / 8 * 4, 170);

    levelChoice[3].setTexture(level4);
    levelChoice[3].setPosition(width / 8 * 5, 250);

    levelHighlight[3].setTexture(LevelNotHighlight);
    levelHighlight[3].setPosition(width / 8 * 5, 170);

    levelChoice[4].setTexture(level5);
    levelChoice[4].setPosition(width / 8 * 2, 550);

    levelHighlight[4].setTexture(LevelNotHighlight);
    levelHighlight[4].setPosition(width / 8 * 2, 470);

    levelChoice[5].setTexture(level6);
    levelChoice[5].setPosition(width / 8 * 3, 550);

    levelHighlight[5].setTexture(LevelNotHighlight);
    levelHighlight[5].setPosition(width / 8 * 3, 470);

    levelChoice[6].setTexture(level7);
    levelChoice[6].setPosition(width / 8 * 4, 550);

    levelHighlight[6].setTexture(LevelNotHighlight);
    levelHighlight[6].setPosition(width / 8 * 4, 470);

    levelChoice[7].setTexture(level8);
    levelChoice[7].setPosition(width / 8 * 5, 550);

    levelHighlight[7].setTexture(LevelNotHighlight);
    levelHighlight[7].setPosition(width / 8 * 5, 470);

    LevelSelect = 0;
}

Levels::~Levels() {

}

void Levels::draw(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {
    window.setFramerateLimit(300);
    sf::Texture texture;
    texture.loadFromFile("data/MainBackground.png");

    sf::Sprite background(texture);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        //Get the function MoveUp from the GameMenu class
                        case sf::Keyboard::Left:
                            MoveUp();
                            break;
                            //Get the function MoveDown from the GameMenu class
                        case sf::Keyboard::Right:
                            MoveDown();
                            break;
                        case sf::Keyboard::Escape:
                            stateMachine.SendSignal(Signals::menu, window, fullScreen, sound, music, level);
                            break;
                        case sf::Keyboard::Return: {
                            switch (GetLevelSelect()) {
                                case 0:
                                    stateMachine.SendSignal(Signals::level1, window, fullScreen, sound, music, level);
                                    break;
                                case 1:
                                    stateMachine.SendSignal(Signals::level2, window, fullScreen, sound, music, level);
                                    break;
                                case 2:
                                    stateMachine.SendSignal(Signals::level3, window, fullScreen, sound, music, level);
                                    break;
                                case 3:
                                    stateMachine.SendSignal(Signals::level4, window, fullScreen, sound, music, level);
                                    break;
                            }
                        }

                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.setView(window.getDefaultView());
        window.draw(background);
        LevelsPanel.loadFromFile("LevelIcons/LevelsPanel.png");
        sf::Sprite levelsPanel;
        levelsPanel.setPosition(width / 5, height / 14);
        levelsPanel.setTexture(LevelsPanel);
        window.draw(levelsPanel);

        if(LevelSelect == 0){
            texture.loadFromFile("LevelIcons/Level1BackGround.png");
        }else if(LevelSelect == 1){
            texture.loadFromFile("LevelIcons/Level2BackGround.png");
        }else if(LevelSelect == 2){
            texture.loadFromFile("LevelIcons/Level3BackGround.png");
        }

        for (int i = 0; i < 8; ++i) {
            window.draw(levelChoice[i]);
            window.draw(levelHighlight[i]);

        }
        window.display();
    }

}

void Levels::MoveUp() {
    if (LevelSelect - 1 >= 0) {
        levelHighlight[LevelSelect].setTexture(LevelNotHighlight);
        LevelSelect--;
        levelHighlight[LevelSelect].setTexture(LevelHighlight);
    }
}

void Levels::MoveDown() {
    if (LevelSelect + 1 < 8) {
        levelHighlight[LevelSelect].setTexture(LevelNotHighlight);
        LevelSelect++;
        levelHighlight[LevelSelect].setTexture(LevelHighlight);
    }
}


#include <iostream>
#include "EnemyBee.h"
#include "../GlobalVars.h"

//Vector for bee sprite sheet
sf::Vector2i Bsource(1, 0);

EnemyBee::EnemyBee(sf::RenderWindow &window, std::array<int, 5> BxPos, std::array<int, 5> ByPos) {

    window.setView(window.getDefaultView());

    textureBeeEnemy.loadFromFile("data/transpWasp.png");

    for (int i = 0; i < spriteBeeEnemy.size(); ++i) {       //draw BeeEnemy
        spriteBeeEnemy[i].setTexture(textureBeeEnemy);
        spriteBeeEnemy[i].setTextureRect(sf::IntRect(67, 75, 67, 75));
        spriteBeeEnemy[i].setPosition(BxPos[i], ByPos[i]);
    }

}

EnemyBee::~EnemyBee() = default;

/**
 * they move in the x axis in both left and right
 * draw them in the window
 *
 * @param window :take window which is sent and draw the enemy in it
 * @param BxPos : position of Bee in window in x axis
 * @param ByPos : position of Bee in window in the window in y axis
 */
void EnemyBee::drawEnemyBee(sf::RenderWindow &window, std::array<int, 5> BxPos, std::array<int, 5> ByPos) {

    for (int i = 0; i < spriteBeeEnemy.size(); ++i) {
        switch (i) {
            case 0: {
                switch (direction_B0) {
                    case LEFT_B0: {
                        spriteBeeEnemy[0].move(-1, 0);

                        if (spriteBeeEnemy[0].getPosition().x <= (BxPos[0] - 100)) {
                            velDirection *= -1;
                            direction_B0 = DirectionBee::RIGHT_B0;
                        }
                        break;
                    }
                    case RIGHT_B0: {
                        spriteBeeEnemy[0].move(1, 0);

                        if (spriteBeeEnemy[0].getPosition().x >= (BxPos[0] + 200)) {
                            velDirection *= -1;
                            direction_B0 = DirectionBee::LEFT_B0;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 1: {
                switch (direction_B1) {
                    case LEFT_B1: {
                        spriteBeeEnemy[1].move(-1, 0);

                        if (spriteBeeEnemy[1].getPosition().x <= (BxPos[1] - 50)) {
                            velDirection *= -1;
                            direction_B1 = DirectionBee::RIGHT_B1;
                        }
                        break;
                    }
                    case RIGHT_B1: {
                        spriteBeeEnemy[1].move(1, 0);

                        if (spriteBeeEnemy[1].getPosition().x >= (BxPos[1] + 50)) {
                            velDirection *= -1;
                            direction_B1 = DirectionBee::LEFT_B1;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {
                switch (direction_B2) {
                    case LEFT_B2: {
                        spriteBeeEnemy[2].move(-1, 0);

                        if (spriteBeeEnemy[2].getPosition().x <= (BxPos[2])) {
                            velDirection *= -1;
                            direction_B2 = DirectionBee::RIGHT_B2;
                        }
                        break;
                    }
                    case RIGHT_B2: {
                        spriteBeeEnemy[2].move(1, 0);

                        if (spriteBeeEnemy[2].getPosition().x >= (BxPos[2] + 180)) {
                            velDirection *= -1;
                            direction_B2 = DirectionBee::LEFT_B2;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 3: {
                switch (direction_B3) {
                    case LEFT_B3: {
                        spriteBeeEnemy[3].move(-1, 0);

                        if (spriteBeeEnemy[3].getPosition().x <= (BxPos[3])) {
                            velDirection *= -1;
                            direction_B3 = DirectionBee::RIGHT_B3;
                        }
                        break;
                    }
                    case RIGHT_B3: {
                        spriteBeeEnemy[3].move(1, 0);

                        if (spriteBeeEnemy[3].getPosition().x >= (BxPos[3] + 210)) {
                            velDirection *= -1;
                            direction_B3 = DirectionBee::LEFT_B3;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 4: {
                switch (direction_B4) {
                    case LEFT_B4: {
                        spriteBeeEnemy[4].move(-1, 0);

                        if (spriteBeeEnemy[4].getPosition().x <= (BxPos[4] - 180)) {
                            velDirection *= -1;
                            direction_B4 = DirectionBee::RIGHT_B4;
                        }
                        break;
                    }
                    case RIGHT_B4: {
                        spriteBeeEnemy[4].move(1, 0);

                        if (spriteBeeEnemy[4].getPosition().x >= BxPos[4]) {
                            velDirection *= -1;
                            direction_B4 = DirectionBee::LEFT_B4;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            default:
                break;
        }

        if (speedOfBeeEnemy % 10 == 0) {
            switch (i) {
                case 0: {
                    switch (direction_B0) {
                        case LEFT_B0: {
                            spriteBeeEnemy[0].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75 + 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[0].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        case RIGHT_B0: {
                            spriteBeeEnemy[0].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[0].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 1: {
                    switch (direction_B1) {
                        case LEFT_B1: {
                            spriteBeeEnemy[1].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75 + 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[1].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        case RIGHT_B1: {
                            spriteBeeEnemy[1].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[1].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 2: {
                    switch (direction_B2) {
                        case LEFT_B2: {
                            spriteBeeEnemy[2].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75 + 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[2].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        case RIGHT_B2: {
                            spriteBeeEnemy[2].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[2].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 3: {
                    switch (direction_B3) {
                        case LEFT_B3: {
                            spriteBeeEnemy[3].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75 + 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[3].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        case RIGHT_B3: {
                            spriteBeeEnemy[3].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[3].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 4: {
                    switch (direction_B4) {
                        case LEFT_B4: {
                            spriteBeeEnemy[4].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75 + 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[4].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        case RIGHT_B4: {
                            spriteBeeEnemy[4].setTextureRect(sf::IntRect(Bsource.x * 67,
                                                                         Bsource.y * 75,
                                                                         67, 75));
                            Bsource.x++;
                            if ((Bsource.x) * 67 >= spriteBeeEnemy[4].getTexture()->getSize().x)
                                Bsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }

    }

    for (const auto &i : spriteBeeEnemy) {
        window.draw(i);
    }
    speedOfBeeEnemy++;

}
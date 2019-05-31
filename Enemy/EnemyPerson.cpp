
#include "EnemyPerson.h"

//Vector for personEnemy sprite sheet
sf::Vector2i Psource(1, 0);

EnemyPerson::EnemyPerson(sf::RenderWindow &window, std::array<int, 5> PxPos,
                         std::array<int, 5> PyPos) {

    texturePersonEnemy.loadFromFile("data/personEnemy.png");

    for (int i = 0; i < spritePersonEnemy.size(); ++i) {   //draw the person for the first time to the screen
        spritePersonEnemy[i].setTexture(texturePersonEnemy);
        spritePersonEnemy[i].setTextureRect(sf::IntRect(60, 73, 60, 73));
        spritePersonEnemy[i].setPosition(PxPos[i], PyPos[i]);
    }

}

EnemyPerson::~EnemyPerson() = default;

/**
 * they move in the x axis in both left and right
 * draw them in the window
 *
 * @param window
 * @param PxPos : the window for which the person enemy should draw
 * @param PyPos : position of person in window in x axis
 * @param level : position of person wolf in window in y axis
 */

void EnemyPerson::drawEnemyPerson(sf::RenderWindow &window, std::array<int,
        5> PxPos, std::array<int, 5> PyPos, int level) {


    /**
     * for loop for the for enemies in different positions
     * switch case for enemy directions
     */
    if (level == 1) {
        subtInXPersonL = {100, 50, 80, 50, 100};
        addInXPersonL = {100, 50, 0, 50, 100};
    } else if (level == 2) {
        subtInXPersonL = {0, 0, 0, 0, 0};
        addInXPersonL = {220, 210, 540, 470, 300};
    }

    for (int i = 0; i < spritePersonEnemy.size(); ++i) {
        switch (i) {
            case 0: {
                switch (direction_P0) {
                    case LEFT_P0: {

                        spritePersonEnemy[0].move(-1, 0);

                        if (spritePersonEnemy[0].getPosition().x <= (PxPos[0] - subtInXPersonL[0])) {
                            velDirection *= -1;
                            direction_P0 = DirectionPerson::RIGHT_P0;
                        }
                        break;
                    }
                    case RIGHT_P0: {
                        spritePersonEnemy[0].move(1, 0);
                        if (spritePersonEnemy[0].getPosition().x >= (PxPos[0] + addInXPersonL[0])) {
                            velDirection *= -1;
                            direction_P0 = DirectionPerson::LEFT_P0;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 1: {
                switch (direction_P1) {
                    case LEFT_P1: {
                        spritePersonEnemy[1].move(-1, 0);

                        if (spritePersonEnemy[1].getPosition().x <= (PxPos[1] - subtInXPersonL[1])) {
                            velDirection *= -1;
                            direction_P1 = DirectionPerson::RIGHT_P1;
                        }
                        break;
                    }
                    case RIGHT_P1: {
                        spritePersonEnemy[1].move(1, 0);
                        if (spritePersonEnemy[1].getPosition().x >= (PxPos[1] + addInXPersonL[1])) {
                            velDirection *= -1;
                            direction_P1 = DirectionPerson::LEFT_P1;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {

                switch (direction_P2) {
                    case LEFT_P2: {

                        if (level == 1) {
                            spritePersonEnemy[2].move(0, -1);
                            if (spritePersonEnemy[2].getPosition().y <= (PyPos[2] - subtInXPersonL[2])) {
                                velDirection *= -1;
                                direction_P2 = DirectionPerson::RIGHT_P2;
                            }
                        } else if (level == 2) {
                            spritePersonEnemy[2].move(-1, 0);
                            if (spritePersonEnemy[2].getPosition().x <= (PxPos[2] - subtInXPersonL[2])) {
                                velDirection *= -1;
                                direction_P2 = DirectionPerson::RIGHT_P2;
                            }
                        }
                        break;
                    }
                    case RIGHT_P2: {

                        if (level == 1) {
                            spritePersonEnemy[2].move(0, 1);
                            if (spritePersonEnemy[2].getPosition().y >= (PyPos[2] + addInXPersonL[2])) {
                                velDirection *= -1;
                                direction_P2 = DirectionPerson::LEFT_P2;
                            }
                        } else if (level == 2) {
                            spritePersonEnemy[2].move(1, 0);
                            if (spritePersonEnemy[2].getPosition().x >= (PxPos[2] + addInXPersonL[2])) {
                                velDirection *= -1;
                                direction_P2 = DirectionPerson::LEFT_P2;
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 3: {

                switch (direction_P3) {
                    case LEFT_P3: {
                        spritePersonEnemy[3].move(-1, 0);

                        if (spritePersonEnemy[3].getPosition().x <= (PxPos[3] - subtInXPersonL[3])) {
                            velDirection *= -1;
                            direction_P3 = DirectionPerson::RIGHT_P3;
                        }
                        break;
                    }
                    case RIGHT_P3: {
                        spritePersonEnemy[3].move(1, 0);
                        if (spritePersonEnemy[3].getPosition().x >= (PxPos[3] + addInXPersonL[3])) {
                            velDirection *= -1;
                            direction_P3 = DirectionPerson::LEFT_P3;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 4: {

                switch (direction_P4) {
                    case LEFT_P4: {
                        spritePersonEnemy[4].move(-1, 0);

                        if (spritePersonEnemy[4].getPosition().x <= (PxPos[4] - subtInXPersonL[4])) {
                            velDirection *= -1;
                            direction_P4 = DirectionPerson::RIGHT_P4;
                        }
                        break;
                    }
                    case RIGHT_P4: {
                        spritePersonEnemy[4].move(1, 0);
                        if (spritePersonEnemy[4].getPosition().x >= (PxPos[4] + addInXPersonL[4])) {
                            velDirection *= -1;
                            direction_P4 = DirectionPerson::LEFT_P4;
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
/**
 * here is the switch for graphical movement
 */
        if (speedOfPerEnemy % 10 == 0) {

            switch (i) {
                case 0: {
                    switch (direction_P0) {
                        case LEFT_P0: {
                            spritePersonEnemy[0].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[0].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        case RIGHT_P0: {
                            spritePersonEnemy[0].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73 + 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[0].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 1: {


                    switch (direction_P1) {
                        case LEFT_P1: {
                            spritePersonEnemy[1].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[1].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        case RIGHT_P1: {
                            spritePersonEnemy[1].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73 + 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[1].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 2: {


                    switch (direction_P2) {
                        case LEFT_P2: {
                            spritePersonEnemy[2].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[2].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        case RIGHT_P2: {
                            spritePersonEnemy[2].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73 + 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[2].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 3: {

                    switch (direction_P3) {
                        case LEFT_P3: {
                            spritePersonEnemy[3].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[3].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        case RIGHT_P3: {
                            spritePersonEnemy[3].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73 + 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[3].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 4: {


                    switch (direction_P4) {
                        case LEFT_P4: {
                            spritePersonEnemy[4].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[4].getTexture()->getSize().x)
                                Psource.x = 0;
                            break;
                        }
                        case RIGHT_P4: {
                            spritePersonEnemy[4].setTextureRect(sf::IntRect(Psource.x * 60,
                                                                            Psource.y * 73 + 73,
                                                                            60, 73));
                            Psource.x++;
                            if ((Psource.x) * 60 >= spritePersonEnemy[4].getTexture()->getSize().x)
                                Psource.x = 0;
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

    for (const auto &i : spritePersonEnemy) {
        window.draw(i);
    }
    speedOfPerEnemy++;
}
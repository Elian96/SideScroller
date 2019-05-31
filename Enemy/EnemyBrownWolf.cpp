

#include "EnemyBrownWolf.h"

//Vector for brownWolfEnemy sprite sheet
sf::Vector2i BrWsource(1, 0);

EnemyBrownWolf::EnemyBrownWolf(sf::RenderWindow &window, std::array<int,
        4> BrWxPos, std::array<int, 4> BrWyPos) {

    textureBrownWolfEnemy.loadFromFile("data/BrownWolf.png");

    for (int i = 0; i < spriteBrownWolfEnemy.size(); ++i) {       //draw the brownEnemy for first time
        spriteBrownWolfEnemy[i].setTexture(textureBrownWolfEnemy);
        spriteBrownWolfEnemy[i].setTextureRect(sf::IntRect(80, 47, 80, 47));
        spriteBrownWolfEnemy[i].setPosition(BrWxPos[i], BrWyPos[i]);
    }
}

/**
 * they move in the x axis in both left and right
 * draw them in the window
 *
 * @param window : the window for which the Black wolf enemy should draw
 * @param BrWxPos : position of BrownWolf in window in x axis
 * @param BrWyPos : position of Brown wolf in window in y axis
 */

void EnemyBrownWolf::drawEnemyBrownWolf(sf::RenderWindow &window, std::array<int,
        4> BrWxPos, std::array<int, 4> BrWyPos) {
    subtInXPersonL2 = {0, 0, 0, 0};
    addInXPersonL2 = {290, 300, 560, 190};

    for (int i = 0; i < spriteBrownWolfEnemy.size(); ++i) {
        switch (i) {
            case 0: {
                switch (direction_BrW0) {
                    case LEFT_BrW0: {
                        spriteBrownWolfEnemy[0].move(-1, 0);

                        if (spriteBrownWolfEnemy[0].getPosition().x <= (BrWxPos[0] - subtInXPersonL2[0])) {
                            velDirection *= -1;
                            direction_BrW0 = DirectionBrownWolf::RIGHT_BrWO;
                        }
                        break;
                    }
                    case RIGHT_BrWO: {
                        spriteBrownWolfEnemy[0].move(1, 0);
                        if (spriteBrownWolfEnemy[0].getPosition().x >= (BrWxPos[0] + addInXPersonL2[0])) {
                            velDirection *= -1;
                            direction_BrW0 = DirectionBrownWolf::LEFT_BrW0;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }

            case 2: {
                switch (direction_BrW2) {
                    case LEFT_BrW2: {
                        spriteBrownWolfEnemy[2].move(-1, 0);

                        if (spriteBrownWolfEnemy[2].getPosition().x <= (BrWxPos[2] - subtInXPersonL2[2])) {
                            velDirection *= -1;
                            direction_BrW2 = DirectionBrownWolf::RIGHT_BrW2;
                        }
                        break;
                    }
                    case RIGHT_BrW2: {
                        spriteBrownWolfEnemy[2].move(1, 0);
                        if (spriteBrownWolfEnemy[2].getPosition().x >= (BrWxPos[2] + addInXPersonL2[2])) {
                            velDirection *= -1;
                            direction_BrW2 = DirectionBrownWolf::LEFT_BrW2;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }

        }

        if (speedOfBrWolfEnemy % 5 == 0) {
            switch (i) {
                case 0: {
                    switch (direction_BrW0) {
                        case LEFT_BrW0: {
                            spriteBrownWolfEnemy[0].setTextureRect(sf::IntRect(BrWsource.x * 83,
                                                                               BrWsource.y * 48,
                                                                               83, 48));
                            BrWsource.x++;
                            if ((BrWsource.x) * 83 >= spriteBrownWolfEnemy[0].getTexture()->getSize().x)
                                BrWsource.x = 0;
                            break;
                        }
                        case RIGHT_BrWO: {
                            spriteBrownWolfEnemy[0].setTextureRect(sf::IntRect(BrWsource.x * 83,
                                                                               BrWsource.y * 48 + 48,
                                                                               83, 48));
                            BrWsource.x++;
                            if ((BrWsource.x) * 83 >= spriteBrownWolfEnemy[0].getTexture()->getSize().x)
                                BrWsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 2: {
                    switch (direction_BrW2) {
                        case LEFT_BrW2: {
                            spriteBrownWolfEnemy[2].setTextureRect(sf::IntRect(BrWsource.x * 83,
                                                                               BrWsource.y * 48,
                                                                               83, 48));
                            BrWsource.x++;
                            if ((BrWsource.x) * 83 >= spriteBrownWolfEnemy[2].getTexture()->getSize().x)
                                BrWsource.x = 0;
                            break;
                        }
                        case RIGHT_BrW2: {
                            spriteBrownWolfEnemy[2].setTextureRect(sf::IntRect(BrWsource.x * 83,
                                                                               BrWsource.y * 48 + 48,
                                                                               83, 48));
                            BrWsource.x++;
                            if ((BrWsource.x) * 83 >= spriteBrownWolfEnemy[2].getTexture()->getSize().x)
                                BrWsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }

            }
        }
        window.draw(spriteBrownWolfEnemy[i]);
    }
    speedOfBrWolfEnemy++;
}

EnemyBrownWolf::~EnemyBrownWolf() = default;
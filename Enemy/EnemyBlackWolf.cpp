#include "EnemyBlackWolf.h"

//Vector for blackWolfEnemy sprite sheet
sf::Vector2i Wsource(1, 0);

EnemyBlackWolf::EnemyBlackWolf(sf::RenderWindow &window,
                               std::array<int, 2> WxPos, std::array<int, 2> WyPos) {

    textureBlackWolfEnemy.loadFromFile("data/blackWolf.png");

    for (int i = 0; i < spriteBlackWolfEnemy.size(); ++i) {    // draw the blackEnemy for the first time
        spriteBlackWolfEnemy[i].setTexture(textureBlackWolfEnemy);
        spriteBlackWolfEnemy[i].setTextureRect(sf::IntRect(64, 47, 64, 47));
        spriteBlackWolfEnemy[i].setPosition(WxPos[i], WyPos[i]);
    }
}

/**
 * they move in the x axis in both left and right
 * draw them in the window
 *
 * @param window : the window for which the Black wolf enemy should draw
 * @param WxPos : position of BlackWolf in window in x axis
 * @param WyPos : position of Black wolf in window in y axis
 */

void EnemyBlackWolf::drawEnemyBlackWolf(sf::RenderWindow &window,
                                        std::array<int, 2> WxPos, std::array<int, 2> WyPos) {

    for (int i = 0; i < spriteBlackWolfEnemy.size(); ++i) {
        switch (i) {
            case 0: {
                switch (direction_W0) {
                    case LEFT_BlW0: {

                        spriteBlackWolfEnemy[0].move(-1, 0);

                        if (spriteBlackWolfEnemy[0].getPosition().x <= (WxPos[0] - 50)) {
                            velDirection *= -1;
                            direction_W0 = DirectionBlackWolf::RIGHT_BlW0;
                        }
                        break;
                    }
                    case RIGHT_BlW0: {
                        spriteBlackWolfEnemy[0].move(1, 0);
                        if (spriteBlackWolfEnemy[0].getPosition().x >= (WxPos[0] + 300)) {
                            velDirection *= -1;
                            direction_W0 = DirectionBlackWolf::LEFT_BlW0;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 1: {

                switch (direction_W1) {
                    case LEFT_W1:
                        break;

                    default:
                        break;
                }

                break;
            }
            default:
                break;
        }

        if (speedOfWolfEnemy % 5 == 0) {

            switch (i) {
                case 0: {
                    switch (direction_W0) {
                        case LEFT_BlW0: {
                            spriteBlackWolfEnemy[0].setTextureRect(sf::IntRect(Wsource.x * 64,
                                                                               Wsource.y * 47,
                                                                               64, 47));
                            Wsource.x++;
                            if ((Wsource.x) * 66 >= spriteBlackWolfEnemy[0].getTexture()->getSize().x)
                                Wsource.x = 0;
                            break;
                        }
                        case RIGHT_BlW0: {
                            spriteBlackWolfEnemy[0].setTextureRect(sf::IntRect(Wsource.x * 64,
                                                                               Wsource.y * 47 + 47,
                                                                               64, 47));
                            Wsource.x++;
                            if ((Wsource.x) * 66 >= spriteBlackWolfEnemy[0].getTexture()->getSize().x)
                                Wsource.x = 0;
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 1: {

                    switch (direction_W1) {

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
    for (const auto &i : spriteBlackWolfEnemy) {
        window.draw(i);
    }
    speedOfWolfEnemy++;
}

EnemyBlackWolf::~EnemyBlackWolf() = default;
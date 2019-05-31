#ifndef ASSIGNMENT_6_COLLECTORS_H
#define ASSIGNMENT_6_COLLECTORS_H

#include <SFML/Graphics.hpp>
#include <sstream>

class Collectors {

public:
    //bool DPressedf = false;
    int visible = 0;
    int score = 0 ;

    Collectors(sf::RenderWindow &window, std::array <int , 20> CoinX, std::array <int , 20> CoinY);//add a paramater visible that is int

    ~Collectors();

    void drawCoins(sf::RenderWindow &window);

    int speedOfCoins = 40;
    sf::Font font;
    sf::Texture CoinsTexture;
    sf::String StringScore = std::to_string(score);
    std::array <sf::Sprite, 20> CoinsTotal;

private:


};

#endif
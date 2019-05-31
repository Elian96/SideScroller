#include <iostream>
#include <fstream>
#include "Collectors.h"
#include "../Levels/LevelBuild.h"

sf::Vector2i vsource(1, 0);
//LevelBuild levelBuild;
Collectors::Collectors(sf::RenderWindow &window, std::array<int , 20> CoinX, std::array<int , 20> CoinY) {

    LevelBuild levelBuild;

    //load  new textures to Collectors
    window.setView(window.getDefaultView());
    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    CoinsTexture.loadFromFile("data/coin2.png");


    for (int i = 0; i < CoinsTotal.size(); i++) {
        CoinsTotal[i].setTexture(CoinsTexture);
        CoinsTotal[i].setPosition(CoinX[i], CoinY[i]);

    }

}

Collectors::~Collectors() {

}

//moving the coins
void Collectors::drawCoins(sf::RenderWindow &window) { // send en ekstra paramter som heter visible

    if ((speedOfCoins % 5) == 0) {
        if ((vsource.y + 1) * 64 >= CoinsTexture.getSize().y)
            vsource.y = 0;
        else {
            vsource.x++;
            if ((vsource.x + 1) * 64 >= CoinsTexture.getSize().x) {
                vsource.x = 0;
                vsource.y++;
            }
        }
        for (int i = 0; i < CoinsTotal.size(); ++i) {
            CoinsTotal[i].setTextureRect(sf::IntRect(vsource.x * 64, vsource.y * 64, 64, 64));
        }

    }


    //if (!DPressedf ) {
    for (int i = visible; i < CoinsTotal.size(); ++i) {
        window.draw(CoinsTotal[i]);
    }
    speedOfCoins++;

}
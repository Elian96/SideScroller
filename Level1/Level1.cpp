#include "Level1.h"
#include "../Collectors/Collectors.h"
#include "../Enemy/EnemyBee.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;

Level1::Level1(float width, float height) {
}

Level1::~Level1() {

}


void Level1::draw(sf::RenderWindow &window) {
    sf::Vector2u WindowSize;

    //EnemyBee enemyBee(window);
//    Collectors collectors(window);
    bool paused = true;
    sf::Texture textureBackground;
    textureBackground.loadFromFile("data/image.png");
    sf::Sprite background(textureBackground);

    //make 3 cloud sprite from CoinsTexture
    sf::Texture textureCloud01;
    sf::Texture textureCloud02;
    sf::Texture textureCloud03;

    //load  new textures
    textureCloud01.loadFromFile("data/cloud01.png");
    textureCloud02.loadFromFile("data/cloud02.png");
    textureCloud03.loadFromFile("data/cloud03.png");

    //3 new sprites with 3 CoinsTexture
    sf::Sprite spriteCloud01;
    sf::Sprite spriteCloud02;
    sf::Sprite spriteCloud03;
    spriteCloud01.setTexture(textureCloud01);
    spriteCloud02.setTexture(textureCloud02);
    spriteCloud03.setTexture(textureCloud03);

    //are the clouds currently in screen
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    //how fast is each cloud
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    //position the clouds off the screen
    spriteCloud01.setPosition(0, 0);
    spriteCloud02.setPosition(200, 300);
    spriteCloud03.setPosition(600, 50);


    ifstream openfile("Map.txt");
    sf::Texture tileTexture;
    sf::Sprite tiles;
    sf::Vector2i map[100][100];
    sf::Vector2i loadCounter = sf::Vector2i(0, 0);


    if (openfile.is_open()) {
        string tileLocation;
        openfile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);
        while (!openfile.eof()) {
            string str;
            openfile >> str;
            char x = str[0], y = str[2];
            if (!isdigit(x) || !isdigit(y)) {//sjekker om de 2 er bokstaver, også ikke tall
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
            } else {
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
            }
            if (openfile.peek() == '\n') {
                loadCounter.x = 0;
                loadCounter.y++;
            } else {
                loadCounter.x++;
            }
        }
    }
    //Make vectors to use as 2 dim sizes for window and the CoinsTexture
    sf::Vector2u TileSize;
    //
    TileSize = tileTexture.getSize();
    WindowSize = window.getSize();

    float ScaleX = (float) WindowSize.x / (TileSize.x);
    float ScaleY = (float) WindowSize.y / (TileSize.y);

    tiles.setScale(ScaleX, ScaleY);

    //variables to control time itself
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event Event;
        while (window.pollEvent(Event)) {
            switch (Event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
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
            srand(static_cast<unsigned int>((int) time(0) % 10));
            float height = (rand() % 150);
            spriteCloud01.setPosition(1920, height);
            cloud1Active = true;
        } else {
            spriteCloud01.setPosition(
                    spriteCloud01.getPosition().x -
                    (cloud1Speed * dt.asSeconds()),
                    spriteCloud01.getPosition().y
            );
            //Has the  clould reached the right hand edge of the screen
            if (spriteCloud01.getPosition().x < -400) {
                //set it up ready to be a whole new cloud next frame
                cloud1Active = false;
            }
        }
        //cloud 2

        if (!cloud2Active) {
            //permanet speed of cloud02
            cloud2Speed = 50;

            //how high is the cloud
            srand(static_cast<unsigned int>((int) time(0) * 20));
            float height = ((rand() % 300) - 150);
            spriteCloud02.setPosition(1930, height);
            cloud2Active = true;
        } else {
            spriteCloud02.setPosition(
                    spriteCloud02.getPosition().x -
                    (cloud2Speed * dt.asSeconds()),
                    spriteCloud02.getPosition().y
            );
            //Has the  clould reached the right hand edge of the screen
            if (spriteCloud02.getPosition().x < -400) {
                //set it up ready to be a whole new cloud next frame
                cloud2Active = false;
            }
        }

        //cloud 3
        if (!cloud3Active) {
            //how fast is the cloud
            srand(static_cast<unsigned int>(time(0) * 20));
            cloud3Speed = (rand() % 200);

            //how high is the cloud
            srand(static_cast<unsigned int>((int) time(0) * 30));
            float height = ((rand() % 450) - 150);
            spriteCloud03.setPosition(1940, height);
            cloud3Active = true;
        } else {
            spriteCloud03.setPosition(
                    spriteCloud03.getPosition().x -
                    (cloud3Speed * dt.asSeconds()),
                    spriteCloud03.getPosition().y
            );
            //Has the  clould reached the right hand edge of the screen
            if (spriteCloud03.getPosition().x < -400) {
                //set it up ready to be a whole new cloud next frame
                cloud3Active = false;
            }
        }

        //draw the background
        window.clear(sf::Color::Cyan);
        //window.draw(background);

        //draw the clouds
        window.draw(spriteCloud01);
        window.draw(spriteCloud02);
        window.draw(spriteCloud03);


        for (int i = 0; i < loadCounter.x; ++i) {
            for (int j = 0; j < loadCounter.y; ++j) {
                if (map[i][j].x != -1 && map[i][j].y != -1) {
                    tiles.setPosition(i * ((float) WindowSize.x / 34.0f), j * ((float) WindowSize.y / 22.0f));
                    tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
                    window.draw(tiles);
                }
            }
        }

        //collectors.drawCoins(window);
        //enemyBee.drawEnemyBee(window);
        window.display();
    }

}
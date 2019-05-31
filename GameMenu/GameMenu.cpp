#include "GameMenu.h"
#include "../GlobalVars.h"
#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>

GameMenu::GameMenu(float width, float height) {

    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    PlayButton.loadFromFile("Buttons/PlayBtn.png");
    ScoreButton.loadFromFile("Buttons/HighscoreBtn.png");
    UpgradesButton.loadFromFile("Buttons/UpgradesBtn.png");
    SettingButton.loadFromFile("Buttons/SettingsBtn.png");
    ExitButton.loadFromFile("Buttons/ExitBtn.png");
    BtnHighlight.loadFromFile("Buttons/BtnHighlight.png");
    BtnNotHighlight.loadFromFile("Buttons/BtnNotHighlight.png");

    buttons[0].setTexture(PlayButton);
    buttons[0].setPosition(width / 2 - 180, height / 8 * 2);

    btnHighligh[0].setTexture(BtnHighlight);
    btnHighligh[0].setPosition(width / 2 - 220, height / 8 * 2);

    buttons[1].setTexture(ScoreButton);
    buttons[1].setPosition(width / 2 - 180, height / 8 * 3);

    btnHighligh[1].setTexture(BtnNotHighlight);
    btnHighligh[1].setPosition(width / 2 - 220, height / 8 * 3);

    buttons[2].setTexture(UpgradesButton);
    buttons[2].setPosition(width / 2 - 180, height / 8 * 4);

    btnHighligh[2].setTexture(BtnNotHighlight);
    btnHighligh[2].setPosition(width / 2 - 220, height / 8 * 4);

    buttons[3].setTexture(SettingButton);
    buttons[3].setPosition(width / 2 - 180, height / 8 * 5);

    btnHighligh[3].setTexture(BtnNotHighlight);
    btnHighligh[3].setPosition(width / 2 - 220, height / 8 * 5);

    buttons[4].setTexture(ExitButton);
    buttons[4].setPosition(width / 2 - 180, height / 8 * 6);

    btnHighligh[4].setTexture(BtnNotHighlight);
    btnHighligh[4].setPosition(width / 2 - 220, height / 8 * 6);

    ItemSelect = 0;
}

GameMenu::~GameMenu() {

}

void GameMenu::draw(sf::RenderWindow &window) {
    MenuPanel.loadFromFile("GameMenu/MainMenu.png");
    sf::Sprite menuPanel;
    menuPanel.setPosition(width / 2 - 290, height / 8);
    menuPanel.setTexture(MenuPanel);
    window.setView(window.getDefaultView());
    window.draw(menuPanel);
    for (int i = 0; i < 5; ++i) {
        window.draw(buttons[i]);
        window.draw(btnHighligh[i]);
    }
}

void GameMenu::MoveUp() {
    if (ItemSelect - 1 >= 0) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect--;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}

void GameMenu::MoveDown() {
    if (ItemSelect + 1 < 5) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect++;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);
    }
}
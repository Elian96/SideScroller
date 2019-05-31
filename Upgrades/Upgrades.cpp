#include <sstream>
#include <fstream>
#include <iostream>
#include "Upgrades.h"
#include "../GlobalVars.h"
#include "../StateMachine/StateMachine.h"

using namespace std;

Upgrades::Upgrades() {
    std::ifstream MoneyFile("Upgrades/money.txt");

    while (!MoneyFile.eof()) {
        MoneyFile >> moneyTotal;
    }
    MoneyFile.close();
    std::ofstream CleanMoney;
    CleanMoney.open("Upgrades/money.txt", std::ofstream::trunc);
    CleanMoney.close();

    std::ifstream upgrades("Upgrades/Upgrades.txt");

    for (int j = 0; j < 4; ++j) {
        upgrades >> upg[j];
    }
    upgrades.close();

    std::ofstream CleanUpgrades;
    CleanUpgrades.open("Upgrades/Upgrades.txt", std::ofstream::trunc);
    CleanUpgrades.close();

    HealthLevel = std::stoi(upg[0]);
    StrengthLevel = std::stoi(upg[1]);
    SpeedLevel = std::stoi(upg[2]);

    std::cout << HealthLevel << endl;
    std::cout << StrengthLevel << endl;
    std::cout << SpeedLevel << endl;

    if (HealthLevel == 0 || HealthLevel == 1) {
        Health.loadFromFile("UpgradeButtons/HealthUpgrade1.png");
        healthCost = 50;
        HealthText.setString(to_string(healthCost));

    } else if (HealthLevel == 2) {
        Health.loadFromFile("UpgradeButtons/HealthUpgrade2.png");
        healthCost = 100;
        HealthText.setString(to_string(healthCost));

    } else if (HealthLevel == 3) {
        Health.loadFromFile("UpgradeButtons/HealthUpgrade3.png");
        healthCost = 200;
        HealthText.setString(to_string(healthCost));
    } else if (HealthLevel == 4) {
        Health.loadFromFile("UpgradeButtons/HealthUpgrade4.png");
        healthCost = 400;
        HealthText.setString(to_string(healthCost));
    } else if (HealthLevel == 5) {
        Health.loadFromFile("UpgradeButtons/HealthUpgrade5.png");
        HealthText.setString("Full");
        HealthText.setPosition(width / 2, height / 8 * 3);
    }

    if (StrengthLevel == 1 || StrengthLevel == 0) {
        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade1.png");
        strengthCost = 50;
        StrengthText.setString(to_string(strengthCost));
    } else if (StrengthLevel == 2) {
        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade2.png");
        strengthCost = 100;
        StrengthText.setString(to_string(strengthCost));
    } else if (StrengthLevel == 3) {
        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade3.png");
        strengthCost = 200;
        StrengthText.setString(to_string(strengthCost));
    } else if (StrengthLevel == 4) {
        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade4.png");
        strengthCost = 400;
        StrengthText.setString(to_string(strengthCost));
    } else if (StrengthLevel == 5) {
        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade5.png");
        StrengthText.setString("Full");
        StrengthText.setPosition(width / 2, height / 8 * 4);
    }

    if (SpeedLevel == 1 || SpeedLevel == 0) {
        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade1.png");
        speedCost = 50;
        SpeedText.setString(to_string(speedCost));
    } else if (SpeedLevel == 2) {
        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade2.png");
        speedCost = 100;
        SpeedText.setString(to_string(speedCost));
    } else if (SpeedLevel == 3) {
        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade3.png");
        speedCost = 200;
        SpeedText.setString(to_string(speedCost));
    } else if (SpeedLevel == 4) {
        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade4.png");
        speedCost = 400;
        SpeedText.setString(to_string(speedCost));
    } else if (SpeedLevel == 5) {
        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade5.png");
        SpeedText.setString("Full");
        SpeedText.setPosition(width / 2, height / 8 * 5);
    }

}

bool Upgrades::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {

    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    BtnHighlight.loadFromFile("UpgradeButtons/UpgradeHighlight.png");
    BtnNotHighlight.loadFromFile("Buttons/BtnNotHighlight.png");
    Money.loadFromFile("UpgradeButtons/MoneyBase.png");
    Back.loadFromFile("Buttons/BackBtn.png");
    ItemSelect = 0;

    MoneyText.setFont(font);
    MoneyText.setString(to_string(moneyTotal));
    MoneyText.setScale(1.2, 1.2);

    HealthText.setFont(font);
    HealthText.setString(to_string(healthCost));

    StrengthText.setFont(font);
    StrengthText.setString(to_string(strengthCost));

    SpeedText.setFont(font);
    SpeedText.setString(to_string(speedCost));

    sf::Texture textureBackground;
    textureBackground.loadFromFile("data/MainBackground.png");
    sf::Sprite background(textureBackground);

    money.setTexture(Money);
    money.setPosition(width / 2 - 113, height / 8 * 2);

    MoneyText.setPosition(width / 2 - 20, height / 8 * 2 + 30);
    HealthText.setPosition(width / 2 + 20, height / 8 * 3);
    StrengthText.setPosition(width / 2 + 20, height / 8 * 4);
    SpeedText.setPosition(width / 2 + 20, height / 8 * 5);

    buttons[0].setTexture(Health);
    buttons[0].setPosition(width / 2 - 180, height / 8 * 3);

    btnHighligh[0].setTexture(BtnHighlight);
    btnHighligh[0].setPosition(width / 2 - 200, height / 8 * 3);

    buttons[1].setTexture(Strength);
    buttons[1].setPosition(width / 2 - 180, height / 8 * 4);

    btnHighligh[1].setTexture(BtnNotHighlight);
    btnHighligh[1].setPosition(width / 2 - 200, height / 8 * 4);

    buttons[2].setTexture(Speed);
    buttons[2].setPosition(width / 2 - 180, height / 8 * 5);

    btnHighligh[2].setTexture(BtnNotHighlight);
    btnHighligh[2].setPosition(width / 2 - 200, height / 8 * 5);

    buttons[3].setTexture(Back);
    buttons[3].setPosition(width / 2 - 180, height / 8 * 6);

    btnHighligh[3].setTexture(BtnNotHighlight);
    btnHighligh[3].setPosition(width / 2 - 200, height / 8 * 6);


    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            MoveUp();
                            break;
                            //Get the function MoveDown from the GameMenu class
                        case sf::Keyboard::Down:
                            MoveDown();
                            break;
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                        case sf::Keyboard::Return:

                            switch (GetItemSelect()) {
                                case 0:
                                    if (HealthLevel == 1 && moneyTotal >= 50) {
                                        Health.loadFromFile("UpgradeButtons/HealthUpgrade2.png");
                                        HealthLevel++;
                                        moneyTotal -= 50;
                                        healthCost *= 2;
                                        HealthText.setString(to_string(healthCost));
                                        MoneyText.setString(to_string(moneyTotal));

                                    } else if (HealthLevel == 2 && moneyTotal >= 100) {
                                        Health.loadFromFile("UpgradeButtons/HealthUpgrade3.png");
                                        HealthLevel++;
                                        moneyTotal -= 100;
                                        healthCost *= 2;
                                        HealthText.setString(to_string(healthCost));
                                        MoneyText.setString(to_string(moneyTotal));

                                    } else if (HealthLevel == 3 && moneyTotal >= 200) {
                                        Health.loadFromFile("UpgradeButtons/HealthUpgrade4.png");
                                        HealthLevel++;
                                        moneyTotal -= 200;
                                        healthCost *= 2;
                                        HealthText.setString(to_string(healthCost));
                                        MoneyText.setString(to_string(moneyTotal));
                                    } else if (HealthLevel == 4 && moneyTotal >= 400) {
                                        Health.loadFromFile("UpgradeButtons/HealthUpgrade5.png");
                                        HealthLevel++;
                                        moneyTotal -= 400;
                                        HealthText.setString("Full");
                                        HealthText.setPosition(width / 2, height / 8 * 3);
                                    }
                                    break;
                                case 1:
                                    if (StrengthLevel == 1 && moneyTotal >= 50) {
                                        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade2.png");
                                        StrengthLevel++;
                                        moneyTotal -= 50;
                                        strengthCost *= 2;
                                        StrengthText.setString(to_string(strengthCost));
                                        MoneyText.setString(to_string(moneyTotal));
                                    } else if (StrengthLevel == 2 && moneyTotal >= 100) {
                                        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade3.png");
                                        StrengthLevel++;
                                        moneyTotal -= 100;
                                        strengthCost *= 2;
                                        StrengthText.setString(to_string(strengthCost));
                                        MoneyText.setString(to_string(moneyTotal));
                                    } else if (StrengthLevel == 3 && moneyTotal >= 200) {
                                        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade4.png");
                                        StrengthLevel++;
                                        moneyTotal -= 200;
                                        strengthCost *= 2;
                                        StrengthText.setString(to_string(strengthCost));
                                        MoneyText.setString(to_string(moneyTotal));
                                    } else if (StrengthLevel == 4 && moneyTotal >= 400) {
                                        Strength.loadFromFile("UpgradeButtons/StrengthUpgrade5.png");
                                        StrengthLevel++;
                                        moneyTotal -= 400;
                                        StrengthText.setString("Full");
                                        StrengthText.setPosition(width / 2, height / 8 * 4);
                                        MoneyText.setString(to_string(moneyTotal));
                                    }
                                    break;
                                case 2:
                                    if (SpeedLevel == 1 && moneyTotal >= 50) {
                                        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade2.png");
                                        SpeedLevel++;
                                        moneyTotal -= 50;
                                        speedCost *= 2;
                                        SpeedText.setString(to_string(speedCost));
                                        MoneyText.setString(to_string(moneyTotal));
                                    } else if (SpeedLevel == 2 && moneyTotal >= 100) {
                                        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade3.png");
                                        SpeedLevel++;
                                        moneyTotal -= 100;
                                        speedCost *= 2;
                                        SpeedText.setString(to_string(speedCost));
                                        MoneyText.setString(to_string(moneyTotal));
                                    } else if (SpeedLevel == 3 && moneyTotal >= 200) {
                                        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade4.png");
                                        SpeedLevel++;
                                        moneyTotal -= 200;
                                        speedCost *= 2;
                                        SpeedText.setString(to_string(speedCost));
                                        MoneyText.setString(to_string(moneyTotal));
                                    } else if (SpeedLevel == 4 && moneyTotal >= 400) {
                                        Speed.loadFromFile("UpgradeButtons/SpeedUpgrade5.png");
                                        SpeedLevel++;
                                        moneyTotal -= 400;
                                        SpeedText.setString("Full");
                                        SpeedText.setPosition(width / 2, height / 8 * 5);
                                        MoneyText.setString(to_string(moneyTotal));
                                    }
                                    break;

                                case 3:
                                    StateMachine StateMachine;
                                    StateMachine.SendSignal(Signals::menu, window, fullScreen, sound, music, level);
                                    break;
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
        UpgradesPanel.loadFromFile("Upgrades/UpgradesPanel.png");
        sf::Sprite upgradesPanel;
        upgradesPanel.setPosition(width / 2 - 280, height / 8 - 30);
        upgradesPanel.setTexture(UpgradesPanel);

        std::ofstream AddMoney;
        AddMoney.open("Upgrades/money.txt");
        AddMoney << moneyTotal;
        AddMoney.close();

        std::ofstream AddUpgrades;
        AddUpgrades.open("Upgrades/Upgrades.txt");
        AddUpgrades << HealthLevel << endl << StrengthLevel << endl << SpeedLevel << endl;
        AddUpgrades.close();
        window.draw(upgradesPanel);

        for (int i = 0; i < 4; ++i) {
            window.draw(buttons[i]);
            window.draw(btnHighligh[i]);
        }

        window.draw(money);
        window.draw(MoneyText);
        window.draw(HealthText);
        window.draw(StrengthText);
        window.draw(SpeedText);
        window.display();
    }


    return true;
}

void Upgrades::MoveUp() {
    if (ItemSelect - 1 >= 0) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect--;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);

    }
}

void Upgrades::MoveDown() {
    if (ItemSelect + 1 < 4) {
        btnHighligh[ItemSelect].setTexture(BtnNotHighlight);
        ItemSelect++;
        btnHighligh[ItemSelect].setTexture(BtnHighlight);
    }
}

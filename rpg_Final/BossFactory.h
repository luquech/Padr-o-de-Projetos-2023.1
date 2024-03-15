#ifndef BOSSFACTORY_H
#define BOSSFACTORY_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>

Enemy* create_boss_enemy() {
    Boss* boss = new Boss();
    boss->setName("Katyusco o terrivel");
    boss->setAttackPoints(90);
    boss->setLifePoints(1000);

    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    window.setFramerateLimit(60);

    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("boss.png")) {
        std::cout << "Erro ao carregar a imagem do Boss." << std::endl;
        return nullptr;
    }
    sprite.setTexture(texture);

    while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                    // Fecha a janela quando qualquer tecla for pressionada
                    window.close();
                }
            }
            window.clear();
            window.draw(sprite);
            window.display();
        }
    return boss;
}



#endif

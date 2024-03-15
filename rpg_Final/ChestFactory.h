#ifndef CHESTFACTORY_H
#define CHESTFACTORY_H

#include "Chest.h"
#include <SFML/Graphics.hpp>

Chest* create_random_chest() {
	
    int random = rand() % 100; // gera um número aleatório entre 0 e 99
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    window.setFramerateLimit(60);
	

    sf::Texture texture;
    sf::Sprite sprite;

    if (random < 5) { // 5% de chance de ExplosiveBox
        ExplosiveBox* explosiveBox = new ExplosiveBox();

        if (!texture.loadFromFile("explosivo.png")) {
            std::cout << "Erro ao carregar a imagem da Explosive Box." << std::endl;
            return nullptr;
        }
        sprite.setTexture(texture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
                    window.close();
            }

            window.clear();
            window.draw(sprite);
            window.display();
        }

        return explosiveBox;
    } else if (random < 5 + 40) { // 40% de chance de VidaBox
        VidaBox* vidaBox = new VidaBox();

        if (!texture.loadFromFile("vida.png")) {
            std::cout << "Erro ao carregar a imagem da Vida Box." << std::endl;
            return nullptr;
        }
        sprite.setTexture(texture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed|| event.type == sf::Event::MouseButtonPressed)
                    window.close();
            }

            window.clear();
            window.draw(sprite);
            window.display();
        }

        return vidaBox;
    } else if (random < 5 + 40 + 35) { // 35% de chance de ManaBox
        ManaBox* manaBox = new ManaBox();

        if (!texture.loadFromFile("mana.png")) {
            std::cout << "Erro ao carregar a imagem da Mana Box." << std::endl;
            return nullptr;
        }
        sprite.setTexture(texture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
                    window.close();
            }

            window.clear();
            window.draw(sprite);
            window.display();
        }

        return manaBox;
    } else { // 20% de chance de EmptyChest
        EmptyChest* emptyChest = new EmptyChest();

        if (!texture.loadFromFile("vazio.png")) {
            std::cout << "Erro ao carregar a imagem do Empty Chest." << std::endl;
            return nullptr;
        }
        sprite.setTexture(texture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
                    window.close();
            }

            window.clear();
            window.draw(sprite);
            window.display();
        }

        return emptyChest;
    }
}


#endif



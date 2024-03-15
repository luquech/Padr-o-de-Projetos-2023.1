#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

Enemy* create_random_enemy() {
    srand(static_cast<unsigned>(time(nullptr)));
    int random = rand() % 3; // gera um número aleatório entre 0 e 2

    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    window.setFramerateLimit(60);

    sf::Texture texture;
    sf::Sprite sprite;

    if (random == 0) {
        Giant* giant = new Giant();
        giant->setName("Giant");
        giant->setAttackPoints(20);
        giant->setLifePoints(250);
        if (!texture.loadFromFile("giant.png")) {
            std::cout << "Erro ao carregar a imagem do Giant." << std::endl;
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
        return giant;
    } else if (random == 1) {
        Demon* demon = new Demon();
        demon->setName("Demon");
        demon->setAttackPoints(25);
        demon->setLifePoints(200);
        if (!texture.loadFromFile("demon.png")) {
            std::cout << "Erro ao carregar a imagem do Demon." << std::endl;
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
        return demon;
    } else {
        Bandit* bandit = new Bandit();
        bandit->setName("Bandit");
        bandit->setAttackPoints(30);
        bandit->setLifePoints(150);
        if (!texture.loadFromFile("bandit.png")) {
            std::cout << "Erro ao carregar a imagem do Bandit." << std::endl;
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
        return bandit;
    }
}

#endif



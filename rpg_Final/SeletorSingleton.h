#include "PersonagemNEW.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class PersonagemFactory {
private:
    static std::shared_ptr<PersonagemFactory> instance;

    PersonagemFactory() {} // Construtor privado para evitar instanciação direta

public:
    static std::shared_ptr<PersonagemFactory> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<PersonagemFactory>(new PersonagemFactory());
        }
        return instance;
    }

    std::shared_ptr<Personagem> createPersonagem() {
        int escolha;
        std::cout << "Selecione o tipo de personagem: " << std::endl;
        std::cout << "1. Mago" << std::endl;
        std::cout << "2. Guerreiro" << std::endl;
        std::cout << "3. Arqueiro" << std::endl;
        std::cout << "Digite aqui a opção: ";

        sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
        window.setFramerateLimit(60);

        // Carregar a imagem
        sf::Texture texture;
        if (!texture.loadFromFile("seletor.png")) {
            std::cout << "Erro ao carregar a imagem." << std::endl;
            return nullptr;
        }

        // Criar sprite para a imagem
        sf::Sprite sprite(texture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Num1) {
                        escolha = 1;
                        window.close();
                    } else if (event.key.code == sf::Keyboard::Num2) {
                        escolha = 2;
                        window.close();
                    } else if (event.key.code == sf::Keyboard::Num3) {
                        escolha = 3;
                        window.close();
                    }
                }
            }

            window.clear();
            window.draw(sprite); // Desenhar o sprite na janela
            window.display();
        }

         switch (escolha) {
            case 1:
                return std::make_shared<Mago>("Mago", 50, 100,200,100, 200,8);
            case 2:
                return std::make_shared<Guerreiro>("Guerreiro", 40, 80,250,80, 250,7);
            case 3:
                return std::make_shared<Arqueiro>("Arqueiro", 35, 120,180,120, 180,5);
            default:
                std::cout << "Opção inválida. Criando um Guerreiro por padrão." << std::endl;
                return std::make_shared<Guerreiro>("Guerreiro", 40, 80,250,80, 250,7);
        
    }
  }    
};

std::shared_ptr<PersonagemFactory> PersonagemFactory::instance = nullptr;
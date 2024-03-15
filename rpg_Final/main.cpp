#include <iostream>
#include <string>
#include <vector>

#include "Enemy.h"
#include "GameState.h"
#include "PersonagemNEW.h"
#include <SFML/Audio.hpp>


int main() {
   /* Warrior warrior("Kratos");
    Archer archer("Linky");
    Mage mage("Jana");

    warrior.addPot("Health Potion");
    warrior.addPot("Mana Potion");

    std::cout << "Life:" << warrior.getLifePoints() << "\n";
    std::cout << "Ataque:" << warrior.getAttackPoints()<< "\n";
    std::cout << "Mana:" << warrior.getManaPoints()<< "\n";

    std::vector<std::string> warriorPotions = warrior.getListPots();
    for (const auto& potion : warriorPotions) {
        std::cout << potion << " ";
   }
    */  

    IniciarJogo();
    std::shared_ptr<PersonagemFactory> factory = PersonagemFactory::getInstance(); // obtem instancia unica de personagem tenq colocar no gamestate depois
   std::shared_ptr<Personagem> personagem = factory->createPersonagem();// cria o personagem tenq colocar no gamestate depois
    
    exibirPersonagem(personagem.get());
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
  
    Game* game = Game::getInstance(); // Obtém a instância única do jogo
    game->setPersonagem(personagem);  
    game->setState(new MenuState());
    
    while (true) {
        game->play();
    }


  
    return 0;
}

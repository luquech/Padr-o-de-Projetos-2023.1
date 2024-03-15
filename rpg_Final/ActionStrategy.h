#include "Enemy.h"
#include "PersonagemNEW.h"
#include <cstdlib> // Para a funcao std::rand()
#include <ctime> // Para inicializar a semente do gerador de numeros aleatórios
#include <iostream>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void exibirAcao(Personagem *jogador, Enemy *inimigo, string descricao){
    sf::RenderWindow window(sf::VideoMode(800,600),"RPG");

    sf::Font font,fontp;
    sf::Texture MagoT,ArqueiroT,GuerreiroT,BattleT,GiganteT,DemonioT,BandidoT,BossT;


    if(!font.loadFromFile("Arial.ttf")){
        cout << "Erro" << endl;
    }
    if(!fontp.loadFromFile("PixelBloated.ttf")){
        cout << "Erro" << endl;
    }

    if(!BattleT.loadFromFile("battle.png")){
        cout << "Erro ao carregar" << endl;
    }

    if(!MagoT.loadFromFile("MagoB.png")){
        cout << "Erro ao carregar" << endl;
    }

    if(!ArqueiroT.loadFromFile("ArqueiroB.png")){
        cout << "Erro ao carregar" << endl;
    }

    if(!GuerreiroT.loadFromFile("GuerreiroB.png")){
        cout << "Erro ao carregar" << endl;
    }

    if(!BandidoT.loadFromFile("BanditB.png")){
        cout << "Erro";
    }
    if(!DemonioT.loadFromFile("DemonB.png")){
        cout << "Erro";
    }
    if(!GiganteT.loadFromFile("GigantB.png")){
        cout << "Erro";
    }
    if(!BossT.loadFromFile("BossB.png")){
        cout << "Erro";
    }

    sf::Text Titulo("Voce esta em batalha",fontp,35),Atacar("1 - Atacar",fontp,25),Defender("2 - Defender",fontp,25),
    Inventario("3 - Inventario",fontp,25),Especial("4 - Usar Especial",fontp,25);
    Titulo.setPosition(40,50);
    Titulo.setFillColor(sf::Color::Magenta);
    Atacar.setPosition(50,500);
    Defender.setPosition(50,550);
    Inventario.setPosition(400,500);
    Especial.setPosition(400,550);

    sf::Text efeito(descricao,fontp,18);
    efeito.setPosition(100,525);


    sf::Sprite Battle(BattleT),Heroi,Inimigo;

    if(jogador->getNome()=="Mago")
        Heroi.setTexture(MagoT);
    else if (jogador->getNome()=="Arqueiro")
        Heroi.setTexture(ArqueiroT);
    else
        Heroi.setTexture(GuerreiroT);

    if(inimigo->getName() == "Bandit")
        Inimigo.setTexture(BandidoT);
    else if (inimigo->getName() == "Katyusco o terrivel")
        Inimigo.setTexture(BossT);
    else if(inimigo->getName() == "Demon")
        Inimigo.setTexture(DemonioT);
    else
        Inimigo.setTexture(GiganteT);

    Heroi.setPosition(-200,180);
    Inimigo.setPosition(400,200);



    sf::Text vidaText;
    sf::Text ataqueText;
    sf::Text manaText;

    vidaText.setFont(fontp);
    vidaText.setCharacterSize(30);
    vidaText.setFillColor(sf::Color::White);
    vidaText.setPosition(10, 150);

    ataqueText.setFont(fontp);
    ataqueText.setCharacterSize(30);
    ataqueText.setFillColor(sf::Color::White);
    ataqueText.setPosition(10, 190);

    manaText.setFont(fontp);
    manaText.setCharacterSize(30);
    manaText.setFillColor(sf::Color::White);
    manaText.setPosition(10, 230);

    sf::Text statusInimigoText;
    sf::Text vidaInimigoText;
    sf::Text ataqueInimigoText;

    statusInimigoText.setFont(fontp);
    statusInimigoText.setCharacterSize(30);
    statusInimigoText.setFillColor(sf::Color::White);
    statusInimigoText.setPosition(550, 10);

    vidaInimigoText.setFont(fontp);
    vidaInimigoText.setCharacterSize(30);
    vidaInimigoText.setFillColor(sf::Color::White);
    vidaInimigoText.setPosition(520, 150);

    ataqueInimigoText.setFont(fontp);
    ataqueInimigoText.setCharacterSize(30);
    ataqueInimigoText.setFillColor(sf::Color::White);
    ataqueInimigoText.setPosition(520, 190);
    
    vidaText.setString("Vida: " + std::to_string(jogador->getLifePoints()));
    ataqueText.setString("Ataque: " + std::to_string(jogador->getAttackPoints()));
    manaText.setString("Mana: " + std::to_string(jogador->getManaPoints()));

    vidaInimigoText.setString("Vida: " + std::to_string(inimigo->getLifePoints()));
    ataqueInimigoText.setString("Ataque: " + std::to_string(inimigo->getAttackPoints()));



    bool Principal=true,Activate=false;
    int choice=0;
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                exit(0);
            else if (event.type == sf::Event::KeyPressed)
            {
                window.close();
            }
        }
        
    


    window.clear();
    window.draw(Battle);
    window.draw(Titulo);

    if(Principal){
        window.draw(Heroi);
        window.draw(Inimigo);
        window.draw(efeito);
        window.draw(vidaText);
        window.draw(ataqueText);
        window.draw(manaText);
        
        window.draw(vidaInimigoText);
        window.draw(ataqueInimigoText);
    }

    window.display();


    }
    
}


void ArredondarKEKW(sf::RectangleShape &rectangle, sf::Text text){

    sf::FloatRect textBounds = text.getLocalBounds();
    rectangle.setSize(sf::Vector2f(textBounds.width + 20, textBounds.height + 20));
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setPosition(text.getPosition() - sf::Vector2f(10, 10));
}
void ArredondarKEKW2(sf::RectangleShape &rectangle, sf::Text text){

    sf::FloatRect textBounds = text.getLocalBounds();
    rectangle.setSize(sf::Vector2f(textBounds.width + 30, textBounds.height + 30));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setPosition(text.getPosition() - sf::Vector2f(10, 10));
    rectangle.setOutlineThickness(7.f);
}
class Action {
public:
  virtual void execute() = 0;
  virtual ~Action() {}
  string descricao;
};

class AttackAction : public Action {
private:
  Personagem &personagem; // Referência para o personagem principal
  Enemy &enemy;           // Referência para o inimigo

public:
  AttackAction(Personagem &character, Enemy &enemy)
      : personagem(character), enemy(enemy) {
    std::srand(
        std::time(0)); // Inicializar a semente do gerador de numeros aleatórios
  }
  void execute() override {
    std::cout << "hello" ;
    // Lógica para o ataque do jogador
    int attackPoints =
        personagem.getAttackPoints(); // Obter os pontos de ataque do personagem
                                      // principal
    int enemyLifePoints =
        enemy.getLifePoints(); // Obter os pontos de vida do inimigo

    int damage =
        calculateDamage(attackPoints); // Calcular o dano causado ao inimigo

    enemy.setLifePoints(enemyLifePoints -
                        damage); // Diminuir os pontos de vida do inimigo

    if (damage > attackPoints) {
      std::cout << "Voce atacou o inimigo e causou um acerto critico de "
                << damage << " de dano!\n";
				
                descricao= "Voce atacou o inimigo e causou um acerto critico de " + to_string(damage) + " de dano!\n";
                exibirAcao(&personagem, &enemy, descricao);
    } else {
      std::cout << "Voce atacou o inimigo e causou " << damage << " de dano!\n";
      descricao= "Voce atacou o inimigo e causou " + to_string(damage) + " de dano!\n";
	  exibirAcao(&personagem, &enemy, descricao);

    }
  }

private:
  int calculateDamage(int attackPoints) {
    int randomValue = rand() % 10; // Gera um numero aleatório de 0 a 9

    if (randomValue == 1) {
      return static_cast<int>(
          attackPoints * 1.25); // Multiplica o dano por 1,25 se o numero for 1
    } else {
      return attackPoints; // Caso contrario, retorna o dano sem modificacao
    }
  }
};
class DefendAction : public Action {
private:
  std::shared_ptr<Personagem> personagem;
  bool* skipEnemyTurn;  // Ponteiro para a variavel de controle

public:
  DefendAction(std::shared_ptr<Personagem> character, bool* skipEnemy) : personagem(character), skipEnemyTurn(skipEnemy) {}

  void execute() override {
    // Lógica de defesa
    srand(static_cast<unsigned int>(time(0)));
    int agilidade = personagem->getAgilidade();
    
    int random = rand() % (10 - agilidade);
    if (random % 2 == 0) {
      std::cout << "Voce conseguiu se esquivar com sucesso!\n";
      *skipEnemyTurn = true;  // Defesa bem sucedida, pula o turno do inimigo
    } else {
      std::cout << "Voce nao conseguiu se esquivar do ataque!\n";
	  
    }
  }
};

class PotionAction : public Action {
private:
    shared_ptr<Personagem> boneco;

public:
    PotionAction(shared_ptr<Personagem> boneco) : boneco(boneco) {}

    void execute() override {
        sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
        sf::Texture InventarioA, InventarioG, InventarioM, Vida, Mana, Arco, Lanca, Cajado;
        sf::Font font, fontp;

        if (!font.loadFromFile("Arial.ttf"))
            cout << "Erro ao carregar" << endl;

    if (!fontp.loadFromFile("PixelBloated.ttf"))
            cout << "Erro ao carregar" << endl;

    if(!Arco.loadFromFile("Arco.png"))
        cout << "erro ao carregar" << endl;

    if(!Lanca.loadFromFile("Lanca.png"))
        cout << "erro ao carregar" << endl;
    
    if(!Cajado.loadFromFile("Cajado.png"))
        cout << "erro ao carregar" << endl;

    if (!InventarioA.loadFromFile("InventarioA.png")) {
        cout << "Erro ao carregar" << endl;
 
    }

    if (!InventarioM.loadFromFile("InventarioM.png")) {
        cout << "Erro ao carregar" << endl;
    
    }

    if (!InventarioG.loadFromFile("InventarioG.png")) {
        cout << "Erro ao carregar" << endl;
   
    }
    if (!Vida.loadFromFile("Vida2.png")) {
        cout << "Erro ao carregar" << endl;
   
    }
    if (!Mana.loadFromFile("Mana2.png")) {
        cout << "Erro ao carregar" << endl;

    }
	
	sf::Sprite Inventario, ManaS(Mana),Arma;
    sf::Sprite VidaS(Vida);
	
	sf::Text QuantidadeV,NameV("- Pocao da Vida",fontp,25),Titulo("Voce esta na mochila",fontp,35),ArmaT,
    ExcluirB("Modo de Exclusao : OFF",fontp,35),UsarP("Modo Pocao : OFF",fontp,35);
	
	Titulo.setPosition((window.getSize().x /2) - (Vida.getSize().x /2) -50,(window.getSize().y /2) - (Vida.getSize().y /2)-50);
    Titulo.setFillColor(sf::Color::Magenta);
    ExcluirB.setFillColor(sf::Color::Black);
    UsarP.setFillColor(sf::Color::Black);
    ExcluirB.setPosition((window.getSize().x /2) - (Vida.getSize().x /2) -80,(window.getSize().y /2) +180);
    UsarP.setPosition((window.getSize().x /2) - (Vida.getSize().x /2) -80,(window.getSize().y /2) +240);
	
	sf::Text Life;
    Life.setFont(fontp); Life.setCharacterSize(25);
	
	sf::Text ManaT;
    ManaT.setFont(fontp); ManaT.setCharacterSize(25);
	
	sf::Text AttackP;
    AttackP.setFont(fontp); AttackP.setCharacterSize(25);
	
	Life.setPosition(15,80);
    ManaT.setPosition(15,130);
    AttackP.setPosition(15,170);
	
	ArmaT.setFont(fontp);
    ArmaT.setCharacterSize(25);
	
	if(boneco->getNome()=="Arqueiro"){
        Inventario.setTexture(InventarioA);
        Arma.setTexture(Arco);
        ArmaT.setString("- Arco de Artemis");
        ArmaT.setFillColor(sf::Color::Yellow);
    }
    else if(boneco->getNome()=="Mago"){
        Inventario.setTexture(InventarioM);
        Arma.setTexture(Cajado);
        ArmaT.setString("- Cajado Arcano");
        ArmaT.setFillColor(sf::Color::Magenta);
    }
    else if(boneco->getNome()=="Guerreiro"){
        Inventario.setTexture(InventarioG);
        Arma.setTexture(Lanca);
        ArmaT.setString("- Lanca de Ares");
        ArmaT.setFillColor(sf::Color::Red);
    } 
	
	QuantidadeV.setFont(font);
    QuantidadeV.setCharacterSize(25);
    QuantidadeV.setFillColor(sf::Color::Black);
    NameV.setFillColor(sf::Color::Red);
    sf::Text QuantidadeM,NameM("- Pocao de Mana",fontp,25);
    NameM.setFillColor(sf::Color::Blue);
    QuantidadeM.setFont(font);
    QuantidadeM.setCharacterSize(25);
    QuantidadeM.setFillColor(sf::Color::Black);
    bool MExcluir=false;
    bool MPocao=false;
	
	sf::Vector2u windowSize = window.getSize();
    sf::RectangleShape rectangle;
	
	while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                exit(0);
            if(event.type == sf::Event::MouseButtonPressed){

                if(ExcluirB.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                   
                    if(MExcluir){
                    MExcluir=false;
                    ExcluirB.setString("Modo de Exclusao : OFF");
                    }
                    else if(!MPocao){
                        MExcluir=true;
                        ExcluirB.setString("Modo de Exclusao : ON");
                    }
                }
                if(MExcluir && NameV.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && boneco->searchItem("Life Potion") >=1 ){
                    
                    boneco->removeInv("Life Potion",1);
                }
                if(MExcluir && NameM.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && boneco->searchItem("Mana Potion") >=1){
            
                    boneco->removeInv("Mana Potion",1);

                }

                
                if(UsarP.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                    
                    if(MPocao){
                        MPocao=false;
                        UsarP.setString("Modo Pocao : OFF");
                    }
                    else if (!MExcluir){
                        MPocao=true;
                        UsarP.setString("Modo Pocao : ON");
                    }

                }
                if(MPocao && NameV.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && boneco->searchItem("Life Potion") >=1){
                    boneco->usarPot("Vida");
                    cout << "Curado" << endl;
                }
                if(MPocao && NameM.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && boneco->searchItem("Mana Potion") >=1){
                    boneco->usarPot("Mana");
                    cout << "Mais Mana" << endl;
                }
            }
            if (event.key.code == sf::Keyboard::Escape){
                window.close();
				
       
			}
        }
		
		Life.setString("HP : " + to_string(boneco->getLifePoints()));
        AttackP.setString("Attack : " + to_string(boneco->getAttackPoints()));
        ManaT.setString("Mana : " + to_string(boneco->getManaPoints()));
		
		int pos= -80;
        string item;
        for(int i=0;i<2;i++){
            if(i==0)
                item="Life Potion";
            else
                item="Mana Potion";
            if(!boneco->searchItem(item))
                continue;
            if(i==0){
                VidaS.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)-110,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos));
                QuantidadeV.setString("x"+to_string(boneco->searchItem(item)));
                QuantidadeV.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)+190,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos) +212);
                NameV.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)+250,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos) +212);
            }
            else{
                ManaS.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)-110,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos));
                QuantidadeM.setString("x"+to_string(boneco->searchItem(item)));
                QuantidadeM.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)+190,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos) +212);
                NameM.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)+250,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos) +212);
            }pos+=60;
        }
		
		window.clear();
        window.draw(Inventario);
        window.draw(Life);
        window.draw(ManaT);
        window.draw(AttackP);
        window.draw(Titulo);
        ArredondarKEKW(rectangle,ExcluirB);
        window.draw(ExcluirB);
        window.draw(rectangle);

        window.draw(UsarP);
        ArredondarKEKW(rectangle,UsarP);
        window.draw(rectangle);

        if(boneco->searchItem("Mana Potion") >=1){
            window.draw(ManaS);
            window.draw(QuantidadeM);
            window.draw(NameM);
        }
        
        if(boneco->searchItem("Life Potion") >=1){
            window.draw(VidaS);
            window.draw(QuantidadeV);
            window.draw(NameV);
        }
            Arma.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)-85,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos)+10);
            ArmaT.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)+250,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos) +212);

            window.draw(Arma);
            window.draw(ArmaT);
        
        
        window.display();
    }
    }
};


class EspecialAction : public Action {
private:
  Personagem& personagem; // Referência para o personagem principal
  Enemy& enemy;           // Referência para o inimigo
  bool* skipEnemyTurn;    // Ponteiro para a variável skipEnemyTurn

public:
  EspecialAction(Personagem& character, Enemy& enemy, bool* skipTurn)
      : personagem(character), enemy(enemy), skipEnemyTurn(skipTurn) {}

  void execute() override {
    int mana = personagem.getManaPoints();
    string atackinfo;
    if (mana > 20) {
      // Lógica para o ataque do jogador
      int attackPoints =
          personagem.getAttackPoints(); // Obter os pontos de ataque do
                                        // personagem principal
      int enemyLifePoints =
          enemy.getLifePoints(); // Obter os pontos de vida do inimigo

      int damage =
          calculateDamage(attackPoints); // Calcular o dano causado ao inimigo

      enemy.setLifePoints(enemyLifePoints -
                          damage); // Diminuir os pontos de vida do inimigo

      std::string especial = personagem.getEspecial();

      personagem.setManaPoints(mana - 20);
      

      std::cout << "Voce usou a habilidade especial " << especial << "! e causou " << damage << " de dano!\n" << std::endl;
      atackinfo= especial + "! causou " + to_string(damage) + " de dano!";
      exibirAcao(&personagem, &enemy, atackinfo);
	  system("pause");
	  system("cls");
    } else {
      std::cout << "Mana insuficiente para usar a habilidade especial."
                << std::endl;
    atackinfo= "Mana insuficiente";
    
    exibirAcao(&personagem, &enemy, atackinfo);
	  system("pause");
	  system("cls");
	
	*skipEnemyTurn = true;
    }
  }

private:
  int calculateDamage(int attackPoints) {

    return attackPoints * 2; // Caso contrario, retorna o dano sem modificacao
  }
};


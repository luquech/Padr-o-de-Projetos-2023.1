
#include "ActionStrategy.h"
#include "ChestFactory.h"
#include "EnemyFactory.h"
#include "BossFactory.h"
#include "SeletorSingleton.h"
#include <cstdlib> // Para a funcão rand()
#include <ctime>   // Para inicializar a semente rand()
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int num,auxE=0;
int xp = 0;
sf::Music music;

void exibirJanela(Personagem *jogador, Enemy *inimigo,string descricao){
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

    sf::Text Titulo("Voce esta em batalha", fontp, 35);
    sf::Text Atacar("1 - Atacar", fontp, 25);
    sf::Text Defender("2 - Defender", fontp, 25);
    sf::Text Inventario("3 - Inventario", fontp, 25);
    sf::Text Especial("4 - Usar Especial", fontp, 25);

    Titulo.setPosition(40, 50);
    Titulo.setFillColor(sf::Color::Magenta);
    Atacar.setPosition(50, 500);
    Defender.setPosition(50, 550);
    Inventario.setPosition(400, 500);
    Especial.setPosition(400, 550);

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


     sf::Text efeito(descricao,fontp,18);
    efeito.setPosition(40,525);


    sf::Sprite Battle(BattleT),Heroi,Inimigo;

    if(jogador->getNome()=="Mago")
        Heroi.setTexture(MagoT);
    else if (jogador->getNome()=="Arqueiro")
        Heroi.setTexture(ArqueiroT);
    else
        Heroi.setTexture(GuerreiroT);

    if(inimigo->getName() == "Bandit")
        Inimigo.setTexture(BandidoT);
    
    else if(inimigo->getName() == "Demon")
        Inimigo.setTexture(DemonioT);
    else
        Inimigo.setTexture(GiganteT);

    Heroi.setPosition(-200,180);
    Inimigo.setPosition(400,200);


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
        window.draw(vidaText);
        window.draw(ataqueText);
        window.draw(manaText);
        
        window.draw(vidaInimigoText);
        window.draw(ataqueInimigoText);
        window.draw(efeito);   
    }

    window.display();


    }
    
}


void Arredondar(sf::RectangleShape &rectangle, sf::Text text){

    sf::FloatRect textBounds = text.getLocalBounds();
    rectangle.setSize(sf::Vector2f(textBounds.width + 20, textBounds.height + 20));
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setPosition(text.getPosition() - sf::Vector2f(10, 10));
}
void Arredondar2(sf::RectangleShape &rectangle, sf::Text text){

    sf::FloatRect textBounds = text.getLocalBounds();
    rectangle.setSize(sf::Vector2f(textBounds.width + 30, textBounds.height + 30));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setPosition(text.getPosition() - sf::Vector2f(10, 10));
    rectangle.setOutlineThickness(7.f);
}


void ExibirTelaMago() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    
    sf::Texture texture;
    if (!texture.loadFromFile("AncestralMago.png")) {
        // Tratar erro ao carregar a textura
        return;
    }
    
    sf::Sprite sprite(texture);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed ||
                event.type == sf::Event::MouseButtonPressed) {
                window.close();
            }
        }
        
        window.clear();
        window.draw(sprite);
        window.display();
    }
};
void ExibirTelaGuerreiro() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    
    sf::Texture texture;
    if (!texture.loadFromFile("AncestralGuerreiro.png")) {
        // Tratar erro ao carregar a textura
        return;
    }
    
    sf::Sprite sprite(texture);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed ||
                event.type == sf::Event::MouseButtonPressed) {
                window.close();
            }
        }
        
        window.clear();
        window.draw(sprite);
        window.display();
    }
};

void ExibirTelaArqueiro() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    
    sf::Texture texture;
    if (!texture.loadFromFile("AncestralArqueiro.png")) {
        // Tratar erro ao carregar a textura
        return;
    }
    
    sf::Sprite sprite(texture);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed ||
                event.type == sf::Event::MouseButtonPressed) {
                window.close();
            }
        }
        
        window.clear();
        window.draw(sprite);
        window.display();
    }
};
void PoderAncestral(Personagem *jogador){

  std::cout << "\nApos adiquirir experiencia ao longo do jogo...\n";
  std::cout << "Voce desperta um poder ancestral!\n";
  std::cout << "Agora seus status estao completamente melhorados!\n\n";
  
  
  if (jogador->getNome() == "Mago") {
      jogador->setLifePoints(700);
      jogador->setAttackPoints(80);
      jogador->setManaPoints(150);
      jogador->setManaMax(150);
      jogador->setLifeMax(700);
      ExibirTelaMago();
    }
    if (jogador->getNome() == "Guerreiro") {
      jogador->setLifePoints(1000);
      jogador->setAttackPoints(100);
      jogador->setManaPoints(125);
      jogador->setManaMax(125);
      jogador->setLifeMax(1000);
      ExibirTelaGuerreiro();
    }
    if (jogador->getNome() == "Arqueiro") {
      jogador->setLifePoints(600);
      jogador->setAttackPoints(120);
      jogador->setManaPoints(120);
      jogador->setManaMax(120);
      jogador->setLifeMax(600);
      ExibirTelaArqueiro();
    }
  
}

void IniciarJogo() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");

    
    if (!music.openFromFile("gamesong.ogg")) {
        std::cout << "Erro ao carregar o arquivo de música." << std::endl;
    }
    music.setLoop(true);
    music.play();
    music.setVolume(50);
    sf::Texture Cenario,Start;
    if (!Cenario.loadFromFile("Cenario2.png")) {
        cout << "erro" << endl;
    }
    if (!Start.loadFromFile("Start.png")) {
        cout << "erro" << endl;
    }


    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = Cenario.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    float scaleFactor = std::max(scaleX, scaleY);

    sf::Sprite StartS(Start),CenarioS;
    CenarioS.setTexture(Cenario);

    StartS.setPosition((window.getSize().x /2) - (Start.getSize().x /2) ,
    (window.getSize().y /2) - (Start.getSize().y /2));
    

    bool sair=false;
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                exit(0);
             if (event.type == sf::Event::MouseButtonPressed)
            {
                    // Verifica se o clique foi dentro do botão
                    if (StartS.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {   
                        sair=true;
                        window.close();
                    }
    
            }



        }



        window.clear();
        window.draw(CenarioS);
        window.draw(StartS);
        window.display();
        if(sair==true)
            break;


    }
}

void exibirPersonagem(Personagem* personagem) {
    std::string nome = personagem->getNome();

    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    window.setFramerateLimit(60);

    sf::Texture texture;
    sf::Sprite sprite;

    if (nome == "Mago") {
        if (!texture.loadFromFile("mago.png")) {
            std::cout << "Erro ao carregar a imagem do Mago." << std::endl;
            return;
        }
    } else if (nome == "Guerreiro") {
        if (!texture.loadFromFile("guerreiro.png")) {
            std::cout << "Erro ao carregar a imagem do Guerreiro." << std::endl;
            return;
        }
    } else if (nome == "Arqueiro") {
        if (!texture.loadFromFile("arqueiro.png")) {
            std::cout << "Erro ao carregar a imagem do Arqueiro." << std::endl;
            return;
        }
    } else {
        std::cout << "Nome de personagem invalido." << std::endl;
        return;
    }

    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed){
                window.close();}
        if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            window.close();
        }
    }
}

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

void exibirJogador(Personagem *jogador) {

  std::cout << "\nStatus do Jogador:" << std::endl;
  std::cout << "Vida: " << jogador->getLifePoints() << "\n" << std::endl;
  std::cout << "Ataque: " << jogador->getAttackPoints() << "\n" << std::endl;
  std::cout << "Mana: " << jogador->getManaPoints() << "\n" << std::endl;
}

int gameover(Personagem *jogador) {
  int var = 0;
  if (jogador->getLifePoints() <= 0) {
    var = 1;
    std::cout << "Game over, Voce foi derrotado!";
    std::cout << "\nReiniciando o jogo!!\n";
	system("pause");
    jogador->clearInv();
    if (jogador->getNome() == "Mago") {
      jogador->setLifePoints(200);
      jogador->setManaPoints(100);
    }
    if (jogador->getNome() == "Guerreiro") {
      jogador->setLifePoints(250);
      jogador->setManaPoints(80);
    }
    if (jogador->getNome() == "Arqueiro") {
      jogador->setLifePoints(180);
      jogador->setManaPoints(120);
    }
    
  }
  return var;
}

void exibirStatus(Personagem *jogador, Enemy *inimigo) {
  std::cout << "\nStatus do Jogador:" << std::endl;
  std::cout << "Vida: " << jogador->getLifePoints() << "\n" << std::endl;
  std::cout << "Ataque: " << jogador->getAttackPoints() << "\n" << std::endl;
  std::cout << "Mana: " << jogador->getManaPoints() << "\n" << std::endl;
  std::cout << std::endl;

  std::cout << "\nStatus do Inimigo:" << std::endl;
  std::cout << "Vida: " << inimigo->getLifePoints() << "\n" << std::endl;
  std::cout << "Ataque: " << inimigo->getAttackPoints() << "\n" << std::endl;
}

class GameState;

class Game {
private:
  static Game *instance; // Instância unica do jogo
  GameState *currentState;
  std::shared_ptr<Personagem>
      personagem; // Adicionado o objeto compartilhado do tipo Personagem

  Game();
  ~Game();

public:
  static Game *getInstance(); // Metodo para obter a instância unica do jogo

  void setState(GameState *state);
  std::shared_ptr<Personagem>
  getPersonagem(); // Metodo para obter o objeto Personagem
  void setPersonagem(
      std::shared_ptr<Personagem> p); // Metodo para definir o objeto Personagem
  void play();
  friend class Personagem;
};

class GameState {
public:
  virtual ~GameState() {}
  virtual void play(Game *game) = 0;
};

class creditosState : public GameState {
public:
  void play(Game *game) override;
};

class ExploringState : public GameState {
public:
  void play(Game *game) override;
};

class MenuState : public GameState {
public:
  void play(Game *game) override;
};

class BattleState : public GameState {
private:
  std::unique_ptr<Enemy> enemy;
  bool isPlayerTurn;
  std::map<int, std::unique_ptr<Action>> actions;
  bool skipEnemyTurn;
public:
  void play(Game *game) override;
};

Game *Game::instance = nullptr;

Game::Game() : currentState(nullptr) {}

Game::~Game() { delete currentState; }

Game *Game::getInstance() {
  if (instance == nullptr) {
    instance = new Game();
  }
  return instance;
}

void Game::setState(GameState *state) {
  if (currentState != nullptr) {
    delete currentState;
  }
  currentState = state;
}

std::shared_ptr<Personagem> Game::getPersonagem() { return personagem; }

void Game::setPersonagem(std::shared_ptr<Personagem> p) { personagem = p; }

void Game::play() {
  if (currentState != nullptr) {
    currentState->play(this);
  }
}
class InvState : public GameState {
public:
  void play(Game *game) override;
};

void InvState::play(Game *game){
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
	sf::Texture InventarioA, InventarioG, InventarioM, Vida, Mana,Arco,Lanca,Cajado;
    sf::Font font,fontp;


	
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
	
	if(game->getPersonagem()->getNome()=="Arqueiro"){
        Inventario.setTexture(InventarioA);
        Arma.setTexture(Arco);
        ArmaT.setString("- Arco de Artemis");
        ArmaT.setFillColor(sf::Color::Yellow);
    }
    else if(game->getPersonagem()->getNome()=="Mago"){
        Inventario.setTexture(InventarioM);
        Arma.setTexture(Cajado);
        ArmaT.setString("- Cajado Arcano");
        ArmaT.setFillColor(sf::Color::Magenta);
    }
    else if(game->getPersonagem()->getNome()=="Guerreiro"){
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
                if(MExcluir && NameV.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && game->getPersonagem()->searchItem("Life Potion") >=1 ){
                    
                    game->getPersonagem()->removeInv("Life Potion",1);
                }
                if(MExcluir && NameM.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && game->getPersonagem()->searchItem("Mana Potion") >=1){
            
                    game->getPersonagem()->removeInv("Mana Potion",1);

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
                if(MPocao && NameV.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && game->getPersonagem()->searchItem("Life Potion") >=1){
                    game->getPersonagem()->usarPot("Vida");
                    cout << "Curado" << endl;
                }
                if(MPocao && NameM.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && game->getPersonagem()->searchItem("Mana Potion") >=1){
                    game->getPersonagem()->usarPot("Mana");
                    cout << "Mais Mana" << endl;
                }
            }
            if (event.key.code == sf::Keyboard::Escape){
                window.close();
				game->setState(new ExploringState());
       
			}
        }
		
		Life.setString("HP : " + to_string(game->getPersonagem()->getLifePoints()));
        AttackP.setString("Attack : " + to_string(game->getPersonagem()->getAttackPoints()));
        ManaT.setString("Mana : " + to_string(game->getPersonagem()->getManaPoints()));
		
		int pos= -80;
        string item;
        for(int i=0;i<2;i++){
            if(i==0)
                item="Life Potion";
            else
                item="Mana Potion";
            if(!game->getPersonagem()->searchItem(item))
                continue;
            if(i==0){
                VidaS.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)-110,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos));
                QuantidadeV.setString("x"+to_string(game->getPersonagem()->searchItem(item)));
                QuantidadeV.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)+190,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos) +212);
                NameV.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)+250,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos) +212);
            }
            else{
                ManaS.setPosition((window.getSize().x /2) - (Vida.getSize().x /2)-110,(window.getSize().y /2) - (Vida.getSize().y /2) + (pos));
                QuantidadeM.setString("x"+to_string(game->getPersonagem()->searchItem(item)));
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
        Arredondar(rectangle,ExcluirB);
        window.draw(ExcluirB);
        window.draw(rectangle);

        window.draw(UsarP);
        Arredondar(rectangle,UsarP);
        window.draw(rectangle);

        if(game->getPersonagem()->searchItem("Mana Potion") >=1){
            window.draw(ManaS);
            window.draw(QuantidadeM);
            window.draw(NameM);
        }
        
        if(game->getPersonagem()->searchItem("Life Potion") >=1){
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


void ExploringState::play(Game *game) {
  std::cout << "\nJogador esta explorando o mundo...\n" << std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    sf::Texture texture;
    if (!texture.loadFromFile("explorer.png")) {
        std::cout << "Erro ao carregar a imagem da Explorer" << std::endl;

    }
    sf::Sprite sprite(texture);

    while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                window.close();
            }
        }
    }

    window.clear();
    window.draw(sprite);
    window.display();
}
  int randomEvent = std::rand() % 100;

  if (randomEvent <= 40) {
    std::cout << "\nEncontrou um inimigo!\n" << std::endl;
    game->setState(new BattleState());
  }

  else  {
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    window.setFramerateLimit(60);

    sf::Texture chestTexture;
    sf::Sprite chestSprite;

    if (!chestTexture.loadFromFile("Bau.png")) {
        std::cout << "Erro ao carregar a imagem do bau." << std::endl;
    
    }
    chestSprite.setTexture(chestTexture);

    bool shouldOpenChest = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Num1) {
                    shouldOpenChest = true;
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Num2) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(chestSprite);
        window.display();
    }
    if (shouldOpenChest) {
      Chest *chest = create_random_chest(); // Cria um bau aleatorio

      if (chest->is_empty()) {
        std::cout << "\nO bau esta vazio.\n" << std::endl;
      } else {
        std::cout << "\nVoce encontrou: \n" << chest->get_drop() << std::endl;
        if (chest->get_drop() != "Voce abriu um Bau Explosivo")
          game->getPersonagem()->addInv(chest->get_drop());
        else {
          game->getPersonagem()->setLifePoints(
          game->getPersonagem()->getLifePoints() - 50);
          exibirJogador(game->getPersonagem().get());
          if (gameover(game->getPersonagem().get()) == 1) {
            game->getPersonagem()->clearInv();
            game->setState(new MenuState);
            return;
          }
        }
		system("cls");
        auxE=1;
        game->setState(new InvState());
        
            }
      // falta a logica de pegar a pot e colocar na mochila
      delete chest; // Libera a memoria alocada para o bau
    } else {
      std::cout << "\nVoce decidiu nao abrir o bau.\n" << std::endl;
    }
  }
}
class Arquivo {
public:
    void pararMusica(sf::Music& music);
};

void Arquivo::pararMusica(sf::Music& music) {
    music.stop();
}


int exibirJanela(Personagem *jogador, Enemy *inimigo){
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
    

    sf::Text Titulo("Voce esta em batalha", fontp, 35);
    sf::Text Atacar("1 - Atacar", fontp, 25);
    sf::Text Defender("2 - Defender", fontp, 25);
    sf::Text Inventario("3 - Inventario", fontp, 25);
    sf::Text Especial("4 - Usar Especial", fontp, 25);

    Titulo.setPosition(40, 50);
    Titulo.setFillColor(sf::Color::Magenta);
    Atacar.setPosition(50, 500);
    Defender.setPosition(50, 550);
    Inventario.setPosition(400, 500);
    Especial.setPosition(400, 550);

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


    sf::Sprite Battle(BattleT),Heroi,Inimigo;

    if(jogador->getNome()=="Mago")
        Heroi.setTexture(MagoT);
    else if (jogador->getNome()=="Arqueiro")
        Heroi.setTexture(ArqueiroT);
    else
        Heroi.setTexture(GuerreiroT);

    if(inimigo->getName() == "Bandit")
        Inimigo.setTexture(BandidoT);
    else if(inimigo->getName() == "Demon")
        Inimigo.setTexture(DemonioT);
    else
        Inimigo.setTexture(GiganteT);

    Heroi.setPosition(-200,180);
    Inimigo.setPosition(400,200);


    bool Principal=true,Activate=false;
    int choice=0;
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                exit(0);
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Num1) {
                     return 1;
                     window.close();
                }
                else if (event.key.code == sf::Keyboard::Num2) {
                    return 2;
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Num3) {
                    return 3;
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Num4) {
                    return 4;
                    window.close();
                }
            }
        }
        
    


    window.clear();
    window.draw(Battle);
    window.draw(Titulo);

    if(Principal){
        window.draw(Atacar);
        window.draw(Defender);
        window.draw(Inventario);
        window.draw(Especial);
        window.draw(Heroi);
        window.draw(Inimigo);
        window.draw(vidaText);
        window.draw(ataqueText);
        window.draw(manaText);
        
        window.draw(vidaInimigoText);
        window.draw(ataqueInimigoText);   
    }

    window.display();


    }
    return 0;
}





void BattleState::play(Game* game) {
    bool boss = false;
    skipEnemyTurn = false;
    if (xp == 7){
	  music.stop();
	  if (!music.openFromFile("BossSong.ogg")) {
				std::cout << "erro";
			}
	   music.play();
	   music.setVolume(100);
      enemy = std::unique_ptr<Enemy>(create_boss_enemy());
      boss = true;
	  system("cls");
	  PoderAncestral(game->getPersonagem().get());
	  system("pause");
	  
    }
	else{
    enemy = std::unique_ptr<Enemy>(create_random_enemy());
    system("cls");
    enemy->showStatus(); // Exibe o status atual do inimigo

    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");

    sf::Texture texture;
    if (!texture.loadFromFile("run.png")) {
        std::cout << "Erro ao carregar a imagem da luta." << std::endl;
        return;
    }

    sf::Sprite sprite(texture);

    bool running = true;
    while (window.isOpen() && running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    num = 1;
                    running = false; // Sai do loop e executa o if (num == 1)
                } else if (event.key.code == sf::Keyboard::Num2) {
                    num = 2; // Define num como 2 e executa o if (num == 2)
                    running = false; // Sai do loop
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    }
	
    if (num == 1) {
        game->setState(new ExploringState());
    } else if (num == 2 || xp==7) {
        std::cout << "\nJogador esta em uma batalha...\n" << std::endl;

      
        // Adicione as acões disponíveis ao mapa 'actions'
        actions[1] = std::make_unique<AttackAction>(*game->getPersonagem(), *enemy.get());
        actions[2] = std::make_unique<DefendAction>(game->getPersonagem(), &skipEnemyTurn);
        actions[3] = std::make_unique<PotionAction>(game->getPersonagem());
        actions[4] = std::make_unique<EspecialAction>(*game->getPersonagem(), *enemy.get(), &skipEnemyTurn);
        
        while (true) {
            if (isPlayerTurn) {
                // Turno do jogador
				system("cls");
                exibirStatus(game->getPersonagem().get(), enemy.get()); // Exibe o status atual do jogador e do inimigo
                std::cout << "\e o seu turno! Escolha uma acao:\n";
                std::cout << "1. Atacar\n";
                std::cout << "2. Defender\n";
                std::cout << "3. Usar Pocao\n";
                std::cout << "4. Usar Especial\n";
                
                int choice=exibirJanela(game->getPersonagem().get(),enemy.get());
                
                if (choice == 3) {
                    auto it = actions.find(choice);
                    if (it != actions.end()) {
                        it->second->execute();
                        continue;  // Continua no turno do jogador sem trocar para o turno do inimigo
                    } else {
                        std::cout << "\nOpcao invalida!\n";
                        continue;
                    }
                }
                
                auto it = actions.find(choice);
                if (it != actions.end()) {
                    it->second->execute();
                } else {
                    std::cout << "\nOpcao invalida!\n";
                    continue;
                }
            } else {
                string acaoini;
                // Turno do inimigo
                if (!skipEnemyTurn) {
                    std::cout << "\e o turno do inimigo!\n";
                    string acaoini;
                    // Logica para o ataque do inimigo
                    
                    int enemyAttackPoints = enemy->getAttackPoints();
                    int playerLifePoints = game->getPersonagem()->getLifePoints();
                    
                    // int damage = calculateDamage(enemyAttackPoints); // Calcular o dano causado ao jogador
                    
                    game->getPersonagem()->setLifePoints(playerLifePoints - enemy->getAttackPoints()); // Diminuir os pontos de vida do jogador
                    system("cls");
                    std::cout << "\nO inimigo atacou Voce e causou " << enemy->getAttackPoints() << " de dano!\n";
                    acaoini= "O inimigo atacou Voce e causou " + to_string(enemy->getAttackPoints()) + " de dano!";
                    exibirAcao(game->getPersonagem().get(), enemy.get(),acaoini);
                    
					
                } else {
                    std::cout << "\nO turno do inimigo foi pulado devido à defesa bem sucedida!\n";
                    acaoini= "Defesa bem sucedida,Turno inimigo pulado!";
					exibirAcao(game->getPersonagem().get(), enemy.get(),acaoini);
                    skipEnemyTurn = false;  // Reseta a variavel de controle
                }
            }
            
            // Atualizacão dos status, verificacão de fim de batalha, etc.
            // ...e
            
            // Exibe os status atualizados do jogador e do inimigo
            
            // Verifica se a batalha terminou
            if (enemy->getLifePoints() <= 0) {
                std::cout << "\nVoce derrotou o inimigo!\n";
                break;
            } else if (game->getPersonagem()->getLifePoints() <= 0) { // Acessa o objeto Personagem atraves do Game
                std::cout << "\nVoce foi derrotado pelo inimigo!\n";
				if(boss==true){
					boss=false;
					music.stop();
				if (!music.openFromFile("gamesong.ogg")) {
					std::cout << "erro";
				}
				music.play();
				music.setVolume(100);
				
				
				}
                break;
            }
            
            // Alterna entre os turnos do jogador e do inimigo
            isPlayerTurn = !isPlayerTurn;
        }
        
        // Ao final da batalha, retornar para o estado de exploracão
		if (boss == true){
		  music.stop();
		if (!music.openFromFile("Credits.ogg")) {
				std::cout << "erro";
			}
	   music.play();
	   music.setVolume(100);
          game->setState(new creditosState());
          return;
          
        }
        
        if (gameover(game->getPersonagem().get()) == 1) {
            sf::RenderWindow gameOverWindow(sf::VideoMode(800, 600), "RPG");
    
    sf::Texture gameOverTexture;
    if (!gameOverTexture.loadFromFile("gameover.png")) {
        std::cout << "Erro ao carregar o arquivo de imagem." << std::endl;
    }
    
    sf::Sprite gameOverSprite(gameOverTexture);

    while (gameOverWindow.isOpen()) {
        sf::Event event;
        while (gameOverWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gameOverWindow.close();

            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
                gameOverWindow.close();
                game->setState(new MenuState());
                
        }

        gameOverWindow.clear();
        gameOverWindow.draw(gameOverSprite);
        gameOverWindow.display();
    }
} else {
            exibirJogador(game->getPersonagem().get());
            game->setState(new ExploringState());
        }
    }
	
}
void creditosState::play(Game* game) {
    std::cout << "\nVoce Derrotou o boss Katiusco, o terrivel\n";
    std::cout << "Sua bravura foi essencial para os dev's nao irem para a final!\n";
    std::cout << "Obrigado!!";

    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");
    window.setFramerateLimit(60);

    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("creditos.png")) {
        std::cout << "Erro ao carregar a imagem de creditos." << std::endl;
        exit(1);
    }
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    exit(0);
}


void MenuState::play(Game* game) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");

    // Carrega a imagem do botão
    sf::Texture Cenario,Titulo,BackT,Cenario2;
    sf::Font font,fontp;
    if(!font.loadFromFile("Arial.ttf")){
        cout << "Erro" << endl;
    }
    if(!fontp.loadFromFile("PixelBloated.ttf")){
        cout << "Erro" << endl;
    }

    sf::Text Iniciar("Iniciar",fontp,40),Devs("Devs",fontp,40),Sair("Sair",fontp,40);

    if (!Cenario.loadFromFile("Cenario.png")) {
        cout << "erro" << endl;
    }
    if (!Cenario2.loadFromFile("CenarioDevs.png")) {
        cout << "erro" << endl;
    }
    
    if(!BackT.loadFromFile("Back.png")){
        cout << "Erro" << endl;
    }

    if (!Titulo.loadFromFile("Revange.png"))
        cout << "ERRO" << endl;

    sf::Sprite CenarioS,TituloS,Back,DevsC;
    CenarioS.setTexture(Cenario);
    Back.setTexture(BackT);
    TituloS.setTexture(Titulo);   
    DevsC.setTexture(Cenario2);
    TituloS.setPosition(150,-50);




    // Define a posição do botão
    Iniciar.setPosition(300,300);
    Back.setPosition(20,500);
    Devs.setPosition(325,450);

    Sair.setPosition(620,500);

    
    bool janela1= true;
    bool janela2=false;
    sf::RectangleShape Arredondamento;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            exit(0);

            // Verifica se o botão foi clicado
            if (event.type == sf::Event::MouseButtonPressed)
            {

                    // Verifica se o clique foi dentro do botão
                    if (janela1 &&  Iniciar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        window.close();
                        game->setState(new ExploringState());
                        
        
                    }
                    if (janela1 && Devs.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        janela1= false;
                        janela2=true;
                        Devs.setFillColor(sf::Color::Black);
                        Devs.setPosition(325,93);

                    }
                    if (janela1 && Sair.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        exit(0);

                    }
                    if (janela2 && Back.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        janela1=true;
                        janela2=false;
                        Devs.setFillColor(sf::Color::White);
                        Devs.setPosition(325,450);
                    

                    }

            }
        }
        window.draw(CenarioS);
        if (janela1){

        window.draw(TituloS);
        
        Arredondar2(Arredondamento,Iniciar);
        window.draw(Arredondamento);
        window.draw(Iniciar);

        Arredondar2(Arredondamento,Devs);
        window.draw(Arredondamento);
        window.draw(Devs);

        Arredondar2(Arredondamento,Sair);
        window.draw(Arredondamento);
        window.draw(Sair);

        window.display();
        }
        if (janela2){
        window.clear();
        window.draw(Devs);
        window.draw(DevsC);
        window.draw(Back);
        window.draw(Devs);
    
        window.display();
        }
    }
}

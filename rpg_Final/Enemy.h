#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
using namespace std;



class Enemy {
protected:
  std::string nome;
  int attackPoints;
  int lifePoints;

public:
  virtual string getName() = 0;
  virtual int getAttackPoints() = 0;
  virtual int getLifePoints() = 0;
  virtual void showStatus() = 0;
  virtual void setName(const string &nome) { this->nome = nome; }
  virtual void setAttackPoints(int attackPoints) {
    this->attackPoints = attackPoints;
  }
  virtual void setLifePoints(int lifePoints) { this->lifePoints = lifePoints; }
};

class Giant : public Enemy {
public:
  string getName() override { return nome; }

  int getAttackPoints() override { return attackPoints; }

  int getLifePoints() override { return lifePoints; }


  void showStatus() override {
    if (getLifePoints() <= 0) {
      std::cout << "O monstro morreu!" << std::endl;
    } else {
      std::cout << "Nome: " << getName() << std::endl;
      std::cout << "Pontos de Ataque: " << getAttackPoints() << std::endl;
      std::cout << "Pontos de Vida: " << getLifePoints() << std::endl;
    }
  }
};

class Demon : public Enemy {
public:
  string getName() override { return nome; }

  int getAttackPoints() override { return attackPoints; }

  int getLifePoints() override { return lifePoints; }


  void showStatus() override {
    if (getLifePoints() <= 0) {
      std::cout << "O monstro morreu!" << std::endl;
    } else {
      std::cout << "Nome: " << getName() << std::endl;
      std::cout << "Pontos de Ataque: " << getAttackPoints() << std::endl;
      std::cout << "Pontos de Vida: " << getLifePoints() << std::endl;
    }
  }
};

class Bandit : public Enemy {
public:
  string getName() override { return nome; }

  int getAttackPoints() override { return attackPoints; }

  int getLifePoints() override { return lifePoints; }


  void showStatus() override {
    if (getLifePoints() <= 0) {
      std::cout << "O monstro morreu!" << std::endl;
    } else {
      std::cout << "Nome: " << getName() << std::endl;
      std::cout << "Pontos de Ataque: " << getAttackPoints() << std::endl;
      std::cout << "Pontos de Vida: " << getLifePoints() << std::endl;
    }
  }
};

class Boss : public Enemy {
public:
  string getName() override { return nome; }

  int getAttackPoints() override { return attackPoints; }

  int getLifePoints() override { return lifePoints; }


  void showStatus() override {
    if (getLifePoints() <= 0) {
      std::cout << "O monstro morreu!" << std::endl;
    } else {
      std::cout << "Nome: " << getName() << std::endl;
      std::cout << "Pontos de Ataque: " << getAttackPoints() << std::endl;
      std::cout << "Pontos de Vida: " << getLifePoints() << std::endl;
    }
  }
};

#endif // ENEMY_H

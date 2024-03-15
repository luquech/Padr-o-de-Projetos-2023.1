#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Personagem {
protected:
    std::string nome;
    std::string specialName;
    int attackPoints;
    int manaPoints;
    int lifePoints;
    int manaMax;
    int lifeMax;
    std::vector<std::string> Inventario;
    int agilidade;
public:
    Personagem(const std::string& nome, const std::string& specialName, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade);

    const std::string& getNome() const;
    int getAttackPoints() const;
    int getManaPoints() const;
    int getLifePoints() const;
    int getManaMax() const;
    int getLifeMax() const;
    int getAgilidade() const;
    std::string getEspecial();
    void setManaPoints(int manaPoints);
    void setAttackPoints(int attackPoints);
    std::vector<std::string> getListPots() const;
    void setLifePoints(int lifePoints);
    void setManaMax(int manaMax);
    void setLifeMax(int lifeMax);
    void Damage(int damage);
    void addInv(std::string item);
    void removeInv(std::string item, int quantidade);
    void removeInv(int item, int quantidade);
    int searchItem(std::string Item);
    int searchItem(int item);
    bool InvEmpty();
    void clearInv();
    void analisarInv();
    void analisarInv(bool n);
    void usarPot(std::string Pocao);
};

class Mago : public Personagem {
public:
    Mago(const std::string& nome, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade);
};

class Guerreiro : public Personagem {
public:
    Guerreiro(const std::string& nome, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade);
};

class Arqueiro : public Personagem {
public:
    Arqueiro(const std::string& nome, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade);
};

Personagem::Personagem(const std::string& nome, const std::string& specialName, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade)
    : nome(nome), specialName(specialName), attackPoints(attackPoints), manaPoints(manaPoints), lifePoints(lifePoints), manaMax(manaMax), lifeMax(lifeMax), agilidade(agilidade) {}

const std::string& Personagem::getNome() const {
    return nome;
}

void Personagem::addInv(std::string item) {
    Inventario.push_back(item);
    std::sort(Inventario.begin(), Inventario.end());
}

void Personagem::clearInv() {
    Inventario.clear();
}

void Personagem::usarPot(std::string Pocao) {
    if (Pocao == "Mana") {
        if (manaMax > manaPoints + 40)
            manaPoints += 40;
        else if (manaMax == manaPoints)
            return;
        else
            manaPoints = manaMax;
        removeInv("Mana Potion", 1);
    }
    else if (Pocao == "Vida") {
        if (lifeMax > lifePoints + 50)
            lifePoints += 50;
        else if (lifeMax == lifePoints)
            return;
        else
            lifePoints = lifeMax;
        removeInv("Life Potion", 1);
    }
}

void Personagem::removeInv(std::string item, int quantidade) {
    if (searchItem(item) < quantidade) {
        return;
    }

    for (auto i = Inventario.begin(); i != Inventario.end(); i=i) {
        if (*i == item) {
            i = Inventario.erase(i);
            quantidade--;
            if (quantidade == 0) {
                break;
            }
        }
        else {
            ++i;
        }
    }
}

void Personagem::removeInv(int item, int quantidade) {
    if (item == 1)
        removeInv(Inventario[0], quantidade);
    else {
        std::string aux = Inventario[0];
        for (int i = 0; i < Inventario.size(); i=i
        ) {
            if (Inventario[i] == aux)
                continue;
            else {
                aux = Inventario[i];
                item--;
            }
            if (item == 1)
                removeInv(aux, quantidade);
        }
    }
}

int Personagem::searchItem(std::string Item) {
    if (InvEmpty() == 1)
        return 0;
    int contador = 0;
    for (int i = 0; i < Inventario.size(); i++) {
        if (Inventario[i] == Item)
            contador++;
    }
    return contador;
}

bool Personagem::InvEmpty() {
    if (Inventario.empty())
        return 1;
    else
        return 0;
}

void Personagem::analisarInv() {
    std::map<std::string, int> contagem;

    for (const auto& elemento : Inventario) {
        contagem[elemento]++;
    }

    std::cout << "Itens:" << std::endl;
    for (const auto& par : contagem) {
        std::cout << par.first << " - Quantidade: " << par.second << std::endl;
    }
}

void Personagem::analisarInv(bool n) {
    std::map<std::string, int> contagem;

    for (const auto& elemento : Inventario) {
        contagem[elemento]++;
    }

    std::cout << "Itens:" << std::endl;
    int aux = 0;
    for (const auto& par : contagem) {
        aux++;
        std::cout << aux << "." << par.first << " - Quantidade: " << par.second << std::endl;
    }
}

int Personagem::getAttackPoints() const {
    return attackPoints;
}

int Personagem::getAgilidade() const {
    return agilidade;
}

int Personagem::getManaPoints() const {
    return manaPoints;
}

int Personagem::getLifePoints() const {
    return lifePoints;
}

int Personagem::getManaMax() const {
    return manaMax;
}

int Personagem::getLifeMax() const {
    return lifeMax;
}

std::string Personagem::getEspecial() {
    return specialName;
}
void Personagem::setManaMax(int manaMax) {
    this->manaMax = manaMax;
}

void Personagem::setLifeMax(int lifeMax) {
    this->lifeMax = lifeMax;
}
void Personagem::setLifePoints(int lifePoints) {
    this->lifePoints = lifePoints;
}

void Personagem::setAttackPoints(int attackPoints) {
    this->attackPoints = attackPoints;
}

void Personagem::setManaPoints(int manaPoints) {
    this->manaPoints = manaPoints;
}

void Personagem::Damage(int damage) {
    lifePoints -= damage;
}

Mago::Mago(const std::string& nome, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade)
    : Personagem(nome, "Fireball", attackPoints, manaPoints, lifePoints, manaMax, lifeMax, agilidade) {}

Guerreiro::Guerreiro(const std::string& nome, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade)
    : Personagem(nome, "Rage", attackPoints, manaPoints, lifePoints, manaMax, lifeMax, agilidade) {}

Arqueiro::Arqueiro(const std::string& nome, int attackPoints, int manaPoints, int lifePoints, int manaMax, int lifeMax, int agilidade)
    : Personagem(nome, "Precision Shot", attackPoints, manaPoints, lifePoints, manaMax, lifeMax, agilidade) {}

#endif  // PERSONAGEM_H

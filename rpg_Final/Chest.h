#ifndef CHEST_H
#define CHEST_H

#include <string>
#include <cstdlib>

using namespace std;

class Chest {
public:
  virtual bool is_empty() = 0;
  virtual string get_drop() = 0;
};

class EmptyChest : public Chest {
public:
  bool is_empty() override { return true; }

  string get_drop() override { return "Nothing"; }
};

class ManaBox : public Chest {
public:
  bool is_empty() override { return false; }

  string get_drop() override { return "Mana Potion"; }
};

class VidaBox : public Chest {
public:
  bool is_empty() override { return false; }

  string get_drop() override { return "Life Potion"; }
};

class ExplosiveBox : public Chest {
private:
  string drop;

public:
  ExplosiveBox() {
    // logica de dano
  }

  bool is_empty() override { return false; }

  string get_drop() override { return "Voce abriu um Bau Explosivo"; }
};

#endif

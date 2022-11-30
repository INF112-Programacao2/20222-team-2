#pragma once

#include "GameObject.h"
#include "Position.h"

#include <allegro5/allegro.h>

enum class Cor {
  PRETO,
  BRANCO
};

class Peca : public GameObject {
protected:
  Cor _cor;
  Position _pos;
  ALLEGRO_BITMAP* _sprite;

  Peca(Cor cor, Position pos, ALLEGRO_BITMAP* _sprite);
  ~Peca() {}

public:
  virtual void onRender();
  Position movepeca(); //New
};

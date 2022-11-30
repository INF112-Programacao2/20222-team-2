#pragma once

#include "Peca.h"

class Peao : public Peca {
public:
  Peao(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  ~Peao() {}
  Position movepeca();
};

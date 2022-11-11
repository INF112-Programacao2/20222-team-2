#pragma once

#include "Peca.h"

class Rei : public Peca {
public:
  Rei(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  ~Rei() {}
};

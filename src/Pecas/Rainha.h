#pragma once

#include "Peca.h"

class Rainha : public Peca
{
public:
  Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  ~Rainha() {}

  bool validarMovimento(Position pos);
};

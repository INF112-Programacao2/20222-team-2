#pragma once

#include "Peca.h"

class Cavalo : public Peca
{
public:
  Cavalo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  ~Cavalo() {}

  bool validarMovimento(Position pos);
};

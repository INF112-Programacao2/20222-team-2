#pragma once

#include "Peca.h"

class Bispo : public Peca
{
public:
  Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  ~Bispo() {}

  bool validarMovimento(Position pos);
};

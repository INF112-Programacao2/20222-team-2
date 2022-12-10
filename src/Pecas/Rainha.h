#pragma once

#include "Peca.h"

class Rainha : public Peca
{
public:
  Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  ~Rainha() {}

  virtual bool validarMovimento(Position pos) const override;
};

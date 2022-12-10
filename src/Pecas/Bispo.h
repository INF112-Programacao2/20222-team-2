#pragma once

#include "Peca.h"

class Bispo : public Peca
{
public:
  Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  ~Bispo() {}

  virtual bool validarMovimento(Position pos) const override;
};

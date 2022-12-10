#pragma once

#include "Peca.h"

class Rainha : public Peca
{
public:
  Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Rainha() {}

  virtual bool validarMovimento(Position pos) const override;
  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

#pragma once

#include "../Peca.h"

class Rainha : public Peca
{
public:
  Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Rainha() {}

  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

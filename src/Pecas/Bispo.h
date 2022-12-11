#pragma once

#include "../Peca.h"

class Bispo : public Peca
{
public:
  Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Bispo() {}

  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

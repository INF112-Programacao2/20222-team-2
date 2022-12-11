#pragma once

#include "../Peca.h"

class Cavalo : public Peca
{
public:
  Cavalo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Cavalo() {}

  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

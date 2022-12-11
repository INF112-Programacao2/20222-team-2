#pragma once

#include "../Peca.h"

class Peao : public Peca
{
public:
  Peao(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Peao() {}

  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

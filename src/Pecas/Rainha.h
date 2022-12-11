#pragma once

#include "../Peca.h"

class Rainha : public Peca
{
public:
  Rainha(Cor cor, Position pos);
  virtual ~Rainha() {}

  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

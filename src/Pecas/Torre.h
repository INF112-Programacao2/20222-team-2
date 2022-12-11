#pragma once

#include "../Peca.h"

class Torre : public Peca
{
public:
  Torre(Cor cor, Position pos);
  virtual ~Torre() {}

  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

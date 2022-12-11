#pragma once

#include "../Peca.h"
#include "../Tabuleiro.h"

class Rei : public Peca
{
public:
  Rei(Cor cor, Position pos);
  virtual ~Rei() {}

  bool roque(Peca* tabuleiro[8][8]);
  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

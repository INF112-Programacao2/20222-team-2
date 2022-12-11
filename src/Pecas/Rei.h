#pragma once

#include "../Peca.h"
#include "../Tabuleiro.h"

class Rei : public Peca
{
public:
  Rei(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Rei() {}

  virtual std::vector<Movimento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

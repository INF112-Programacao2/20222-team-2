#pragma once

#include "../Peca.h"

class Torre : public Peca
{
public:
  Torre(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Torre() {}

  virtual std::vector<Movi mento> gerarMovimentos(Peca* tabuleiro[8][8]) const override;
};

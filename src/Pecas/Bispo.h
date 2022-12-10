#pragma once

#include "Peca.h"

class Bispo : public Peca
{
public:
  Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Bispo() {}

  virtual bool validarMovimento(Position pos) const override;
  virtual std::vector<Movimento> gerarMovimentos(const Tabuleiro& t) const override;
};

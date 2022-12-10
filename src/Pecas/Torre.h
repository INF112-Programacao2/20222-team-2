#pragma once

#include "Peca.h"

class Torre : public Peca
{
public:
  Torre(Cor cor, Position pos, ALLEGRO_BITMAP* sprite);
  virtual ~Torre() {}

  virtual bool validarMovimento(Position pos) const override;
  virtual std::vector<Movimento> gerarMovimentos(const Tabuleiro& t) const override;
};

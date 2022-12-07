#pragma once

#include "Peca.h"

class Cavalo : public Peca {
public:
  Cavalo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo);
  ~Cavalo() {}

  void validarMovimento(Position pos);
};

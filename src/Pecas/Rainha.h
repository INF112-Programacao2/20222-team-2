#pragma once

#include "Peca.h"

class Rainha : public Peca {
public:
  Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo);
  ~Rainha() {}

  bool validarMovimento(Position pos);
};

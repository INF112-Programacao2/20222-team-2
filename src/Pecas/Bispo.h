#pragma once

#include "Peca.h"

class Bispo : public Peca {
public:
  Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo);
  ~Bispo() {}

  void validarMovimento(Position pos);
};


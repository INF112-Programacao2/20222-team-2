#pragma once

#include "Peca.h"

class Rei : public Peca {
public:
  Rei(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo);
  ~Rei() {}

  void validarMovimento(Position pos);
};

#pragma once

#include "Peca.h"

class Torre : public Peca {
public:
  Torre(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo);
  ~Torre() {}
};

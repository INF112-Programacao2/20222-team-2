#include "Pecas/Torre.h"
#include <string>

Torre::Torre(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo)
  : Peca(cor, pos, sprite, tipo) {}

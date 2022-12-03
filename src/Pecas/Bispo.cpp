#include "Pecas/Bispo.h"
#include <string>

Bispo::Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo)
  : Peca(cor, pos, sprite, tipo) {}

#include "Pecas/Cavalo.h"
#include <string>

Cavalo::Cavalo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo)
  : Peca(cor, pos, sprite, tipo) {}

#include "Pecas/Peao.h"
#include <string>

Peao::Peao(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo)
  : Peca(cor, pos, sprite, tipo) {}

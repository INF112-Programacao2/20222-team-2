#include "Peca.h"
#include <string>
#include "constants.h"

Peca::Peca(Cor cor, Position pos, ALLEGRO_BITMAP *sprite, std::string tipo)
    : _cor(cor), _pos(pos), _sprite(sprite), _tipo(tipo) {}

void Peca::onRender() {
  al_draw_bitmap(_sprite,
                 (float)_pos.get_x() * BOARD_STEP,
                 (float)_pos.get_y() * BOARD_STEP, 0);
}

std::string Peca::getTipo() {
  return _tipo;
}

Cor Peca::getCor() {
  return _cor;
}

Position Peca::setpos(Position pos) {
  _pos = pos;
  return _pos;
}
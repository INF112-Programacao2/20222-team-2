#include "Peca.h"

#include "constants.h"

Peca::Peca(Cor cor, Position pos, ALLEGRO_BITMAP *sprite)
  : _cor(cor), _pos(pos), _sprite(sprite) {}

void Peca::onRender() {
  al_draw_bitmap(_sprite,
                 (float)_pos.get_x() * BOARD_STEP,
                 (float)_pos.get_y() * BOARD_STEP, 0);
}

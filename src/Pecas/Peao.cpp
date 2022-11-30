#include "Pecas/Peao.h"

Peao::Peao(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite) {}

Position Peao::movepeca(){
   if(ALLEGRO_EVENT_KEY_DOWN && event.mouse.x == _pos.get_x() && event.mouse.y == _pos.get_y()){
       
   }
}
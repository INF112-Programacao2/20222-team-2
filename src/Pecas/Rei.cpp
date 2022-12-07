#include "Rei.h"
#include <string>

Rei::Rei(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo)
  : Peca(cor, pos, sprite, tipo) {}

void Rei::validarMovimento(Position pos) {
     if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7) {
    throw "Movimento inválido";

  } else {
    //Movimentação do Rei
    if(pos.get_x() == _pos.get_x() + 1 && pos.get_y() == _pos.get_y() + 1)
    _pos = pos;
  }


}
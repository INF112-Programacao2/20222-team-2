#pragma once

#include "common.h"

#include "GameObject.h"
#include "Position.h"
#include <allegro5/allegro.h>
#include <string>


class Peca : public GameObject
{
protected:
  Cor _cor;
  Position _pos;
  ALLEGRO_BITMAP* _sprite;
  int turno = 1;

  Peca(Cor cor, Position pos, ALLEGRO_BITMAP* _sprite);
  ~Peca() {}

public:
  virtual void onRender() const override;
  Position movepeca(float x, float y); // New
  std::string getTipo();
  Cor getCor();
  Position setpos(Position pos);
  Position getPos();
  int getTurno();
  void setTurno(int turno);
  void trocarTurno();
  virtual bool validarMovimento(Position pos);
};

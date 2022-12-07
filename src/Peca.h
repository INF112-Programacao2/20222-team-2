#pragma once

#include "GameObject.h"
#include "Position.h"
#include <string>
#include <allegro5/allegro.h>

enum class Cor {
  PRETO,
  BRANCO
};

class Peca : public GameObject {
protected:
  Cor _cor;
  Position _pos;
  ALLEGRO_BITMAP* _sprite;
  std::string _tipo;
  int turno = 1;

  Peca(Cor cor, Position pos, ALLEGRO_BITMAP* _sprite, std::string tipo);
  ~Peca() {}

public:
  virtual void onRender();
  Position movepeca(float x, float y); //New
  std::string getTipo();
  Cor getCor();
  Position setpos(Position pos);
  int getTurno();
  void setTurno(int turno);
  void trocarTurno();
  virtual void validarMovimento(Position pos);
};

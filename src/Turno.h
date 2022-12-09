#include "Game.h"
#include "Peca.h"
#include "Tabuleiro.h"
#include <allegro5/allegro.h>
#include <iostream>

class Turno
{

private:
  int _turno;
  int _turno_atual;

public:
  Turno();
  ~Turno();
  void setTurnoAtual(int turno_atual);
  int getTurnoAtual();
  void setTurno(int _turno);
  int getTurno();
  void trocarTurno();
};

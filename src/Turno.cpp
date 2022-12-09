#include "Turno.h"
#include <allegro5/allegro.h>
#include <iostream>

Turno::Turno()
{
  _turno = 1;
  _turno_atual = 1;
}

Turno::~Turno() {}

void
Turno::setTurnoAtual(int turno_atual)
{
  _turno_atual = turno_atual;
}

int
Turno::getTurnoAtual()
{
  return _turno_atual;
}

void
Turno::setTurno(int _turno)
{
  _turno = _turno;
}

int
Turno::getTurno()
{
  return _turno;
}

void
Turno::trocarTurno()
{
  if (_turno_atual == 1)
  {
    _turno_atual = 2;
  }
  else
  {
    _turno_atual = 1;
  }
}

#include <iostream> 
#include <allegro5/allegro.h>
#include "Tabuleiro.h"
#include "Game.h"
#include "Peca.h"

class Turno : public GameObject{

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

#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

#include "Bispo.h"
#include "Cavalo.h"
#include "GameObject.h"
#include "Peao.h"
#include "Peca.h"
#include "Rainha.h"
#include "Rei.h"
#include "Torre.h"
// #include "Turno.h"

class Tabuleiro : public GameObject
{
private:
  Peca* _tabuleiro[8][8];
  Peca* _pecaSelecionada;
  void _debugarPeca(Peca* p);
  void _moverPeca(int destX, int destY);

public:
  Tabuleiro();
  ~Tabuleiro() {}

  Position _screenToBoard(const ALLEGRO_EVENT& e) const;
  unsigned int moverPeca(int x, int y, unsigned int turno);
  void inicializarJogo();
  virtual void onRender() const override;
  void onClick(const ALLEGRO_EVENT& e, unsigned int& turno);
  Peca* get_peca(int x, int y);
};
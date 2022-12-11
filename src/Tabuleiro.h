#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

#include "GameObject.h"
#include "Movimento.h"
#include "Peca.h"

class Tabuleiro : public GameObject
{
private:
  Peca* _tabuleiro[8][8];
  Peca* _pecaSelecionada;
  std::vector<std::vector<Movimento>> _movimentos;
  void _moverPeca(int destX, int destY);
  void _gerarMovimentos();
  void _debugarPeca(Peca* p);

public:
  Tabuleiro();
  ~Tabuleiro() {}

  Position _screenToBoard(const ALLEGRO_EVENT& e) const;
  static bool isInside(const Position& pos);
  unsigned int moverPeca(int destX, int destY);
  void inicializarJogo();
  virtual void onRender() const override;
  void onClick(const ALLEGRO_EVENT& e, unsigned int& turno);
};

#pragma once

#include <allegro5/allegro.h>

#include <vector>

#include "GameObject.h"
#include "Movimento.h"
#include "Position.h"
#include "Tabuleiro.h"
#include "common.h"

// forward declaration to solve circular dependency
class Tabuleiro;

class Peca : public GameObject
{
protected:
  Cor _cor;
  Position _pos;
  ALLEGRO_BITMAP* _sprite;
  unsigned int _movimentos = 0;

  Peca(Cor cor, Position pos, ALLEGRO_BITMAP* _sprite);

public:
  virtual ~Peca() {}

  virtual void onRender() const override;
  Cor getCor() const;
  Position setPos(Position pos);
  Position getPos() const;
  // TODO: tentar retornar esse vetor como referencia para evitar cópias
  virtual std::vector<Movimento> gerarMovimentos(const Tabuleiro& t) const = 0;

  virtual bool validarMovimento(Position pos) const = 0;
};

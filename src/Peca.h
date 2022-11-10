#pragma once

#include "GameObject.h"
#include "Position.h"

enum class PieceColor {
  PRETO,
  BRANCO
};

class Peca : public GameObject {
protected:
  PieceColor _cor;
  Position _pos;

  Peca(PieceColor cor, Position pos);

public:
  virtual void onRender();
};

#pragma once

#include "Position.h"
#include "common.h"

class Movimento
{
private:
  Position _origem;
  Position _destino;
  bool _isValid;

public:
  Movimento(Position origem, Position destino, bool isValid);
  ~Movimento() {}
};
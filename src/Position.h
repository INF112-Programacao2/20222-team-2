#pragma once

#include <iostream>

class Position
{
private:
  int _pos_x;
  int _pos_y;

public:
  Position(int pos_x, int pos_y);
  ~Position() {}

  int get_x() const;
  int get_y() const;
  int set_x(int pos_x);
  int set_y(int pos_y);
  // Função para mover a peça
  void movepeca(int x, int y);

  friend std::ostream& operator<<(std::ostream& os, const Position& p);
};

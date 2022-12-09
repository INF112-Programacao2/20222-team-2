#include "Tabuleiro.h"

#include <iostream>

#include "Game.h"
#include "constants.h"
#include "globals.h"

Tabuleiro::Tabuleiro()
  : _pecaSelecionada(nullptr)
{
}

void
Tabuleiro::onRender() const
{
  ALLEGRO_COLOR c = al_map_rgb(255, 255, 255);
  bool isWhiteSquare = false;

  // desenha o quadriculado do tabuleiro, utilizando offsets para não haver interseção com os
  // elementos de UI
  for (int i = OFFSET_Y; i <= BOARD_SIZE - BOARD_STEP + OFFSET_Y; i += BOARD_STEP)
  {
    isWhiteSquare = !isWhiteSquare;
    for (int j = OFFSET_X; j <= BOARD_SIZE - BOARD_STEP + OFFSET_X; j += BOARD_STEP)
    {
      if (isWhiteSquare)
      {
        c = al_map_rgb(0, 80, 180);
        isWhiteSquare = !isWhiteSquare;
      }
      else
      {
        c = al_map_rgb(200, 200, 220);
        isWhiteSquare = !isWhiteSquare;
      }
      al_draw_filled_rectangle(j, i, j + BOARD_STEP, i + BOARD_STEP, c);
    }
  }

  // desenha as peças
  for (int x = 0; x < 8; ++x)
  {
    for (int y = 0; y < 8; ++y)
    {
      if (_tabuleiro[x][y])
      {
        _tabuleiro[x][y]->onRender();
      }
    }
  }
}

void
Tabuleiro::inicializarJogo()
{
  // zerar todas as posições do tabuleiro
  for (int x = 0; x < 8; ++x)
  {
    for (int y = 0; y < 8; ++y)
    {
      _tabuleiro[x][y] = nullptr;
    }
  }

  // colocar as peças como num jogo padrão de xadrez
  // pretas, fileira de trás
  _tabuleiro[1][0] = new Cavalo(Cor::PRETO, { 1, 0 }, _knightBlackBmp);
  _tabuleiro[2][0] = new Bispo(Cor::PRETO, { 2, 0 }, _bishopBlackBmp);
  _tabuleiro[3][0] = new Rainha(Cor::PRETO, { 3, 0 }, _queenBlackBmp);
  _tabuleiro[4][0] = new Rei(Cor::PRETO, { 4, 0 }, _kingBlackBmp);
  _tabuleiro[5][0] = new Bispo(Cor::PRETO, { 5, 0 }, _bishopBlackBmp);
  _tabuleiro[6][0] = new Cavalo(Cor::PRETO, { 6, 0 }, _knightBlackBmp);
  _tabuleiro[7][0] = new Torre(Cor::PRETO, { 7, 0 }, _rookBlackBmp);
  _tabuleiro[0][0] = new Torre(Cor::PRETO, { 0, 0 }, _rookBlackBmp);
  // pretas, peões
  for (int x = 0; x < 8; ++x)
  {
    _tabuleiro[x][1] = new Peao(Cor::PRETO, { x, 1 }, _pawnBlackBmp);
  }

  // brancas, fileira de trás
  _tabuleiro[0][7] = new Torre(Cor::BRANCO, { 0, 7 }, _rookWhiteBmp);
  _tabuleiro[1][7] = new Cavalo(Cor::BRANCO, { 1, 7 }, _knightWhiteBmp);
  _tabuleiro[2][7] = new Bispo(Cor::BRANCO, { 2, 7 }, _bishopWhiteBmp);
  _tabuleiro[3][7] = new Rainha(Cor::BRANCO, { 3, 7 }, _queenWhiteBmp);
  _tabuleiro[4][7] = new Rei(Cor::BRANCO, { 4, 7 }, _kingWhiteBmp);
  _tabuleiro[5][7] = new Bispo(Cor::BRANCO, { 5, 7 }, _bishopWhiteBmp);
  _tabuleiro[6][7] = new Cavalo(Cor::BRANCO, { 6, 7 }, _knightWhiteBmp);
  _tabuleiro[7][7] = new Torre(Cor::BRANCO, { 7, 7 }, _rookWhiteBmp);
  // brancas, peões
  for (int x = 0; x < 8; ++x)
  {
    _tabuleiro[x][6] = new Peao(Cor::BRANCO, { x, 6 }, _pawnWhiteBmp);
  }
}

void
Tabuleiro::onClick(const ALLEGRO_EVENT& e)
{
  if (_pecaSelecionada != nullptr)
  {
    Position pos = _screenToBoard(e);
    Position selPos = _pecaSelecionada->getPos();
    int x1 = selPos.get_x();
    int y1 = selPos.get_y();
    moverPeca(x1, y1, pos.get_x(), pos.get_y());
    _pecaSelecionada = nullptr;
  }
  else
  {
    Position pos = _screenToBoard(e);
    if (_tabuleiro[pos.get_x()][pos.get_y()] != nullptr)
    {
      _pecaSelecionada = _tabuleiro[pos.get_x()][pos.get_y()];
      std::cout << (_pecaSelecionada->getCor() == Cor::BRANCO ? "BRANCO" : "PRETO") << std::endl;
    }
  }
}

Position
Tabuleiro::_screenToBoard(const ALLEGRO_EVENT& e) const
{
  Position p = { ((int)e.mouse.x - OFFSET_X) / BOARD_STEP,
                 ((int)e.mouse.y - OFFSET_Y) / BOARD_STEP };
  std::cout << p << std::endl;
  return p;
}

// x e y são as coordenadas de origem da peça e x2 e y2 são as coordenadas de destino
void
Tabuleiro::moverPeca(int origem_X, int origem_Y, int destino_X, int destino_Y)
{
  // x1 e y1 são as coordenadas de destino da peça
  int auxiliar_X = destino_X;
  int auxiliar_Y = destino_Y;

  //Se a origem for nula
  if (_tabuleiro[origem_X][origem_Y] == nullptr) {
    return;
  }

  //Se a peça for preta e o movimento for válido conforme a peça
  if (_tabuleiro[origem_X][origem_Y]->getCor() == Cor::PRETO && 
      _tabuleiro[origem_X][origem_Y]->validarMovimento({ auxiliar_X, auxiliar_Y }))
  {
    //Se o destino for nulo apenas move
    if (_tabuleiro[destino_X][destino_Y] == nullptr)
    {
      _tabuleiro[destino_X][destino_Y] = _tabuleiro[origem_X][origem_Y];
      _tabuleiro[origem_X][origem_Y] = nullptr;
      _tabuleiro[destino_X][destino_Y]->setpos({ auxiliar_X, auxiliar_Y });
    }
    //Se o destino for diferente de nulo e a cor for branca, são peças de times diferentes então pode mover e comer
    else if (_tabuleiro[destino_X][destino_Y] != nullptr && 
             _tabuleiro[destino_X][destino_Y]->getCor() == Cor::BRANCO)
    {
      _tabuleiro[destino_X][destino_Y] = _tabuleiro[origem_X][origem_Y];
      _tabuleiro[origem_X][origem_Y] = nullptr;
      _tabuleiro[destino_X][destino_Y]->setpos({ auxiliar_X, auxiliar_Y });
    }
    //Se o destino for diferente de nulo e a cor for preta, são peças da mesma cor então não pode mover
    else if (_tabuleiro[destino_X][destino_Y] != nullptr &&
             _tabuleiro[destino_X][destino_Y]->getCor() == Cor::PRETO)
    {
      return;
    }
  }

  //Se a peça for branca
  else if (_tabuleiro[origem_X][origem_Y]->getCor() == Cor::BRANCO && 
           _tabuleiro[origem_X][origem_Y]->validarMovimento({ auxiliar_X, auxiliar_Y }))
  {
    //Se o destino for nulo
    if (_tabuleiro[destino_X][destino_Y] == nullptr)
    {
      _tabuleiro[destino_X][destino_Y] = _tabuleiro[origem_X][origem_Y];
      _tabuleiro[origem_X][origem_Y] = nullptr;
      _tabuleiro[destino_X][destino_Y]->setpos({ auxiliar_X, auxiliar_Y });
    }
    //Se o destino for diferente de nulo e a cor for preta, são peças de times diferentes então pode mover e comer
    else if (_tabuleiro[destino_X][destino_Y] != nullptr &&
             _tabuleiro[destino_X][destino_Y]->getCor() == Cor::PRETO)
    {
      _tabuleiro[destino_X][destino_Y] = _tabuleiro[origem_X][origem_Y];
      _tabuleiro[origem_X][origem_Y] = nullptr;
      _tabuleiro[destino_X][destino_Y]->setpos({ auxiliar_X, auxiliar_Y });
    }
    //Se o destino for diferente de nulo e a cor for branca, são peças da mesma cor então não pode mover
    else if (_tabuleiro[destino_X][destino_Y] != nullptr &&
             _tabuleiro[destino_X][destino_Y]->getCor() == Cor::BRANCO)
    {
      return;
    }   
  }
}
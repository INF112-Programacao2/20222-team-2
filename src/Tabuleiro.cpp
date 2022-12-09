#include "Tabuleiro.h"
#include "constants.h"
#include "Game.h"
#include "globals.h"
#include <iostream>
// #include "Turno.h"

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
    _tabuleiro[x][1] = new Peao(Cor::PRETO, { (float)x, 1 }, _pawnBlackBmp);
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
    _tabuleiro[x][6] = new Peao(Cor::BRANCO, { (float)x, 6 }, _pawnWhiteBmp);
  }
}

// Função para mover peças no tabuleiro utilizando as coordenadas x e y
void
Tabuleiro::moverPeca(int x, int y, int x2, int y2)
{
  float x1 = x2; // Conversão de int para float
  float y1 = y2; // Conversão de int para float
  // int turno = 1; // Variável para verificar o turno do jogador troca o valor
  // toda vez que o jogador faz um movimento

  if (_tabuleiro[x][y] != nullptr && _tabuleiro[x][y]->getCor() == Cor::PRETO &&
      _tabuleiro[x][y]->validarMovimento({ x1, y1 }) == true)
  {
    if (_tabuleiro[x2][y2] == nullptr)
    {
      _tabuleiro[x2][y2] = _tabuleiro[x][y];
      _tabuleiro[x][y] = nullptr;
      _tabuleiro[x2][y2]->setpos({ x1, y1 });
    }
    else if (_tabuleiro[x2][y2] != nullptr &&
             _tabuleiro[x2][y2]->getCor() == Cor::BRANCO) // Se quise
    {
      _tabuleiro[x2][y2] = _tabuleiro[x][y];
      _tabuleiro[x][y] = nullptr;
      _tabuleiro[x2][y2]->setpos({ x1, y1 });
    }
  }

  else if (_tabuleiro[x][y] != nullptr && _tabuleiro[x][y]->getCor() == Cor::BRANCO &&
           _tabuleiro[x][y]->validarMovimento({ x1, y1 }) == true)
  {
    if (_tabuleiro[x2][y2] == nullptr)
    {
      _tabuleiro[x2][y2] = _tabuleiro[x][y];
      _tabuleiro[x][y] = nullptr;
      _tabuleiro[x2][y2]->setpos({ x1, y1 });
    }
    else if (_tabuleiro[x2][y2] != nullptr &&
             _tabuleiro[x2][y2]->getCor() == Cor::PRETO) // Se quise
    {
      _tabuleiro[x2][y2] = _tabuleiro[x][y];
      _tabuleiro[x][y] = nullptr;
      _tabuleiro[x2][y2]->setpos({ x1, y1 });
      // std::cout << "Pontos do time preto: " << contplacarpretas << std::endl;
    }
  }
}

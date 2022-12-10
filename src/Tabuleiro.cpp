#include "Tabuleiro.h"

#include <iostream>
#include <memory>

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
  _tabuleiro[0][0] = new Torre(Cor::PRETO, { 0, 0 }, _rookBlackBmp);
  _tabuleiro[1][0] = new Cavalo(Cor::PRETO, { 1, 0 }, _knightBlackBmp);
  _tabuleiro[2][0] = new Bispo(Cor::PRETO, { 2, 0 }, _bishopBlackBmp);
  _tabuleiro[3][0] = new Rainha(Cor::PRETO, { 3, 0 }, _queenBlackBmp);
  _tabuleiro[4][0] = new Rei(Cor::PRETO, { 4, 0 }, _kingBlackBmp);
  _tabuleiro[5][0] = new Bispo(Cor::PRETO, { 5, 0 }, _bishopBlackBmp);
  _tabuleiro[6][0] = new Cavalo(Cor::PRETO, { 6, 0 }, _knightBlackBmp);
  _tabuleiro[7][0] = new Torre(Cor::PRETO, { 7, 0 }, _rookBlackBmp);
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
Tabuleiro::onClick(const ALLEGRO_EVENT& e, unsigned int& turno)
{
  if (_pecaSelecionada != nullptr)
  {
    Position pos = _screenToBoard(e);

    Peca* dest = _tabuleiro[pos.get_x()][pos.get_y()];
    if (dest && (dest->getCor() == (turno % 2 ? Cor::BRANCO : Cor::PRETO)))
    {
      _pecaSelecionada = dest;
      return;
    }
    if (moverPeca(pos.get_x(), pos.get_y(), turno))
    {
      ++turno;
      _pecaSelecionada = nullptr;
    }
  }
  else
  {
    Position pos = _screenToBoard(e);
    Peca* sel = _tabuleiro[pos.get_x()][pos.get_y()];
    if (sel && (sel->getCor() == (turno % 2 ? Cor::BRANCO : Cor::PRETO)))
    {
      _pecaSelecionada = _tabuleiro[pos.get_x()][pos.get_y()];
    }
  }
}

Position
Tabuleiro::_screenToBoard(const ALLEGRO_EVENT& e) const
{
  Position p = { ((int)e.mouse.x - OFFSET_X) / BOARD_STEP,
                 ((int)e.mouse.y - OFFSET_Y) / BOARD_STEP };
  return p;
}

// Move a peça selecionada para a posição x, y (coluna / linha), começando na (0, 0)
// O turno começa em 1 (branco), então para saber se o jogador atual é o preto ou o branco, basta
// saber se o turno é par ou ímpar.
//
// Retorna 1 se o movimento ocorrer, 0 se o movimento for inválido.
unsigned int
Tabuleiro::moverPeca(int destX, int destY, unsigned int turno)
{
  Peca* pecaDestino = _tabuleiro[destX][destY];

  if (!(_pecaSelecionada->validarMovimento({ destX, destY })))
  {
    return 0;
  }
  
  if (pecaDestino)
  {
    if (pecaDestino->getCor() != _pecaSelecionada->getCor())
    {
      _moverPeca(destX, destY);
      delete pecaDestino;
      return 1;
    }
    else
    {
      // clique em peças de mesma cor, selecionar a outra peça
      _pecaSelecionada = pecaDestino;
      return 0;
    }
  }
  else
  {
    _moverPeca(destX, destY);
    return 1;
  }
  return 0;
}

// Função auxiliar
// Move a peca selecionada para a posição de destino, independente do que estiver lá.
// NOTA: essa função NÃO deleta a peça de destino, isso deve ser feito na função que está chamando
// esta.
void
Tabuleiro::_moverPeca(int destX, int destY)
{
  _tabuleiro[destX][destY] = _pecaSelecionada;
  Position posOrigem = _pecaSelecionada->getPos();
  _tabuleiro[posOrigem.get_x()][posOrigem.get_y()] = nullptr;
  _pecaSelecionada->setPos({ destX, destY });
}
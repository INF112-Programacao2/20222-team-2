#include "Tabuleiro.h"

#include <iostream>

#include "Pecas/Bispo.h"
#include "Pecas/Cavalo.h"
#include "Pecas/Peao.h"
#include "Pecas/Rainha.h"
#include "Pecas/Rei.h"
#include "Pecas/Torre.h"
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

// Limpa o tabuleiro e coloca as peças como num jogo padrão de xadrez, alocando novas peças
void
Tabuleiro::inicializarJogo() // TODO: trocar o nome para algo que faça mais sentido
{
  // zerar todas as posições do tabuleiro
  // TODO: copiar esse loop para o construtor, e verificar se existem peças nesse loop. Se
  // existirem, deletar antes de setar para nullptr
  for (int x = 0; x < 8; ++x)
  {
    for (int y = 0; y < 8; ++y)
    {
      _tabuleiro[x][y] = nullptr;
    }
  }

  // colocar as peças como num jogo padrão de xadrez
  // pretas, fileira de trás
  _tabuleiro[0][0] = new Torre(Cor::PRETO, { 0, 0 });
  _tabuleiro[1][0] = new Cavalo(Cor::PRETO, { 1, 0 });
  _tabuleiro[2][0] = new Bispo(Cor::PRETO, { 2, 0 });
  _tabuleiro[3][0] = new Rainha(Cor::PRETO, { 3, 0 });
  _tabuleiro[4][0] = new Rei(Cor::PRETO, { 4, 0 });
  _tabuleiro[5][0] = new Bispo(Cor::PRETO, { 5, 0 });
  _tabuleiro[6][0] = new Cavalo(Cor::PRETO, { 6, 0 });
  _tabuleiro[7][0] = new Torre(Cor::PRETO, { 7, 0 });
  // pretas, peões
  for (int x = 0; x < 8; ++x)
  {
    _tabuleiro[x][1] = new Peao(Cor::PRETO, { x, 1 });
  }

  // brancas, fileira de trás
  _tabuleiro[0][7] = new Torre(Cor::BRANCO, { 0, 7 });
  _tabuleiro[1][7] = new Cavalo(Cor::BRANCO, { 1, 7 });
  _tabuleiro[2][7] = new Bispo(Cor::BRANCO, { 2, 7 });
  _tabuleiro[3][7] = new Rainha(Cor::BRANCO, { 3, 7 });
  _tabuleiro[4][7] = new Rei(Cor::BRANCO, { 4, 7 });
  _tabuleiro[5][7] = new Bispo(Cor::BRANCO, { 5, 7 });
  _tabuleiro[6][7] = new Cavalo(Cor::BRANCO, { 6, 7 });
  _tabuleiro[7][7] = new Torre(Cor::BRANCO, { 7, 7 });
  // brancas, peões
  for (int x = 0; x < 8; ++x)
  {
    _tabuleiro[x][6] = new Peao(Cor::BRANCO, { x, 6 });
  }

  // Para testes apenas
  // Bispo, Torre ou Rainha
  // _tabuleiro[4][4] = new Rainha(Cor::BRANCO, { 4, 4 });
  // _tabuleiro[4][1] = new Cavalo(Cor::BRANCO, { 4, 1 });
  // _tabuleiro[4][6] = new Cavalo(Cor::PRETO, { 4, 6 });
  // _tabuleiro[6][4] = new Torre(Cor::BRANCO, { 6, 4 });
  // _tabuleiro[2][4] = new Torre(Cor::BRANCO, { 2, 4 });
  // _tabuleiro[6][6] = new Bispo(Cor::BRANCO, { 6, 6 });
  // _tabuleiro[5][3] = new Bispo(Cor::PRETO, { 5, 3 });
  // _tabuleiro[1][7] = new Rei(Cor::PRETO, { 1, 7 });
  // _tabuleiro[0][0] = new Rei(Cor::BRANCO, { 0, 0 });

  // Cavalo
  // _tabuleiro[4][4] = new Cavalo(Cor::BRANCO, { 4, 4 });
  // _tabuleiro[3][2] = new Rei(Cor::PRETO, { 3, 2 });
  // _tabuleiro[5][2] = new Cavalo(Cor::PRETO, { 5, 2 });
  // _tabuleiro[2][3] = new Cavalo(Cor::PRETO, { 2, 3 });
  // _tabuleiro[2][5] = new Cavalo(Cor::PRETO, { 2, 5 });
  // _tabuleiro[3][6] = new Cavalo(Cor::PRETO, { 3, 6 });
  // _tabuleiro[5][6] = new Cavalo(Cor::PRETO, { 5, 6 });
  // _tabuleiro[6][5] = new Cavalo(Cor::PRETO, { 6, 5 });
  // _tabuleiro[6][3] = new Cavalo(Cor::PRETO, { 6, 3 });

  // Rei
  // _tabuleiro[0][0] = new Rei(Cor::BRANCO, { 0, 0 });
  // _tabuleiro[7][0] = new Rei(Cor::BRANCO, { 7, 0 });
  // _tabuleiro[0][7] = new Rei(Cor::BRANCO, { 0, 7 });
  // _tabuleiro[7][7] = new Rei(Cor::BRANCO, { 7, 7 });
  // _tabuleiro[5][5] = new Rei(Cor::PRETO, { 5, 5 });
  // _tabuleiro[5][4] = new Cavalo(Cor::BRANCO, { 5, 4 });
  // _tabuleiro[5][6] = new Cavalo(Cor::PRETO, { 5, 6 });

  _gerarMovimentos();
  // DEBUG: imprimir todos os movimentos
  for (int i = 0; i < _movimentos.size(); ++i)
  {
    std::cout << i << std::endl;
    if (_movimentos[i].size() > 0)
    {
      _debugarPeca(
        _tabuleiro[_movimentos[i][0].get_origem().get_x()][_movimentos[i][0].get_origem().get_y()]);
    }
    for (Movimento& movimento : _movimentos[i])
    {
      std::cout << movimento << std::endl;
    }
  }
}

// Gerencia o que ocorre quando o jogador clicka na tela
void
Tabuleiro::onClick(const ALLEGRO_EVENT& e, unsigned int& turno)
{
  Position pos = _screenToBoard(e);
  if (!isInside(pos))
  {
    return;
  }

  if (_pecaSelecionada != nullptr)
  {
    Peca* dest = _tabuleiro[pos.get_x()][pos.get_y()];
    if (dest && (dest->getCor() == (turno % 2 ? Cor::BRANCO : Cor::PRETO)))
    {
      _pecaSelecionada = dest;
      return;
    }
    if (moverPeca(pos.get_x(), pos.get_y()))
    {
      ++turno;
      _pecaSelecionada = nullptr;
      _movimentos.clear();
      _gerarMovimentos();
      // DEBUG: imprimir todos os movimentos
      for (int i = 0; i < _movimentos.size(); ++i)
      {
        std::cout << i << std::endl;
        if (_movimentos[i].size() > 0)
        {
          _debugarPeca(_tabuleiro[_movimentos[i][0].get_origem().get_x()]
                                 [_movimentos[i][0].get_origem().get_y()]);
        }
        for (Movimento& movimento : _movimentos[i])
        {
          std::cout << movimento << std::endl;
        }
      }
    }
  }
  else
  {
    Peca* sel = _tabuleiro[pos.get_x()][pos.get_y()];
    if (sel && (sel->getCor() == (turno % 2 ? Cor::BRANCO : Cor::PRETO)))
    {
      _pecaSelecionada = _tabuleiro[pos.get_x()][pos.get_y()];
    }
  }
}

// Converte uma posição do mouse na tela para uma posição no tabuleiro
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
//
// Essa função retorna um unsigned int para ser somado (incrementar) ao número de turnos, por isso
// não pode ser bool
unsigned int
Tabuleiro::moverPeca(int destX, int destY)
{
  Peca* pecaDestino = _tabuleiro[destX][destY];
  std::vector<Movimento> movPecaSelecionada;

  if (pecaDestino && pecaDestino->getCor() == _pecaSelecionada->getCor())
  {
    // clique em peças de mesma cor, selecionar a outra peça
    _pecaSelecionada = pecaDestino;
    return 0;
  }

  // procura os movimentos da peça selecionada na lista de movimentos
  for (int i = 0; i < _movimentos.size(); ++i)
  {
    if (_movimentos[i].size() > 0 &&
        _movimentos[i][0].get_origem().get_x() == _pecaSelecionada->getPos().get_x() &&
        _movimentos[i][0].get_origem().get_y() == _pecaSelecionada->getPos().get_y())
    {
      movPecaSelecionada = _movimentos[i];
      break;
    }
  }

  // verifica se há um movimento com o destino selecionado
  for (const Movimento& movimento : movPecaSelecionada)
  {
    Position posDestino = movimento.get_destino();
    if (destX == posDestino.get_x() && destY == posDestino.get_y())
    {
      _moverPeca(destX, destY);
      if (movimento.get_captura())
      {
        delete pecaDestino;
      }
      return 1;
    }
  }

  return 0;
}

// Gera todos os movimentos possíveis para todas as peças do tabuleiro
void
Tabuleiro::_gerarMovimentos()
{
  for (int x = 0; x < 8; ++x)
  {
    for (int y = 0; y < 8; ++y)
    {
      if (_tabuleiro[x][y])
      {
        _movimentos.push_back(_tabuleiro[x][y]->gerarMovimentos(_tabuleiro));
      }
    }
  }
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
  _pecaSelecionada->incrementarMovimentos();
}

// Função auxiliar
// Verifica se uma posição está ou não dentro do tabuleiro
bool
Tabuleiro::isInside(const Position& pos)
{
  int x = pos.get_x();
  int y = pos.get_y();
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void
Tabuleiro::_debugarPeca(Peca* p)
{
  if (!p)
  {
    std::cout << "Vazio" << '\n' << std::endl;
    return;
  }
  Torre* t1 = dynamic_cast<Torre*>(p);
  Cavalo* t2 = dynamic_cast<Cavalo*>(p);
  Bispo* t3 = dynamic_cast<Bispo*>(p);
  Rainha* t4 = dynamic_cast<Rainha*>(p);
  Rei* t5 = dynamic_cast<Rei*>(p);
  Peao* t6 = dynamic_cast<Peao*>(p);
  if (t1)
  {
    std::cout << "TORRE";
  }
  else if (t2)
  {
    std::cout << "CAVALO";
  }
  else if (t3)
  {
    std::cout << "BISPO";
  }
  else if (t4)
  {
    std::cout << "RAINHA";
  }
  else if (t5)
  {
    std::cout << "REI";
  }
  else if (t6)
  {
    std::cout << "PEAO";
  }
  std::cout << ' ' << (p->getCor() == Cor::BRANCO ? "BRANCO" : "PRETO");
  std::cout << ' ' << p->getPos() << std::endl;
}
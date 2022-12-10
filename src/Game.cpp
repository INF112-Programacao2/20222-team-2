#include "Game.h"

#include <allegro5/allegro_image.h>

#include <imgui.h>
#include <imgui_impl_allegro5.h>

#include <iostream>

#include "Partida.h"

#include "constants.h"
#include "errorHandling.h"
#include "globals.h"

//Construtor da classe Game
Game::Game()
{
  // inicialização do allegro e criação da janela
  EC_CALL(al_init()); // inicializa o allegro
  EC_CALL(al_install_keyboard()); // inicializa o teclado
  EC_CALL(al_install_mouse()); // inicializa o mouse
  EC_CALL(_display = al_create_display(SCREEN_W, SCREEN_H)); // cria a janela
  EC_CALL(_font = al_create_builtin_font()); // cria a fonte padrão
  EC_CALL(al_init_image_addon()); // inicializa o addon de imagens
  EC_CALL(al_init_primitives_addon()); // inicializa o addon de primitivas

  // inicializa as imagens das peças
  // pretas
  EC_CALL(_kingBlackBmp = al_load_bitmap("./assets/Chess_kdt45.png"));
  EC_CALL(_queenBlackBmp = al_load_bitmap("./assets/Chess_qdt45.png"));
  EC_CALL(_bishopBlackBmp = al_load_bitmap("./assets/Chess_bdt45.png"));
  EC_CALL(_knightBlackBmp = al_load_bitmap("./assets/Chess_ndt45.png"));
  EC_CALL(_rookBlackBmp = al_load_bitmap("./assets/Chess_rdt45.png"));
  EC_CALL(_pawnBlackBmp = al_load_bitmap("./assets/Chess_pdt45.png"));
  // brancas
  EC_CALL(_kingWhiteBmp = al_load_bitmap("./assets/Chess_klt45.png"));
  EC_CALL(_queenWhiteBmp = al_load_bitmap("./assets/Chess_qlt45.png"));
  EC_CALL(_bishopWhiteBmp = al_load_bitmap("./assets/Chess_blt45.png"));
  EC_CALL(_knightWhiteBmp = al_load_bitmap("./assets/Chess_nlt45.png"));
  EC_CALL(_rookWhiteBmp = al_load_bitmap("./assets/Chess_rlt45.png"));
  EC_CALL(_pawnWhiteBmp = al_load_bitmap("./assets/Chess_plt45.png"));

  // inicializa o timer para 30 fps
  EC_CALL(_timer = al_create_timer(1.0 / 30.0));

  // inicializa a fila de eventos e registra os eventos que serão capturados
  EC_CALL(_queue = al_create_event_queue()); // cria a fila de eventos
  al_register_event_source(_queue, al_get_keyboard_event_source()); // registra o teclado
  al_register_event_source(_queue, al_get_display_event_source(_display)); // registra a janela
  al_register_event_source(_queue, al_get_mouse_event_source()); // registra o mouse
  al_register_event_source(_queue, al_get_timer_event_source(_timer)); // registra o timer

  // inicializa o tabuleiro
  al_set_target_bitmap(al_get_backbuffer(_display));

  // inicializa o sistema de textos do allegro e cria a fonte padrão do jogo (Inter) com tamanho 24 pixels
  IMGUI_CHECKVERSION(); // verifica a versão do ImGui
  ImGui::CreateContext(); // cria o contexto da Dear ImGui
  ImGuiIO& io = ImGui::GetIO(); 
  io.Fonts->AddFontFromFileTTF("assets/Inter-Regular.ttf", 24); // carrega a fonte padrão do jogo
  ImGui::StyleColorsLight(); // carrega o estilo padrão do ImGui
  ImGui_ImplAllegro5_Init(_display); // inicializa o ImGui para o Allegro
}

// Destrutor da classe Game
Game::~Game()
{
  // desaloca o contexto do ImGui e desliga o ImGui do Allegro
  ImGui_ImplAllegro5_Shutdown();
  ImGui::DestroyContext(); 

  // desaloca as imagens das peças
  // pretas
  al_destroy_bitmap(_kingBlackBmp);
  al_destroy_bitmap(_queenBlackBmp);
  al_destroy_bitmap(_bishopBlackBmp);
  al_destroy_bitmap(_knightBlackBmp);
  al_destroy_bitmap(_rookBlackBmp);
  al_destroy_bitmap(_pawnBlackBmp);
  // brancas
  al_destroy_bitmap(_kingWhiteBmp);
  al_destroy_bitmap(_queenWhiteBmp);
  al_destroy_bitmap(_bishopWhiteBmp);
  al_destroy_bitmap(_knightWhiteBmp);
  al_destroy_bitmap(_rookWhiteBmp);
  al_destroy_bitmap(_pawnWhiteBmp);

  // desinicializa e destrói os sistemas da allegro
  al_shutdown_image_addon();
  al_shutdown_font_addon();
  al_shutdown_primitives_addon();
  al_destroy_timer(_timer);
  al_destroy_event_queue(_queue);
  al_destroy_font(_font);
  al_destroy_display(_display);
  al_uninstall_system();
}

void
Game::mainLoop()
{
  bool running = true; // indica se o jogo está rodando
  bool redraw = true;  // indica se a tela deve ser redesenhada
  ALLEGRO_EVENT event; // evento que será capturado

  Partida partida;
  ALLEGRO_EVENT mouseClick;
  bool clicked = false;

  // inicia o timer para o jogo rodar a 30 fps
  al_start_timer(_timer);

  // loop principal do jogo
  while (running)
  {
    al_wait_for_event(_queue, &event); // aguarda um evento

    ImGui_ImplAllegro5_ProcessEvent(&event); // processa o evento para o ImGui

    // verifica o tipo do evento
    switch (event.type)
    {
      // se o evento for um evento de teclado
      case ALLEGRO_EVENT_TIMER:
      {
        // game logic goes here.
        if (clicked)
        {
          partida.onClick(mouseClick);
          clicked = false;
        }
        redraw = true;
        break;
      }
      // se o evento for um evento de janela
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
      {
        running = false;
        break;
      }
      // se o evento for um evento de mouse
      case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
      {
        clicked = true;
        mouseClick = event;
        break;
      }
    }

    // se a tela deve ser redesenhada e não há eventos na fila
    if (redraw && al_is_event_queue_empty(_queue))
    {
      al_clear_to_color(al_map_rgb(0, 0, 0)); // limpa a tela para preto (apaga o que estava na tela)

      ImGui_ImplAllegro5_NewFrame(); // inicia o frame do ImGui
      ImGui::NewFrame(); // inicia o frame do ImGui

      partida.onRender(); // renderiza a partida

      ImGui::Render(); // renderiza o ImGui
      ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData()); // renderiza o ImGui
      al_flip_display(); // atualiza a tela

      redraw = false;
    }
  }
}

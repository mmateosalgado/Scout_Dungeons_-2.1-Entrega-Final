#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED

#include "../BASICAS/funciones_basicas.h"

///HISTORIA

void muestra_historia(int id,usuario nombre,personaje clase);
void historia_1(usuario nombre,personaje clase);
void historia_2(usuario nombre,personaje clase);
void historia_3(usuario nombre,personaje clase);
void historia_4(usuario nombre,personaje clase);
void historia_5(usuario nombre,personaje clase);
void muestra_arma_pocion_encontrada();

///GENERAL
void titulo ();
void pantalla_muerte ();
void mostrar_ganaste();

///MOSTRAR ENEMIGOS
void mostrar_enemigo(personaje enemigo);
void mostrar_enano();
void mostrar_esqueleto();
void mostrar_la_parca();
void mostrar_grifo();
void mostrar_dragon();
///???????
void mostrar_sorpresa();

///MOSTRAR JUGADOR

void mostrar_jugador(int id);
void mostrar_guerrero();
void mostrar_mago();
void mostrar_arquero();

///MOSTRAR EDIFICIOS
void mostrar_castillo();
void mostrar_templo();
void mostrar_puerta_cementerio();


///MENUS
void menu_batalla(personaje jugador,personaje enemigo,int turno);
void menu_batalla_opciones(int id);
void menuInventario();

///COMBATE

//ATAQUE
void muestra_ataque_magico_basico(personaje * atacante,int armadura);
void muestra_ataque_magico_critico(personaje * atacante);
void muestra_ataque_fisico_basico(personaje * atacante,int armadura);
void muestra_ataque_fisico_critico(personaje * atacante);
void muestra_ataque_veneno(personaje enemigo);
//DEFENSA
void muestra_defender_y_cargar_energia();
//EFECTO
void muestra_efecto_hechizo(int id);
//SUFRE
void muestra_sufre_veneno();

///INVENTARIO

void muestra_arma(arma dato_arma);
void muestra_lista_armas(personaje jugador,int tipo);
void muestra_armas_hechizos(personaje jugador);
void muestra_pocion(pocion dato_pocion);
void muestra_pociones(nodo_pocion*lista);

///IA | ENEMIGO

//ATAQUE
void muestra_ataque_fisico_critico_enemigo(personaje * atacante);
void muestra_ataque_fisico_basico_enemigo(personaje * atacante,int armadura);
void muestra_ataque_veneno_IA(personaje enemigo);
//DEFENSA
void muestra_defender_y_cargar_energia_enemigo();
//BOOST DANO
void muestra_boost_danio_enemigo(personaje enemigo);
//CURA
void muestra_cura_IA(personaje enemigo);
//SUFRE VENENO
void muestra_sufre_veneno_IA(personaje enemigo);


#endif // GRAFICOS_H_INCLUDED

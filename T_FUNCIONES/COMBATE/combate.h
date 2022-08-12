#ifndef COMBATE_H_INCLUDED
#define COMBATE_H_INCLUDED

#include "../BASICAS/funciones_basicas.h"
#include "../GRAFICOS/graficos.h"

///PRINCIPAL
void combate(personaje * jugador,personaje * enemigo,int turno);

///SECUNDARIAS

void acceso_inventario(personaje * jugador, personaje * enemigo,int turno);
void defender_y_cargar_energia(personaje * jugador);

int select_ataque(personaje * atacante, personaje * defensor);
int ataque_fisico(personaje * atacante, personaje * defensor);
int ataque_magico(personaje * atacante, personaje * defensor);


///INVENTARIO

arma busca_arma(nodo_base_inventario*lista,int id);
void cambiar_arma(personaje * jugador,int tipo,int id);
void aplicar_pocion(personaje * jugador,pocion pocion_seleccionada);

///FUNCIONES ATAQUES ESPECIALES
void aplicar_ataque_con_efecto_hechizo(personaje * atacante, personaje * defensor);
void ataque_dano_const(personaje * jugador,personaje * enemigo);///para VENENO o FUEGO
void ataque_stun(personaje * jugador , personaje * enemigo);

void aplica_stun_enemigo(personaje * jugador,personaje * enemigo,int turno,int critico);
void aplica_veneno_enemigo(personaje * enemigo);
void aplica_veneno_jugador(personaje * jugador);


///IA

void combate_IA(personaje*IA, personaje*jugador,int turno,int flag_critico);
void accion_IA(personaje*IA,personaje*jugador);


#endif // COMBATE_H_INCLUDED

#ifndef FUNCIONES_BASICAS_H_INCLUDED
#define FUNCIONES_BASICAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string.h"
#include <time.h>
#include <stdbool.h>


/// CONSTANTES

#define DIMENSION_ARREGLO_INVENTARIO 2
#define DANO_CONSTANTE 75

/// NOMBRES ARCHIVOS

#define rutaUsuario "Usuarios.dat"
#define rutaPersonaje "Personajes.dat"
#define rutaArmas "Armas.dat"
#define rutaPociones "Pociones.dat"
#define rutaInventario "inventario.dat"
#define rutaIA "inteligencia.dat"


/// =================================================== ESTRUCTURAS =================================================================

/// Pociones a utilizar en el juego
typedef struct
{
    int idPocion;///LAS IDENTIFICA INDIVIDUALMENTE
    int idTipo;///ID DEL TIPO DE POCION 1 VIDA/2 ENERGIA/ ETC
    bool estadoPoc; /// Alta = true // Baja = false
    char nombrePoc[25];
    int aumento;
    int curaVeneno;
} pocion;

typedef struct nodo_pocion
{
  pocion dato;
  struct nodo_pocion * siguiente;
  struct nodo_pocion * anterior;
}nodo_pocion;

/// Estadisticas de las armas
typedef struct
{
    char nombreArm [25];
    int id;///Id especifica de cada arma/hechizo
    int tipo;/// 0-> ARMA | 1-> HECHIZO
    int danioF; /// Daño Fisico
    int danioM; /// Daño Magico
    int efecto;///VER TABLA EFECTOS //1 STUNS | 0 DANO CONSTANTE
    int cantidad_turnos_efecto;
    float critico;///Porcentaje agregado al daño inicial
    bool estadoArma;///Para no tener que entrar a la struct
} arma;

/// Inventario --> esperemos tema nuevo

typedef struct nodo_base_inventario
{
    arma arma_dato;

    struct nodo_base_inventario *siguiente;
    struct nodo_base_inventario *anterior;

}nodo_base_inventario;

typedef struct celda_inventario
{
    ///0 -> solo ARMA|1 -> solo HECHIZOS
    nodo_base_inventario*dato;

}celda_inventario;

/// Estadisticas de los personajes
typedef struct
{
    int id;/// ID>0 HEROE | ID<0 ENEMIGO
    int nivel;///Sube stats (vida - armadura - energia)
    bool estado;  /// ESTADO=true--> VIVO | ESTADO=false--> MUERTO

    int cantidad_turnos_veneno;
    int cantidad_turnos_stun;

    char nombre[25];
    float vida;
    float armadura;
    int energia;
    int danioBase;
    arma stats;
    nodo_pocion * pociones; ///Pocion que se posee
    celda_inventario inventario[DIMENSION_ARREGLO_INVENTARIO];///ARMAS Y HECHIZOS

} personaje;

/// Usuarios
typedef struct
{
    int id;
    int tipo; ///Admin = 1 // Usuario = 0
    char nombre[25];
    char contrasenia[20]; /// En un futuro que el administrador pueda cambiar la contra y el nombre
} usuario;

///IA ENEMIGOS
typedef struct
{
    int id;///INPUT DEL JUGADOR - Parametro de Busqueda
    int respuesta;///RESPUESTA DE ACCION

}dato_IA;//para pasar al arhivo

typedef struct nodo_IA
{
    dato_IA info;

    struct nodo_IA*derecha;
    struct nodo_IA*izquierda;

}nodo_IA;

/// FUNCIONES

void menu_principal();

///FUNCIONES DE LOGUEO USUARIO
usuario logueo ();
usuario cargaUsuario();
usuario usuarioCreado(usuario aux, usuario nuevo, int* flag, FILE* archi);
usuario crearUsuario(usuario aux, usuario nuevo, FILE* archi);

//MENU USUARIO
usuario menuUsuario(usuario nuevo);

//CAMBIOS USUARIO
usuario cambioUser(usuario nuevo);
usuario cambioContra(usuario nuevo);

//BUSQUEDA USUARIO
int busquedaUser(char nombre[], FILE* archi);
//VERIFICAR QUE EL USER NO SE REPITA
int UserRepetido(char nombre[],FILE* archi);

//SELECCION
void seleccionPersonaje(personaje* protagonista);
void mostrarAnimaciones(int id);
void mostrarArmaUser(personaje auxP);
void leerEnemigos(personaje* enemigo, int numEnemigo);
void mostrarPersonajesUser();
//SELECCIONA PERSONAJE
void personajeSeleccionado(char nombrefarchivovo[], personaje* auxP);
//BUSCA PERSONAJE SEGUN LA ID
int busquedaPersonajeUser(personaje* auxP);

///INVENTARIO

//NODOS
nodo_base_inventario * inic_lista_base_inventario();
nodo_base_inventario * crea_nodo_base_inventario(arma arma_dato);
nodo_base_inventario * agregar_nodo_base_inventario_principio ( nodo_base_inventario * lista, nodo_base_inventario * nuevo);

//CELDAS
int buscarId (celda_inventario arreglo[], int val, arma buscada);
void crear_inventario(celda_inventario arreglo[],arma dato_arma,arma hechizo);
void crear_inventario(celda_inventario arreglo[],arma dato_arma,arma hechizo);
void ingresa_arma_inventario(celda_inventario arreglo[],arma dato,int tipo);
///ASIGNACIONES BASICAS
void asignarPrincipales(personaje* protagonista);
///HECHIZOS
void asignarHechizosBasicos(personaje* protagonista);
void asignarSegunID(arma auxA,arma auxA2,personaje* protagonista);
///POCIONES
void asignarPocionesBasicas(personaje* protagonista);
//DAR ITEM RANDOM
//ARMAS
int busca_id_max_arma_archivo();
arma busqueda_arma_archivo(int id);
arma dar_arma_random();
bool verifica_id_inventario(nodo_base_inventario*lista,int id);
arma arma_random(personaje * jugador);
//POCIONES
int busca_id_max_pocion_archivo();
pocion busqueda_pocion_archivo(int id);
nodo_pocion * pocion_random();


///POCIONES
nodo_pocion * inic_lista_pociones();
nodo_pocion * crea_nodo_pocion(pocion dato);
nodo_pocion * buscar_ultimo_pocion(nodo_pocion * lista);
nodo_pocion * agregar_al_final_pocion(nodo_pocion * lista,nodo_pocion*nuevo);
nodo_pocion * buscar_pocion(nodo_pocion * lista,int  id);
nodo_pocion * borrar_pocion(nodo_pocion * lista,int  id);
nodo_pocion * borrar_pociones(nodo_pocion * lista);

///IA
nodo_IA * inic_arbol_IA();
nodo_IA * crea_nodo_ia(int id,int rta);
nodo_IA * insertar(nodo_IA*arbol,nodo_IA*nuevo);
nodo_IA * leer_arbol_IA_archivo(nodo_IA*arbol);
int analiza_estado_combate_IA(personaje jugador,personaje enemigo);
int busca_respuesta_arbol_IA(nodo_IA*arbol,int id);

#endif /// FUNCIONES_BASICAS_H_INCLUDED

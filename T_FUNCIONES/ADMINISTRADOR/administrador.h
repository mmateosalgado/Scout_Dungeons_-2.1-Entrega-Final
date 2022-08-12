#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED

#include "../BASICAS/funciones_basicas.h"
#include "../GRAFICOS/graficos.h"

///FUNCIONES DE ADMINISTRADOR -----------------------------------------------

void opcionesdeadministrador();

///PERSONAJES----------------------------------------------------------------
///MENU PERSONAJES
void creacionPersonaje();
///AGREGAR
void agregarPersonajes();
personaje nombrePRepetido(personaje creacionP, FILE* farchivo);
personaje asignarValoresPersonaje(personaje creacionP, FILE* farchivo);
///VER TODOS LOS DATOS
void verPersonajes();
void verPersonajesAux(personaje* auxP);
///MODIFICAR
void modificarPersonajes();
personaje modificarPersonajesAux(personaje auxP,FILE* farchivo);
///BUSQUEDA DEL PERSONAJE
int busquedaPersonaje(personaje* aux, FILE* farchivo);
///REPETIDOS
int personajeRepetido(personaje* auxP,FILE* farchivo);
///VER SOLO NOMBRE DE LOS PERSONAJES
void mostrarPersonajes(FILE* farchivo);
///ASIGNAR ID AL PERSONAJE SEGUN LOS QUE YA ESTAN CREADOS
void asignarID(personaje* creacionP,FILE* farchivo);
int seleccionID(int ID, int IDenemigo);
///ASIGNACIONES DEL PERSONAJE
void asignarArma(personaje* creacionP);

///ARMAS----------------------------------------------------------------------
///MENU ARMAS
void creacionArmas();
///AGREGAR
void agregarArmas();
arma nombreARepetido(arma creacionA,FILE* farchivo);
arma asignarValoresArma(arma creacionA,FILE* farchivo);
///VER TODOS LOS DATOS
void verArmas();
void verArmasAux(arma auxA);
///MODIFICAR
void modificarArmas();
arma modificarArmasAux(arma auxA,FILE* farchivo);
///BUSQUEDA DEL ARMA
int busquedaBytesArma(arma* aux, FILE* farchivo);
///REPETIDOS
int armaRepetida(arma* auxArm, FILE* farchivo);
///VER SOLO EL NOMBRE DE LAS ARMAS
void mostrarArmas(FILE* farchivo);
///ASIGNAR ID AL ARMA SEGUN LAS QUE YA ESTÉN CREADAS
void asignarIDArma(arma* creacionA,FILE* farchivo);

///POCIONES----------------------------------------------------------------------
///MENU POCIONES
void creacionPociones();
///AGREGAR
void agregarPociones();
pocion nombrePocRepetido(pocion creacionP,FILE* farchivo);
pocion asignarValoresPocion(pocion creacionPoc,FILE* farchivo);
///VER TODOS LOS DATOS
void verPociones();
void verPocionesAux(pocion auxPoc);
///MODIFICAR
void modificarPociones();
pocion modificarPocionesAux(pocion auxPoc,FILE* farchivo);
///BUSQUEDA DE POCIONES
int busquedaBytesPociones(pocion* aux,FILE* farchivo);
///REPETIDOS
int  pocionRepetida(pocion* auxPoc,FILE* farchivo);
///VER SOLO LOS NOMBRES
void mostrarPocionesAdmin(FILE* farchivo);
///ASIGNAR ID POCION
void asignarIDPoc(pocion* creacionPoc,FILE* farchivo);

///MUESTRA PERSONAJES VALIDOS AL USER----------------------------------------------------------------------
void mostrarPersonajesUserAux(personaje auxP);

///SELECCION
void mostrarPersonajesUser();
void seleccionPersonaje(personaje* protagonista);

#endif // ADMINISTRADOR_H_INCLUDED

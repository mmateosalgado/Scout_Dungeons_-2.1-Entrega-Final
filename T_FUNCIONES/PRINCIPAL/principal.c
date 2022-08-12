#include "principal.h"
///SERIA COMO EL MAIN
void funcion_principal()
{
    arma arma_encontrada;
    nodo_pocion * pocion_encontrada=inic_lista_pociones();

    personaje protagonista,enemigo;

    ///PARA REINICIAR LAS STATS AL FINALIZAR UN COMBATE
    personaje auxProta;
    int idEnemigo=-1,turno=0;
    titulo();
    system("pause");


    ///LOGUEO
    usuario Activo = logueo();
    system("cls");

///SI ES USUARIO VA A SER 0
    if (Activo.tipo == 0)
    {
///PRUEBEN PONER EN ID EL 11, 12 O 13, Personaje secreto? Descubrilo por tu cuenta.

        seleccionPersonaje(&protagonista);
        asignarPrincipales(&protagonista);

        auxProta=protagonista;

        nodo_pocion* aux=inic_lista_pociones();
        pocion arreglo[4];
        aux=protagonista.pociones;
        nodo_pocion* aux2=inic_lista_pociones();
        arreglo[0]=aux->dato;
        aux=aux->siguiente;

        arreglo[1]=aux->dato;
        aux=aux->siguiente;

        arreglo[2]=aux->dato;
        aux=aux->siguiente;

        arreglo[3]=aux->dato;
        aux=aux->siguiente;



        for(int idHistoria=1; idHistoria<=5; idHistoria++)
        {
            ///COMBATE
            muestra_historia(idHistoria,Activo,protagonista);
            leerEnemigos(&enemigo,idEnemigo);
            combate(&protagonista,&enemigo,turno);


            ///RESETEAMPOS STATS, TURNOS ,DAMOS UN ARMA RANDOM Y CAMBIA ID ENEMIGO
            turno=0;
            protagonista=auxProta;
            idEnemigo--;

            ///reinicia pociones
            protagonista.pociones=inic_lista_pociones();
            for(int i=0; i<4; i++)
            {
                aux2=crea_nodo_pocion(arreglo[i]);
                protagonista.pociones=agregar_al_final_pocion(protagonista.pociones,aux2);
            }


            arma_encontrada=arma_random(&protagonista);
            pocion_encontrada=pocion_random();


            ingresa_arma_inventario(protagonista.inventario,arma_encontrada,arma_encontrada.tipo);
            protagonista.pociones=agregar_al_final_pocion(protagonista.pociones,pocion_encontrada);

            muestra_arma_pocion_encontrada();
            printf("\n");
            muestra_arma(arma_encontrada);
            printf("\n");
            muestra_pocion(pocion_encontrada->dato);
            system("pause");

            auxProta=protagonista;
        }
        ///GG
        mostrar_ganaste();
    }
    else if (Activo.tipo == 1)
    {
        ///LA CUENTA DEL ADMINISTRADOR ES USUARIO: Scout Contraseña: Dungeons
        ///SOLO SI ES ADMINISTRADOS, puede crear
        opcionesdeadministrador();
    }
}


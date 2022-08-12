#include "administrador.h"

///Funcion principal del administrador
void opcionesdeadministrador()
{
    system("cls");
    int menu;
    printf("----Oh Jefe por fin volviste, ya te echabamos de menos\n");
    printf("----Bienvenido al menu de opciones, que cambios deseas realizar en esta oportunidad?\n");
    printf("----Oprime [1] para personajes, [2] para Armas, [3] para Pociones o [4] para todas\n");

    fflush(stdin);
    scanf("%d", &menu);
    printf("----MANOSS A LA OBRAAA\n");

    while(menu>0)
    {

        switch(menu)
        {
        case 1:
        {
            creacionPersonaje();
            break;
        }
        case 2:
        {
            creacionArmas();
            break;
        }
        case 3:
        {
            creacionPociones();
            break;
        }
        case 4:
        {
            creacionPersonaje();
            creacionArmas();
            creacionPociones();
            break;
        }
        default:
        {
            printf("----Creo que te equivocaste de opcion jefe\n");
            break;
        }
        }
        printf("---------------------------------------Funciones Administrador-----------------------------------------\n");
        printf("----Quieres fijarte en algo mas?\n");
        printf("----Oprime [1] para personajes, [2] para Armas, [3] para Pociones o [4] para todas\n");
        printf("----Sino oprime 0 para salir\n");
        fflush(stdin);
        scanf("%d", &menu);
    }
    printf("---Eso fue todo jefe?\n Nos vemos en la proxima!!!\n");
}

///------------------------------------PERSONAJES------------------------------------------
///MENU PERSONAJES
void creacionPersonaje()
{
    system("cls");
    int opciones;


    printf("---Bienvenido jefe al espacio donde creamos personajes !!\n");

    printf("---Oprima [1] para agregar personajes, [2] para verlos o [3] para modificarlos\n");

    scanf("%d", &opciones);

    switch(opciones)
    {
    case 1:
    {

        agregarPersonajes();
        break;
    }


    case 2:
    {
        verPersonajes();
        break;
    }
    case 3:
    {

        modificarPersonajes();
        break;
    }


    default:

    {
        printf("---Creo que te equivocaste de numero jefe\n");
        creacionPersonaje();
        break;
    }
    }
}

///CREACION PERSONAJES
void agregarPersonajes()
{
    system("cls");
    personaje creacionP;
    int pregunta = 1;

    printf("---Bienvenido a la sala de creacion de personajes\n");

    FILE* farchivo =fopen(rutaPersonaje, "a+b");

    if(farchivo)
    {
        while(pregunta == 1)
        {
            mostrarPersonajes(farchivo);
            creacionP= asignarValoresPersonaje(creacionP,farchivo);

            fwrite(&creacionP, sizeof(personaje), 1, farchivo);

            printf("---Quieres crear otro personaje? Oprime [1] para si, [0] para no\n");
            fflush(stdin);
            scanf("%d", &pregunta);
        }

        fclose(farchivo);
    }
}

personaje nombrePRepetido(personaje creacionP, FILE* farchivo)
{
    int repetido=0;
    while(repetido==0)
    {
        printf("---Nombre:");
        fflush(stdin);
        gets(creacionP.nombre);

        repetido = personajeRepetido(&creacionP,farchivo);

        if (repetido==0)
        {
            printf("---Nombre repetido\nPruebe con otro Nombre\n");
        }
    }
    return creacionP;
}

personaje asignarValoresPersonaje(personaje creacionP, FILE* farchivo)
{
    int estado;
    creacionP= nombrePRepetido(creacionP,farchivo);

    printf("---Vida:\n");
    fflush(stdin);
    scanf("%f", &creacionP.vida);

    printf("---Energia: \n");
    fflush(stdin);
    scanf("%d", &creacionP.energia);

    printf("---Armadura:\n");
    fflush(stdin);
    scanf("%f", &creacionP.armadura);

    printf("---Danio:\n");
    fflush(stdin);
    scanf("%d",&creacionP.danioBase);

    printf("---Nivel:\n");
    fflush(stdin);
    scanf("%d",&creacionP.nivel);

    printf("---Arma:\n");
    fflush(stdin);
    asignarArma(&creacionP);

    ///Asigna ID Automaticamente printf("---ID:\n");
    asignarID(&creacionP,farchivo);

    ///DAR DE ALTA O BAJA AL PERSONAJE

    printf("---Quieres darlo de alta? Oprima [1] para si, [0] para no\n");
    fflush(stdin);
    scanf("%d", &estado);

    if(estado == 1)
    {
        creacionP.estado=true;
    }
    else
    {
        creacionP.estado=false;
    }

    ///ASIGNA VALORES 0 A EFECTOS DE COMBATE
    creacionP.cantidad_turnos_stun=0;
    creacionP.cantidad_turnos_veneno=0;

    ///INICIALIZA LA LISTA DE POCIONES Y EL INVENTARIO
    creacionP.pociones=inic_lista_pociones();
    creacionP.inventario[0].dato=inic_lista_base_inventario();
    creacionP.inventario[1].dato=inic_lista_base_inventario();

    return creacionP;
}


///VER PERSONAJES
void verPersonajes()
{
    system("cls");
    personaje auxP;

    auxP.pociones=inic_lista_pociones();
    FILE* farchivo =fopen(rutaPersonaje, "rb");
    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(fread(&auxP, sizeof(personaje), 1, farchivo)> 0)
        {
            ///printf("%s",auxP.pociones->dato.nombrePoc)
            verPersonajesAux(&auxP);
        }
        fclose(farchivo);
    }
}

void verPersonajesAux(personaje* auxP)
{

    printf("---Nombre: %s\n", auxP->nombre);
    printf("---Vida: %.1f\n", auxP->vida);
    printf("---Energia: %d\n", auxP->energia);
    printf("---Armadura: %.1f\n", auxP->armadura);
    printf("---Danio Base:%d\n",auxP->danioBase);
    printf("---Arma: %s\n",auxP->stats.nombreArm);
    printf("---Nivel: %d\n",auxP->nivel);
    printf("---Arma danio %d\n",auxP->stats.danioF);
    printf("---Estado: %d\n", auxP->estado);
    printf("---ID %d\n", auxP->id);
    printf("-------------------------------------------------\n");
}


///MODIFICAR PERSONAJES
void modificarPersonajes()
{
    system("cls");
    personaje auxP;
    FILE* farchivo =fopen(rutaPersonaje, "r+b");

    if(farchivo)
    {
inicioP:
        mostrarPersonajes(farchivo);
        printf("---Que personaje desea modificar?\n");
        fflush(stdin);
        gets(auxP.nombre);

        int repetido=personajeRepetido(&auxP,farchivo);
        if(repetido==1)
        {
            goto inicioP;
        }

        int personajeEncontrado= busquedaPersonaje(&auxP,farchivo);

        auxP= modificarPersonajesAux(auxP,farchivo);

        fseek(farchivo, sizeof(personaje)* (personajeEncontrado -1),SEEK_SET);
        fwrite(&auxP, sizeof(personaje), 1, farchivo);
        fclose(farchivo);
    }
}

personaje modificarPersonajesAux(personaje auxP,FILE* farchivo)
{
    system("cls");
    int cambiar, estado;
    printf("Ingrese la caracteristica a cambiar\n");
    printf("\n      -NOMBRE            [1] ");
    printf("\n      -VIDA              [2] ");
    printf("\n      -ENERGIA           [3] ");
    printf("\n      -ARMADURA          [4] ");
    printf("\n       -DA%cO BASE        [5] ",165);
    printf("\n      -ARMA PRINCIPAL    [6] ");
    printf("\n      -NIVEL             [7] ");
    printf("\n      -ID                [8] ");
    printf("\n      -ESTADO            [9] ");
    printf("\n -OPCION : ");
    fflush(stdin);
    scanf("%d", &cambiar);
    while (cambiar> 0)
    {

        switch(cambiar)
        {

        case 1:
        {
            printf("---Nombre:%s\n", auxP.nombre);
            auxP= nombrePRepetido(auxP,farchivo);
            break;
        }


        case 2:
        {
            printf("---Vida: %.1f\n", auxP.vida);
            fflush(stdin);
            scanf("%f", &auxP.vida);
            break;
        }

        case 3:
        {
            printf("---Energia: %d\n", auxP.energia);
            fflush(stdin);
            scanf("%d", &auxP.energia);
            break;
        }
        case 4:
        {
            printf("---Armadura: %.1f\n", auxP.armadura);
            fflush(stdin);
            scanf("%f", &auxP.armadura);
            break;
        }
        case 5:
        {
            printf("---Danio Base: %d\n", auxP.danioBase);
            fflush(stdin);
            scanf("%d",&auxP.danioBase);
            break;
        }
        case 6:
        {

            printf("---Arma %s\n", auxP.stats.nombreArm);
            fflush(stdin);
            printf("---Hola xd");
            asignarArma(&auxP);
            break;
        }

        case 7:
        {
            printf("---Nivel %d\n", auxP.nivel);
            fflush(stdin);
            scanf("%d",&auxP.nivel);
            break;
        }
        case 8:
        {
            printf("---ID\n");
            fflush(stdin);
            scanf("%d", &auxP.id);
            break;
        }
        case 9:
        {
            printf("---Estado: [1] = alta [0] = baja\n Estado a modificar: %d\n", auxP.estado);
            fflush(stdin);
            scanf("%d", &estado);
            if(estado==1)
            {
                auxP.estado=true;
            }
            else
            {
                auxP.estado=false;
            }
            break;
        }
        default:
        {
            printf("---Error\n");
            printf("Ingrese la caracteristica a cambiar\n");
            printf("\n      -NOMBRE            [1] ");
            printf("\n      -VIDA              [2] ");
            printf("\n      -ENERGIA           [3] ");
            printf("\n      -ARMADURA          [4] ");
            printf("\n       -DA%cO BASE        [5] ",165);
            printf("\n      -ARMA PRINCIPAL    [6] ");
            printf("\n      -NIVEL             [7] ");
            printf("\n      -ID                [8] ");
            printf("\n      -ESTADO            [9] ");
            printf("---Si deseas pasar al siguiente, apreta [0]\n");
            printf("\n -OPCION : ");
            fflush(stdin);
            scanf("%d", &cambiar);
            break;
        }
        }

        printf("---Ingrese la caracteristica a cambiar\n");
        printf("\n      -NOMBRE            [1] ");
        printf("\n      -VIDA              [2] ");
        printf("\n      -ENERGIA           [3] ");
        printf("\n      -ARMADURA          [4] ");
        printf("\n       -DA%cO BASE        [5] ",165);
        printf("\n      -ARMA PRINCIPAL    [6] ");
        printf("\n      -NIVEL             [7] ");
        printf("\n      -ID                [8] ");
        printf("\n      -ESTADO            [9] ");
        printf("---Si deseas pasar al siguiente, apreta [0]\n");
        printf("\n -OPCION : ");
        fflush(stdin);
        scanf("%d", &cambiar);
    }

    return auxP;
}

///BUSQUEDA DEL PERSONAJE
int busquedaPersonaje(personaje* aux, FILE* farchivo)
{
    personaje auxP;
    int personajeEncontrado=0,flag=0;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(flag ==0 && fread(&auxP, sizeof(personaje), 1, farchivo)> 0)
        {

            if (strcmp(auxP.nombre, aux->nombre)== 0)
            {

                flag=1;
            }
        }

        if(strcmp(auxP.nombre,aux->nombre)== 0)
        {
            fseek(farchivo,0,SEEK_CUR);
            (*aux)=auxP;
            personajeEncontrado = ftell(farchivo) / sizeof(personaje);
        }
    }

    return personajeEncontrado;
}

///Verifica si se repite el nombre de un Personaje
int personajeRepetido(personaje* auxP,FILE* farchivo)
{
    int repetido=1;
    personaje aux2P;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {

        while(repetido == 1 && fread(&aux2P, sizeof(personaje),1,farchivo)>0)
        {

            if(strcmp(auxP->nombre, aux2P.nombre)== 0)
            {
                repetido=0;
            }
        }
    }
    return repetido;
}

///MOSTRAR SOLO EL NOMBRE DE PERSONAJES CREADOS
void mostrarPersonajes(FILE* farchivo)
{
    system("cls");
    personaje auxP;
    printf("---Los personajes ya creados son:\n");

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(fread(&auxP, sizeof(personaje), 1, farchivo)>0)
        {
            printf("---%s;", auxP.nombre);
        }
    }
    printf("---\n-----------------------------------------------------------\n");
}

///ASIGNAR ID AL PERSONAJE SEGUN LOS QUE YA ESTÉN CREADOS
void asignarID(personaje* creacionP,FILE* farchivo)
{
    personaje auxP;
    int ID=0, IDenemigo=0;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(fread(&auxP, sizeof(personaje),1,farchivo)>0)
        {
            if(auxP.id>0)
            {
                ID++;
            }

            if(auxP.id<0)
            {
                IDenemigo--;
            }
        }
    }
    creacionP->id =seleccionID(ID,IDenemigo);
}

int seleccionID(int ID, int IDenemigo)
{
    int opcionID, auxID;
    printf("---Oprima [1] para que el personaje sea bueno o [2] para que sea un enemigo\n");
    fflush(stdin);
    scanf("%d",&opcionID);

///DEPENDIENDO SI ES BUENO O MALO LE ASIGNA UNA ID
///SI ES BUENO LE PONE COMO ID UN NUMERO POSITIVO
///SI ES ENEMIGO LE PONE COMO ID UN NUMERO NEGATIVO
    if(opcionID == 1)
    {
        ID++;
        auxID=ID;
    }

    else if(opcionID == 2)
    {
        IDenemigo--;
        printf("---Enemigo:\n");
        auxID=IDenemigo;
    }
    else
    {
        printf("---Error\n");
        auxID= seleccionID(ID,IDenemigo);
    }

    return auxID;
}

///ASIGNACIONES DEL PERSONAJE
///ASIGNAR ARMA A UN PERSONAJE
void asignarArma(personaje* creacionP)
{
    arma auxA, aux2A;
    int flag=0, cambiar;

    FILE* farchivo =fopen(rutaArmas, "rb");
inicioA:

    mostrarArmas(farchivo);

    printf("---Que Arma deseas asignarle?\n");
    fflush(stdin);
    gets(aux2A.nombreArm);

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(flag == 0 && fread(&auxA, sizeof(arma), 1, farchivo)> 0 )
        {
            if (strcmp(auxA.nombreArm, aux2A.nombreArm) == 0)
            {
                flag=1;
                creacionP->stats = auxA;
            }
        }

        fclose(farchivo);
    }

    ///Por si no existe el Arma
    if (flag == 0)
    {
        goto inicioA;
        printf("---Lo siento no encontramos el arma buscada\n");
        printf("---Oprima [1] para crear un arma, [0] para volver a asignarle otro arma\n");
        fflush(stdin);
        scanf("%d", &cambiar);

        if(cambiar == 1)
        {
            agregarArmas();
            asignarArma(creacionP);
        }

        else if(cambiar==0)
        {
            asignarArma(creacionP);
        }
    }
}
///------------------------------------ARMAS------------------------------------------

///MENU ARMAS
void creacionArmas()
{
    system("cls");
    int opciones;
    printf("---Bienvenido jefe a la herreria, lugar donde creamos las Armas !!\n");

    printf("---Oprima [1] para agregar Armas, [2] para verlos o [3] para modificarlos\n");

    scanf("%d", &opciones);

    switch(opciones)
    {
    case 1:
    {
        agregarArmas();
        break;

    }
    case 2:
    {
        verArmas();
        break;
    }
    case 3:
    {
        modificarArmas();
        break;
    }

    default:
    {
        printf("---Creo que te equivocaste de numero jefe\n");
        creacionArmas();
        break;
    }
    }
}

///CREAR ARMAS
void agregarArmas()
{
    system("cls");
    arma creacionA;
    int pregunta = 1;

    printf("---Bienvenido a la sala de creacion de armas\n");

    FILE* farchivo =fopen(rutaArmas, "a+b");

    if(farchivo)
    {
        while(pregunta == 1)
        {
            mostrarArmas(farchivo);
            creacionA= asignarValoresArma(creacionA,farchivo);
            fwrite(&creacionA, sizeof(arma), 1, farchivo);

            printf("---Quieres crear otro arma? Oprime [1] para si, [0] para no\n");
            fflush(stdin);
            scanf("%d", &pregunta);
        }

        fclose(farchivo);
    }

}

arma nombreARepetido(arma creacionA,FILE* farchivo)
{

    int repetido=0;
    while(repetido==0)
    {
        printf("---Nombre:\n");
        fflush(stdin);
        gets(creacionA.nombreArm);

        repetido =armaRepetida(&creacionA,farchivo);

        if (repetido==0)
        {
            printf("---Nombre repetido\nPruebe con otro Nombre\n");

        }
    }
    return creacionA;
}

arma asignarValoresArma(arma creacionA,FILE* farchivo)
{
    int estado;
    ///ASIGNA AUTOMATICAMENTE ID
    asignarIDArma(&creacionA,farchivo);

    ///VERIFICA QUE EL NOMBRE NO SE REPITA
    creacionA = nombreARepetido(creacionA,farchivo);


    printf("---Que desea crear? [0] para arma o [1] para hechizo:\n");
    fflush(stdin);
    scanf("%d",&creacionA.tipo);

    printf("---Danio Fisico:\n");
    fflush(stdin);
    scanf("%d", &creacionA.danioF);

    printf("---Danio Magico:\n");
    fflush(stdin);
    scanf("%d", &creacionA.danioM);

    printf("---Critico:\n");
    fflush(stdin);
    scanf("%f", &creacionA.critico);


    printf("Efecto:[2]DA%cO CONSTANTE, [1] STUN, [0]NADA (POR ENDE ES UN ARMA):\n",165);
    fflush(stdin);
    scanf("%d",&creacionA.efecto);

    ///DAR DE ALA O BAJA AL PERSONAJE

    printf("---Quieres darlo de alta? Oprima [1] para si, [0] para no\n");
    fflush(stdin);
    scanf("%d", &estado);

    if(estado == 1)
    {
        creacionA.estadoArma=true;
    }
    else
    {
        creacionA.estadoArma=false;
    }
    if(creacionA.tipo==1)
    {
        printf("---Cantidad de turnos\n");
        fflush(stdin);
        scanf("%d",&creacionA.cantidad_turnos_efecto);
    }
    else
    {
        creacionA.cantidad_turnos_efecto=0;
    }

    return creacionA;
}
///VER ARMAS
void verArmas()
{
    system("cls");
    arma auxA;
    FILE* farchivo =fopen(rutaArmas, "rb");

    fseek(farchivo,0,SEEK_SET);

    if(farchivo)
    {

        while(fread(&auxA, sizeof(arma), 1, farchivo)> 0)
        {
            verArmasAux(auxA);

        }
        fclose(farchivo);
    }
}

void verArmasAux(arma auxA)
{
    printf("---Nombre: %s\n", auxA.nombreArm);
    printf("---ID: %d\n",auxA.id);
    printf("---ID: [0] ARMA; [1] HECHIZO: %d\n",auxA.tipo);
    printf("---Danio fisico: %d\n", auxA.danioF);
    printf("---Danio magico: %d\n", auxA.danioM);
    printf("---Critico: %.2f\n", auxA.critico);
    printf("---Efecto:[2] DA%cO CONSTANTE, [1] STUN, [0]NADA (POR ENDE ES UN ARMA): %d \n",165,auxA.efecto);
    printf("---Cant turnos: %d\n",auxA.cantidad_turnos_efecto);
    printf("---Estado: %d\n", auxA.estadoArma);
    printf("-------------------------------------------------\n");
}
/// MODIFICAR ARMAS
void modificarArmas()
{
    system("cls");
    arma auxA;

    FILE* farchivo =fopen(rutaArmas, "r+b");

    if(farchivo != NULL)
    {
inicioArma:
        mostrarArmas(farchivo);
        printf("---Que Arma desea modificar?\n");
        fflush(stdin);
        gets(auxA.nombreArm);

        int repetido=armaRepetida(&auxA,farchivo);

        if(repetido==1)
        {
            goto inicioArma;
        }

        int armaEncontrada=busquedaBytesArma(&auxA,farchivo);

        auxA=modificarArmasAux(auxA,farchivo);
        fseek(farchivo, sizeof(arma)* (armaEncontrada-1),SEEK_SET);
        fwrite(&auxA, sizeof(arma), 1, farchivo);

        fclose(farchivo);
    }
}
arma modificarArmasAux(arma auxA,FILE* farchivo)
{
    ///AGREGAR ID AUTOMATICA
    system("cls");
    int cambiar,estado;

    printf("Ingrese la caracteristica a cambiar\n");
    printf("\n      -NOMBRE           [1] ");
    printf("\n      -TIPO             [2] ");
    printf("\n      -DA%cO FISICO      [3] ",165);
    printf("\n      -DA%cO MAGICO      [4] ",165);
    printf("\n      -CRITICO          [5] ");
    printf("\n      -EFECTO           [6] ");
    printf("\n      -CANT TURNOS      [7] ");
    printf("\n      -ESTADO           [8] ");
    printf("\n -OPCION : ");
    fflush(stdin);
    scanf("%d", &cambiar);

    while (cambiar> 0)
    {
        switch(cambiar)
        {

        case 1:
        {
            printf("---Nombre: %s\n", auxA.nombreArm);
            auxA= nombreARepetido(auxA,farchivo);

            break;
        }

        case 2:
        {

            printf("---Que desea cambiar: [0] para arma o [1] para hechizo: %d\n",auxA.tipo);
            fflush(stdin);
            scanf("%d",&auxA.tipo);
            break;
        }

        case 3:
        {
            printf("---Danio fisico %d\n", auxA.danioF);
            fflush(stdin);
            scanf("%d", &auxA.danioF);
            break;
        }

        case 4:
        {
            printf("---Danio magico: %d\n", auxA.danioM);
            fflush(stdin);
            scanf("%d", &auxA.danioM);
            break;
        }
        case 5:
        {
            printf("---Critico: %.2f\n", auxA.critico);
            fflush(stdin);
            scanf("%f", &auxA.critico);
            break;
        }
        case 6:
        {
            printf("---Efecto:[2] DA%cO CONSTANTE, [1] STUN, [0]NADA (POR ENDE ES UN ARMA): %d \n",165,auxA.efecto);
            fflush(stdin);
            scanf("%d", &auxA.efecto);

            break;
        }
        case 7:
        {
            if(auxA.tipo==1)
            {
                printf("---Cantidad de turnos %d:\n",auxA.cantidad_turnos_efecto);
                fflush(stdin);
                scanf("%d",&auxA.cantidad_turnos_efecto);
            }
            else
            {
                auxA.cantidad_turnos_efecto=0;
            }

            break;
        }
        case 8:
        {
            printf("---Estado: [1] = alta [0] =baja\nEstado a modificar %d\n", auxA.estadoArma);
            fflush(stdin);
            scanf("%d", &estado);
            if(estado==1)
            {
                auxA.estadoArma=true;
            }
            else
            {
                auxA.estadoArma=false;
            }
            break;
        }
        default:
            printf("---Error\n");
            printf("Ingrese la caracteristica a cambiar\n");
            printf("\n      -NOMBRE            [1] ");
            printf("\n      -TIPO              [2] ");
            printf("\n      -DA%cO FISICO       [3] ",165);
            printf("\n      -DA%cO MAGICO       [4] ",165);
            printf("\n      -CRITICO           [5] ");
            printf("\n      -EFECTO            [6] ");
            printf("\n      -CANT TURNOS      [7] ");
            printf("\n      -ESTADO           [8] ");
            printf("---\nSi deseas pasar al siguiente, apreta [0]\n");
            printf("\n -OPCION : ");
            fflush(stdin);
            scanf("%d", &cambiar);



        }
        printf("Ingrese la caracteristica a cambiar\n");
        printf("\n      -NOMBRE           [1] ");
        printf("\n      -TIPO             [2] ");
        printf("\n      -DA%cO FISICO      [3] ",165);
        printf("\n      -DA%cO MAGICO      [4] ",165);
        printf("\n      -CRITICO          [5] ");
        printf("\n      -EFECTO           [6] ");
        printf("\n      -CANT TURNOS      [7] ");
        printf("\n      -ESTADO           [8] ");
        printf("---\nSi deseas pasar al siguiente, apreta [0]\n");
        printf("\n -OPCION : ");
        fflush(stdin);
        scanf("%d", &cambiar);
    }

    return auxA;
}

int busquedaBytesArma(arma* aux, FILE* farchivo)
{
    arma auxA;
    int armaEncontrada=0,flag=0;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while( flag == 0 && fread(&auxA, sizeof(arma), 1, farchivo)> 0 )
        {

            if (strcmp(auxA.nombreArm, aux->nombreArm)== 0)
            {
                flag=1;
            }
        }

        if (strcmp(auxA.nombreArm, aux->nombreArm)== 0)
        {
            fseek(farchivo,0,SEEK_CUR);
            (*aux)=auxA;
            armaEncontrada = ftell(farchivo) / sizeof(arma);

        }
    }

    return armaEncontrada;
}

///Verifica si se repite el nombre de un Arma
int armaRepetida(arma* auxArm, FILE* farchivo)
{
    int repetido=1;
    arma aux2Arm;
    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {

        while(repetido == 1 && fread(&aux2Arm, sizeof(arma),1,farchivo)>0)
        {
            if(strcmp(auxArm->nombreArm, aux2Arm.nombreArm)== 0)
            {
                repetido=0;
            }
        }
    }
    return repetido;
}

///MOSTRAR SOLO EL NOMBRE DE ARMAS CREADAS
void mostrarArmas(FILE* farchivo)
{
    system("cls");
    arma auxA;
    printf("---Las armas ya creadas son:\n");

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(fread(&auxA, sizeof(arma), 1, farchivo)>0)
        {
            printf("---%s;", auxA.nombreArm);
        }
    }
    printf("---\n-----------------------------------------------------------\n");
}
///ASIGNAR ID AL ARMA SEGUN LAS QUE YA ESTÉN CREADAS
void asignarIDArma(arma* creacionA,FILE* farchivo)
{
    arma auxA;
    int ID=0;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(fread(&auxA, sizeof(arma),1,farchivo)>0)
        {
            ID++;
        }
    }

    ///LE ASIGNA UNA ID
    ID++;
    creacionA->id=ID;
}


///------------------------------------POCIONES------------------------------------------
///MENU POCIONES
void creacionPociones()
{
    system("cls");
    int opciones;


    printf("---Bienvenido jefe al laboratorio, lugar donde creamos las pociones !!\n");

    printf("---Oprima [1] para agregar pociones, [2] para verlas o [3] para modificarlas\n");

    fflush(stdin);
    scanf("%d", &opciones);

    switch(opciones)
    {
    case 1:
    {

        agregarPociones();
        break;
    }
    case 2:
    {
        verPociones();
        break;
    }
    case 3:
    {

        modificarPociones();
        break;
    }
    default:

    {
        printf("---Creo que te equivocaste de numero jefe\n");
        creacionPociones();
        break;
    }

    }

}

///CREAR POCIONES
void agregarPociones()
{
    system("cls");
    pocion creacionPoc;
    int pregunta = 1;

    printf("---Bienvenido a la sala de experimentos con pociones\n");

    FILE* farchivo =fopen(rutaPociones, "a+b");
    if(farchivo)
    {
        while(pregunta == 1)
        {
            mostrarPocionesAdmin(farchivo);
            creacionPoc=asignarValoresPocion(creacionPoc,farchivo);
            fwrite(&creacionPoc, sizeof(pocion), 1, farchivo);

            printf("---Quieres crear otra pocion? Oprime [1] para si, [0] para no\n");
            fflush(stdin);
            scanf("%d", &pregunta);
        }

        fclose(farchivo);
    }
}

pocion nombrePocRepetido(pocion creacionP,FILE* farchivo)
{
    int repetido=0;
    while(repetido==0)
    {
        printf("---Nombre Pocion:\n");
        fflush(stdin);
        gets(creacionP.nombrePoc);

        repetido = pocionRepetida(&creacionP,farchivo);

        if (repetido==0)
        {
            printf("---Nombre repetido\nPruebe con otro Nombre\n");

        }
    }
    return creacionP;
}

pocion asignarValoresPocion(pocion creacionPoc,FILE* farchivo)
{
    int estado;
///NOMBRE
    creacionPoc= nombrePocRepetido(creacionPoc,farchivo);

aux:
    ///TIPO
    printf("\n - Que tipo de pocion desea fabricar?: ");
    printf("\n -VIDA        [1] ");
    printf("\n -ENERGIA     [2] ");
    printf("\n  -DA%cO       [3] ",165);
    printf("\n -CURA VENENO [4] ");

    printf("\n -OPCION : ");
    scanf("%d",&creacionPoc.idTipo);
    creacionPoc.curaVeneno=0;
    creacionPoc.aumento=0;
///AUMENTO DE VIDA/ENERGIA/DAÑO
    switch(creacionPoc.idTipo)
    {
    case 1:
    {
        printf("---Vida:\n");
        fflush(stdin);
        scanf("%d", &creacionPoc.aumento);
        break;
    }
    case 2:
    {
        printf("---Energia:\n");
        fflush(stdin);
        scanf("%d", &creacionPoc.aumento);
        break;
    }
    case 3:
    {
        printf("---Danio Total:\n");
        fflush(stdin);
        scanf("%d", &creacionPoc.aumento);
        break;
    }
    case 4:
    {
        printf("---Se ha creado una pocion Cura Veneno  ! \n");
        creacionPoc.curaVeneno=1;
        break;
    }
    default:
        printf("\n -INGRESE UN VALOR VALIDO! ");
        goto aux;
    }
    ///DAR DE ALTA O BAJA AL PERSONAJE

    printf("---Quieres darlo de alta? Oprima [1] para si, [0] para no\n");
    fflush(stdin);
    scanf("%d", &estado);

    if(estado == 1)
    {
        creacionPoc.estadoPoc=true;
    }
    else
    {
        creacionPoc.estadoPoc=false;
    }
    ///LE asigna una ID
    asignarIDPoc(&creacionPoc,farchivo);

    return creacionPoc;
}

///VER POCIONES
void verPociones()
{
    system("cls");
    pocion auxPoc;
    FILE* farchivo =fopen(rutaPociones, "rb");
    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {

        while(fread(&auxPoc, sizeof(pocion), 1, farchivo)> 0)
        {
            verPocionesAux(auxPoc);

        }

        fclose(farchivo);

    }
}

void verPocionesAux(pocion auxPoc)
{
    printf("---Nombre : %s\n", auxPoc.nombrePoc);
    printf("---Cura Veneno: [1] SI | [0] NO : %d\n",auxPoc.curaVeneno);
    printf("---Estado : %d\n", auxPoc.estadoPoc);
    printf("---ID : %d\n",auxPoc.idPocion);
    printf("---Tipo [1] Vida | [2] Energia | [3] Danio : %d\n",auxPoc.idTipo);
    printf("---Aumento : %d\n",auxPoc.aumento);
    printf("-------------------------------------------------\n");
}

///MODIFICAR POCIONES
void modificarPociones()
{
    system("cls");
    pocion auxPoc;

    FILE* farchivo =fopen(rutaPociones, "r+b");

    if(farchivo)
    {
inicioPocAux:
        mostrarPocionesAdmin(farchivo);

        printf("---Que Pocion deseas modificar?\n");
        fflush(stdin);
        gets(auxPoc.nombrePoc);

        int repetido=pocionRepetida(&auxPoc,farchivo);
        if(repetido==1)
        {
            goto inicioPocAux;
        }


        int pocionEncontrada=busquedaBytesPociones(&auxPoc,farchivo);

        auxPoc=modificarPocionesAux(auxPoc,farchivo);

        fseek(farchivo, sizeof(pocion)* (pocionEncontrada-1),SEEK_SET);
        fwrite(&auxPoc, sizeof(pocion), 1, farchivo);

        fclose(farchivo);

    }

}

pocion modificarPocionesAux(pocion auxPoc,FILE* farchivo)
{
    system("cls");
    int cambiar,estado;

    printf("\n - Ingrese la caracteristica a cambiar: ");
    printf("\n      -NOMBRE      [1] ");
    printf("\n      -VIDA        [2] ");
    printf("\n      -ENERGIA     [3] ");
    printf("\n       -DA%cO       [4] ",165);
    printf("\n      -CURA VENENO [5] ");
    printf("\n      -ESTADO      [6] ");
    printf("\n      -TODAS       [7] ");
    printf("\n -OPCION : ");
    fflush(stdin);
    scanf("%d", &cambiar);

    while (cambiar> 0)
    {
        switch(cambiar)
        {

        case 1:
        {
            printf("---Nombre: %s\n", auxPoc.nombrePoc);
            auxPoc=nombrePocRepetido(auxPoc,farchivo);
            break;
        }
        case 2:
        {
            printf("---Vida: %d\n", auxPoc.aumento);
            fflush(stdin);
            scanf("%d", &auxPoc.aumento);
            break;
        }
        case 3:
        {
            printf("---Energia: %d\n", auxPoc.aumento);
            fflush(stdin);
            scanf("%d", &auxPoc.aumento);
            break;
        }
        case 4:
        {
            printf("---Danio Total: %d\n", auxPoc.aumento);
            fflush(stdin);
            scanf("%d", &auxPoc.aumento);
            break;
        }
        case 5:
        {
            printf("---Cura Veneno -->  Si [1] |  No[0] : %d\n",auxPoc.curaVeneno);
            fflush(stdin);
            scanf("%d",&auxPoc.curaVeneno);

            break;
        }
        case 6:
        {
            printf("---Estado: [1] = alta [0] =baja\nEstado a modificar %d\n", auxPoc.estadoPoc);
            fflush(stdin);
            scanf("%d", &estado);
            if(estado ==1)
            {
                auxPoc.estadoPoc=true;
            }
            else
            {
                auxPoc.estadoPoc=false;
            }
            break;
        }
        case 7:
        {
            printf("---Oprime [1] para Vida, [2] para Energia,[3] para Danio, o [4] para CuraVeneno: %d\n",auxPoc.idTipo);
            fflush(stdin);
            scanf("%d", &auxPoc.idTipo);
            break;
        }
        default:
        {

            printf("---Error\n");
            printf("\n - Ingrese la caracteristica a cambiar: ");
            printf("\n      -NOMBRE      [1] ");
            printf("\n      -VIDA        [2] ");
            printf("\n      -ENERGIA     [3] ");
            printf("\n       -DA%cO       [4] ",165);
            printf("\n      -CURA VENENO [5] ");
            printf("\n      -ESTADO      [6] ");
            printf("\n      -TODAS       [7] ");
            printf("---Si deseas volver, apreta [0]\n");
            printf("\n -OPCION : ");
            fflush(stdin);
            scanf("%d", &cambiar);
        }
        }
        printf("\n - Ingrese la caracteristica a cambiar: ");
        printf("\n      -NOMBRE      [1] ");
        printf("\n      -VIDA        [2] ");
        printf("\n      -ENERGIA     [3] ");
        printf("\n       -DA%cO       [4] ",165);
        printf("\n      -CURA VENENO [5] ");
        printf("\n      -ESTADO      [6] ");
        printf("\n      -TODAS       [7] ");
        printf("---Si desea pasar al siguiente, apreta [0]\n");
        printf("\n -OPCION : ");
        fflush(stdin);
        scanf("%d", &cambiar);
    }
    return auxPoc;
}

///BUSQUEDA DE POCIONES

int busquedaBytesPociones(pocion* aux,FILE* farchivo)
{
    pocion auxPoc;
    int pocionEncontrada=0,flag=0;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {

        while(flag == 0 &&  fread(&auxPoc, sizeof(pocion), 1, farchivo)> 0)
        {

            if (strcmp(auxPoc.nombrePoc, aux->nombrePoc)== 0)
            {
                flag=1;
            }
        }

        if (strcmp(auxPoc.nombrePoc, aux->nombrePoc)== 0)
        {
            fseek(farchivo,0,SEEK_CUR);
            (*aux)=auxPoc;
            pocionEncontrada = ftell(farchivo) / sizeof(pocion);
        }
    }
    return pocionEncontrada;
}


///Verifica si se repite el nombre de una Poción
int  pocionRepetida(pocion* auxPoc,FILE* farchivo)
{
    int repetido=1;
    pocion aux2Poc;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(repetido == 1 && fread(&aux2Poc, sizeof(pocion),1,farchivo)>0)
        {
            if(strcmp(auxPoc->nombrePoc, aux2Poc.nombrePoc)== 0)
            {
                repetido=0;
            }
        }
    }
    return repetido;
}

///MOSTRAR SOLO EL NOMBRE DE POCIONES CREADAS
void mostrarPocionesAdmin(FILE* farchivo)
{
    system("cls");
    pocion auxPoc;
    printf("---Las pociones ya creadas son:\n");

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(fread(&auxPoc, sizeof(pocion), 1, farchivo)>0)
        {
            printf("---%s;", auxPoc.nombrePoc);
        }
    }
    printf("---\n-----------------------------------------------------------\n");
}

///ASIGNAR ID A LA POCION SEGUN LAS QUE YA ESTÉN CREADAS
void asignarIDPoc(pocion* creacionPoc,FILE* farchivo)
{
    pocion auxPoc;
    int ID=0;

    fseek(farchivo,0,SEEK_SET);
    if(farchivo)
    {
        while(fread(&auxPoc, sizeof(pocion),1,farchivo)>0)
        {
            ID++;
        }
    }
///LE ASIGNA UNA ID
    ID++;
    creacionPoc->idPocion=ID;
}


///MUESTRA PERSONAJES VALIDOS AL USER----------------------------------------------------------------------

void mostrarPersonajesUserAux(personaje auxP)
{
    printf("---Numero de personaje: %d\n",auxP.id);
    printf("---Nombre: %s\n", auxP.nombre);
    printf("---Vida: %.1f\n", auxP.vida);
    printf("---Energia: %d\n", auxP.energia);
    printf("---Armadura: %.1f\n", auxP.armadura);
    printf("---Danio Base:%d\n",auxP.danioBase);
    printf("---Arma: %s\n",auxP.stats.nombreArm);
    printf("\n----------------------------------------------\n");
}

///MUESTRA PERSONAJES VALIDOS AL USER
void mostrarPersonajesUser()
{
    personaje auxP;
    FILE* farchivo =fopen(rutaPersonaje, "rb");
    fseek(farchivo,0,SEEK_SET);


    if(farchivo != NULL)
    {
        while(fread(&auxP, sizeof(personaje), 1, farchivo)> 0)
        {
            if (auxP.id>=1 && auxP.estado ==1)
            {
                mostrarPersonajesUserAux(auxP);
            }
        }
        fclose(farchivo);
    }
}


///SELECCIÓN
void seleccionPersonaje(personaje* protagonista)
{
    personaje auxP;
    int cambio;

    mostrarPersonajesUser(rutaPersonaje);

    personajeSeleccionado(rutaPersonaje, &auxP);

    printf("---Que desea hacer?\n Oprima 1 para confirmar su seleccion, 2 para ver las estadisticas del arma o 3 para volver a elegir\n");
    fflush(stdin);
    scanf("%d", &cambio);

    switch(cambio)
    {
    case 1:
    {
        system("cls");
        printf("---------------------------------------------\n");
        printf("|||||||||||| %s Seleccionado Correctamente |||||||||||| \n",auxP.nombre);
        printf("---------------------------------------------\n");
        mostrar_jugador(auxP.id);
        *protagonista=auxP;
        printf("\n");
        system("pause");
        break;
    }

    case 2:
    {
        mostrarArmaUser(auxP);
        system("pause");
        system("cls");
        seleccionPersonaje(protagonista);
        break;
    }

    case 3:
    {
        seleccionPersonaje(protagonista);
        break;
    }

    default:
    {
        printf("---Error, ingrese nuevamente\n");
        seleccionPersonaje(protagonista);
        break;
    }
    }
}




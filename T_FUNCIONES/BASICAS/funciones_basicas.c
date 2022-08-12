#include "funciones_basicas.h"

///LOGUEO
usuario logueo()
{
    usuario nuevo,aux;
    int flag = 0,cambio;

    FILE* archi = fopen(rutaUsuario,"a+b");

    if (archi)
    {
        ///Cargamos los datos del usuario
        nuevo = cargaUsuario();

        ///Vemos si el usuario ya esta creado
        nuevo= usuarioCreado(aux,nuevo,&flag,archi);

        if(flag == 0)
        {
            ///Si no coincide con ninguno creamos uno
            nuevo = crearUsuario(aux,nuevo,archi);
        }

        fclose(archi);
    }

    printf("-Que desea hacer? 1 para iniciar el juego //2 para ir a configuracion usuario\n");
    fflush(stdin);
    scanf("%d",&cambio);

    if(cambio==2)
    {
        nuevo = menuUsuario(nuevo);
    }
    return nuevo;
}

usuario cargaUsuario()
{
    usuario nuevo;

    printf("-Usuario:");
    fflush(stdin);
    gets(nuevo.nombre);
    printf("-Clave:");
    fflush(stdin);
    gets(nuevo.contrasenia);

    return nuevo;
}

usuario usuarioCreado(usuario aux, usuario nuevo, int* flag, FILE* archi)
{
    while(fread(&aux,sizeof(usuario),1,archi) > 0 && (*flag) == 0)
    {
        while (strcmp(aux.nombre,nuevo.nombre) == 0 && strcmp(aux.contrasenia,nuevo.contrasenia) != 0)
        {
            printf("-La clave es incorrecta, intente nuevamente: ");
            fflush(stdin);
            gets(nuevo.contrasenia);

        }
        if (strcmp(aux.nombre,nuevo.nombre) == 0 && strcmp(aux.contrasenia,nuevo.contrasenia) == 0)
        {
            ///Comprobamos si es el administrador o no

            if (strcmpi(aux.nombre, "Scout") == 0 && strcmpi(aux.contrasenia, "Dungeons") == 0)
            {
                *flag = 2;
                printf("-Bienvenido jefe, otra vez con errores?, (chiste chiste, no me borres)\n");
                nuevo.id = 0;
                nuevo.tipo = 1;
            }
            else
            {
                printf("-Bienvenido de nuevo, %s \n",nuevo.nombre);
                *flag = 1;
                nuevo = aux;
            }
        }
    }

    return nuevo;
}

usuario crearUsuario(usuario aux, usuario nuevo, FILE* archi)
{
    nuevo.id = aux.id + 1;
    nuevo.tipo = 0;

    fwrite(&nuevo,sizeof(usuario),1,archi);

    printf("-Celebremos! Un nuevo usuario ha sido creado!\n");
    return nuevo;
}

//MENU USUARIO
usuario menuUsuario(usuario nuevo)
{
    int cambio;
    printf("-Bienvenido al Menu Usuario\n");
    printf("-Oprima 1 para cambiar usuario o 2 para cambiar contrasenia\n");
    fflush(stdin);
    scanf("%d",&cambio);

    if(cambio==1)
    {
        nuevo=cambioUser(nuevo);
    }
    if(cambio==2)
    {
        nuevo=cambioContra(nuevo);
    }
    return nuevo;
}

///CAMBIO USUARIO
usuario cambioUser(usuario nuevo)
{
    int flag=0;
    usuario aux;
    FILE* archi = fopen(rutaUsuario,"r+b");
    if(archi)
    {

        ///BUSCAMOS LA POSICION DEL USUARIO
        int UserEncontrado=busquedaUser(nuevo.nombre,archi);

        ///CAMBIAMOS EL NOMBRE DEL USUARIO
        while(flag==0)
        {
            printf("-A que user quiere cambiar a:%s\n",nuevo.nombre);
            fflush(stdin);
            gets(aux.nombre);
            flag=UserRepetido(aux.nombre,archi);

            if(flag==0)
            {
                printf("-ERROR, USUARIO REPETIDO\n");
            }
        }

        ///PASAMOS EL NUEVO NOMBRE AL USUARIO
        strcpy(nuevo.nombre,aux.nombre);

        ///LO ESCRIBIMOS EN EL ARCHIVO
        fseek(archi, sizeof(usuario)* (UserEncontrado -1),SEEK_SET);
        fwrite(&nuevo, sizeof(usuario), 1, archi);

        fclose(archi);
    }
    printf("-Usuario cambiado correctamente\n");

    return nuevo;
}

usuario cambioContra(usuario nuevo)
{
    FILE* archi = fopen(rutaUsuario,"r+b");
    if(archi)
    {

        ///BUSCAMOS LA POSICION DEL USUARIO
        int UserEncontrado=busquedaUser(nuevo.nombre,archi);

        ///CAMBIAMOS EL LA CONTRASEÑA
        printf("-A que contrasenia quiere cambiar, teniendo como anterior:%s\n",nuevo.contrasenia);
        fflush(stdin);
        gets(nuevo.contrasenia);


        ///LO ESCRIBIMOS EN EL ARCHIVO
        fseek(archi, sizeof(usuario)* (UserEncontrado -1),SEEK_SET);
        fwrite(&nuevo, sizeof(usuario), 1, archi);

        fclose(archi);
    }
    printf("-Contrasenia cambiada correctamente\n");
    return nuevo;
}

///BUSQUEDA USER/ CONTRASEÑA
int busquedaUser(char nombre[], FILE* archi)
{
    usuario aux;
    int UserEncontrado=0,flag=0;

    while(flag ==0 && fread(&aux, sizeof(usuario), 1, archi)> 0)
    {

        if (strcmp(aux.nombre, nombre)== 0)
        {
            flag=1;
        }
    }

    if(strcmp(aux.nombre, nombre)== 0)
    {
        fseek(archi,0,SEEK_CUR);
        UserEncontrado = ftell(archi) / sizeof(usuario);
    }

    return UserEncontrado;
}

///VERIFICAR QUE EL USER NO SE REPITA
int UserRepetido(char nombre[],FILE* archi)
{
    int flag=1;

    fseek(archi,0,SEEK_SET);
    usuario aux;

    if(archi != NULL)
    {

        while(flag == 1 && fread(&aux, sizeof(usuario),1,archi)>0)
        {
            if(strcmp(nombre, aux.nombre)== 0)
            {
                flag=0;
            }
        }

    }
    return flag;
}


void mostrarArmaUser(personaje auxP)
{
    ///MUESTRA EL ARMA QUE TENGA EL USER
    printf("---Nombre: %s\n", auxP.stats.nombreArm);
    printf("---Danio fisico: %d\n", auxP.stats.danioF);
    printf("---Danio magico: %d\n", auxP.stats.danioM);
    printf("---Critico: %.0f%%\n", auxP.stats.critico);
    printf("---Efecto: %d\n", auxP.stats.efecto);
    printf("----------------------------------------------\n");
}

void leerEnemigos(personaje* enemigo, int numEnemigo)
{
    FILE* farchivo = fopen(rutaPersonaje, "rb");

    if(farchivo)
    {

        while(fread((enemigo), sizeof(personaje),1,farchivo)>0 && numEnemigo != enemigo->id)
        {

        }
        fclose(farchivo);
    }
    printf("%s",enemigo->nombre);
}



//SELECCIONA PERSONAJE
void personajeSeleccionado(char nombrefarchivovo[], personaje* auxP)
{
    ///SELECCION SEGUN SU ID
    printf("---Elija el numero de personaje que deseas seleccionar\n");
    fflush(stdin);
    scanf("%d", &auxP->id);


    int flag= busquedaPersonajeUser(auxP);

    if (flag==0)
    {
        printf("---Error, personaje no encontrado\n");
        personajeSeleccionado(rutaPersonaje, auxP);
    }
}

//BUSCA PERSONAJE SEGUN LA ID
int busquedaPersonajeUser(personaje* auxP)
{
    personaje aux2P;
    int flag=0;
    FILE* farchivo = fopen(rutaPersonaje,"rb");

    if(farchivo!=NULL)
    {
        while(fread(&aux2P, sizeof(personaje), 1, farchivo)> 0 && flag == 0)
        {
            if (aux2P.id== auxP->id)
            {
                flag=1;
                *auxP=aux2P;
            }
        }

        fclose(farchivo);
    }
    return flag;
}


///FUNCIONES BASICAS DEL MANEJO DE LSL (INVENTARIO)

//NODO BASE

nodo_base_inventario * inic_lista_base_inventario()
{
    return NULL;
}

nodo_base_inventario * crea_nodo_base_inventario(arma dato_arma)
{
    nodo_base_inventario*nuevo=(nodo_base_inventario*)malloc(sizeof(nodo_base_inventario));
    nuevo->anterior=inic_lista_base_inventario();
    nuevo->siguiente=inic_lista_base_inventario();
    nuevo->arma_dato=dato_arma;

    return nuevo;
}

nodo_base_inventario * agregar_nodo_base_inventario_principio(nodo_base_inventario * lista,nodo_base_inventario *nuevo)
{
    if(lista==NULL)
        lista=nuevo;
    else
    {
        nuevo->siguiente=lista;
        lista->anterior=nuevo;
        lista=nuevo;
    }

    return lista;
}


//CELDAS

int buscarId (celda_inventario arreglo[], int val, arma buscada) ///devuelve la pos del arreglo donde encontro el arma o hechizo (0 armas / 1 hechizos)
{
    int rta = -1;
    int i = 0;

    while(i<val && rta == -1)
    {
        if(arreglo[i].dato->arma_dato.id == buscada.id)
        {
            rta = i;
        }
        i++;      // devolvemos la rta asi que no pasa nada si se suma un 1 de mas a la i al final del bucle
    }
    return rta;
}

/*int buscar_tipo(celda_inventario arreglo[],int val,int tipo)
{
    int pos=-1;
    int i=0;

    while((i<val) && (pos==-1))
    {
        if(arreglo[i]==tipo)
            pos=i;

        i++;
    }

    return pos;
}
void alta(celda_inventario arreglo[],int validos,arma dato_arma,int tipo)
{
    nodo_base_inventario*nuevo;
    nuevo=crea_nodo_base_inventario(dato_arma);

    int pos=buscar_tipo(arreglo,validos,tipo);

    if(pos==-1)
    {
        agregar_celda(tipo,validos,arreglo);
        pos=validos-1;
    }

    arreglo[pos].dato=agregar_nodo_base_inventario_principio(arreglo[pos].dato,nuevo);
}*/

void crear_inventario(celda_inventario arreglo[],arma dato_arma,arma hechizo)
{
    nodo_base_inventario*nuevo_arma;
    nodo_base_inventario*nuevo_hechizo;

    nuevo_arma=crea_nodo_base_inventario(dato_arma);
    arreglo[0].dato=inic_lista_base_inventario();
    arreglo[0].dato=agregar_nodo_base_inventario_principio(arreglo[0].dato,nuevo_arma);

    nuevo_hechizo=crea_nodo_base_inventario(hechizo);
    arreglo[1].dato=inic_lista_base_inventario();
    arreglo[1].dato=agregar_nodo_base_inventario_principio(arreglo[1].dato,nuevo_hechizo);
}

void ingresa_arma_inventario(celda_inventario arreglo[],arma dato,int tipo)
{
    if(tipo==1 || tipo==0)
    {
        nodo_base_inventario*aux=crea_nodo_base_inventario(dato);
        arreglo[tipo].dato=agregar_nodo_base_inventario_principio(arreglo[tipo].dato,aux);
    }
}

///ASIGANAR HECHIZOS Y POCIONES BÁSICAS
void asignarPrincipales(personaje* protagonista)
{

    ///Asigna Arma cargada
    asignarPocionesBasicas(protagonista);
    asignarHechizosBasicos(protagonista);
}

void asignarPocionesBasicas(personaje* protagonista)
{
    pocion auxPoc;
    nodo_pocion* aux= inic_lista_pociones();
    protagonista->pociones=inic_lista_pociones();
    FILE* farchivo=fopen(rutaPociones,"rb");
    fseek(farchivo,0,SEEK_SET);

    if(farchivo)
    {
        while((fread(&auxPoc,sizeof(pocion),1,farchivo)>0) && (auxPoc.idPocion!=5))
              {
            aux=crea_nodo_pocion(auxPoc);
            protagonista->pociones=agregar_al_final_pocion(protagonista->pociones,aux);
              }
        fclose(farchivo);
    }
}

void asignarHechizosBasicos(personaje* protagonista)
{
    arma auxA;
    arma auxA2;
    FILE* farchivo=fopen(rutaArmas,"rb");
    fseek(farchivo,0,SEEK_SET);

    if(farchivo)
    {
        while((fread(&auxA,sizeof(arma),1,farchivo)>0) &&(auxA.id!=10))
              {
                  if(auxA.id==9)
                  {
                      auxA2=auxA;
                  }
              }
        fclose(farchivo);
    }

    asignarSegunID(auxA,auxA2,protagonista);
}

void asignarSegunID(arma auxA,arma auxA2,personaje* protagonista)
{
    ///AUXA = 10 = FUEGO
    ///AUXA2 = 9 = HIELO
    if(protagonista->id==1)
    {
    crear_inventario(protagonista->inventario,protagonista->stats,auxA);
    }
    else if(protagonista->id==2)
    {
    crear_inventario(protagonista->inventario,protagonista->stats,auxA2);
    }
    else
    {
        crear_inventario(protagonista->inventario,protagonista->stats,auxA2);
        ingresa_arma_inventario(protagonista->inventario,auxA,auxA.tipo);
    }
}

//DAR ITEM RANDOM
//ARMAS
int busca_id_max_arma_archivo()
{
    int max=0;
    arma auxA;
    FILE* farchi=fopen(rutaArmas,"rb");
    fseek(farchi,0,SEEK_SET);
    if(farchi)
    {

        while(fread(&auxA,sizeof(arma),1,farchi)>0)
        {
            if(max<auxA.id)
            {
                max=auxA.id;
            }
        }

        fclose(farchi);
    }

    return max;
}

arma busqueda_arma_archivo(int id)
{
    arma auxA;
    int flag=0;

    FILE*punteroarchi=fopen(rutaArmas,"rb");
    fseek(punteroarchi,0,SEEK_SET);

    if(punteroarchi)
    {
        while( flag == 0 && fread(&auxA, sizeof(arma), 1, punteroarchi)> 0 )
        {
            if (auxA.id==id)
            {
                flag=1;
            }
        }
        fclose(punteroarchi);
    }

    return auxA;
}

arma dar_arma_random()
{
    int id_max=busca_id_max_arma_archivo();
    arma nueva;
    srand(time(NULL));

    int id_rand=rand()%id_max;

    nueva=busqueda_arma_archivo(id_rand);
    return nueva;
}

bool verifica_id_inventario(nodo_base_inventario * lista,int id)
{
    int flag=false;

    while(!flag && lista!=NULL)
    {
        if(lista->arma_dato.id==id )
            flag=true;

        lista=lista->siguiente;
    }

    return flag;
}

arma arma_random(personaje * jugador)
{
    int id_max=busca_id_max_arma_archivo();
    int flag=0;

    arma nueva;
    nueva=dar_arma_random(id_max);

    while(flag==0)
    {
        if(!verifica_id_inventario(jugador->inventario[0].dato,nueva.id))
        {
            flag=1;
        }
        else if(!verifica_id_inventario(jugador->inventario[1].dato,nueva.id))
        {
            flag=1;
        }
        else
        {
            nueva=dar_arma_random(id_max);
        }
    }
    return nueva;
}

//POCIONES
int busca_id_max_pocion_archivo()
{
    int max=0;
    pocion auxA;
    FILE* farchi=fopen(rutaPociones,"rb");
    fseek(farchi,0,SEEK_SET);
    if(farchi)
    {
        while(fread(&auxA,sizeof(pocion),1,farchi)>0)
        {
            if(max<auxA.idPocion)
            {
                max=auxA.idPocion;
            }
        }

        fclose(farchi);
    }

    return max;
}

pocion busqueda_pocion_archivo(int id)
{
    pocion auxA;
    int flag=0;

    FILE*punteroarchi=fopen(rutaPociones,"rb");
    fseek(punteroarchi,0,SEEK_SET);


    if(punteroarchi)
    {
        while( flag == 0 && fread(&auxA, sizeof(pocion), 1, punteroarchi)> 0 )
        {
            if (auxA.idTipo==id)
            {
                flag=1;
            }
        }
        fclose(punteroarchi);
    }

    return auxA;
}

nodo_pocion * pocion_random()
{
    int id_max=busca_id_max_pocion_archivo();

    pocion nueva;

    srand(time(NULL));

    int id_nueva=rand()%id_max;

    nueva=busqueda_pocion_archivo(id_nueva);

    nodo_pocion*nuevo_nodo=crea_nodo_pocion(nueva);

    return nuevo_nodo;
}


///POCIONES
nodo_pocion * inic_lista_pociones()
{
    return NULL;
}

nodo_pocion * crea_nodo_pocion(pocion dato)
{
    nodo_pocion*nuevo=(nodo_pocion*)malloc(sizeof(nodo_pocion));
    nuevo->anterior=NULL;
    nuevo->siguiente=NULL;
    nuevo->dato=dato;

    return nuevo;
}

nodo_pocion * buscar_ultimo_pocion(nodo_pocion * lista)
{
    nodo_pocion * aux=lista;

    if (aux!=NULL)
    {
        while(aux->siguiente!=NULL)
            aux=aux->siguiente;
    }
    return aux;
}

nodo_pocion * agregar_al_final_pocion(nodo_pocion * lista,nodo_pocion*nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodo_pocion*ultimo=buscar_ultimo_pocion(lista);
        ultimo->siguiente=nuevo;
        nuevo->anterior=ultimo;
    }
    return lista;
}


nodo_pocion * buscar_pocion(nodo_pocion * lista,int id)
{
    nodo_pocion * aux=lista;
    nodo_pocion * rta=NULL;

    int flag=0;

    while(aux!=NULL && flag==0)
    {
        if(aux->dato.idPocion==id)
        {
            rta=aux;
            flag=1;
        }
        aux=aux->siguiente;
    }
    return rta;
}

int cuenta_pociones(nodo_pocion * lista)
{
    int contador=0;

    if(lista!=NULL)
    {
        while(lista!=NULL)
        {
            contador++;
            lista=lista->siguiente;
        }
    }


    return contador;
}

nodo_pocion * borrar_pocion(nodo_pocion * lista,int id)
{
    int contador=0;
    nodo_pocion*aux=lista;
    nodo_pocion*ante;

    if(aux!=NULL)
    {
        if(aux->dato.idPocion!=id)
        {
            while((aux->dato.idPocion!=id)&&(aux!=NULL))
            {
                aux=aux->siguiente;
            }
            ante=aux->anterior;
            ante->siguiente=aux->siguiente;
            free(aux);
        }
        else
        {
            lista=aux->siguiente;
            lista->anterior=NULL;
            free(aux);
        }
    }

contador = cuenta_pociones(lista);
if(contador==0)
{
    lista =NULL;
}
    return lista;
}

nodo_pocion * borrar_pociones(nodo_pocion * lista)
{
    nodo_pocion*borrar;

    while(lista!=NULL)
    {
        borrar=lista;
        lista=lista->siguiente;
        free(borrar);
    }
    return lista;
}


///IA

nodo_IA * inic_arbol_IA()
{
    return NULL;
}

nodo_IA * crea_nodo_ia(int id,int rta)
{
    nodo_IA*nuevo=(nodo_IA*)malloc(sizeof(nodo_IA));

    nuevo->derecha=inic_arbol_IA();
    nuevo->izquierda=inic_arbol_IA();
    nuevo->info.id=id;
    nuevo->info.respuesta=rta;

    return nuevo;
}

nodo_IA*insertar(nodo_IA*arbol,nodo_IA*nuevo)
{
    if(arbol==NULL)
        arbol=nuevo;
    else
    {
        if(nuevo->info.id >arbol->info.id)
            arbol->derecha=insertar(arbol->derecha,nuevo);
        else if(nuevo->info.id < arbol->info.id)
            arbol->izquierda=insertar(arbol->izquierda,nuevo);
    }

    return arbol;
}

nodo_IA* leer_arbol_IA_archivo(nodo_IA*arbol)
{
    FILE*punteroarchi=fopen(rutaIA,"rb");
    dato_IA dato;
    nodo_IA*nuevo=inic_arbol_IA();

    if(punteroarchi!=NULL)
    {
        while(fread(&dato,sizeof(dato_IA),1,punteroarchi)>0)
        {
            nuevo=crea_nodo_ia(dato.id,dato.respuesta);
            arbol=insertar(arbol,nuevo);
        }
        fclose(punteroarchi);

    }
    else
    {
        printf("-\n -ERROR:ARCHIVO NO EXISTE \n");
    }

    return arbol;
}

int analiza_estado_combate_IA(personaje jugador,personaje enemigo)///ARREGLAR
{
    int id=0;
    srand(time(NULL));

    arma ataque_jugador=jugador.stats;
    arma ataque_enemigo=enemigo.stats;


    if(jugador.vida<=ataque_enemigo.danioF + enemigo.danioBase || jugador.vida<=ataque_enemigo.danioM + enemigo.danioBase)
    {
        id=2;
    }
    else if((enemigo.vida <= ataque_jugador.danioF + jugador.danioBase || enemigo.vida<=ataque_jugador.danioM + jugador.danioBase))
    {
        id=0;
    }
    else
    {
        if(enemigo.vida<=jugador.vida)
        {
            id=4;
        }
        else
        {
            id=1;
        }
    }

    return id;
}

int busca_respuesta_arbol_IA(nodo_IA*arbol,int id)
{
    int respuesta=-1;

    if(arbol!=NULL)
    {
        if((id)==(arbol->info.id))
        {
            respuesta=arbol->info.respuesta;
        }
        else
        {
            if((id)>(arbol->info.id))
            {
                respuesta=busca_respuesta_arbol_IA(arbol->derecha,id);
            }
            else if((id)<(arbol->info.id))
            {
                respuesta=busca_respuesta_arbol_IA(arbol->izquierda,id);
            }
        }
    }

    return respuesta;
}

/*
void mostrar_inorder(nodo_IA*arbol)
{
    if(arbol!=NULL)
    {
        mostrar_inorder(arbol->izquierda);
        printf("-\n\n -ID: %d",arbol->info.id);
        printf("-\n -RTA: %d",arbol->info.respuesta);
        mostrar_inorder(arbol->derecha);
    }
}*/








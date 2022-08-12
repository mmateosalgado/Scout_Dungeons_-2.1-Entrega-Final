#include "combate.h"

///PRINCIPAL
void combate(personaje*jugador,personaje*enemigo,int turno)
{
    int critico=0;
    int selector;
    char control;
    if(jugador->vida>0 && enemigo->vida>0)
    {
invalido:
        menu_batalla(*jugador,*enemigo,turno);
        menu_batalla_opciones(jugador->stats.tipo);

inicio:

        printf("\n  -Que accion deseas tomar? : ");
        fflush(stdin);
        scanf("%d",&selector);
        switch(selector)
        {
        case 1:
            if(jugador->stats.tipo == 0) /// si es un arma
            {
                if(jugador->energia>=20)
                {
                    critico=select_ataque(jugador,enemigo);
                    jugador->energia-=20;
                }
                else
                {
                    printf("\n  -No tienes suficiente energia, elige otra opcion: ");
                    system("pause");
                    goto inicio;
                }
            }
            else if (jugador->stats.tipo == 1)///SI ES HECHIZO
            {
                if(jugador->energia>=100)
                {
                    critico=select_ataque(jugador,enemigo);
                    jugador->energia-=100;
                }
                else
                {
                    printf("\n  -No tienes suficiente energia, elige otra opcion: ");
                    system("pause");
                    goto inicio;
                }
            }
            break;
        case 2:
            acceso_inventario(jugador,enemigo,turno);
            break;
        case 3:
            defender_y_cargar_energia(jugador);
            break;
        case 4:
            printf("\n  -Seguro que quieres abandonar la partida? s/n : ");
            fflush(stdin);
            scanf ("%c",&control);

            if(control == 's' || control=='S')
                jugador->vida=0;
            else
                goto inicio;
            break;

        default:
            goto invalido;
        }

        system("pause");
        system("cls");

        menu_batalla(*jugador,*enemigo,turno);
        menu_batalla_opciones(jugador->stats.tipo);

        if(enemigo->vida>0 && jugador->vida>0)
        {
            aplica_stun_enemigo(jugador,enemigo,turno,critico);

            aplica_veneno_enemigo(enemigo);

            aplica_veneno_jugador(jugador);

            system("pause");
            combate(jugador,enemigo,turno);
        }
    }
    else if(enemigo->vida>0)
    {
        pantalla_muerte();
        system("pause");
        //funcion_principal();
    }
    else
    {
        printf("MURIO");
    }
}

///SECUNDARIAS
void acceso_inventario(personaje* jugador, personaje* enemigo,int turno)
{
    int selector;
    int id_pocion;
    int id_arma;
    int tipo_arma;
    nodo_pocion*aux;
    pocion pocion_seleccionada;

inicio:
    system("cls");

    menuInventario();

    printf("\n  -Que accion deseas tomar? : ");
    fflush(stdin);
    scanf("%d",&selector);

    switch(selector)
    {
    case 1:
        muestra_pociones(jugador->pociones);

        printf("\n -Ingrese el ID de la pocion a usar : ");
        fflush(stdin);
        scanf("%d",&id_pocion);

        aux=buscar_pocion(jugador->pociones,id_pocion);


        if(aux!=NULL)
        {
            pocion_seleccionada=aux->dato;
            aplicar_pocion(jugador,pocion_seleccionada);
            jugador->pociones=borrar_pocion(jugador->pociones,pocion_seleccionada.idPocion);
        }
        else
        {
            printf("\n -ERROR:ID DE POCION INGRESADA NO VALIDA \n");
            system("pause");
            goto inicio;
        }

        break;
    case 2:
        muestra_armas_hechizos(*jugador);

        printf("\n -Desea equipar un arma (0) o un hechizo (1)? : ");
        fflush(stdin);
        scanf("%d",&tipo_arma);

        if(tipo_arma== 0 || tipo_arma==1)
        {
            printf("\n\n -Ingrese el ID del arma a usar: ");
            fflush(stdin);
            scanf("%d",&id_arma);
            cambiar_arma(jugador,tipo_arma,id_arma);
            //combate(jugador,enemigo,turno);
        }
        else
        {
            printf("\n -ERROR: INGRESE UN VALOR VALIDO! \n");
            goto inicio;
        }

        break;
    case 3:
       // combate(jugador,enemigo,turno);
        break;
    default:
        printf("\n -ERROR: ACCION NO EXITE! \n");
        goto inicio;
    }
}


void defender_y_cargar_energia(personaje * protagonista)
{
    protagonista->energia = protagonista->energia + 50;
    protagonista->armadura = protagonista->armadura + 2.5;

    if(protagonista->id >0)
        muestra_defender_y_cargar_energia();
    else
        muestra_defender_y_cargar_energia_enemigo();
}

int select_ataque(personaje*atacante,personaje*defensor)
{
    int critico=0;

    if(atacante->stats.danioF==0)
    {
        critico=ataque_magico(atacante,defensor);
        muestra_efecto_hechizo(atacante->stats.id);
    }
    else
    {
        critico=ataque_fisico(atacante,defensor);
    }

    return critico;
}

int ataque_fisico(personaje * atacante, personaje * defensor)
{
    int critico=0;
    int armadura = (int) atacante->stats.danioF * defensor->armadura / 100; ///Valor de la armadura en base al danio recibido

    srand(time(NULL));

    if(rand()%100 <= atacante->stats.critico) ///Critico
    {
        defensor->vida = (defensor->vida) - ((atacante->stats.danioF+atacante->danioBase) * 2);
        if(atacante->id>0)
            muestra_ataque_fisico_critico(atacante);
        else
            muestra_ataque_fisico_critico_enemigo(atacante);

        critico=1;
    }
    else ///Basico
    {
        defensor->vida = (defensor->vida + armadura) - ((atacante->stats.danioF)+atacante->danioBase);

        if(atacante->id>0)
            muestra_ataque_fisico_basico(atacante,defensor->armadura);
        else
            muestra_ataque_fisico_basico_enemigo(atacante,defensor->armadura);
    }
    return critico;
}

int ataque_magico(personaje * atacante, personaje * defensor)
{
    int critico=0;
    int armadura = (int) atacante->stats.danioM * defensor->armadura / 100; ///Valor de la armadura en base al danio recibido
    srand(time(NULL));

    if(rand()%100 <= atacante->stats.critico) ///Critico
    {
        defensor->vida = (defensor->vida) - ((atacante->stats.danioM + atacante->danioBase) * 2);
        aplicar_ataque_con_efecto_hechizo(atacante,defensor);
        muestra_ataque_magico_critico(atacante);
        critico=1;
    }
    else
    {
        defensor->vida = (defensor->vida + armadura) - ((atacante->stats.danioM)+atacante->danioBase);
        aplicar_ataque_con_efecto_hechizo(atacante,defensor);
        muestra_ataque_magico_basico(atacante,defensor->armadura);
    }

    return critico;
}

///TERCIARIAS

arma busca_arma(nodo_base_inventario*lista,int id)
{
    int flag=false;
    arma dato;

    while(!flag && lista!=NULL)
    {
        if(lista->arma_dato.id==id)
        {
            flag=true;
            dato=lista->arma_dato;
        }

        lista=lista->siguiente;
    }

    return dato;
}

void cambiar_arma(personaje * jugador,int tipo,int id)
{
    bool verificacion=verifica_id_inventario(jugador->inventario[tipo].dato,id);

    if(verificacion)
    {
        arma dato=busca_arma(jugador->inventario[tipo].dato,id);
        jugador->stats=dato;
    }
    else
    {
        printf("\n -CUIDADO! : ID DE LA ARMA INGRESADA NO EXISTE !! \n");
    }
}

void aplicar_pocion(personaje * jugador,pocion pocion_seleccionada)
{
    int id_tipo=pocion_seleccionada.idTipo;

    switch(id_tipo)
    {
    case 1:
        jugador->vida=jugador->vida+pocion_seleccionada.aumento;
        break;
    case 2:
        jugador->energia=jugador->energia+pocion_seleccionada.aumento;
        break;
    case 3:
        jugador->danioBase=jugador->danioBase + pocion_seleccionada.aumento;
        break;
    case 4:
        if(jugador->cantidad_turnos_veneno==0)
            printf("\n -ATENCION! : No estabas envenenado,gastas la pocion y no tuvo efecto! \n");
        else
        {
            printf("\n -Ya no te encuentras ");
            printf("\033[0;33m");
            printf(" ENVENENDADO! \n");
            printf("\033[1;37m");
            jugador->cantidad_turnos_veneno=0;
        }
        break;
    default:
        printf("\n -ERROR:ID DE POCION NO VALIDA \n");
    }
}

///FUNCIONES ATAQUES ESPECIALES
void aplicar_ataque_con_efecto_hechizo(personaje * atacante, personaje * defensor)
{
    int efecto=atacante->stats.efecto;

    if(efecto==1)
    {
        ataque_stun(atacante,defensor);
    }
    else if(efecto==2)
    {
        ataque_dano_const(atacante,defensor);
    }
}

void ataque_dano_const(personaje * atacante,personaje * atacado)
{
    if(atacado->cantidad_turnos_veneno==0)
    {

        if(atacante->id>0)
        {
            atacado->cantidad_turnos_veneno=atacante->stats.cantidad_turnos_efecto;
            muestra_ataque_veneno(*atacado);
        }
        else
        {
            atacado->cantidad_turnos_veneno=10;
            muestra_ataque_veneno_IA(*atacado);
        }
    }
    else
    {
        if(atacante->id>0)
            printf("\n -ATENCION! : EL ENEMIGO YA ESTA ENVENENADO, EL HECHIZO NO TIENE EFECTO! \n");
        else
            printf("\n -ATENCION! : EL JUGADOR YA ESTA ENVENENADO, EL HECHIZO NO TIENE EFECTO! \n");
    }
}

void ataque_stun(personaje * jugador, personaje * enemigo)
{
    if(enemigo->cantidad_turnos_stun==0)
    {
        enemigo->cantidad_turnos_stun=jugador->stats.cantidad_turnos_efecto;
    }
    else
        printf("\n -ATENCION! : EL ENEMIGO YA ESTA ATURDIDO, EL HECHIZO NO TIENE EFECTO! \n");
}

void aplica_stun_enemigo(personaje * jugador,personaje * enemigo,int turno,int critico)
{
    if(enemigo->cantidad_turnos_stun==0)
    {
        combate_IA(enemigo,jugador,turno++,critico);
    }
    else
    {
        enemigo->cantidad_turnos_stun--;
        printf("\n -%s SIGUE ATURDIDO! \n",enemigo->nombre);
        if(enemigo->cantidad_turnos_stun==0)
            printf("\n -%s SE HA DESPERTADO! \n",enemigo->nombre);
    }
}

void aplica_veneno_enemigo(personaje * enemigo)
{
    if(enemigo->cantidad_turnos_veneno>0)
    {
        enemigo->vida=enemigo->vida-DANO_CONSTANTE;
        muestra_sufre_veneno_IA(*enemigo);
        enemigo->cantidad_turnos_veneno--;
    }
}

void aplica_veneno_jugador(personaje * jugador)
{
    if(jugador->cantidad_turnos_veneno>0)
    {
        jugador->vida=jugador->vida-DANO_CONSTANTE;
        muestra_sufre_veneno();
        jugador->cantidad_turnos_veneno--;
    }
}

///IA

void combate_IA(personaje*IA, personaje*jugador,int turno,int flag_critico)
{
    srand(time(NULL));
    int probabilidad=rand()%100;

    printf("\n");
    printf(" -Turno del %s :\n",IA->nombre);


    if(flag_critico==0)
    {
        if(probabilidad < 45)
        {
            ataque_fisico(IA,jugador);
        }
        else if(probabilidad>=45 && probabilidad<60)
        {
            ataque_dano_const(IA,jugador);
        }
        else
        {
            accion_IA(IA,jugador);
        }
    }
    else
    {
        IA->vida=IA->vida+250;
        muestra_cura_IA(*IA);
    }
}

void accion_IA(personaje*IA,personaje*jugador)
{
    int situacion=analiza_estado_combate_IA(*jugador,*IA);

    nodo_IA*arbol=inic_arbol_IA();

    arbol=leer_arbol_IA_archivo(arbol);
    int respuesta=busca_respuesta_arbol_IA(arbol,situacion);

    switch(respuesta)
    {
    case 0:
        ataque_fisico(IA,jugador);
        break;
    case 1:
        defender_y_cargar_energia(IA);
        break;
    case 2:
        IA->vida=IA->vida+250;
        muestra_cura_IA(*IA);
        break;
    case 3:
        IA->danioBase=IA->danioBase+30;
        muestra_boost_danio_enemigo(*IA);
        break;
    default:
        printf("\n -ERROR FATAL: WOW! TODO ESTA ROTO! \n");
        printf("\n -FELICITACION! NO TENIAMOS IDEA DE QUE ERA POSIBLE HACER ESTO");
        printf("\n -EL ARBOL DE IA ESTA MAL CARGADO");
        ///OJALA NUNCA PASE
    }


}


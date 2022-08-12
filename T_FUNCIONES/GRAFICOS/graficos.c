#include "graficos.h"


///HISTORIA

void muestra_historia(int id,usuario nombre,personaje clase)
{
    switch(id)
    {
    case 1:
        historia_1(nombre,clase);
        break;
    case 2:
        historia_2(nombre,clase);
        break;
    case 3:
        historia_3(nombre,clase);
        break;
    case 4:
        historia_4(nombre,clase);
        break;
    case 5:
        historia_5(nombre,clase);
        break;
    default:
        printf("\n -ERROR : ID DE HISTORIA NO ES VALIDA \n");
    }
}

void historia_1(usuario nombre,personaje clase)
{
    system("cls");
    mostrar_castillo();
    printf("\n\n\n La historia comenz\xA2 en las tierras de Inti-Kaia, donde la gente gozaba de paz\n luego de siglos de lucha contra diferentes criaturas que acechaban la ciudad.\n Hace ya muchos siglos los Caminantes, salvadores de la humanidad, se hab%can encargado de ellas\n montando las batallas m\xA0s \x82picas jam\xA0s vistas en la faz de la tierra.\n Sin embargo, la verdadera historia reci\x82n comenzaba.\n",161);
    printf("\n");
    system("pause");

    system("cls");
    mostrar_castillo();
    printf("\n\n\n Desde muy lejos un viajero llegaba a Inti-Kaia , su nombre era %s, un %s con experiencia.\n Solo ten%ca unas pocas monedas y hab%ca viajado a Inti-Kaia para cumplir un encargo del rey.\n",nombre.nombre,clase.nombre,161,161);
    printf("\n");
    system("pause");

    system("cls");
    mostrar_castillo();
    printf("\n\n\n Pero antes de eso decidi\xA2 tomar una cerveza en una conocida taberna de la ciudad.\n Donde tropez\xA2 con un enano derramando toda la cerveza en su cara.\n El enano enojado arremeti\xA2 contra %s y dio lugar a una batalla.\n", nombre.nombre);
    printf("\n");
    system("pause");
}

void historia_2(usuario nombre,personaje clase)
{
    system("cls");
    mostrar_puerta_cementerio();
    printf(" \n Pero primero el gran %s deb%ca pasar por el cementerio de los abandonados.\n",nombre.nombre,161);
    printf(" Al entrar, la niebla consum%ca todo,casi no se pod%ca ver.\n",161,161);
    printf(" Para mala suerte de %s, se empezaron a escuchar unos susurros provenientes del piso.\n",clase.nombre);
    printf(" \"Ayuda, ayuda, nos est%c controlando.\" \n\n",160);
    system("pause");
    system("cls");
    mostrar_puerta_cementerio();
    printf(" El joven %s no comprend%ca la situaci%cn.\n",nombre.nombre,161,162);
    printf(" Hasta que desde una vieja l%cpida, un caballero esqueleto comenz%c a levantarse.\n",160,162);
    system("pause");
}

void historia_3(usuario nombre,personaje clase)
{
    system("cls");
    mostrar_puerta_cementerio();
    printf("\n Al vencerlo, el esqueleto le agradeci%c, pues ya era libre. Pero todav%ca la pelea no hab%ca conclu%Cdo.\n",162,161,161,161);
    printf("\n Del esqueleto se desprendi%c un esp%critu maligno, el cual reclamaba el alma de nuestro h%croe.\n",162,161,130);
    printf("\n Era conocido por todas las personas de Inti Kaia, y no era otra que \"La Parca\".\n\n");
    system("pause");
}

void historia_4(usuario nombre,personaje clase)
{
    system("cls");
    mostrar_castillo();
    printf("\n\n\n El enano qued\xA2 inconsciente y %s decidi\xA2 partir hacia el castillo del rey para hablar acerca de su recado.\n", nombre.nombre);
    printf("\n");
    system("pause");

    system("cls");
    mostrar_castillo();
    printf("\n\n\n Al entrar a las afueras del castillo se top\xA2 con un desastre, sangre y tripas esparcidas por doquier.\n Decidido a averiguar lo sucedido, el %s comenz\xA2 a seguir un rastro de sangre y plumas que rodeaba el castillo\n y conduc%ca al patio trasero del mismo.\n",clase.nombre,161);
    printf("\n");
    system("pause");

    system("cls");
    mostrar_castillo();
    printf("\n\n\n All\xA1 encontr\xA2 un grifo enfurecido que  estaba a punto de devorar a algunos de los hombres del castillo.\n El grifo era una de las bestias del rey pero se hab%ca salido de control.\n Era el deber de %s detenerlo.\n",161,nombre.nombre);
    printf("\n");
    system("pause");
}

void historia_5(usuario nombre,personaje clase)
{
    system("cls");
    mostrar_templo();
    printf("\n\n\n Antes de asestar el golpe final contra el grifo\n este con sus \xA3ltimas energ%cas desplego sus alas para huir del castillo.\n Al llegar el rey a la terrible escena\n vio la gran masacre y solo se encontraba all\xA1 el joven %s rodeado de cad\xA0veres.\n\n",161, clase.nombre);
    system("pause");

    system("cls");
    mostrar_templo();
    printf("\n\n\n El rey bien llamado \"El rey loco\" no supo darle otra explicaci\xA2n al suceso\n m\xA0s que acusar a %s de asesino y decidi\xA2 condenarlo a muerte. \n\n", nombre.nombre);
    system("pause");

    system("cls");
    mostrar_templo();
    printf("\n\n\n El rey loco no sab%ca lo complicado que iba a ser atrapar al famoso %s\n que era uno de los 3 grandes Caminantes que hab%can salvado a la humanidad en otros tiempos.\n Por lo que en un ataque de rabia decidi\xA2 liberar al \xA3ltimo drag\xA2n que hab%ca sido mantenido en secreto en los  calabozos de la ciudad durante d%ccadas. \n\n",161,clase.nombre,161,161,130);
    system("pause");

    system("cls");
    mostrar_templo();
    printf("\n\n\n El H%croe supo que no podr%ca enfrentar al drag\xA2n con un arma ordinaria\n por lo que atrajo al drag\xA2 \n",130,161);
    printf("hacia un templo antiguo que se encontraban a las afueras de la ciudad.\n");
    printf("Una vez all\xA1 %s se hizo con un arma legendaria con la cual hab%ca librado \x82picas batallas en tiempos pasados.\n ",nombre.nombre,161);
    printf("Al equiparla, sinti\xA2 una bestia aterrizar a sus espaldas\n ");
    printf("En ese momento supo que un glorioso combate estaba a punto de suceder.\n\n");

    system("pause");
}

void muestra_arma_pocion_encontrada()
{
    printf("\033[0;33m");
    printf("\n------------------------------------------------------------------------------------------------------");
    printf("\033[1;37m");
    printf("\n\n \" En el cadaver del enemigo encuentras un ARMA y una POCION NUEVA, revisa tu inventario......\" \n");
    printf("\033[0;33m");
    printf("\n------------------------------------------------------------------------------------------------------");
    printf("\033[1;37m");
}


///GENERAL

void titulo ()
{

    system("cls");
    printf("\033[0;35m");
    printf("%s","\t\t _____ _____ _____ _   _ _____  ______ _   _ _   _ _____  _____ _____ _   _  _____     _____");
    printf("%s","\n\t\t/  ___/  __ \\  _  | | | |_   _| |  _  \\ | | | \\ | |  __ \\|  ___|  _  | \\ | |/  ___|   /  _  \\");
    printf("%s","\n\t\t\\ `--.| /  \\/ | | | | | | | |   | | | | | | |  \\| | |  \\/| |__ | | | |  \\| |\\ `--.   |__| |  |");
    printf("%s","\n\t\t `--. \\ |   | | | | | | | | |   | | | | | | | . ` | | __ |  __|| | | | . ` | `--. \\      /  /");
    printf("%s","\n\t\t/\\__/ / \\__/\\ \\_/ / |_| | | |   | |/ /| |_| | |\\  | |_\\ \\| |___\\ \\_/ / |\\  |/\\__/ /    /  /__");
    printf("%s","\n\t\t\\____/ \\____/\\___/ \\___/  \\_/   |___/  \\___/\\_| \\_/\\____/\\____/ \\___/\\_| \\_/\\____/    |______| \n\n\n\n ");



    printf("\033[0;33m");
    printf("%s","\t\t\t\t\t   |\\                     /)");
    printf("\033[1;30m");
    printf("%s","\n\t\t\t\t\t /\\_");
    printf("\033[0;33m");
    printf("%s","\\\\");
    printf("\033[1;30m");
    printf("%s","__");
    printf("%s","               (_");
    printf("\033[0;33m");
    printf("%s","//");
    printf("\033[1;30m");
    printf("%s","\n\t\t\t\t\t|   `>");
    printf("\033[0;33m");
    printf("%s","\\");
    printf("\033[1;30m");
    printf("%s","-`");
    printf("\033[1;37m");
    printf("%s","     _._       ");
    printf("\033[1;36m");
    printf("%s","//");
    printf("\033[1;30m");
    printf("%s","`)");
    printf("\033[1;30m");
    printf("%s","\n\t\t\t\t\t \\ /` ");
    printf("\033[0;33m");
    printf("%s","\\\\  ");
    printf("\033[1;37m");
    printf("%s","_.-`");
    printf("\033[0;31m");
    printf("%s",":::");
    printf("\033[1;37m");
    printf("%s","`-._  ");
    printf("\033[1;36m");
    printf("%s","//");
    printf("\033[1;30m");
    printf("%s","\n\t\t\t\t\t  `");
    printf("\033[0;33m");
    printf("%s","    \\");
    printf("\033[1;37m");
    printf("%s","|`    ");
    printf("\033[0;31m");
    printf("%s",":::");
    printf("\033[1;37m");
    printf("%s","    `|");
    printf("\033[1;36m");
    printf("%s","/");
    printf("\033[1;37m");
    printf("%s","\n\t\t\t\t\t        |");
    printf("\033[0;31m");
    printf("%s","     :::");
    printf("\033[1;37m");
    printf("%s","     |");
    printf("\033[1;37m");
    printf("%s","\n\t\t\t\t\t        |");
    printf("\033[0;31m");
    printf("%s",".....:::.....");
    printf("\033[1;37m");
    printf("%s","|");
    printf("%s","\n\t\t\t\t\t        |");
    printf("\033[0;31m");
    printf("%s",":::::::::::::");
    printf("\033[1;37m");
    printf("%s","|");
    printf("%s","\n\t\t\t\t\t        |     ");
    printf("\033[0;31m");
    printf("%s",":::     ");
    printf("\033[1;37m");
    printf("%s","|");
    printf("%s","\n\t\t\t\t\t        \\");
    printf("\033[0;31m");
    printf("%s","     :::     ");
    printf("\033[1;37m");
    printf("%s","/");
    printf("%s","\n\t\t\t\t\t         \\");
    printf("\033[0;31m");
    printf("%s","    :::");
    printf("\033[1;37m");
    printf("%s","    /");
    printf("%s","\n\t\t\t\t\t          `-.");
    printf("\033[0;31m");
    printf("%s"," :::");
    printf("\033[1;37m");
    printf("%s"," .-'");
    printf("\033[1;36m");
    printf("%s","\n\t\t\t\t\t           //");
    printf("\033[1;37m");
    printf("%s","`");
    printf("\033[0;31m");
    printf("%s",":::");
    printf("\033[1;37m");
    printf("%s","`");
    printf("\033[0;33m");
    printf("%s","\\\\");
    printf("\033[1;36m");
    printf("%s","\n\t\t\t\t\t          //");
    printf("\033[1;37m");
    printf("%s","   '");
    printf("\033[0;33m");
    printf("%s","   \\\\");
    printf("\033[1;36m");
    printf("%s","\n\t\t\t\t\t         |/");
    printf("\033[0;33m");
    printf("%s","         \\\\    \n\n");
    printf("\033[0m");

}

void pantalla_muerte()
{
    //system("cls");
    printf("\033[1;37m");
    printf("                              .___.");
    printf("\033[0;33m");
    printf("\n          /)               ");
    printf("\033[1;37m");
    printf(",-^     ^-.");
    printf("\033[0;33m");
    printf("\n         //               ");
    printf("\033[1;37m");
    printf("%s","/           \\");
    printf("\033[0;33m");
    printf("%s","\n.-------| |");
    printf("\033[1;30m");
    printf("%s","--------------");
    printf("\033[1;37m");
    printf("%s","/  __     __  \\");
    printf("\033[1;30m");
    printf("%s","-------------------.__");
    printf("\033[0;33m");
    printf("%s","\n|WMWMWMW| |");
    printf("\033[1;30m");
    printf("%s",">>>>>>>>>>>>>>");
    printf("\033[1;37m");
    printf("%s","| /");
    printf("\033[1;30m");
    printf("%s",">>");
    printf("\033[1;37m");
    printf("%s","\\   /");
    printf("\033[1;30m");
    printf("%s",">>");
    printf("\033[1;37m");
    printf("%s","\\ |");
    printf("\033[1;30m");
    printf("%s",">>>>>>>>>>>>>>>>>>>>>>:>");
    printf("\033[0;33m");
    printf("%s","\n`-------| |");
    printf("\033[1;30m");
    printf("%s","--------------");
    printf("\033[1;37m");
    printf("%s","| \\__/   \\__/ |");
    printf("\033[1;30m");
    printf("%s","-------------------'^^");
    printf("\033[0;33m");
    printf("%s","\n         \\\\               ");
    printf("\033[1;37m");
    printf("%s","\\    /|\\    /");
    printf("\033[0;33m");
    printf("%s","\n          \\)               ");
    printf("\033[1;37m");
    printf("%s","\\   \\_/   /");
    printf("%s","\n                            |       |");
    printf("%s","\n                            |+H+H+H+|");
    printf("%s","\n                            \\       /");
    printf("%s","\n                             ^-----^\n\n");



    printf("\033[0;31m \n");

    printf("\n    ( \t\t(\t\t* \t\t(\t\t)   ");
    printf("\n     )\\ )  *   )   (     )\\ )   (`\t)  \\ )  *   ) ( /( ");

    printf("\033[0;33m");

    printf("%s","\n (  (()/(` )  /(   )\\   (()/(   )\\))(     (  (  (()/(` )  /( ) \\ ())");
    printf("%s","\n )\\  /(_))( )(_)|(((_)(  /(_)) ((_)()\\    )\\ )\\  /(_))( )(_)|(_)\\");

    printf("\033[1;33m");

    printf("%s","\n((_)(_)) (_(_()) )\\ _ )\\(_))   (_()((_)_ ((_|(_)(_)) (_(_())  ((_)");

    printf("\033[1;37m");

    printf("%s","\n| __/ __||_   _|   /_\\  / __|  |  \\/  | | | | __| _ \\|_   _| / _ \\");
    printf("%s","\n| _|\\__ \\  | |    / _ \\ \\__ \\  | |\\/| | |_| | _||   /  | |  | (_) |");
    printf("%s","\n|___|___/  |_|   /_/ \\_\\|___/  |_|  |_|\\___/|___|_|_\\  |_|   \\___/");

    printf("\n\n\n\n\n\n");
}

void mostrar_ganaste()
{
    system("cls");
    printf("\033[1;36m");
    printf("%s","                        /\\");
    printf("%s","\n                        ||");
    printf("%s","\n                        ||");
    printf("%s","\n                        ||");
    printf("%s","\n                        ||                                               ");
    printf("\033[0;31m");
    printf("%s","~-----~");
    printf("\033[1;36m");
    printf("%s","\n                        ||                                            ");
    printf("\033[0;31m");
    printf("%s","/===--  ---~~~");
    printf("\033[1;36m");
    printf("%s","\n                        ||                   ");
    printf("\033[1;31m");
    printf("%s",";'                 ");
    printf("\033[0;31m");
    printf("%s","/==~- --   -    ---~~~");
    printf("\033[1;36m");
    printf("%s","\n                        ||                ");
    printf("\033[1;31m");
    printf("%s","(/ ('              ");
    printf("\033[0;31m");
    printf("%s","/=----         ~~_  --(  '");
    printf("\033[1;36m");
    printf("%s","\n                        ||             ");
    printf("\033[1;31m");
    printf("%s","' / ;'             ");
    printf("\033[0;31m");
    printf("%s","/=----               \\__~");
    printf("%s","\n     '                ");
    printf("\033[0;33m");
    printf("%s","~==");
    printf("\033[0;37m");
    printf("%s","_");
    printf("\033[0;33m");
    printf("%s","=~          ");
    printf("\033[1;31m");
    printf("%s","'('             ");
    printf("\033[0;31m");
    printf("%s","~-~~      ~~~~        ~~~--\\~'");
    printf("%s","\n     \\\\                ");
    printf("\033[0;37m");
    printf("%s","(c_\\_        ");
    printf("%s",".");
    printf("\033[1;31m");
    printf("%s","i");
    printf("\033[0;37m");
    printf("%s",".             ");
    printf("\033[0;31m");
    printf("%s","/~--    ~~~--   -~     (     '");
    printf("%s","\n      `\\               ");
    printf("\033[0;37m");
    printf("%s","(}");
    printf("\033[0;33m");
    printf("%s","| ");
    printf("\033[0;37m");
    printf("%s","/       / : \\           ");
    printf("\033[0;31m");
    printf("%s","/ ~~------~     ~~\\   (");
    printf("%s","\n      \\ '               ");
    printf("\033[0;33m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s","/ \\      |===|          ");
    printf("\033[0;31m");
    printf("%s","/~/             ~~~ \\ \\(");
    printf("%s","\n      ``~\\              ");
    printf("\033[0;33m");
    printf("%s","~~");
    printf("\033[0;37m");
    printf("%s","\\  )~.~_ >._.< _~-~     ");
    printf("\033[0;31m");
    printf("%s","|`_          ~~-~     )\\");
    printf("%s","\n       '-~                 ");
    printf("\033[0;37m");
    printf("%s","{  /  ) \\___/ (   \\");
    printf("\033[0;31m");
    printf("%s","   |` ` _       ~~         '");
    printf("%s","\n       \\ -~\\                ");
    printf("\033[0;37m");
    printf("%s","-<__/  -   -  L~ -;");
    printf("\033[0;31m");
    printf("%s","   \\\\    \\ _ _/");
    printf("%s","\n       `` ~~=\\                  ");
    printf("\033[0;37m");
    printf("%s","{    :    }\\ ,\\    ");
    printf("\033[0;31m");
    printf("%s","||   _ :(");
    printf("%s","\n        \\  ~~=\\__                ");
    printf("\033[0;37m");
    printf("%s","\\ _/ \\_ /  )  }");
    printf("\033[0;31m");
    printf("%s"," _//   ( `|'");
    printf("%s","\n        ``    , ~\\--~=\\           ");
    printf("\033[0;37m");
    printf("%s","\\     /  / _/");
    printf("\033[0;31m");
    printf("%s"," / '    (   '");
    printf("%s","\n         \\`    } ~ ~~ -~=\\   _~_  ");
    printf("\033[0;37m");
    printf("%s","/ \\ / \\ )^ ( ");
    printf("\033[0;31m");
    printf("%s","// :_  / '");
    printf("%s","\n         |    ,          _~-'   '~~__-_  ");
    printf("\033[0;37m");
    printf("%s","/ - |");
    printf("\033[0;31m");
    printf("%s","/     \\ (");
    printf("%s","\n          \\  ,_--_     _/              ");
    printf("\033[0;37m");
    printf("%s","\\_'---'");
    printf("\033[0;31m");
    printf("%s",", -~ .   \\");
    printf("%s","\n           )/      /\\ / /\\   ,~,         ");
    printf("\033[0;37m");
    printf("%s","\\__ _}     ");
    printf("\033[0;31m");
    printf("%s","\\_  \"~_");
    printf("%s","\n           ,      { ( _ )'} ~ ");
    printf("\033[0;33m");
    printf("%s","- ");
    printf("\033[0;31m");
    printf("%s","\\_    ~\\  ");
    printf("\033[0;37m");
    printf("%s","(-:-)       ");
    printf("\033[0;31m");
    printf("%s","\"\\   ~");
    printf("%s","\n                  /");
    printf("\033[1;37m");
    printf("%s","'' ''  ");
    printf("\033[0;31m");
    printf("%s",")~ ");
    printf("\033[0;33m");
    printf("%s","\\~_ ~\\   ");
    printf("\033[0;31m");
    printf("%s",")->  ");
    printf("\033[0;37m");
    printf("%s","\\ :|    ");
    printf("\033[0;31m");
    printf("%s","_,       \"");
    printf("%s","\n                 (\\  _/)''} ");
    printf("\033[0;37m");
    printf("%s","| ");
    printf("\033[0;33m");
    printf("%s","\\~_ ~  ");
    printf("\033[0;31m");
    printf("%s","/~(   ");
    printf("\033[0;37m");
    printf("%s","| :)   ");
    printf("\033[0;31m");
    printf("%s","/          }");
    printf("%s","\n                <``  >;,,/  ");
    printf("\033[0;37m");
    printf("%s",")= ");
    printf("\033[0;33m");
    printf("%s","\\~__ {{{ '  ");
    printf("\033[0;37m");
    printf("%s","\\ =(  ");
    printf("\033[0;31m");
    printf("%s",",   ,       ;");
    printf("%s","\n               {");
    printf("\033[0;33m");
    printf("%s","o");
    printf("\033[0;31m");
    printf("%s","_");
    printf("\033[0;33m");
    printf("%s","o ");
    printf("\033[0;31m");
    printf("%s","}_/     ");
    printf("\033[0;37m");
    printf("%s","|v  ");
    printf("\033[0;33m");
    printf("%s","'~__  _    ");
    printf("\033[0;37m");
    printf("%s","-v|  ");
    printf("\033[0;31m");
    printf("%s","\"  :       ,\"");
    printf("%s","\n               {/\"\\_)       ");
    printf("\033[0;37m");
    printf("%s","{_/'  ");
    printf("\033[0;33m");
    printf("%s","\\~__ ~\\");
    printf("\033[0;31m");
    printf("%s","_ ");
    printf("\033[0;37m");
    printf("%s","\\_} ");
    printf("\033[0;31m");
    printf("%s","'  {        /~\\");
    printf("\033[0;31m");
    printf("%s","\n               ,");
    printf("\033[1;33m");
    printf("%s","/");
    printf("\033[0;31m");
    printf("%s","!          ");
    printf("\033[0;37m");
    printf("%s","'_/    ");
    printf("\033[0;33m");
    printf("%s","'~__ _-~ ");
    printf("\033[0;37m");
    printf("%s","\\_' ");
    printf("\033[0;31m");
    printf("%s",":  '      ,\"  ~");
    printf("\033[0;31m");
    printf("%s","\n              (");
    printf("\033[1;33m");
    printf("%s","''");
    printf("\033[0;31m");
    printf("%s","`                  ");
    printf("\033[0;31m");
    printf("%s","/,");
    printf("\033[0;33m");
    printf("%s","'~___~    ");
    printf("\033[0;31m");
    printf("%s","| /     ,\"  \\ ~'");
    printf("\033[0;31m");
    printf("%s","\n             '");
    printf("\033[1;33m");
    printf("%s","/, ");
    printf("\033[0;31m");
    printf("%s","\\)                 ");
    printf("\033[0;31m");
    printf("%s","(-)  ");
    printf("\033[0;33m");
    printf("%s","'~____~\"");
    printf("\033[0;31m");
    printf("%s",";     ,\"     , }");
    printf("\033[0;31m");
    printf("%s","\n           /");
    printf("\033[1;33m");
    printf("%s",",'");
    printf("\033[0;31m");
    printf("%s",")                    ");
    printf("\033[0;31m");
    printf("%s","/ \\         /  ,~-\"       '~'");
    printf("%s","\n       (  ");
    printf("\033[1;33m");
    printf("%s","''");
    printf("\033[0;31m");
    printf("%s","/                     ");
    printf("%s","/ ( '       /  /          '~'");
    printf("%s","\n    ~ ");
    printf("\033[0;33m");
    printf("%s","~  ");
    printf("\033[1;33m");
    printf("%s",",, ");
    printf("\033[0;33m");
    printf("%s","/) ");
    printf("\033[0;31m");
    printf("%s",",                 ");
    printf("\033[0;33m");
    printf("%s","(/( \\)      ");
    printf("\033[0;31m");
    printf("%s","( -)          /~'");
    printf("%s","\n  (  ");
    printf("\033[0;33m");
    printf("%s","~");
    printf("\033[1;33m");
    printf("%s","~ )`  ");
    printf("\033[0;33m");
    printf("%s","~}                   ");
    printf("%s","'  \\)'     ");
    printf("\033[0;31m");
    printf("%s","_/ /           ~'");
    printf("%s","\n { ");
    printf("\033[0;33m");
    printf("%s","|) ");
    printf("\033[1;33m");
    printf("%s","/`,--");
    printf("\033[0;33m");
    printf("%s",".(  ");
    printf("\033[0;31m");
    printf("%s","}'                    ");
    printf("\033[0;33m");
    printf("%s","'     ");
    printf("\033[0;31m");
    printf("%s","(  /          /~'");
    printf("%s","\n(` ");
    printf("\033[0;33m");
    printf("%s","~ ");
    printf("\033[1;33m");
    printf("%s","( c|~~| ");
    printf("\033[0;33m");
    printf("%s","`}   ");
    printf("\033[0;31m");
    printf("%s",")                        ");
    printf("\033[0;33m");
    printf("%s","'/:\\         ");
    printf("\033[0;31m");
    printf("%s",",'");
    printf("%s","\n ~ ");
    printf("\033[0;33m");
    printf("%s",")/`");
    printf("\033[1;33m");
    printf("%s","`) ))");
    printf("\033[0;33m");
    printf("%s"," '|),                          ");
    printf("\033[0;33m");
    printf("%s","(/ | \\)");
    printf("\033[0;31m");
    printf("%s","\n  (` ");
    printf("\033[0;33m");
    printf("%s","(-~");
    printf("\033[1;33m");
    printf("%s","(( ");
    printf("\033[0;33m");
    printf("%s","`~`'  ");
    printf("\033[0;31m");
    printf("%s",")                        ");
    printf("\033[0;33m");
    printf("%s","' (/ '");
    printf("\033[0;31m");
    printf("%s","\n   `~");
    printf("\033[0;33m");
    printf("%s","'    )'");
    printf("\033[0;31m");
    printf("%s","`')                              ");
    printf("\033[0;33m");
    printf("%s","'");
    printf("\033[0;31m");
    printf("%s","\n     ` ``");
    printf("\033[0;36m");
    printf("%s","\n\n\n\t _   _  _____  _____  _____  _____ ______  _____   ___ ");
    printf("%s","\n\t| | | ||_   _|/  __ \\|_   _||  _  || ___ \\|_   _| / _ \\ ");
    printf("%s","\n\t| | | |  | |  | /  \\/  | |  | | | || |_/ /  | |  / /_\\ \\");
    printf("%s","\n\t| | | |  | |  | |      | |  | | | ||    /   | |  |  _  |");
    printf("%s","\n\t\\ \\_/ / _| |_ | \\__/\\  | |  \\ \\_/ /| |\\ \\  _| |_ | | | |");
    printf("%s","\n\t \\___/  \\___/  \\____/  \\_/   \\___/ \\_| \\_| \\___/ \\_| |_/\n\n");
    printf("\033[1;37m");
}


///MOSTRAR ENEMIGOS
void mostrar_enemigo (personaje enemigo)
{
    int id = enemigo.id;

    switch (id)
    {
    case -1:
    {
        mostrar_enano();
        break;
    }
    case -2:
    {
        mostrar_esqueleto();

        break;
    }
    case -3:
    {
        mostrar_la_parca();
        break;
    }

    case -4:
    {
        mostrar_grifo();
        break;
    }
    case -5:
    {
        mostrar_dragon();
        break;
    }
    default:
    {
        printf("\n -IMAGEN PREDETERMINADA- \n");
        mostrar_enano();
    }
    }
}

void mostrar_enano ()
{

    printf("\n");
    printf("\n");

    printf("\033[1;30m");
    printf("               /\\_");
    printf("\033[0;33m");
    printf("[]");
    printf("\033[1;30m");
    printf("_/\\ ");
    printf("\n              |] _");
    printf("\033[0;33m");
    printf("||");
    printf("\033[1;30m");
    printf("_ [|");
    printf("\033[0;36m");
    printf("\n       ___     ");
    printf("\033[1;30m");
    printf("\\/");
    printf("\033[0;33m");
    printf(" || ");
    printf("\033[1;30m");
    printf("\\/");
    printf("\033[0;36m");
    printf("\n      /___\\       ");
    printf("\033[0;33m");
    printf("||");
    printf("\033[0;36m");
    printf("\n     (|");
    printf("\033[1;37m");
    printf("0 0");
    printf("\033[0;36m");
    printf("|)      ");
    printf("\033[0;33m");
    printf("||");
    printf("\033[0;36m");
    printf("%s","\n   __/");
    printf("\033[0;33m");
    printf("%s","{\\");
    printf("\033[1;37m");
    printf("%s","-");
    printf("\033[0;33m");
    printf("%s","/}");
    printf("\033[0;36m");
    printf("%s","\\_ __");
    printf("\033[0;35m");
    printf("%s","_/vvv");
    printf("\033[0;36m");
    printf("%s","\n  / \\  ");
    printf("\033[0;33m");
    printf("%s","{~}   ");
    printf("\033[0;36m");
    printf("%s","/ _");
    printf("\033[0;35m");
    printf("%s","|_P");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;36m");
    printf("%s","\n  | /\\  ");
    printf("\033[0;33m");
    printf("%s","~   ");
    printf("\033[0;36m");
    printf("%s","/_/   ");
    printf("\033[0;33m");
    printf("%s","[]");
    printf("\033[0;36m");
    printf("%s","\n  |_| ");
    printf("\033[0;36m");
    printf("%s","(____)");
    printf("\033[0;35m");
    printf("%s","\n  \\_]");
    printf("\033[0;31m");
    printf("%s","/______\\");
    printf("\033[0;33m");
    printf("%s","\n     _\\_||_/_");
    printf("\033[1;32m");
    printf("%s","\n____");
    printf("\033[0;33m");
    printf("%s","(_,_||_,_)");
    printf("\033[0;32m");
    printf("%s","____");
    printf("\033[0;33m");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\033[1;37m");
}

void mostrar_esqueleto()
{
    printf("                              _.--""-._\n");
    printf("  .                         ."         ".\n");
    printf(" / \\    ,^.         /(     Y            |     )\\ \n");
    printf("/   `---. |--'\\    (  \\__..'--   -  -- -'""-.-'   ) \n");
    printf("|        :|    `>   '.     l_..-------.._|    .'  \n");
    printf("|      __l;__ .'      ""-.__.||_.-'v'-._||`""----"" \n");
    printf(" \\  .-' | |  `              l._       _.'  \n");
    printf("  \\/    | |                   l`^^'^^'j   \n");
    printf("        | |                _   \\_____/     _ \n");
    printf("        | |               l `--__)-'(__.--' | \n");
    printf("        | |               | /`---``-----'""| |  ,-----.  \n");
    printf("        | |               )/  `--' '---'   \'-'  ___  `-. \n");
    printf("        | |              //  `-'  '`----'  /  ,-'   I`.  \\ \n");
    printf("      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \\ \n");
    printf("     '._' / \\         _/(   `/   )- ---' ;  /__.|   |.__.\\ : \n");
    printf("      `._;/7(-.......'  /        ) (     |  |            | | \n");
    printf("      `._;l _'--------_/         )-'/     :  |___.    _._./ ; \n");
    printf("        | |                 ._ _ )-'\\  __  \\  \\  |   |   / / \n");
    printf("        `-'                /   `-\\-(-'   \\ \\  `.|   | ,' / \n");
    printf("                           \\__  `-'    __/  `-. `---'',-' \n");
    printf("                              )-._.-- (        `-----' \n");
    printf("                             )(  |\\ o ('..-. \n");
    printf("                       _..--' _'-' '--'.-. | \n");
    printf("                __,,-'' _,,-''            \\ \\ \n");
    printf("               f'. _,,-'                   \\ \\ \n");
    printf("              ()--  |                       \\ \\ \n");
    printf("                \\.  |                       /  \\ \n");
    printf("                  \\ \\                      |._  | \n");
    printf("                   \\ \\                     |  ()| \n");
    printf("                    \\ \\                     \\  / \n");
    printf("                     ) `-.                   | | \n");
    printf("                    // .__)                  | | \n");
    printf("                 _.//7'                      | | \n");
    printf("               '---'                         |_| ` \n");
    printf("                                            (| | \n");
    printf("                                             |  \\ \n");
    printf("                                             |lllj \n");
    printf("                                             |||||  \n");
}

void mostrar_la_parca()
{
    printf("                                              .""--..__  \n");
    printf("                     _                     []       ``-.._ \n");
    printf("                  .'` `'.                  ||__           `-._ \n");
    printf("                 /    ,-.\\                 ||_ ```---..__     `-. \n");
    printf("                 /    ,-.\\                ||_ ```---..__  `-.    \\\n");
    printf("                /    /:::\\\\               /|//}        ``--._ `.  \\ \n");
    printf("                |    |:::||              |////}                `-. \\ \n");
    printf("                |    |:::||             //'///                    `.\\ \n");
    printf("                |    |:::||            //  ||'                      `| \n");
    printf("                /    |:::|/        _,-//\\  || \n");
    printf("               /`    |:::|`-,__,-'`  |/  \\ || \n");
    printf("             /`  |   |'' ||           \\   ||| \n");
    printf("           /`    \\   |   ||            |  /|| \n");
    printf("         |`       |  |   |)            \\ | || \n");
    printf("        |          \\ |   /      ,.__    \\| || \n");
    printf("        /           `         /`    `\\   | || \n");
    printf("       |                     /        \\  / || \n");
    printf("       |                     |        | /  || \n");
    printf("       /         /           |        `(   || \n");
    printf("      /          .           /          )  || \n");
    printf("     |            \\          |     ________|| \n");
    printf("    /             |          /     `-------.| \n");
    printf("   |\\            /          |              || \n");
    printf("   \\/`-._       |           /              || \n");
    printf("    //   `.    /`           |              || \n");
    printf("   //`.    `. |             \\              || \n");
    printf("  ///\\ `-._  )/             |              || \n");
    printf(" //// )   .(/               |              || \n");
    printf(" ||||   ,'` )               /              // \n");
    printf(" ||||  /                    /             ||  \n");
    printf(" `\\` /`                    |             //  \n");
    printf("     |`                     \\            ||   \n");
    printf("    /                        |           //   \n");
    printf("  /`                          \\         //   \n");
    printf("/`                            |        ||     \n");
    printf("`-.___,-.      .-.        ___,'        (/     \n");
    printf("         `---'`   `'----'`\n");
}

void mostrar_grifo()
{
    printf("\033[1;33m");
    printf("%s","        _____,    ");
    printf("\033[1;37m");
    printf("%s","_..-=-=-=-=-====--,");
    printf("\033[0;33m");
    printf("%s","\n     _");
    printf("\033[1;33m");
    printf("%s",".'");
    printf("\033[1;37m");
    printf("%s","a   ");
    printf("\033[1;33m");
    printf("%s","/  ");
    printf("\033[1;37m");
    printf("%s",".-',___,..=--=--==-'`");
    printf("\033[0;33m");
    printf("%s","\n    ( _     ");
    printf("\033[1;33m");
    printf("%s","\\ ");
    printf("\033[1;37m");
    printf("%s","/  //___/-=---=----'");
    printf("\033[0;33m");
    printf("%s","\n     ` ");
    printf("\033[1;33m");
    printf("%s","`\\    ");
    printf("\033[1;37m");
    printf("%s","/  //---/--==----=-'");
    printf("\033[0;33m");
    printf("%s","\n  ,-.    ");
    printf("\033[1;33m");
    printf("%s","| ");
    printf("\033[1;37m");
    printf("%s","/ \\_//-_.'==-==---='");
    printf("\033[0;33m");
    printf("%s","\n (.-.`");
    printf("\033[1;33m");
    printf("%s","\\  | ");
    printf("\033[1;37m");
    printf("%s","|'../-'=-=-=-=--'");
    printf("\033[0;33m");
    printf("%s","\n  (' `");
    printf("\033[1;33m");
    printf("%s","\\`\\");
    printf("\033[1;33m");
    printf("%s","| ");
    printf("\033[1;37m");
    printf("%s","//_|-\\.`;");
    printf("\033[1;33m");
    printf("%s","-~````~,        _");
    printf("\033[1;33m");
    printf("%s","\n       \\ | ");
    printf("\033[1;37m");
    printf("%s","\\_,_,_\\.'        ");
    printf("\033[1;33m");
    printf("%s","\\     .'_`\\");
    printf("%s","\n        `\\            ,    , \\    || `\\\\");
    printf("%s","\n          \\    /   _.--\\    \\ '._.'/  ");
    printf("\033[0;33m");
    printf("%s","/ |");
    printf("\033[1;33m");
    printf("%s","\n          /  /`---'   \\ \\   |`'---'   ");
    printf("\033[0;33m");
    printf("%s","\\/");
    printf("\033[1;33m");
    printf("%s","\n         / /'          \\ ;-. \\");
    printf("\033[1;33m");
    printf("%s","\n      __/ /           ");
    printf("\033[0;33m");
    printf("%s","__) \\ ) `|");
    printf("%s","\n    ((='--;)         (,___/(,_/");
    printf("\033[1;37m");
    printf("\n");
}

void mostrar_dragon()
{
    printf("\033[1;33m");
    printf("%s","             __                  __");
    printf("%s","\n            ( _)                ( _)");
    printf("\033[0;31m");
    printf("%s","\n           / / \\\\              / /\\_\\_");
    printf("%s","\n          / /   \\\\            / / ");
    printf("\033[0;33m");
    printf("%s","| ");
    printf("\033[0;31m");
    printf("%s","\\ \\");
    printf("%s","\n         / /     \\\\          / /  ");
    printf("\033[0;33m");
    printf("%s","|\\ ");
    printf("\033[0;31m");
    printf("%s","\\ \\");
    printf("%s","\n        /  /   ");
    printf("\033[1;33m");
    printf("%s",",  ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("\033[1;33m");
    printf("%s",",       ");
    printf("\033[0;31m");
    printf("%s","/ /   ");
    printf("\033[0;33m");
    printf("%s","/|  ");
    printf("\033[0;31m");
    printf("%s","\\ \\");
    printf("%s","\n       /  /    ");
    printf("%s","|\\");
    printf("\033[0;31m");
    printf("%s","_ ");
    printf("%s","/|      ");
    printf("\033[0;31m");
    printf("%s","/ /   ");
    printf("\033[0;33m");
    printf("%s","/ \\   ");
    printf("\033[0;31m");
    printf("%s","\\_\\");
    printf("%s","\n      /  /  ");
    printf("\033[1;37m");
    printf("%s","|\\");
    printf("\033[0;31m");
    printf("%s","/ ");
    printf("%s","_ ");
    printf("%s","'");
    printf("%s","_");
    printf("%s","| \\   / /   ");
    printf("\033[0;33m");
    printf("%s","/   ");
    printf("%s","\\    ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("%s","\n     |  /   ");
    printf("\033[1;37m");
    printf("%s","|");
    printf("\033[0;31m");
    printf("%s","/  ");
    printf("\033[1;37m");
    printf("%s","* ");
    printf("\033[0;31m");
    printf("%s","\\");
    printf("\033[1;37m");
    printf("%s","*");
    printf("\033[0;31m");
    printf("%s","\\    / |    ");
    printf("\033[0;33m");
    printf("%s","|    \\    ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("%s","\n     |    ");
    printf("\033[1;37m");
    printf("%s","|\\");
    printf("\033[0;31m");
    printf("%s","|      \\_\\_ /  /    ");
    printf("\033[0;33m");
    printf("%s","|     \\    ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("%s","\n     |  | ");
    printf("\033[1;37m");
    printf("%s","|");
    printf("\033[0;31m");
    printf("%s","/    \\.\\ ");
    printf("\033[0;33m");
    printf("%s","o");
    printf("\033[0;31m");
    printf("%s","\\");
    printf("\033[0;33m");
    printf("%s","o");
    printf("\033[0;31m");
    printf("%s",")");
    printf("%s","  /      ");
    printf("\033[0;33m");
    printf("%s","\\     |    ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("%s","\n     \\    |     /\\\\`");
    printf("\033[1;37m");
    printf("%s","v");
    printf("\033[0;31m");
    printf("%s","-");
    printf("\033[1;37m");
    printf("%s","v  ");
    printf("\033[0;31m");
    printf("%s","/        ");
    printf("\033[0;33m");
    printf("%s","|    |     ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("%s","\n      | \\/    ");
    printf("\033[0;33m");
    printf("%s","/_| ");
    printf("\033[0;31m");
    printf("%s","\\\\_|  /         ");
    printf("\033[0;33m");
    printf("%s","|    | \\    ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("%s","\n      | |    ");
    printf("\033[0;33m");
    printf("%s","/__/");
    printf("\033[0;31m");
    printf("%s","_ `-` /   _____  ");
    printf("\033[0;33m");
    printf("%s","|    |  \\    ");
    printf("\033[0;31m");
    printf("%s","\\\\");
    printf("%s","\n      \\|    ");
    printf("\033[0;33m");
    printf("%s","[__]  ");
    printf("\033[0;31m");
    printf("%s","\\_/  |_________  ");
    printf("\033[0;33m");
    printf("%s","\\   |   \\    ");
    printf("\033[1;33m");
    printf("%s","()");
    printf("\033[0;31m");
    printf("%s","\n       /    ");
    printf("\033[0;33m");
    printf("%s","[___] ");
    printf("\033[0;31m");
    printf("%s","(    \\         \\  ");
    printf("\033[0;33m");
    printf("%s","|\\ |   |   ");
    printf("\033[0;31m");
    printf("%s","//");
    printf("%s","\n      |    ");
    printf("\033[0;33m");
    printf("%s","[___]                  ");
    printf("\033[0;31m");
    printf("%s","\\ ");
    printf("\033[0;33m");
    printf("%s","| \\|   /  ");
    printf("\033[0;31m");
    printf("%s","|/");
    printf("%s","\n     /|    ");
    printf("\033[0;33m");
    printf("%s","[____]                  ");
    printf("\033[0;31m");
    printf("%s","\\  ");
    printf("\033[0;33m");
    printf("%s","|/\\ / / ");
    printf("\033[0;31m");
    printf("%s","||");
    printf("%s","\n    (  \\   ");
    printf("\033[0;33m");
    printf("%s","[____ ");
    printf("\033[0;31m");
    printf("%s","/     ) _\\      \\  \\    ");
    printf("\033[0;33m");
    printf("%s","\\| | ");
    printf("\033[0;31m");
    printf("%s","||");
    printf("%s","\n     \\  \\  ");
    printf("\033[0;33m");
    printf("%s","[_____");
    printf("\033[0;31m");
    printf("%s","|    / /     __/    \\   ");
    printf("\033[0;33m");
    printf("%s","/ / ");
    printf("\033[0;31m");
    printf("%s","//");
    printf("%s","\n     |   \\ ");
    printf("\033[0;33m");
    printf("%s","[_____");
    printf("\033[0;31m");
    printf("%s","/   / /        \\    |   ");
    printf("\033[0;33m");
    printf("%s","\\/ ");
    printf("\033[0;31m");
    printf("%s","//");
    printf("%s","\n     |   /  ");
    printf("\033[0;33m");
    printf("%s","'----");
    printf("\033[0;31m");
    printf("%s","|   /=\\____   _/    |   ");
    printf("\033[0;33m");
    printf("%s","/ ");
    printf("\033[0;31m");
    printf("%s","//");
    printf("%s","\n  __ /  /        |  /   ___/  _/\\    \\  ");
    printf("\033[0;33m");
    printf("%s","| ");
    printf("\033[0;31m");
    printf("%s","||");
    printf("\033[1;30m");
    printf("%s","\n_");
    printf("\033[0;33m");
    printf("%s","(/-(/-\\)");
    printf("\033[1;30m");
    printf("%s","__    ");
    printf("\033[0;31m");
    printf("%s","/   \\  ");
    printf("\033[1;30m");
    printf("%s","_");
    printf("\033[0;33m");
    printf("%s","(/\\/\\)/");
    printf("\033[1;30m");
    printf("%s","_ ");
    printf("\033[0;31m");
    printf("%s","|    /  ");
    printf("\033[0;33m");
    printf("%s","| ");
    printf("\033[0;31m");
    printf("%s","/");
    printf("\033[1;30m");
    printf("%s","\n           \\___");
    printf("\033[0;33m");
    printf("%s","(/\\/\\)");
    printf("\033[1;30m");
    printf("%s","___        ");
    printf("\033[0;31m");
    printf("%s","/   /   //");
    printf("\033[1;30m");
    printf("%s","\n            \\");
    printf("\033[0;31m");
    printf("%s","         _________/   /    /");
    printf("\033[0;32m");
    printf("%s","\n_____________");
    printf("\033[1;30m");
    printf("%s","\\");
    printf("\033[0;32m");
    printf("%s","_______");
    printf("\033[0;31m");
    printf("%s","\\____________/");
    printf("\033[0;32m");
    printf("%s","____");
    printf("\033[1;33m");
    printf("%s","(");
    printf("\033[0;32m");
    printf("%s","____");
    printf("\033[1;37m");
    printf("\n");

}
///???????????
void mostrar_sorpresa()
{
    system("cls");
    printf("Que trucazo no?\n");

    printf("\033[1;32m");

    printf("                  /\\_.----._                   \n");
    printf("              .\" _,=<'\"=. \",/|               \n");
    printf("             /,-'    \"=.`.   (                    \n");
    printf("            //         \\ |    \\                     \n");
    printf("           /,    _.,.   |      \\    (|               \n");
    printf("         ,\" |   ,\\'v/', |       \\  _)(               \n");
    printf("        /   |   !>(\")<|/         \\ c_ \\             \n");
    printf("     _-/     \\  '=,Z\\\\7           . C. \\           \n");
    printf(" _,-\" V  /    '-._,>*\"     \\      |   \\ \\         \n");
    printf(" \\  <\"|  )\\ __ __ ____ _    Y     |     \\ \\        \n");
    printf("  \\ \\ |   >._____________.< |     \"-.   \\ \\     \n");
    printf("   \\ \\|   \\ \\/\\/\\/\\/\\/\\/ /' /    =_  '-._) \\           \n");
    printf("    \\ (    \\            /         |\"*=,_   /             \n");
    printf("     \\ \\    \\_/\\/\\/\\/\\_/         /      \"\"\"               \n");
    printf("     _).^     \"******\"          /                      \n");
    printf("    (()!|\\                     /                                  \n");
    printf("     *==\" \",                 ,\"                               \n");
    printf("            \",_            ,\"                                    \n");
    printf("               \\\"*<==> ,=*\"                            \n");
    printf("                \\ \\ / /                                        \n");
    printf("            _____>_V /                                \n");
    printf("           f  .-----\"                                 \n");
    printf("           |  \\    \\ \\                                  \n");
    printf("           |   \\    \\ '-.                               \n");
    printf("           J    \\    \\   \\                               \n");
    printf("          (  \\ \\ \\ _.-J   )                               \n");
    printf("           \\V)V)=*.','  ,'                              \n");
    printf("               (V(V)(V)/                                  \n");
    printf("               '''''  ");
    printf("\n");
    printf("\033[1;37m");
}
///MOSTRAR JUGADOR


void mostrar_jugador(int id)
{
    ///SEGUN LA ID DEL PERSONAJE TE MUESTRA UNA ANIMACION
    if (id == 1)
    {
        mostrar_guerrero();
    }
    else if (id == 2)
    {
        mostrar_arquero();

    }
    else if (id == 3)
    {
        mostrar_mago();
    }
    else
    {
        mostrar_sorpresa();
    }
}

void mostrar_guerrero()
{
    printf("\033[1;37m");
    printf("\033[1;36m");
    printf("\n  /\\");
    printf("\n  ||");
    printf("\n  ||");
    printf("\n  ||");
    printf("\n  ||           ");
    printf("\033[1;31m");
    printf("%s","{}");
    printf("\033[1;36m");
    printf("%s","\n  ||          ");
    printf("\033[1;30m");
    printf("%s",".--.");
    printf("\033[1;36m");
    printf("%s","\n  ||         ");
    printf("\033[1;30m");
    printf("%s","/.--.\\");
    printf("\033[1;36m");
    printf("%s","\n  ||         ");
    printf("\033[1;30m");
    printf("%s","|====|");
    printf("\033[1;36m");
    printf("%s","\n  ||         ");
    printf("\033[1;30m");
    printf("%s","|`::`|");
    printf("\033[0;33m");
    printf("%s","\n _");
    printf("\033[1;36m");
    printf("%s","||");
    printf("\033[0;33m");
    printf("%s","_    ");
    printf("\033[1;30m");
    printf("%s",".-;`\\..../`;");
    printf("\033[0;37m");
    printf("%s","_.-^-._");
    printf("\033[1;30m");
    printf("%s","\n  /\\\\   /  |");
    printf("\033[0;31m");
    printf("%s","...::..");
    printf("\033[0;37m");
    printf("%s","|`   ");
    printf("\033[0;31m");
    printf("%s",":   ");
    printf("\033[0;37m");
    printf("%s","`|");
    printf("\033[1;30m");
    printf("%s","\n  |:'\\ |   /");
    printf("\033[0;31m");
    printf("%s","'''::''");
    printf("\033[0;37m");
    printf("%s","|   ");
    printf("\033[0;31m");
    printf("%s",".:.   ");
    printf("\033[0;37m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","\n   \\ /\\;-,/\\   ");
    printf("\033[0;31m");
    printf("%s","::  ");
    printf("\033[0;37m");
    printf("%s","|");
    printf("\033[0;31m");
    printf("%s","..:::::..");
    printf("\033[0;37m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","\n    \\ <` >  >._");
    printf("\033[0;31m");
    printf("%s","::");
    printf("\033[1;30m");
    printf("%s","_.");
    printf("\033[0;37m");
    printf("%s","| ");
    printf("\033[0;31m");
    printf("%s","':::::' ");
    printf("\033[0;37m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","\n     `\"\"`  /   ^^  ");
    printf("\033[0;37m");
    printf("%s","|   ");
    printf("\033[0;31m");
    printf("%s","':'   ");
    printf("\033[0;37m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","\n           |       ");
    printf("\033[0;37m");
    printf("%s","\\    ");
    printf("\033[0;31m");
    printf("%s",":    ");
    printf("\033[0;37m");
    printf("%s","/");
    printf("\033[1;30m");
    printf("%s","\n           |        ");
    printf("\033[0;37m");
    printf("%s","\\   ");
    printf("\033[0;31m");
    printf("%s",":   ");
    printf("\033[0;37m");
    printf("%s","/");
    printf("\033[1;30m");
    printf("%s","\n           |___/\\___|");
    printf("\033[0;37m");
    printf("%s","`-.");
    printf("\033[0;31m");
    printf("%s",":");
    printf("\033[0;37m");
    printf("%s",".-`");
    printf("\033[1;30m");
    printf("%s","\n            \\_ || _/    ");
    printf("\033[0;37m");
    printf("%s","`");
    printf("\033[1;30m");
    printf("%s","\n            <_ >< _>");
    printf("%s","\n            |  ||  |");
    printf("%s","\n            |  ||  |");
    printf("%s","\n           _\\.:||:./_");
    printf("%s","\n          /____/\\____\\");
    printf("\033[1;37m");
}

void mostrar_mago()
{
    printf("\033[0;34m");
    printf("                    ____");
    printf("\n                  .'");
    printf("\033[1;33m");
    printf("* *");
    printf("\033[0;34m");
    printf(".'");
    printf("\n               __/_");
    printf("\033[1;33m");
    printf("*");
    printf("\033[0;34m");
    printf("_");
    printf("\033[1;33m");
    printf("*");
    printf("\033[0;34m");
    printf("(_");
    printf("\n              / _______ \\");
    printf("\033[0;35m");
    printf("\n             _");
    printf("\033[0;34m");
    printf("\\");
    printf("\033[0;35m");
    printf("%s","_");
    printf("\033[0;34m");
    printf(")");
    printf("\033[1;33m");
    printf("/___\\");
    printf("\033[0;34m");
    printf("(");
    printf("\033[0;35m");
    printf("_");
    printf("\033[0;34m");
    printf("/");
    printf("\033[0;35m");
    printf("_");
    printf("\n            / _");
    printf("\033[1;37m");
    printf("((\\- -/))");
    printf("\033[0;35m");
    printf("_ \\");
    printf("\n            \\ \\");
    printf("\033[1;37m");
    printf("())(-)(()");
    printf("\033[0;35m");
    printf("/ /");
    printf("\n             ' \\");
    printf("\033[1;37m");
    printf("(((()))");
    printf("\033[0;35m");
    printf("/ '");
    printf("\n            / ' ");
    printf("\\");
    printf("\033[1;37m");
    printf(")).))");
    printf("\033[0;35m");
    printf("/ ' \\");
    printf("\n           / _ ");
    printf("\033[1;33m");
    printf("\\ ");
    printf("\033[0;35m");
    printf("- ");
    printf("\033[1;33m");
    printf("| ");
    printf("\033[0;35m");
    printf("- ");
    printf("\033[1;33m");
    printf("/");
    printf("\033[0;35m");
    printf("_  \\");
    printf("\n          (   ( ");
    printf("\033[1;33m");
    printf(".;''';. ");
    printf("\033[0;35m");
    printf(".'  )");
    printf("\033[1;33m");
    printf("\n          _");
    printf("\033[0;35m");
    printf("\\\"");
    printf("\033[1;33m");
    printf("__ /    )\\ __");
    printf("\033[0;35m");
    printf("\"/");
    printf("\033[1;33m");
    printf("_");
    printf("\033[0;35m");
    printf("\n            \\/  ");
    printf("\033[1;33m");
    printf("\\   ' /  ");
    printf("\033[0;35m");
    printf("\\/");
    printf("\n             .'  ");
    printf("\033[1;33m");
    printf("'...' ");
    printf("\033[0;35m");
    printf("' )");
    printf("\n              / ");
    printf("\033[1;33m");
    printf("/  |  \\ ");
    printf("\033[0;35m");
    printf("\\");
    printf("\033[0;35m");
    printf("\n             / .   .   . \\");
    printf("\n            /   .     .   \\");
    printf("\n           /   /   |   \\   \\");
    printf("\n         .'   /    b    '.  '.");
    printf("\n     _.-'    /     Bb     '-. '-._");
    printf("\n _.-'       |      BBb       '-.  '-.");
    printf("\n(___________\\____.dBBBb.________)____)  ");
    printf("\033[1;37m");
}

void mostrar_arquero()
{
    printf("\033[1;33m");
    printf("%s","             /");
    printf("\033[0;33m");
    printf("%s","`.");
    printf("\033[0;31m");
    printf("%s","\n         )  ");
    printf("\033[1;33m");
    printf("%s","/   ");
    printf("\033[0;33m");
    printf("%s",":.                        ");
    printf("\033[1;33m");
    printf("%s","_");
    printf("\033[0;32m");
    printf("%s","\n        ,',");
    printf("\033[1;33m");
    printf("%s","/     ");
    printf("\033[0;33m");
    printf("%s","\\\\                      ");
    printf("\033[1;33m");
    printf("%s","| |");
    printf("\033[0;32m");
    printf("%s","\n       ,");
    printf("%s",";;");
    printf("\033[1;33m");
    printf("%s","/");
    printf("\033[0;32m");
    printf("%s",";      ");
    printf("\033[0;33m");
    printf("%s","::              ");
    printf("\033[1;37m");
    printf("%s",">>>>");
    printf("\033[0;33m");
    printf("%s","---");
    printf("\033[1;33m");
    printf("%s",": |");
    printf("\033[1;31m");
    printf("%s",">");
    printf("\033[0;32m");
    printf("%s","\n    ___");
    printf("\033[0;32m");
    printf("%s",":");
    printf("\033[1;33m");
    printf("%s","c");
    printf("\033[1;33m");
    printf("%s","/");
    printf("\033[1;37m");
    printf("%s",".");
    printf("\033[1;33m");
    printf("%s","(      ");
    printf("\033[0;33m");
    printf("%s","||                     ");
    printf("\033[1;33m");
    printf("%s","| |");
    printf("\033[0;32m");
    printf("%s","\n  ,'  _|");
    printf("\033[1;33m");
    printf("%s",":)");
    printf("\033[1;37m");
    printf("%s",">>>");
    printf("\033[0;33m");
    printf("%s","--");
    printf("\033[0;32m");
    printf("%s",",");
    printf("\033[0;33m");
    printf("%s","-");
    printf("\033[1;33m");
    printf("%s","'B)");
    printf("\033[1;31m");
    printf("%s",">                    ");
    printf("\033[1;33m");
    printf("%s","| |");
    printf("\033[0;32m");
    printf("%s","\n (  '---'");
    printf("\033[1;33m");
    printf("%s","\\");
    printf("\033[0;32m");
    printf("%s","--'` _,'");
    printf("\033[0;33m");
    printf("%s","||                     ");
    printf("\033[1;33m");
    printf("%s","| |");
    printf("\033[0;32m");
    printf("%s","\n  `--.    ");
    printf("\033[1;33m");
    printf("%s","\\ ");
    printf("\033[0;32m");
    printf("%s",",-'   ");
    printf("\033[0;33m");
    printf("%s",";;                     ");
    printf("\033[1;33m");
    printf("%s","| |");
    printf("\033[0;32m");
    printf("%s","\n      |    ");
    printf("\033[1;33m");
    printf("%s","\\");
    printf("\033[0;32m");
    printf("%s","|    ");
    printf("\033[0;33m");
    printf("%s","//                  ,");
    printf("\033[1;37m");
    printf("%s",">");
    printf("\033[0;33m");
    printf("%s","-.");
    printf("\033[1;33m");
    printf("%s","| |");
    printf("\033[0;32m");
    printf("%s","\n      |     ");
    printf("\033[1;33m");
    printf("%s","\\   ");
    printf("\033[0;33m");
    printf("%s",";'                  ");
    printf("\033[1;37m");
    printf("%s","^    ");
    printf("\033[1;33m");
    printf("%s","|_|");
    printf("\033[0;32m");
    printf("%s","\n      |_____|");
    printf("\033[1;33m");
    printf("%s","\\");
    printf("\033[0;33m");
    printf("%s",",'                          ");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;36m");
    printf("%s","\n      :     :                             ");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;36m");
    printf("%s","\n      |  ,  |                             ");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;36m");
    printf("%s","\n      | : \\ :                             ");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;36m");
    printf("%s","\n      | | : :                             ");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;36m");
    printf("\n      | | ");
    printf("\033[0;33m");
    printf("| |                            /|\\");
    printf("\033[0;33m");
    printf("\n      | | |_`.                          / | \\");
    printf("\n      '--`                             /  |  \\");
    printf("\n                                          '");
    printf("\033[1;37m");
    printf("\n");
}

///MOSTRAR EDIFICIOS

void mostrar_castillo()
{
    system("cls");
    printf("\033[0;33m");
    printf("%s","                                  |");
    printf("\033[0;31m");
    printf("%s",">>>");
    printf("\033[0;33m");
    printf("%s","\n                                  |");
    printf("%s","\n                    |");
    printf("\033[0;31m");
    printf("%s",">>>      ");
    printf("\033[1;30m");
    printf("%s","_  _");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","_  _         ");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;31m");
    printf("%s",">>>");
    printf("\033[0;33m");
    printf("%s","\n                    |        ");
    printf("\033[1;30m");
    printf("%s","|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","| |");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","| |");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|        ");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","\n                _  _");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","_  _    \\\\");
    printf("\033[0;37m");
    printf("%s",".    .  ");
    printf("\033[1;30m");
    printf("%s","/    _  _");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[1;30m");
    printf("%s","_  _");
    printf("%s","\n               |");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|    \\\\");
    printf("\033[0;37m");
    printf("%s",":. ,  ");
    printf("\033[1;30m");
    printf("%s","/    |");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|");
    printf("%s","\n               \\\\");
    printf("\033[0;37m");
    printf("%s","..      ");
    printf("\033[1;30m");
    printf("%s","/    ||");
    printf("\033[0;37m");
    printf("%s",";   . ");
    printf("\033[1;30m");
    printf("%s","|    \\");
    printf("\033[0;37m");
    printf("%s",".    .  ");
    printf("\033[1;30m");
    printf("%s","/");
    printf("%s","\n                \\\\");
    printf("\033[0;37m");
    printf("%s",".  ,  ");
    printf("\033[1;30m");
    printf("%s","/     ||");
    printf("\033[0;37m");
    printf("%s",":  .  ");
    printf("\033[1;30m");
    printf("%s","|     \\");
    printf("\033[0;37m");
    printf("%s",":  .  ");
    printf("\033[1;30m");
    printf("%s","/");
    printf("%s","\n                 ||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","|_   _ ||_ ");
    printf("\033[0;37m");
    printf("%s",". ");
    printf("\033[1;30m");
    printf("%s","_ | _   _||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","|");
    printf("%s","\n                 ||");
    printf("\033[0;37m");
    printf("%s",":  .");
    printf("\033[1;30m");
    printf("%s","|||_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","|_|");
    printf("\033[0;37m");
    printf("%s",";");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",":.  ");
    printf("\033[1;30m");
    printf("%s","|");
    printf("%s","\n                 ||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",".    .     .      . ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",":  .");
    printf("\033[1;30m");
    printf("%s","|");
    printf("%s","\n                 ||");
    printf("\033[0;37m");
    printf("%s",": . ");
    printf("\033[1;30m");
    printf("%s","|| ");
    printf("\033[0;37m");
    printf("%s",".     . .   .  ");
    printf("%s",",   ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","|       ");
    printf("\033[1;37m");
    printf("%s","\\,/");
    printf("\033[1;30m");
    printf("%s","\n                 ||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",":  ,  ");
    printf("\033[1;30m");
    printf("%s","_______   ");
    printf("\033[0;37m");
    printf("%s",".   ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",": , ");
    printf("\033[1;30m");
    printf("%s","|            ");
    printf("\033[1;37m");
    printf("%s","/`\\");
    printf("\033[1;30m");
    printf("%s","\n                 ||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","|| ");
    printf("\033[0;37m");
    printf("%s",".   /+++++++\\    . ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","|");
    printf("%s","\n                 ||");
    printf("\033[0;37m");
    printf("%s",":   ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",".    |+++++++| .    ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",": . ");
    printf("\033[1;30m");
    printf("%s","|");
    printf("\033[0;32m");
    printf("%s","\n              __ ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",": . ");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;37m");
    printf("%s",": ,  |+++++++|.  . ");
    printf("\033[0;32m");
    printf("%s","_");
    printf("\033[1;30m");
    printf("%s","||");
    printf("\033[0;32m");
    printf("%s","_   ");
    printf("\033[1;30m");
    printf("%s","|");
    printf("\033[0;32m");
    printf("%s","\n     ____--`~    ");
    printf("\033[1;30m");
    printf("%s","'");
    printf("\033[0;32m");
    printf("%s","--~~__");
    printf("\033[1;30m");
    printf("%s","|");
    printf("\033[0;37m");
    printf("%s",".    |+++++");
    printf("\033[0;32m");
    printf("%s"," __");
    printf("\033[0;37m");
    printf("%s","|");
    printf("\033[0;32m");
    printf("%s","----~    ~`---,                ");
    printf("\033[0;32m");
    printf("%s","___");
    printf("\033[0;32m");
    printf("%s","\n-~--~                   ~---__");
    printf("\033[0;37m");
    printf("%s","|");
    printf("\033[1;32m");
    printf("%s",",--~'                  ");
    printf("\033[0;32m");
    printf("%s",",~~----_____-..~'   `");
    printf("\033[1;34m");
    printf("%s","~----~~");
    printf("\033[1;37m");

}

void mostrar_templo()
{
    system("cls");
    printf("\033[0;32m");
    printf("   `,.      ");
    printf("\033[1;33m");
    printf(".   .        *   .    .      .  _    ..          .");
    printf("\033[0;32m");
    printf("\n     \\,~-.         ");
    printf("\033[1;33m");
    printf("*           .    .       ))       *    .");
    printf("\033[0;32m");
    printf("\n          \\ ");
    printf("\033[1;33m");
    printf("%s","*          .   .   ");
    printf("\033[0;33m");
    printf("%s","|    ");
    printf("\033[1;33m");
    printf("%s","*  . .  ~    .      .  .  ");
    printf("\033[1;32m");
    printf("%s",",");
    printf("\033[0;32m");
    printf("%s","\n ,           `-.  ");
    printf("\033[1;33m");
    printf("%s",".            ");
    printf("\033[0;33m");
    printf("%s",":               ");
    printf("\033[1;33m");
    printf("%s","*           ");
    printf("\033[1;32m");
    printf("%s",",-");
    printf("\033[0;32m");
    printf("%s","\n  -             `-.        ");
    printf("\033[1;33m");
    printf("%s","*");
    printf("\033[1;30m");
    printf("%s","._/_\\_.       ");
    printf("\033[1;33m");
    printf("%s",".       .   ");
    printf("\033[1;32m");
    printf("%s",",-'");
    printf("\033[0;32m");
    printf("%s","\n  -                 `-_.,     ");
    printf("\033[1;31m");
    printf("%s","|n|");
    printf("\033[1;33m");
    printf("%s","     .      .       ");
    printf("\033[1;32m");
    printf("%s",";");
    printf("%s","\n    -                    \\ ");
    printf("\033[1;30m");
    printf("%s","._/_,_\\_.  ");
    printf("\033[1;33m");
    printf("%s",".          . ");
    printf("\033[1;32m");
    printf("%s",",'         ,");
    printf("\033[0;32m");
    printf("%s","\n     -                    `-.");
    printf("\033[1;31m");
    printf("%s","|.n.|      ");
    printf("\033[1;33m");
    printf("%s",".   ");
    printf("\033[1;32m");
    printf("%s",",-.__,'         -");
    printf("\033[0;32m");
    printf("%s","\n      -                   ");
    printf("\033[1;30m");
    printf("%s","._/_,_,_\\_.    ");
    printf("\033[1;32m");
    printf("%s",",-'              -");
    printf("\033[0;32m");
    printf("%s","\n      -                     ");
    printf("\033[1;31m");
    printf("%s","|..n..|");
    printf("\033[1;32m");
    printf("%s","-`'-'                -");
    printf("\033[0;32m");
    printf("%s","\n       -                 ");
    printf("\033[1;30m");
    printf("%s","._/_,_,_,_\\_.                 ");
    printf("\033[1;32m");
    printf("%s","-");
    printf("\033[0;32m");
    printf("%s","\n         -               ,-");
    printf("\033[1;31m");
    printf("%s","|...n...|                  ");
    printf("\033[1;32m");
    printf("%s","-");
    printf("\033[0;32m");
    printf("%s","\n           -         ");
    printf("\033[1;32m");
    printf("%s",",-'");
    printf("\033[1;30m");
    printf("%s","._/_,_,_,_,_\\_.              ");
    printf("\033[1;32m");
    printf("%s","-");
    printf("\033[0;32m");
    printf("%s","\n             -  ");
    printf("\033[1;32m");
    printf("%s",",-=-'     ");
    printf("\033[1;31m");
    printf("%s","|....n....|              ");
    printf("\033[1;32m");
    printf("%s","-");
    printf("\033[0;32m");
    printf("%s","\n              -");
    printf("\033[1;32m");
    printf("%s",";       ");
    printf("\033[1;30m");
    printf("%s","._/_,_,_,_,_,_\\_.         ");
    printf("\033[1;32m");
    printf("%s","-");
    printf("%s","\n             ,-          ");
    printf("\033[1;31m");
    printf("%s","|.....n.....|          ");
    printf("\033[1;32m");
    printf("%s","-");
    printf("\033[1;32m");
    printf("%s","\n           ,;         ");
    printf("\033[1;30m");
    printf("%s","._/_,_,_,_,_,_,_\\_.         ");
    printf("\033[1;32m");
    printf("%s","-");
    printf("\033[0;33m");
    printf("%s","\n  `,  '.  `.  \".  `,  '.");
    printf("\033[1;31m");
    printf("%s","| n   ");
    printf("\033[0;33m");
    printf("%s",",-.   ");
    printf("\033[1;31m");
    printf("%s","n |  ");
    printf("\033[0;33m");
    printf("%s","\",  `.  `,  '.  `,  ',");
    printf("\033[0;37m");
    printf("%s","\n,.:;..;;..;;.,:;,.;:,");
    printf("\033[0;33m");
    printf("%s","o");
    printf("\033[0;37m");
    printf("%s","__");
    printf("\033[1;31m");
    printf("%s","|");
    printf("\033[0;37m");
    printf("%s","__");
    printf("\033[0;33m");
    printf("%s","o ");
    printf("\033[0;33m");
    printf("%s","!.|.! ");
    printf("\033[0;33m");
    printf("%s","o");
    printf("\033[0;37m");
    printf("%s","__");
    printf("\033[1;31m");
    printf("%s","|");
    printf("\033[0;37m");
    printf("%s","__");
    printf("\033[0;33m");
    printf("%s","o");
    printf("\033[0;37m");
    printf("%s",";,.:;.,;;,,:;,.:;,;;:");
    printf("%s","\n ][  ][  ][  ][  ][  |_i_i_H_");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;37m");
    printf("%s","_");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;37m");
    printf("%s","_");
    printf("\033[0;33m");
    printf("%s","|");
    printf("\033[0;37m");
    printf("%s","_H_i_i_|  ][  ][  ][  ][  ][");
    printf("%s","\n                     |     ");
    printf("\033[1;31m");
    printf("%s","//");
    printf("\033[1;30m");
    printf("%s","=====");
    printf("\033[1;31m");
    printf("%s","\\\\     ");
    printf("\033[0;37m");
    printf("%s","|");
    printf("%s","\n                     |____");
    printf("\033[1;31m");
    printf("%s","//");
    printf("\033[1;30m");
    printf("%s","=======");
    printf("\033[1;31m");
    printf("%s","\\\\");
    printf("\033[0;37m");
    printf("%s","____|");
    printf("\033[1;31m");
    printf("%s","\n                         //");
    printf("\033[1;30m");
    printf("=========");
    printf("\033[1;31m");
    printf("\\\\    \n");
    printf("\033[1;37m");
}

void mostrar_puerta_cementerio()
{
    printf("                                {} {}                   \n");
    printf("                          !  !  II II  !  !                    \n");
    printf("                       !  I__I__II II__I__I  !                     \n");
    printf("                       I_/|--|--|| ||--|--|\\_I                   \n");
    printf("      .-'\\\"'-.      ! /|_/|  |  || ||  |  |\\_|\\ !       .-'\"'-.        \n");
    printf("     /===    \\      I//|  |  |  || ||  |  |  |\\ \\I     /===    \\          \n");
    printf("     \\==     /   ! /|/ |  |  |  || ||  |  |  | \\|\\ !   \\==     /           \n");
    printf("      \\__  _/    I//|  |  |  |  || ||  |  |  |  |\\\\I    \\__  _/            \n");
    printf("       _} {_  ! /|/ |  |  |  |  || ||  |  |  |  | \\|\\ !  _} {_             \n");
    printf("      {_____} I//|  |  |  |  |  || ||  |  |  |  |  |\\\\I {_____}            \n");
    printf(" !  !  |=  |=/|/ |  |  |  |  |  || ||  |  |  |  |  | \\|\\=|-  |  !  !      \n");
    printf("_I__I__|=  ||/|  |  |  |  |  |  || ||  |  |  |  |  |  |\\||   |__I__I_     \n");
    printf("-|--|--|-  || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||=  |--|--|-     \n");
    printf("_|__|__|   ||_|__|__|__|__|__|__|| ||__|__|__|__|__|__|_||-  |__|__|_     \n");
    printf("-|--|--|   ||-|--|--|--|--|--|--|| ||--|--|--|--|--|--|-||   |--|--|-     \n");
    printf(" |  |  |=  || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||   |  |  |      \n");
    printf(" |  |  |   || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||=  |  |  |      \n");
    printf(" |  |  |-  || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||   |  |  |      \n");
    printf(" |  |  |   || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||=  |  |  |       \n");
    printf(" |  |  |=  || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||   |  |  |       \n");
    printf(" |  |  |   || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||   |  |  |      \n");
    printf(" |  |  |   || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||-  |  |  |      \n");
    printf("_|__|__|   || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||=  |__|__|_     \n");
    printf("-|--|--|=  || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||   |--|--|-     \n");
    printf("_|__|__|   ||_|__|__|__|__|__|__|| ||__|__|__|__|__|__|_||-  |__|__|_     \n");
    printf("-|--|--|=  ||-|--|--|--|--|--|--|| ||--|--|--|--|--|--|-||=  |--|--|-     \n");
    printf("-|--|--|-  || |  |  |  |  |  |  || ||  |  |  |  |  |  | ||-  |  |  |      \n");
    printf("~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~~~~~~~~~~    \n");
}
///MENUS INTERACCION
void menu_batalla(personaje jugador,personaje enemigo,int turno)
{
    system("cls");
    printf("Es tu turno!\n");
    printf("\033[1;37m");
    printf("Vida:");
    printf("\033[1;32m");
    printf(" %.1f\n", jugador.vida);
    printf("\033[1;37m");
    printf("Armadura: ");
    printf("\033[1;36m");
    printf("%.1f %%\n", jugador.armadura);
    printf("\033[1;37m");
    printf("Energia disponible: ");
    printf("\033[1;34m");
    printf("%d\n", jugador.energia);
    printf("\033[1;37m");
    printf("Arma / Hechizo seleccionado: ");
    printf("\033[0;33m");
    printf("%s\n", jugador.stats.nombreArm);
    printf("\033[1;37m");
    printf("Turno %d --------------------------\n", turno);
    printf("Vida de %s : ",enemigo.nombre);
    printf("\033[1;35m");
    printf("%.1f\n", enemigo.vida);
    printf("\033[1;37m");


    mostrar_enemigo(enemigo);
}

void menu_batalla_opciones(int id)
{
    printf("\033[0;32m");
    printf("Acciones: ------------------------\n");
    printf("\033[0;37m");
    printf("- Ataque (1)");

    if(id == 0) ///arma
    {
        printf("\033[1;34m");
        printf(" (-20 E)\n");
        printf("\033[1;37m");
    }
    else if  (id==1)  ///hechizo
    {
        printf("\033[1;34m");
        printf(" (-100 E)\n");
        printf("\033[1;37m");
    }
    else
    {
        printf("\033[1;34m");
        printf(" (-20 E)\n");
        printf("\033[1;37m");
    }

    printf("- Inventario (2)\n");
    printf("\033[1;34m");
    printf("\033[1;37m");
    printf("- Defender y Cargar energia (3)");
    printf("\033[1;34m");
    printf("(+50 E) ");
    printf("\033[1;36m");
    printf("(+2,5%% A)\n");
    printf("\033[1;37m");
    printf("- Abandonar combate (4)\n");
    printf("\033[0;32m");
    printf("----------------------------------\n");
    printf("\033[0;37m");
}

void menuInventario()
{
    printf("\033[0;32m");
    printf("Inventario -----------------------\n");
    printf("\033[0;37m");
    printf("- Pociones (1)\n");
    printf("- Cambiar Arma | Hechizo (2)\n");
    printf("- Volver a menu inicial (3)\n\n");
    printf("\033[0;32m");
    printf("----------------------------------\n");
    printf("\033[0;37m");
}

///BATALLA
//ATAQUE
void muestra_ataque_magico_basico(personaje * atacante,int armadura)
{
    printf("\n -Infligido ");
    printf("\033[1;34m");
    printf("%d ",(atacante->stats.danioM + atacante->danioBase ) - armadura);
    printf("\033[1;37m");
    printf("puntos de vida al enemigo!\n");
}

void muestra_ataque_magico_critico(personaje * atacante)
{
    printf("\033[1;34m");
    printf("- REALIZADO UN ATAQUE CRITICO!");
    printf("\033[1;37m");
    printf(", ignoras la armadura e infliges el doble de puntos de vida ");
    printf("\033[1;34m");
    printf("(%d) ", ((atacante->stats.danioM + atacante->danioBase ) * 2));
    printf("\033[1;37m");
    printf("al enemigo \n");
}

void muestra_ataque_fisico_basico(personaje * atacante,int armadura)
{
    printf("\n -Infligido ");
    printf("\033[1;31m");
    printf("%d ",(atacante->stats.danioF + atacante->danioBase ) - armadura);
    printf("\033[1;37m");
    printf("puntos de vida al enemigo!\n");
}

void muestra_ataque_fisico_critico(personaje * atacante)
{
    printf("\033[1;31m");
    printf("- REALIZADO UN ATAQUE CRITICO!");
    printf("\033[1;37m");
    printf(", ignoras la armadura e infliges el doble de puntos de vida ");
    printf("\033[1;31m");
    printf("(%d) ", ((atacante->stats.danioF + atacante->danioBase ) * 2));
    printf("\033[1;37m");
    printf("al enemigo \n");
}

void muestra_ataque_veneno(personaje enemigo)
{
    printf("\n - %s ahora esta ",enemigo.nombre);
    printf("\033[0;33m");
    printf(" ENVENENDADO! \n");
    printf("\033[1;37m");
}

//DEFENSA

void muestra_defender_y_cargar_energia()
{
    printf("\033[1;34m");
    printf("   + 50 Puntos de energia\n");
    printf("\033[1;36m");
    printf("   + 3%% De armadura\n");
    printf("\033[1;37m");
}

//EFECTO

void muestra_efecto_hechizo(int efecto)
{
    if(efecto>0)
    {
        if(efecto==1)
            printf("\n -        EFECTO : ATURDIMIENTO! \n");
        else if(efecto==2)
            printf("\n -        EFECTO : DA%cO CONSTANTE! \n",165);
    }
}

void muestra_sufre_veneno()
{
    printf("\n -Sufres ");
    printf("\033[0;33m");
    printf("%d ",DANO_CONSTANTE);
    printf("\033[1;37m");
    printf("de da%co por el veneno! \n",164);
}

///INVENTARIO


void muestra_arma(arma dato_arma)
{
    printf("\n\n          - %s -",dato_arma.nombreArm);
    printf("\n -            ID: %d",dato_arma.id);
    if(!(dato_arma.estadoArma))
        printf("\n -ARMA ROTA-");

    printf("\n -  DA%cO FISICO : %d",165,dato_arma.danioF);
    printf("\n -  DA%cO MAGICO : %d",165,dato_arma.danioM);
    printf("\n -      CRITICO : %% %.2f",dato_arma.critico);


    if(dato_arma.danioF==0)
    {
        muestra_efecto_hechizo(dato_arma.efecto);
        printf(" - TIEMPO EFECTO : %d",dato_arma.cantidad_turnos_efecto);
    }
}

void muestra_lista_armas(personaje jugador,int tipo)
{
    nodo_base_inventario*lista=jugador.inventario[tipo].dato;

    while(lista!=NULL)
    {
        muestra_arma(lista->arma_dato);
        lista=lista->siguiente;
    }
}

void muestra_armas_hechizos(personaje jugador)
{
    printf("\033[0;33m");
    printf("\n -------------------");
    printf("\n -ARMAS Y HECHIZOS-\n");
    printf(" --------------------\n");
    printf("\033[0;31m");
    printf("\n\n -ARMAS: ");
    printf("\033[0;37m");
    muestra_lista_armas(jugador,0);

    printf("\033[1;34m");
    printf("\n\n -HECHIZOS: ");
    printf("\033[0;37m");
    muestra_lista_armas(jugador,1);
    printf("\033[0;32m");
    printf("\n-----------------------------------\n");
    printf("\033[0;37m");
}

void muestra_pocion(pocion dato_pocion)
{
    printf("\n - %s  (%d)-", dato_pocion.nombrePoc,dato_pocion.idPocion);
    switch(dato_pocion.idTipo)
    {
    case 1:
        printf("\033[0;32m");
        printf("\n -  + %d ",dato_pocion.aumento);
        printf("\033[0;37m");
        break;
    case 2:
        printf("\033[1;34m");
        printf("\n -  + %d ",dato_pocion.aumento);
        printf("\033[1;37m");
        break;
    case 3:
        printf("\033[1;31m");
        printf("\n -  + %d ",dato_pocion.aumento);
        printf("\033[1;37m");
        break;
    case 4:
        printf("\033[0;33m");
        printf("\n -  Cura Veneno! ");
        printf("\033[1;37m");
        break;
    default:
        printf("\n -ERROR:ID POCION NO VALIDA \n");
    }
    printf("\n\n");
}

void muestra_pociones(nodo_pocion*lista)
{
    if(lista!=NULL)
    {
        while(lista!=NULL)
        {
            muestra_pocion(lista->dato);
            lista=lista->siguiente;
        }
    }
    else
    {
        printf("\n-No tienes m%cs pociones!",160);
    }
    printf("\033[0;32m");
    printf("\n-------------------------------------------------\n");
    printf("\033[0;37m");
}

///IA | ENEMIGO

//ATAQUE

void muestra_ataque_fisico_critico_enemigo(personaje * atacante)
{
    printf("\033[1;31m");
    printf("- %s HA REALIZADO UN ATAQUE CRITICO!",atacante->nombre);
    printf("\033[1;37m");
    printf(", ignora tu armadura e inflige el doble a tus puntos de vida! ");
    printf("\033[1;31m");
    printf("(%d) ", ((atacante->stats.danioF + atacante->danioBase )* 2));
    printf("\033[1;37m");
}


void muestra_ataque_fisico_basico_enemigo(personaje * atacante,int armadura)
{
    printf("\n -%s a infligido ",atacante->nombre);
    printf("\033[1;31m");
    printf("%d ",(atacante->stats.danioF + atacante->danioBase ) - armadura);
    printf("\033[1;37m");
    printf("puntos de vida!\n");
}

void muestra_ataque_veneno_IA(personaje enemigo)
{
    printf("\n -%s ha Inflingido un ataque  ",enemigo.nombre);
    printf("\033[0;33m");
    printf(" VENENOSO! \n");
    printf("\033[1;37m");
}

//DEFENSA

void muestra_defender_y_cargar_energia_enemigo(personaje enemigo)
{
    printf("\n - %s se defiende! \n",enemigo.nombre);
    printf("\033[1;34m");
    printf("   + 50 Puntos de energia\n");
    printf("\033[1;36m");
    printf("   + 3%% De armadura\n");
    printf("\033[1;37m");
}

//BOOST DANO

void muestra_boost_danio_enemigo(personaje enemigo)
{
    printf("\n - %s se aumenta su da%co! \n",enemigo.nombre,164);
    printf("\033[1;31m");
    printf("   + 30 Puntos de da%co base! \n",164);
    printf("\033[1;37m");
}

//CURA

void muestra_cura_IA(personaje enemigo)
{
    printf("\n - %s se cura ! \n",enemigo.nombre);
    printf("\033[1;32m");
    printf("   + 250 Puntos de da%co base! \n",164);
    printf("\033[1;37m");
}

//SUFRE VENENO

void muestra_sufre_veneno_IA(personaje enemigo)
{
    printf("\n - %s sufre ",enemigo.nombre);
    printf("\033[0;33m");
    printf("%d ",DANO_CONSTANTE);
    printf("\033[1;37m");
    printf("de da%co por el veneno! \n",164);
}










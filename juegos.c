#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <pthread.h>

typedef struct{
    char usuario[20];
    int puntaje;
} Puntaje;
extern Puntaje puntajeUsuario;

typedef struct{
    char usuario[20];
    char contrasena[20];
} Usuario;

extern Usuario usuarioLogeado;

void cactus(int posX, int posY) {
    gotoxy(posX,posY);
    printf("    XX ");
    gotoxy(posX,posY+1);
    printf("  X XX");
    gotoxy(posX,posY+2);
    printf("  X XX X");
    gotoxy(posX,posY+3);
    printf("  XxXX X");
    gotoxy(posX,posY+4);
    printf("    XXxX ");
    gotoxy(posX,posY+5);
    printf("    XX    ");
    gotoxy(posX,posY+6);
    printf("    XX  ");
}

void animacionCactus() {
    int posX = 86;
    int posY = 21;
    for (int i = 0; i < 86; i++) {
        cactus(posX -i, posY);
        Sleep(200);
        borrarCactus(posX -i,posY);
    }
}

void pajaro(int posX, int posY) {
    gotoxy(posX,posY);
    printf(" <*     ");
    gotoxy(posX,posY+1);
    printf("   ----     ");
    gotoxy(posX, posY+2);
    printf("   \\\\     ");
    gotoxy(posX, posY+3);
    printf("          ");
    gotoxy(posX, posY+4);
    printf("        ");
}

void aleteoPajaro(int posX, int posY) {
    gotoxy(posX,posY);
    printf(" <* //    ");
    gotoxy(posX,posY+1);
    printf("   ----     ");
    gotoxy(posX, posY+2);
    printf("       ");
    gotoxy(posX, posY+3);
    printf("          ");
    gotoxy(posX, posY+4);
    printf("        ");
}

void borrarPajaro(int posX, int posY) {
    gotoxy(posX,posY);
    printf("     ");
    gotoxy(posX,posY+1);
    printf("       ");
    gotoxy(posX, posY+2);
    printf("       ");
    gotoxy(posX, posY+3);
    printf("          ");
    gotoxy(posX, posY+4);
    printf("        ");
}

void animacionPajaro(int posX, int posY) {

    for(int i = 0; i < 999; i++)
    {
    pajaro(posX-i-i, posY);
    Sleep(200);
    borrarPajaro(posX-i-i, posY);
    aleteoPajaro(posX-i-i, posY);
    Sleep(200);
    borrarPajaro(posX-i-i, posY);
    }
}

void borrarCactus(int posX, int posY) {
    gotoxy(posX,posY);
    printf("             ");
    gotoxy(posX,posY+1);
    printf("            ");
    gotoxy(posX,posY+2);
    printf("            ");
    gotoxy(posX,posY+3);
    printf("            ");
    gotoxy(posX,posY+4);
    printf("         ");
    gotoxy(posX,posY+5);
    printf("          ");
    gotoxy(posX,posY+6);
    printf("        ");
}

void dibujarDinosaurio(int posX, int posY) {
    gotoxy(posX, posY+4);
    printf("          %c%c%c%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+5);
    printf("         %c%c  %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-1, posY+6);
    printf("          %c%c%c%c%c%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+7);
    printf("         %c%c%c%c%c ", 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+8);
    printf("%c             %c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+9);
    printf("%c            %c%c%c%c%c ", 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+10);
    printf("%c%c         %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+11);
    printf("%c%c%c%c      %c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-4, posY+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-3, posY+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c",219 , 219, 219, 219, 219, 219, 219, 219, 219, 219,219);
    gotoxy(posX-2, posY+15);
    printf(" %c%c%c%c%c%c%c%c%c" , 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+16);
    printf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+17);
    printf("%c%c    %c%c", 219, 219, 219, 219);
    gotoxy(posX, posY+18);
    printf("%c      %c", 219, 219);
    gotoxy(posX, posY+19);
    printf("%c%c%c    %c%c%c   ", 219, 219, 219, 219, 219, 219);
}

void borrarDinosaurio(int posX, int posY) {
    gotoxy(posX, posY+4);
    printf("                             ");
    gotoxy(posX,posY+5);
    printf("                             ");
    gotoxy(posX-1,posY+6);
    printf("                             ");
    gotoxy(posX, posY+7);
    printf("                               ");
    gotoxy(posX-5, posY+8);
    printf("                                ");
    gotoxy(posX-5, posY+9);
    printf("                                ");
    gotoxy(posX-5, posY+10);
    printf("                                ");
    gotoxy(posX-5, posY+11);
    printf("                                 ");
    gotoxy(posX-5, posY+12);
    printf("                                   ");
    gotoxy(posX-4, posY+13);
    printf("                                    ");
    gotoxy(posX-3, posY+14);
    printf("                                    " );
    gotoxy(posX-2, posY+15);
    printf("                                     ");
    gotoxy(posX, posY+16);
    printf("                                     ");
    gotoxy(posX, posY+17);
    printf("                                      ");
    gotoxy(posX, posY+18);
    printf("                                     ");
    gotoxy(posX, posY+19);
    printf("                                  ");
}

void caminDinosaurio1(int posX, int posY) {
    gotoxy(posX, posY+4);
    printf("          %c%c%c%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX,posY+5);
    printf("         %c%c  %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-1,posY+6);
    printf("          %c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+7);
    printf("         %c%c%c%c%c ", 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+8);
    printf("%c             %c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+9);
    printf("%c            %c%c%c%c%c ", 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+10);
    printf("%c%c         %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+11);
    printf("%c%c%c%c      %c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-4, posY+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-3, posY+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c",219 , 219, 219, 219, 219, 219, 219, 219, 219, 219,219);
    gotoxy(posX-2, posY+15);
    printf(" %c%c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+16);
    printf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+17);
    printf("%c%c    %c%c", 219, 219, 219, 219);
    gotoxy(posX, posY+18);
    printf("%c      %c%c%c", 219, 219, 219, 219);
    gotoxy(posX, posY+19);
    printf("%c%c%c", 219, 219, 219);
}

void caminDinosaurio2(int posX, int posY)
{
     gotoxy(posX, posY+4);
    printf("          %c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX,posY+5);
    printf("         %c%c  %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-1,posY+6);
    printf("          %c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+7);
    printf("         %c%c%c%c%c ", 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+8);
    printf("%c             %c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+9);
    printf("%c            %c%c%c%c%c", 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+10);
    printf("%c%c         %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+11);
    printf("%c%c%c%c      %c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-5, posY+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-4, posY+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX-3, posY+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c",219 , 219, 219, 219, 219, 219, 219, 219, 219, 219,219);
    gotoxy(posX-2, posY+15);
    printf(" %c%c%c%c%c%c%c%c%c" , 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+16);
    printf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(posX, posY+17);
    printf("%c%c    %c%c", 219, 219, 219, 219);
    gotoxy(posX, posY+18);
    printf("%c%c%c    %c", 219, 219, 219, 219);
    gotoxy(posX, posY+19);
    printf("       %c%c%c", 219, 219, 219, 219, 219, 219);
}

void puntaje() {
    int contador = 0;
    gotoxy(84,1);
    printf("Puntaje: %d", contador);
    for(contador; contador < 9999999; contador++) {
        gotoxy(84,1);
        printf("Puntaje: [%d]", contador);
        Sleep(100);
        if(contador == 100)
        {
            Beep(500,300);
        }
        if(contador == 200)
        {
            Beep(500,300);
        }if(contador == 300)
        {
            Beep(500,300);
        }if(contador == 400)
        {
            Beep(500,300);
        }if(contador == 500)
        {
            Beep(500,300);
        }if(contador == 600) {
            Beep(500,300);
        }if(contador == 700) {
            Beep(500,300);
        }if(contador == 800) {
            Beep(500,300);
        }if(contador == 900) {
            Beep(500,300);
        }if(contador == 1000) {
            Beep(500,300);
        }if(contador == 1100) {
            Beep(500,300);
        }if(contador == 1200) {
            Beep(500,300);
        }if(contador == 1300) {
            Beep(500,300);
        }if(contador == 1400) {
            Beep(500,300);
        }if(contador == 1500) {
            Beep(500,300);
        }if(contador == 1600) {
            Beep(500,300);
        }if(contador == 1700) {
            Beep(500,300);
        }if(contador == 1800) {
            Beep(500,300);
        } if(contador == 1900) {
            Beep(500,300);
        } if(contador == 2000) {
            Beep(500,300);
        } if(contador == 2100) {
            Beep(500,300);
        } if(contador == 2200) {
            Beep(500,300);
        }
    }

}

void cancion() {
    while (1){
        sndPlaySound("TemaDino.wav", 0);
    }
}


void MarcoYPuntaje() {
    marco();
    puntaje();
}


void juego() {

    //INICIALIZO VARIABLES
    int frame = 0;
    int frameTime = 10; //CADA CUANTOS MS SE REFRESCA EL FRAME
    int jugando = 1; //FLAG PARA EL GAME LOOP

    //POSICION DINO
    const int xDino = 20;
    const int yDinoInicial = 8;
    int yDino = yDinoInicial;

    //ESTADO DINO (0:PATA ARRIBA, 1: PATA ABAJO, 2: SALTANDO)
    int estadoDino = 0;
    int saltando = 0;
    const int duracionSalto = 10; //CONFIGURACION
    int frameSalto; //VARIABLE PARA EL CICLO DEL SALTO

    //POSICION INICIAL CACTUS
    const int xCactusInicial = 90;
    int xCactus = xCactusInicial;
    const int yCactus = 21;

    marco();

    //GAME LOOP
    while(jugando == 1) {

        char teclaUsuario = 0;

        //CONTROL SALTO
        if(kbhit()) {
            fflush(stdin);
            teclaUsuario = getch();
            if(teclaUsuario == 'w'){
                saltando = 1;
                frameSalto = duracionSalto;
            }
        }

        //MOVIMIENTO SALTO
        if(saltando == 0) { //SI NO ESTÁ SALTANDO
            if((frame % 5) == 0) { //ANIMACION CAMINAR
                if(estadoDino == 0) {
                    estadoDino = 1;
                    borrarDinosaurio(xDino, yDino);
                    caminDinosaurio1(xDino, yDino);
                } else {
                    estadoDino = 0;
                    borrarDinosaurio(xDino, yDino);
                    caminDinosaurio2(xDino, yDino);
                }
            }
        } else { //SI ESTÁ SALTANDO
            estadoDino = 2;
            if(frameSalto <= duracionSalto && frameSalto > 0) { //ELEVO EL DINO
                dibujarDinosaurio(xDino, yDino);
                borrarDinosaurio(xDino, yDino);
                yDino--;
                frameSalto--;
            } else if(yDino != yDinoInicial){ //BAJO EL DINO
                dibujarDinosaurio(xDino, yDino);
                borrarDinosaurio(xDino, yDino);
                yDino++;
            }
        }

        //SI EL DINO YA ESTÁ EN EL PISO VUELVO AL ESTADO 0 Y ASIGNO SALTANDO = 0
        if(yDino == yDinoInicial && estadoDino != 1){
            estadoDino = 0;
            saltando = 0;
        }

        dibujarDinosaurio(xDino, yDino);

        //MOVIMIENTO CACTUS
        if((frame % 1) == 0 && xCactus > 1) {
            gotoxy(xCactus, yCactus);
            printf("   XX  ");
            gotoxy(xCactus, yCactus+1);
            printf(" X XX    ");
            gotoxy(xCactus, yCactus+2);
            printf(" X XX X   ");
            gotoxy(xCactus, yCactus+3);
            printf(" XxXX X   ");
            gotoxy(xCactus, yCactus+4);
            printf("   XXxX   ");
            gotoxy(xCactus, yCactus+5);
            printf("   XX   ");
            gotoxy(xCactus, yCactus+6);
            printf("   XX   ");
            xCactus--;
        } else {
            gotoxy(xCactus, yCactus);
            printf("        ");
            gotoxy(xCactus, yCactus+1);
            printf("        ");
            gotoxy(xCactus, yCactus+2);
            printf("        ");
            gotoxy(xCactus, yCactus+3);
            printf("        ");
            gotoxy(xCactus, yCactus+4);
            printf("        ");
            gotoxy(xCactus, yCactus+5);
            printf("        ");
            gotoxy(xCactus, yCactus+6);
            printf("        ");

            xCactus = xCactusInicial;
        }

        gotoxy(84,1);
        printf("puntaje: [%d]", frame);

        //COLISION
        if(yDino == 8 && xCactus == 20) {
            jugando = 0;
        }

        frame++;

        int velocidad = 0;

        if(frame > 50)
        {
            velocidad = 2;
        }if(frame > 100)
        {
            velocidad = 4;
        }if(frame > 150)
        {
            velocidad = 6;
        }if(frame > 200)
        {
            velocidad = 8;
        }if(frame > 250)
        {
            velocidad = 12;
        }if(frame > 300)
        {
            velocidad = 14;
        }if(frame > 350)
        {
            velocidad = 16;
        }if(frame > 400)
        {
            velocidad = 18;
        }

        Sleep(25-velocidad);


        //Sleep(frameTime);
        /*
        if((frame % 100) == 0) { //AUMENTO LA VELOCIDAD
            frameTime = frameTime - 1;
        }
        */
    };

    //CREO PUNTAJE A GUARDAR
    strcpy(puntajeUsuario.usuario,usuarioLogeado.usuario);
    puntajeUsuario.puntaje = frame;
    guardarPuntuacion(puntajeUsuario);
    /*
    printf("%s",puntajeUsuario.usuario);
    printf("%i",puntajeUsuario.puntaje);
    getch();
    */
    GameOver(1,1,frame);
}


void iniciarJuego() {
    pthread_t hiloMusica;
    pthread_t hiloJuego;
    pthread_create(&hiloMusica, NULL, cancion, NULL);
    pthread_create(&hiloJuego, NULL, juego, NULL);
    pthread_join(hiloMusica, NULL);
    pthread_join(hiloJuego, NULL);
}

void GameOver(int x, int y, int puntaje)
{
    marco();
    gotoxy(x,y);
    printf("%s","     ::::::::      :::       :::   :::   ::::::::::      ::::::::  :::     ::: :::::::::: :::::::::\n");
    gotoxy(x,y+1);
    printf("%s","    :+:    :+:   :+: :+:    :+:+: :+:+:  :+:           :+:    :+: :+:     :+: :+:        :+:    :+:\n");
    gotoxy(x,y+2);
    printf("%s","   +:+         +:+   +:+  +:+ +:+:+ +:+ +:+           +:+    +:+ +:+     +:+ +:+        +:+    +:+\n");
    gotoxy(x,y+3);
    printf("%s","  :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#      +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:\n");
    gotoxy(x,y+4);
    printf("%s"," +#+  #+#+# +#+     +#+ +#+       +#+ +#+           +#+    +#+  +#+   +#+  +#+        +#+    +#+\n");
    gotoxy(x,y+5);
    printf("%s","#+#    #+# #+#     #+# #+#       #+# #+#           #+#    #+#   #+#+#+#   #+#        #+#    #+#\n");
    gotoxy(x,y+6);
    printf("%s","########  ###     ### ###       ### ##########    ########      ###     ########## ###    ###\n");
    gotoxy(x,y+7);
    printf("%s","       :::   :::  ::::::::  :::    :::          :::        ::::::::   ::::::::  ::::::::::\n");
    gotoxy(x,y+8);
    printf("%s","      :+:   :+: :+:    :+: :+:    :+:          :+:       :+:    :+: :+:    :+: :+:\n");
    gotoxy(x,y+9);
    printf("%s","      +:+ +:+  +:+    +:+ +:+    +:+          +:+       +:+    +:+ +:+        +:+\n");
    gotoxy(x,y+10);
    printf("%s","      +#++:   +#+    +:+ +#+    +:+          +#+       +#+    +:+ +#++:++#++ +#++:++#\n");
    gotoxy(x,y+11);
    printf("%s","      +#+    +#+    +#+ +#+    +#+          +#+       +#+    +#+        +#+ +#+\n");
    gotoxy(x,y+12);
    printf("%s","     #+#    #+#    #+# #+#    #+#          #+#       #+#    #+# #+#    #+# #+#\n");
    gotoxy(x,y+12);
    printf("%s","     ###     ########   ########           ########## ########   ########  ##########\n");

    gotoxy(1,15);
    printf("%s"," _______ _______  _______  _______  ______ \n");
    gotoxy(1,15+1);
    printf("%s","|  ____ \|  ____ ||  ___  ||  ____ ||  ____|                        \n");
    gotoxy(1,15+2);
    printf("%s","| |   \/ | |    \/ | |   | || |    ||| |        _____________       ~~~~~~~~~~~~~~~~~~~~~~\n");
    gotoxy(1,15+3);
    printf("%s","| |____ | |      | |   | || |____||| |__     |_____________|      *                    *\n");
    gotoxy(1,15+4);
    printf("%s","|_____ || |      | |   | ||     __||  __|     _____________       *                    *\n");
    gotoxy(1,15+5);
    printf("%s", "     | || |      | |   | ||  __ |  | |       |_____________|      *                    *\n");
    gotoxy(1,15+6);
    printf("%s","/\____| || |____/\ | |___| || |  ||__| |____                        ~~~~~~~~~~~~~~~~~~~~~~\n");
    gotoxy(1,15+7);
    printf("%s","\_______||_______/|_______||__| |__/|______| \n");

    gotoxy(76,19);
    printf("%d", puntaje);

    boton(7,25,"[V]OLVER");
    boton(7+22,25,"[J]UGAR DE NUEVO");
    boton(7+22*2,25,"[M]AX PUNTUACIONES");
    boton(7+22*3,25,"[S]ALIR");

    switch(getch()) {
        case 'j': juego();
        break;

        case 'm': MaxPuntuaciones();
        break;

        case 's': salir();
        break;

        case 'v': bienvenida();
        break;

        default: GameOver(1,1,puntaje);
        break;
    }
}

void MaxPuntuaciones() {
    marco();
    gotoxy(8,1);
    printf("%s","______  _______          ______         ________                                 \n");
    gotoxy(8,1+1);
    printf("%s","___  / / /___(_)_______ ____  /__       __  ___/_____________ _____________ ________ \n");
    gotoxy(8,1+2);
    printf("%s","__  /_/ / __  / __  __ `/__ __  /       _____  \ _  ___/ _  __ \__  ___/_   _  \__  ___/ \n");
    gotoxy(8,1+3);
    printf("%s","_  __  /  _  /  _  /_/ / _ / / /        ____/ / / /__   / /_/ /_  /    /  __/_(__  ) \n");
    gotoxy(8,1+4);
    printf("%s","/_/ /_/   /_/     __, / /_/ /_/        /_____/ /____/  /_____/ /_/    /____/ /____/ \n");
    gotoxy(8,1+5);
    printf("%s","                /____/                                                              \n");

    mostrarPuntuaciones();

    boton(5,25,"[V]OLVER");
    boton(40,25,"[J]UGAR DE NUEVO");
    boton(75,25,"[S]ALIR");

    switch(getch()) {
        case 'j': juego();
        break;

        case 's': salir();
        break;

        case 'v': bienvenida();
        break;

        default: MaxPuntuaciones();
        break;
    }
}

void guardarPuntuacion(Puntaje puntaje) {
    FILE* archivo;
    archivo = fopen("puntajes.bin","ab");
    if(archivo != NULL){
        fwrite(&puntaje, sizeof(Puntaje), 1, archivo);
    }
    fclose(archivo);
}

void mostrarPuntuaciones(){

    //ABRO EL ARCHIVO DE PUNTAJES
    FILE* archivo;
    archivo = fopen("puntajes.bin","rb");
    Puntaje puntajeArchivo;

    Puntaje puntajes[100];
    int i = 0;
    while(fread(&puntajeArchivo,sizeof(Puntaje),1,archivo) > 0){
        strcpy(puntajes[i].usuario,puntajeArchivo.usuario);
        puntajes[i].puntaje = puntajeArchivo.puntaje;
        i++;
    }
    fclose(archivo);

    //OBTENGO ORDENADAMENTE LOS 10 MEJORES PUNTAJES
    ordernarPuntuaciones(puntajes,i);

    //IMPRIMO EN PANTALLA
    int ii = 0;
    int x = 30;
    int y = 10;

    while(ii < 6){
        gotoxy(x,y);
        toUpperString(puntajes[ii].usuario);
        printf("%s",puntajes[ii].usuario);
        gotoxy(x+30,y);
        printf("%i",puntajes[ii].puntaje);
        gotoxy(x,y+1);
        for(int i = 0; i < 40;i++){
            printf("%c",196);
        }
        y=y+2;
        ii++;
    }
}

void ordernarPuntuaciones(Puntaje *puntuaciones,int validos){

    Puntaje puntuacionesAux[validos];
    Puntaje puntuacionMax = {"",0};
    int ii = 0;
    int posicionMaxPuntuacion = 0;

    while(ii <= 5 && ii <= validos){
        for(int i = 0; i < validos;i++){ //CICLO RECORRE ARRAY ORIGINAL (LARGO 100)
            if(puntuacionMax.puntaje < puntuaciones[i].puntaje) {
                strcpy(puntuacionMax.usuario, puntuaciones[i].usuario);
                puntuacionMax.puntaje = puntuaciones[i].puntaje;
                posicionMaxPuntuacion = i;
            }
        }

        puntuacionesAux[ii] = puntuacionMax;
        puntuaciones[posicionMaxPuntuacion].puntaje = 0;
        puntuacionMax.puntaje = 0;
        ii++;
    }

    for(int i = 0;i <= validos; i++){
        puntuaciones[i] = puntuacionesAux[i];
    }
}







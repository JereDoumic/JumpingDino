#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct{
    char usuario[20];
    int puntaje;
} Puntaje;
Puntaje puntajeUsuario = {"",0};

typedef struct{
    char usuario[20];
    char contrasena[20];
} Usuario;
Usuario usuarioLogeado = {"INVITADO",""};

void main() {

    bienvenida();


}



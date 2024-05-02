/// INTERFAZ GRÁFICA DE MENUS
#include <conio.h>
#include <stdio.h>
#include <string.h>
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

void bienvenida();
void registrarse();
void iniciarSesion();
void cerrarSesion();
void salir();
void skins();

const int anchoVentana = 100;
const int altoVentana = 30;

void bienvenida() {
    marco();
    titulo(20,5);
    if(strcmpi(usuarioLogeado.usuario,"Invitado") == 0){
        boton(25,15+3*1,"[I]NICIAR SESION");
        boton(25,15+3*2,"[R]EGISTRARSE");
    } else {
        boton(25,15+3*1,"[P]ERFIL");
        boton(25,15+3*2,"[C]ERRAR SESION");
    }
    boton(55,15+3*1,"[J]UGAR");
    boton(55,15+3*2,"[M]AX PUNTUACIONES");
    boton(55,15+3*3,"[S]ALIR");
    boton(25,15+3*3,"[E]SKINS");



    gotoxy(3,27);
    char mensajeLogin[50];
    strcpy(mensajeLogin,usuarioLogeado.usuario);
    toUpperString(mensajeLogin);
    printf("%s",mensajeLogin);


    switch(getch()){
        case 'r': registrarse();
        break;
        case 'i': iniciarSesion();
        break;
        case 'c':
            cerrarSesion();
            bienvenida();
        break;
        case 'j': iniciarJuego();
        break;
        case 's': salir();
        break;
        case 'm': MaxPuntuaciones();
        break;
        case 'p': perfil();
        break;
        case 'e': skins();
        break;
        default: bienvenida();
        break;
    }

};



void skins()
{
    marco();
    dibujarDinosaurio(20,8);
    char teclaUsuario;
    teclaUsuario = getch();
        if(teclaUsuario == 'd')
        {
            color(02);
            dibujarDinosaurio(20,8);

        }
        if(teclaUsuario == 'f')
        {
            color(02);
            dibujarDinosaurio(20,8);
        }



}

void registrarse() {

    ///VISUAL
    marco();

    gotoxy(2,1);
    printf("REGISTRARSE");
    gotoxy(1,2);
    for(int i = 0; i <= anchoVentana-2;i++){
        printf("%c",196);
    }
    input(5,5,"USUARIO");
    input(5,5+2,"CONTRASENA");
    input(5,5+4,"REPETIR CONTRASENA:");

    ///FUNCIONALIDAD
    Usuario usuario;
    char input_usuario[20];
    char input_contrasena[20];
    char input_contrasena2[20];

    gotoxy(5+12,5);
    fflush(stdin);
    gets(&input_usuario);

    gotoxy(5+12,5+2);
    fflush(stdin);
    gets(&input_contrasena);

    gotoxy(5+12,5+4);
    fflush(stdin);
    gets(&input_contrasena2);

    //CHEQUEO SI CONTRASEÑAS COINCIDEN
    if(!strcmp(input_contrasena,input_contrasena2)) {
        strcpy(usuario.usuario,input_usuario);
        strcpy(usuario.contrasena,input_contrasena);

        FILE* archivo;
        archivo = fopen("usuarios.bin","r+b");

        int existe = 0;

        if(archivo != NULL){
            Usuario usuarioArchivo;
            while(fread(&usuarioArchivo,sizeof(Usuario),1,archivo) > 0 && existe == 0){
                if(!strcmp(usuario.usuario,usuarioArchivo.usuario)){
                    existe = 1;
                }
            }

            if(existe == 1 ) {
                mensaje(20,20,"USUARIO YA EXISTE");
            } else {
                mensaje(20,20,"REGISTRO EXITOSO");
                fseek(archivo, 0, SEEK_END);
                fwrite(&usuario, sizeof(Usuario), 1, archivo);
            }
            fclose(archivo);
        }
        getch();
        bienvenida();

    } else {
        mensaje(20,20,"ERROR. LAS CONTRASENAS NO COINCIDEN");
        getch();
        bienvenida();
    }
}

void iniciarSesion() {
    marco();
    gotoxy(2,1);
    printf("INICIAR SESION");
    gotoxy(1,2);
    for(int i = 0; i <= anchoVentana-2;i++){
        printf("%c",196);
    }
    //mostrarUsuarios();
    input(5,5,"Usuario");
    input(5,5+2,"Contrasena");

    //FUNCIONALIDAD
    char input_usuario[20];
    char input_contrasena[20];

    gotoxy(5+12,5);//usuario
    fflush(stdin);
    gets(&input_usuario);

    gotoxy(5+12,5+2);//contrasena
    fflush(stdin);
    gets(&input_contrasena);

    if(validarUsuarioContrasena(input_usuario,input_contrasena) == 1){
        strcpy(usuarioLogeado.usuario,input_usuario);
        char mensajeBienvenida[] = "BIENVENIDO ";
        strcat(mensajeBienvenida,input_usuario);
        toUpperString(mensajeBienvenida);
        mensaje(10,10,mensajeBienvenida);
        getch();
        bienvenida();
    } else {
        mensaje(10,10,"LOGIN FALLIDO");
        getch();
        bienvenida();
    }
}

void salir(){
    exit(1);
}

void marco(){

    gotoxy(0,0);

    ///FILA SUPERIOR
    printf("%c",201);
    for(int i = 0; i <= anchoVentana-2;i++){
        printf("%c",205);
    }
    printf("%c",187);

    ///FILA INTERMEDIA
    for(int i = 1; i <= altoVentana-2;i++){
        gotoxy(0,i);
        printf("%c",186);
            for(int i = 0; i <= anchoVentana-2;i++){
            printf("%c",32);
        }
        gotoxy(anchoVentana,i);
        printf("%c",186);
    }

    ///FILA INFERIOR
    gotoxy(0,altoVentana-2);
    printf("%c",200);
    for(int i = 0; i <= anchoVentana-2;i++){
        printf("%c",205);
    }
    printf("%c",188);

}

void boton(int x, int y, char texto[]) {

    const int ancho = 20;
    const int alto = 3;

    gotoxy(x,y);

    ///FILA SUPERIOR
    printf("%c",218);
    for(int i = 0; i <= ancho-2;i++){
        printf("%c",196);
    }
    printf("%c",191);

    ///FILA INTERMEDIA
    for(int i = 0; i < alto-2;i++){

        gotoxy(x,y+i+1);
        printf("%c",179);

        gotoxy(x+((ancho/2)-(strlen(texto)/2)),y+i+1);
        printf("%s",texto);/* IMPRIMO EL TEXTO*/

        gotoxy(x+ancho,y+i+1);
        printf("%c",179);

    }

    ///FILA INFERIOR
    gotoxy(x,y+alto-1);
    printf("%c",192);

    for(int i = 0; i <= ancho-2;i++){
        printf("%c",196);
    }
    printf("%c",217);
}

void input(int x, int y, char label[]){

    gotoxy(x,y);
    printf("%s:", label);
    gotoxy(x+12,y);
    printf("_____________________________");

}


void titulo(int x, int y){
    gotoxy(x,y);
    printf("%s","   ___                       _              ______ _             \n");
    gotoxy(x,y+1);
    printf("%s","  |_  |                     (_)             |  _  (_)            \n");
    gotoxy(x,y+2);
    printf("%s","    | |_   _ _ __ ___  _ __  _ _ __   __ _  | | | |_ _ __   ___  \n");
    gotoxy(x,y+3);
    printf("%s","    | | | | | '_ ` _ \\| '_ \\| | '_ \\ / _` | | | | | | '_ \\ / _ \\ \n");
    gotoxy(x,y+4);
    printf("%s","/\\__/ / |_| | | | | | | |_) | | | | | (_| | | |/ /| | | | | (_) |\n");
    gotoxy(x,y+5);
    printf("%s","\\____/ \\__,_|_| |_| |_| .__/|_|_| |_|\\__, | |___/ |_|_| |_|\\___/ \n");
    gotoxy(x,y+6);
    printf("%s","                      | |             __/ |                      \n");
    gotoxy(x,y+7);
    printf("%s","                      |_|            |___/                       \n");
}

void mostrarUsuarios(){
    FILE* archivo;
    archivo = fopen("usuarios.bin","rb");

    Usuario usuario;

    while(fread(&usuario,sizeof(Usuario),1,archivo) > 0){
        printf("posicion: %i\n",ftell(archivo));
        printf("usuario: %s\n",usuario.usuario);
        printf("pass: %s\n\n",usuario.contrasena);

    }
    fclose(archivo);
}

int validarUsuarioContrasena(char usuario[20], char contrasena[20]){
    FILE* archivo;
    archivo = fopen("usuarios.bin","rb");
    Usuario usuario2;
    int userPassCheck = 0;

    while(fread(&usuario2,sizeof(Usuario),1,archivo) > 0 && userPassCheck == 0){
            /*
            printf("usuario: %s\n",usuario);
            printf("usuario2.usuario: %s\n",usuario2.usuario);
            printf("%i\n",strcmpi(usuario,usuario2.usuario));
            printf("contrasena: %s\n",contrasena);
            printf("usuario2.contrasena: %s\n",usuario2.contrasena);
            printf("%i\n",strcmpi(contrasena,usuario2.contrasena));
            */

        if(strcmpi(usuario,usuario2.usuario) == 0 && strcmpi(contrasena,usuario2.contrasena) == 0){
            userPassCheck = 1;
        }
    }
    fclose(archivo);
    return userPassCheck;
}

void cerrarSesion(){
    strcpy(usuarioLogeado.usuario,"Invitado");
    strcpy(usuarioLogeado.contrasena,"");
}

void mensaje(int x, int y, char texto[]) {

    const int ancho = 40;
    const int alto = 3;

    gotoxy(x,y);

    ///FILA SUPERRIOR
    printf("%c",218);
    for(int i = 0; i <= ancho-2;i++){
        printf("%c",196);
    }
    printf("%c",191);

    ///FILA INTERMEDIA
    for(int i = 0; i < alto-2;i++){

        gotoxy(x,y+i+1);
        printf("%c",179);

        gotoxy(x+((ancho/2)-(strlen(texto)/2)),y+i+1);
        printf("%s",texto);/* IMPRIMO EL TEXTO*/

        gotoxy(x+ancho,y+i+1);
        printf("%c",179);

    }

    ///FILA INFERIOR
    gotoxy(x,y+alto-1);
    printf("%c",192);

    for(int i = 0; i <= ancho-2;i++){
        printf("%c",196);
    }
    printf("%c",217);
}

void perfil(){
    marco();
    gotoxy(24,1);
    printf("%s","  _____    ______   _____    ______   _____   _       ");
    gotoxy(24,1+1);
    printf("%s"," |  __ \\  |  ____| |  __ \\  |  ____| |_   _| | |     ");
    gotoxy(24,1+2);
    printf("%s"," | |__) | | |__    | |__) | | |__      | |   | |     ");
    gotoxy(24,1+3);
    printf("%s"," |  ___/  |  __|   |  _  /  |  __|     | |   | |     ");
    gotoxy(24,1+4);
    printf("%s"," | |      | |____  | | \\ \\  | |       _| |_  | |____ ");
    gotoxy(24,1+5);
    printf("%s"," |_|      |______| |_|  \\_\\ |_|      |_____| |______|");

    boton(5,10,"USUARIO");
    gotoxy(30,11);
    printf("%s", usuarioLogeado.usuario);

    boton(5,13,"[C]AMBIA CONTRASENA");


    boton(5,25,"[V]OLVER");
    boton(40,25,"[J]UGAR");
    boton(75,25,"[S]ALIR");

    switch(getch())
    {
        case 'v': bienvenida();
        break;

        case 'j': juego();
        break;

        case 's': salir();
        break;

        case 'c': cambiaContrasena();
        break;

        default: perfil();
        break;
    }
}

void cambiaContrasena() {
    Usuario usuarioAux = {"",""};

    char input_contrasena[20];
    char input_contrasena2[20];

    input(5,19,"CONTRASENA");
    input(5,22,"REPETIR:");

    gotoxy(5+12,19);
    fflush(stdin);
    gets(&input_contrasena);

    gotoxy(5+12,22);
    fflush(stdin);
    gets(&input_contrasena2);

    int encontrado = 0;

    if(!strcmp(input_contrasena2, input_contrasena)){
        FILE* archivo;
        archivo = fopen("usuarios.bin","r+b");
        if (archivo != NULL) {
            while(fread(&usuarioAux, sizeof(Usuario), 1, archivo) > 0 && encontrado == 0) {
                if(!strcmp(usuarioLogeado.usuario, usuarioAux.usuario)) {
                    encontrado = 1;

                    strcpy(usuarioAux.contrasena,input_contrasena);
                    strcpy(usuarioAux.usuario,usuarioLogeado.usuario);

                    fseek(archivo, sizeof(Usuario)* -1, SEEK_CUR);
                    fwrite(&usuarioAux, sizeof(Usuario), 1, archivo);

                    mensaje(35,20,"CONTRASENA CAMBIADA CON EXITO");
                }
            }
        } else {
            mensaje(35,20,"ERROR AL ABRIR EL ARCHIVO");
        }
        fclose(archivo);
    } else {
        mensaje(35,20,"LAS CONTRASENAS NO COINCIDEN");
    }
    getch();
    bienvenida();
}

#ifndef FUNCIONESDIBUJO_H_INCLUDED
#define FUNCIONESDIBUJO_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"

using namespace std;
using namespace rlutil;

///------------------- DECLARACION DE FUNCIONES----------------------

void bordes(int);
// DIBUJO DE LAS LINEAS DEL BORDE DEL PROGRAMA

void menuPrincipal();

void underlineDraw(int x, int y, int m);
// SUBRAYADO DE TITULOS

void dibujoDados(int y);
// DIBUJO DE LOS DADOS, LA Y DETERMINA LA ALTURA DE LOS DADOS


int selectDraw(int x, int y, int y2, int s); // int s = saltos
// CON ESTO SE DIBUJA LAS FLECHAS DE LOS MENUS | x = POSICION EN X DE LAS FLECHAS, y = PRIMERA OPCION DEL MENU, y2 = ULTIMA OPCION DEL MENU

void limpiarDados();

void dibujar1(int n_dado);

void dibujar2(int n_dado);

void dibujar3(int n_dado);

void dibujar4(int n_dado);

void dibujar5(int n_dado);

void dibujar6(int n_dado);


///------------------- DESARROLLO FUNCIONES ----------------------

void menuPrincipal()
{
    locate(6,6);
    setColor(BLUE);
    printf("%c", 158);
    setColor(WHITE);
    cout << " Un jugador";
    locate(6,8);
    setColor(BLUE);
    printf("%c", 158);
    setColor(WHITE);
    cout << " Dos jugadores";
    locate(6,10);
     setColor(BLUE);
    printf("%c", 158);
    setColor(WHITE);
    cout << " Puntuacion maxima";
    locate(6,12);
    setColor(BLUE);
    printf("%c", 158);
    setColor(WHITE);
    cout << " Salir";
}

void dibujar1(int n_dado)
{
    switch(n_dado)
    {
    case 0:
        locate(11, 9);
        printf("%c", 254);
        break;
    case 1:
        locate(26, 9);
        printf("%c", 254);
        break;
    case 2:
        locate(41, 9);
        printf("%c", 254);
        break;
    case 3:
        locate(56, 9);
        printf("%c", 254);
        break;
    case 4:
        locate(71, 9);
        printf("%c", 254);
        break;
    case 5:
        locate(86, 9);
        printf("%c", 254);
        break;

    }
}

void dibujar2(int n_dado)
{
    switch(n_dado)
    {
    case 0:
        locate(8, 8);
        printf("%c", 254);
        locate(14, 10);
        printf("%c", 254);
        break;
    case 1:
        locate(23, 8);
        printf("%c", 254);
        locate(29, 10);
        printf("%c", 254);
        break;
    case 2:
        locate(38, 8);
        printf("%c", 254);
        locate(44, 10);
        printf("%c", 254);
        break;
    case 3:
        locate(53, 8);
        printf("%c", 254);
        locate(59, 10);
        printf("%c", 254);
        break;
    case 4:
        locate(68, 8);
        printf("%c", 254);
        locate(74, 10);
        printf("%c", 254);
        break;
    case 5:
        locate(83, 8);
        printf("%c", 254);
        locate(89, 10);
        printf("%c", 254);
        break;
    }
}

void dibujar3(int n_dado)
{
    switch(n_dado)
    {
    case 0:
        locate(11, 9);
        printf("%c", 254);
        locate(8, 8);
        printf("%c", 254);
        locate(14, 10);
        printf("%c", 254);
        break;
    case 1:
        locate(26, 9);
        printf("%c", 254);
        locate(23, 8);
        printf("%c", 254);
        locate(29, 10);
        printf("%c", 254);
        break;
    case 2:
        locate(41, 9);
        printf("%c", 254);
        locate(38, 8);
        printf("%c", 254);
        locate(44, 10);
        printf("%c", 254);
        break;
    case 3:
        locate(56, 9);
        printf("%c", 254);
        locate(53, 8);
        printf("%c", 254);
        locate(59, 10);
        printf("%c", 254);
        break;
    case 4:
        locate(71, 9);
        printf("%c", 254);
        locate(68, 8);
        printf("%c", 254);
        locate(74, 10);
        printf("%c", 254);
        break;
    case 5:
        locate(86, 9);
        printf("%c", 254);
        locate(83, 8);
        printf("%c", 254);
        locate(89, 10);
        printf("%c", 254);
        break;
    }
}

void dibujar4(int n_dado)
{
    switch(n_dado)
    {
    case 0:
        locate(8, 8);
        printf("%c", 254);
        locate(14, 8);
        printf("%c", 254);
        locate(14, 10);
        printf("%c", 254);
        locate(8, 10);
        printf("%c", 254);
        break;
    case 1:
        locate(23, 8);
        printf("%c", 254);
        locate(29, 10);
        printf("%c", 254);
        locate(29, 8);
        printf("%c", 254);
        locate(23, 10);
        printf("%c", 254);
        break;
    case 2:
        locate(38, 8);
        printf("%c", 254);
        locate(44, 10);
        printf("%c", 254);
        locate(44, 8);
        printf("%c", 254);
        locate(38, 10);
        printf("%c", 254);
        break;
    case 3:
        locate(53, 8);
        printf("%c", 254);
        locate(59, 10);
        printf("%c", 254);
        locate(59, 8);
        printf("%c", 254);
        locate(53, 10);
        printf("%c", 254);
        break;
    case 4:
        locate(68, 8);
        printf("%c", 254);
        locate(74, 10);
        printf("%c", 254);
        locate(74, 8);
        printf("%c", 254);
        locate(68, 10);
        printf("%c", 254);
        break;
    case 5:
        locate(83, 8);
        printf("%c", 254);
        locate(89, 10);
        printf("%c", 254);
        locate(89, 8);
        printf("%c", 254);
        locate(83, 10);
        printf("%c", 254);
        break;
    }

}

void dibujar5(int n_dado)
{
    switch(n_dado)
    {
    case 0:
        locate(11, 9);
        printf("%c", 254);
        locate(8, 8);
        printf("%c", 254);
        locate(14, 8);
        printf("%c", 254);
        locate(14, 10);
        printf("%c", 254);
        locate(8, 10);
        printf("%c", 254);
        break;
    case 1:
        locate(26, 9);
        printf("%c", 254);
        locate(23, 8);
        printf("%c", 254);
        locate(29, 10);
        printf("%c", 254);
        locate(29, 8);
        printf("%c", 254);
        locate(23, 10);
        printf("%c", 254);
        break;
    case 2:
        locate(41, 9);
        printf("%c", 254);
        locate(38, 8);
        printf("%c", 254);
        locate(44, 10);
        printf("%c", 254);
        locate(44, 8);
        printf("%c", 254);
        locate(38, 10);
        printf("%c", 254);
        break;
    case 3:
        locate(56, 9);
        printf("%c", 254);
        locate(53, 8);
        printf("%c", 254);
        locate(59, 10);
        printf("%c", 254);
        locate(59, 8);
        printf("%c", 254);
        locate(53, 10);
        printf("%c", 254);
        break;
    case 4:
        locate(71, 9);
        printf("%c", 254);
        locate(68, 8);
        printf("%c", 254);
        locate(74, 10);
        printf("%c", 254);
        locate(74, 8);
        printf("%c", 254);
        locate(68, 10);
        printf("%c", 254);
        break;
    case 5:
        locate(86, 9);
        printf("%c", 254);
        locate(83, 8);
        printf("%c", 254);
        locate(89, 10);
        printf("%c", 254);
        locate(89, 8);
        printf("%c", 254);
        locate(83, 10);
        printf("%c", 254);
        break;
    }
}

void dibujar6(int n_dado)
{
    switch(n_dado)
    {
    case 0:
        locate(8, 9);
        printf("%c", 254);
        locate(14, 9);
        printf("%c", 254);
        locate(8, 8);
        printf("%c", 254);
        locate(14, 8);
        printf("%c", 254);
        locate(14, 10);
        printf("%c", 254);
        locate(8, 10);
        printf("%c", 254);
        break;
    case 1:
        locate(23, 9);
        printf("%c", 254);
        locate(29, 9);
        printf("%c", 254);
        locate(23, 8);
        printf("%c", 254);
        locate(29, 10);
        printf("%c", 254);
        locate(29, 8);
        printf("%c", 254);
        locate(23, 10);
        printf("%c", 254);
        break;
    case 2:
        locate(38, 9);
        printf("%c", 254);
        locate(44, 9);
        printf("%c", 254);
        locate(38, 8);
        printf("%c", 254);
        locate(44, 10);
        printf("%c", 254);
        locate(44, 8);
        printf("%c", 254);
        locate(38, 10);
        printf("%c", 254);
        break;
    case 3:
        locate(53, 9);
        printf("%c", 254);
        locate(59, 9);
        printf("%c", 254);
        locate(53, 8);
        printf("%c", 254);
        locate(59, 10);
        printf("%c", 254);
        locate(59, 8);
        printf("%c", 254);
        locate(53, 10);
        printf("%c", 254);
        break;
    case 4:
        locate(68, 9);
        printf("%c", 254);
        locate(74, 9);
        printf("%c", 254);
        locate(68, 8);
        printf("%c", 254);
        locate(74, 10);
        printf("%c", 254);
        locate(74, 8);
        printf("%c", 254);
        locate(68, 10);
        printf("%c", 254);
        break;
    case 5:
        locate(83, 9);
        printf("%c", 254);
        locate(89, 9);
        printf("%c", 254);
        locate(83, 8);
        printf("%c", 254);
        locate(89, 10);
        printf("%c", 254);
        locate(89, 8);
        printf("%c", 254);
        locate(83, 10);
        printf("%c", 254);
        break;
    }
}


void dibujoDados(int n_dado)
{

int x = 6, y = 4;
int anteriorY = y;

for(int j=1; j<=6; j++)
{
    locate(x, y);

    printf("%c", 201);
    for(int i=1; i<=9; i++)
    {
    printf("%c", 205);
    }
    printf("%c", 187);

    y++;

    locate(x,y); ///

    printf("%c", 186);
    for(int i=1; i<=9; i++)
    {
    printf("%c", 92);
    }
    printf("%c", 186);

    y++;

    locate(x,y); ///

    printf("%c", 186);
    for(int i=1; i<=9; i++)
    {
    printf("%c", 92);
    }
    printf("%c", 186);

    y++;

    locate(x,y); ///

    printf("%c", 204);
     for(int i=1; i<=9; i++)
    {
    printf("%c", 205);
    }
    printf("%c", 185);

    y++;

    for(int i = 1; i<=3; i++)
    {
       locate(x,y); ///
       printf("%c", 186);
       locate(x+10,y);
       printf("%c", 186);
       y++;
    }

    locate(x,y); ///
    printf("%c", 200);
    for(int i=1; i<=9; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);

    x+= 15;
    y = anteriorY;
}
}


void limpiarDados()
{
    int x = 8, anteriorY, y = 8;

    anteriorY = y;

        for(int j=1; j<=6; j++)
        {
            for(int i=1; i<=3; i++)
           {
               locate(x, y);
               cout << "       ";
               y++;
           }

           y = anteriorY;
           x +=15;
        }

}
/// ---------- DESARROLLO DE DIBUJOS GRALES ---------


void bordes(int c){
  int y = 1, y2 = 1, x=2, x2=1;

switch(c)
{
case 1:
    y = 1;
    y2 = 1;
    x=2;
    x2=1;
    rlutil::setColor(CYAN);
    printf("%c", 219);
    for(int i = 0; i<=28; i++)
    {
        y++;
        rlutil::locate(1,y);
        printf("%c", 219);
    }
    rlutil::locate(1,30);
    printf("%c", 223);

    // Fin borde izq

    rlutil::locate(120,1);
    printf("%c", 219);
    for(int i = 0; i<=28; i++)
    {
        y2++;
        rlutil::locate(120,y2);
        printf("%c", 219);
    }

    rlutil::locate(120,30);
    printf("%c", 223);

    // DIBUJO DE BORDES HORIZONTALES

    rlutil::locate(2,1);
    printf("%c", 223);
    for(int i=2; i<119; i++)
    {
        x++;
        rlutil::locate(x,1);
        printf("%c", 223);
    }
    for(int i=2; i<120; i++)
    {
        x2++;
        rlutil::locate(x2,30);
        printf("%c", 223);
    }
    break;
case 2:
    rlutil::setColor(LIGHTBLUE);
    printf("%c", 219);
    for(int i = 0; i<=28; i++)
    {
        rlutil::locate(1,y);
        printf("%c", 219);
        y++;
    }
    rlutil::locate(1,30);
    printf("%c", 223);

    // Fin borde izq

    rlutil::locate(120,1);
    printf("%c", 219);
    for(int i = 0; i<=28; i++)
    {
        y2++;
        rlutil::locate(120,y2);
        printf("%c", 219);
    }

    rlutil::locate(120,30);
    printf("%c", 223);

    // DIBUJO DE BORDES HORIZONTALES

    rlutil::locate(2,1);
    printf("%c", 223);
    for(int i=2; i<119; i++)
    {
        x++;
        rlutil::locate(x,1);
        printf("%c", 223);
    }
    for(int i=2; i<120; i++)
    {
        x2++;
        rlutil::locate(x2,30);
        printf("%c", 223);
    }
    break;
case 3:
    rlutil::setColor(RED);
    printf("%c", 219);
    for(int i = 0; i<=28; i++)
    {
        rlutil::locate(1,y);
        printf("%c", 219);
        y++;
    }
    rlutil::locate(1,30);
    printf("%c", 223);

    // Fin borde izq

    rlutil::locate(120,1);
    printf("%c", 219);
    for(int i = 0; i<=28; i++)
    {
        y2++;
        rlutil::locate(120,y2);
        printf("%c", 219);
    }

    rlutil::locate(120,30);
    printf("%c", 223);

    // DIBUJO DE BORDES HORIZONTALES

    rlutil::locate(2,1);
    printf("%c", 223);
    for(int i=2; i<119; i++)
    {
        x++;
        rlutil::locate(x,1);
        printf("%c", 223);
    }
    for(int i=2; i<120; i++)
    {
        x2++;
        rlutil::locate(x2,30);
        printf("%c", 223);
    }
    break;
}

    setColor(WHITE);

}

void underlineDraw(int x, int y, int m){
    rlutil::setColor(LIGHTBLUE);
    for(int i=0; i<=m; i++){
        x++;
        rlutil::locate(x,y);
        printf("%c", 196);
    }
    rlutil::setColor(rlutil::WHITE);
}

int selectDraw(int x, int y, int y2, int s){
rlutil::setColor(rlutil::BLUE);
int val_Y = y, key = 1;

rlutil::locate(x, val_Y);
printf("%c", 174);

   rlutil::locate(x, val_Y);
cout << " ";
rlutil::locate(x, val_Y);
printf("%c", 174);

    while(key != 13){
        key = getch();
        switch (key)
        {
        case 80:
            rlutil::locate(x, val_Y);
            cout << " ";
            val_Y+=s;
            rlutil::locate(x, val_Y);
            printf("%c", 174);
            if(val_Y>y2)
            {
            rlutil::locate(x, val_Y);
            cout << " ";
            val_Y-=s;
            rlutil::locate(x, val_Y);
            printf("%c", 174);
            }
            break;

        case 72:
            rlutil::locate(x, val_Y);       /* Arregle un error de las flechas que se dibujaba otra al subir - Sergio*/
            cout << " ";
            val_Y-=s;
            if(val_Y<y)
            {
                locate(x,val_Y);
                cout << " ";
                val_Y+=s;
                locate(x, val_Y);
                printf("%c", 174);
            }
            rlutil::locate(x, val_Y);
            printf("%c", 174);
            break;
        }
    }

    setColor(WHITE);
    return val_Y; // SE DEVUELVE LA ULTIMA UBICACION DE LA FLECHA AL PONER ENTER

}
#endif // FUNCIONESDIBUJO_H_INCLUDED

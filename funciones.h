#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <iostream>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

///------------------- DECLARACION DE FUNCIONES----------------------

int selectDraw(int x, int y, int y2); 
// CON ESTO SE DIBUJA LAS FLECHAS DE LOS MENUS | x = POSICION EN X DE LAS FLECHAS, y = PRIMERA OPCION DEL MENU, y2 = ULTIMA OPCION DEL MENU

///------------------- DESARROLLO DE FUNCIONES ----------------------

int selectDraw(int x, int y, int y2){
rlutil::setColor(rlutil::LIGHTBLUE);
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
            val_Y++;
            rlutil::locate(x, val_Y);
            printf("%c", 174);
            if(val_Y>y2)
            {
            rlutil::locate(x, val_Y);
            cout << " ";
            val_Y--;
            rlutil::locate(x, val_Y);
            printf("%c", 174);
            }
            break;

        case 72:
            rlutil::locate(x, val_Y);      
            cout << " ";
            val_Y--;
            if(val_Y<y)
            {
                locate(x,val_Y);
                cout << " ";
                val_Y++;
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

#endif // FUNCIONES_H_INCLUDED

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <iostream>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

int selectDraw(int x, int y, int y2); // CON ESTO SE DIBUJA LAS FLECHAS DE LOS MENUS

int selectDraw(int x, int y, int y2){

rlutil::setColor(rlutil::LIGHTBLUE);
int val_Y = y, key = 1;

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
            break;
        case 72:
            rlutil::locate(x, val_Y);
            cout << " ";
            val_Y--;
            rlutil::locate(x, val_Y);
            printf("%c", 174);
            break;
        }
        if(val_Y>y2)
        {
            rlutil::locate(x, val_Y);
            cout << " ";
            val_Y--;
            rlutil::locate(x, val_Y);
            printf("%c", 174);
        }
        else
        {
            if(val_Y<y)
            {
                rlutil::locate(x, val_Y);
                cout << " ";
                val_Y++;
                rlutil::locate(x, val_Y);
                printf("%c", 174);
            }
        }

    }

    setColor(WHITE);
    return val_Y;

}


#endif // FUNCIONES_H_INCLUDED

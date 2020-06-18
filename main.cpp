#include <iostream>
#include <conio.h>
#include "rlutil.h"
#include "funciones.h"

using namespace std;
using namespace rlutil;

int main()
{

int valF; // Lo que devuelve la flecha

   while(true)
    {
        system("cls");
    cout << "- Un jugador\n";
    cout << "- Dos jugadores\n";
    cout << "-Puntuacion maxima\n";
    cout << "-Salir\n";

    valF = selectDraw(20, 1, 4);

    switch(valF)
    {
    case 1:
        system("cls");
        cout << "1\n";
        system("pause");

        break;
    case 2:
        system("cls");
        cout << "2\n";
        system("pause");
        break;

    case 3:
        system("cls");
        cout << "max\n";
        system("pause");
        break;
    case 4:
        return 0;
        break;


    }


    }


    return 0;
}

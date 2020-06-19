#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "rlutil.h"
#include "funciones.h"
#include "dibujofunciones.h"

using namespace std;
using namespace rlutil;

int main()
{

int valorFlechita; // Lo que devuelve la flecha

   while(true)
    {
    system("cls");
    cout << "- Un jugador\n";
    cout << "- Dos jugadores\n";
    cout << "- Puntuacion maxima\n";
    cout << "- Salir\n";

    valorFlechita = selectDraw(25, 1, 4);

    switch(valorFlechita) // MENU
    {
    case 1:             // OPCION DE UN JUGADOR
        system("cls");

        borderDraw();   // SE DIBUJAN LOS BORDES DE PANTALLA

        unJugador();    // FUNCION DE UN JUGADOR

        system("pause");

        break;
    case 2:           // OPCION DE DOS JUGADORES
        system("cls");

        borderDraw();   // SE DIBUJAN LOS BORDES DE PANTALLA

        /*dosJugadores(); // FUNCION DE DOS JUGADORES*/

        system("pause");
        break;

    case 3:         // OPCION DE MAX PUNTUACION
        system("cls");
        cout << "max\n";
        system("pause");
        break;
    case 4:         // SALIR
        return 0;
        break;


    }


    }


    return 0;
}

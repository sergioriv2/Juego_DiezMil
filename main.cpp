#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "rlutil.h"
#include "funciones.h"
#include "dibujofunciones.h"
#include "juego.h"

using namespace rlutil;
using namespace std;

int main()
{
    setConsoleTitle("Diez Mil");
    int valorFlechita;
    int  Val = 0;
    char listanombres[10][15], nombre1[15], nombre2[15];
    int  puntajes[10], ValorY = 5, puntuacion;

    ponerEnCero(puntajes, 10);

    limpiarListaNombres(listanombres);

    while(true)
    {

        if(Val>=10)
        {
            Val = 0;
        }

        system("cls");

        bordes(2);

        titulo();

        menuPrincipal();

        valorFlechita = selectDraw(27, 6, 12, 2);

        switch(valorFlechita) // MENU
        {
        case 6:  // OPCION DE UN JUGADOR

            system("cls");

            bordes(1);

            unJugador(nombre1);

            bordes(1);

            puntuacion = gameplay_1(nombre1);

            // PUNTUACION FINAL

            strcpy(listanombres[Val], nombre1);
            puntajes[Val] = puntuacion;
            Val++;

            break;
        case 8:         // OPCION DE DOS JUGADORES

            system("cls");

            bordes(1);

            dosJugadores(nombre1, nombre2);

            puntuacion = gameplay_2(nombre1, nombre2);

            // PUNTUACION FINAL

            break;
        case 10:  // OPCION DE MAX PUNTUACION

            system("cls");

            bordes(1);

            locate(5, 3);
            cout << "Nombres";
            locate(20, 3);
            cout << "Ronda ganadora";
            locate(5, ValorY);

            for(int i=0; i<10; i++)
            {
                ValorY++;
                locate(5, ValorY);
                cout << i+1 << ". "<< listanombres[i];
            }

            ValorY = 5;

            for(int i=0; i<10; i++)
            {
                ValorY++;
                locate(20, ValorY);
                cout << "    " << puntajes[i] <<"";
            }


            locate(5, 20);

            system("pause");

            break;
        case 12:   // SALIR

            return 0;

            break;

        }
    }

    return 0;
}

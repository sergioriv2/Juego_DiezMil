#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "rlutil.h"
#include "funciones.h"
#include "dibujofunciones.h"

using namespace rlutil;
using namespace std;

int main()
{

int valorFlechita; // Lo que devuelve la flecha
bool jugar = true; // DECLARACION DE VARIABLES GENERALES
char nombre1[20], nombre2[20], nombres[5][20];
int ronda = 0, rondamax, lanzamiento = 0, puntuacion = 0, puntuacionM, puntuacionG[5];
int valorDados[6]; // DECLARACION DE VARIABLE PARA LOS DADOS

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

        rondamax = unJugador(nombre1);    // FUNCION DE UN JUGADOR


    underlineDraw(2, 3, 115);

    locate(3, 2);
    cout << "TURNO DE: ";
    setColor(GREEN);
    cout << nombre1;
    setColor(WHITE);
    locate(26, 2);
    cout << "|\tRONDA N: ";
    setColor(GREEN);
    cout << ronda;
    setColor(WHITE);
    locate(49, 2);
    cout << "|\tLANZAMIENTO N: ";
    setColor(GREEN);
    cout << lanzamiento;
    setColor(WHITE);
    locate(77, 2);
    cout << "|\tPUNTUACION ACTUAL: ";
    setColor(GREEN);
    cout << puntuacion;
    setColor(WHITE);

    dibujoDados(4);

    locate(6, 20);
    cout << "Lanzar dados";

    while(jugar)
    {
        for(int i=1; i<=rondamax; i++)
        {
            dibValorDados(ronda, valorDados);

        valorFlechita = selectDraw(20, 20, 21);

        switch(valorFlechita)
        {

        case 20:

            ronda++;
            lanzamiento++;

            locate(42, 2);
            setColor(GREEN);
            cout << ronda;
            locate(72, 2);
            cout << lanzamiento;
            setColor(WHITE);


            limpiarDados();

            tirarDados(valorDados, 1);

            for(int i=0; i<6; i++)
            {
                switch(valorDados[i])
                {
                case 1:
                    dibujar1(i);
                    break;
                case 2:
                    dibujar2(i);
                    break;
                case 3:
                    dibujar3(i);
                    break;
                case 4:
                    dibujar4(i);
                    break;
                case 5:
                    dibujar5(i);
                    break;
                case 6:
                    dibujar6(i);
                    break;
                }
            }

                    locate(6,23);
                    cout << "(Valores del vector de dados): ";
                    locate(6, 25);

                    mostrarDados(valorDados);

                    getch();

                    break;
                }
        }

        jugar = false;

            }

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

        borderDraw();

        /*puntuacionG = puntuacionMax()*/


        system("pause");
        break;
    case 4:         // SALIR
        return 0;
        break;


    }
    
    }

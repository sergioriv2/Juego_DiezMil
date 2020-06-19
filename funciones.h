#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "rlutil.h"
#include "dibujofunciones.h"

using namespace std;
using namespace rlutil;

///------------------- DECLARACION DE FUNCIONES----------------------


void tirarDados(int vecDados[], bool azar);
// FUNCION GENERAL PARA TIRAR DADOS, C = CANTIDAD DE DADOS, BOOL 1 = DADOS AL AZAR, BOOL 0 = DADOS MANUALMENTE

void mostrarDados(int vecDados[]);

void ingame1(char nombre[15]);
// DESAROLLO DEL JUEGO PARA 1 JUGADOR

void ingame2(char nombre1[15], char nombre2[15]);
// DESARROLLO DEL JUEGO PARA 2 JUGADORES

void unJugador();

void dosJugadores();

void puntuacionMax();

void dibValorDados(int ronda, int dados[]);

///------------------- DESARROLLO DE FUNCIONES ----------------------

void unJugador()
{
    char nombreJ1[15];

    locate(50, 3);
    cout << "UN JUGADOR";
    underlineDraw(49, 4, 9);

    locate(46,9);
    cout << "--------------";

    locate(46,6);
    cout << "Ingresa tu nombre\n";
    locate(46,8);
    cin.getline(nombreJ1, 15);

    system("cls");
    borderDraw();

    ingame1(nombreJ1);

}

void ingame1(char nombre[15])
{
    int ronda = 0, lanzamiento = 0, puntuacion = 0, jugar = true, valorFlechita; // DECLARACION DE VARIABLES GENERALES
    int valorDados[6]; // DECLARACION DE VARIABLE PARA LOS DADOS

    underlineDraw(2, 3, 115);

    locate(3, 2);
    cout << "TURNO DE: ";
    setColor(GREEN);
    cout << nombre;
    setColor(WHITE);
    cout << "    |\tRONDA N: ";
    setColor(GREEN);
    cout << ronda;
    setColor(WHITE);
    cout << "    |\tLANZAMIENTO N: ";
    setColor(GREEN);
    cout << lanzamiento;
    setColor(WHITE);
    cout << "    |\tPUNTUACION ACTUAL: ";
    setColor(GREEN);
    cout << puntuacion;
    setColor(WHITE);

    dibujoDados(4);

    locate(6, 20);
    cout << "Lanzar dados";

    while(jugar)
    {
        dibValorDados(ronda, valorDados);

        valorFlechita = selectDraw(20, 20, 21);

        switch(valorFlechita)
        {

        case 20:

            ronda++;
            lanzamiento++;

            locate(34, 2);
            setColor(GREEN);
            cout << ronda;
            locate(56, 2);
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

                    locate(6, 25);

                    mostrarDados(valorDados);

                    getch();

                    break;
                }
            }

        }


/// --------- DESARROLLO DADOS ---------------------

        void mostrarDados(int vecDados[])
        {
            for(int i=0; i<6; i++)
            {
                cout << vecDados[i] <<"\t";
            }
        }

        void tirarDados(int vecDados[], bool azar)
        {

            if(azar==1)
            {

                srand(time(NULL));
                int n;
                for(int i=0; i<6; i++)
                {
                    n = rand()%6+1;
                    vecDados[i] = n;
                }

            }
            else
            {
                cout << "Ingrese los valores de los dados\n";
                for(int i=0; i<6; i++)
                {
                    cin >> vecDados[i];
                }

            }

        }

        void dibValorDados(int ronda, int dados[])
        {
            int x = 8, anteriorY, y = 8;

            anteriorY = y;

            if(ronda == 0)
            {
                setColor(LIGHTRED);
                for(int j=1; j<=6; j++)
                {
                    for(int i=1; i<=3; i++)
                    {
                        locate(x, y);
                        cout << "???????";
                        y++;
                    }

                    y = anteriorY;
                    x += 15;
                }
                setColor(WHITE);
            }

        }






#endif // FUNCIONES_H_INCLUDED

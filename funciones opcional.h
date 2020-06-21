#ifndef FUNCIONES_GITHUB_H_INCLUDED
#define FUNCIONES_GITHUB_H_INCLUDED

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
/// FUNCION GENERAL PARA TIRAR DADOS, C = CANTIDAD DE DADOS, BOOL 1 = DADOS AL AZAR, BOOL 0 = DADOS MANUALMENTE

void mostrarDados(int vecDados[]);

int ronda (int t);

void ingame1(char nombre[15]);
/// DESAROLLO DEL JUEGO PARA 1 JUGADOR

void ingame2(char nombre1[15], char nombre2[15]);
/// DESARROLLO DEL JUEGO PARA 2 JUGADORES

int unJugador(char );

void dosJugadores();

int puntuacionMax();

void dibValorDados(int ronda, int dados[]);

void nombMax (char mayorJugador[5][20]);

int siguejuego(bool sigue);

///------------------- DESARROLLO DE FUNCIONES ----------------------

int unJugador(char nom[])/// dejo de ser void por que busco el retorno del nombre de la persona y que quede fijo en main mientras se juega.
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

    return nombreJ1; ///probar si funciona bien el retorno para que figure en main continuamente

    /*ingame1(nombreJ1);*/

}

/*void ingame1(char nombre[15])
{


    char ronda= 0, lanzamiento = 0, puntuacion = 0, jugar = true, valorFlechita; /// DECLARACION DE VARIABLES GENERALES
    int valorDados[6]; /// DECLARACION DE VARIABLE PARA LOS DADOS
    cout<<nombre
    underlineDraw(2, 3, 115);

   locate(3, 2);
    cout << "TURNO DE: ";
    setColor(GREEN);
    cout << nombre;
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
                    locate(6,23);
                    cout << "(Valores del vector de dados): ";

                    locate(6, 25);

                    mostrarDados(valorDados);

                    getch();

                    break;
                }
            }

}

*/

int round (int t){  ///la cantidad de rondas

int s;



    locate(51,16);
    cin<<s;

    return s;

}

bool siguejuego(bool sigue){ /// para dos jugadores





}


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
    return val_Y; // SE DEVUELVE LA ULTIMA UBICACION DE LA FLECHA AL PONER ENTER

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

        /*void dibValorDados(int ronda, int dados[])

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

        }*/



int puntuacionMax (int maximo){

int s;

        s=partidas[0];

for(int forx=0; forx<partidas; forx++){



     if(partidas[forx]>s){

        s=partidas[forx];


     }

}


///en main se debe validar que la partida  primera (vector posicion 0, )no contenga un valor 0, si el vaor es 0 cartel aclaratorio diciendo que no se jugo partida


return s;

}

void nombMax (char mayorJugador[10][20], int pos){



    cout<<mayorJugador[i]



}


#endif /// FUNCIONES_H_INCLUDED

#endif /// FUNCIONES_GITHUB_H_INCLUDED

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

/*void ingame1(char nombre[15]);
// DESAROLLO DEL JUEGO PARA 1 JUGADOR*/

void ingame2(char nombre1[], char nombre2[]);
// DESARROLLO DEL JUEGO PARA 2 JUGADORES

void dadosPrimeraRonda(int ronda, int dados[]);
// MUESTRA " ? ? ? " EN LOS DADOS DURANTE LA PRIMERA RONDA O RONDA 0

void dosJugadores(char nombre1[], char nombre2[]);

void limpiarListaNombres(char lista[10][15]);


int unJugador(char nombreJ1[]);


/// -------------- DECLARACION DE FUNCIONES DE LAS JUGADAS ----------------


int jugadas(int vecDados[]);

int juegoDeUno(int vecDados[]);

int juegoDeCinco(int vecDados[]);

int trioUno(int vecDados[]);

int trioP(int vecDados[]);

int trioPP(int vecDados[]);

int trioAmpliado(int vecDados[]);

int tresPares(int vecDados[]);

int escaleraLarga(int vecDados[]);

int sexteto(int vecDados[]);

/// -------------- DESARROLLO DE LAS FUNCIONES DE LAS JUGADAS ----------------


int jugadas(int vecDados[6])
{
    int puntos = 0;

    puntos += tresPares(vecDados);

    return puntos;
}



int tresPares(int vecdados[6])
{

int vecdadoscomp[6], analizar, contar, par = 0, puntos = 0;
bool bandera = false;

for(int i=0; i<6; i++)
{
    vecdadoscomp[i] = vecdados[i];
}


for(int i=0; i<6; i++)
{

    if(bandera == true)
    {
        for(int k=0; k<6; k++)
        {
            if(vecdadoscomp[k] == analizar)
            {
                vecdadoscomp[k] = 0;
            }
        }

        bandera = false;
    }

    contar = 0;
    analizar = vecdados[i];

    for(int j=0; j<6; j++)
    {
        if(vecdadoscomp[j]!=0)
        {
            if(vecdadoscomp[j] == analizar)
            {
                contar++;
            }
        }
    }
    bandera = true;

    if(contar == 2)
    {
        par++;
    }
    if(contar == 4)
    {
        par+=2;
    }
    if(contar == 6)
    {
        par+=3;
    }

}

if(par == 3)
{
    cout << "Jugada de pares !";
    puntos = 1000;
}

return puntos;

}


///------------------- DESARROLLO DE FUNCIONES ----------------------

void limpiarListaNombres(char lista[10][15])
{
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<10; j++)
        {
            lista[j][i] = '\0';
        }
    }
}

int unJugador(char nombreJ1[])
{
    int rondasg;
    bordes(1);

    locate(50, 3);
    cout << "UN JUGADOR";
    underlineDraw(49, 4, 9);

    locate(27,8);
    cout << "Ingresa tu nombre:";
    locate(46,8);
    cin.getline(nombreJ1, 15);

    locate(27,10);
    cout << "Ingresa la cantidad";
    locate(27, 11);
    cout << "de rondas ganadoras:  ";
    cin >> rondasg;

    cin.ignore();

    system("cls");

return rondasg;
}

void dosJugadores(char nombre1[], char nombre2[])
{
    bordes(1);
    locate(50, 3);
    cout << "DOS JUGADORES";
    underlineDraw(49, 4, 12);


    locate(27,8);
    cout << "Nombre del jugador 1:";
    locate(49,8);
    cin.getline(nombre1, 15);


    bordes(3);

    locate(27,10);
    cout << "Nombre del jugador 2:";
    locate(49,10);
    cin.getline(nombre2, 15);


}

/*void ingame1(char nombre[15])
{
char nombre1[20], nombre2[20], nombres[5][20];
int ronda = 0, rondamax, lanzamiento, puntuacion, puntuacionM, puntuacionG[5], valorFlechita;
bool jugar = true;
int valorDados[6]; // DECLARACION DE VARIABLE PARA LOS DADOS


    puntuacion = 0;
    // ----------
    ronda = 0;
    // ----------
    lanzamiento = 0;
    // ----------


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

            locate(42, 2);
            setColor(GREEN);
            cout << ronda;
            locate(72, 2);
            cout << lanzamiento;
            locate(100, 2);
            cout << puntuacion;
            setColor(WHITE);

        valorFlechita = selectDraw(20, 20, 21);

        switch(valorFlechita)
        {

        case 20:

            ronda++;
            lanzamiento++;

            limpiarDados();

            tirarDados(valorDados, 1); /// INGRESAR DADOS MANUALMENTE PARA TESTEAR 0, DADOS AL AZAR 1

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
                    locate(6, 24);
                    mostrarDados(valorDados);

                    locate(24, 20);

                    puntuacion += jugadapares(valorDados);


                    break;
                }

            }

    }
}
*/
/// --------- DESARROLLO DADOS ---------------------

        void mostrarDados(int vecDados[])
        {
            for(int i=0; i<6; i++)
            {
                cout << vecDados[i] <<" ";
            }
        }

        void tirarDados(int vecDados[], bool azar)
        {
            int x = 6;
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
                locate(6, 26);
                cout << "Ingrese los valores de los dados\n";
                for(int i=0; i<6; i++)
                {
                    locate(x, 27);
                    cin >> vecDados[i];
                    x+=2;
                }

            }

        }

        void  dadosPrimeraRonda(int ronda, int dados[])
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

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
    int valorDados[6]; // DECLARACION DE VARIABLE PARA LOS DADOS
    int valorFlechita; // Lo que devuelve la flecha
    int puntuacion, puntuacion2, ronda2, lanzamiento, ronda, rondamax, Val = 0;
    char listanombres[10][15], nombre1[15], nombre2[15];
    int puntajes[10] = {0};
    bool jugar;

    limpiarListaNombres(listanombres);

    while(true)
    {

        if(Val>=10)
        {
            Val = 0;
        }

        system("cls");

        bordes(2);

        menuPrincipal();

        valorFlechita = selectDraw(27, 6, 12, 2);

        switch(valorFlechita) // MENU
        {
        case 6:             // OPCION DE UN JUGADOR
            system("cls");
            jugar = true;
            bordes(1);   // SE DIBUJAN LOS BORDES DE PANTALLA

            rondamax = unJugador(nombre1);

            bordes(1);

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
                for(int i=0; i<=rondamax; i++)
                {

                    dadosPrimeraRonda(ronda, valorDados);

                    locate(42, 2);
                    setColor(GREEN);
                    cout << ronda;
                    locate(72, 2);
                    cout << lanzamiento;
                    locate(100, 2);
                    cout << puntuacion;
                    setColor(WHITE);

                    valorFlechita = selectDraw(20, 20, 21, 1);

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

                        puntuacion += tresPares(valorDados);


                        break;
                    }

                    jugar = false;

                }

            }

            ///----------------------------------
            // PUNTUACION FINAL
            strcpy(listanombres[Val], nombre1);
            puntajes[Val] = puntuacion;
            Val++;

            break;
        case 8:           // OPCION DE DOS JUGADORES
            system("cls");

            bordes(1);   // SE DIBUJAN LOS BORDES DE PANTALLA

             ///----------------------------------
            // PUNTUACION FINAL
            strcpy(listanombres[Val], nombre1);
            puntajes[Val] = puntuacion;
            Val++;

            Val+=2;

            system("pause");
            break;

        case 10:         // OPCION DE MAX PUNTUACION
            system("cls");

            bordes(1);

            locate(5, 5);

            for(int i=0; i<10; i++)
            {
                cout << i+1 << ". "<< listanombres[i];
                cout << "\t\t" << puntajes[i] <<"\n";
            }


            system("pause");
            break;
        case 12:         // SALIR
            return 0;
            break;

        }
    }

    return 0;
}

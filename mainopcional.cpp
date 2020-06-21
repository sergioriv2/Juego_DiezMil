#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "rlutil.h"
#include "funciones opcional.h"
#include "dibujofunciones.h"

using namespace std;
using namespace rlutil;

///declarar funcion


int main()
{

    int valorFlechita; /// Lo que devuelve la flecha

    while(true)
    {
        system("cls");
        cout << "- Un jugador\n";
        cout << "- Dos jugadores\n";
        cout << "- Puntuacion maxima\n";
        cout << "- Salir\n";

        valorFlechita = selectDraw(25, 1, 4);


        switch(valorFlechita) /// MENU
        {
        case 1:             /// OPCION DE UN JUGADOR
            system("cls");

            borderDraw();   /// SE DIBUJAN LOS BORDES DE PANTALLA hay que hacerlo

            unJugador();    /// FUNCION DE UN JUGADOR

            juego==1;



            system("pause");

            break;
        case 2:           /// OPCION DE DOS JUGADORES
            system("cls");

            borderDraw();   /// SE DIBUJAN LOS BORDES DE PANTALLA

            dosJugadores(); /// FUNCION DE DOS JUGADORES

            system("pause");
            break;

        case 3:         /// OPCION DE MAX PUNTUACION
            system("cls");



            puntaje=maxPuntaje(t);
            nombMax(mayorJugador);

            if(puntaje==0)
            {
                locate(51,16);
                cout<<"No hay juegos registrados"<<endl;
            }

            else
            {
                locate(51,16);
                cout<<nombMax<<"    "<<puntaje<<endl;///armar recuadro de puntaje
            }
            /*cout << "max\n";*/ ///borrar


            system("pause");
            break;


        case 4:         /// SALIR
            return 0;
            break;


        }///switch menu

        system("cls");

        if(juego==1)
        {


            ///void ingame1(char nombre[15])
///{

            char ronda = 0, lanzamiento = 0, puntuacion = 0, jugar = true, valorFlechita, nombre[15]; /// DECLARACION DE VARIABLES GENERALES
            int valorDados[6], rondas; /// DECLARACION DE VARIABLE PARA LOS DADOS*/


            nombre=unjugador(nom)///aca tiene que retornar el nombre del jugador.

            locate(51,15);
            cout<<"Cuantas rondas quiere probar la suerte de ganar : ";
            round(rondas);

            system ("cls");

            for(int forx=0; forx<round; forx++)
            {

                underlineDraw(2, 3, 115);

                locate(3, 2);
                cout << "TURNO DE: ";
                setColor(GREEN);
                cout << nombre;
                setColor(WHITE);
                locate(26, 2);
                cout << "|\tRONDA N: ";
                setColor(GREEN);
                cout << round; ///ronda;
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

                while(jugar)///el while nunca fallaria, lo que fallaria seria el for cuando termine la ronda
                {
                    dibValorDados(ronda, valorDados);

                    valorFlechita = selectDraw(20, 20, 21);

                    switch(valorFlechita)
                    {

                    case 20: ///por que el 20

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


                }///while jugar

            }///for juego, contendria la estetica mas las operaciones con datos

        }///if juego. debaj de esto se debe colocar el modo de juego 2


    }///while menu


    return 0;
}

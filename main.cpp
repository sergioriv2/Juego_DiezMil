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
    int valorDados[6], turnopar; // DECLARACION DE VARIABLE PARA LOS DADOS
    int valorFlechita; // Lo que devuelve la flecha
    int puntuacion, puntuacion2, lanzamiento, lanzamiento2, ronda, rondamax, Val = 0;
    char listanombres[10][15], nombre1[15], nombre2[15];
    int  puntajes[10], juegos[19], ValorY = 5, indice = 0;
    bool jugar;

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
            underlineDraw(2, 19, 115);

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

                    valorFlechita = selectDraw2();

                    switch(valorFlechita)
                    {

                    case 20:

                        ronda++;
                        lanzamiento++;

                        limpiarDados();
                        ponerEnCero(juegos, 19);

                        gotoxy(42, 23);
                        cout << "                                       ";
                        gotoxy(42, 24);
                        cout << "                                       ";
                        gotoxy(42, 25);
                        cout << "                                       ";

                        tirarDados(valorDados, juegos, 1); /// INGRESAR DADOS MANUALMENTE PARA TESTEAR 0, DADOS AL AZAR 1///le agregue puntuacion

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

                        /* locate(6,23);
                         cout << "(Valores del vector de dados): ";
                         locate(6, 24);
                         mostrarDados(valorDados);

                         locate(24, 20);*/


                        juegoD1     (valorDados, juegos);
                        juegoD5     (valorDados, juegos);
                        selectivo   (valorDados, juegos);
                        tresPares   (valorDados, juegos);
                        escalera    (valorDados, juegos);

                        jugadas(juegos);
                        break;
                    case 23:
                        indice = buscaruno(juegos, 1);
                        puntuacion += sumarPuntos(indice);
                        i--;
                        locate(42, 23);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    case 24:
                        indice = buscaruno(juegos, 2);
                        puntuacion += sumarPuntos(indice);
                        i--;
                        locate(42, 24);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    case 25:
                        indice = buscaruno(juegos, 3);
                        puntuacion += sumarPuntos(indice);
                        i--;
                        locate(42, 25);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    }



                }///for
                jugar = false;
            }

            system("cls");

            bordes(1);
            locate(30, 10);
            cout << "Jugador: ";
            cout << nombre1;
            locate(55, 10);
            cout << "Puntos: ";
            cout << puntuacion;
            if(puntuacion<10000)
            {
                locate(30, 12);
                setColor(RED);
                cout << "Perdiste";
            }
            else
            {
                locate(30, 12);
                setColor(LIGHTGREEN);
                cout << "Ganaste!!!";
            }
            setColor(WHITE);
            anykey();
            ///----------------------------------
            // PUNTUACION FINAL
            strcpy(listanombres[Val], nombre1);
            puntajes[Val] = puntuacion;
            Val++;

            break;
        case 8:           // OPCION DE DOS JUGADORES
            system("cls");

            bordes(1);   // SE DIBUJAN LOS BORDES DE PANTALLA

            jugar = true;

            dosJugadores(nombre1, nombre2);

            puntuacion = 0;
            // ----------
            puntuacion2 = 0;
            // ----------
            ronda = 0;
            // ----------
            lanzamiento = 0;
            // ----------
            lanzamiento2 = 0;

            underlineDraw(2, 3, 115);
            underlineDraw(2, 19, 115);

            while(jugar)
            {

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

                dadosPrimeraRonda(ronda, valorDados);
                dibujoDados(4);

                locate(6, 20);
                cout << "Lanzar dados";
    ///-----------------------------------------------------------------------------------------
                if(ronda%2 == 0 && ronda!=0)
                {
                    turnopar = 1;
                }
                else{
                    turnopar = 0;
                }

                switch(turnopar)
                {
                case 0:
                locate(13, 2);
                setColor(GREEN);
                cout << "          ";
                locate(13, 2);
                cout << nombre1;
                locate(42, 2);
                setColor(GREEN);
                cout << ronda;
                locate(72, 2);
                cout << lanzamiento;
                locate(100, 2);
                cout << "          ";
                locate(100, 2);
                cout << puntuacion;

                valorFlechita = selectDraw2();

                switch(valorFlechita)
                {

                case 20:
                    ronda++;
                    limpiarDados();
                    ponerEnCero(juegos, 19);

                    gotoxy(42, 23);
                    cout << "                                       ";
                    gotoxy(42, 24);
                    cout << "                                       ";
                    gotoxy(42, 25);
                    cout << "                                       ";

                    tirarDados(valorDados, juegos, 1); /// INGRESAR DADOS MANUALMENTE PARA TESTEAR 0, DADOS AL AZAR 1

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

                    /*locate(6,23);
                    cout << "(Valores del vector de dados): ";
                    locate(6, 24);
                    mostrarDados(valorDados);*/

                    juegoD1     (valorDados, juegos);
                    juegoD5     (valorDados, juegos);
                    selectivo   (valorDados, juegos);
                    tresPares   (valorDados, juegos);
                    escalera    (valorDados, juegos);

                    jugadas(juegos);
                    break;

                case 23:
                    lanzamiento++;
                    indice = buscaruno(juegos, 1);
                    puntuacion += sumarPuntos(indice);
                    //i--;
                    locate(42, 23);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    break;
                case 24:
                    lanzamiento++;
                    indice = buscaruno(juegos, 2);
                    puntuacion += sumarPuntos(indice);
                    //i--;
                    locate(42, 24);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    break;
                case 25:
                    lanzamiento++;
                    indice = buscaruno(juegos, 3);
                    puntuacion += sumarPuntos(indice);
                    //i--;
                    locate(42, 25);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    break;
                }
                break;
                case 1:
                    locate(13, 2);
                    setColor(RED);
                    cout << "          ";
                    locate(13, 2);
                    cout << nombre2;
                    locate(42, 2);
                    setColor(GREEN);
                    cout << ronda;
                    locate(72, 2);
                    cout << lanzamiento2;
                    locate(100, 2);
                    cout << "          ";
                    locate(100, 2);
                    cout << puntuacion2;
                    setColor(WHITE);

                    valorFlechita = selectDraw2();

                    switch(valorFlechita)
                    {

                    case 20:

                        ronda++;
                        limpiarDados();
                        ponerEnCero(juegos, 19);
                        gotoxy(42, 23);
                        cout << "                                       ";
                        gotoxy(42, 24);
                        cout << "                                       ";
                        gotoxy(42, 25);
                        cout << "                                       ";

                        tirarDados(valorDados,juegos, 1);  /// INGRESAR DADOS MANUALMENTE PARA TESTEAR 0, DADOS AL AZAR 1

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

                        /*locate(6,23);
                        cout << "(Valores del vector de dados): ";
                        locate(6, 24);
                        mostrarDados(valorDados);*/


                        juegoD1     (valorDados, juegos);
                        juegoD5     (valorDados, juegos);
                        selectivo   (valorDados, juegos);
                        tresPares   (valorDados, juegos);
                        escalera    (valorDados, juegos);
                        jugadas(juegos);

                        break;

                    case 23:

                        lanzamiento2++;
                        indice = buscaruno(juegos, 1);
                        puntuacion2 += sumarPuntos(indice);
                        //i--;
                        locate(42, 23);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    case 24:
                        lanzamiento2++;
                        indice = buscaruno(juegos, 2);
                        puntuacion2 += sumarPuntos(indice);
                        //i--;
                        locate(42, 24);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    case 25:
                        lanzamiento2++;
                        indice = buscaruno(juegos, 3);
                        puntuacion2 += sumarPuntos(indice);
                        //i--;
                        locate(42, 25);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    }

                    break;
                }

                if(ronda>=10)
                {
                    jugar = false;
                }
                else{
                    if(puntuacion2 == 10000 || puntuacion == 10000)
                    {
                        jugar = false;
                    }
                }
            }
             system("cls");

            bordes(1);
            if(puntuacion > puntuacion2)
            {
                locate(30, 11);
                cout << nombre1;
                locate(55, 11);
                cout << "Puntuacion: " << puntuacion;
                locate(30, 12);
                setColor(LIGHTGREEN);
                cout << "Ganaste!!!";
                setColor(WHITE);

            }
            else{
                locate(30, 11);
                cout << nombre2;
                locate(55, 11);
                cout << "Puntuacion: " << puntuacion;
                locate(30, 12);
                setColor(LIGHTGREEN);
                cout << "Ganaste!!!";
                setColor(WHITE);

            }
            locate(30, 15);

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

            locate(5, ValorY);

            for(int i=0; i<10; i++)
            {
                ValorY++;
                locate(5, ValorY);
                cout << i+1 << ". "<< listanombres[i];
                cout << "    " << puntajes[i] <<"";
            }

            ValorY = 5;

            system("pause");
            break;
        case 12:         // SALIR
            return 0;
            break;

        }
    }

    return 0;
}

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

void tirarDados(int vecDados[], int juegos[], bool azar);
// FUNCION GENERAL PARA TIRAR DADOS, C = CANTIDAD DE DADOS, BOOL 1 = DADOS AL AZAR, BOOL 0 = DADOS MANUALMENTE

void mostrarDados(int vecDados[]);

void dadosPrimeraRonda(int ronda, int dados[]);
// MUESTRA " ? ? ? " EN LOS DADOS DURANTE LA PRIMERA RONDA O RONDA 0

void dosJugadores(char nombre1[], char nombre2[]);

void limpiarListaNombres(char lista[10][15]);

int unJugador(char nombreJ1[]);


/// -------------- DECLARACION DE FUNCIONES DE LAS JUGADAS ----------------

int jugadas(int juegos[19]);

void tresPares(int vecDados[], int juegos[]);

void selectivo(int vecDados[], int juegos[]);

void juegoD5(int vecDados[], int juegos[]);

void escalera(int vecDados[], int juegos[]);

void juegoD1(int vecDados[], int juegos[]);

/// -------------- DESARROLLO DE LAS FUNCIONES DE LAS JUGADAS ----------------


int jugadas(int juegos[19])
{
    int puntoss = 0, vueltas = 23;

    int  tot;

    for(int forx=0; forx<19; forx++)
    {

        if(juegos[forx]==1)
        {
            switch(forx)
            {

            case 0:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Escalera"<<endl;
                vueltas++;
                break;

            case 1:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Tres Pares"<<endl;
                vueltas++;
                break;

            case 2:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 2++"<<endl;
                vueltas++;
                break;

            case 3:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 2"<<endl;
                vueltas++;
                break;

            case 4:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 3++"<<endl;
                vueltas++;
                break;
            case 5:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 3"<<endl;
                vueltas++;
                break;

            case 6:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 4++"<<endl;
                vueltas++;
                break;

            case 7:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 4"<<endl;
                vueltas++;
                break;

            case 8:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 6++"<<endl;
                vueltas++;
                break;
            case 9:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 6"<<endl;
                vueltas++;
                break;

            case 10:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Juego de 5"<<endl;
                vueltas++;
                break;

            case 11:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Juego de 5"<<endl;
                vueltas++;
                break;

            case 12:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 5"<<endl;
                vueltas++;
                break;
            case 13:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 5++"<<endl;
                vueltas++;
                break;

            case 14:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Juego de 1"<<endl;
                puntoss+= 100;
                vueltas++;
                break;

            case 15:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Juego de 1"<<endl;
                vueltas++;
                break;

            case 16:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio de 1"<<endl;
                vueltas++;
                break;

            case 17:
                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Trio 1 ampliado"<<endl;
                vueltas++;
                break;

            case 18:

                gotoxy(45,vueltas);
                cout<<"                   "<<endl;
                gotoxy(45,vueltas);
                cout<<"Sexteto"<<endl;
                vueltas++;
                break;
            }///switch

        }///if

    }///for
    return puntoss;


}
///------------------- DESARROLLO DE FUNCIONES ----------------------

void escalera(int vecDados[6], int juegos[])
{


    int n = vecDados[0];
    bool escalera1 = true, escalera2 = true;

    for(int x=1; x<=5; x++)
    {
        if(escalera1)
        {
            if(vecDados[x]>n)
            {
                n = vecDados[x];
            }
            else
            {
                escalera1 = false;
            }
        }
    }

    n = vecDados[0];

    for(int x=1; x<=5; x++)
    {
        if(escalera2)
        {
            if(vecDados[x]<n)
            {
                n = vecDados[x];
            }
            else
            {
                escalera2 = false;
            }
        }
    }

    if(escalera1)
    {
        juegos[0]=1;///0
    }
    else
    {
        if(escalera2)
        {
            juegos[0]=1;///0
        }
    }




}

void tresPares(int vecdados[6], int juegos[])///
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

        juegos[1]=1;
    }



}

void selectivo(int vecDados[6], int juegos[])///YATA
{

    int sumar2=0, sumar4=0, sumar3=0, sumar6=0;
    for(int a=0; a<6; a++)
    {

        switch(vecDados[a])
        {
        case 2:

            sumar2++;

            break;
        case 3:

            sumar3++;

            break;
        case 4:

            sumar4++;

            break;
        case 6:

            sumar6++;

            break;

        }

    }///for

    switch(sumar2)
    {


    case 4:
    case 5:

        juegos[2]=1;

        break;


    case 3:

        juegos[3]=1;

    }///switch 2

    switch(sumar3)
    {

    case 4:
    case 5:

        juegos[4]=1;
        break;

    case 3:
        juegos[5]=1;

    }///switch 3

    switch(sumar4)
    {

    case 4:
    case 5:

        juegos[6]=1;

        break;

    case 3:

        juegos[7]=1;

    }///switch 4


    switch(sumar6)
    {

    case 4:
    case 5:

        juegos[8]=1;

        break;

    case 3:

        juegos[9]=1;

    }///switch 6
}

void juegoD5(int vecDados[6], int juegos[])///
{

    int numeros=0;

    for(int j=0; j<6; j++)
    {

        if(vecDados[j] == 5 )
        {
            numeros++;
        }//llaves del if

    } // fin del for
    switch(numeros)
    {

    case 1:
        juegos[10]=1;
        break;
    case 2:
        juegos[11]=1;
        break;
    case 3:
        juegos[12]=1;
        break;

    case 4:
    case 5:
        juegos[13]=1;


    }



}

void juegoD1(int vecDados[6], int juegos[19])
{

    int valores = 0;

    for(int j=0; j<6; j++)
    {

        if(vecDados[j] == 1)
        {
            valores++;
        }//llaves del if

    } // fin del for

    switch(valores)
    {
    case 1:
        juegos[14]=1;
        break;
    case 2:
        juegos[15]=1;
        break;
    case 3:
        juegos[16]=1;
        break;
    case 4:
    case 5:
        juegos[17]=1;
        break;
    case 6:
        juegos[18]=1;
    }



}

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

    system("cls");

}




/// --------- DESARROLLO DADOS ---------------------

void mostrarDados(int vecDados[])
{
    for(int i=0; i<6; i++)
    {
        cout << vecDados[i] <<" ";
    }
}

void tirarDados(int vecDados[], int juegos[], bool azar)
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

void ponerEnCero(int vec[19])
{
    for(int i=0; i<19; i++)
    {
        vec[i] = 0;
    }
}



#endif // FUNCIONES_H_INCLUDED

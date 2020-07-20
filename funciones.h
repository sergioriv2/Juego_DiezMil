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

void unJugador(char nombreJ1[]);

void ponerEnCero(int vec[], int tam);
// LE PONE 0 A TODOS LOS VALORES A UN VECTOR DE TAMAÑO N

void limpiarListaNombres(char lista[10][15]);

int buscaruno(int juegos[19], int N_uno);

void ordenar_minlista(int juegos[19], int lista[]);

int sumarPuntos(int V);

/// -------------- DECLARACION DE FUNCIONES DE LAS JUGADAS ----------------

void jugadas(int juegos[19]);

void tresPares(int vecDados[6], int juegos[19]);

void selectivo(int vecDados[6], int juegos[19]);

void juegoD5(int vecDados[6], int juegos[19]);

void escalera(int vecDados[6], int juegos[19]);

void juegoD1(int vecDados[6], int juegos[19]);

/// -------------- DESARROLLO DE LAS FUNCIONES DE LAS JUGADAS ----------------

int sumarPuntos(int V)
{
    int puntoss = 0;

    switch(V)
    {
    case 0:
        puntoss+=1500;
        break;
    case 1:
        puntoss+=1000;
        break;
    case 2:
        puntoss+=400;
        break;
    case 3:
        puntoss+=200;
        break;
    case 4:
        puntoss+=600;
        break;
    case 5:
        puntoss+=300;
        break;
    case 6:
        puntoss+=800;
        break;
    case 7:
        puntoss+=400;
        break;
    case 8:
        puntoss+=1200;
        break;
    case 9:
        puntoss+=600;
        break;
    case 10:
        puntoss+=50;
        break;
    case 11:
        puntoss+=100;
        break;
    case 12:
        puntoss+=500;
        break;
    case 13:
        puntoss+=1000;
        break;
    case 14:
        puntoss+=100;
        break;
    case 15:
        puntoss+=200;
        break;
    case 16:
        puntoss+=1000;
        break;
    case 17:
        puntoss+=2000;
        break;
    case 18:
        puntoss+=10000;
        break;
    }
    return puntoss;
}

void jugadas(int juegos[19])
{
    int vueltas = 20;


    for(int forx=0; forx<19; forx++)
    {

        if(juegos[forx]==1)
        {
            switch(forx)
            {

            case 0:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Escalera"<<endl;
                locate(70, vueltas);
                cout << "1500 puntos";
                vueltas++;
                break;

            case 1:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Tres Pares"<<endl;
                locate(70, vueltas);
                cout << "1000 puntos";
                vueltas++;
                break;

            case 2:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 2++"<<endl;
                locate(70, vueltas);
                cout << "400 puntos";
                vueltas++;
                break;

            case 3:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 2"<<endl;
                locate(70, vueltas);
                cout << "200 puntos";
                vueltas++;
                break;

            case 4:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 3++"<<endl;
                locate(70, vueltas);
                cout << "600 puntos";
                vueltas++;
                break;
            case 5:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 3"<<endl;
                 locate(70, vueltas);
                cout << "300 puntos";
                vueltas++;
                break;

            case 6:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 4++"<<endl;
                 locate(70, vueltas);
                cout << "800 puntos";
                vueltas++;
                break;

            case 7:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 4"<<endl;
                 locate(70, vueltas);
                cout << "400 puntos";
                vueltas++;
                break;

            case 8:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 6++"<<endl;
                 locate(70, vueltas);
                cout << "1200 puntos";
                vueltas++;
                break;
            case 9:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 6"<<endl;
                 locate(70, vueltas);
                cout << "600 puntos";
                vueltas++;
                break;

            case 10:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Juego de 5"<<endl;
                locate(70, vueltas);
                cout << "50 puntos";
                vueltas++;
                break;

            case 11:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Juego de 5"<<endl;
                locate(70, vueltas);
                cout << "100 puntos";
                vueltas++;
                break;

            case 12:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 5"<<endl;
                 locate(70, vueltas);
                cout << "500 puntos";
                vueltas++;
                break;
            case 13:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 5++"<<endl;
                 locate(70, vueltas);
                cout << "1000 puntos";
                vueltas++;
                break;

            case 14:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Juego de 1"<<endl;
                 locate(70, vueltas);
                cout << "100 puntos";
                vueltas++;
                break;

            case 15:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Juego de 1"<<endl;
                 locate(70, vueltas);
                cout << "200 puntos";
                vueltas++;
                break;

            case 16:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio de 1"<<endl;
                locate(70, vueltas);
                cout << "1000 puntos";
                vueltas++;
                break;

            case 17:
                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Trio 1 ampliado"<<endl;
                 locate(70, vueltas);
                cout << "2000 puntos";
                vueltas++;
                break;

            case 18:

                locate(45,vueltas);
                cout<<"                   "<<endl;
                locate(45,vueltas);
                cout<<"Sexteto"<<endl;
                locate(70, vueltas);
                setColor(LIGHTGREEN);
                cout << "Ganas el juego";
                setColor(WHITE);
                vueltas++;
                break;
            }///switch

        }///if

    }///for


}
///------------------- DESARROLLO DE FUNCIONES ----------------------

void escalera(int vecDados[6], int juegos[19])
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

void tresPares(int vecdados[6], int juegos[19])///
{

    int vecdadoscomp[6], analizar, contar, par = 0;
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

void ordenar_minlista(int juegos[19], int lista[])
{
    int v = 0;

    for(int i=0; i<19; i++)
    {
        if(juegos[i] == 1)
        {
            lista[v] = 1;
            v++;
        }
    }
}

void selectivo(int vecDados[6], int juegos[19])///YATA
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

void juegoD5(int vecDados[6], int juegos[19])///
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

void unJugador(char nombreJ1[])
{

    bordes(1);

    locate(50, 3);
    cout << "UN JUGADOR";
    underlineDraw(49, 4, 9);

    locate(27,8);
    cout << "Ingresa tu nombre:";
    locate(46,8);
    cin.getline(nombreJ1, 15);
    system("cls");



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

    bordes(1);

}

void ponerEnCero(int vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i] = 0;
    }
}

void compararTablas(int juegos[19], int tabla[3])
{
    int p = 0;

    for(int i=0; i<19; i++)
    {
        if(juegos[i] == 1)
        {
            tabla[p] = 1;
            p++;
        }
    }
}

int buscaruno(int juegos[19], int N_uno)
{
    bool primeruno = true, segundouno = true, terceruno = true;
    int v = 0, con = 0;

    switch(N_uno)
    {

    case 1:

        while(primeruno)
        {

            if(juegos[v] == 1)
            {
                primeruno = false;
            }
            else
            {
                v++;
            }

        }

        break;
    case 2:
        while(segundouno)
        {

            if(juegos[v] == 1)
            {
                con++;
            }
            if(con == 2)
            {
                segundouno = false;
            }
            else{
              v++;
            }


        }
        break;
    case 3:
        while(terceruno)
        {
           if(juegos[v] == 1)
           {
               con++;
           }
           if(con == 3)
           {
               terceruno = false;
           }
           else{
            v++;
           }

        }
        break;
    }
    return v;
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

            cin.ignore();
        }

        x = 6;
        for(int i=0; i<6; i++)
        {
            locate(x,27);
            cout << " ";
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

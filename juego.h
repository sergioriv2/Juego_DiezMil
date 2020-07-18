#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

int gameplay_1(int, char);

int gameplay_2(char, char);

///------------------------------------------------------

int gameplay_1(int rondamax, char nombre1[15])
{
    int valorDados[6], puntuacion, lanzamiento, ronda, valorFlechita;
    int juegos[19], listaunos[3], indice = 0;
    bool jugar = true;

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
            locate(6, 21);
            cout << "Sumar puntos";

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

                    valorFlechita = selectDraw2(listaunos);

                    switch(valorFlechita)
                    {

                    case 20:

                        ronda++;
                        lanzamiento++;

                        limpiarDados();

                        ponerEnCero(juegos, 19);
                        ponerEnCero(listaunos, 3);

                        gotoxy(42, 23);
                        cout << "                                        ";
                        gotoxy(42, 24);
                        cout << "                                        ";
                        gotoxy(42, 25);
                        cout << "                                        ";

                        tirarDados(valorDados, juegos, 1); /// INGRESAR DADOS MANUALMENTE PARA TESTEAR 0, DADOS AL AZAR 1///le agregue puntuacion
                        dibujo(valorDados);

                        juegoD1     (valorDados, juegos);
                        juegoD5     (valorDados, juegos);
                        selectivo   (valorDados, juegos);
                        tresPares   (valorDados, juegos);
                        escalera    (valorDados, juegos);

                        jugadas(juegos);

                        ordenar_minlista(juegos, listaunos);

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

            return puntuacion;
}

int gameplay_2(char nombre1[15], char nombre2[15])
{
    int puntuacion, puntuacion2, ronda, lanzamiento, lanzamiento2, turnopar, valorDados[6], valorFlechita;
    int juegos[19], listaunos[3], indice = 0;
    bool jugar = true;

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

                valorFlechita = selectDraw2(listaunos);

                switch(valorFlechita)
                {

                case 20:
                    ronda++;
                    limpiarDados();
                    ponerEnCero(juegos, 19);
                    ponerEnCero(listaunos, 3);

                    gotoxy(42, 23);
                    cout << "                                       ";
                    gotoxy(42, 24);
                    cout << "                                       ";
                    gotoxy(42, 25);
                    cout << "                                       ";

                    tirarDados(valorDados, juegos, 1); /// INGRESAR DADOS MANUALMENTE PARA TESTEAR 0, DADOS AL AZAR 1

                    dibujo(valorDados);

                    juegoD1     (valorDados, juegos);
                    juegoD5     (valorDados, juegos);
                    selectivo   (valorDados, juegos);
                    tresPares   (valorDados, juegos);
                    escalera    (valorDados, juegos);

                    jugadas(juegos);
                    ordenar_minlista(juegos, listaunos);

                    break;

                case 23:
                    lanzamiento++;
                    indice = buscaruno(juegos, 1);
                    puntuacion += sumarPuntos(indice);
                    locate(42, 23);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    break;
                case 24:
                    lanzamiento++;
                    indice = buscaruno(juegos, 2);
                    puntuacion += sumarPuntos(indice);
                    locate(42, 24);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    break;
                case 25:
                    lanzamiento++;
                    indice = buscaruno(juegos, 3);
                    puntuacion += sumarPuntos(indice);
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

                    valorFlechita = selectDraw2(listaunos);

                    switch(valorFlechita)
                    {

                    case 20:

                        ronda++;
                        limpiarDados();
                        ponerEnCero(juegos, 19);
                        ponerEnCero(listaunos, 3);
                        gotoxy(42, 23);
                        cout << "                                       ";
                        gotoxy(42, 24);
                        cout << "                                       ";
                        gotoxy(42, 25);
                        cout << "                                       ";

                        tirarDados(valorDados,juegos, 1);  /// INGRESAR DADOS MANUALMENTE PARA TESTEAR 0, DADOS AL AZAR 1

                        dibujo(valorDados);

                        juegoD1     (valorDados, juegos);
                        juegoD5     (valorDados, juegos);
                        selectivo   (valorDados, juegos);
                        tresPares   (valorDados, juegos);
                        escalera    (valorDados, juegos);
                        jugadas(juegos);

                        ordenar_minlista(juegos, listaunos);

                        break;

                    case 23:

                        lanzamiento2++;
                        indice = buscaruno(juegos, 1);
                        puntuacion2 += sumarPuntos(indice);
                        locate(42, 23);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    case 24:
                        lanzamiento2++;
                        indice = buscaruno(juegos, 2);
                        puntuacion2 += sumarPuntos(indice);
                        locate(42, 24);
                        setColor(YELLOW);
                        cout << "X";
                        setColor(WHITE);
                        break;
                    case 25:
                        lanzamiento2++;
                        indice = buscaruno(juegos, 3);
                        puntuacion2 += sumarPuntos(indice);
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

                return puntuacion;

            }
            else{
                locate(30, 11);
                cout << nombre2;
                locate(55, 11);
                cout << "Puntuacion: " << puntuacion2;
                locate(30, 12);
                setColor(LIGHTGREEN);
                cout << "Ganaste!!!";
                setColor(WHITE);

                return puntuacion2;

            }
            locate(30, 15);
}

#endif // JUEGO_H_INCLUDED

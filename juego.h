#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

int gameplay_1(int, char);

int gameplay_2(char, char);

///------------------------------------------------------

int gameplay_1(char nombre1[15])
{
    int valorDados[6] = { 0, 0, 0, 0, 0, 0 };

    int puntuacion, lanzamiento, ronda,  valorFlechita, puntuacion_acu, ant_puntuacion, indice;
    puntuacion = lanzamiento = ronda = valorFlechita = puntuacion_acu = ant_puntuacion = indice = 0;

    int juegos[19], listaunos[3];

    bool jugar = true, ceroForzado = false;

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
    cout << "Sumar puntos acu.";
    locate(6, 17);
    cout << "Puntuacion Acu. ";
    locate(50, 17);
    cout << "Para empezar a jugar... lanza los dados!";

    while(jugar)
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
        locate(25, 17);
        cout << puntuacion_acu;

        valorFlechita = selectDraw2(listaunos);

        switch(valorFlechita)
        {

        case 50:

            if(ronda == 0)
            {
                ronda++;
                locate(50, 17);
                cout << "                                        ";
            }

            lanzamiento++;

            limpiarDados();

            ponerEnCero(juegos, 19);
            ponerEnCero(listaunos, 3);
            ceroForzado = false; /// ESTE BOOL LO NECESITO PORQUE DESPUES LA LISTA DE UNOS LA TENGO QUE PONER EN CERO Y CON EL BOOL ME RESPALDO DE ERRORES

            gotoxy(42, 20);
            cout << "                                          ";
            gotoxy(42, 21);
            cout << "                                          ";
            gotoxy(42, 22);
            cout << "                                          ";
            gotoxy(22, 17);
            cout << "              ";

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
        case 51:
            if(ronda!= 0) /// ESTO ES UN FILTRO PARA EVITAR QUE SE "ROMPA" EL JUEGO AL ELEGIRSE ESTA OPCION CUANDO LA RONDA ES 0
            {
                if(puntuacion_acu + puntuacion == 10000) /// PREGUNTO PARA EVITAR QUE LA RONDA MOSTRADA AL FINAL SEA INCORRECTA
                {
                    puntuacion+= puntuacion_acu;
                    puntuacion_acu = 0;
                    gotoxy(42, 20);
                    cout << "                                          ";
                    gotoxy(42, 21);
                    cout << "                                          ";
                    gotoxy(42, 22);
                    cout << "                                          ";
                    gotoxy(22, 17);
                    cout << "              ";
                }
                else
                {
                    ronda++;
                    puntuacion+= puntuacion_acu;
                    ant_puntuacion = puntuacion_acu;
                    puntuacion_acu = 0;
                    lanzamiento = 0;
                    gotoxy(42, 20);
                    cout << "                                          ";
                    gotoxy(42, 21);
                    cout << "                                          ";
                    gotoxy(42, 22);
                    cout << "                                          ";
                    gotoxy(22, 17);
                    cout << "              ";
                    ponerEnCero(listaunos, 3);
                    ceroForzado = true;
                }
            }
            break;
        case 81: ///--------------------
            indice = buscaruno(juegos, 1);
            if(indice == 18) /// ESTE IF LO QUE HACE ES ASEGURARSE SI EN EL VECTOR DE JUEGOS HAY UN SEXTETO
            {
                puntuacion = 10000;
            }
            else
            {
                puntuacion_acu += sumarPuntos(indice);
                locate(42, 20);
                setColor(YELLOW);
                cout << "X";
                setColor(WHITE);
                ponerEnCero(listaunos, 3);
                ceroForzado = true;
            }
            break;
        case 82:
            indice = buscaruno(juegos, 2);
            if(indice == 18)
            {
                puntuacion = 10000;
            }
            else
            {
                puntuacion_acu += sumarPuntos(indice);
                locate(42, 21);
                setColor(YELLOW);
                cout << "X";
                setColor(WHITE);
                ponerEnCero(listaunos, 3);
                ceroForzado = true;
            }
            break;
        case 83:
            indice = buscaruno(juegos, 3);
            if(indice == 18)
                puntuacion = 10000;
            else
            {
                puntuacion_acu += sumarPuntos(indice);
                locate(42, 22);
                setColor(YELLOW);
                cout << "X";
                setColor(WHITE);
                ponerEnCero(listaunos, 3);
                ceroForzado = true;
            }
            break;
        }

        if(listaunos[0] == 0 && listaunos[1] == 0 && listaunos[2] == 0 && ceroForzado == false) /// --------- ESTO ES SI NO HAY JUGADAS GANADORAS
        {
            puntuacion_acu = 0;
            lanzamiento = 0;
            ronda++;
            locate(6, 25);
            setColor(RED);
            cout << "NO TE TOCO NINGUNA JUGADA GANADORA! PERDES LOS PUNTOS ACUMULADOS :(";
            setColor(WHITE);
            locate(6, 27);
            cout << "Presiona cualquier tecla para continuar...";
            anykey();
            locate(6, 25);
            cout << "                                                                                        ";
            locate(6, 27);
            cout << "                                                                                        ";
        }

        locate(40, 17);
        cout << "                                                               ";
        if(puntuacion == 10000)
        {
            jugar = false;
        }
        else
        {
            if(puntuacion>10000)
            {
                puntuacion-=ant_puntuacion;
                locate(40, 17);
                cout << "Te pasaste de 10.000! | Puntuacion -" << ant_puntuacion;
            }
        }
    }

    system("cls");

    bordes(1);
    locate(30, 10);
    cout << "Jugador: ";
    cout << nombre1;
    locate(55, 10);
    cout << "Rondas: ";
    cout << ronda;
    locate(30, 13);
    setColor(LIGHTGREEN);
    cout << "GANASTE!";
    setColor(WHITE);
    locate(30, 15);
    cout << "Presiona cualquier tecla para continuar...";
    anykey();

    return ronda;
}

int gameplay_2(char nombre1[15], char nombre2[15])
{
    int puntuacion, puntuacion2, puntuacion_acu = 0, puntuacion_acu2 = 0, ant_puntuacion = 0, ant_puntuacion2 = 0, ronda, lanzamiento, lanzamiento2, turnopar, valorDados[6], valorFlechita;
    int juegos[19], listaunos[3], indice = 0;
    bool jugar = true, ceroForzado = false;

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
        locate(6, 21);
        cout << "Sumar puntos acu.";
        locate(6, 17);
        cout << "Puntuacion Acu. ";

        ///-----------------------------------------------------------------------------------------
        if(ronda%2 == 0 && ronda!=0)  /// PREGUNTO SI LA RONDA ES PAR O NO
        {
            turnopar = 1;
        }
        else
        {
            turnopar = 0;
        }

        switch(turnopar) ///---------------------- SABER A QUE JUGADOR LE TOCA
        {
        case 0: /// ----------------- JUGADOR 1

            /// --------- ESTO ES PARA MOSTRAR LA PUNTUACION DEL JUGADOR 2 EN LA PANTALLA DEL JUGADOR 1
            locate(97,5);
            cout << "                    ";
            locate(97,5);
            setColor(RED);
            cout << nombre2;
            setColor(WHITE);
            cout << ": " << puntuacion2;
            /// -----------------------------------------------------------------------------------------------


            locate(25, 17);
            cout << puntuacion_acu;
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

            case 50:


                if(ronda == 0)
                {
                    ronda++;
                }

                lanzamiento++;

                limpiarDados();

                ponerEnCero(juegos, 19);
                ponerEnCero(listaunos, 3);
                ceroForzado = false;

                gotoxy(42, 20);
                cout << "                                        ";  /// SE LIMPIA CARTELES DE JUGADA 1
                gotoxy(42, 21);
                cout << "                                        ";  /// SE LIMPIA CARTELES DE JUGADA 2
                gotoxy(42, 22);
                cout << "                                        ";  /// SE LIMPIA CARTELES DE JUGADA 3
                gotoxy(22, 17);
                cout << "              "; /// SE LIMPIA LOS PUNTOS ACUMULADOS MOSTRADOS EN PANTALLA

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
            case 51:
                if(ronda!= 0) /// ESTO ES UN FILTRO PARA EVITAR QUE SE "ROMPA" EL JUEGO AL ELEGIRSE ESTA OPCION CUANDO LA RONDA ES 0
                {
                    if(puntuacion_acu + puntuacion == 10000) /// PREGUNTO PARA EVITAR QUE LA RONDA MOSTRADA AL FINAL SEA INCORRECTA
                    {
                        puntuacion+= puntuacion_acu;
                        puntuacion_acu = 0;
                        gotoxy(42, 20);
                        cout << "                                          ";
                        gotoxy(42, 21);
                        cout << "                                          ";
                        gotoxy(42, 22);
                        cout << "                                          ";
                        gotoxy(22, 17);
                        cout << "              ";
                    }
                    else
                    {
                        ronda++;
                        puntuacion+= puntuacion_acu;
                        ant_puntuacion = puntuacion_acu;
                        puntuacion_acu = 0;
                        lanzamiento = 0;
                        gotoxy(42, 20);
                        cout << "                                          ";
                        gotoxy(42, 21);
                        cout << "                                          ";
                        gotoxy(42, 22);
                        cout << "                                          ";
                        gotoxy(22, 17);
                        cout << "              ";
                        ponerEnCero(listaunos, 3);
                        ceroForzado = true;
                    }
                }
                break;
            case 81: ///--------------------
                indice = buscaruno(juegos, 1);
                if(indice == 18) /// ESTE IF LO QUE HACE ES ASEGURARSE SI EN EL VECTOR DE JUEGOS HAY UN SEXTETO
                {
                    puntuacion = 10000;
                }
                else
                {
                    puntuacion_acu += sumarPuntos(indice);
                    locate(42, 20);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    ponerEnCero(listaunos, 3);
                    ceroForzado = true;
                }
                break;
            case 82:
                indice = buscaruno(juegos, 2);
                if(indice == 18)
                {
                    puntuacion = 10000;
                }
                else
                {
                    puntuacion_acu += sumarPuntos(indice);
                    locate(42, 21);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    ponerEnCero(listaunos, 3);
                    ceroForzado = true;
                }
                break;
            case 83:
                indice = buscaruno(juegos, 3);
                if(indice == 18)
                    puntuacion = 10000;
                else
                {
                    puntuacion_acu += sumarPuntos(indice);
                    locate(42, 22);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    ponerEnCero(listaunos, 3);
                    ceroForzado = true;
                }
                break;
            }

            if(listaunos[0] == 0 && listaunos[1] == 0 && listaunos[2] == 0 && ceroForzado == false) /// EN CASO DE QUE NO HAYA JUGADAS GANADORAS, SE MUESTRA ESTE MENSAJE
            {
                puntuacion_acu = 0;
                lanzamiento = 0;
                ronda++;
                locate(6, 25);
                setColor(RED);
                cout << "NO TE TOCO NINGUNA JUGADA GANADORA! PERDES LOS PUNTOS ACUMULADOS Y LE TOCA A: ";
                setColor(WHITE);
                cout << nombre2;
                locate(6, 27);
                cout << "Presiona cualquier tecla para continuar...";
                anykey();
                locate(6, 25);
                cout << "                                                                                        ";
                locate(6, 27);
                cout << "                                                                                        ";
            }

            if(puntuacion>10000)
            {
                puntuacion-=ant_puntuacion;
                locate(40, 17);
                cout << "Te pasaste de 10.000! | Puntuacion -" << ant_puntuacion;
            }
            break;
        case 1: /// -------------------- JUGADOR 2


            /// --------- ESTO ES PARA MOSTRAR LA PUNTUACION DEL JUGADOR 1 EN LA PANTALLA DEL JUGADOR 2
            locate(97,5);
            cout << "                    ";
            locate(97,5);
            setColor(GREEN);
            cout << nombre1;
            setColor(WHITE);
            cout << ": " << puntuacion;
            /// -----------------------------------------------------------------------------------------------

            locate(25, 17);
            cout << puntuacion_acu2;
            locate(13, 2);
            setColor(RED);
            cout << "          ";
            locate(13, 2);
            cout << nombre2;
            locate(42, 2);
            setColor(GREEN);
            cout << ronda;
            locate(72, 2);
            cout << "  ";
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

            case 50:


                if(ronda == 0)
                {
                    ronda++;
                }

                lanzamiento2++;

                limpiarDados();

                ponerEnCero(juegos, 19);
                ponerEnCero(listaunos, 3);
                ceroForzado = false;

                gotoxy(42, 20);
                cout << "                                        ";  /// SE LIMPIA CARTELES DE JUGADA 1
                gotoxy(42, 21);
                cout << "                                        ";  /// SE LIMPIA CARTELES DE JUGADA 2
                gotoxy(42, 22);
                cout << "                                        ";  /// SE LIMPIA CARTELES DE JUGADA 3
                gotoxy(22, 17);
                cout << "              "; /// SE LIMPIA LOS PUNTOS ACUMULADOS MOSTRADOS EN PANTALLA

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
            case 51:
                if(ronda!= 0) /// ESTO ES UN FILTRO PARA EVITAR QUE SE "ROMPA" EL JUEGO AL ELEGIRSE ESTA OPCION CUANDO LA RONDA ES 0
                {
                    if(puntuacion_acu2 + puntuacion2 == 10000) /// PREGUNTO PARA EVITAR QUE LA RONDA MOSTRADA AL FINAL SEA INCORRECTA
                    {
                        puntuacion2+= puntuacion_acu2;
                        puntuacion_acu2 = 0;
                        gotoxy(42, 20);
                        cout << "                                          ";
                        gotoxy(42, 21);
                        cout << "                                          ";
                        gotoxy(42, 22);
                        cout << "                                          ";
                        gotoxy(22, 17);
                        cout << "              ";
                    }
                    else
                    {
                        ronda++;
                        puntuacion2+= puntuacion_acu2;
                        ant_puntuacion2 = puntuacion_acu2;
                        puntuacion_acu2 = 0;
                        lanzamiento2 = 0;
                        gotoxy(42, 20);
                        cout << "                                          ";
                        gotoxy(42, 21);
                        cout << "                                          ";
                        gotoxy(42, 22);
                        cout << "                                          ";
                        gotoxy(22, 17);
                        cout << "              ";
                        ponerEnCero(listaunos, 3);
                        ceroForzado = true;
                    }
                }
                break;
            case 81: ///--------------------
                indice = buscaruno(juegos, 1);
                if(indice == 18) /// ESTE IF LO QUE HACE ES ASEGURARSE SI EN EL VECTOR DE JUEGOS HAY UN SEXTETO
                {
                    puntuacion2 = 10000;
                }
                else
                {
                    puntuacion_acu2 += sumarPuntos(indice);
                    locate(42, 20);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    ponerEnCero(listaunos, 3);
                    ceroForzado = true;
                }
                break;
            case 82:
                indice = buscaruno(juegos, 2);
                if(indice == 18)
                {
                    puntuacion2 = 10000;
                }
                else
                {
                    puntuacion_acu2 += sumarPuntos(indice);
                    locate(42, 21);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    ponerEnCero(listaunos, 3);
                    ceroForzado = true;
                }
                break;
            case 83:
                indice = buscaruno(juegos, 3);
                if(indice == 18)
                    puntuacion2 = 10000;
                else
                {
                    puntuacion_acu2 += sumarPuntos(indice);
                    locate(42, 22);
                    setColor(YELLOW);
                    cout << "X";
                    setColor(WHITE);
                    ponerEnCero(listaunos, 3);
                    ceroForzado = true;
                }
                break;
            }
            if(listaunos[0] == 0 && listaunos[1] == 0 && listaunos[2] == 0 && ceroForzado == false) /// EN CASO DE QUE NO HAYA JUGADAS GANADORAS, SE MUESTRA ESTE MENSAJE
            {
                puntuacion_acu2 = 0;
                lanzamiento2 = 0;
                ronda++;
                locate(6, 25);
                setColor(RED);
                cout << "NO TE TOCO NINGUNA JUGADA GANADORA! PERDES LOS PUNTOS ACUMULADOS Y LE TOCA A: ";
                setColor(WHITE);
                cout << nombre1;
                locate(6, 27);
                cout << "Presiona cualquier tecla para continuar...";
                anykey();
                locate(6, 25);
                cout << "                                                                                        ";
                locate(6, 27);
                cout << "                                                                                        ";
            }

            if(puntuacion2>10000)
            {
                puntuacion2-=ant_puntuacion2;
                locate(40, 17);
                cout << "Te pasaste de 10.000! | Puntuacion Acu. -" << ant_puntuacion2;
            }

            break;
        }


        if(ronda>=10) /// PREGUNTO SI YA SE SUPERARON LAS 10 RONDAS PARA TERMINAR EL JUEGO
        {
            jugar = false;
        }
        else   /// SI NO PREGUNTO SI LA PUNTUACION DE CUALQUIERA DE LOS DOS YA ES 10.000
        {
            if(puntuacion2 == 10000 || puntuacion == 10000)
            {
                jugar = false;
            }
        }//FIN DE IF
    }
    system("cls");

    bordes(1);

    if(puntuacion2 == 10000 || puntuacion == 10000)
    {
        if(puntuacion == 10000)
        {
            locate(30, 10);
            cout << "Jugador: ";
            cout << nombre1;
            locate(55, 10);
            cout << "Rondas: ";
            cout << ronda;
            locate(30, 12);
            setColor(LIGHTGREEN);
            cout << "GANASTE!";
            setColor(WHITE);

            locate(30, 15);
            cout << "Jugador: ";
            cout << nombre2;
            locate(30, 17);
            setColor(RED);
            cout << "PERDISTE";
            setColor(WHITE);


            locate(30, 20);
            cout << "Presiona cualquier tecla para continuar...";
            anykey();

            return ronda;
        }
        else{
            if(puntuacion2 == 10000)
        {
            locate(30, 10);
            cout << "Jugador: ";
            cout << nombre2;
            locate(55, 10);
            cout << "Rondas: ";
            cout << ronda;
            locate(30, 12);
            setColor(LIGHTGREEN);
            cout << "GANASTE!";
            setColor(WHITE);

            locate(30, 15);
            cout << "Jugador: ";
            cout << nombre1;
            locate(30, 17);
            setColor(RED);
            cout << "PERDISTE";
            setColor(WHITE);


            locate(30, 20);
            cout << "Presiona cualquier tecla para continuar...";
            anykey();

            return ronda;
        }
        }
    }
    else{
        if(puntuacion > puntuacion2)
        {
            locate(30, 10);
            cout << "Jugador: ";
            cout << nombre1;
            locate(55, 10);
            cout << "Rondas: ";
            cout << ronda;
            locate(30, 12);
            setColor(LIGHTGREEN);
            cout << "GANASTE!";
            setColor(WHITE);

            locate(30, 15);
            cout << "Jugador: ";
            cout << nombre2;
            locate(30, 17);
            setColor(RED);
            cout << "PERDISTE";
            setColor(WHITE);


            locate(30, 20);
            cout << "Presiona cualquier tecla para continuar...";
            anykey();

            return ronda;
        }
        else
        {
            if(puntuacion2 > puntuacion)
        {
            locate(30, 10);
            cout << "Jugador: ";
            cout << nombre2;
            locate(55, 10);
            cout << "Rondas: ";
            cout << ronda;
            locate(30, 12);
            setColor(LIGHTGREEN);
            cout << "GANASTE!";
            setColor(WHITE);

            locate(30, 15);
            cout << "Jugador: ";
            cout << nombre1;
            locate(30, 17);
            setColor(RED);
            cout << "PERDISTE";
            setColor(WHITE);


            locate(30, 20);
            cout << "Presiona cualquier tecla para continuar...";
            anykey();

            return ronda;
        }
        }
    }
}

#endif // JUEGO_H_INCLUDED

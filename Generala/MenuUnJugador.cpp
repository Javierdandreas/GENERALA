#include<iostream>
#include<cstdlib>
#include"rlutil.h"

using namespace std;

#include "Menu.h"
#include "MenuUnJugador.h"
#include "Dados.h"
#include "funciones.h"
#include "Reglas.h"
#include "MenuDosJugador.h"

void MenuJugador (){

    TituloAnimado("BIENVENIDO AL MODO UN JUGADOR", 50);

    char jugador[30];

    bool hubo_escalera = false;

    int puntos = 0;
    int ronda = 1;
    int mayor=0;

    int vDados[6];
    ponerCero(vDados, 6);

    int vPuntos[4];
    ponerCero(vPuntos, 3);

    int vRepetidos[6];
    ponerCero(vRepetidos, 6);

    rlutil::showcursor();

    rlutil::locate(45, 12);
    cout << " Ingrese nombre del Jugador : ";
    cin.getline(jugador, 30, '\n');

    rlutil::hidecursor();

    system("cls");

    negro();

    entreTurno(ronda, jugador, puntos);

    while (puntos<500 && hubo_escalera==0){

        system("cls");

        Interfaz(ronda, jugador, puntos, vDados, vPuntos, vRepetidos, mayor, hubo_escalera);

        if (hubo_escalera==true){
            break;
        }
        if (puntos>=500){
            break;
        }

        entreTurno(ronda, jugador, puntos);



        ronda = ronda + 1;
    }

    ganador(jugador, ronda, puntos);
}

void Interfaz(int& R, char *J, int& total, int vD[], int vP[], int vR[], int may, bool& esca){

    int lanza;
    int mayorRonda;
    int numDadoMayor;
    int RepesMayor;

    for (int x=1; x<=3; x++){
        lanza=x;
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::locate(35, 13);
        cout<< (char) 201;

        rlutil::locate(35, 28);
        cout<< (char) 200;

        rlutil::locate(96, 13);
        cout<< (char) 187;

        rlutil::locate(96, 28);
        cout<< (char) 188;

        //COLUMNA
        for(int ycol=13; ycol<27; ycol++){
            rlutil::locate(35, ycol+1);
            cout<<( char) 186;

            rlutil::locate(96, ycol+1);
            cout<<( char) 186;
        }

        //FILAS
        for (int xcol = 36; xcol <= 95; xcol++) {
            rlutil::locate(xcol, 13);
            cout<< (char) 205;

            rlutil::locate(xcol, 28);
            cout<< (char) 205;

        }
        rlutil::setBackgroundColor(rlutil::BLACK);

        //FILITAS
        for (int xcol = 37; xcol<95; xcol++){
        rlutil::setColor(rlutil::CYAN);
        rlutil::locate(xcol, 16);
        cout<< (char) 45;

        rlutil::locate(xcol, 20);
        cout<< (char) 45;

        }
        rlutil::setColor(rlutil::WHITE);


        rlutil::locate(36, 14);
        cout << " TURNO DE: " << J << "   RONDA NUMERO: " << R << "   PUNTAJE TOTAL: "<< total ;

        cargarAleatorio(vD, 7, 6);

        DibujarDados(vD[1], 37, 22);
        DibujarDados(vD[2], 47, 22);
        DibujarDados(vD[3], 57, 22);
        DibujarDados(vD[4], 67, 22);
        DibujarDados(vD[5], 77, 22);
        DibujarDados(vD[6], 87, 22);

        vR[1] = contarNumerosRepetidos(vD, 1, 7);
        vR[2] = contarNumerosRepetidos(vD, 2, 7);
        vR[3] = contarNumerosRepetidos(vD, 3, 7);
        vR[4] = contarNumerosRepetidos(vD, 4, 7);
        vR[5] = contarNumerosRepetidos(vD, 5, 7);
        vR[6] = contarNumerosRepetidos(vD, 6, 7);

        may = maximoVector(vR, 7);

        numDadoMayor=may;
        RepesMayor=vR[may];

        if (RepesMayor==6 && numDadoMayor==6){
            rlutil::locate(36, 17);
            cout << " EL MAXIMO PUNTAJE DE LA RONDA ES: " << mayorRonda;

            rlutil::locate(36, 18);
            cout << " LANZAMIENTO NUMERO: " << lanza;

            rlutil::locate(36, 17);
            cout << " EL MAXIMO PUNTAJE DE LA RONDA ES: " << mayorRonda;

            rlutil::locate(36, 18);
            cout << " LANZAMIENTO NUMERO: " << lanza;

            rlutil::locate(75, 17);
            cout << " PUNTOS LANZ. 1: " << vP[1];
            rlutil::locate(75, 18);
            cout << " PUNTOS LANZ. 2: " << vP[2];
            rlutil::locate(75, 19);
            cout << " PUNTOS LANZ. 3: " << vP[3];

            rlutil::anykey();
            system("cls");
            break;
        }

        if (RepesMayor==1){
            x=3;
            rlutil::locate(37, 26);
            cout << " GANASTE LA PARTIDA!! " ;
            esca = true;
            total = 501;
            R = R +1;
        }

        vP[x] = CalcularPuntos(numDadoMayor, RepesMayor, vD);

        mayorRonda = MayorVector(vP, 3);

        rlutil::locate(36, 17);
        cout << " EL MAXIMO PUNTAJE DE LA RONDA ES: " << mayorRonda;
        rlutil::locate(36, 18);
        cout << " LANZAMIENTO NUMERO: " << lanza;

        rlutil::locate(75, 17);
        cout << " PUNTOS LANZ. 1: " << vP[1];
        rlutil::locate(75, 18);
        cout << " PUNTOS LANZ. 2: " << vP[2];
        rlutil::locate(75, 19);
        cout << " PUNTOS LANZ. 3: " << vP[3];

        rlutil::anykey();
        system("cls");

    }

    total += mayorRonda;
    ponerCero(vP, 3);
    ponerCero(vD, 6);
    mayorRonda = 0;
    numDadoMayor = 0;
    RepesMayor = 0;

}

void entreTurno(int R, char *turno, int& total){

        azul();

        rlutil::locate(45, 13);
        cout<< (char) 201;

        rlutil::locate(45, 21);
        cout<< (char) 200;

        rlutil::locate(71, 13);
        cout<< (char) 187;

        rlutil::locate(71, 21);
        cout<< (char) 188;

        //COLUMNAS
        for(int ycol=13; ycol<20; ycol++){
            rlutil::locate(71, ycol+1);
            cout<<( char) 186;

            rlutil::locate(45, ycol+1);
            cout<<( char) 186;
        }

        //FILAS
        for (int xcol = 46; xcol <= 70; xcol++) {
            rlutil::locate(xcol, 13);
            cout<< (char) 205;

            rlutil::locate(xcol, 21);
            cout<< (char) 205;

        }

        rlutil::locate(50, 15);
        cout<< "RONDA NUMERO: " << R;

        rlutil::locate(47, 16);
        cout<< "SIGUIENTE TURNO: " << turno;

        rlutil::locate(50, 18);
        cout<< "PUNTAJE TOTAL: " << total;

        negro();

        rlutil::anykey();


}


















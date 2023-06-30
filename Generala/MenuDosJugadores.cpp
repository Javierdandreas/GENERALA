
#include<iostream>
#include<cstdlib>
#include"rlutil.h"
using namespace std;

#include "Menu.h"
#include "MenuDosJugador.h"
#include "Dados.h"
#include "funciones.h"
#include "Reglas.h"

void MenuDosJugadores () {

    TituloAnimado("BIENVENIDO AL MODO DOS JUGADORES", 45);

    char jugador1[30];
    char jugador2[30];

    bool hubo_escalera=false;

    //Variables de Partida
    int Puntos_J1 = 0;
    int Puntos_J2 = 0;
    int ronda = 1;
    int mayor = 0;
    int mayorPuntaje = 0;
    char winner[30];

    int vDados_J1[6];
    int vDados_J2[6];
    ponerCero(vDados_J1, 6);
    ponerCero(vDados_J2, 6);

    int vPuntos_J1[3];
    int vPuntos_J2[3];
    ponerCero(vPuntos_J1, 3);
    ponerCero(vPuntos_J2, 3);

    int vRepetidos_1[6];
    int vRepetidos_2[6];
    ponerCero(vRepetidos_1, 6);
    ponerCero(vRepetidos_2, 6);

    rlutil::showcursor();

    rlutil::locate(45, 12);
    cout << " Ingrese nombre del Jugador 1: ";
    cin.getline(jugador1, 30, '\n');

    rlutil::locate(45, 14);
    cout << " Ingrese nombre del Jugador 2: ";
    cin.getline(jugador2, 30, '\n');

    rlutil::hidecursor();
    system("cls");

    negro();

    EntreTurno1 (ronda, jugador1, jugador2, Puntos_J1, Puntos_J2);

    while (Puntos_J1<500 && Puntos_J2<500 && hubo_escalera==0){

        system("cls");

        InterfazJ1(ronda, jugador1, Puntos_J1, vDados_J1, vPuntos_J1, vRepetidos_1, mayor, hubo_escalera);

        if (hubo_escalera==true){
            break;
        }
        if (Puntos_J1>=500){
            break;
        }

        EntreTurno2(ronda, jugador2, jugador1, jugador2, Puntos_J1, Puntos_J2);

        system("cls");

        InterfazJ2(ronda, jugador2, Puntos_J2, vDados_J2, vPuntos_J2, vRepetidos_2, mayor, hubo_escalera);

        if (hubo_escalera==true){
            break;
        }
        if (Puntos_J2>=500){
            break;
        }


        EntreTurno2(ronda, jugador1, jugador1, jugador2, Puntos_J1, Puntos_J2);

        ronda = ronda + 1;
    }

        ronda = ronda - 1;

    if(Puntos_J1>Puntos_J2){
        mayorPuntaje = Puntos_J1;
        strcpy(winner, jugador1);
    }
    else{
        mayorPuntaje = Puntos_J2;
        strcpy(winner, jugador2);
    }

    system("cls");

    ganador(winner, ronda, mayorPuntaje);

}

void InterfazJ1(int& R, char *J1, int& total_1, int vD[], int vP[], int vR[], int may, bool& esca){
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
        cout << " TURNO DE: " << J1 << "   RONDA NUMERO: " << R << "   PUNTAJE TOTAL: "<< total_1 ;

        cargarAleatorio(vD, 6, 6);

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

        may = maximoVector(vR, 6);



        numDadoMayor=may;
        RepesMayor=vR[may];


        vP[x] = CalcularPuntos(numDadoMayor, RepesMayor, vD);

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
            R = R +1;
        }

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

    total_1 += mayorRonda;

    ponerCero(vP, 4);
    ponerCero(vD, 6);
    mayorRonda = 0;
    numDadoMayor = 0;
    RepesMayor = 0;

}

void InterfazJ2(int& R, char *J2, int& total_2, int vD[], int vP[], int vR[], int may, bool& esca) {
    int lanza;
    int mayorRonda;
    int numDadoMayor;
    int RepesMayor;


    for (int x=1; x<=3; x++){
        lanza = x;
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
        cout << " TURNO DE: " << J2 << "   RONDA NUMERO: " << R << "   PUNTAJE TOTAL: "<< total_2 ;

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

            for (int x=1; x<=3; x++){
                vP[x]=0;
            }

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

    total_2 = total_2 + mayorRonda;
    ponerCero(vP, 4);
    ponerCero(vD, 6);
    mayorRonda = 0;
    numDadoMayor = 0;
    RepesMayor = 0;

}

void EntreTurno1(int R, char *J1, char *J2, int& total_1, int& total_2){

        negro();

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

        rlutil::locate(50, 16);
        cout<< "PRIMER TURNO: " << J1;

        rlutil::locate(50, 18);
        cout<< "PUNTAJE " << J1 << ": " << total_1;

        rlutil::locate(50, 19);
        cout<< "PUNTAJE " << J2 << ": " << total_2;


        rlutil::anykey();
}

void EntreTurno2 (int R, char *turno, char *J1, char *J2, int& total_1, int& total_2){

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
        cout<< "PUNTAJE " << J1 << ": " << total_1;

        rlutil::locate(50, 19);
        cout<< "PUNTAJE " << J2 << ": " << total_2;

        negro();

        rlutil::anykey();
}

int CalcularPuntos(int numDado, int Repes, int vDados[]){

int resultado=0;

    if (Repes>1 && Repes<3){
        resultado = sumarVector(vDados, 7);
    }
    if (Repes>=3 && Repes<6){
        resultado = numDado * 10;
    }
    if (Repes==6 &&  numDado!=6){
        resultado = numDado * 50;
    }
        return resultado;
}

void ganador(char *campeon, int R, int puntaje){

        azul();

        rlutil::locate(39, 13);
        cout<< (char) 201;

        rlutil::locate(39, 21);
        cout<< (char) 200;

        rlutil::locate(81, 13);
        cout<< (char) 187;

        rlutil::locate(81, 21);
        cout<< (char) 188;

        //COLUMNAS
        for(int ycol=13; ycol<20; ycol++){

            rlutil::locate(39, ycol+1);
            cout<<( char) 186;

            rlutil::locate(81, ycol+1);
            cout<<( char) 186;

        }

        //FILAS
        for (int xcol = 40; xcol <= 80; xcol++) {
            rlutil::locate(xcol, 13);
            cout<< (char) 205;

            rlutil::locate(xcol, 21);
            cout<< (char) 205;

        }

        rlutil::locate(43, 16);
        cout << "El ganador es: " << campeon << " con " << puntaje << " puntos ";
        rlutil::locate(48, 18);
        cout << "La partida duro: " << R << " rondas";

        rlutil::anykey();

}

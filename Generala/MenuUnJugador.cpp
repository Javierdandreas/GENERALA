#include<iostream>
#include<cstdlib>
#include"rlutil.h"

using namespace std;
#include "Menu.h"
#include "MenuUnJugador.h"

void MenuUnJugador (){
    do {

        rlutil::setBackgroundColor(rlutil::BLUE);
        int xcol;
        // primera linea
        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(14, 2);
        cout<< (char) 201;
        rlutil::locate(14, 3);
        cout<<( char) 186;
        rlutil::locate(14, 4);
        cout<< (char) 200;


        for (xcol = 15; xcol <= 116; xcol++) {
        rlutil::locate(xcol, 2);
        cout<< (char) 205;
        rlutil::locate(xcol, 4);
        cout<< (char) 205;


        }

        rlutil::locate(116, 2);
        cout<< (char) 187;
        rlutil::locate(116, 3);
        cout<< (char) 186;
        rlutil::locate(116, 4);
        cout<< (char) 188;

        //SEGUNDA LINEA

        char vtitulo[] = "BIENVENIDO JUGADOR A LA ESCALERA";
        int vlongitud;
        vlongitud = strlen(vtitulo);
        int vcentro = (((80 - vlongitud) / 2) + 1);

        for (xcol = 49; xcol <= vcentro; xcol++) {
        }
            rlutil::locate(xcol, 3); cout<<(vtitulo);

        }while(repite);
}

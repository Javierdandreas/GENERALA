#include<iostream>
#include<cstdlib>
#include"rlutil.h"

using namespace std;

#include "Menu.h"

void TituloAnimado(){
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

        char vtitulo[] = "BIENVENIDO A ESCALERA";
        int vlongitud;
        vlongitud = strlen(vtitulo);
        int vcentro = (((80 - vlongitud) / 2) + 1);

        for (xcol = 49; xcol <= vcentro; xcol++) {
        }
            rlutil::locate(xcol, 3); cout<<(vtitulo);
        }

enum Opciones {
	Opcion1=0,
	Opcion2=1,
	Opcion3=2,
	Salir=3
};

void Seleccion(const char* text, int posx, int posy, bool selected) {

	if (selected) {
		rlutil::setBackgroundColor(rlutil::BLUE);
		rlutil::locate(posx - 3, posy);
		cout <<" "<<(char)175<<" "<< text <<" "<<(char)174<<" "<<endl;

	}
	else {
		rlutil::setBackgroundColor(rlutil::BLACK);
		rlutil::locate(posx-3, posy);
		cout <<"   "<< text <<"   "<<endl;
	}

	rlutil::setBackgroundColor(rlutil::BLACK);
}

void MostarMenuPrincipal(){
    int op = 1;
	int y = 0; //Variable para que se muestre cual estoy seleccionando, si arriba o abajo
	rlutil::hidecursor();

	do {

        TituloAnimado();

	    rlutil::cls;

		rlutil::setBackgroundColor(rlutil::BLACK);
		rlutil::setColor(rlutil::WHITE);
		rlutil::hidecursor();

		Seleccion("   UN JUGADOR   ", 52, 10, y == Opcion1);
		Seleccion("  DOS JUGADORES ", 52, 11, y == Opcion2);
		Seleccion("     REGLAS     ", 52, 12, y == Opcion3);
		Seleccion("     SALIR      ", 52, 13, y == Salir);

		switch (rlutil::getkey()){
		case 14: // ARRIBA
			rlutil::locate(28, 10 + y);
			cout << " " << endl;
			//Aca se ira restando a "y" para ir cambiando su posicion y que suba.
			y--;
			if (y < 0)
                {y = 0;}
			break;

		case 15: // ABAJO
			rlutil::locate(28, 10 + y);
			cout << " " << endl;
			//Aca se ira sumando a "y" para ir cambiando su posicion y que baje.
			y++;
			if (y > 3)
                {y = 3;}
			break;

		case 1: // ENTER
			switch (y){
			    case 3:
                    op = 0;
                default:
                break;
            }

			break;
		default:
			break;
		}
	} while (op != 0);
}

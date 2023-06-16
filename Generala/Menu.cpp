#include<iostream>
#include<cstdlib>
#include"rlutil.h"
#include<cstdlib>
using namespace std;
#include "Reglas.h"
#include "Menu.h"
#include "Dados.h"

int TituloAnimado(const char *titulo, int posx){
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
        rlutil::locate(posx, 3);
        cout<<titulo;
}

void Seleccion(const char* text, int posx, int posy, bool selected) {
    //Recibe una cadena de caracteres, su posicion y un booleano para saber si esta seleccionado o no (usamos la variable "y" que sube o baja para saber si vale 0, 1, 2, 3)
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

enum OPCIONES {
    OP1=0,
    OP2=1,
    OP3=2,
    SALIR=3

};

void MenuPrincipal(){
    bool repite = true;

	int y = 0; //Variable para que se muestre cual estoy seleccionando, si arriba o abajo
	rlutil::hidecursor();

	do {
       rlutil::cls;

        TituloAnimado("BIENVENIDO A ESCALERA", 50);


		rlutil::setBackgroundColor(rlutil::BLACK);
		rlutil::setColor(rlutil::WHITE);
		rlutil::hidecursor();

        //Llamo a la funcion Seleccion y le envio los parametros

		Seleccion("   UN JUGADOR   ", 52, 10, y == OP1);
		Seleccion("  DOS JUGADORES ", 52, 11, y == OP2);
		Seleccion("     REGLAS     ", 52, 12, y == OP3);
		Seleccion("     SALIR      ", 52, 13, y == SALIR);

        rlutil::cls;

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
            case 0:
                system("cls");

                TituloAnimado("MODO DE UN JUGADOR", 51);



                rlutil::anykey();
                break;

            case 1:
                system("cls");

                TituloAnimado("MODO DOS JUGADORES", 51);




                rlutil::anykey();
                break;

            case 2:
                system("cls");
                MenuReglas();
                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::BLACK);
                system("cls");

                break;

            case 3:
                repite = false;

            default:
                break;
            }
        break;
		default:
        break;
		}

	} while (repite);
}

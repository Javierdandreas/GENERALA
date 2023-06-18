#include<iostream>
#include<cstdlib>
#include"rlutil.h"

using namespace std;
#include "Reglas.h"
#include "Menu.h"
#include "Dados.h"


void MenuReglas (){

        TituloAnimado("REGLAS DE LA ESCALERA", 50);
        rlutil::locate(25, 10);
        cout << "Las partidas estan compuestas por cierta cantidad de rondas." << endl;

        rlutil::locate(25, 11);
        cout << "Una ronda esta compuesta por 3 lanzamientos"<< endl;

        rlutil::locate(25, 12);
        cout << "y un lanzamiento consiste en tirar 6 dados y evaluar sus valores para determinar el puntaje"<< endl;

        rlutil::locate(25, 16);
        cout << "Como se determina el puntaje?" << endl;

        rlutil::locate(27, 17);
        cout << "Sera el valor maximo obtenido entre los 3 lanzamientos con 2 excepciones: " << endl;

        rlutil::locate(27, 18);
        cout << "1) Si se obtiene Escalera GANA EL PARTIDO en ese momento" << endl;
        Escalera();

        azul();
        rlutil::locate(25, 24);
        cout << "El orden puede ser desordenado. No necesariamente tiene que estarlo como se ve en el ejemplo" << endl;

        rlutil::locate(25, 27);
        cout << "2) Si se obtiene 6 dados con valor 6 el puntaje de la ronda sera 0" << endl;
        negro();
        Sexteto6();

        azul();
        rlutil::locate(25, 35);
        cout << "Luego hay 3 tipos de conbinaciones mas:";

        rlutil::locate(25, 37);
        cout << "SUMA DE DADOS: ";

        rlutil::locate(26, 38);
        cout << "Su condicion debe ser que tienen que haber menos de 3 dados iguales, su maximo son dos";

        rlutil::locate(85, 41);
        cout << " 6 + 5 + 5 + 2 + 2 + 1 = 21 puntos";

        negro();
        SumaDados();

        azul();
        rlutil::locate(25, 47);
        cout << "TRIO X: " ;

        rlutil::locate(26, 48);
        cout << "Su condicion debe ser que tienen que haber mas de 3 dados iguales, su maximo son cinco";

        rlutil::locate(85, 50);
        cout << "Si hay 2 ternas de dados se elige";

        rlutil::locate(85, 51);
        cout << "la que otorgue mayor puntaje";

        rlutil::locate(85, 53);
        cout << " X * 10 = PUNTOS ";

        rlutil::locate(85, 54);
        cout << " 2 * 10 = 20 PUNTOS ";
        negro();
        TrioX();

        azul();
        rlutil::locate(25, 58);
        cout << "SEXTETO X ";

        rlutil::locate(26, 59);
        cout << "Su condicion debe ser los 6 dados iguales (EXCEPTO EL 6) ";

        rlutil::locate(85, 62);
        cout << " X * 50 = PUNTOS ";

        rlutil::locate(85, 63);
        cout << " 5 * 50 = 250 PTS ";
        negro();
        SextetoX();

}
void negro (){
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void azul (){
    rlutil::setBackgroundColor(rlutil::BLUE);
}

void SumaDados (){
        DibujarDados(6, 25, 40);
        DibujarDados(5, 35, 40);
        DibujarDados(5, 45, 40);
        DibujarDados(2, 55, 40);
        DibujarDados(2, 65, 40);
        DibujarDados(1, 75, 40);
}

void TrioX (){
        DibujarDados(1, 25, 50);
        DibujarDados(1, 35, 50);
        DibujarDados(1, 45, 50);
        DibujarDados(2, 55, 50);
        DibujarDados(2, 65, 50);
        DibujarDados(2, 75, 50);
}
void SextetoX (){
        DibujarDados(5, 25, 61);
        DibujarDados(5, 35, 61);
        DibujarDados(5, 45, 61);
        DibujarDados(5, 55, 61);
        DibujarDados(5, 65, 61);
        DibujarDados(5, 75, 61);
}
void Escalera (){
        DibujarDados(1, 25, 20);
        DibujarDados(2, 35, 20);
        DibujarDados(3, 45, 20);
        DibujarDados(4, 55, 20);
        DibujarDados(5, 65, 20);
        DibujarDados(6, 75, 20);
}
void Sexteto6 (){
        DibujarDados(6, 25, 29);
        DibujarDados(6, 35, 29);
        DibujarDados(6, 45, 29);
        DibujarDados(6, 55, 29);
        DibujarDados(6, 65, 29);
        DibujarDados(6, 75, 29);
}

#include "Reglas.h"

#include <iostream>
#include "rlutil.h"
#include "Dados.h"
using namespace std;
#include "funciones.h"


int main(){

    DibujarDados(1, 1, 5);
    DibujarDados(2, 10, 5);
    DibujarDados(3, 20, 5);
    DibujarDados(4, 30, 5);
    DibujarDados(5, 40, 5);
    DibujarDados(6, 50, 5);


    rlutil::locate(1, 24);
    cout<<endl;
	system("pause");
    return 0;
}

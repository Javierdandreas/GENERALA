#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
#include "TestDados.h"
#include "rlutil.h"
using namespace rlutil;

int main()
{
    int opcion, i, dados[5], j, casos;
    bool cicloinfinito = true;

    while (cicloinfinito)
    {
        setBackgroundColor(CYAN);
        casos = MenuPrincipalGenerala(); //LLamamos al menu Principal

        i = 1;

        switch (casos)
        {
        case 9:
            system("cls");
            cargarAleatorio(dados, 5, 6);
            cout << "Ejemplo de dados:  " << endl;
            MenuDeDados(dados);
            cout << "\n" << "\n" <<endl;
            system("pause");
        break;
        /////////////////////////////////////////////////////
        case 10:
            system("cls");
            for (j=0;j<5 ;j++ ){
            cout<<"Ingrese el valor del dado "<<j+1<<":"<<endl;
            cin>>dados[j];
            while(!(dados[j]>0&&dados[j]<7)){
                cout<<"Valor de dado Inexistente, por favor ingrese un numero del 1 al 6: "<<endl;
                cin>>dados[j];
                }
            }
            system("cls");
            MenuDeDados(dados);
            cout << "\n" << "\n" <<endl;
            system("pause");
            break;
        /////////////////////////////////////////////////////
        case 11:
            system("cls");
            exit(0);
        break;
};
system("cls");
}
system("pause");
return 0;
}

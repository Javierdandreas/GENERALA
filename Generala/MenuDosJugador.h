#ifndef MENU_DOS_JUGADOR_H_INCLUDED
#define MENU_DOS_JUGADOR_H_INCLUDED

void MenuDosJugadores();

void InterfazJ1(int&, char *J1, int&, int[], int[], int[], int, bool&);

void InterfazJ2(int&, char *J2, int&, int[], int[], int[], int, bool&);

void EntreTurno1(int, char *J1, char*J2, int&, int&);

void EntreTurno2(int,  char *turno, char *J1, char*J2, int&, int&);

int CalcularPuntos(int, int, int, int[], int [], bool);

void ganador(char*, int, int);

#endif // MENU_DOS_JUGADOR_H_INCLUDED

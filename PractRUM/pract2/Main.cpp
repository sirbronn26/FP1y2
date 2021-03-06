//NOMBRES:Carlos Forriol Molina cforriol@ucm.es
//No? Arones de la Cruz noarones@ucm.es
#include <utility>
#include<iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int menu();
#include "Bolsa.h"
#include "tablero.h"
#include "Fichas.h"



int main() {

	tBolsa bolsa;
	tSoportes soportes;
	tTablero tablero;
	int jugActual = 0;
	int op = menu();

	inicializarBolsa(bolsa);
	repartir(bolsa, soportes);

	cout << "Turno para el jugador " << jugActual + 1 << "..." << endl << endl;

	while (op != 5) {
		mostrar(tablero);

		if (op == 1) {
			ordenarPorNum(soportes.soportes[jugActual]);
			mostrar(soportes.soportes[jugActual]);
		}
		else if (op == 2) {
			ordenarPorColor(soportes.soportes[jugActual]);
			mostrar(soportes.soportes[jugActual]);
		}
		else if (op == 3) {
			mostrarSeries(soportes.soportes[jugActual]);
			mostrarEscaleras(soportes.soportes[jugActual]);
		}
		else if (op == 4) {
			jugar(tablero, soportes.soportes[jugActual]);
		}

		else if (op == 0) {
			jugActual++;
			if (jugActual >= NUMJUGADORES)jugActual = 0;
			cout << "Turno para el jugador " << jugActual + 1 << " ..." << endl << endl;
			mostrar(tablero);
			mostrar(soportes.soportes[jugActual]);
		}

		op = menu();
		if (soportes.soportes[jugActual].cont == 0) {
			cout << "El jugador " << jugActual + 1 << " ha ganado!" << endl;
			op = 5;
		}
	}

	int ganador = menor(soportes);
	cout << "El jugador " << ganador + 1 << " ha ganado!" << endl;
	delTablero(tablero);
	delSoportes(soportes);
	delBolsa(bolsa);
	_CrtDumpMemoryLeaks();
}
int menu() {

	int op;

	cout << "1: Ordenar por num.  ";
	cout << "2: Ordenar por color.  ";
	cout << "3: Sugerir.  ";
	cout << "4: Poner.  ";
	cout << "0: Fin turno.  ";
	cout << "5: Salir Programa >>>  ";
	cin >> op;
	while ((op < 0) || (op > 5)) {
		cout << "Opcion no valida. Introduce otra opcion: ";
		cin >> op;
	}
	return op;
}
void mostrarIndices(int num) {
	cout << "          " << 1 << "  ";
	for (int i = 2; i < num + 1; i++) {
		cout << i << "  ";
	}
	cout << endl;
}
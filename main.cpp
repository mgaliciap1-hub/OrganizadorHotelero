#include <iostream>
#include <fstream>
#include <sstream>
#include "estructuras.h"
#include "persistencia.h"

using namespace std;

Habitacion habitaciones[MAX_HABITACIONES];
int totalHabitaciones = 0;
Huesped huespedes[MAX_HUESPEDES];
int totalHuespedes = 0;
Reservacion reservaciones[MAX_RESERVAS];
int totalReservas = 0;
int mapaHotel[PISOS][HABS_POR_PISO];

void actualizarMatriz() {
    for (int p = 0; p < PISOS; p++)
        for (int h = 0; h < HABS_POR_PISO; h++)
            mapaHotel[p][h] = 0;

    for (int i = 0; i < totalHabitaciones; i++) {
        int piso = (habitaciones[i].numero / 100) - 1;
        int col = (habitaciones[i].numero % 100) - 1;
        if (piso >= 0 && piso < PISOS && col >= 0 && col < HABS_POR_PISO) {
            mapaHotel[piso][col] = (habitaciones[i].estado == 1) ? 1 : 2;
        }
    }
}

void mostrarMapaHotel() {
    actualizarMatriz();
    cout << "\n-- MAPA DEL HOTEL --\n[0=Vacio | 1=Ocupado | 2=Disponible]\n" << endl;
    for (int p = PISOS - 1; p >= 0; p--) {
        cout << "Piso " << (p + 1) << ": ";
        for (int h = 0; h < HABS_POR_PISO; h++) cout << "[" << mapaHotel[p][h] << "] ";
        cout << endl;
    }
}

void generarReporte() {
    cout << "\n-- REPORTES --" << endl;
    cout << "Habitaciones totales: " << totalHabitaciones << endl;
    cout << "Reservas activas: " << totalReservas << endl;
}

void guardarDatos() {
    ofstream fHab("habitaciones.txt");
    for (int i = 0; i < totalHabitaciones; i++)
        fHab << habitaciones[i].numero << "," << habitaciones[i].tipo << "," << habitaciones[i].tarifa << "," << habitaciones[i].estado << "\n";
    fHab.close();
}

void cargarDatos() {
    actualizarMatriz();
}
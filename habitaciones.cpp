#include <iostream>
#include "estructuras.h"
#include "habitaciones.h"
#include "persistencia.h"

using namespace std;

void registrarHabitacion() {
    if (totalHabitaciones >= MAX_HABITACIONES) {
        cout << "[X] Capacidad maxima alcanzada." << endl;
        return;
    }
    Habitacion h;
    cout << "\n-- Registrar Habitacion --" << endl;
    cout << "Numero (101 a 405): ";
    cin >> h.numero;

    if (buscarHabitacion(h.numero) != -1) {
        cout << "[X] El numero ya existe." << endl;
        return;
    }

    cout << "Tipo (Sencilla / Doble / Suite): ";
    cin.ignore();
    getline(cin, h.tipo);
    cout << "Tarifa por noche: ";
    cin >> h.tarifa;
    h.estado = 0;

    habitaciones[totalHabitaciones++] = h;
    actualizarMatriz();
    cout << "[OK] Habitacion registrada." << endl;
}

int buscarHabitacion(int numero) {
    for (int i = 0; i < totalHabitaciones; i++) {
        if (habitaciones[i].numero == numero) return i;
    }
    return -1;
}

void consultarHabitaciones() {
    cout << "\n-- HABITACIONES --" << endl;
    for (int i = 0; i < totalHabitaciones; i++) {
        cout << "Habitacion " << habitaciones[i].numero 
             << " | Tipo: " << habitaciones[i].tipo 
             << " | Q" << habitaciones[i].tarifa 
             << " | Estado: " << (habitaciones[i].estado == 0 ? "Disponible" : "Ocupada") << endl;
    }
}
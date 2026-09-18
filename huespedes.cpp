#include <iostream>
#include "estructuras.h"
#include "huespedes.h"

using namespace std;

void registrarHuesped() {
    if (totalHuespedes >= MAX_HUESPEDES) {
        cout << "[X] Limite de huespedes alcanzado." << endl;
        return;
    }
    Huesped h;
    cout << "\n-- Registrar Huesped --" << endl;
    cout << "DPI: ";
    cin >> h.dpi;

    if (buscarHuesped(h.dpi) != -1) {
        cout << "[!] Ya registrado." << endl;
        return;
    }

    cout << "Nombre Completo: ";
    cin.ignore();
    getline(cin, h.nombre);
    cout << "Telefono: ";
    getline(cin, h.telefono);

    huespedes[totalHuespedes++] = h;
    cout << "[OK] Huesped registrado." << endl;
}

int buscarHuesped(string dpi) {
    for (int i = 0; i < totalHuespedes; i++) {
        if (huespedes[i].dpi == dpi) return i;
    }
    return -1;
}

void consultarHuespedes() {
    cout << "\n-- HUESPEDES --" << endl;
    for (int i = 0; i < totalHuespedes; i++) {
        cout << "DPI: " << huespedes[i].dpi << " | Nombre: " << huespedes[i].nombre << endl;
    }
}
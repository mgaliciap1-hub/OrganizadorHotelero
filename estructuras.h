#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
using namespace std;

const int MAX_HABITACIONES = 20;
const int MAX_HUESPEDES = 50;
const int MAX_RESERVAS = 100;
const int PISOS = 4;
const int HABS_POR_PISO = 5;

struct Habitacion {
    int numero;
    string tipo;
    double tarifa;
    int estado;
};

struct Huesped {
    string dpi;
    string nombre;
    string telefono;
};

struct Reservacion {
    int id;
    int numHabitacion;
    string dpiHuesped;
    int dias;
    double costoTotal;
    int estado;
};

extern Habitacion habitaciones[MAX_HABITACIONES];
extern int totalHabitaciones;
extern Huesped huespedes[MAX_HUESPEDES];
extern int totalHuespedes;
extern Reservacion reservaciones[MAX_RESERVAS];
extern int totalReservas;
extern int mapaHotel[PISOS][HABS_POR_PISO];

#endif

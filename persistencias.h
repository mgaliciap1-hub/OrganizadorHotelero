#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <string>
using namespace std;

const int MAX_HABITACIONES = 100;
const int MAX_HUESPEDES = 100;
const int MAX_RESERVAS = 100;
const int PISOS = 5;
const int HABS_POR_PISO = 10;

struct Habitacion { int numero; string tipo; float tarifa; int estado; };
struct Huesped { int id; string nombre; string nit; };
struct Reservacion { int id; int idHabitacion; int idHuesped; };

#endif
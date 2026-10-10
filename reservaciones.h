#ifndef RESERVACIONES_H
#define RESERVACIONES_H

#include "estructuras.h"

//funciones para el módulo de reservaciones
bool crearReservacion(Reservacion res[], int &cantR, Habitacion hab[], int cantH, Huesped hues[], int cantHu, Reservacion nueva);
float realizarCheckOut(Reservacion res[], int cantR, Habitacion hab[], int cantH, int idRes);

#endif

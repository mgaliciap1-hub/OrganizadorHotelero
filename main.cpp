#include <iostream>
#include <fstream>
#include <sstream>
#include "estructuras.h"
#include "habitaciones.h"
#include "huespedes.h"
#include "persistencia.h"
#include "reservaciones.h"

using namespace std;

// variables globales del sistema
Habitacion habitaciones[MAX_HABITACIONES];
int totalHabitaciones = 0;
Huesped huespedes[MAX_HUESPEDES];
int totalHuespedes = 0;
Reservacion reservaciones[MAX_RESERVAS];
int totalReservas = 0;
int mapaHotel[PISOS][HABS_POR_PISO];

int main() {
    cargarDatos();
    int opcion = 0;

    do {
        cout << "\n=========================================" << endl;
        cout << "    SISTEMA DE RESERVACIONES DE HOTEL     " << endl;
        cout << "=========================================" << endl;
        cout << "1. Registrar Habitacion" << endl;
        cout << "2. Consultar Habitaciones" << endl;
        cout << "3. Registrar Huesped" << endl;
        cout << "4. Consultar Huespedes" << endl;
        cout << "5. Registrar Reservacion (Check-In)" << endl;
        cout << "6. Procesar Check-Out" << endl;
        cout << "7. Ver Mapa del Hotel" << endl;
        cout << "8. Generar Reportes" << endl;
        cout << "9. Guardar Datos" << endl;
        cout << "10. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarHabitacion();
                break;
            case 2:
                consultarHabitaciones();
                break;
            case 3:
                registrarHuesped();
                break;
            case 4:
                consultarHuespedes();
                break;
            case 5: 
                reservacionnueva();
                break;
            case 6: 
                procesarCheckout();
                break;
            case 7:
                mostrarMapaHotel();
                break;
            case 8:
                generarReporte();
                break;
            case 9:
                guardarDatos();
                break;
            case 10:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "[X] Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 10);

    return 0;
}

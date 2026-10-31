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

            case 5: {
                Reservacion nueva;
                cout << "\n--- REGISTRO DE RESERVACION ---" << endl;
                cout << "Ingrese ID de la Reserva: ";
                cin >> nueva.id;
                cout << "Ingrese Dias de estancia: ";
                cin >> nueva.dias;
                
                if (crearReservacion(reservaciones, totalReservas, habitaciones, totalHabitaciones, huespedes, totalHuespedes, nueva)) {
                    cout << "[OK] Reservacion registrada con exito." << endl;
                } else {
                    cout << "[ERROR] No se pudo realizar el registro." << endl;
                }
                break;
            }

            case 6: {
                int idBusqueda;
                cout << "\n--- PROCESAR CHECK-OUT ---" << endl;
                cout << "Ingrese ID de Reservacion a cerrar: ";
                cin >> idBusqueda;
                
                float total = realizarCheckOut(reservaciones, totalReservas, habitaciones, totalHabitaciones, idBusqueda);
                cout << "Monto Total a Pagar: Q " << total << endl;
                break;
            }

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

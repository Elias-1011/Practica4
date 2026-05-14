#include <iostream>
#include "Red.h"
#include "utilidades.h"

using namespace std;

int main() {
    Red red;
    int opcion;
    string origen, destino, archivo;
    int costo;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Nombre del enrutador: ";
            cin >> origen;
            red.agregarEnrutador(origen);
            red.actualizarTablas();
            cout << "Enrutador agregado correctamente.\n";
            break;

        case 2:
            cout << "Nombre del enrutador a eliminar: ";
            cin >> origen;
            red.eliminarEnrutador(origen);
            cout << "Operacion finalizada.\n";
            break;

        case 3:
            cout << "Enrutador origen: ";
            cin >> origen;
            cout << "Enrutador destino: ";
            cin >> destino;
            cout << "Costo del enlace: ";
            cin >> costo;
            red.conectar(origen, destino, costo);
            cout << "Enrutadores conectados correctamente.\n";
            break;

        case 4:
            cout << "Enrutador origen: ";
            cin >> origen;
            cout << "Enrutador destino: ";
            cin >> destino;
            red.desconectar(origen, destino);
            cout << "Operacion finalizada.\n";
            break;

        case 5:
            cout << "Nombre del enrutador: ";
            cin >> origen;
            red.mostrarVecinos(origen);
            break;

        case 6:
            cout << "Nodo origen: ";
            cin >> origen;
            red.actualizarTablas();
            red.calcularRutasDesde(origen);
            cout << "\nTabla de costos guardada en el enrutador " << origen << ":\n";
            red.mostrarTablaCostos(origen);
            break;

        case 7:
            cout << "Nombre del archivo: ";
            cin >> archivo;
            if (cargarRedDesdeArchivo(red, archivo)){
                red.actualizarTablas();
                cout << "Tablas actualizadas despues de cargar el archivo.\n";
            }
            break;

        case 8:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 8);

    return 0;
}

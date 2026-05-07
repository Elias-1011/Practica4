#include <iostream>
#include "Red.h"

using namespace std;

void mostrarMenu() {
    cout << "\n===== SIMULADOR DE RED DE ENRUTADORES =====\n";
    cout << "1. Agregar enrutador\n";
    cout << "2. Eliminar enrutador\n";
    cout << "3. Conectar enrutadores\n";
    cout << "4. Desconectar enrutadores\n";
    cout << "5. Mostrar vecinos de un enrutador\n";
    cout << "6. Calcular rutas y mostrar tabla de costos\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    Red red;
    int opcion;
    string origen, destino;
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
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 7);

    return 0;
}

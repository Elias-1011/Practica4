#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void mostrarMenu() {
    cout << "\n===== SIMULADOR DE RED DE ENRUTADORES =====\n";
    cout << "1. Agregar enrutador\n";
    cout << "2. Eliminar enrutador\n";
    cout << "3. Conectar enrutadores\n";
    cout << "4. Desconectar enrutadores\n";
    cout << "5. Mostrar vecinos de un enrutador\n";
    cout << "6. Calcular rutas y mostrar tabla de costos\n";
    cout << "7. Cargar red desde archivo\n";
    cout << "8. Salir\n";
    cout << "Seleccione una opcion: ";
}

bool cargarRedDesdeArchivo(Red& red, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << "\n";
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string origen, destino;
        int costo;
        ss >> origen >> destino >> costo;

        if (origen.empty() || destino.empty() || ss.fail()) {
            cerr << "Línea inválida: " << linea << "\n";
            continue;
        }

        red.conectar(origen, destino, costo);
    }

    archivo.close();
    cout << "Red cargada correctamente desde el archivo.\n";
    return true;
}

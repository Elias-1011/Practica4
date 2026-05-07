#include "enrutador.h"
#include <iostream>
#include <climits>

Enrutador::Enrutador() {
    nombre = "";
}

Enrutador::Enrutador(const std::string& nombre) {
    this->nombre = nombre;
    tablaCostos[nombre] = 0;
}

void Enrutador::agregarVecino(const std::string& destino, int costo) {
    vecinos[destino] = costo;
    tablaCostos[destino] = costo;
}

void Enrutador::eliminarVecino(const std::string& destino) {
    vecinos.erase(destino);
    tablaCostos.erase(destino);
}

std::map<std::string, int> Enrutador::obtenerVecinos() const {
    return vecinos;
}

std::string Enrutador::obtenerNombre() const {
    return nombre;
}

void Enrutador::actualizarCosto(const std::string& destino, int costo) {
    tablaCostos[destino] = costo;
}

void Enrutador::establecerTablaCostos(const std::map<std::string, int>& tabla) {
    tablaCostos = tabla;
}

std::map<std::string, int> Enrutador::obtenerTablaCostos() const {
    return tablaCostos;
}

void Enrutador::mostrarTablaCostos() const {
    std::cout << "Tabla de costos de " << nombre << ":\n";

    if (tablaCostos.empty()) {
        std::cout << "  No hay costos calculados.\n";
        return;
    }

    for (const auto& par : tablaCostos) {
        std::cout << "  Destino: " << par.first << " | Costo: ";

        if (par.second == INT_MAX) {
            std::cout << "INF";
        } else {
            std::cout << par.second;
        }

        std::cout << std::endl;
    }
}

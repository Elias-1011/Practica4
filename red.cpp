#include "Red.h"
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void Red::agregarEnrutador(const string& nombre) {
    if (enrutadores.find(nombre) == enrutadores.end()) {
        enrutadores[nombre] = Enrutador(nombre);
    }
}

void Red::eliminarEnrutador(const string& nombre) {
    if (enrutadores.find(nombre) == enrutadores.end()) {
        cout << "El enrutador no existe.\n";
        return;
    }

    enrutadores.erase(nombre);

    for (auto& par : enrutadores) {
        par.second.eliminarVecino(nombre);
    }

    actualizarTablas();
}

void Red::conectar(const string& origen, const string& destino, int costo) {
    if (costo < 0) {
        cout << "El costo no puede ser negativo.\n";
        return;
    }

    agregarEnrutador(origen);
    agregarEnrutador(destino);

    enrutadores[origen].agregarVecino(destino, costo);
    enrutadores[destino].agregarVecino(origen, costo);

    actualizarTablas();
}

void Red::desconectar(const string& origen, const string& destino) {
    if (enrutadores.find(origen) == enrutadores.end() ||
        enrutadores.find(destino) == enrutadores.end()) {
        cout << "Uno de los enrutadores no existe.\n";
        return;
    }

    enrutadores[origen].eliminarVecino(destino);
    enrutadores[destino].eliminarVecino(origen);

    actualizarTablas();
}

void Red::mostrarVecinos(const string& nombre) const {
    auto it = enrutadores.find(nombre);

    if (it == enrutadores.end()) {
        cout << "El enrutador no existe.\n";
        return;
    }

    map<string, int> vecinos = it->second.obtenerVecinos();

    cout << "Vecinos de " << nombre << ":\n";

    if (vecinos.empty()) {
        cout << "  Este enrutador no tiene vecinos conectados.\n";
        return;
    }

    for (const auto& par : vecinos) {
        cout << "  -> " << par.first << " (costo: " << par.second << ")\n";
    }
}

map<string, int> Red::calcularDistanciasDesde(
    const string& origen,
    map<string, string>* anteriores
    ) const {
    map<string, int> distancias;
    map<string, bool> visitado;

    for (const auto& par : enrutadores) {
        distancias[par.first] = INT_MAX;
        visitado[par.first] = false;
    }

    if (enrutadores.find(origen) == enrutadores.end()) {
        return distancias;
    }

    distancias[origen] = 0;

    for (size_t i = 0; i < enrutadores.size(); i++) {
        string actual = "";
        int menorCosto = INT_MAX;

        // Buscar el enrutador no visitado con menor costo
        for (const auto& par : distancias) {
            if (!visitado[par.first] && par.second < menorCosto) {
                menorCosto = par.second;
                actual = par.first;
            }
        }

        if (actual == "") {
            break;
        }

        visitado[actual] = true;

        map<string, int> vecinos = enrutadores.at(actual).obtenerVecinos();

        for (const auto& vecino : vecinos) {
            string destino = vecino.first;
            int costoEnlace = vecino.second;

            if (distancias[actual] != INT_MAX &&
                distancias[actual] + costoEnlace < distancias[destino]) {

                distancias[destino] = distancias[actual] + costoEnlace;

                if (anteriores != nullptr) {
                    (*anteriores)[destino] = actual;
                }
            }
        }
    }

    return distancias;
}

void Red::actualizarTablas() {
    for (auto& par : enrutadores) {
        string origen = par.first;
        map<string, int> distancias = calcularDistanciasDesde(origen, nullptr);
        par.second.establecerTablaCostos(distancias);
    }
}

void Red::mostrarTablaCostos(const string& nombre) const {
    auto it = enrutadores.find(nombre);

    if (it == enrutadores.end()) {
        cout << "El enrutador no existe.\n";
        return;
    }

    it->second.mostrarTablaCostos();
}

void Red::calcularRutasDesde(const string& origen) const {
    if (enrutadores.find(origen) == enrutadores.end()) {
        cout << "El enrutador origen no existe.\n";
        return;
    }

    map<string, string> anteriores;
    map<string, int> distancias = calcularDistanciasDesde(origen, &anteriores);

    cout << "\nRutas desde [" << origen << "]:\n";

    for (const auto& par : distancias) {
        string destino = par.first;
        int costo = par.second;

        if (destino == origen) {
            continue;
        }

        cout << "  -> " << destino << " (costo: ";

        if (costo == INT_MAX) {
            cout << "INF, sin camino)\n";
            continue;
        }

        cout << costo << ", camino: ";

        vector<string> ruta;
        string actual = destino;

        while (actual != origen) {
            ruta.push_back(actual);

            if (anteriores.find(actual) == anteriores.end()) {
                break;
            }

            actual = anteriores[actual];
        }

        ruta.push_back(origen);
        reverse(ruta.begin(), ruta.end());

        for (size_t i = 0; i < ruta.size(); i++) {
            cout << ruta[i];

            if (i < ruta.size() - 1) {
                cout << " -> ";
            }
        }

        cout << ")\n";
    }
}
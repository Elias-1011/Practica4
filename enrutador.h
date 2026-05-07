#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <map>
#include <string>


class Enrutador {
private:
    std::string nombre;
    std::map<std::string, int> vecinos;      // vecino -> costo directo
    std::map<std::string, int> tablaCostos;  // destino -> costo minimo

public:
    Enrutador();
    Enrutador(const std::string& nombre);

    void agregarVecino(const std::string& destino, int costo);
    void eliminarVecino(const std::string& destino);

    std::map<std::string, int> obtenerVecinos() const;
    std::string obtenerNombre() const;

    void actualizarCosto(const std::string& destino, int costo);
    void establecerTablaCostos(const std::map<std::string, int>& tabla);
    std::map<std::string, int> obtenerTablaCostos() const;
    void mostrarTablaCostos() const;
};

#endif // ENRUTADOR_H

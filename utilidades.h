#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "red.h"
#include <string>

using namespace std;

void mostrarMenu();
bool cargarRedDesdeArchivo(Red& red, const string& nombreArchivo);

#endif // UTILIDADES_H

#include "red.h"

void Red::agregarEnrutador(const std::string& nombre) {
    enrutadores[nombre] = Enrutador(nombre);
}

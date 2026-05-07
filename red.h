#ifndef RED_H
#define RED_H
#include <map>

using namespace std;

class red{
private:
    map<string, Enrutador> enrutadores;

public:
    void agregarEnrutador(const string& nombre);
};

#endif // RED_H

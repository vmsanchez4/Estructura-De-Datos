#include <iostream>
#include "../Listas/Validaciones.h"

using namespace std;

extern "C" __declspec(dllimport)
Validaciones* crearValidaciones();

int main() {
    Validaciones* v = crearValidaciones();

    if (v->validarCedula("1753039948")) {
        cout << "Cedula valida" << endl;
    } else {
        cout << "Cedula invalida" << endl;
    }

    return 0;
}

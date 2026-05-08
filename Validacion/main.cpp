#include <iostream>
#include <string>
#include <limits>
#include "ValidadorCedula.h"

using namespace std;

int main() {
    ValidadorCedula* validador = new ValidadorCedula();
    int opcion = 0;
    string cedula;
    string nombre;

    do {
        cout << "\n--- MENU DE VALIDACION DE CEDULAS ---" << endl;
        cout << "1. Registrar cedula y nombre" << endl;
        cout << "2. Buscar cedula en el listado" << endl;
        cout << "3. Mostrar todas las cedulas registradas" << endl;
        cout << "4. Contar cedulas por provincia" << endl;
        cout << "5. Eliminar cedula" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                cout << "Ingrese el numero de cedula: ";
                cin >> cedula;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingrese el nombre completo: ";
                getline(cin, nombre);

                if (validador->agregarRegistro(cedula, nombre)) {
                    cout << "Cedula registrada correctamente" << endl;
                } else if (!validador->validar(cedula)) {
                    cout << "Cedula invalida" << endl;
                } else {
                    cout << "La cedula ya existe en el listado" << endl;
                }
                break;

            case 2:
                cout << "Ingrese la cedula a buscar: ";
                cin >> cedula;

                if (validador->buscarCedula(cedula)) {
                    cout << "La cedula " << cedula << " se encuentra en el listado." << endl;
                } else {
                    cout << "La cedula " << cedula << " NO se encuentra en el listado." << endl;
                }
                break;

            case 3:
                validador->mostrarRegistros();
                break;

            case 4:
                validador->contarPorProvincia();
                break;

            case 5:
                cout << "Ingrese la cedula a eliminar: ";
                cin >> cedula;

                if (validador->eliminarCedula(cedula)) {
                    cout << "Cedula eliminada correctamente." << endl;
                } else {
                    cout << "No se encontro la cedula para eliminar." << endl;
                }
                break;

            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 6);

    delete validador;
    return 0;
}
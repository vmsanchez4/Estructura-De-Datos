#include <iostream>
#include "Auto.h"

using namespace std;

int main() {
    Auto miCamioneta;
    float tanqueEstacion = 15.5f;

    cout << "=== ESTACION DE SERVICIO ===" << endl;
    miCamioneta.ingresarDatos();
    
    cout << "\nLa estacion de servicio tiene disponible: " << tanqueEstacion << " Litros." << endl;

    cout << "\nIniciando carga de combustible conectando manguera (Por Referencia)..." << endl;
    miCamioneta.cargarRef(tanqueEstacion);
    
    cout << "\n--- REPORTE FINAL ---" << endl;
    miCamioneta.mostrarDatos();
    cout << "Combustible restante en la estacion: " << tanqueEstacion << " Litros." << endl;

    return 0;
}
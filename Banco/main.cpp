#include "Cuenta.h"
#include <cstdio>

int main() {
    Cuenta miCuenta;
    double billeteraReal = 100.0;

    miCuenta.ingresarDatos();
    
    printf("\n--- Deposito por Valor (Copia) ---\n");
    miCuenta.depositarValor(20.0); 
    miCuenta.mostrarDatos();

    printf("\n--- Deposito por Referencia (Afecta billetera) ---\n");
    printf("Billetera antes: %.2f\n", billeteraReal);
    miCuenta.depositarRef(billeteraReal);
    miCuenta.mostrarDatos();
    printf("Billetera despues: %.2f\n", billeteraReal);

    return 0;
}
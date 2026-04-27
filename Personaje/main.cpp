#include <iostream>
#include "Personaje.h"

using namespace std;

int main() {
    Personaje miHeroe;
    int pocionRoja = 50;
    int pocionAzul = 30;

    cout << "=== SIMULADOR DE COMBATE RPG ===" << endl;
    miHeroe.ingresarDatos();

    cout << "\n--- Curacion por VALOR (Copia) ---" << endl;
    miHeroe.curarValor(20); 
    miHeroe.mostrarDatos();

    cout << "\n--- Curacion por REFERENCIA (Consume el item) ---" << endl;
    cout << "Inventario ANTES: Pocion Roja = " << pocionRoja << " HP" << endl;
    miHeroe.curarRef(pocionRoja);
    miHeroe.mostrarDatos();
    cout << "Inventario DESPUES: Pocion Roja = " << pocionRoja << " HP (Se ha vaciado)" << endl;

    cout << "\n--- Curacion por PUNTERO (Consume el item) ---" << endl;
    cout << "Inventario ANTES: Pocion Azul = " << pocionAzul << " HP" << endl;
    miHeroe.curarPtr(&pocionAzul); // Usamos & para mandar la direccion
    miHeroe.mostrarDatos();
    cout << "Inventario DESPUES: Pocion Azul = " << pocionAzul << " HP (Se ha vaciado)" << endl;

    return 0;
}
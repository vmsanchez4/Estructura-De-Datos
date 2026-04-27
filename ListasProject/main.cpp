#include "headers/Menu.h"
#include <cstdlib>
#include <new>

// ============================================================
//  PUNTO DE ENTRADA
//  El Menu y todas las listas usan malloc internamente
// ============================================================
int main() {
    // Crear Menu con malloc + placement new
    void* mem  = malloc(sizeof(Menu));
    Menu* menu = new (mem) Menu();

    menu->ejecutar();

    // Destruir y liberar con free
    menu->~Menu();
    free(menu);

    return 0;
}

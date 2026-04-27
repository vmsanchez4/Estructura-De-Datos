#include "headers/Menu.h"

// ============================================================
//  PUNTO DE ENTRADA - main.cpp
// ============================================================
int main() {
    Menu* menu = new Menu();   // Puntero al menu
    menu->ejecutar();
    delete menu;
    return 0;
}

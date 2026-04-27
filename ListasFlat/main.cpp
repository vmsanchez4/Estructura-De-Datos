#include "Menu.h"
#include <cstdlib>
#include <new>

int main() {
    void* mem  = malloc(sizeof(Menu));
    Menu* menu = new (mem) Menu();
    menu->ejecutar();
    menu->~Menu();
    free(menu);
    return 0;
}

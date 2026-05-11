#include "Menus.h"
#include "Banco.h"
#include <iostream>

int main() {
    Banco banco;
    Menus::menuPrincipal(banco);

    std::cout << "\nPrograma finalizado. Presiona ENTER para salir...";
    std::cin.get();
    return 0;
}

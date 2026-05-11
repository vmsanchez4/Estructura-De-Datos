#ifndef MENUS_H
#define MENUS_H

#include "Banco.h"

namespace Menus {
    void menuPrincipal(Banco& banco);
    void menuRegistroUsuario(Banco& banco);
    void menuLogin(Banco& banco);

    void menuUsuario(Banco& banco, Usuario& usuario);
    void menuDepositar(Banco& banco, Usuario& usuario);
    void menuRetirar(Banco& banco, Usuario& usuario);
    void menuTransferir(Banco& banco, Usuario& usuario);
    void menuEstadoCuenta(Usuario& usuario);
    void menuHistorial(Usuario& usuario);
    void menuLogicaConjuntos(Usuario& usuario);
}

#endif

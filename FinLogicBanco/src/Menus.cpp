#include "Menus.h"
#include "Archivos.h"
#include "Validaciones.h"
#include <iostream>
#include <limits>
#include <algorithm>


static void pausa() {
    std::cout << "\nPresiona ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menus::menuPrincipal(Banco& banco) {
    while (true) {
        std::cout << "\n=== Banco FinLogic ===\n";
        std::cout << "1. Registrar usuario\n";
        std::cout << "2. Iniciar sesion\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccion: ";
        int op = Validaciones::pedirOpcionValida(0, 2);
        if (op == 1) {
            menuRegistroUsuario(banco);
        } else if (op == 2) {
            menuLogin(banco);
        } else if (op == 0) {
            break;
        }
    }
}


void Menus::menuRegistroUsuario(Banco& banco) {
    std::string nombre, pais, cedula, numDocumento;
    std::cout << "\n-- Registro de usuario --\n";

    nombre = Validaciones::pedirNombreValido("Nombre");

    std::cout << "Es extranjero?\n";
    std::cout << "1. Si\n";
    std::cout << "2. No\n";
    std::cout << "Seleccion: ";
    int opcionExtranjero = Validaciones::pedirOpcionValida(1, 2);

    bool esExtranjero = (opcionExtranjero == 1);

    if (esExtranjero) {
    pais = Validaciones::pedirNombreValido("Pais");
    numDocumento = Validaciones::pedirDocumentoValido();
} else {
    pais = "Ecuador";
    cedula = Validaciones::pedirCedulaValida();
}

    std::string id, error;
    if (banco.registrarUsuario(nombre, esExtranjero, pais, cedula, numDocumento, id, error)) {
        std::cout << "Registro exitoso. ID asignado: " << id << "\n";
    } else {
        std::cout << "Error: " << error << "\n";
    }

    pausa();
}



void Menus::menuLogin(Banco& banco) {
    std::cout << "\n-- Iniciar sesion --\n";
    std::string id = Validaciones::pedirIdValido();
    Usuario u;
    if (!banco.cargarUsuario(id, u)) {
        std::cout << "Usuario no encontrado.\n";
        pausa();
        return;
    }
    menuUsuario(banco, u);
    banco.guardarUsuario(u);
}


void Menus::menuUsuario(Banco& banco, Usuario& usuario) {
    while (true) {
        std::cout << "\n=== Menu Usuario (" << usuario.nombre << ") ===\n";
        std::cout << "1. Depositar\n";
        std::cout << "2. Retirar\n";
        std::cout << "3. Transferir entre cuentas\n";
        std::cout << "4. Ver estado de cuenta\n";
        std::cout << "5. Historial de transacciones\n";
        std::cout << "6. Ver operaciones logicas y conjuntos\n";
        std::cout << "0. Cerrar sesion\n";
        std::cout << "Seleccion: ";
        int op = Validaciones::pedirOpcionValida(0, 6);

        if (op == 1) menuDepositar(banco, usuario);
        else if (op == 2) menuRetirar(banco, usuario);
        else if (op == 3) menuTransferir(banco, usuario);
        else if (op == 4) menuEstadoCuenta(usuario);
        else if (op == 5) menuHistorial(usuario);
        else if (op == 6) menuLogicaConjuntos(usuario);
        else if (op == 0) break;
    }
    banco.guardarUsuario(usuario);
}


void Menus::menuDepositar(Banco& banco, Usuario& usuario) {
    std::cout << "\n-- Depositar --\n";
    double monto = Validaciones::pedirMontoValido();
    std::string pais = Validaciones::pedirNombreValido("Pais de transaccion");
    std::string motivo;
    EvaluacionLogica eval{};
    bool ok = usuario.depositar(monto, pais, motivo, eval);

    const auto& hist = usuario.historialSesion;
    Transaccion tx = hist.back();
    EvaluacionLogica e = banco.evaluarTransaccion(usuario, tx, hist, usuario.paisRegistro);

    e.P = eval.P;

    Archivos::appendTransaccion(usuario.id, tx);
    Archivos::appendLogica(usuario.id, tx, e);

    if (ok) {
        std::cout << "Deposito exitoso. Nuevo saldo: " << usuario.saldo << "\n";
        Archivos::guardarCuenta(usuario);
    } else {
        std::cout << "Deposito fallido: " << motivo << "\n";
    }
    pausa();
}


void Menus::menuRetirar(Banco& banco, Usuario& usuario) {
    std::cout << "\n-- Retirar --\n";

    double monto = Validaciones::pedirMontoValido();

    std::string pais = Validaciones::pedirNombreValido("Pais de transaccion");

    std::string motivo;
    EvaluacionLogica eval{};
    bool ok = usuario.retirar(monto, pais, motivo, eval);

    const auto& hist = usuario.historialSesion;
    Transaccion tx = hist.back();
    EvaluacionLogica e = banco.evaluarTransaccion(usuario, tx, hist, usuario.paisRegistro);
    e.P = eval.P;

    Archivos::appendTransaccion(usuario.id, tx);
    Archivos::appendLogica(usuario.id, tx, e);

    if (ok) {
        std::cout << "Retiro exitoso. Nuevo saldo: " << usuario.saldo << "\n";
        Archivos::guardarCuenta(usuario);
    } else {
        std::cout << "Retiro fallido: " << motivo << "\n";
    }

    pausa();
}



void Menus::menuTransferir(Banco& banco, Usuario& usuario) {
    std::cout << "\n-- Transferir --\n";
    std::string idDestino = Validaciones::pedirIdValido();

    Usuario destino;
    if (!banco.cargarUsuario(idDestino, destino)) {
        std::cout << "Destino no existe.\n";
        pausa();
        return;
    }

    double monto = Validaciones::pedirMontoValido();
    std::string pais = Validaciones::pedirNombreValido("Pais de transaccion");
    std::string motivo;
    EvaluacionLogica eval{};
    bool ok = usuario.transferirA(destino, monto, pais, motivo, eval);

    if (usuario.historialSesion.empty()) {
        std::cout << "Error interno: no se registró transacción en el origen.\n";
        pausa();
        return;
    }

    Transaccion tx = usuario.historialSesion.back();
    EvaluacionLogica e = banco.evaluarTransaccion(usuario, tx, usuario.historialSesion, usuario.paisRegistro);
    e.P = eval.P;

    Archivos::appendTransaccion(usuario.id, tx);
    Archivos::appendLogica(usuario.id, tx, e);

    if (!destino.historialSesion.empty()) {
        Transaccion txDestino = destino.historialSesion.back();
        Archivos::appendTransaccion(destino.id, txDestino);
        Archivos::appendLogica(destino.id, txDestino, e);
    }

    banco.guardarUsuario(usuario);
    banco.guardarUsuario(destino);

    if (ok) {
        std::cout << "Transferencia exitosa. Nuevo saldo: " << usuario.saldo << "\n";
        Archivos::guardarCuenta(usuario);
        Archivos::guardarCuenta(destino);
    } else {
        std::cout << "Transferencia fallida: " << motivo << "\n";
    }

    pausa();
}



void Menus::menuEstadoCuenta(Usuario& usuario) {
    Banco banco;
    banco.cargarUsuario(usuario.id, usuario);
    std::cout << "\n-- Estado de cuenta --\n";
    std::cout << "ID: " << usuario.id << "\n";
    std::cout << "Nombre: " << usuario.nombre << "\n";
    std::cout << "Pais registro: " << usuario.paisRegistro << "\n";
    std::cout << "Extranjero: " << (usuario.esExtranjero ? "SI" : "NO") << "\n";
    if (!usuario.esExtranjero) std::cout << "Cedula: " << usuario.cedula << "\n";
    std::cout << "Saldo: " << usuario.saldo << "\n";
    std::cout << "Limite diario: " << Banco::LIMITE_DIARIO << "\n";
    std::cout << "Depositado hoy: " << usuario.totalDepositadoHoy << "\n";
    std::cout << "Retirado hoy: " << usuario.totalRetiradoHoy << "\n";
    pausa();
}

void Menus::menuHistorial(Usuario& usuario) {
    Banco banco;
    banco.cargarUsuario(usuario.id, usuario);
    std::cout << "\n-- Historial de transacciones (Sesion) --\n";
    for (const auto& tx : usuario.historialSesion) {
        std::cout << tx.fechaHora << " | " << tx.tipo << " | " << tx.monto
                  << " | " << tx.paisOrigen << " | " << tx.estado
                  << (tx.estado == "FALLIDA" ? (" | " + tx.motivoFalla) : "")
                  << (tx.tipo == "TRANSFERENCIA" ? (" | Dest:" + tx.idDestino) : "")
                  << "\n";
    }
    std::cout << "Nota: El archivo 'transacciones.txt' contiene todo el historial persistente.\n";
    pausa();
}

void Menus::menuLogicaConjuntos(Usuario& usuario) {
    Banco banco;
    banco.cargarUsuario(usuario.id, usuario);
    std::cout << "\n-- Operaciones logicas y conjuntos (Sesion) --\n";

    std::vector<std::string> A, B, C;
    std::vector<std::string> interAB;
    std::vector<std::string> unionBC;
    std::vector<std::string> diffAC;
    std::vector<std::string> diffBC;

    for (size_t i = 0; i < usuario.historialSesion.size(); ++i) {
        std::vector<Transaccion> prev(usuario.historialSesion.begin(),
                                      usuario.historialSesion.begin() + i);

        const auto& tx = usuario.historialSesion[i];
        auto eval = banco.evaluarTransaccion(usuario, tx, prev, usuario.paisRegistro);

        std::cout << tx.idTransaccion << " | " << tx.tipo << " | " << tx.monto
                  << " | P:" << (eval.P ? "1" : "0")
                  << " Q:" << (eval.Q ? "1" : "0")
                  << " R:" << (eval.R ? "1" : "0")
                  << " | " << eval.regla
                  << " | Conjunto: " << eval.conjunto << "\n";

        const bool P = eval.P, Q = eval.Q, R = eval.R;

        if (!P && !Q) {
            A.push_back(tx.idTransaccion);
        } else if (P && Q && R) {
            C.push_back(tx.idTransaccion);
        } else if ((P && Q) || (!P && Q && R) || (P && !Q) || (P && !Q && R)) {
            B.push_back(tx.idTransaccion);
        } else {
            B.push_back(tx.idTransaccion);
        }

        if (!P && Q) interAB.push_back(tx.idTransaccion);
    }

    unionBC = B;
    for (const auto& id : C)
        if (std::find(unionBC.begin(), unionBC.end(), id) == unionBC.end())
            unionBC.push_back(id);

    diffAC = A;
    for (const auto& id : B)
        if (std::find(C.begin(), C.end(), id) == C.end())
            diffBC.push_back(id);

    auto mostrarLista = [](const std::string& nombre, const std::vector<std::string>& v) {
        std::cout << nombre << ": ";
        for (size_t i = 0; i < v.size(); ++i)
            std::cout << v[i] << (i + 1 < v.size() ? ", " : "");
        std::cout << "\n";
    };

    std::cout << "\n";
    mostrarLista("A (normales)", A);
    std::cout << "\n";
    mostrarLista("B (sospechosas)", B);
    std::cout << "\n";
    mostrarLista("C (alto riesgo)", C);
    std::cout << "\n";
    mostrarLista("A interseccion B:operaciones con comportamiento inusual, pero aun validas", interAB);
    std::cout << "\n";
    mostrarLista("B union C:operaciones que requieren revision por seguridad.", unionBC);
    std::cout << "\n";
    mostrarLista("A diferencia C:transacciones seguras y verificadas. ", diffAC);
    std::cout << "\n";

    std::cout << "Nota: 'logica_conjuntos.txt' persiste las evaluaciones por transaccion.";
    pausa();
}


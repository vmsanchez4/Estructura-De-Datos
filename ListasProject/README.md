# Sistema de Listas Enlazadas - C++ POO + Templates + malloc

## Estructura del Proyecto

```
ListasProject/
│
├── ListasProject.sln           <- Abrir con Visual Studio
├── ListasProject.vcxproj
├── main.cpp                    <- Punto de entrada (malloc + placement new)
│
├── headers/                    <- PROTOTIPOS y declaraciones (.h)
│   ├── Persona.h               Clase abstracta (virtual puro: mostrar)
│   ├── PersonaConcreta.h       Implementa mostrar()
│   ├── Nodo.h                  TEMPLATE<T> con malloc/free + placement new
│   ├── ListaBase.h             TEMPLATE<T> abstracta (4 virtuales puros)
│   ├── ListaSimple.h           TEMPLATE<T> hereda ListaBase<T>
│   ├── ListaDoble.h            TEMPLATE<T> hereda ListaBase<T>
│   ├── ListaCircular.h         TEMPLATE<T> hereda ListaBase<T>
│   └── Menu.h                  Instancia listas con <Persona>
│
└── src/                        <- LOGICA completa
    ├── Persona.cpp             Implementacion Persona
    ├── PersonaConcreta.cpp     Implementacion PersonaConcreta
    ├── Menu.cpp                Implementacion Menu (malloc para listas)
    ├── ListaSimple.tpp         Implementacion template (incluida por .h)
    ├── ListaDoble.tpp          Implementacion template (incluida por .h)
    └── ListaCircular.tpp       Implementacion template (incluida por .h)
```

---

## Por que .tpp y no .cpp para los templates?

Los templates en C++ **no se compilan solos**: el compilador necesita ver
la implementacion completa en el momento en que instancia el template
(p.ej. `ListaSimple<Persona>`).

Por eso cada `.h` de lista incluye su `.tpp` al final:

```cpp
// Al final de ListaSimple.h:
#include "../src/ListaSimple.tpp"
```

Los `.tpp` son archivos de implementacion de templates, visibles en
Visual Studio bajo "Source Files".

---

## Jerarquia de Clases

```
Persona  [ABSTRACTA]  (virtual puro: mostrar())
    └── PersonaConcreta  [CONCRETA]  => implementa mostrar()

ListaBase<T>  [ABSTRACTA TEMPLATE]
    Virtuales puros: insertar / eliminar / mostrar / buscar
    ├── ListaSimple<T>
    ├── ListaDoble<T>    (extra: mostrarInverso())
    └── ListaCircular<T> (extra: recorrerVueltas(n))

Nodo<T>  [TEMPLATE]
    ├── T*       dato    puntero al dato (tipo generico)
    ├── Nodo<T>* sig     puntero al siguiente
    ├── Nodo<T>* ant     puntero al anterior (lista doble)
    ├── static crear()   fabrica con malloc + placement new
    └── static destruir() destructor explicito + free

Menu
    ├── ListaSimple<Persona>*
    ├── ListaDoble<Persona>*
    └── ListaCircular<Persona>*
```

---

## Donde se usa malloc

| Lugar                  | Que se aloja con malloc         |
|------------------------|---------------------------------|
| `Nodo<T>::crear()`     | Cada nodo de las listas         |
| `Nodo<T>::destruir()`  | Libera cada nodo con free       |
| `Nodo<T>::~Nodo()`     | Libera el dato con free         |
| `Menu::Menu()`         | Las 3 listas (placement new)    |
| `Menu::~Menu()`        | Destructor explicito + free     |
| `Menu::pedirPersona()` | Cada PersonaConcreta ingresada  |
| `main()`               | El objeto Menu                  |

---

## Conceptos Aplicados

| Concepto              | Donde                                              |
|-----------------------|----------------------------------------------------|
| Clase abstracta       | `Persona` y `ListaBase<T>`                         |
| Virtual puro `= 0`    | `mostrar()`, `insertar()`, `eliminar()`, `buscar()`|
| Templates `<T>`       | `Nodo<T>`, `ListaBase<T>`, las 3 listas            |
| `malloc` / `free`     | Toda la memoria dinamica del programa              |
| Placement new         | Construir objetos en memoria cruda de malloc       |
| Destructor explicito  | `obj->~Clase()` antes de `free(obj)`               |
| Herencia              | `ListaSimple<T> : ListaBase<T>`                    |
| Polimorfismo virtual  | `Persona*` llama `mostrar()` del tipo real         |
| Punteros referencia   | `const string&`, `T*`, `Nodo<T>*`                 |
| Encapsulamiento       | `private`, `protected`, `public`                   |
| `.h` solo prototipos  | Clases no-template                                 |
| `.tpp` implementacion | Clases template (requerido por el compilador)      |

---

## Como abrir en Visual Studio

1. Doble clic en `ListasProject.sln`
2. Visual Studio carga todos los archivos automaticamente
3. `Ctrl + F5` para compilar y ejecutar
4. Los `.tpp` aparecen en "Source Files" como "None" (no se compilan
   directamente, son incluidos por los `.h`)

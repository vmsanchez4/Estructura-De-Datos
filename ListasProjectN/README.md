# Sistema de Listas Enlazadas - C++ POO

## Arquitectura del Proyecto

```
ListasProject/
│
├── ListasProject.sln          <- Abrir con Visual Studio
├── ListasProject.vcxproj      <- Configuracion del proyecto
├── main.cpp                   <- Punto de entrada
│
├── headers/                   <- Solo PROTOTIPOS (.h)
│   ├── Persona.h              <- Clase abstracta base (virtual puro)
│   ├── PersonaConcreta.h      <- Implementa mostrar()
│   ├── Nodo.h                 <- Nodo con punteros sig/ant
│   ├── ListaBase.h            <- Clase abstracta lista (virtual puro)
│   ├── ListaSimple.h          <- Hereda ListaBase
│   ├── ListaDoble.h           <- Hereda ListaBase
│   ├── ListaCircular.h        <- Hereda ListaBase
│   └── Menu.h                 <- Menu principal
│
└── src/                       <- LOGICA completa (.cpp)
    ├── Persona.cpp
    ├── PersonaConcreta.cpp
    ├── Nodo.cpp
    ├── ListaBase.cpp
    ├── ListaSimple.cpp
    ├── ListaDoble.cpp
    ├── ListaCircular.cpp
    └── Menu.cpp
```

## Jerarquia de Clases

```
Persona  (abstracta - virtual puro: mostrar())
    └── PersonaConcreta  (concreta - implementa mostrar())

ListaBase  (abstracta - virtual puros: insertar/eliminar/mostrar/buscar)
    ├── ListaSimple
    ├── ListaDoble    (extra: mostrarInverso())
    └── ListaCircular (extra: recorrerVueltas(n))

Nodo
    ├── dato  -> Persona*   (puntero a tipo abstracto = polimorfismo)
    ├── sig   -> Nodo*      (puntero al siguiente)
    └── ant   -> Nodo*      (puntero al anterior, para lista doble)

Menu
    ├── ListaSimple*
    ├── ListaDoble*
    └── ListaCircular*
```

## Conceptos aplicados

| Concepto             | Donde se aplica                                      |
|----------------------|------------------------------------------------------|
| Clase abstracta      | `Persona` y `ListaBase` con metodos `= 0`            |
| virtual puro         | `mostrar()`, `insertar()`, `eliminar()`, `buscar()`  |
| Herencia             | `PersonaConcreta : Persona`, `ListaSimple : ListaBase` |
| Polimorfismo         | `Persona*` apunta a `PersonaConcreta`, llamada virtual |
| Punteros             | `Nodo* cabeza`, `Nodo* sig`, `Nodo* ant`             |
| Paso por referencia  | `const string& cedula`, `const string& nombre`       |
| Encapsulamiento      | `private`, `protected`, `public` en cada clase       |
| Destructor virtual   | `virtual ~Persona()`, `virtual ~ListaBase()`         |

## Como abrir en Visual Studio

1. Doble clic en `ListasProject.sln`
2. Visual Studio abre con todos los archivos organizados
3. Presionar `Ctrl+F5` para compilar y ejecutar

## Lista Simple
- Cada nodo apunta solo al siguiente (`sig`)
- Insercion al final, eliminacion por cedula

## Lista Doble
- Cada nodo apunta al siguiente (`sig`) y al anterior (`ant`)
- Permite recorrer en ambas direcciones
- Opcion especial: `mostrarInverso()` (de cola a cabeza)

## Lista Circular
- El ultimo nodo apunta de vuelta al primero (`cola->sig = cabeza`)
- Recorrido con `do-while` usando `aux != cabeza` como condicion
- Opcion especial: `recorrerVueltas(n)` para ver la circularidad

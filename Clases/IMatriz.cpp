#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
//Prototipo
void encerar(float**, int , int );
void ingresar(float**,int , int  );
void imprimir(float**,int , int  );
void procesar(float**,float**,float***, int , int );


//pr
void encerar(float **mat,int fila, int columna){
    int i,j;
    for(i=0;i<fila;i++){
        for(j=0;j<columna;j++){
            mat[i][j]=0;
        }
    }
}

void ingresar(float **mat,int fila, int columna){
    int i,j;
    for(i=0;i<fila;i++){
        for(j=0;j<columna;j++){
            cout<<"ingrese ["<<i<<"]["<<j<<"]:"<<endl;
            //scanf("%f",mat[i][j]);
            scanf("%f",*(*(&mat)+i)+j);
        }
    }
}

void imprimir(float **mat, int fila, int columna) {
    for (int i = 0; i < fila; i++) {
        cout << "[ "; 
        for (int j = 0; j < columna; j++) {
            cout << *(*(mat + i) + j);
            if (j < columna - 1) {
                cout << "\t";
            }
        }
        cout << " ]\n"; 
    }
}

int main(int argc, char** argv){
    int fila=3,col=3;
    //ingresar datos aparte nunca mezclar
    //float mat[3][3];
    //funcion llamada segmentar mandar
    float **mat;
    //reservando
    mat = (float**)malloc(4*sizeof(int*));
    
    for(int i=0;i<fila;i++){
        mat[i]=(float*)malloc(sizeof(float)*col);
    }

    encerar(mat,fila,col);
    //ingresar(mat,fila,col);
    imprimir(mat,fila,col);
    ingresar(mat,fila,col);
    imprimir(mat,fila,col);

    return 0;
}
//poner en clases con getters y setters
//segmentacion sin corchetez
#include <iostream>
using namespace std;

// ============================================================================
// 1. CLASE NODO: Representa el "molde" para cada caja de nuestra lista
// ============================================================================
class Nodo {
private:
    int dato;           // Aquí guardamos el número (el valor real)
    Nodo* siguiente;    // Un puntero que actúa como la "flecha" hacia el próximo nodo

public:
    // Constructor: Se ejecuta automáticamente al hacer un 'new Nodo(valor)'
    Nodo(int valor) {
        dato = valor;          // Guardamos el valor que nos pasan
        siguiente = nullptr;   // Como es nuevo, aún no apunta a nadie (va al final)
    }

    // Le damos permiso exclusivo a la clase ListaSimple para que pueda
    // leer y modificar nuestros atributos privados ('dato' y 'siguiente')
    friend class ListaSimple; 
};

// ============================================================================
// 2. CLASE LISTASIMPLE: La administradora que controla todos los nodos
// ============================================================================
class ListaSimple {
private:
    Nodo* cabeza; // El puntero más importante: nos dice dónde arranca la lista

public:
    // Constructor: Al crear la lista en el main, inicia vacía (cabeza nula)
    ListaSimple() {
        cabeza = nullptr;
    }

    // ------------------------------------------------------------------------
    // MÉTODO: INSERTAR (Agrega un elemento al final de la fila)
    // ------------------------------------------------------------------------
    void insertar(int valor) {
        // 1. Fabricamos el nuevo nodo en la memoria RAM
        Nodo* nuevoNodo = new Nodo(valor); 

        // 2. ¿La lista está vacía?
        if (cabeza == nullptr) {
            cabeza = nuevoNodo; // El nuevo nodo se convierte en el principio de todo
            cout << "Insertado " << valor << " como primer elemento." << endl;
        } 
        // 3. Si ya hay elementos, debemos ir hasta el final para conectarlo
        else {
            Nodo* temp = cabeza; // Usamos 'temp' para caminar sin perder la 'cabeza' original
            
            // Mientras el nodo en el que estoy tenga alguien adelante...
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente; // ...doy un paso hacia adelante
            }
            // Al salir del while, 'temp' es el último nodo. Lo conectamos al nuevo.
            temp->siguiente = nuevoNodo;
            cout << "Insertado " << valor << " al final." << endl;
        }
    }

    // ------------------------------------------------------------------------
    // MÉTODO: IMPRIMIR (Muestra la lista visualmente en consola)
    // ------------------------------------------------------------------------
    void imprimir() {
        // Si no hay cabeza, avisamos y salimos de la función con 'return'
        if (cabeza == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        
        Nodo* temp = cabeza; // Nos paramos en la línea de salida
        cout << "Lista: CABEZA -> ";
        
        // Mientras el nodo actual exista (no sea un hueco vacío)
        while (temp != nullptr) {
            cout << temp->dato << " -> "; // Imprimimos su valor
            temp = temp->siguiente;       // Saltamos a la siguiente caja
        }
        cout << "NULL" << endl; // Indicamos el final visualmente
    }

    // ------------------------------------------------------------------------
    // MÉTODO: BUSCAR (Recorre la lista buscando coincidencias)
    // ------------------------------------------------------------------------
    void buscar(int valor) {
        Nodo* temp = cabeza;
        int posicion = 0; // Llevamos la cuenta de en qué índice vamos
        
        while (temp != nullptr) {
            // ¿El número de esta caja es el que busco?
            if (temp->dato == valor) {
                cout << "Exito: Valor " << valor << " encontrado en indice " << posicion << "." << endl;
                return; // Si lo encuentro, termino la función aquí mismo
            }
            temp = temp->siguiente; // Si no es, avanzo
            posicion++;             // Y sumo 1 al contador
        }
        // Si el while termina y nunca se ejecutó el 'return', es que no existe
        cout << "Fallo: El valor " << valor << " NO se encuentra." << endl;
    }

    // ------------------------------------------------------------------------
    // MÉTODO: MODIFICAR (Busca un valor y lo reemplaza)
    // ------------------------------------------------------------------------
    void modificar(int valorViejo, int valorNuevo) {
        Nodo* temp = cabeza;
        
        while (temp != nullptr) {
            if (temp->dato == valorViejo) {
                temp->dato = valorNuevo; // Sobrescribimos el número viejo con el nuevo
                cout << "Modificado: " << valorViejo << " ahora es " << valorNuevo << "." << endl;
                return; // Trabajo terminado, salimos
            }
            temp = temp->siguiente;
        }
        cout << "Error: No se pudo modificar. El valor " << valorViejo << " no existe." << endl;
    }

    // ------------------------------------------------------------------------
    // MÉTODO: ELIMINAR (Busca un nodo, lo desconecta y borra su memoria)
    // ------------------------------------------------------------------------
    void eliminar(int valor) {
        // Verificación de seguridad
        if (cabeza == nullptr) {
            cout << "Error: La lista esta vacia." << endl;
            return;
        }

        Nodo* temp = cabeza;         // Para ubicar el nodo a borrar
        Nodo* anterior = nullptr;    // Para recordar el nodo que estaba justo antes

        // CASO A: El valor a eliminar resulta ser el primerísimo de la lista
        if (temp != nullptr && temp->dato == valor) {
            cabeza = temp->siguiente; // La cabeza ahora será el segundo elemento
            delete temp;              // Destruimos el primer elemento de la memoria RAM
            cout << "Eliminado: Valor " << valor << " (era la cabeza)." << endl;
            return;
        }

        // CASO B: El valor está en el medio o al final de la lista
        // Caminamos hasta encontrarlo o hasta llegar al final (nullptr)
        while (temp != nullptr && temp->dato != valor) {
            anterior = temp;        // Antes de avanzar, guardamos el nodo actual como 'anterior'
            temp = temp->siguiente; // Damos el paso al frente
        }

        // Si terminamos de caminar y caímos al vacío (nullptr), no lo encontramos
        if (temp == nullptr) {
            cout << "Error: No se pudo eliminar. " << valor << " no existe." << endl;
            return;
        }

        // Si llegamos aquí, 'temp' es el nodo a borrar y 'anterior' es el nodo de atrás.
        // Hacemos que el nodo de atrás "se salte" a 'temp' y apunte al que le sigue a 'temp'.
        anterior->siguiente = temp->siguiente; 
        
        // Ahora que 'temp' quedó aislado y desconectado, lo destruimos
        delete temp; 
        cout << "Eliminado: Valor " << valor << " de la lista." << endl;
    }
};

// ============================================================================
// 3. FUNCIÓN PRINCIPAL (Punto de entrada del programa)
// ============================================================================
int main() {
    // 1. Instanciamos nuestro objeto. Al hacerlo, el constructor pone cabeza = nullptr.
    ListaSimple miLista; 

    cout << "--- INSERTANDO DATOS ---" << endl;
    miLista.insertar(10);
    miLista.insertar(20);
    miLista.insertar(30);
    miLista.imprimir();       

    cout << "\n--- BUSCANDO DATOS ---" << endl;
    miLista.buscar(20);       
    miLista.buscar(50);       

    cout << "\n--- MODIFICANDO DATOS ---" << endl;
    miLista.modificar(20, 99); 
    miLista.imprimir();       

    cout << "\n--- ELIMINANDO DATOS ---" << endl;
    miLista.eliminar(10);     // Borramos la cabeza
    miLista.imprimir();       

    miLista.eliminar(30);     // Borramos el final
    miLista.imprimir();       

    return 0; // Fin del programa
}
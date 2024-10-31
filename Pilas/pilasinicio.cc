#include <iostream>


struct Datos{
    int dato;
};

struct Nodo {
    Datos dato;
    Nodo* siguiente;
};

Nodo* pila = nullptr;

void push(Nodo*& tope, int valor)  //Agrega un elemento al tope de la pila
    {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato.dato = valor;
    nuevo_nodo->siguiente = tope;
    tope = nuevo_nodo;
}
/*
//OTRA FORMA DE AGREGAR ELEMETOS AL TOPE DE LA PILA
void push(Nodo*& tope, int valor) { 
    Nodo* nuevo = new Nodo{valor, pila};
    pila = nuevo;
}*/


int Pop(Nodo*& tope, int valor) {
    if (tope == nullptr) {
        std::cerr << "La pila está vacía." << std::endl;
        return -1; // O lanzar una excepción
    }
    
    Nodo* nodo_eliminar = tope;
    valor = nodo_eliminar->dato.dato;
    tope = tope->siguiente;
    delete nodo_eliminar;
    return valor;
}
/*
//OTRA FORMA DE eliminar el elemento en el tope de la fila
void pop() { 
    if (pila != nullptr) {
        Nodo* temp = pila;
        pila = pila->siguiente;
        delete temp;
    }
}
*/

int top() {
    return (pila != nullptr) ? pila->dato.dato : -1; // Retorna el tope o -1 si está vacía
}

int main() {
   int cantidad, valor;

    // Preguntar cuántos números quiere ingresar el usuario
    std::cout << "¿Cuántos números deseas agregar a la pila? ";
    std::cin >> cantidad;

    // Ingresar los valores y agregarlos a la lista
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Ingrese el número " << i + 1 << ": ";
        std::cin >> valor;
        push(pila, valor);
    }

     
    std::cout << "El elemento al tope de la pila es: " << top() << std::endl;
    Pop(pila, valor);
    std::cout << "Nuevo tope tras eliminar el ultimo elemento de la pila: " << top() << std::endl;

    return 0;
}

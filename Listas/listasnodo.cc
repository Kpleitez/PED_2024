#include <iostream>

struct Datos
{
    int elemento;
};

struct Nodo {
    Datos dato;       // El valor que almacena el nodo
    Nodo* siguiente; // El puntero al próximo nodo
};


Nodo* lista = nullptr; // Al inicio, la lista está vacía

bool estaVacia(Nodo* lista) { //funcion para verificar si la lista esta vacia
    return lista == nullptr;
}


// Función para insertar un nodo al inicio de la lista
void insertarInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo;    // Crear un nuevo nodo en memoria dinámica
    nuevoNodo->dato.elemento = valor;       // Asignar el valor al nodo
    nuevoNodo->siguiente = cabeza; // Apuntar al nodo actual de la cabeza
    cabeza = nuevoNodo;            // Actualizar la cabeza al nuevo nodo
}

// Función para imprimir todos los elementos de la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* temporal = cabeza;  // Usamos un puntero temporal para recorrer la lista
    while (temporal != nullptr) {
        std::cout << temporal->dato.elemento << " -> ";
        temporal = temporal->siguiente; // Avanzar al siguiente nodo
    }
    std::cout << "fin de la lista" << std::endl;
}

int main() {
    int cantidad, valor;

    // Preguntar cuántos números quiere ingresar el usuario
    std::cout << "¿Cuántos números deseas agregar a la lista? ";
    std::cin >> cantidad;

    // Ingresar los valores y agregarlos a la lista
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Ingrese el número " << i + 1 << ": ";
        std::cin >> valor;
        insertarInicio(lista, valor);
    }

    // Imprimir la lista resultante
    std::cout << "Elementos en la lista: ";
    imprimirLista(lista);

    return 0;
}
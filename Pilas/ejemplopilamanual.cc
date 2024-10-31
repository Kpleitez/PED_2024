#include <iostream>

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para apilar (Push)
void Push(Nodo*& cima, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = cima;
    cima = nuevo_nodo;
}

// Función para desapilar (Pop)
int Pop(Nodo*& cima) {
    if (cima == nullptr) {
        std::cerr << "La pila está vacía." << std::endl;
        return -1; // Indicador de error
    }

    Nodo* nodo_eliminar = cima;
    int valor = nodo_eliminar->dato;
    cima = cima->siguiente;
    delete nodo_eliminar;
    return valor;
}

// Función para obtener la cima (Peek)
int Peek(Nodo* cima) {
    if (cima == nullptr) {
        std::cerr << "La pila está vacía." << std::endl;
        return -1; // Indicador de error
    }
    return cima->dato;
}

// Función para verificar si la pila está vacía
bool IsEmpty(Nodo* cima) {
    return cima == nullptr;
}

// Función para mostrar todos los elementos de la pila
void MostrarPila(Nodo* cima) {
    if (IsEmpty(cima)) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }
    Nodo* actual = cima;
    std::cout << "Elementos en la pila: ";
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

// Función principal (main)
int main() {
    Nodo* cima = nullptr;
    int valor;

    // Solicitando al usuario que ingrese valores para apilar
    std::cout << "Ingrese los valores para apilar (0 para terminar): " << std::endl;
    
    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        Push(cima, valor);
    }

    // Mostrando la pila
    MostrarPila(cima);

    // Operaciones adicionales en la pila
    std::cout << "Cima de la pila: " << Peek(cima) << std::endl;
    
    std::cout << "Desapilando el elemento: " << Pop(cima) << std::endl;
    MostrarPila(cima);
    
    // Desapilar todos los elementos
    while (!IsEmpty(cima)) {
        std::cout << "Desapilando el elemento: " << Pop(cima) << std::endl;
    }
    
    return 0;
}
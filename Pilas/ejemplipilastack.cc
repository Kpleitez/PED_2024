#include <iostream>
#include <stack>

// Función para mostrar todos los elementos de la pila sin modificarla
void MostrarPila(std::stack<int> pila) {
    if (pila.empty()) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }

    std::cout << "Elementos en la pila: ";
    while (!pila.empty()) {
        std::cout << pila.top() << " ";  // Muestra el elemento en la cima
        pila.pop();                      // Elimina el elemento de la cima
    }
    std::cout << std::endl;
}

// Función principal (main)
int main() {
    std::stack<int> pila;
    int valor;

    // Solicitando al usuario que ingrese valores para apilar
    std::cout << "Ingrese los valores para apilar (0 para terminar): " << std::endl;
    
    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        pila.push(valor);  // Apilando el valor
    }

    // Mostrando la pila
    MostrarPila(pila);

    // Operaciones adicionales en la pila
    if (!pila.empty()) {
        std::cout << "Cima de la pila: " << pila.top() << std::endl;
        pila.pop();
        std::cout << "Desapilando un elemento..." << std::endl;
    } else {
        std::cout << "La pila está vacía, no hay nada que desapilar." << std::endl;
    }

    // Mostrar pila después de desapilar
    MostrarPila(pila);

    return 0;
}
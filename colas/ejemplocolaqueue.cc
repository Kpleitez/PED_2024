#include <iostream>
#include <queue>

// Función para mostrar todos los elementos de la cola sin modificarla
void MostrarCola(std::queue<int> cola) {
    if (cola.empty()) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }

    std::cout << "Elementos en la cola: ";
    while (!cola.empty()) {
        std::cout << cola.front() << " ";  // Mostrar el elemento al frente
        cola.pop();                        // Eliminar el elemento del frente
    }
    std::cout << std::endl;
}

// Función principal (main)
int main() {
    std::queue<int> cola;
    int valor;

    // Solicitando al usuario que ingrese valores para encolar
    std::cout << "Ingrese los valores para encolar (0 para terminar): " << std::endl;
    
    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        cola.push(valor);  // Encolar el valor
        std::cout << "Encolando: " << valor << std::endl;
    }

    // Mostrando la cola
    MostrarCola(cola);

    // Operaciones adicionales en la cola
    if (!cola.empty()) {
        std::cout << "Valor al frente de la cola: " << cola.front() << std::endl; // Ver el frente
        cola.pop();  // Desencolar el frente
        std::cout << "Desencolando un elemento..." << std::endl;
    } else {
        std::cout << "La cola está vacía, no hay nada que desencolar." << std::endl;
    }

    // Mostrar cola después de desencolar un elemento
    MostrarCola(cola);

    return 0;
}
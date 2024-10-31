#include <iostream>

// Estructura del Nodo
struct Nodo {
    int dato;           // Valor almacenado
    Nodo* siguiente;    // Puntero al siguiente nodo
};

// Estructura de la Cola
struct Cola {
    Nodo* frente;       // Puntero al frente de la cola
    Nodo* final;        // Puntero al final de la cola
};

// Función para inicializar una cola vacía
void InicializarCola(Cola*& cola) {
    cola = new Cola();
    cola->frente = nullptr;
    cola->final = nullptr;
}

// Función para verificar si la cola está vacía
bool IsEmpty(Cola* cola) {
    return (cola->frente == nullptr);
}

// Función para encolar (agregar un elemento al final)
void Enqueue(Cola*& cola, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = nullptr;

    if (IsEmpty(cola)) {
        cola->frente = nuevo_nodo;  // Si la cola está vacía, el nuevo nodo es el frente
    } else {
        cola->final->siguiente = nuevo_nodo;  // Si no está vacía, el nodo final apunta al nuevo nodo
    }

    cola->final = nuevo_nodo;  // El nuevo nodo es ahora el final de la cola
    std::cout << "Encolando: " << valor << std::endl;
}

// Función para desencolar (eliminar el elemento del frente)
int Dequeue(Cola*& cola) {
    if (IsEmpty(cola)) {
        std::cerr << "La cola está vacía." << std::endl;
        return -1;  // Indicador de error
    }

    Nodo* nodo_eliminar = cola->frente;
    int valor = nodo_eliminar->dato;
    cola->frente = cola->frente->siguiente;

    if (cola->frente == nullptr) {
        cola->final = nullptr;  // Si la cola queda vacía, final también es nullptr
    }

    delete nodo_eliminar;
    return valor;
}

// Función para obtener el valor del frente de la cola sin eliminarlo
int Front(Cola* cola) {
    if (IsEmpty(cola)) {
        std::cerr << "La cola está vacía." << std::endl;
        return -1;  // Indicador de error
    }

    return cola->frente->dato;
}

// Función para mostrar todos los elementos de la cola
void MostrarCola(Cola* cola) {
    if (IsEmpty(cola)) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }

    Nodo* actual = cola->frente;
    std::cout << "Elementos en la cola: ";
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

// Función principal (main)
int main() {
    Cola* cola = nullptr;
    InicializarCola(cola);

    // Solicitando al usuario que ingrese valores para encolar
    int valor;
    std::cout << "Ingrese los valores para encolar (0 para terminar): " << std::endl;
    
    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        Enqueue(cola, valor);
    }

    // Mostrando la cola
    MostrarCola(cola);

    // Obtener el valor del frente sin desencolar
    if (!IsEmpty(cola)) {
        std::cout << "Valor al frente de la cola: " << Front(cola) << std::endl;
    }

    // Desencolando elementos
    std::cout << "Desencolando el primer elemento: " << Dequeue(cola) << std::endl;
    MostrarCola(cola);

    // Desencolando todos los elementos
    while (!IsEmpty(cola)) {
        std::cout << "Desencolando: " << Dequeue(cola) << std::endl;
    }

    // Mostrando la cola después de desencolar todos los elementos
    MostrarCola(cola);

    return 0;
}
#include <iostream>


struct Datos
{
    int elemento;
};

struct Nodo
{
    Datos datos;
    Nodo *siguiente;
};

Nodo *lista = nullptr;


void insertarNodo(int n)
{
    Nodo *nuevoNodo = new Nodo;
   
   
    Nodo *temporal = lista;
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = nullptr;
   
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
}

int NumerosPares(int contador = 0)
{
  struct Nodo *temporal = lista;

  while (temporal != nullptr)
  {
    if (temporal->datos.elemento % 2 == 0)
    {
      contador ++;
    }
    temporal = temporal->siguiente;
  }
  std::cout << "Existen " << contador << " pares \n";
}

int NumerosImpares(int contador = 0)
{
  struct Nodo *temporal = lista;

  while (temporal != nullptr)
  {
    if (temporal->datos.elemento % 2 != 0)
    {
      contador ++;
    }
    temporal = temporal->siguiente;
  }
  std::cout << "Existen " << contador << " impares";
}



int main(int argc, char *argv[]) 
{
    int cantidad, valor;

    std::cout << "Ingrese una cantidad de numeros: ";
    std::cin >> cantidad;

    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Ingrese el número " << i + 1 << ": ";
        std::cin >> valor;
        insertarNodo(valor);  
    }
    std::cout << '\n';
    std::cout << "A continuacion se muestra cuantos numeros son pares e impares: \n";
    NumerosPares();
    NumerosImpares();
    return 0;
}
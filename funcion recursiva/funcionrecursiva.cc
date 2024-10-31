#include "iostream"

int Factorial(int);
int Suma(int);
void Conteo(int);
int Fibonacci(int);

int main()
{

    // std::cout << Factorial(5) ;
    // std::cout << Conteo(3);
    std::cout << Fibonacci(8);
    return 0;
}

int Factorial(int x)
{

    // caso base
    if (x == 1)
    {
        return x;
    }
    else
    {
        return x * Factorial(x - 1);
    }
}

// Funcion recursiva suma de numeros
int Suma(int y)
{
    if (y == 1)
    {
        return y;
    }
    else
    {
        return y * Suma(y - 1);
    }
}

void Conteo(int c)
{
    // caso base
    if (c < 1)
    {
        return;
    }
    else
    {
        std::cout << c;
        Conteo(c - 1);
    }
}

int Fibonacci(int n)
{
    // caso base
    if (n < 2)
    {
        return n;
    }

    else
    {
        return Fibonacci(n - 2) + Fibonacci(n - 1);
    }
}
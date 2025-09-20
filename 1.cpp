#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Contar pares
int contarPares(int numeros[], int n) {
    int pares = 0;
    for (int i = 0; i < n; i++) {
        if (numeros[i] % 2 == 0)
            pares++;
    }
    return pares;
}

// Contar impares
int contarImpares(int numeros[], int n) {
    int impares = 0;
    for (int i = 0; i < n; i++) {
        if (numeros[i] % 2 != 0)
            impares++;
    }
    return impares;
}

// Encontrar segundo mayor
int segundoMayor(int numeros[], int n) {
    int mayor = -1, segMayor = -1;
    for (int i = 0; i < n; i++) {
        if (numeros[i] > mayor) {
            segMayor = mayor;
            mayor = numeros[i];
        } else if (numeros[i] > segMayor && numeros[i] != mayor) {
            segMayor = numeros[i];
        }
    }
    return segMayor;
}

// Encontrar segundo menor
int segundoMenor(int numeros[], int n) {
    int menor = 101, segMenor = 101;
    for (int i = 0; i < n; i++) {
        if (numeros[i] < menor) {
            segMenor = menor;
            menor = numeros[i];
        } else if (numeros[i] < segMenor && numeros[i] != menor) {
            segMenor = numeros[i];
        }
    }
    return segMenor;
}

// Invertir arreglo en el mismo
void invertir(int numeros[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = numeros[i];
        numeros[i] = numeros[n - 1 - i];
        numeros[n - 1 - i] = temp;
    }
}

int main() {
    const int N = 20;
    int numeros[N];

    srand(time(0));

    // Generar números aleatorios
    for (int i = 0; i < N; i++) {
        numeros[i] = rand() % 100 + 1;
    }

    // Mostrar números
    cout << "Numeros aleatorios generados:" << endl;
    for (int i = 0; i < N; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Contar pares e impares
    cout << "Cantidad de pares: " << contarPares(numeros, N) << endl;
    cout << "Cantidad de impares: " << contarImpares(numeros, N) << endl;

    // Segundo mayor y segundo menor
    cout << "Segundo mayor: " << segundoMayor(numeros, N) << endl;
    cout << "Segundo menor: " << segundoMenor(numeros, N) << endl;

    // Invertir el arreglo
    invertir(numeros, N);
    cout << "Arreglo invertido:" << endl;
    for (int i = 0; i < N; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 100;

// Llenar la matriz con valores aleatorios
void llenarMatrix(int filas, int columnas, int matrix[MAX][MAX]) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matrix[i][j] = rand() % 100 + 1;
}

// Mostrar la matriz
void mostrarMatrix(int filas, int columnas, int matrix[MAX][MAX]) {
    cout << "La matriz es:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

// Sumar cada fila
void sumaFilas(int filas, int columnas, int matrix[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += matrix[i][j];
        }
        cout << "Suma de la fila " << i + 1 << ": " << suma << endl;
    }
}

void filaMayor(int filas, int columnas, int matrix[MAX][MAX]) {
    int fila = 0;
    int mayor = matrix[0][0];
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += matrix[i][j];
        }
        if (suma > mayor) {
            mayor = suma;
            fila = i;
        }
    }
    cout << "La fila con mayor suma es la fila " << fila + 1 << " con una suma de " << mayor << endl;
}

int matrixTranspuesta(int filas, int columnas, int matrix[MAX][MAX]){
    cout << "La matriz transpuesta es:" << endl;
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++)
            cout << matrix[j][i] << "\t";
        cout << endl;
    }
}
int main() {
    srand(time(0));
    int N = 5;
    int matrix[MAX][MAX];

    llenarMatrix(N, N, matrix);
    mostrarMatrix(N, N, matrix);
    cout << endl;
    sumaFilas(N, N, matrix);
    filaMayor(N, N, matrix);
    matrixTranspuesta(N, N, matrix);

    return 0;
}

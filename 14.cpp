/*3. Matriz dinámica con operaciones
    - Crea una matriz cuadrada dinámica de n x n.
    - Implementa funciones que permitan:
    - Llenarla con valores aleatorios.
    - Calcular la suma de la diagonal principal y secundaria.
    - Transponer la matriz.
    - Liberar memoria.*/

#include <iostream>
#include <vector>
using namespace std;

void llenarMatriz(int n, vector<vector<int>> &matriz)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    cout << "La matriz es:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << "\t";
        cout << endl;
    }
}

void calcularSuma(int n, vector<vector<int>> &matriz)
{

    int total1 = 0;
    int total2=0;

    for (int i = 0; i < n; i++)
    {
        total1 = total1 + matriz[i][i];
        total2 = total2 + matriz[i][n-1-i] ;
    }

    cout << "Suma diagonal principal: " << total1 << endl;
    cout << "Suma diagonal secundaria: " << total2 << endl;
}

void Transpuesta(int n, vector<vector<int>> &matriz)
{
    cout << "La matriz transpuesta es:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matriz[j][i] << "\t";
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;

    // Crear matriz n x n inicializada en 0
    vector<vector<int>> matriz(n, vector<int>(n));
    llenarMatriz(n, matriz);
    calcularSuma(n, matriz);
    Transpuesta(n, matriz);



    return 0;
}

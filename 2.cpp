#include <iostream>
#include <vector>
using namespace std;

void llenarArreglos(vector<int> v1, vector<int> v2, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el numero " << i + 1 << " del vector 1: ";
        cin >> v1[i];
    }

    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el numero " << i + 1 << " del vector 2: ";
        cin >> v2[i];
    }

    cout << "Arreglo 1 es: ";
    for (int i = 0; i < N; i++)
        cout << v1[i] << " ";
    cout << endl;

    cout << "Arreglo 2 es: ";
    for (int i = 0; i < N; i++)
        cout << v2[i] << " ";
    cout << endl;
}

// Suma elemento a elemento (vector resultado)
void sumaArreglo(vector<int> v1, vector<int> v2, int N)
{
    vector<int> suma(N);
    for (int i = 0; i < N; i++)
        suma[i] = v1[i] + v2[i];

    cout << "Suma elemento a elemento: ";
    for (int i = 0; i < N; i++)
        cout << suma[i] << " ";
    cout << endl;
}

// Producto escalar (un número)
void productoEscalar(vector<int> v1, vector<int> v2, int N)
{
    int producto = 0;
    for (int i = 0; i < N; i++)
        producto += v1[i] * v2[i];

    cout << "Producto escalar: " << producto << endl;
}

int main()
{
    int N;
    cout << "Ingrese la cantidad de numeros en los arreglos: ";
    cin >> N;

    vector<int> v1(N), v2(N); // <-- importante: reservar memoria ANTES

    llenarArreglos(v1, v2, N);
    sumaArreglo(v1, v2, N);
    productoEscalar(v1, v2, N);

    return 0;
}

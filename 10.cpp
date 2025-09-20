/*10. Array dinámico
    - Solicita al usuario cuántos números quiere ingresar.
    - Reserva memoria dinámica (new) para un arreglo de ese tamaño.
    - Pide al usuario los valores y calcula: suma, promedio y número mayor.
    - Libera la memoria (delete[]).*/

#include <iostream>
using namespace std;

int main(){
    int suma = 0;
    int N, *Array;
    cout << "Digite cuantos numeros desea ingresar: " <<endl;
    cin >> N;

    Array = new int [N];

    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el numero " << i+1 <<endl;
        cin >> Array[i];
    }

    for (int i = 0; i < N; i++)
    {
        suma = suma + Array[i];
    }
    cout << "La suma es: " << suma <<endl;

    int promedio;
    promedio = suma/N;
    cout << "El promedio es: " << promedio <<endl;

    int mayor = 0;
    for (int i = 0; i < N; i++)
    {
        if (Array[i]>mayor)
        {
            mayor = Array[i];
        }
        
    }
    cout << "El mayor es: " << mayor <<endl;

    delete[] Array;

    


    

    




}


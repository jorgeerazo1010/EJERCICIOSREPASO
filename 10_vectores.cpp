/*10. Array dinámico
    - Solicita al usuario cuántos números quiere ingresar.
    - Reserva memoria dinámica (new) para un arreglo de ese tamaño.
    - Pide al usuario los valores y calcula: suma, promedio y número mayor.
    - Libera la memoria (delete[]).*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int suma = 0, N;
    cout << "Digite cuantos numeros desea ingresar: " <<endl;
    cin >> N;

    vector <int> numeros(N);
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el numero " << i+1 <<endl;
        cin >> numeros[i];
    }

    for (int i = 0; i < N; i++)
    {
        suma = suma + numeros[i];
    }
    cout << "La suma es: " << suma <<endl;

    int promedio;
    promedio = suma/N;
    cout << "El promedio es: " << promedio <<endl;

    int mayor = 0;
    for (int i = 0; i < N; i++)
    {
        if (numeros[i]>mayor)
        {
            mayor = numeros[i];
        }
        
    }
    cout << "El mayor es: " << mayor <<endl;

   return 0;

    


    

    




}


/*7. Arreglo estático
    - Declara un arreglo estático de enteros de tamaño 10.
    - Llénalo con valores aleatorios entre 1 y 100.
    - Implementa funciones para:
        - Encontrar el máximo.
        - Encontrar el mínimo.
        - Calcular el promedio.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void findmax(int array[], int N){
   int  max=0;
    for (int i = 0; i < N; i++)
    {
       if (array[i]>max)
       {
        max=array[i];
       }
       
    }
    cout << "El numero maximo del arreglo es: " << max <<endl;
    
}


void findmin(int array[], int N){
   int  min=10000;
    for (int i = 0; i < N; i++)
    {
       if (array[i]<min)
       {
        min=array[i];
       }
       
    }
    cout << "El numero minimo del arreglo es: " << min <<endl;
    
}
void promedio(int array[],int N){
   int total=0;
    for (int i = 0; i < N; i++)
    {
        total= array[i]+total;
    }

   float promedio;
    promedio = total/10;
    cout << "El promedio es: " << promedio <<endl;
}

int main()
{
   int  N = 10;
    int array[N];
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 100 + 1;
        cout << array[i] <<"  ";
    }
    cout <<endl;
    findmax(array, N);
    findmin(array, N);
    promedio(array, N);

    

}
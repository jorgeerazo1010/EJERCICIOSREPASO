/*11. Struct + array dinámico
    - Crea un struct Producto con: código, nombre y precio.
    - Pregunta al usuario cuántos productos desea registrar.
    - Reserva memoria dinámica para ese número de productos.
    - Implementa funciones para:
        - Leer los productos.
        - Mostrar todos los productos.
        - Encontrar el más caro.*/

#include <iostream>
#include <vector>
using namespace std;

struct Producto
{
    int codigo;
    string nombre;
    int precio;
};

void Leer( vector<Producto> &productos, int N)
{
 
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el codigo del producto "<< i + 1<< " :"<<endl;
        cin >> productos[i].codigo;

        cin.ignore(); // limpiar buffer antes de getline
        cout << "Ingrese el nombre del producto " << i + 1 << " :";
        getline(cin, productos[i].nombre);

        cout << "Ingrese el precio del producto "<< i + 1<< " :" <<endl;
        cin >> productos[i].precio;
    }
}

void Mostrar( vector<Producto> &productos, int N)
{
    
    for (int i = 0; i < N; i++)
    {
        cout << "codigo del producto" << i + 1 << ": " << productos[i].codigo << endl;
        cout << "nombre del producto " << i + 1 << ": " << productos[i].nombre << endl;
        cout << "precio del producto " << i + 1 << ": " << productos[i].precio << endl;
    }
}
void Encontrar(vector<Producto> &productos, int N)
{
    
    int mayor = 0;
    for (int i = 0; i < N; i++)
    {
        if (productos[i].precio > mayor)
        {
            mayor = productos[i].precio;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (mayor == productos[i].precio)
        {
            cout << "El mas caro es: " << productos[i].nombre << endl;
        }
    }
}

int main()
{
    int N;
    cout << "Digite cuantos productos desea ingresar: ";
    cin >> N;
    vector <Producto> productos(N);
    Leer(productos,N);
    Mostrar(productos, N);
    Encontrar(productos, N);

    return 0;
}

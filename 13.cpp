/*1. Sistema de gestión de inventario
Crea un programa que maneje productos con un struct Producto que tenga:
id, nombre, precio, cantidad.
El programa debe:
    - Usar un arreglo dinámico de productos.
    - Permitir:
        - Agregar productos.
        - Buscar por id.
        - Actualizar la cantidad.
        - Calcular el valor total del inventario.*/
#include <iostream>
#include <vector>
using namespace std;

struct Producto
{
    int id;
    string nombre;
    int precio;
    int cantidad;
};

void agregarProductos(vector<Producto> &productos)
{
    Producto p;
    cout << "Ingrese el ID del producto " << " :" << endl;
    cin >> p.id;

    cin.ignore(); // limpiar buffer antes de getline
    cout << "Ingrese el nombre del producto " << " :";
    getline(cin, p.nombre);

    cout << "Ingrese el precio del producto " << " :" << endl;
    cin >> p.precio;

    cout << "Ingrese la cantidad del producto " << " :" << endl;
    cin >> p.cantidad;

    productos.push_back(p); // lo añadimos al vector
    cout << "Producto agregado con exito!\n";
}

void buscarID(vector<Producto> &productos)
{
    Producto p;
    int id;

    

    cout << "Ingrese el numero de id a buscar: " << endl;
    cin >> id;

    for (int i = 0; i < productos.size(); i++)
    {
        if (id = productos[i].id)
        {
            cout << "ID del producto " << productos[i].id << endl;
            cout << "Nombre del producto " << productos[i].nombre << endl;
            cout << "Precio del producto " << productos[i].precio << endl;
            cout << "Cantidad del producto " << productos[i].cantidad << endl;
        }
    }
}

void ActualizarCantidad(vector<Producto> &productos)
{
    Producto p;
    int id;
    int nuevac;

   

    cout << "Ingrese el numero de id a buscar: " << endl;
    cin >> id;

    for (int i = 0; i < productos.size(); i++)
    {
        if (id = productos[i].id)
        {
            cout << "Ingrese la nueva cantidad: " << endl;
            cin >> productos[i].cantidad;
        }
    }
}

void valorTotal(vector<Producto> &productos)
{
    int total = 0;
    Producto p;

    for (int i = 0; i < productos.size(); i++)
    {
        total = total + productos[i].precio * productos[i].cantidad;
    }

    cout << "El precio total del inventario es: " << total << endl;
}

int main()
{
    int N;
    int opcion;
    vector<Producto> productos(N);
    do
    {
        cout << "MENU: " << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Buscar por ID" << endl;
        cout << "3. Actualizar cantidad" << endl;
        cout << "4. Calcular el valor total" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarProductos(productos);
            break;
        case 2:
            buscarID(productos);
            break;
        case 3:
            ActualizarCantidad(productos);
            break;
        case 4:
            valorTotal(productos);
            break;

        default:
            break;
        }
    } while (opcion != 5);

}
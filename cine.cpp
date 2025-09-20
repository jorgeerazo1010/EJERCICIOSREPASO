#include <iostream>
#include <string>
using namespace std;

struct Sala
{

    int numero;
    string pelicula;
    int butacas;
};

const int n = 5;

struct Cine
{
    string nombre;
    string direccion;
    Sala salas[n];
};

Cine solicitarDatos()
{
    Cine c;
    cout << "Ingrese el nombre del cine: " << endl;
    cin >> c.nombre;
    cout << "Ingrese la direccion del cine: " << endl;
    getline(cin >> ws, c.direccion);

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el numero de sala del cine: " << endl;
        cin >> c.salas[i].numero;
        cout << "Ingrese la pelicula: " << endl;
        getline(cin >> ws, c.salas[i].pelicula);
        cout << "Ingrese el numero de butacas de la sala: " << endl;
        cin >> c.salas[i].butacas;
    }
    return c;
}

void mostrarInfo(const Cine &c)
{
    cout << "Nombre del cine: " << c.nombre << endl;
    cout << "Direccion del cine: " << c.direccion << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Numero de sala del cine: " << c.salas[i].numero << endl;
        cout << "Pelicula: " << c.salas[i].pelicula << endl;
        cout << "Butacas de la sala: " << c.salas[i].butacas << endl;
    }
}

void calcularTotal(const Cine &c)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += c.salas[i].butacas;
    }
    cout << "El total de butacas es: " << total;
}

void buscarPelicula(const Cine &c)
{
    string pelicula;
    cout << "Ingrese la peliculas buscar: " << endl;
    cin >> pelicula;

    for (int i = 0; i < n; i++)
    {
        if (pelicula == c.salas[i].pelicula)
        {
            cout << "ENCONTRADO" <<endl;
            cout << "Numero de sala del cine: " << c.salas[i].numero << endl;
            cout << "Pelicula: " << c.salas[i].pelicula << endl;
            cout << "Butacas de la sala: " << c.salas[i].butacas << endl;
        }
    }
}

int main()
{
    Cine c;
    int opcion;
    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Solicitar datos\n";
        cout << "2. Imprimir informacion\n";
        cout << "3. Calcular total de butacas\n";
        cout << "4. Buscar pelicula\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            c = solicitarDatos();
            break;
            case 2:
            mostrarInfo(c);
            break;
            case 3:
            calcularTotal(c);
            break;
            case 4:
            buscarPelicula(c);
            break;
        
        default:
            break;
        }
    } while (opcion != 5);
    
}
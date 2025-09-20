/*2. Agenda de contactos (uso de punteros a structs)
    - Crea un struct Contacto con: nombre, teléfono, correo.
    - Usa un puntero a puntero (Contacto**) para manejar una lista dinámica de contactos.
    - Implementa funciones para:
    - Agregar un nuevo contacto.
    - Mostrar todos los contactos.
    - Buscar un contacto por nombre.
    - Eliminar un contacto (liberar memoria y reacomodar la lista).*/

#include <iostream>
#include <vector>
using namespace std;

struct Contacto
{

    string nombre;
    int telefono;
    string correo;
};

void NuevoContacto(vector<Contacto> &contactos)
{
    Contacto c;
    cout << "Ingrese el nombre del nuevo contacto:" << endl;
    cin >> c.nombre;
    cout << "Ingrese el telefono del nuevo contacto:" << endl;
    cin >> c.telefono;
    cout << "Ingrese el correo del nuevo contacto:" << endl;
    cin >> c.correo;
    contactos.push_back(c);
}

void mostrarContactos(vector<Contacto> &contactos)
{
    Contacto c;
    int longitud;
    longitud = contactos.size();

    for (int i = 0; i < longitud; i++)
    {
        cout << "Nombre del contacto " << i + 1 << " " << contactos[i].nombre << endl;
        cout << "Telefono del contacto " << i + 1 << " " << contactos[i].telefono << endl;
        cout << "Correo del contacto " << i + 1 << " " << contactos[i].correo << endl;
    }
}

void buscarContacto(vector<Contacto> &contactos)
{
    Contacto c;
    string nombre;
    cout << "Ingrese el nombre del contacto a buscar:" << endl;
    cin >> nombre;

    int longitud;
    longitud = contactos.size();

    for (int i = 0; i < longitud; i++)
    {
        if (nombre == contactos[i].nombre)
        {
            cout << "Nombre del contacto " << " " << contactos[i].nombre << endl;
            cout << "Telefono del contacto " << " " << contactos[i].telefono << endl;
            cout << "Correo del contacto " << " " << contactos[i].correo << endl;
        }
    }
}

void deleteContacto(vector<Contacto> &contactos)
{

    Contacto c;
    string nombre;
    cout << "Ingrese el nombre del contacto a eliminar:" << endl;
    cin >> nombre;

    int longitud;
    longitud = contactos.size();

    for (int i = 0; i < longitud; i++)
    {
        if (nombre == contactos[i].nombre)
        {
            contactos.erase(contactos.begin() + i);
        }
    }
}

int main()
{
    int opcion;
    vector<Contacto> contactos;
    do
    {
        cout << "\nMENU: " << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Mostrar todos los contactos" << endl;
        cout << "3. Buscar contacto por su nombre" << endl;
        cout << "4. Eliminar contacto" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            NuevoContacto(contactos);
            break;
        case 2:
            mostrarContactos(contactos); // Imprime de mayor a menor
            break;
        case 3:
            buscarContacto(contactos);
            break;
        case 4:
            deleteContacto(contactos);
             cout << "Nueva lista: " << endl;
            mostrarContactos(contactos);
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Facultad {
    int numero_facultad;
    string carrera_principal;
    int numero_estudiantes;
};

const int cantidad_facultades = 5;

struct Universidad {
    string nombre;
    string direccion;
    Facultad facultades[cantidad_facultades];
};

// Función para solicitar datos de la universidad y sus facultades, uwu, xd,x
Universidad solicitar_datos() {
    Universidad u;
    cout << "Ingrese el nombre de la universidad: ";
    getline(cin, u.nombre);

    cout << "Ingrese la direccion de la universidad: ";
    getline(cin, u.direccion);

    for (int i = 0; i < cantidad_facultades; i++) {
        cout << "\nFacultad " << i + 1 << ":" << endl;

        cout << "Ingrese el numero de la facultad: ";
        cin >> u.facultades[i].numero_facultad;
        cin.ignore(); // limpiar buffer

        cout << "Ingrese la carrera principal de la facultad: ";
        getline(cin, u.facultades[i].carrera_principal);

        cout << "Ingrese el numero de estudiantes de la facultad: ";
        cin >> u.facultades[i].numero_estudiantes;
        cin.ignore(); // limpiar buffer para la siguiente iteración
    }

    return u;
}

// Función para imprimir información de la universidad
void imprimir_info(const Universidad &u) {
    cout << "\n--- Información de la Universidad ---\n";
    cout << "Nombre: " << u.nombre << endl;
    cout << "Direccion: " << u.direccion << endl;

    for (int i = 0; i < cantidad_facultades; i++) {
        cout << "\nFacultad " << i + 1 << ":" << endl;
        cout << "Numero: " << u.facultades[i].numero_facultad << endl;
        cout << "Carrera principal: " << u.facultades[i].carrera_principal << endl;
        cout << "Estudiantes: " << u.facultades[i].numero_estudiantes << endl;
    }
}

// Función para calcular total de estudiantes
int total_estudiantes(const Universidad &u) {
    int total = 0;
    for (int i = 0; i < cantidad_facultades; i++) {
        total += u.facultades[i].numero_estudiantes;
    }
    return total;
}

// Función para buscar carrera
bool buscar_carrera(const Universidad &u, const string &carrera) {
    for (int i = 0; i < cantidad_facultades; i++) {
        if (u.facultades[i].carrera_principal == carrera) {
            return true;
        }
    }
    return false;
}

int main() {
    Universidad u;
    bool datos_ingresados = false;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Solicitar datos\n";
        cout << "2. Imprimir informacion\n";
        cout << "3. Calcular total de estudiantes\n";
        cout << "4. Buscar carrera\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer

        switch(opcion) {
            case 1:
                u = solicitar_datos();
                datos_ingresados = true;
                break;
            case 2:
                if(datos_ingresados)
                    imprimir_info(u);
                else
                    cout << "Primero debe ingresar los datos.\n";
                break;
            case 3:
                if(datos_ingresados)
                    cout << "Total de estudiantes: " << total_estudiantes(u) << endl;
                else
                    cout << "Primero debe ingresar los datos.\n";
                break;
            case 4:
                if(datos_ingresados) {
                    string carrera;
                    cout << "Ingrese el nombre de la carrera a buscar: ";
                    getline(cin, carrera);
                    if(buscar_carrera(u, carrera))
                        cout << "La carrera '" << carrera << "' existe en alguna facultad.\n";
                    else
                        cout << "La carrera '" << carrera << "' NO existe en la universidad.\n";
                } else {
                    cout << "Primero debe ingresar los datos.\n";
                }
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while(opcion != 5);

    return 0;
}

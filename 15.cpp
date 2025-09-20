/*4. Registro de estudiantes con ordenamiento
    - Crea un struct Estudiante con: carnet, nombre, promedio.
    - Usa un arreglo dinámico de estudiantes.
    - Implementa funciones para:
    - Ingresar estudiantes.
    - Ordenarlos por promedio (usando punteros y algoritmo burbuja o selección).
    - Mostrar el estudiante con mejor y peor promedio.*/

#include <iostream>
#include <vector>
using namespace std;

struct Estudiante {
    int carnet;
    string nombre;
    float promedio;
};

// Función para ingresar estudiantes
void Ingresar(vector<Estudiante> &estudiantes) {
    Estudiante p;
    cout << "Ingrese el carnet del estudiante: ";
    cin >> p.carnet;
    cin.ignore(); // limpiar buffer antes de getline
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, p.nombre);
    cout << "Ingrese el promedio del estudiante: ";
    cin >> p.promedio;
    estudiantes.push_back(p);
}

// Ordenamiento por burbuja de menor a mayor promedio
void OrdenarPorPromedio(vector<Estudiante> &estudiantes) {
    int n = estudiantes.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (estudiantes[j].promedio > estudiantes[j + 1].promedio) { // "<" para menor a mayor
                Estudiante temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
}

// Mostrar estudiantes de mayor a menor recorriendo al revés
void MostrarEstudiantesReversa(const vector<Estudiante> &estudiantes) {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes ingresados." << endl;
        return;
    }

    cout << "\nLista de estudiantes de mayor a menor promedio:\n";
    for (int i = estudiantes.size() - 1; i >= 0; i--) {
        cout << "Carnet: " << estudiantes[i].carnet
             << ", Nombre: " << estudiantes[i].nombre
             << ", Promedio: " << estudiantes[i].promedio << endl;
    }
}

// Mostrar mejor y peor promedio
void MejoryPeor(const vector<Estudiante> &estudiantes) {
    if (estudiantes.empty()) return;

    int posMejor = 0;
    int posPeor = 0;
    int n = estudiantes.size();

    for (int i = 1; i < n; i++) {
        if (estudiantes[i].promedio > estudiantes[posMejor].promedio) {
            posMejor = i;
        }
        if (estudiantes[i].promedio < estudiantes[posPeor].promedio) {
            posPeor = i;
        }
    }

    cout << "\nEstudiante con mejor promedio:\n";
    cout << "Carnet: " << estudiantes[posMejor].carnet
         << ", Nombre: " << estudiantes[posMejor].nombre
         << ", Promedio: " << estudiantes[posMejor].promedio << endl;

    cout << "\nEstudiante con peor promedio:\n";
    cout << "Carnet: " << estudiantes[posPeor].carnet
         << ", Nombre: " << estudiantes[posPeor].nombre
         << ", Promedio: " << estudiantes[posPeor].promedio << endl;
}

int main() {
    vector<Estudiante> estudiantes;
    int opcion;

    do {
        cout << "\nMENU: " << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Ordenar por promedio (mayor a menor)" << endl;
        cout << "3. Encontrar mejor y peor promedio" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            Ingresar(estudiantes);
            break;
        case 2:
            OrdenarPorPromedio(estudiantes);         // Ordena de menor a mayor
            MostrarEstudiantesReversa(estudiantes);  // Imprime de mayor a menor
            break;
        case 3:
            MejoryPeor(estudiantes);
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}


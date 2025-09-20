#include <iostream>
using namespace std;

struct Estudiante
{
    string nombre;
    int edad;
    float promedio;
};

void leerEstudiante(Estudiante est[]){
   for (int i = 0; i < 3; i++)
   {
       cout << "nombre del estudiante " << i + 1 << ": " << est[i].nombre <<endl;
       cout << "edad del estudiante " << i + 1 << ": " << est[i].edad <<endl;
       cout << "promedio del estudiante " << i + 1 << ": " << est[i].promedio <<endl;
   }
}
void mejorPromedio(Estudiante est[]){
    int indicemayor = 0;
    for (int i = 0; i < 3; i++)
    {

        if (est[i].promedio > est[indicemayor].promedio)
        {
            indicemayor = i;
        }
    }
    cout << "El estudiante con el mayor promedio es: " << est[indicemayor].nombre << " con un promedio de " << est[indicemayor].promedio << endl;
}

int main()
{
    Estudiante est[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> est[i].nombre;
        cout << "Ingrese la edad del estudiante " << i + 1 << ": ";
        cin >> est[i].edad;
        cout << "Ingrese el promedio del estudiante " << i + 1 << ": ";
        cin >> est[i].promedio;
    }
    leerEstudiante(est);
    mejorPromedio(est);

}

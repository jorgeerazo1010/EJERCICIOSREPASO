/*
4. Cadenas con funciones y arrays
Trabaja con char[] (no con string).
    - Implementa funciones que:
        - Verifiquen si una cadena es un palíndromo.
        - Conviertan todas las letras a mayúsculas.
        - Cuenten cuántas vocales y consonantes tiene.*/

#include <iostream>
#include <string.h>
using namespace std;



void palindromo(char cadena[], char palin[])
{
    char copia[100];
    strcpy(copia, cadena);        // guardamos la original
    strcpy(palin, strrev(copia)); // invertimos la copia y la guardamos en palin

    if (strcmp(palin, cadena) == 0)
    {
        cout << "Si es un palindromo." << endl;
    }
    else
    {
        cout << "No es un palindromo." << endl;
    }
}

void mayusculas(char cadena[])
{
    cout << "La palabra en mayusculas es: " << strupr(cadena) << endl;
}

void contar(char cadena[]) {
    int vocales = 0, consonantes = 0; 
    int N=strlen(cadena);
    
    for (int i = 0; i < N ; i++) {
        char c = cadena[i];

        // Contamos vocales (mayúsculas o minúsculas)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vocales++;
        }
        // Contamos consonantes (todas las letras menos vocales)
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            consonantes++;
        }
        // números o símbolos se ignoran
    }
    cout << "La palabra tiene " << vocales << " vocales y " << consonantes << " consonantes." << endl;
}

int main()
{

    char cadena[100], palin[100];
    cout << "Ingresa la palabra deseada: " << endl;
    cin.getline(cadena, 100, '\n');
    palindromo(cadena, palin);
    mayusculas(cadena);
    contar(cadena);
}

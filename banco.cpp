/*5. Banco (simulación simple con structs y funciones)
    - Crea un struct Cuenta con: numeroCuenta, nombreTitular, saldo.
    - El programa debe:
    - Usar un arreglo dinámico de cuentas.
    - Permitir:
    - Depositar dinero.
    - Retirar dinero (con validación de fondos).
    - Transferir entre cuentas.
    - Mostrar el saldo total del banco.*/
#include <iostream>
#include <vector>
using namespace std;

struct Cuenta
{

    int numeroCuenta;
    string nombreTitular;
    int saldo;
};

void crear(vector<Cuenta> &cuentas)
{
    Cuenta c;
    cout << "Ingrese el numero de la cuenta: " << endl;
    cin >> c.numeroCuenta;
    cout << "Ingrese el nombre del responsable de la cuenta: " << endl;
    cin >> c.nombreTitular;
    cout << "Ingrese el saldo a depositar a la cuenta: " << endl;
    cin >> c.saldo;
    cuentas.push_back(c);
}

void mostrarCuentas(vector<Cuenta> &cuentas)
{
    Cuenta c;
    int longitud;
    longitud = cuentas.size();

    for (int i = 0; i < longitud; i++)
    {
        cout << "Numero de cuenta " << i + 1 << " " << cuentas[i].numeroCuenta << endl;
        cout << "Nombre del responsable de la cuenta " << i + 1 << " " << cuentas[i].nombreTitular << endl;
        cout << "Saldo de la cuenta " << i + 1 << " " << cuentas[i].saldo << endl;
    }
}

void depositar(vector<Cuenta> &cuentas)
{
    Cuenta c;
    int numero, deposito, total;
    cout << "Ingrese el numero de cuenta a depositar: " << endl;
    cin >> numero;

    cout << "Ingrese la cantidad en dolares a depositar: " << endl;
    cin >> deposito;

    int longitud;
    longitud = cuentas.size();

    for (int i = 0; i < longitud; i++)
    {
        if (numero == cuentas[i].numeroCuenta)
        {
            cuentas[i].saldo += deposito;
        }
    }
}

void retirar(vector<Cuenta> &cuentas)
{
    int numero, monto;
    int total;
    cout << "Ingrese el numero de cuenta de donde desea retirar: " << endl;
    cin >> numero;

    cout << "Ingrese la cantidad a retirar: " << endl;
    cin >> monto;

    int longitud;
    longitud = cuentas.size();

    for (int i = 0; i < longitud; i++)
    {

        if (numero == cuentas[i].saldo)
        {
            if (cuentas[i].saldo > 0)
            {
                cuentas[i].saldo -= monto;
            }

            else
            {
                cout << "Saldo insuficiente." << endl;
            }
        }
    }
}

void Transferencia(vector<Cuenta> &cuentas)
{
    int numero, monto;
    int total;
    cout << "Ingrese el numero de cuenta de donde desea transferir: " << endl;
    cin >> numero;

    cout << "Ingrese la cantidad a retirar: " << endl;
    cin >> monto;

    int longitud;
    longitud = cuentas.size();

    for (int i = 0; i < longitud; i++)
    {

        if (numero == cuentas[i].numeroCuenta)
        {
            if (cuentas[i].saldo > 0)
            {
               cuentas[i].saldo -= monto;
            }

            else
            {
                cout << "Saldo insuficiente." << endl;
            }
        }
    }
    cout << "Ingrese el numero de cuenta adonde desea depositar: " << endl;
    cin >> numero;

    for (int i = 0; i < longitud; i++)
    {
        if (numero == cuentas[i].numeroCuenta)
        {
            cuentas[i].saldo += monto;
        }

       
    }
}

void saldoTotal(vector<Cuenta> &cuentas)
{
    int longitud;
    int total = 0;
    longitud = cuentas.size();

    for (int i = 0; i < longitud; i++)
    {
        total = total + cuentas[i].saldo;
    }

    cout << "El saldo total del banco es: " << total << endl;
}

int main()
{
    vector<Cuenta> cuentas;
    int opcion;
    do
    {
        cout << "\nMENU: " << endl;
        cout << "1. Agregar cuenta" << endl;
        cout << "2. Mostrar cuentas" << endl;
        cout << "3. Depositar dinero" << endl;
        cout << "4. Transferir dinero" << endl;
        cout << "5. Saldo total del banco" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            crear(cuentas);
            break;
        case 2:
            mostrarCuentas(cuentas);
            break;
        case 3:
            depositar(cuentas);
            cout << "Cuentas actualizadas: " << endl;
            mostrarCuentas(cuentas);
            break;
        case 4:
            Transferencia(cuentas);
            cout << "Cuentas actualizadas: " << endl;
            mostrarCuentas(cuentas);
            break;
        case 5:
            saldoTotal(cuentas);
            break;

        default:
            break;
        }
    } while (opcion!=6);
}

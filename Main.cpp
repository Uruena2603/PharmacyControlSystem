#include <iostream>
#include "Laboratorio.h"
#include "Cliente.h"
#include "CompraVenta.h"
#include "Consultas.h"
#include "Medicamento.h"
using namespace std;

void limpiarDatos()
{
    limpiarMedicamentos();
}

void menu()
{
    int opcion = 0;
    do
    {
        system("cls");
        cout << "BIENVENIDO PHARMACY CONTROL SYSTEM\n";
        cout << "ADMINISTRAR MEDICAMENTOS------->(1)\n";
        cout << "ADMINISTRAR LABORATORIOS------->(2)\n";
        cout << "ADMINISTRAR CLIENTES----------->(3)\n";
        cout << "COMPRAR MEDICAMENTOS----------->(4)\n";
        cout << "VENDER MEDICAMENTOS------------>(5)\n";
        cout << "HISTORIAL FACTURAS------------->(6)\n";
        cout << "CONSULTAS---------------------->(7)\n";
        cout << "CERRAR PROGRMAMA--------------->(8)\n";
        cout << "DIGITE UNA OPCION-------------->";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            system("cls");
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            system("pause");
            break;
        }
        default:
        {
            system("cls");
            cout << "NINGUNA OPCION DISPONIBLE FUE SELECCIONADA.\n";
            system("pause");
            cin.ignore();
            menu();
            break;
        }
        }

    } while (opcion >= 1 && opcion <= 7);
}

int main()
{
    system("cls");
    limpiarDatos();
    menu();
    cin.ignore();
    return 0;
}

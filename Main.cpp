#include <iostream>
#include "Laboratorio.h"
#include "Cliente.h"
#include "CompraVenta.h"
#include "Consultas.h"
#include "Medicamento.h"
using namespace std;

void limpiarDatos()
{
}

void menu()
{
    int menu = 0;
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
        cout << "CERRAR PROGRMAMA--------------->(7)\n";

        cin >> menu;

        switch (menu)
        {
        }

    } while (menu >= 1 && menu <= 8);
}

int main()
{
    system("cls");
    limpiarDatos();
    menu();
    cin.ignore();
    return 0;
}

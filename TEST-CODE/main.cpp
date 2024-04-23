#include <iostream>
#include <windows.h>
#include "Laboratorio.h"
#include "Cliente.h"
#include "CompraVenta.h"
#include "Consultas.h"
#include "Medicamento.h"

using namespace std;

void limpiarDatos() {
    limpiarMedicamentos();
    limpiarLaboratorio();
    limpiarCliente();
}

void mostrarOpciones(int Set[], int numOpciones) {
    gotos(0, 0);
    color(15);
    printf("BIENVENIDO! PHARMACY CONTROL SYSTEM\n\n");
    for (int i = 0; i < numOpciones; ++i) {
        color(Set[i]);
        switch (i + 1) {
            case 1:
                printf("1. ADMINISTRAR MEDICAMENTOS\n");
                break;
            case 2:
                printf("2. ADMINISTRAR LABORATORIOS\n");
                break;
            case 3:
                printf("3. ADMINISTRAR CLIENTES\n");
                break;
            case 4:
                printf("4. COMPRAR $$$ MEDICAMENTOS\n");
                break;
            case 5:
                printf("5. VENDER  $$$ MEDICAMENTOS\n");
                break;
            case 6:
                printf("6. HISTORIAL # FACTURAS\n");
                break;
            case 7:
                printf("7. CONSULTAS\n");
                break;
            case 8:
                printf("8. CERRAR PROGRAMA\n");
                break;
        }
    }
    color(7);
}

void menu() {
    int Set[] = {15, 15, 15, 15, 15, 15, 15, 15};
    int counter = 0;
    char llave;

    do {
        mostrarOpciones(Set, 8);

        llave = _getch();
        if (llave == 72 && counter > 1) {
            Set[counter - 1] = 15;
            counter--;
        }
        else if (llave == 80 && counter < 8) {
            Set[counter - 1] = 15;
            counter++;
        }
        else if (llave == '\r') {
            break;
        }
        Set[counter - 1] = 12;
    } while (true);
    gotos(0, 9);
    for (int i = 0; i < 20; ++i) {
        printf("                                         ");// Espacios en blanco para borrar
    }
        switch (counter) {
        case 1:
        {
            system("cls");
            crudMedicamentos();
            break;
        }
        case 2:
        {
            system("cls");
            crudLaboratorios();
            break;
        }
        case 3:
        {
            system("cls");
            crudCliente();
            break;
        }
        case 4:
        {
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");
            break;
        }
        case 6:
        {
            system("cls");
            break;
        }
        case 7:
        {
            system("cls");
            break;
        }
        case 8:
        {
            system("cls");
            color(12);
            printf("SALIENDO...\n");
            color(15);
            exit(0);
        }
    }
    cin.ignore();
}

int main() {
    system("cls");
    limpiarDatos();
    do {
        menu();
    } while (true);
    cin.ignore();
    return 0;
}

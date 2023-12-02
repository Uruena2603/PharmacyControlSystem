// Laboratorio.h
#include <iostream>
#ifndef LABORATORIO_H
#define LABORATORIO_H
using namespace std;

const int tamanoLaboratorio = 11;

struct Laboratorio
{
    int codigoLaboratorio = 0;
    string nombreLaboratorio = "";
    int telefonoLaboratorio = 0;
    string direccionLaboratorio = "";
    string emailLaboratorio = "";
};

int validarGuardado(Laboratorio site[], int tamanoLaboratorio)
{
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        if (site[i].codigoLaboratorio == 0 && site[i].nombreLaboratorio.empty() && site[i].telefonoLaboratorio == 0 && site[i].direccionLaboratorio.empty() && site[i].emailLaboratorio.empty())
        {
            return i;
        }
    }
    return 11;
}

bool validarLaboratorio(Laboratorio site[], int tamanoLaboratorio, int codigoLaboratorio)
{
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        if (site[i].codigoLaboratorio == codigoLaboratorio)
        {
            return true;
        }
    }
    return false;
}

void verLaboratorios(Laboratorio site[], int tamanoLaboratorio)
{
    system("cls");
    cout << "LABORATORIOS GUARDADOS\n";
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        int codigoLaboratorio = 0;
        codigoLaboratorio = site[i].codigoLaboratorio;
        if (codigoLaboratorio != 0)
        {
            cout << "\nLABORATORIO #" << i + 1 << "\n";
            cout << "CODIGO    LABORATORIO-->" << site[i].codigoLaboratorio << "\n";
            cout << "NOMBRE    LABORATORIO-->" << site[i].nombreLaboratorio << "\n";
            cout << "TELEFONO  LABORATORIO-->" << site[i].telefonoLaboratorio << "\n";
            cout << "DIRECCION LABORATORIO-->" << site[i].direccionLaboratorio << "\n";
            cout << "EMAIL     LABORATORIO-->" << site[i].emailLaboratorio << "\n";
            system("pause");
        }
        else
        {
            cout << "INGRESE MAS LABORATORIOS. (# DE ESPACIOS DISPONIBLES:" << tamanoLaboratorio - i << ")\n";
            system("pause");
            break;
        }
    }
    cin.get();
}

void crearLaboratorio(Laboratorio site[], int tamanoLaboratorio)
{
    system("cls");
    cout << "COMPLETE EL FORMULARIO PARA REGISTRAR UN LABORATORIO\n";
    int dato = validarGuardado(site, tamanoLaboratorio);
    int codigo = 0;
    string nombre = "";
    if (dato >= 0 && dato < tamanoLaboratorio)
    {
        cout << "INGRESE EL NOMBRE DEL LABORATORIO-->";
        cin >> nombre;
        cout << "INGRESE EL CODIGO DEL LABORATORIO-->";
        cin >> codigo;
        if (!validarLaboratorio(site, tamanoLaboratorio, codigo))
        {
            site[dato].codigoLaboratorio = codigo;
            site[dato].nombreLaboratorio = nombre;
            int telefono = 0;
            string direccion = "";
            string email = "";
            cout << "INGRESE EL TELEFONO DEL LABORATORIO-->";
            cin >> telefono;
            site[dato].codigoLaboratorio = telefono;
            cin.ignore();
            cout << "INGRESE LA DIRECCION DEL LABORATORIO-->";
            cin >> direccion;
            site[dato].direccionLaboratorio = direccion;
            cout << "INGRESE EL EMAIL DEL LABORATORIO-->";
            cin >> email;
            site[dato].emailLaboratorio = email;
        }
        else
        {
            for (int i = 0; i < tamanoLaboratorio; i++)
            {
                if (site[i].codigoLaboratorio == codigo)
                {
                    cout << "EL LABORATORIO->" << site[i].nombreLaboratorio << " CON CODIGO->" << site[i].codigoLaboratorio << "YA ESTA REGISTRADO\n";
                    cin.ignore();
                    break;
                }
            }
            return;
        }
        cout << "SE HA REGISTRADO EL LABORATORIO\n";
        system("pause");
    }
}

Laboratorio site[tamanoLaboratorio];

void crudLaboratorios()
{
    int opcion = 0;
    do
    {
        system("cls");
        cout << "CREAR LABORATORIO--------->1\n";
        cout << "VER LABORATORIOS---------->2\n";
        cout << "ACTUALIZAR LABORATORIOS--->3\n";
        cout << "ELIMINAR LABORATORIOS----->4\n";
        cout << "SALIR--------------------->5\n";
        cout << "DIGITE UNA OPCION--------->";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            crearLaboratorio(site, tamanoLaboratorio);
            break;
        }
        case 2:
        {
            verLaboratorios(site, tamanoLaboratorio);
            break;
        }
        case 3:
        {
            // actualizarLaboratorio();
            break;
        }
        case 4:
        {
            // eliminarLaboratorio();
            break;
        }
        default:
        {
            system("cls");
            cout << "EXIT.\n";
            cin.ignore();
            break;
        }
            cin.ignore();
            break;
        }
    } while (opcion >= 1 && opcion < 4);
}

void limpiarLaboratorio()
{
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        site[i].codigoLaboratorio = 0;
        site[i].nombreLaboratorio = "";
        site[i].telefonoLaboratorio = 0;
        site[i].direccionLaboratorio = "";
        site[i].emailLaboratorio = "";
    }
}

void eliminarLaboratorio()
{
}

void actualizarLaboratorio()
{
}

#endif // LABORATORIO_H

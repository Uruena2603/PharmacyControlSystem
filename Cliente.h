// Clientes.h
#include <iostream>
#ifndef CLIENTE_H
#define CLIENTE_H
using namespace std;

const int tamanoCliente = 11;

struct Cliente
{
    long cedulaCliente = 0;
    string nombreCliente = "";
    string direccionCliente = "";
    long celularCliente = 0;
    string fechaNacimientoCliente = "";
    string emailCliente = "";
};

int validarGuardado(Cliente client[], int tamanoCliente)
{
    for (int i = 0; i < tamanoCliente; i++)
    {
        if (client[i].cedulaCliente == 0 && client[i].nombreCliente.empty() && client[i].direccionCliente.empty() && client[i].celularCliente == 0 && client[i].fechaNacimientoCliente.empty() && client[i].emailCliente.empty())
        {
            return i;
        }
    }
    return 11;
}

bool validarCliente(Cliente client[], int tamanoCliente, int cedulaCliente)
{
    for (int i = 0; i < tamanoCliente; i++)
    {
        if (client[i].cedulaCliente == cedulaCliente)
        {
            return true;
        }
    }
    return false;
}

void verClientes(Cliente client[], int tamanoCliente)
{
    system("cls");
    cout << "CLIENTES GUARDADOS\n";
    for (int i = 0; i < tamanoCliente; i++)
    {
        int cedulaCliente = 0;
        cedulaCliente = client[i].cedulaCliente;
        if (cedulaCliente != 0)
        {
            cout << "\nCLIENTE #" << i + 1 << "\n";
            cout << "CEDULA    CLIENTE-->" << client[i].cedulaCliente << "\n";
            cout << "NOMBRE    CLIENTE-->" << client[i].nombreCliente << "\n";
            cout << "DIRECCION CLIENTE-->" << client[i].direccionCliente << "\n";
            cout << "CELULAR   CLIENTE-->" << client[i].celularCliente << "\n";
            cout << "EMAIL     CLIENTE-->" << client[i].emailCliente << "\n";
        }
        else
        {
            cout << "\nINGRESE MAS CLIENTES. (# DE ESPACIOS DISPONIBLES:" << tamanoCliente - i << ")\n";
            system("pause");
            break;
        }
    }
    cin.get();
}

void crearCliente(Cliente client[], int tamanoCliente)
{
    system("cls");
    cout << "COMPLETE EL FORMULARIO PARA REGISTRAR UN CLIENTE\n";
    int dato = validarGuardado(client, tamanoCliente);
    long cedula = 0;
    string nombre = "";
    if (dato >= 0 && dato < tamanoCliente)
    {
        cout << "INGRESE EL NOMBRE DEL CLIENTE-->";
        cin >> nombre;
        cout << "INGRESE LA CEDULA DEL CLIENTE-->";
        cin >> cedula;
        if (!validarCliente(client, tamanoCliente, cedula))
        {
            client[dato].nombreCliente = nombre;
            client[dato].cedulaCliente = cedula;
            cout << "INGRESE EL EMAIL DEL CLIENTE-->";
            cin >> client[dato].emailCliente;
            cout << "INGRESE LA DIRECCION DEL CLIENTE-->";
            cin >> client[dato].direccionCliente;
            cout << "INGRESE EL CELULAR DEL CLIENTE-->";
            cin >> client[dato].celularCliente;
        }
        else
        {
            for (int i = 0; i < tamanoCliente; i++)
            {
                if (client[i].cedulaCliente == cedula)
                {
                    cout << "EL CLIENTE->" << client[i].nombreCliente << "CON CEDULA->" << client[i].cedulaCliente << " YA ESTA REGISTRADO\n";
                    cin.ignore();
                    break;
                }
            }
            return;
        }
        cout << "SE HA REGISTRADO EL CLIENTE\n";
        system("pause");
    }
}

Cliente client[tamanoCliente];

void crudCliente()
{
    int opcion = 0;
    do
    {
        system("cls");
        cout << "CREAR CLIENTE------------->1\n";
        cout << "VER CLIENTE--------------->2\n";
        cout << "ACTUALIZAR CLIENTE-------->3\n";
        cout << "ELIMINAR CLIENTE---------->4\n";
        cout << "SALIR--------------------->5\n";
        cout << "DIGITE UNA OPCION--------->";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            crearCliente(client, tamanoCliente);
            break;
        }
        case 2:
        {
            verClientes(client, tamanoCliente);
            break;
        }
        case 3:
        {
            // actualizarCliente();
            break;
        }
        case 4:
        {
            // eliminarCliente();
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
    } while (opcion >= 1 && opcion < 5);
}

void limpiarCliente()
{
    for (int i = 0; i < tamanoCliente; i++)
    {
        client[i].cedulaCliente = 0;
        client[i].nombreCliente = "";
        client[i].direccionCliente = "";
        client[i].celularCliente = 0;
        client[i].fechaNacimientoCliente = "";
        client[i].emailCliente = "";
    }
}

void eliminarCliente()
{
}

void actualizarCliente()
{
}

#endif // CLIENTES_H

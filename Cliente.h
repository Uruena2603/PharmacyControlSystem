// Clientes.h
#include <iostream>
#ifndef CLIENTE_H
#define CLIENTE_H
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
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

int validarGuardado(vector<Cliente> &client, int tamanoCliente)
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

bool validarCliente(vector<Cliente> &client, int tamanoCliente, int cedulaCliente)
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

void verClientes(vector<Cliente> &client, int tamanoCliente)
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

void crearCliente(vector<Cliente> &client, int tamanoCliente)
{
    system("cls");
    cout << "COMPLETE EL FORMULARIO PARA REGISTRAR UN CLIENTE\n";
    int dato = validarGuardado(client, tamanoCliente);
    long cedula = 0;
    string nombre = "";

    if (dato >= 0 && dato < tamanoCliente)
    {
        // Validación del nombre
        cout << "INGRESE EL NOMBRE DEL CLIENTE-->";
        while (true)
        {
            cin >> nombre;

            // Validación de la cédula como cadena de números
            bool esNombreValido = true;

            for (int i = 0; i < nombre.size(); i++)
            {
                if (nombre[i] < 'a' || nombre[i] > 'z')
                {
                    esNombreValido = false;
                }
            }

            if (!esNombreValido)
            {
                system("cls");
                cout << "NOMBRE NO VALIDADO, INGRESE SOLO LETRAS\n";
                cedula = 0; // Reiniciar cedula
            }
            else
            {
                cout << "NOMBRE INGRESADO CORRECTAMENTE\n";
                break;
            }
        }

        cout << "INGRESE LA CEDULA DEL CLIENTE-->";
        while (cedula <= 0)
        {
            cin >> cedula;

            // Validación de la cédula como cadena de números
            string clave = to_string(cedula);
            bool esCedulaValida = true;

            for (int i = 0; i < clave.size(); i++)
            {
                if (clave[i] < '0' || clave[i] > '9')
                {
                    esCedulaValida = false;
                }
            }

            if (!esCedulaValida)
            {
                system("cls");
                cout << "CEDULA NO VALIDA, INGRESE SOLO NUMEROS POSITIVOS\n";
                cedula = 0; // Reiniciar cedula
            }
            else
            {
                cout << "CEDULA INGRESADA CORRECTAMENTE\n";
                break;
            }
        }

        if (!validarCliente(client, tamanoCliente, cedula))
        {
            client[dato].nombreCliente = nombre;
            client[dato].cedulaCliente = cedula;
            cout << "INGRESE EL EMAIL DEL CLIENTE-->";
            string email = "";
            for (int i = 0; i < email.size(); i++)
            {
                if (email[i] == '@')
                {
                    string substr = email.substr(email[i], email.size() - 1);
                    if (substr == "gmail" || substr == "hotmail" || substr == "yahoo" || substr == "email" || substr == "outlook")
                    {
                        cin >> client[dato].emailCliente;
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "INGRESE UN CORREO VALIDO\n";
                    }
                }
            }

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
                    cout << "EL CLIENTE-> " << client[i].nombreCliente << " CON CEDULA->" << client[i].cedulaCliente << " YA ESTA REGISTRADO\n";
                    cin.ignore();
                    system("pause");
                    return; // Salir de la función si la cédula ya está registrada
                }
            }
        }

        cout << "SE HA REGISTRADO EL CLIENTE\n";
        system("pause");
    }
}

vector<Cliente> client(tamanoCliente);

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

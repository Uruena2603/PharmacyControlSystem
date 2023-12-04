// Clientes.h
#include <iostream>
#ifndef CLIENTE_H
#define CLIENTE_H
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>
#include <stdlib.h>

using namespace std;

const int tamanoCliente = 11;

struct Cliente
{
    string cedulaCliente = "";
    string nombreCliente = "";
    string direccionCliente = "";
    string celularCliente = "";
    string fechaNacimientoCliente = "";
    string emailCliente = "";
};

int validarGuardado(vector<Cliente> &client, int tamanoCliente)
{
    for (int i = 0; i < tamanoCliente; i++)
    {
        if (client[i].cedulaCliente.empty() && client[i].nombreCliente.empty() && client[i].direccionCliente.empty() && client[i].celularCliente.empty() && client[i].fechaNacimientoCliente.empty() && client[i].emailCliente.empty())
        {
            return i;
        }
    }
    return 11;
}

bool validarCliente(vector<Cliente> &client, int tamanoCliente, string cedulaCliente)
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
        string cedulaCliente = "";
        cedulaCliente = client[i].cedulaCliente;
        if (!cedulaCliente.empty())
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
    string cedula = "";
    string nombre = "";

    if (dato >= 0 && dato < tamanoCliente)
    {
        // Validación del nombre
        cout << "INGRESE EL NOMBRE DEL CLIENTE-->";
        while (true)
        {
            cin.ignore();
            getline(cin, client[dato].nombreCliente);
            nombre = client[dato].nombreCliente;
            bool nombreValido = true;

            if (client[dato].nombreCliente.empty())
            {
                cout << "EL NOMBRE NO PUEDE ESTAR VACIO\n";
                nombreValido = false;
                continue;
            }
            for (int i = 0; i < nombre.size(); i++)
            {
                if (nombre[i] < 'a' || nombre[i] > 'z')
                {
                    nombreValido = false;
                }
            }
            if (!nombreValido)
            {
                system("cls");
                cout << "NOMBRE NO VALIDADO, INGRESE SOLO LETRAS\n";
                nombre = "";
            }
            else
            {
                cout << "NOMBRE INGRESADO CORRECTAMENTE\n";
                break;
            }
        }

        bool cedulaValida = false;
        string cedula = "";
        cout << "INGRESE LA CEDULA DEL CLIENTE-->";
        do
        {
            cin >> cedula;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool digitosValidos = true;

            for (char c : cedula) // Verifica si el número de celular contiene solo dígitos
            {
                if (!isdigit(c))
                {
                    digitosValidos = false;
                    cout << "LA CEDULA DEBE CONTENER SOLO DIGITOS\n";
                    continue;
                }
            }

            if (digitosValidos && cedula.length() == 10)
            {
                cout << "CEDULA INGRESADA CORRECTAMENTE\n";
                cedulaValida = true;
                break;
            }
            else
            {
                if (!digitosValidos)
                {
                    cout << "LA CEDULA DEBE CONTENER SOLO DIGITOS\n";
                    continue;
                }
                else
                {
                    cout << "LA CEDULA DEBE CONTENER 10 DIGITOS\n";
                    continue;
                }
            }

        } while (!cedulaValida);

        if (!validarCliente(client, tamanoCliente, cedula))
        {
            client[dato].nombreCliente = nombre;
            client[dato].cedulaCliente = cedula;

            cout << "INGRESE EL EMAIL DEL CLIENTE-->";
            string email = "";
            bool emailValido = false;

            do
            {
                cin >> email;
                size_t posArroba = email.find('@');  // Busca la posición del '@' en el correo electrónico
                if (email.find('@') == string::npos) // Verifica si el correo electrónico no contiene el símbolo '@'
                {
                    cout << "EL CORREO ELECTRONICO DEBE CONTENER UN @\n";
                    continue;
                }
                if (posArroba != string::npos) // Verifica si se encontró el símbolo '@' en el correo electrónico
                {
                    string dominio = email.substr(posArroba + 1); // Extrae el dominio del correo electrónico

                    if (!dominio.empty() && (dominio == "gmail.com" || dominio == "hotmail.com" || dominio == "yahoo.com" || dominio == "email.com" || dominio == "outlook.com"))
                    {
                        client[dato].emailCliente = email;
                        cout << "CORREO ELECTRONICO INGRESADO CORRECTAMENTE\n";
                        emailValido = true;
                    }
                    else
                    {
                        cout << "INGRESE UN CORREO VALIDO\n";
                        cin.clear();                                                   // Limpiar el estado de error
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora entrada adicional en el buffer
                    }
                }
            } while (!emailValido);

            bool direccionValida = false;
            cout << "INGRESE LA DIRECCION DEL CLIENTE-->";
            do
            {
                cin.ignore();
                getline(cin, client[dato].direccionCliente); // Permite espacios en la dirección

                if (client[dato].direccionCliente.empty())
                {
                    cout << "LA DIRECCION NO PUEDE ESTAR VACIA\n";
                    continue;
                }
                else
                {
                    cout << "DIRECCION INGRESADA CORRECTAMENTE\n";
                    direccionValida = true;
                    break;
                }
            } while (!direccionValida);

            bool celularValido = false;
            string celular = "";
            cout << "INGRESE EL CELULAR DEL CLIENTE-->";
            do
            {
                cin >> celular;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                bool digitosValidos = true;

                for (char c : celular) // Verifica si el número de celular contiene solo dígitos
                {
                    if (!isdigit(c))
                    {
                        digitosValidos = false;
                        cout << "EL CELULAR DEBE CONTENER SOLO DIGITOS\n";
                        continue;
                    }
                }
                if (digitosValidos && celular.length() == 10)
                {
                    cout << "CELULAR INGRESADO CORRECTAMENTE\n";
                    client[dato].celularCliente = celular;
                    celularValido = true;
                }
                else
                {
                    if (!digitosValidos)
                    {
                        cout << "EL CELULAR DEBE CONTENER SOLO DIGITOS\n";
                    }
                    else
                    {
                        cout << "EL CELULAR DEBE CONTENER 10 DIGITOS\n";
                    }
                }

            } while (!celularValido);
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
        client[i].cedulaCliente = "";
        client[i].nombreCliente = "";
        client[i].direccionCliente = "";
        client[i].celularCliente = "";
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

// Laboratorio.h
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#ifndef LABORATORIO_H
#define LABORATORIO_H

using namespace std;

const int tamanoLaboratorio = 11;

struct Laboratorio
{
    string codigoLaboratorio = "";
    string nombreLaboratorio = "";
    string telefonoLaboratorio = "";
    string direccionLaboratorio = "";
    string emailLaboratorio = "";
};

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotos(int a, int b)
{
    COORD c;
    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int validarGuardado(vector<Laboratorio> &site, int tamanoLaboratorio)
{
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        if (site[i].codigoLaboratorio.empty() && site[i].nombreLaboratorio.empty() && site[i].telefonoLaboratorio.empty() && site[i].direccionLaboratorio.empty() && site[i].emailLaboratorio.empty())
        {
            return i;
        }
    }
    return 11;
}

bool validarLaboratorio(vector<Laboratorio> &site, int tamanoLaboratorio, string codigoLaboratorio)
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

void verLaboratorios(vector<Laboratorio> &site, int tamanoLaboratorio)
{
    system("cls");
    cout << "LABORATORIOS GUARDADOS\n";
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        string codigoLaboratorio = "";
        codigoLaboratorio = site[i].codigoLaboratorio;
        if (!codigoLaboratorio.empty())
        {
            cout << "\nLABORATORIO #" << i + 1 << "\n";
            cout << "CODIGO    LABORATORIO-->" << site[i].codigoLaboratorio << "\n";
            cout << "NOMBRE    LABORATORIO-->" << site[i].nombreLaboratorio << "\n";
            cout << "TELEFONO  LABORATORIO-->" << site[i].telefonoLaboratorio << "\n";
            cout << "DIRECCION LABORATORIO-->" << site[i].direccionLaboratorio << "\n";
            cout << "EMAIL     LABORATORIO-->" << site[i].emailLaboratorio << "\n";
        }
        else
        {
            cout << "\nINGRESE MAS LABORATORIOS. (# DE ESPACIOS DISPONIBLES:" << tamanoLaboratorio - i << ")\n";
            system("pause");
            break;
        }
    }
}

void crearLaboratorio(vector<Laboratorio> &site, int tamanoLaboratorio)
{
    system("cls");
    cout << "COMPLETE EL FORMULARIO PARA REGISTRAR UN LABORATORIO\n";
    int dato = validarGuardado(site, tamanoLaboratorio);
    string nombre = "";
    if (dato >= 0 && dato < tamanoLaboratorio)
    {
        cout << "INGRESE EL NOMBRE DEL LABORATORIO\n";
        cout << "~ ";
        while (true)
        {
            getline(cin, nombre);
            transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
            bool nombreValido = true;

            if (nombre.empty())
            {
                system("cls");
                cout << "EL NOMBRE NO PUEDE ESTAR VACIO\n";
                cout << "~ ";
                nombreValido = false;
                continue;
            }

            for (int i = 0; i < nombre.size(); i++)
            {
                if (nombre[i] == 32)
                {
                    continue;
                }

                if (nombre[i] < 97 || nombre[i] > 122)
                {
                    nombreValido = false;
                    break;
                }
            }
            if (!nombreValido)
            {
                system("cls");
                cout << "NOMBRE NO VALIDADO, INGRESE SOLO LETRAS\n";
                cout << "~ ";
                nombre = "";
            }
            else
            {
                cout << "NOMBRE INGRESADO CORRECTAMENTE\n";
                break;
            }
        }

        bool codigoValido = false;
        string codigo = "";
        cout << "INGRESE EL CODIGO DEL LABORATORIO\n";
        cout << "~ ";
        do
        {
            cin >> codigo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool digitosValidos = true;
            for (char c : codigo)
            {
                if (!isdigit(c))
                {
                    system("cls");
                    digitosValidos = false;
                    cout << "EL CODIGO DEBE CONTENER SOLO NUMEROS\n";
                    cout << "~ ";
                    break;
                }
                else if (codigo.length() != 4)
                {
                    system("cls");
                    digitosValidos = false;
                    cout << "EL CODIGO DEBE CONTENER 4 DIGITOS\n";
                    cout << "~ ";
                    break;
                }
            }
            if (digitosValidos && codigo.length() == 4)
            {
                cout << "CODIGO INGRESADO CORRECTAMENTE\n";
                codigoValido = true;
                break;
            }
        } while (!codigoValido);

        if (!validarLaboratorio(site, tamanoLaboratorio, codigo))
        {
            site[dato].codigoLaboratorio = codigo;
            site[dato].nombreLaboratorio = nombre;

            bool telefonoValido = false;
            string telefono = "";
            cout << "INGRESE EL TELEFONO DEL LABORATORIO\n";
            cout << "~ ";
            do
            {
                cin >> telefono;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                bool digitosValidos = true;

                for (char c : telefono)
                {
                    if (!isdigit(c))
                    {
                        system("cls");
                        digitosValidos = false;
                        cout << "EL TELEFONO DEBE CONTENER SOLO DIGITOS\n";
                        cout << "~ ";
                        continue;
                    }
                }
                if (digitosValidos && telefono.length() == 10)
                {
                    cout << "TELEFONO INGRESADO CORRECTAMENTE\n";
                    site[dato].telefonoLaboratorio = telefono;
                    telefonoValido = true;
                }
                else
                {
                    if (!digitosValidos)
                    {
                        system("cls");
                        cout << "EL TELEFONO DEBE CONTENER SOLO DIGITOS\n";
                        cout << "~ ";
                    }
                    else
                    {
                        system("cls");
                        cout << "EL TELEFONO DEBE CONTENER 10 DIGITOS\n";
                        cout << "~ ";
                    }
                }

            } while (!telefonoValido);

            bool direccionValida = false;
            cout << "INGRESE LA DIRECCION DEL LABORATORIO\n";
            cout << "~ ";
            do
            {
                getline(cin, site[dato].direccionLaboratorio);

                if (site[dato].direccionLaboratorio.empty())
                {
                    system("cls");
                    cout << "LA DIRECCION NO PUEDE ESTAR VACIA\n";
                    cout << "~ ";
                    continue;
                }
                else
                {
                    cout << "DIRECCION INGRESADA CORRECTAMENTE\n";
                    direccionValida = true;
                    break;
                }
            } while (!direccionValida);

            cout << "INGRESE EL EMAIL DEL LABORATORIO\n";
            cout << "~ ";
            string email = "";
            bool emailValido = false;

            do
            {
                cin >> email;
                size_t posArroba = email.find('@');
                if (email.find('@') == string::npos)
                {
                    system("cls");
                    cout << "EL CORREO ELECTRONICO DEBE CONTENER UN @\n";
                    cout << "~ ";
                    continue;
                }
                if (posArroba != string::npos)
                {
                    string dominio = email.substr(posArroba + 1);

                    if (!dominio.empty() && (dominio == "gmail.com" || dominio == "hotmail.com" || dominio == "yahoo.com" || dominio == "email.com" || dominio == "outlook.com"))
                    {
                        site[dato].emailLaboratorio = email;
                        cout << "CORREO ELECTRONICO INGRESADO CORRECTAMENTE\n";
                        emailValido = true;
                    }
                    else
                    {
                        system("cls");
                        cout << "INGRESE UN CORREO VALIDO\n";
                        cout << "~ ";
                        cin.clear();                                                   // Limpiar el estado de error
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora entrada adicional en el buffer
                    }
                }
            } while (!emailValido);
        }
        else
        {
            for (int i = 0; i < tamanoLaboratorio; i++)
            {
                if (site[i].codigoLaboratorio == codigo)
                {
                    cout << "EL LABORATORIO-> " << site[i].nombreLaboratorio << " CON CODIGO-> " << site[i].codigoLaboratorio << " YA ESTA REGISTRADO\n";
                    cin.ignore();
                    system("pause");
                    return;
                }
            }
        }
        cout << "SE HA REGISTRADO EL LABORATORIO\n";
        system("pause");
    }
}

void eliminarLaboratorio(vector<Laboratorio> &site, int tamanoLaboratorio)
{
    system("cls");
    cout << "COMPLETE EL FORMULARIO PARA ELIMINAR UN LABORATORIO\n";
    string codigo = "";
    cout << "INGRESE EL CODIGO DEL LABORATORIO\n";
    cout << "~ ";
    cin >> codigo;

    bool laboratorioEncontrado = false;

    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        if (codigo == site[i].codigoLaboratorio)
        {
            site.erase(site.begin() + i);
            cout << "EL LABORATORIO HA SIDO ELIMINADO.\n";
            laboratorioEncontrado = true;
            break;
        }
    }
    if (!laboratorioEncontrado)
    {
        cout << "EL CODIGO INGRESADO NO HA SIDO ENCONTRADO.\n";
    }
    system("pause");
}

void actualizarLaboratorio(vector<Laboratorio> &site, int tamanoLaboratorio)
{
    system("cls");
    cout << "COMPLETE EL FORMULARIO PARA ACTUALIZAR UN LABORATORIO\n";
    string codigo = "";
    cout << "INGRESE EL CODIGO DEL LABORATORIO\n";
    cout << "~ ";
    cin >> codigo;
    bool laboratorioEncontrado = false;
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        if (codigo == site[i].codigoLaboratorio)
        {
            laboratorioEncontrado = true;
            int opcion = 0;
            do
            {
                system("cls");
                cout << "ACTUALIZAR NOMBRE------>(1)\n";
                cout << "ACTUALIZAR TELEFONO---->(2)\n";
                cout << "ACTUALIZAR DIRECCION--->(3)\n";
                cout << "ACTUALIZAR EMAIL------->(4)\n";
                cout << "ACTUALIZAR TODO-------->(5)\n";
                color(12);
                cout << "SALIR------------------>(6)\n";
                color(7);
                cout << "DIGITE UNA OPCION\n";
                cout << "~ ";
                cin >> opcion;

                switch (opcion)
                {
                case 1:
                {
                    system("cls");
                    string nombre = "";
                    cout << "NOMBRE ACTUAL--> " << site[i].nombreLaboratorio << ".\n";
                    cin.get();
                    cout << "INGRESE EL NUEVO NOMBRE\n";
                    cout << "~ ";
                    while (true)
                    {
                        getline(cin, nombre);
                        transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
                        bool nombreValido = true;

                        if (nombre.empty())
                        {
                            system("cls");
                            cout << "EL NOMBRE NO PUEDE ESTAR VACIO\n";
                            cout << "~ ";
                            nombreValido = false;
                            continue;
                        }

                        for (int i = 0; i < nombre.size(); i++)
                        {
                            if (nombre[i] == 32)
                            {
                                continue;
                            }

                            if (nombre[i] < 97 || nombre[i] > 122)
                            {
                                nombreValido = false;
                                break;
                            }
                        }
                        if (!nombreValido)
                        {
                            system("cls");
                            cout << "NOMBRE NO VALIDADO, INGRESE SOLO LETRAS\n";
                            cout << "~ ";
                            nombre = "";
                        }
                        else
                        {
                            cout << "NOMBRE INGRESADO CORRECTAMENTE\n\n";
                            cout << "ACTUALIZACION COMPLETADA CON EXITO.\n";
                            site[i].nombreLaboratorio = nombre;
                            system("pause");
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    system("cls");
                    string telefono = "";
                    cout << "TELEFONO ACTUAL--> " << site[i].telefonoLaboratorio << ".\n";
                    cin.get();
                    bool telefonoValido = false;
                    cout << "INGRESE EL NUEVO TELEFONO\n";
                    cout << "~ ";
                    do
                    {
                        cin >> telefono;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        bool digitosValidos = true;

                        for (char c : telefono)
                        {
                            if (!isdigit(c))
                            {
                                system("cls");
                                digitosValidos = false;
                                cout << "EL TELEFONO DEBE CONTENER SOLO DIGITOS\n";
                                cout << "~ ";
                                continue;
                            }
                        }
                        if (digitosValidos && telefono.length() == 10)
                        {
                            cout << "TELEFONO INGRESADO CORRECTAMENTE\n\n";
                            cout << "ACTUALIZACION COMPLETADA CON EXITO.\n";
                            system("pause");
                            site[i].telefonoLaboratorio = telefono;
                            telefonoValido = true;
                        }
                        else
                        {
                            if (!digitosValidos)
                            {
                                system("cls");
                                cout << "EL TELEFONO DEBE CONTENER SOLO DIGITOS\n";
                                cout << "~ ";
                            }
                            else
                            {
                                system("cls");
                                cout << "EL TELEFONO DEBE CONTENER 10 DIGITOS\n";
                                cout << "~ ";
                            }
                        }

                    } while (!telefonoValido);

                    break;
                }
                case 3:
                {
                    system("cls");
                    string direccion = "";
                    cout << "DIRECCION ACTUAL--> " << site[i].direccionLaboratorio << ".\n";
                    cin.get();
                    bool direccionValida = false;
                    cout << "INGRESE LA NUEVA DIRECCION\n";
                    cout << "~ ";
                    do
                    {
                        getline(cin, direccion);

                        if (direccion.empty())
                        {
                            system("cls");
                            cout << "LA DIRECCION NO PUEDE ESTAR VACIA\n";
                            cout << "~ ";
                            continue;
                        }
                        else
                        {
                            cout << "DIRECCION INGRESADA CORRECTAMENTE\n\n";
                            cout << "ACTUALIZACION COMPLETADA CON EXITO.\n";
                            system("pause");
                            site[i].direccionLaboratorio = direccion;
                            direccionValida = true;
                            break;
                        }
                    } while (!direccionValida);
                    break;
                }
                case 4:
                {
                    system("cls");
                    string email = "";
                    cout << "CORREO ACTUAL--> " << site[i].emailLaboratorio << ".\n";
                    cin.get();
                    bool emailValido = false;
                    cout << "INGRESE EL CORREO NUEVO.\n";
                    cout << "~ ";
                    do
                    {
                        cin >> email;
                        size_t posArroba = email.find('@');
                        if (email.find('@') == string::npos)
                        {
                            system("cls");
                            cout << "EL CORREO ELECTRONICO DEBE CONTENER UN @\n";
                            cout << "~ ";
                            continue;
                        }
                        if (posArroba != string::npos)
                        {
                            string dominio = email.substr(posArroba + 1);

                            if (!dominio.empty() && (dominio == "gmail.com" || dominio == "hotmail.com" || dominio == "yahoo.com" || dominio == "email.com" || dominio == "outlook.com"))
                            {
                                site[i].emailLaboratorio = email;
                                cout << "CORREO ELECTRONICO INGRESADO CORRECTAMENTE\n\n";
                                cout << "ACTUALIZACION COMPLETADA CON EXITO.\n";
                                system("pause");
                                emailValido = true;
                            }
                            else
                            {
                                system("cls");
                                cout << "INGRESE UN CORREO VALIDO\n";
                                cout << "~ ";
                                cin.clear();                                                   // Limpiar el estado de error
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora entrada adicional en el buffer
                            }
                        }
                    } while (!emailValido);

                    break;
                }
                case 5:
                {
                    system("cls");
                    string nombre = "";
                    cout << "NOMBRE ACTUAL--> " << site[i].nombreLaboratorio << ".\n";
                    cin.get();
                    cout << "INGRESE EL NUEVO NOMBRE\n";
                    cout << "~ ";
                    while (true)
                    {
                        getline(cin, nombre);
                        transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
                        bool nombreValido = true;

                        if (nombre.empty())
                        {
                            system("cls");
                            cout << "EL NOMBRE NO PUEDE ESTAR VACIO\n";
                            cout << "~ ";
                            nombreValido = false;
                            continue;
                        }

                        for (int i = 0; i < nombre.size(); i++)
                        {
                            if (nombre[i] == 32)
                            {
                                continue;
                            }

                            if (nombre[i] < 97 || nombre[i] > 122)
                            {
                                nombreValido = false;
                                break;
                            }
                        }
                        if (!nombreValido)
                        {
                            system("cls");
                            cout << "NOMBRE NO VALIDADO, INGRESE SOLO LETRAS\n";
                            cout << "~ ";
                            nombre = "";
                        }
                        else
                        {
                            cout << "NOMBRE INGRESADO CORRECTAMENTE\n";
                            site[i].nombreLaboratorio = nombre;
                            break;
                        }
                    }

                    string telefono = "";
                    cout << "TELEFONO ACTUAL--> " << site[i].telefonoLaboratorio << ".\n";
                    bool telefonoValido = false;
                    cout << "INGRESE EL NUEVO TELEFONO\n";
                    cout << "~ ";
                    do
                    {
                        cin >> telefono;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        bool digitosValidos = true;

                        for (char c : telefono)
                        {
                            if (!isdigit(c))
                            {
                                system("cls");
                                digitosValidos = false;
                                cout << "EL TELEFONO DEBE CONTENER SOLO DIGITOS\n";
                                cout << "~ ";
                                continue;
                            }
                        }
                        if (digitosValidos && telefono.length() == 10)
                        {
                            cout << "TELEFONO INGRESADO CORRECTAMENTE\n";
                            site[i].telefonoLaboratorio = telefono;
                            telefonoValido = true;
                        }
                        else
                        {
                            if (!digitosValidos)
                            {
                                system("cls");
                                cout << "EL TELEFONO DEBE CONTENER SOLO DIGITOS\n";
                                cout << "~ ";
                            }
                            else
                            {
                                system("cls");
                                cout << "EL TELEFONO DEBE CONTENER 10 DIGITOS\n";
                                cout << "~ ";
                            }
                        }

                    } while (!telefonoValido);

                    string direccion = "";
                    cout << "DIRECCION ACTUAL--> " << site[i].direccionLaboratorio << ".\n";
                    bool direccionValida = false;
                    cout << "INGRESE LA NUEVA DIRECCION\n";
                    cout << "~ ";
                    do
                    {
                        getline(cin, direccion);

                        if (direccion.empty())
                        {
                            system("cls");
                            cout << "LA DIRECCION NO PUEDE ESTAR VACIA\n";
                            cout << "~ ";
                            continue;
                        }
                        else
                        {
                            cout << "DIRECCION INGRESADA CORRECTAMENTE\n";
                            site[i].direccionLaboratorio = direccion;
                            direccionValida = true;
                            break;
                        }
                    } while (!direccionValida);

                    string email = "";
                    cout << "CORREO ACTUAL--> " << site[i].emailLaboratorio << ".\n";
                    bool emailValido = false;
                    cout << "INGRESE EL CORREO NUEVO.\n";
                    cout << "~ ";
                    do
                    {
                        cin >> email;
                        size_t posArroba = email.find('@');
                        if (email.find('@') == string::npos)
                        {
                            system("cls");
                            cout << "EL CORREO ELECTRONICO DEBE CONTENER UN @\n";
                            cout << "~ ";
                            continue;
                        }
                        if (posArroba != string::npos)
                        {
                            string dominio = email.substr(posArroba + 1);

                            if (!dominio.empty() && (dominio == "gmail.com" || dominio == "hotmail.com" || dominio == "yahoo.com" || dominio == "email.com" || dominio == "outlook.com"))
                            {
                                site[i].emailLaboratorio = email;
                                cout << "CORREO ELECTRONICO INGRESADO CORRECTAMENTE\n\n";
                                cout << "ACTUALIZACION COMPLETADA CON EXITO.\n";
                                system("pause");
                                emailValido = true;
                            }
                            else
                            {
                                system("cls");
                                cout << "INGRESE UN CORREO VALIDO\n";
                                cout << "~ ";
                                cin.clear();                                                   // Limpiar el estado de error
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora entrada adicional en el buffer
                            }
                        }
                    } while (!emailValido);

                    break;
                }
                }

            } while (opcion >= 1 && opcion < 6);
        }
    }
    if (!laboratorioEncontrado)
    {
        cout << "ESTE LABORATORIO NO ESTA REGISTRADO.\n";
        system("pause");
    }
}

vector<Laboratorio> site(tamanoLaboratorio);

void mostrarOpcionesLaboratorio(int Set[], int numOpciones)
{
    gotos(0, 0);
    color(15);
    cout << "--MENU DE LABORATORIOS (CRUD)\n\n";
    for (int i = 0; i < numOpciones; ++i)
    {
        color(Set[i]);
        switch (i + 1)
        {
        case 1:
            cout << "1. CREAR LABORATORIO\n";
            break;
        case 2:
            cout << "2. VER LABORATORIOS\n";
            break;
        case 3:
            cout << "3. ACTUALIZAR LABORATORIOS\n";
            break;
        case 4:
            cout << "4. ELIMINAR LABORATORIOS\n";
            break;
        case 5:
            cout << "5. SALIR\n";
            break;
        }
    }
    color(7);
}
void crudLaboratorios()
{
    bool flag = true;
    do
    {
        int Set[] = {15, 15, 15, 15, 15};
        int counter = 0;
        char llave;

        do
        {
            mostrarOpcionesLaboratorio(Set, 5);

            llave = _getch();
            if (llave == 72 && counter > 1)
            {
                Set[counter - 1] = 15;
                counter--;
            }
            else if (llave == 80 && counter < 5)
            {
                Set[counter - 1] = 15;
                counter++;
            }
            else if (llave == '\r')
            {
                break;
            }
            Set[counter - 1] = 12;
        } while (true);
        gotos(0, 9);
        for (int i = 0; i < 20; ++i)
        {
            cout << "                                         "; // Espacios en blanco para borrar
        }
        switch (counter)
        {
        case 1:
        {
            crearLaboratorio(site, tamanoLaboratorio);
            flag = false;
            system("cls");
            break;
        }
        case 2:
        {
            verLaboratorios(site, tamanoLaboratorio);
            flag = false;
            system("cls");
            break;
        }
        case 3:
        {
            actualizarLaboratorio(site, tamanoLaboratorio);
            flag = false;
            system("cls");
            break;
        }
        case 4:
        {
            eliminarLaboratorio(site, tamanoLaboratorio);
            flag = false;
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");
            color(15);
            cout << "SALIENDO DEL CRUD LABORATORIO...\n";
            flag = true;
            break;
        }
        default:
        {
            system("cls");
            color(15);
            cout << "NINGUNA OPCION FUE SELECCIONADA.\n";
            break;
        }
        }
    } while (!flag);
}

void limpiarLaboratorio()
{
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        site[i].codigoLaboratorio = "";
        site[i].nombreLaboratorio = "";
        site[i].telefonoLaboratorio = "";
        site[i].direccionLaboratorio = "";
        site[i].emailLaboratorio = "";
    }
}

#endif // LABORATORIO_H

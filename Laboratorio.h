// Laboratorio.h
#include <iostream>
#include <vector>
#include <limits>
#include <cstdint> // Para guardar numero correctamente debido que int=2147483647  y un numero de celular tiene notacion 300000000+
#ifndef LABORATORIO_H
#define LABORATORIO_H
using namespace std;

const int tamanoLaboratorio = 11;

struct Laboratorio
{
    int codigoLaboratorio = 0;
    string nombreLaboratorio = "";
    string telefonoLaboratorio = "";
    string direccionLaboratorio = "";
    string emailLaboratorio = "";
};

int validarGuardado(vector<Laboratorio> &site, int tamanoLaboratorio)
{
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        if (site[i].codigoLaboratorio == 0 && site[i].nombreLaboratorio.empty() && site[i].telefonoLaboratorio.empty() && site[i].direccionLaboratorio.empty() && site[i].emailLaboratorio.empty())
        {
            return i;
        }
    }
    return 11;
}

bool validarLaboratorio(vector<Laboratorio> &site, int tamanoLaboratorio, int codigoLaboratorio)
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
        }
        else
        {
            cout << "\nINGRESE MAS LABORATORIOS. (# DE ESPACIOS DISPONIBLES:" << tamanoLaboratorio - i << ")\n";
            system("pause");
            break;
        }
    }
    cin.get();
}

void crearLaboratorio(vector<Laboratorio> &site, int tamanoLaboratorio)
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
            string telefono = "";
            string direccion = "";
            string email = "";
            cout << "INGRESE EL TELEFONO DEL LABORATORIO-->";
            cin>>telefono;
            site[dato].telefonoLaboratorio = telefono;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Validacion para tomar datos sin limites
            cout << "INGRESE LA DIRECCION DEL LABORATORIO-->";
            getline(cin,direccion);
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
                    cout << "EL LABORATORIO-> " << site[i].nombreLaboratorio << " CON CODIGO-> " << site[i].codigoLaboratorio << " YA ESTA REGISTRADO\n";
                    cin.ignore();
                    system("pause");
                    break;
                }
            }
            return;
        }
        cout << "SE HA REGISTRADO EL LABORATORIO\n";
        system("pause");
    }
}

void eliminarLaboratorio(vector<Laboratorio> &site, int tamanoLaboratorio)
{
    system("cls");
    cout << "COMPLETE EL FORMULARIO PARA ELIMINAR UN LABORATORIO\n";
    int codigo = 0;
    cout << "INGRESE EL CODIGO DEL LABORATORIO-->";
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
    cin.ignore();
}
vector<Laboratorio> site(tamanoLaboratorio);

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
            eliminarLaboratorio(site, tamanoLaboratorio);
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
        site[i].telefonoLaboratorio = "";
        site[i].direccionLaboratorio = "";
        site[i].emailLaboratorio = "";
    }
}

void actualizarLaboratorio()
{
}

#endif // LABORATORIO_H

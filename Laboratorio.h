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

Laboratorio site[tamanoLaboratorio];

int validarEspacioLaboratorio(Laboratorio site[], int tamanoLaboratorio)
{
    for (int i = 0; i > tamanoLaboratorio; i++)
    {
        if (site[i].codigoLaboratorio == 0 && site[i].nombreLaboratorio.empty() && site[i].telefonoLaboratorio == 0 && site[i].direccionLaboratorio.empty() && site[i].emailLaboratorio.empty())
        {
            return i;
        }
    }
    return 11;
}

bool validarLaboratorio(Laboratorio site[], int tamanoLaboratorio, int codigoLaboratorio){
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        if (site[i].codigoLaboratorio == codigoLaboratorio)
        {
            return true;
        }
    }
    return false;
}

void crearLaboratorio(Laboratorio site[], int tamanoLaboratorio)
{
    system("cls");
    cout<<"COMPLETE EL FORMULARIO PARA REGISTRAR UN LABORATORIO\n";
    int dato = validarEspacioLaboratorio(site, tamanoLaboratorio);
    int codigo = 0;
    string nombre = "";
    int telefono = 0;
    string direccion = "";
    string email = "";
    if (dato >= 0 && dato < tamanoLaboratorio)
    {
        cout<<"INGRESE EL NOMBRE DEL LABORATORIO-->";
        cin>>nombre;
        cout<<"INGRESE EL CODIGO DEL LABORATORIO-->";
        cin>>codigo;
        if (!validarLaboratorio(site, tamanoLaboratorio, codigo))
        {
            site[dato].codigoLaboratorio = codigo;
            site[dato].nombreLaboratorio = nombre;
            cout<<"INGRESE EL TELEFONO DEL LABORATORIO-->";
            cin>>telefono;
            cout<<"INGRESE LA DIRECCION DEL LABORATORIO-->";
            cin>>direccion;
            cout<<"INGRESE EL EMAIL DEL LABORATORIO-->";
            cin>>email;
        }else{
            for (int i = 0; i < tamanoLaboratorio; i++)
            {
                if (site[i].codigoLaboratorio == codigo)
                {
                    cout<<"EL LABORATORIO->"<<site[i].nombreLaboratorio<<" CON CODIGO->"<<site[i].codigoLaboratorio<<"YA ESTA REGISTRADO\n";
                    cin.ignore();
                    break;
                }
            }
            return;
        }
        cout<<"SE HA REGISTRADO EL LABORATORIO\n";
    }
}

void limpiarLaboratorio()
{
    Laboratorio site[tamanoLaboratorio];
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

void verLaboratorios(Laboratorio site[], int tamanoLaboratorio){
    system("cls");
    cout<<"MLABORATORIOS GUARDADOS\n";
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        int codigoLaboratorio = 0;
        codigoLaboratorio = site[i].codigoLaboratorio;
        if (codigoLaboratorio != 0)
        {
            cout<<"\nLABORATORIO #"<<tamanoCliente+1<<"\n";
            cout<<"CODIGO    LABORATORIO-->"<<site[i].codigoLaboratorio<<"\n";
            cout<<"NOMBRE    LABORATORIO-->"<<site[i].nombreLaboratorio<<"\n";
            cout<<"TELEFONO  LABORATORIO-->"<<site[i].telefonoLaboratorio<<"\n";
            cout<<"DIRECCION LABORATORIO-->"<<site[i].direccionLaboratorio<<"\n";
            cout<<"EMAIL     LABORATORIO-->"<<site[i].emailLaboratorio<<"\n";
        }else{
        cout<<"INGRESE MAS LABORATORIOS. (# DE ESPACIOS DISPONIBLES:" << tamanoLaboratorio-i << ")\n";
        break;
        }    
    }
    cin.get();    
}

void menuLaboratorios(){
    int opcion = 0;
    Laboratorio site[tamanoLaboratorio];
    system("cls");
    cout<<"REGISTRAR LABORATORIO------(1)\n";
    cout<<"VER LABORATORIOS-----------(2)\n";
    cout<<"DIGITE UNA OPCION---------->";
    cin>>opcion;
    switch (opcion)
    {
    case 1:{
        crearLaboratorio(site, tamanoLaboratorio);
        break;
    }
    case 2:{
        verLaboratorios(site, tamanoLaboratorio);
        break;
    }
    default:{
        system("cls");
        cout<<"NINGUNA OPCION DISPONIBLE FUE SELECCIONADA.\n";
        cin.ignore();
        break;
    }
    cin.ignore();
    break;
}
}

void administrarLaboratorios(){
    limpiarLaboratorio();
    menuLaboratorios();
    cin.ignore();
}

void readLaboratorio()
{
}

void actualizarLaboratorio()
{
}

#endif // LABORATORIO_H

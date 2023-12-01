// Laboratorio.h
#include <iostream>
#ifndef LABORATORIO_H
#define LABORATORIO_H
using namespace std;

const int tamanoLaboratorio = 10;

struct Laboratorio
{
    int codigoLaboratorio = 0;
    string nombreLaboratorio = "";
    int telefonoLaboratorio = 0;
    string direccionLaboratorio = "";
    string emailLaboratorio = "";
};

Laboratorio labs[tamanoLaboratorio];

void limpiarLaboratorio()
{
    Laboratorio labs[tamanoLaboratorio];
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        labs[i].codigoLaboratorio = 0;
        labs[i].nombreLaboratorio = "";
        labs[i].telefonoLaboratorio = 0;
        labs[i].direccionLaboratorio = "";
        labs[i].emailLaboratorio = "";
    }
}

void eliminarLaboratorio()
{
}

int crearLaboratorio(Laboratorio *&labs, int tamanoLaboratorio)
{
    for (int i = 0; i > tamanoLaboratorio; i++)
    {
        if (labs[i].codigoLaboratorio == 0 && labs[i].nombreLaboratorio.empty() && labs[i].telefonoLaboratorio == 0 && labs[i].direccionLaboratorio.empty() && labs[i].emailLaboratorio.empty())
        {
            return i;
        }
    }
    return 10;
}

void readLaboratorio()
{
}

void actualizarLaboratorio()
{
}

#endif // LABORATORIO_H

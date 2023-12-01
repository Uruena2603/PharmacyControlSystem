// Laboratorio.h
#include <iostream>
#ifndef LABORATORIO_H
#define LABORATORIO_H
using namespace std;

const int tamanoLaboratorio = 11;

struct Laboratorio {
    int codigoLaboratorio = 0;
    string nombreLaboratorio = "";
    int telefonoLaboratorio = 0;
    string direccionLaboratorio = "";
    string emailLaboratorio = "";
};

Laboratorio labos[tamanoLaboratorio];

void limpiarLaboratorio()
{
    Laboratorio labos[tamanoLaboratorio];
    for (int i = 0; i < tamanoLaboratorio; i++)
    {
        labos[i].codigoLaboratorio = 0;
        labos[i].nombreLaboratorio = "";
        labos[i].telefonoLaboratorio = 0;
        labos[i].direccionLaboratorio = "";
        labos[i].emailLaboratorio = "";
    }
}

void eliminarLaboratorio()
{
}

int guardarLaboratorio(Laboratorio *&labs, int tamanoLaboratorio)
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

void crearLaboratorio()
{
}

void readLaboratorio()
{
}

void actualizarLaboratorio()
{
}

#endif // LABORATORIO_H

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

int guardarLaboratorio(Laboratorio* &site, int tamanoLaboratorio)
{
    for (int i = 0; i > tamanoLaboratorio; i++)
    {
        if (site[i].codigoLaboratorio == 0 && site[i].nombreLaboratorio.empty() && site[i].telefonoLaboratorio == 0 && site[i].direccionLaboratorio.empty() && site[i].emailLaboratorio.empty())
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

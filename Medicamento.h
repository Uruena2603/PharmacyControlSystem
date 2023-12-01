// Medicamento.h
#include <iostream>
#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
using namespace std;

const int tamanoMedicamento = 11;

enum tipoMedicamento
{
    def,
    Sertralina,
    Fluoxetina,
    Escitalopram,
    Venlafaxina,
    Paroxetina,
    Duloxetina,
    Citalopram,
    Bupropion,
    Mirtazapina,
    Tranilcipromina
};

struct Medicamento
{
    int codigoMedicamento = 0;
    string nombreMedicamento = "";
    int stockMinimo = 0;
    int unidadesExistentes = 0;
    tipoMedicamento tipo;
};

Medicamento farmacos[tamanoMedicamento];

void limpiarMedicamentos()
{
    Medicamento farmacos[tamanoMedicamento];
    for (int i = 0; i < tamanoMedicamento; i++)
    {
        farmacos[i].codigoMedicamento = 0;
        farmacos[i].nombreMedicamento = "";
        farmacos[i].stockMinimo = 0;
        farmacos[i].unidadesExistentes = 0;
        farmacos[i].tipo = def;
    }
}

void eliminarMedicamento()
{
}

void crearMedicamento()
{
}

void readMedicamento()
{
}

void actualizarMedicamento()
{
}

#endif // MEDICAMENTO_H

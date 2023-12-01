// Medicamento.h
#include <iostream>
#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
using namespace std;

enum tipoMedicamento
{
    Sertralina,
    Fluoxetina,
    Escitalopram,
    Venlafaxina,
    Paroxetina,
    Duloxetina,
    Citalopram,
    Bupropión,
    Mirtazapina,
    Tranilcipromina
};

struct medicamento
{
    int codigoMedicamento;
    string nombreMedicamento;
    int stockMin;
    int unidadesExistentes;
    tipoMedicamento tipo;
};

void pruebaMedicamento()
{
    cout << "Importando Medicamento\n";
}

#endif // MEDICAMENTO_H
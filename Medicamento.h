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
    Bupropion,
    Mirtazapina,
    Tranilcipromina
};

struct medicamento
{
    int codigoMedicamento = 0;
    string nombreMedicamento = 0;
    int stockMin = 0;
    int unidadesExistentes = 0;
    tipoMedicamento tipo;
};

void eliminarMedicamento(){

}

void crearMedicamento(){

}

void readMedicamente(){

}

void actualizarMedicamento(){

}


#endif // MEDICAMENTO_H

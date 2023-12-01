// Medicamento.h
#include <iostream>
#include <cstdlib> // Para la función rand
#include <ctime>   // Para la función time
#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
using namespace std;

// Varibles globales
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

int validarStockMedicamento(Medicamento farmacos[], int tamanoMedicamento)
{
    for(int i=0; i<tamanoMedicamento; i++){
        if(farmacos[i].codigoMedicamento == 0 && farmacos[i].nombreMedicamento.empty() && farmacos[i].stockMinimo == 0 && farmacos[i].unidadesExistentes && farmacos[i].tipo == def){
            return i;
        }
    }
    return 11;
}

bool validarMedicamento(Medicamento farmacos[], int tamanoMedicamento, int codigoMedicamento){
    for(int i=0; i<tamanoMedicamento; i++){
        if(farmacos[i].codigoMedicamento == codigoMedicamento){
            return true;
        }
    }
    return false;
}

tipoMedicamento enumToString(string medicamento){
    if (medicamento == "Sertralina") return Sertralina;
    if (medicamento == "Fluoxetina") return Fluoxetina;
    if (medicamento == "Escitalopram") return Escitalopram;
    if (medicamento == "Venlafaxina") return Venlafaxina;
    if (medicamento == "Paroxetina") return Paroxetina;
    if (medicamento == "Duloxetina") return Duloxetina;
    if (medicamento == "Citalopram") return Citalopram;
    if (medicamento == "Bupropion") return Bupropion;
    if (medicamento == "Mirtazapina") return Mirtazapina;
    if (medicamento == "Tranilcipromina") return Tranilcipromina;
    return def;
}

void crearMedicamento(Medicamento farmacos[], int tamanoMedicamento){
    system("cls");
    srand(time(0));
    cout<<"COMPLETE EL FORMULARIO PARA REGISTRAR UN MEDICAMENTO\n";
    int dato = validarStockMedicamento(farmacos,tamanoMedicamento);
    int codigo = 0;
    string nombre = "";
    char primeraLetraMayus = ' ';
    if(dato >=0 && dato < tamanoMedicamento){
        cout<<"INGRESE EL NOMBRE DEL MEDICAMENTO-->";
        cin>>nombre;
        primeraLetraMayus=toupper(nombre[0]);
        nombre[0]=primeraLetraMayus;
        cout<<"nomre:"<<nombre<<"\n";
        cout<<"INGRESE EL CODIGO DEL MEDICAMENTO-->";
        cin>>codigo;
        if(!validarMedicamento(farmacos,tamanoMedicamento,codigo)){
            farmacos[dato].codigoMedicamento = codigo;
            farmacos[dato].nombreMedicamento = nombre;
            farmacos[dato].stockMinimo = 10;
            int numeroDeUnidades = 0;
            numeroDeUnidades=1+rand()%(101-1);
            farmacos[dato].unidadesExistentes = numeroDeUnidades;
            string farmacoTmp = "";
            farmacoTmp=nombre;
            tipoMedicamento farmacoFinal = def;
            farmacoFinal=enumToString(farmacoTmp);
            cout<<"EL TIPO DE FARMACO ES-->"<<farmacoFinal<<"\n";
            farmacos[dato].tipo = farmacoFinal;
        }
        else{
            for(int i=0; i<tamanoMedicamento;i++){
                if(farmacos[i].codigoMedicamento == codigo){
                    cout<<"EL MEDICAMENTO->"<<farmacos[i].nombreMedicamento<<" CON CODIGO->"<<farmacos[i].codigoMedicamento<<" YA ESTA REGISTRADO\n";
                    cin.ignore();
                    break;
                }
            }
            return;
        }
        cout<<"SE HA REGISTRADO EL MEDICAMENTO\n";
    }
}
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

void verMedicamentos(Medicamento farmacos[], int tamanoMedicamento){
    system("cls");
    cout<<"MEDICAMENTOS GUARDADOS\n";
    for(int i=0; i<tamanoMedicamento; i++){
        int codigoMedicamento = 0;
        codigoMedicamento = farmacos[i].codigoMedicamento;
        if (codigoMedicamento != 0){
            cout<<"\nFARMACO #"<<tamanoCliente+1<<"\n";
            cout<<"CODIGO   MEDICAMENTO-->"<<farmacos[i].codigoMedicamento<<"\n";
            cout<<"NOMBRE   MEDICAMENTO-->"<<farmacos[i].nombreMedicamento<<"\n";
            cout<<"STOCK    MINIMO------->"<<farmacos[i].stockMinimo<<"\n";
            cout<<"UNIDADES ESISTENTES--->"<<farmacos[i].unidadesExistentes<<"\n";
            cout<<"TIPO     MEDICAMENTO-->"<<farmacos[i].tipo<<"\n";

        }
        else{
            cout << "\nINGRESE MAS MEDICAMENTOS. ( # DE ESPACIOS DISPONIBLES :" << tamanoMedicamento-i << ")\n";
            break; // Break para romper fors esta brutal.
        }
    }
    cin.get();
}

void menuMedicamentos(){
    int opcion = 0;
    Medicamento farmacos[tamanoMedicamento];
    system("cls");
    cout<<"REGISTRAR MEDICAMENTO------(1)\n";
    cout<<"VER MEDICAMENTOS-----------(2)\n";
    cout<<"DIGITE UNA OPCION---------->";
    cin>>opcion;
    switch (opcion){
        case 1:{
            crearMedicamento(farmacos,tamanoMedicamento);
            break;
        }
        case 2:{
            verMedicamentos(farmacos, tamanoMedicamento);
            break;
        }
        default:{
            system("cls");
            cout << "NINGUNA OPCION DISPONIBLE FUE SELECCIONADA.\n";
            cin.ignore();
            break;
        }
        cin.ignore();
        break;
    }
}

void administrarMedicamentos(){
    limpiarMedicamentos();
    menuMedicamentos();
    cin.ignore();
}
void readMedicamento()
{
}

void actualizarMedicamento()
{
}

#endif // MEDICAMENTO_H

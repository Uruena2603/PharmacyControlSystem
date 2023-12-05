// Medicamento.h
#include <iostream>
#include <cstdlib> // Para la función rand
#include <ctime>   // Para la función time
#include <vector>
#include "Laboratorio.h"
#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
using namespace std;

// Varibles globales
const int tamanoMedicamento = 11;

enum Medicamentos
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
    Tranilcipromina,
    Paracetamol, // jarabe
    Ibuprofeno, //Analgésico, jarabe
    Aspirina, //Analgésico
    Dextrometorfano, //Jarabe, cápsulas
    Guaifenesina, //Jarabe, tabletas)
    Fenilefrina, //Pastas, jarabe)
    Clorfenamina, //Pastas, jarabe)
    Loratadina, //Pastas, jarabe)
    AcetaminofenConCodeina, //- Analgésico Pastas
    Pseudoefedrina,
};
enum tipoMedicamento{
    deff,
    Analgesico,
    Jarabe,
    Inyeccion,
    Pastas,
    Pomada,
    Capsulas,
    Tabletas,
};
struct medicamentoInfo{
    tipoMedicamento categoria;
    Medicamentos nombre;
};
struct Medicamento
{
    int codigoMedicamento = 0;
    string nombreMedicamento = "";
    int stockMinimo = 0;
    int unidadesExistentes = 0;
    pair<tipoMedicamento,Medicamentos> tipo = make_pair(deff,def);
};

int validarGuardado(vector<Medicamento> &farmacos, int tamanoMedicamento)
{
    for (int i = 0; i < tamanoMedicamento; i++)
    {
        if (farmacos[i].codigoMedicamento == 0 && farmacos[i].nombreMedicamento.empty() && farmacos[i].stockMinimo == 0 && farmacos[i].unidadesExistentes == 0 && farmacos[i].tipo.first == deff && farmacos[i].tipo.second == def)
        {
            return i;
        }
    }
    return 11;
}

bool validarMedicamento(vector<Medicamento> &farmacos, int tamanoMedicamento, int codigoMedicamento)
{
    for (int i = 0; i < tamanoMedicamento; i++)
    {
        if (farmacos[i].codigoMedicamento == codigoMedicamento)
        {
            return true;
        }
    }
    return false;
}

Medicamentos stringToEnum(string medicamento)
{
    if (medicamento == "Sertralina")
        return Sertralina;
    if (medicamento == "Fluoxetina")
        return Fluoxetina;
    if (medicamento == "Escitalopram")
        return Escitalopram;
    if (medicamento == "Venlafaxina")
        return Venlafaxina;
    if (medicamento == "Paroxetina")
        return Paroxetina;
    if (medicamento == "Duloxetina")
        return Duloxetina;
    if (medicamento == "Citalopram")
        return Citalopram;
    if (medicamento == "Bupropion")
        return Bupropion;
    if (medicamento == "Mirtazapina")
        return Mirtazapina;
    if (medicamento == "Tranilcipromina")
        return Tranilcipromina;
    if (medicamento == "Paracetamol")
        return Paracetamol;
    if (medicamento == "Ibuprofeno")
        return Ibuprofeno;
    if (medicamento == "Aspirina")
        return Aspirina;
    if (medicamento == "Dextrometorfano")
        return Dextrometorfano;
    if (medicamento == "Guaifenesina")
        return Guaifenesina;
    if (medicamento == "Fenilefrina")
        return Fenilefrina;
    if (medicamento == "Clorfenamina")
        return Clorfenamina;
    if (medicamento == "Loratadina")
        return Loratadina;
    if (medicamento == "Acetaminofen con codeina")
        return AcetaminofenConCodeina;
    if (medicamento == "Pseudoefedrina")
        return Pseudoefedrina;
    return def;
}
string obtenerNombreTipo(tipoMedicamento tipo){
    switch (tipo){
        case Analgesico:
            return "Analgesico";
        case Jarabe:
            return "Jarabe";
        case Inyeccion:
            return "Inyeccion";
        case Pastas:
            return "Pastas";
        case Pomada:
            return "Pomada";
        case Capsulas:
            return "capsulas";
        default:
            return "Def";
    }
}
string obtenerNombreMedicamento(Medicamentos medicamento) {
    switch (medicamento) {
        case Sertralina:
            return "Sertralina";
        case Fluoxetina:
            return "Fluoxetina";
        case Escitalopram:
            return "Escitalopram";
        case Venlafaxina:
            return "Venlafaxina";
        case Paroxetina:
            return "Paroxetina";
        case Duloxetina:
            return "Duloxetina";
        case Citalopram:
            return "Citalopram";
        case Bupropion:
            return "Bupropion";
        case Mirtazapina:
            return "Mirtazapina";
        case Tranilcipromina:
            return "Tranilcipromina";
        case Paracetamol:
            return "Paracetamol";
        case Ibuprofeno:
            return "Ibuprofeno";
        case Aspirina:
            return "Aspirina";
        case Dextrometorfano:
            return "Dextrometorfano";
        case Pseudoefedrina:
            return "Pseudoefedrina";
        case Guaifenesina:
            return "Guaifenesina";
        case Fenilefrina:
            return "Fenilefrina";
        case Clorfenamina:
            return "Clorfenamina";
        case Loratadina:
            return "Loratadina";
        case AcetaminofenConCodeina:
            return "Acetaminofen";
        default:
            return "Def";
    }
}
void verMedicamentos(vector<Medicamento> &farmacos, int tamanoMedicamento)
{
    system("cls");
    cout << "MEDICAMENTOS GUARDADOS\n";
    for (int i = 0; i < tamanoMedicamento; i++)
    {
        int codigoMedicamento = 0;
        codigoMedicamento = farmacos[i].codigoMedicamento;
        if (codigoMedicamento != 0)
        {
            cout << "\nFARMACO #" << i + 1 << "\n";
            cout << "CODIGO   MEDICAMENTO-->" << farmacos[i].codigoMedicamento << "\n";
            cout << "NOMBRE   MEDICAMENTO-->" << farmacos[i].nombreMedicamento << "\n";
            cout << "STOCK    MINIMO------->" << farmacos[i].stockMinimo << "\n";
            cout << "UNIDADES EXISTENTES--->" << farmacos[i].unidadesExistentes << "\n";
            cout << "TIPO     MEDICAMENTO--\n" << "EL MEDICAMENTO -> "<<obtenerNombreMedicamento(farmacos[i].tipo.second)<<" ES DE TIPO -> "<<obtenerNombreTipo(farmacos[i].tipo.first)<<"\n";
        }
        else
        {
            cout << "\nINGRESE MAS MEDICAMENTOS. ( # DE ESPACIOS DISPONIBLES :" << tamanoMedicamento - i << ")\n";
            system("pause");
            break; // Break para romper fors esta brutal.
        }
    }
}

tipoMedicamento traerTipo(string tipo){
    if (tipo == "Sertralina" || tipo == "Fenilefrina" || tipo == "Loratadina")
        return Pastas;
    if (tipo == "Fluoxetina" || tipo == "Escitalopram" || tipo == "Venlafaxina" || tipo == "Paroxetina" || tipo == "Duloxetina" || tipo == "Citalopram" || tipo == "Bupropion" || tipo == "Mirtazapina" || tipo == "Tranilcipromina" || tipo == "Paracetamol" || tipo == "Clorfenamina" || tipo == "Pseudoefedrina")
        return Jarabe;
    if (tipo == "Ibuprofeno" || tipo == "Aspirina" || tipo == "Acetaminofen con codeina")
        return Analgesico;
    if (tipo == "Dextrometorfano")
        return Capsulas;
    if (tipo == "Guaifenesina")
        return Tabletas;
    return deff;
}
void crearMedicamento(vector<Medicamento> &farmacos, int tamanoMedicamento)
{
    system("cls");
    srand(time(0));
    color(15);
    cout << "COMPLETE EL FORMULARIO PARA REGISTRAR UN MEDICAMENTO\n\n";
    int dato = validarGuardado(farmacos, tamanoMedicamento);
    int codigo = 0;
    string nombre = "";
    char primeraLetraMayus = ' ';
    if (dato >= 0 && dato < tamanoMedicamento)
    {
        color(14); // Amarillo
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 14);
        cout << "+-------------------+----------------------+----------------+------------+\n";
        cout << "|   MEDICAMENTO     |     CATEGORIA        |   TIPO         |   CODIGO   |\n";
        cout << "+-------------------+----------------------+----------------+------------+\n";
        cout << "|   Sertralina      |    Ansiolitico       |   Pastas       |    1345    |\n";
        cout << "|   Paracetamol     |    Jarabe            |   Jarabe       |    1567    |\n";
        cout << "|   Fluoxetina      |    Ansiolitico       |   Jarabe       |    1820    |\n";
        cout << "|   Escitalopram    |    Ansiolitico       |   Jarabe       |    5679    |\n";
        cout << "|   Venlafaxina     |    Ansiolitico       |   Jarabe       |    2265    |\n";
        cout << "|   Paroxetina      |    Ansiolitico       |   Jarabe       |    4657    |\n";
        cout << "|   Duloxetina      |    Ansiolitico       |   Jarabe       |    2758    |\n";
        cout << "|   Citalopram      |    Ansiolitico       |   Jarabe       |    9756    |\n";
        cout << "|   Bupropion       |    Ansiolitico       |   Jarabe       |    7509    |\n";
        cout << "|   Mirtazapina     |    Ansiolitico       |   Jarabe       |    2003    |\n";
        cout << "|   Tranilcipromina |    Ansiolitico       |   Jarabe       |    4389    |\n";
        cout << "|   Ibuprofeno      |    Antiinflamatorio  |   Analgesico   |    1108    |\n";
        cout << "|   Aspirina        |    Antipiretico      |   Analgesico   |    5873    |\n";
        cout << "|   Dextrometorfano |    Supresor de tos   |   capsulas     |    3700    |\n";
        cout << "|   Guaifenesina    |    Expectorante      |   tabletas     |    0035    |\n";
        cout << "|   Fenilefrina     |    Descongestionante |   Pastas       |    2004    |\n";
        cout << "|   Clorfenamina    |    Antihistaminico   |   Jarabe       |    3609    |\n";
        cout << "|   Loratadina      |    Pastas            |   Pastas       |    3094    |\n";
        cout << "|   Acetaminofen    |    Analgesico        |   Analgesico   |    2889    |\n";
        cout << "|   Pseudoefedrina  |    Descongestionante |   Jarabe       |    1017    |\n";
        cout << "+-------------------+----------------------+----------------+------------+\n";
        color(15);
        cout << "\nINGRESE EL NOMBRE DEL MEDICAMENTO-->";
        cin >> nombre;
        primeraLetraMayus = toupper(nombre[0]);
        nombre[0] = primeraLetraMayus;
        cout << "INGRESE EL CODIGO DEL MEDICAMENTO-->";
        cin >> codigo;
        if (!validarMedicamento(farmacos, tamanoMedicamento, codigo))
        {
            farmacos[dato].codigoMedicamento = codigo;
            farmacos[dato].nombreMedicamento = nombre;
            farmacos[dato].stockMinimo = 10;
            int numeroDeUnidades = 0;
            numeroDeUnidades = 1 + rand() % (101 - 1);
            farmacos[dato].unidadesExistentes = numeroDeUnidades;
            medicamentoInfo info;
            info.categoria = traerTipo(nombre);
            info.nombre = stringToEnum(nombre);
            farmacos[dato].tipo = make_pair(info.categoria,info.nombre);

//            tipoMedicamento tipoFinalJarabe = deff;
//            Medicamentos medicamentoFinal = def;
//            tipoFinalJarabe = stringToEnum(farmacoTmp);
//            medicamentoFinal = obtenerNombreMedicamento(medicamentoFinal);
//            farmacos[dato].tipo.first = tipoFinalJarabe;
//            farmacos[dato].tipo.second = medicamentoFinal;
        }
        else
        {
            for (int i = 0; i < tamanoMedicamento; i++)
            {
                if (farmacos[i].codigoMedicamento == codigo)
                {
                    cout << "EL MEDICAMENTO-> " << farmacos[i].nombreMedicamento << " CON CODIGO-> " << farmacos[i].codigoMedicamento << " YA ESTA REGISTRADO\n";
                    cin.ignore();
                    system("pause");
                    break;
                }
            }
            return;
        }
        cout << "SE HA REGISTRADO EL MEDICAMENTO\n";
        system("pause");
    }
}

vector<Medicamento> farmacos(tamanoMedicamento);
void mostrarOpcionesMedicamento(int Set[], int numOpciones) {
    gotos(0, 0);
    color(15);
    cout << "--MENU DE MEDICAMENTOS (CRUD)\n\n";
    for (int i = 0; i < numOpciones; ++i) {
        color(Set[i]);
        switch (i + 1) {
            case 1:
                cout << "1. CREAR MEDICAMENTO\n";
                break;
            case 2:
                cout << "2. VER MEDICAMENTO\n";
                break;
            case 3:
                cout << "3. ACTUALIZAR MEDICAMENTO\n";
                break;
            case 4:
                cout << "4. ELIMINAR MEDICAMENTIO\n";
                break;
            case 5:
                cout << "5. SALIR\n";
                break;
        }
    }
    color(7);
}
void crudMedicamentos()
{
    bool flag=true;
    do{
    int Set[] = {15, 15, 15, 15, 15};
    int counter = 0;
    char llave;

    do {
        mostrarOpcionesMedicamento(Set, 5);

        llave = _getch();
        if (llave == 72 && counter > 1) {
            Set[counter - 1] = 15;
            counter--;
        }
        else if (llave == 80 && counter < 5) {
            Set[counter - 1] = 15;
            counter++;
        }
        else if (llave == '\r') {
            break;
        }
        Set[counter - 1] = 12;
    } while (true);
    gotos(0, 9);
    for (int i = 0; i < 20; ++i) {
        cout << "                                         ";  // Espacios en blanco para borrar
    }
    switch (counter) {
            case 1:
            {
                crearMedicamento(farmacos, tamanoMedicamento);
                flag=false;
                system("cls");
                break;
            }
            case 2:
            {
                verMedicamentos(farmacos, tamanoMedicamento);
                flag=false;
                system("cls");
                break;
            }
            case 3:
            {
                // actualizarMedicamento();
                flag=false;
                system("cls");
                break;
            }
            case 4:
            {
                //eliminarMedicamentos(farmacos, tamanoMedicamento);
                flag=false;
                system("cls");
                break;
            }
             case 5:
            {
                system("cls");
                color(15);
                cout<<"SALIENDO DEL CRUD MEDICAMENTO...\n";
                flag=true;
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
    }while(!flag);
}

void limpiarMedicamentos()
{
    for (int i = 0; i < tamanoMedicamento; i++)
    {
        farmacos[i].codigoMedicamento = 0;
        farmacos[i].nombreMedicamento = "";
        farmacos[i].stockMinimo = 0;
        farmacos[i].unidadesExistentes = 0;
        farmacos[i].tipo.first = deff;
        farmacos[i].tipo.second = def;
    }
}

void eliminarMedicamento()
{
}

void actualizarMedicamento()
{
}

#endif // MEDICAMENTO_H

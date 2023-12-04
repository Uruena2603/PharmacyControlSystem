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
    capsulas,
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
            cout << "TIPO     MEDICAMENTO--\n" << "EL MEDICAMENTO -> "<<farmacos[i].tipo.second<<" ES DE TIPO -> "<<farmacos[i].tipo.first<<"\n";
        }
        else
        {
            cout << "\nINGRESE MAS MEDICAMENTOS. ( # DE ESPACIOS DISPONIBLES :" << tamanoMedicamento - i << ")\n";
            system("pause");
            break; // Break para romper fors esta brutal.
        }
    }
}
string obtenerNombreMedicamento(Medicamentos medicamento) {
    switch (medicamento) {
        case Sertralina:
            return "Sertralina";
        case Fluoxetina:
            return "Fluoxetina";
        // ... otros medicamentos
        case Pseudoefedrina:
            return "Pseudoefedrina";
        default:
            return "Desconocido";
    }
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
        cout << "+-------------------+----------------------+----------------+\n";
        cout << "|   MEDICAMENTO     |     CATEGORIA        |   TIPO\t    |\n";
        cout << "+-------------------+----------------------+----------------+\n";
        cout << "|   Sertralina      |    Ansiolitico       |   Pastas       |\n";
        cout << "|   Paracetamol     |    Jarabe            |   Jarabe       |\n";
        cout << "|   Fluoxetina      |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Escitalopram    |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Venlafaxina     |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Paroxetina      |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Duloxetina      |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Citalopram      |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Bupropion       |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Mirtazapina     |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Tranilcipromina |    Ansiolitico       |   Jarabe       |\n";
        cout << "|   Ibuprofeno      |    Antiinflamatorio  |   Analgesico   |\n";
        cout << "|   Aspirina        |    Antipiretico      |   Analgesico   |\n";
        cout << "|   Dextrometorfano |    Supresor de tos   |   capsulas     |\n";
        cout << "|   Guaifenesina    |    Expectorante      |   tabletas     |\n";
        cout << "|   Fenilefrina     |    Descongestionante |   Pastas       |\n";
        cout << "|   Clorfenamina    |    Antihistaminico   |   Jarabe       |\n";
        cout << "|   Loratadina      |    Pastas            |   Pastas       |\n";
        cout << "|   Acetaminofen    |    Analgesico        |   Analgesico   |\n";
        cout << "|   Pseudoefedrina  |    Descongestionante |   Jarabe       |\n";
        cout << "+-------------------+----------------------+----------------+\n";
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
            string farmacoTmp = "";
            farmacoTmp = nombre;
            tipoMedicamento tipoFinal = deff;
            Medicamentos medicamentoFinal = def;
            medicamentoFinal = stringToEnum(farmacoTmp);

            farmacos[dato].tipo.first = tipoFinal;
            farmacos[dato].tipo.second = medicamentoFinal;
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
    int opcion = 0;
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

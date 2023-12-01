// Clientes.h
#include <iostream>
#ifndef CLIENTE_H
#define CLIENTE_H
using namespace std;

const int tamanoCliente = 11;

struct Cliente
{
    long cedulaCliente = 0;
    string nombreCliente = "";
    string direccionCliente = "";
    int celularCliente = 0;
    string fechaNacimientoCliente = "";
    string emailCliente = "";
};

Cliente client[tamanoCliente];

int validarEspacioCliente(Cliente client[], int tamanoCliente){
    for (int i = 0; i < tamanoCliente; i++)
    {
        if (client[i].cedulaCliente == 0 && client[i].nombreCliente.empty() && client[i].direccionCliente.empty() && client[i].celularCliente == 0 && client[i].fechaNacimientoCliente.empty() && client[i].emailCliente.empty())
        {
            return i;
        } 
    }
    return 11;
}

bool validarCliente(Cliente client[], int tamanoCliente, int cedulaCliente){
    for (int i = 0; i < tamanoCliente; i++)
    {
        if (client[i].cedulaCliente == cedulaCliente)
        {
            return true;
        }
    }
    return false;
}

void limpiarCliente()
{
    Cliente client[tamanoCliente];
    for (int i = 0; i < tamanoCliente; i++)
    {
        client[i].cedulaCliente = 0;
        client[i].nombreCliente = "";
        client[i].direccionCliente = "";
        client[i].celularCliente = 0;
        client[i].fechaNacimientoCliente = "";
        client[i].emailCliente = "";
    }
}

void eliminarCliente()
{
}

void readCliente()
{
}

void actualizarCliente()
{
}

void crearCliente()
{
}

#endif // CLIENTES_H
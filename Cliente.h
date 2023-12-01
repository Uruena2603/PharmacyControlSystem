// Clientes.h
#include <iostream>
#ifndef CLIENTE_H
#define CLIENTE_H
using namespace std;

const int tamanoCliente = 11;

struct Cliente
{
    long cedula = 0;
    string nombre = "";
    int telefono = 0;
    string direccion = "";
    int celular = 0;
    string fechaNacimiento = "";
};

Cliente client[tamanoCliente];

void limpiarCliente()
{
    Cliente client[tamanoCliente];
    for (int i = 0; i < tamanoCliente; i++)
    {
        client[i].cedula = 0;
        client[i].nombre = "";
        client[i].telefono = 0;
        client[i].direccion = "";
        client[i].celular = 0;
        client[i].fechaNacimiento = "";
    }
}

void eliminarCliente()
{
}

int guardarCliente(Cliente* &client, int tamanoCliente)
{
    for (int i = 0; i < tamanoCliente; i++)
    {
        if (client[i].cedula == 0 && client[i].nombre.empty() && client[i].telefono == 0 && client[i].direccion.empty() && client[i].celular == 0 && client[i].fechaNacimiento.empty())
        {
            return i;
        }
    }
    return 10;
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
#ifndef ADMINISTRADORARCHIVO_H
#define ADMINISTRADORARCHIVO_H
#include<iostream>
#include "ClassA.h"
#include <fstream>

using namespace std;

class AdministradorArchivo
{
private:
    string NombreArchivo;
public:
    AdministradorArchivo();
    AdministradorArchivo(string);
    void Guardar(ClassA,int &Cont,int Indices[][2],int &Index);
    void CargarIndices(int Indices[][2], int &Cont,int &Index);
    void MostrarElementos();
    void MostrarIndices(int Indices[][2],int Index);
    int ActualizaIndices(int Indices[][2], int &Cont,int A,int &Index);
    void GuardarIndices(int Indices[][2], int Cont,int Index);
    ClassA Buscar(int Indices[][2],int Buscado);
};

#endif // ADMINISTRADORARCHIVO_H

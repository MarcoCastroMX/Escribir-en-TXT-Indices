#include "AdministradorArchivo.h"

AdministradorArchivo::AdministradorArchivo()
{

}

AdministradorArchivo::AdministradorArchivo(string Nombre)
{
    NombreArchivo=Nombre;
}

void AdministradorArchivo::Guardar(ClassA Obj,int &Cont,int Indices[][2],int &Index)
{
    ifstream fin;
    ofstream fout;
    int A,B,C,D;
    if(Cont==0){
        fout.open(NombreArchivo,ios::binary);
        fout.write((char*)&Obj,sizeof(ClassA));
        Indices[Cont][0] = Obj.getA();
        Indices[Cont][1] = 0;
        fout.close();
        Cont++;
        Index++;
    }
    else{
        fin.open(NombreArchivo,ios::binary);
        if(fin.is_open()){
            int subCont=0;
            fin.read((char*)&A,sizeof(int));
            while(!fin.eof()){
                fin.read((char*)&B,sizeof(int));
                fin.read((char*)&C,sizeof(int));
                fin.read((char*)&D,sizeof(int));
                if(Obj.getA()<A){
                    char* Elem = new char[subCont*sizeof(ClassA)];
                    fin.seekg(0);
                    fin.read(Elem,subCont*sizeof(ClassA));
                    fout.open("Auxiliar.bin",ios::binary);
                    fout.write(Elem,subCont*sizeof(ClassA));
                    fout.write((char*)&Obj,sizeof(ClassA));
                    delete(Elem);
                    Elem = new char[sizeof(ClassA)];
                    fin.read(Elem, sizeof(ClassA));
                    while(!fin.eof())
                    {
                        fout.write(Elem, sizeof(ClassA));
                        fin.read(Elem, sizeof(ClassA));
                    }
                    fin.close();
                    fout.close();
                    remove(NombreArchivo.c_str());
                    rename("Auxiliar.bin", NombreArchivo.c_str());
                    int Anterior=ActualizaIndices(Indices,Cont,Obj.getA(),Index);
                    if(Cont%4==0){
                        Indices[Index][0] = Anterior;
                        Indices[Index][1] = Cont*sizeof(ClassA);
                        Index++;
                    }
                    Cont++;
                    return;
                }
                subCont++;
                fin.read((char*)&A,sizeof(int));
            }
            fout.open(NombreArchivo,ios::binary|ios::app);
            fout.write((char*)&Obj,sizeof(ClassA));
            fout.close();
            Cont++;
            if(Cont%5==0){
                Indices[Index][0] = Obj.getA();
                Indices[Index][1] = subCont*sizeof(ClassA);
                Index++;
            }
        }
    }
}

void AdministradorArchivo::CargarIndices(int Indices[][2], int &Cont,int &Index)
{
    ifstream fin;
    fin.open("Indices.bin", ios::binary);
    if(!fin.is_open()){
        Cont=0;
        Index=0;
        return;
    }
    fin.read((char*)&Cont, sizeof(int));
    fin.read((char*)&Index, sizeof(int));
    for(int i=0; i<Index; i++){
        fin.read((char*)&Indices[i][0], sizeof(int));
        fin.read((char*)&Indices[i][1], sizeof(int));
    }
    fin.close();
}

int AdministradorArchivo::ActualizaIndices(int Indices[][2], int &Cont,int A,int &Index)
{
    ifstream fin;
    ClassA Aux;
    int Anterior;
    fin.open(NombreArchivo,ios::binary);
    if(fin.is_open()){
        fin.read((char*)&Aux,sizeof(ClassA));
        bool Encontrado=false;

        while(!fin.eof()){
            if(Aux.getA()==A){
                Encontrado=true;
                Anterior=Aux.getA();
            }
            if(Encontrado==true){
                for(int i=0;i<Index;i++){
                    if(Indices[i][0]==Aux.getA()){
                        Indices[i][0]=Anterior;
                    }
                }
            }
            Anterior=Aux.getA();
            fin.read((char*)&Aux,sizeof(ClassA));
        }
    }
    fin.close();
    return Anterior;
}

void AdministradorArchivo::GuardarIndices(int Indices[][2], int Cont, int Index)
{
    ofstream fout;
    fout.open("Indices.bin", ios::binary);
    fout.write((char*)&Cont, sizeof(int));
    fout.write((char*)&Index, sizeof(int));
    for(int i=0; i<Index; i++){
        fout.write((char*)&Indices[i][0], sizeof(int));
        fout.write((char*)&Indices[i][1], sizeof(int));
    }
    fout.close();
}

ClassA AdministradorArchivo::Buscar(int Indices[][2], int Buscado)
{
    ifstream fin;
    ClassA Aux;
    fin.open(NombreArchivo,ios::binary);
    if(fin.is_open()){
        fin.read((char*)&Aux,sizeof(ClassA));
        while(!fin.eof()){
            if(Aux.getA()==Buscado){
                return Aux;
            }
            fin.read((char*)&Aux,sizeof(ClassA));
        }
    }
    return Aux;
}

void AdministradorArchivo::MostrarElementos()
{
    ifstream fin;
    fin.open(NombreArchivo,ios::binary);
    if(fin.is_open()){
        int A,B,C,D;
        fin.read((char*)&A,sizeof(int));
        while(!fin.eof()){
            fin.read((char*)&B,sizeof(int));
            fin.read((char*)&C,sizeof(int));
            fin.read((char*)&D,sizeof(int));
            cout<<A<<"-"<<B<<"-"<<C<<"-"<<D<<endl;
            fin.read((char*)&A,sizeof(int));
        }
    }
    fin.close();
}

void AdministradorArchivo::MostrarIndices(int Indices[][2],int Index)
{
    for(int i=0;i<Index;i++){
        cout<<Indices[i][0]<<"|"<<Indices[i][1]<<endl;
    }
}




















#include <iostream>
#include "ClassA.h"
#include "AdministradorArchivo.h"

using namespace std;

int main()
{
    int opc,Cont,Index;
    int Indices[100][2];
    AdministradorArchivo Admon("Archivo.bin");
    Admon.CargarIndices(Indices,Cont,Index);
    do{
        cout<<"\n  INDICES POR BLOQUES\t\n"<<endl;
        cout<<"1.-Insertar Objeto\n2.-Mostrar Elementos\n3.-Mostrar Indices\n4.-Buscar y Mostrar\n"<<endl;
        cout<<"Seleccione una Opcion: ";
        cin>>opc;
        switch(opc){
            case 1://inserta
            {
                int a,b,c,d;
                cout<<"Ingrese el Primer Elemento: ";
                cin>>a;
                cout<<"Ingrese el Segundo Elemento: ";
                cin>>b;
                cout<<"Ingrese el Tercer Elemento: ";
                cin>>c;
                cout<<"Ingrese el Cuarto Elemento: ";
                cin>>d;
                ClassA Obj(a,b,c,d);
                Admon.Guardar(Obj,Cont,Indices,Index);
                break;
            }
            case 2://mostrar elementos
            {
                if(Cont==0){
                    cout<<"No Existen Elementos"<<endl;
                    break;
                }
                else{
                    Admon.MostrarElementos();
                }
                break;
            }
            case 3://mostrar indices
            {
                if(Index==0){
                    cout<<"No Existen Elementos"<<endl;
                    break;
                }
                else{
                    Admon.MostrarIndices(Indices,Index);
                }
                break;
            }
            case 4://buscar y mostrar
            {
                if(Cont==0){
                    cout<<"No Existen Elementos"<<endl;
                    break;
                }
                else{
                    int Buscado;
                    cout<<"Ingrese llave a Buscar:"<<endl;
                    cin>>Buscado;
                    if(Admon.Buscar(Indices,Buscado).getA()!=Buscado){
                        cout<<"Elemento Inexistente"<<endl;
                    }
                    else{
                        cout<<Admon.Buscar(Indices,Buscado).ToString()<<endl;
                    }
                }
                break;
            }
        }
    }while(opc!=0);
    cout<<"\tSALIR"<<endl;
    Admon.GuardarIndices(Indices,Cont,Index);
    return 0;
}

#include "Rut.h"
#include "Fecha.h"
#include "Direccion.h"
#include "Licencia.h"
#include "Heap.h"
#include "LLS.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

vector <string> Split(string lineaseparada, char delimitador){
  vector<string> vector_interno;      
  stringstream linea(lineaseparada);
  string parteDelString;

  while(getline(linea, parteDelString, delimitador))
    vector_interno.push_back(parteDelString);
    
    return vector_interno; 
}

void CalcularPromedio(Nodo <Licencia> *N);

void ArchivoaLista(string licencias,Nodo <Licencia> *&N, int indice){
  
  ifstream archivo;
  string LineaObtenida;
  Licencia L1;
  Rut R;
  Direccion D;
  Fecha F;
  
  archivo.open("Licencias.txt",ios::in);    //Abre el archivo en modo lectura 
  
  if (archivo.fail()){
    cout<< "***El archivo no se pudo abrir***"<< endl;
    exit(1);
  }
  
  while(getline(archivo,licencias,'\n')){
    if(indice==0){  //condicion para que se salte la primera linea de texto
      indice++;
      continue;
    }
  
    //Asignar el dato respectivo de licencias.txt a la clase licencia
    vector<string> Data = Split(licencias,';'); 

    L1.Setid(atoi(Data[0].c_str()));

    R.Setnum(atoi(Data[1].c_str()));
    R.Setdv(Data[2]);
    L1.Setrut(R);

    L1.Setnombre(Data[3]);
    L1.Setpaterno(Data[4]);
    L1.Setmaterno(Data[5]);

    F.Setdd(atoi(Data[6].c_str()));
    F.Setmm(atoi(Data[7].c_str()));
    F.Setaa(atoi(Data[8].c_str()));
    L1.Setfnac(F);

    L1.Setsexo(atoi(Data[9].c_str()));
    
    D.Setdir(Data[10]);
    D.Setncasa(atoi(Data[11].c_str()));
    D.Setcom(Data[12]);
    L1.Setd(D);

    L1.SetposeeLicencia(atoi(Data[13].c_str()));
    L1.SettipoLicencia(Data[14][0]);
    L1.Setanteojos(atoi(Data[15].c_str()));
    
    agregarNodo(N,L1);
    
    indice++;
  }

  archivo.close();
}


void MenorEdad(Nodo<Licencia> *N) {
  
  Nodo <Licencia> *N1 = new Nodo<Licencia>;
  N1=NULL;
  Licencia L1;
  Heap<Licencia,int> A;
  Licencia ultimoDato;
  
  while(N!=NULL){
    L1=N->info;
    if(L1.GettipoLicencia()=='A'){
      Fecha fechaNacimiento = L1.Getfnac();
      A.agregar(L1,fechaNacimiento.Getaa());
    }
    N=N->link;
  }
  
  while (!A.vacia()) {
    ultimoDato=A.extraer();
  }
  agregarNodo(N1,ultimoDato);
  mostrarClase(N1);
}


void MostrarPorFecha(Nodo <Licencia> *N){
  Nodo <Licencia> *N1=new Nodo <Licencia>;
  N1=NULL;
  Licencia L1;
  Heap<Licencia,string> B;
  Licencia TipoB;
  int Dia,Mes,Año;
  
  cout<<"\n\u27a4 Ingrese El Día: ";
  cin>> Dia;
  cout<<"\n\u27a4 Ingrese El Mes: ";
  cin>> Mes;
  cout<<"\n\u27a4 Ingrese El Año: ";
  cin>> Año;
  
  while(N!=NULL){
    L1=N->info;
    if(L1.Getfnac().Getdd()>Dia && L1.Getfnac().Getmm()>Mes && L1.Getfnac().Getaa()>Año){
      if(L1.Getsexo()== 1 && L1.GettipoLicencia()=='C'){
        agregarNodo(N1,L1);
      }
    }
    N=N->link;
  }
  cout<<endl;
  mostrarMujeres(N1);
}


void PromedioLicencias(Nodo <Licencia>*N){
  
  Nodo <Licencia> *N1= new Nodo <Licencia>;
  N1=NULL;
  Licencia L1;
  Heap<Licencia,int> M;
  Licencia TipoB;
  Licencia DatoMujer;

  while(N!=NULL){
    L1=N->info;
    if(L1.GettipoLicencia()=='B' && L1.Getd().Getcom()=="SANTIAGO"){
      agregarNodo(N1,L1);
    }
    N=N->link;
  }
   CalcularPromedio(N1);
}

void Consolidado(Nodo<Licencia> *N){
  
  Nodo<Licencia> *N1 = new Nodo<Licencia>;
  N1 = NULL;
  Licencia L, X;
  string S;
  Rut R;

  while(N!=NULL){
    L=N->info;
    if(2023- L.Getfnac().Getaa()>24 && 2023- L.Getfnac().Getaa()<36){
      X=L; 
      agregarNodo(N1,X);
    }
    N=N->link;
  }
  
  mostrarConsolidado(N1);
}

void CalcularPromedio(Nodo <Licencia> *N){
  Licencia L;
  int i=0,Edad=0;
  int Prom=0;
  
  while(N!=NULL){
  L=N->info;
  i++;
  Edad += (2023 - L.Getfnac().Getaa());
  N=N->link;
  }
  Prom = Edad/i;
  cout <<"El promedio de las licencias de tipo B en la comuna de Santiago es: "<<Prom<<endl;
}

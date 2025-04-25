/*
    TALLER 4 EDD 
    MIEMBROS:       Josue
                    Angelo 
    FECHA:          domingo 14 de mayo 2023
    SECCION:        411
    PROFESOR:       MAURO CASTILLO
    LINK AL VDEO:   
 */

//Biblioteca
#include <iostream>
#include <string>

//Clases que ultilizaremos
#include "Licencia.h"
#include "Funciones.h"
#include "Direccion.h"
#include "Fecha.h"
#include "Rut.h"
#include "Heap.h"
#include "LLS.h"

using namespace std;
//Funcion main
int main() 
{
  Nodo <Licencia> *N=NULL;
  Licencia L1;
  int op;
  char opcion;
  int indice=0;
  string licencias ="Licencias.txt";


  ArchivoaLista(licencias,N,indice);
  mostrarClase(N);
  
  //Do While
  do{
    
    //Menu del prograna
    cout<<"****************************************************************************************"<<endl;
    cout << "\n-----Base de datos de Licencias Municipalidad de Pelotillehue-----\n"<<endl;
    cout<<"\n------------- MENU -------------"<<endl<<endl;
    cout << "\n\u27a4 [1] Mostrar los datos de la persona con menor edad y que posea Licencia Tipo A "<<endl;
    cout << "\n\u27a4 [2] Mostrar el promedio de licencias Tipo B en la comuna de Santiago "<<endl;
    cout << "\n\u27a4 [3] Mostrar Nombres de las mujeres con Licencia de tipo C despúes de una fecha determinada "<<endl;
    cout << "\n\u27a4 [4] Mostrar el Nombre y RUT de las personas que posean entre [25-35 años]  "<<endl;
    cout << "\n\u27a4 [5] Terminar"<<endl;
    cout<<"\n****************************************************************************************"<<endl;
    cout << "\nIngrese una opcion: ";
    cin >> op;
        
    if(op > 5)
    cout << "\n*** Opcion invalida. Porfavor digite nuevamente ***\n"<<endl;
        
    switch(op){
      
      case 1: //Licencia de tipo A cuyo usuario sea de menor edad
        
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout <<"Los datos de la persona cuya licencia del tipo A que tenga menor edad es: "<<endl<<endl;
        MenorEdad(N);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do{
          if(opcion=='N'){
            op=5;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
            if(opcion=='Y'){
              break;
            }
              
            else
              cout<<"Operacion invalida."<<endl;
          }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 2: //Promedio de edad de licencias tipo B de la comuna de Santiago
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        PromedioLicencias(N);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
         cout<<"\n\u27a4¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do{
          if(opcion=='N'){
            op=5;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
            if(opcion=='Y'){
              break;
            }
              
            else
              cout<<"Operacion invalida."<<endl;
          }while(opcion!='Y'||opcion!='N');
        
          
      break;
      
      case 3: //Licencias tipo C cuyas mujeres nacen después de una fecha
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout <<"\n\u27a4 Ingrese la fecha que desea: "<<endl<<endl;
        MostrarPorFecha(N);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do{
          if(opcion=='N'){
            op=5;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
            if(opcion=='Y'){
              break;
            }
              
            else
              cout<<"Operacion invalida."<<endl;
          }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 4: //Caso Mostrar el Nombre y RUT de las personas que posean entre [25-35 años]
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout <<"Licencias que cumplan edad en el rango [25-35 años] son: "<<endl<<endl;
        Consolidado(N);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        
        do{
          if(opcion=='N'){
            op=5;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
            if(opcion=='Y'){
              break;
            }
              
            else
              cout<<"Operacion invalida."<<endl;
          }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 5: //Caso Terminar el programa
        cout << "\n****Gracias por utilizar****"<<endl;
      break;
    }
    
    
  }while(op!=5);
}

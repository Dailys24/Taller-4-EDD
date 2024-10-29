#ifndef LLS_H
#define LLS_H
#include <iostream>
#include "Licencia.h"
using namespace std;

template <class T>
struct Nodo {
  T info;
  struct Nodo *link;
};

template <class T>
void agregarNodo( Nodo<T> *&L, T value ){
  Nodo<T> *p = new ( Nodo<T> );
  p->info = value;
  p->link = L;
  L = p;    
}

template <class T>
void mostrarNodo(Nodo<T> *L){
  while(L != NULL){
    cout<<L->info<<endl; 
    L = L->link;
  }
}

//función especializada para las clases
void mostrarClase(Nodo<Licencia> *L){
  while(L != NULL){
    L->info.mostrar(); 
    L = L->link;
  }
}
void mostrarConsolidado(Nodo<Licencia> *L){
  while(L != NULL){
    L->info.MostrarRango(L->info); 
    L = L->link;
  }
}
void mostrarMujeres(Nodo<Licencia> *L){
  while(L != NULL){
    L->info.MostrarMujer(); 
    L = L->link;
  }
}
#endif

///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "Cliente.h"
#include "Persona.h"

 void Cliente::cargar(){
     Persona::cargar();
 //  cout<<"Ingrese el 'ID' del Cliente por favor: ";
 //  cin>>_idCliente;
 _baneado = false;
 _estado = true;
 }

    void Cliente::mostrar(){
     Persona::mostrar();
 cout<<"El 'ID' del Cliente es: ";
 cout<<_idCliente<<endl;
 if(_baneado == 1){
    cout<<"Baneado: SI"<<endl;
 }else{
 cout<<"Baneado: NO"<<endl;
 }

    }

      int Cliente::getIDCliente(){
    return _idCliente;
    }

    void Cliente::setIDCliente(int idCliente){
    _idCliente = idCliente;
    }


    bool Cliente::getBaneado(){
    return _baneado;
    }

    void Cliente::setBaneado(bool baneado){
    _baneado = baneado;
    }


    void Cliente::setEstado(bool estado){
        _estado = estado;
     }

    bool Cliente::getEstado(){
    return _estado;
    }




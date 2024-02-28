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

#include "Empleado.h"

   void Empleado::cargar(){
        Persona::cargar();
 //   cout<<"Ingrese el 'ID' del Empleado por favor: ";
   // cin>>_idEmpleado;
     _estado = true;

    }

    void Empleado::mostrar(){
       Persona::mostrar();
    cout<<"El 'ID' del Empleado es: ";
    cout<<_idEmpleado<<endl;

    }

    int Empleado::getIDEmpleado(){
    return _idEmpleado;
    }

    void Empleado::setIDEmpleado(int idEmpleado){
    _idEmpleado = idEmpleado;
    }


    void Empleado::setEstado(bool estado){
        _estado = estado;
     }

    bool Empleado::getEstado(){
    return _estado;
    }


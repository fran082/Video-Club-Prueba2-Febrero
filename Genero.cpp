///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
#include<iomanip>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "Genero.h"
#include "cargarCadena.h"
#include "validaciones.h"

Genero::Genero(){
_idGenero = 0;
strcpy(_NombreGenero, "");
}

    void Genero::cargar(){
    cout<<"Nombre del genero: ";
    strcpy(_NombreGenero  , getNombrePropio().c_str() );
    cout<<"ID-Genero: ";
    cout<<_idGenero;
    cout<<endl;
    _estado = true;
    }

 void Genero::mostrar(){
 cout<<"\t\t";
cout<<setw(3)<<_idGenero;
cout<<setw(20)<<_NombreGenero<<"\t";
 cout<<endl;

 }

 void Genero::setIDGenero(int id){
     _idGenero = id;
    }

    int  Genero::getIDGenero(){
    return _idGenero;
    }

    void Genero::setNombreGenero(char name[50]){
    strcpy(_NombreGenero , name);
       }

    const char* Genero::getNombreGenero(){
    return _NombreGenero;
    }

     void Genero::setEstado(bool estado){
        _estado = estado;
     }

    bool  Genero::getEstado(){
    return _estado;
    }


    /*
const char* Genero::generoSeleccionado(int eleccion){
for(int i=0;i<5;i++){
    if(_idGenero[i]>0 && eleccion!=i){

    }else{
return _vNombreGenero[eleccion-1];

    }
}
}
*/




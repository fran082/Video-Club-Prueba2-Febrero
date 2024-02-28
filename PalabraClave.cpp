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

#include "PalabraClave.h"
#include "cargarCadena.h"
#include "validaciones.h"

PalabraClave::PalabraClave(){

}

void PalabraClave::cargar(){
cout<<"Ingrese el 'ID' de la pelicula que quiere agregar una palabra clave para identificarla"<<endl;

cin>>_idVideo;
cout<<"Ingrese la palabra o palabras que sirva para identificar la pelicula: ";
cargarCadena(_palabraClave , 50);

_estado = true;
cout<<endl;
}


void PalabraClave::mostrar(){
if(_estado == true){
//cout<<"El'ID' de la pelicula es"<<endl;
//cout<<_idVideo;
cout<<"#";
cout<<_palabraClave;

}
cout<<endl;
}


void PalabraClave::setIDVideo(int idvideo){
_idVideo = idvideo;
}

void PalabraClave::setPalabraClave(char wordClave[50]){
  strcpy(_palabraClave , wordClave);
}

void PalabraClave::setEstado(int estado){
    _estado = estado;
}

int PalabraClave::getIDVideo(){
 return _idVideo;
}

const char* PalabraClave::getPalabraClave(){
 return _palabraClave;
}

bool PalabraClave::getEstado(){
    return _estado;
}

void PalabraClave::setIDPalabraClave(int idPalabraClave){
_idPalabraClave = idPalabraClave;
}

int PalabraClave::getIDPalabraClave(){
return _idPalabraClave;
}

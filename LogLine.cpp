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

#include "LogLine.h"
#include "cargarCadena.h"

LogLine::LogLine(){

}


void LogLine::cargar(){
cout<<"Ingrese el ID-Video al que quiere agregarle un #hashtag de recomendacion";
cin>>_idVideoLogLine;
cout<<"Escriba por favor una palabra o palabras que sirvan para recomendar la pelicula";
cargarCadena(_palabraRecomendacion , 50);
cout<<endl<<endl;
}


void LogLine::mostrar(){
cout<<"El ID-Video ";
cout<<_idVideoLogLine;
cout<<" posee el hashtag de recomendacion #";
cout<<_palabraRecomendacion ;
cout<<endl<<endl;
}


void LogLine::setIDVideoLogLine( int idVideoLogLine){
 _idVideoLogLine = idVideoLogLine;
}

int LogLine::getIDVideoLogLine(){
return _idVideoLogLine;
}

void LogLine::setPalabraRecomendacion(char palabraRecomendacion[50]){
strcpy(_palabraRecomendacion , palabraRecomendacion);
}

const char* LogLine::getPalabraRecomendacion(){
return _palabraRecomendacion;
}



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

#include "Persona.h"
#include "cargarCadena.h"
#include "validaciones.h"

Persona::Persona(){

}

void Persona::cargar(){
cout<<"Apellido y nombre: ";
 strcpy(_apellidoYNombre , getNombrePropio().c_str());
//cargarCadena(_apellidoYNombre, 50);
cout<<"DNI: ";
 //cin>>_dni;
_dni = getIntegerSinComa(1000000, 60000001);
int v_normal[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int v_biesto[12] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
cout<<"Fecha de nacimiento"<<endl;//(";
int dia, mes ,anio;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}

//anio = getIntegerSinComa(1950, 2051) ;
 Fecha nacimiento(dia, mes, anio);
   _nacimiento = nacimiento;
//cout<<").";
cout<<"Ingrese el sexo ('M' o 'F'): ";
char mof;
    cin>>mof;

while(mof != 'M' && mof != 'm' && mof != 'F' && mof != 'f') {
    cin>>mof;
}

_sexo = mof;
cout<<"Ingrese domicilio de la persona : ";
//cargarCadena(_domicilio, 50);
 strcpy( _domicilio , getDireccion().c_str());
//cout<<")";
cout<<"Telefono: +54 ";
cin>>_telefono ;
cout<<"Cargar E-Mail: ";
cargarCadena(_email, 50);

}


void Persona::mostrar(){
cout<<"Apellido y nombre:    ";
cout<<_apellidoYNombre;
cout<<endl<<"DNI: ";
cout<<_dni<<endl;
cout<<"Fecha de nacimiento (";
cout<<_nacimiento.toString();

cout<<")."<<endl;
cout<<"Sexo ('M' o 'F'): ";
cout<<_sexo<<endl;
cout<<"Domicilio(";
cout<<_domicilio;
cout<<")"<<endl;
cout<<"Telefono: +54 ";
cout<<_telefono<<endl;
cout<<"Cargar E-Mail: ";
cout<<_email;
cout<<endl;

}


void Persona::setDNI(int dni){
_dni = dni;
}

int Persona::getDNI(){
return _dni;
}

void Persona::setSexo(char sexo){
_sexo = sexo;
}

const char* Persona::getSexo(){
 return &_sexo;
}

void Persona::setNacimiento(int dia, int mes, int anio){
_nacimiento.setAnio(anio);
_nacimiento.setMes(mes);
_nacimiento.setDia(dia);
}

Fecha Persona::getNacimiento(){
return _nacimiento;
}

void Persona::setApellidoYNombre(char apellidoYNombre[50]){
strcpy(_apellidoYNombre ,  apellidoYNombre);
}

const char* Persona::getApellidoYNombre(){
 return _apellidoYNombre;
}

void Persona::setDomicilio(char domicilio[50]){
strcpy(_domicilio , domicilio);
}

const char* Persona::getDomicilio(){
 return _domicilio;
}

void Persona::setTelefono(long long telefono){
_telefono = telefono;
}

long long Persona::getTelefono(){
 return _telefono;
}

void Persona::setEmail(char email[50]){
strcpy(_email , email);
}

const char* Persona::getEmail(){
 return _email;
}

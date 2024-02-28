///Ejercicio:
///Autor:
///Fecha:
///Comentario:
# include<iostream>
#include <vector>
#include <string>

using namespace std;


#include "FechaHorario.h"
#include "Fecha.h"
#include "Horario.h"

Fecha FechaHorario::getFecha(){
    return _fecha;
}
Horario FechaHorario::getHorario(){
    return _horario;
}
void FechaHorario::setFecha(Fecha fecha){
    _fecha = fecha;
}
void FechaHorario::setHorario(Horario horario){
    _horario = horario;
}
//Agregado por mí , comprobar
void FechaHorario::setFechaHorario(FechaHorario fechahorario){
    _fecha = fechahorario.getFecha();
    _horario = fechahorario.getHorario();
}

void FechaHorario::setFecha(int dia, int mes, int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}
void FechaHorario::setHorario(int segundo, int minuto, int hora){
    _horario = Horario(segundo, minuto, hora);
}

FechaHorario::FechaHorario(Fecha fecha, Horario horario){
    _fecha = fecha;
    _horario = horario;
}

FechaHorario::FechaHorario(){
    ///no existe el 0 por ejemplo 05 horas y 07 minutos con 09 segundos es 5:7:9
    /*
    _fecha.setDia(1);
    _fecha.setMes(1);
    _fecha.setAnio(2030);
    _horario.setSegundo(01);
    _horario.setMinuto(01);
    _horario.setHora(01);
    */
}

FechaHorario::FechaHorario(int dia, int mes, int anio, int segundo, int minuto, int hora){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
    _horario.setSegundo(segundo);
    _horario.setMinuto(minuto);
    _horario.setHora(hora);

}
std::string FechaHorario::toString(){
    std::string valorADevolver;
    valorADevolver = _fecha.toString() + " " + _horario.toString();
    return valorADevolver;
}

std::string FechaHorario::toStringSinHorario(){
    std::string valorADevolver;
    valorADevolver = _fecha.toString() ;
    return valorADevolver;
}



int FechaHorario::DiferenciaDeDias(FechaHorario FechaAlquiler,  FechaHorario FechaDevolucion){
 int vMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 ///Chequear si el a�o es bisiesto
int acumulador=0;
bool primero = false;
bool segundo = false;
//Ficticia   >     Real
int PrimerDiaAlquiler = FechaAlquiler.getFecha().getDia();
int UltimosDiasAlquiler = FechaDevolucion.getFecha().getDia();
int diferencia_de_anios = FechaDevolucion.getFecha().getAnio() - FechaAlquiler.getFecha().getAnio() ;
cout << endl<<endl<<diferencia_de_anios<<" ES EL ANIO DE DEVOLUCION MENOS (-) EL ANIO DE ALQUILER)"<<endl<<endl;
system("pause");
int anio_alquiler = FechaAlquiler.getFecha().getAnio() ;
int anio_devolucion = FechaDevolucion.getFecha().getAnio() ;
int mes_enquese_alquilo = FechaAlquiler.getFecha().getMes() ;
int mes_enquese_devolvio = FechaDevolucion.getFecha().getMes() ;
int mesDelFORINICIO = mes_enquese_alquilo;
int mesDelFORFINAL = mes_enquese_devolvio;
int variable_cout;
int contador=0;

 std::vector<std::string> meses = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    system("cls");
if( diferencia_de_anios > 0 ){

    for(int k = anio_alquiler ; k < anio_devolucion+1 ; k++){

    cout<<"ANIO:: "<<k<<endl;

            if( k == anio_alquiler) {
            mesDelFORINICIO = mes_enquese_alquilo;
            primero = true;
            }else{ mesDelFORINICIO = 1;}


            mesDelFORFINAL = 12;


       for(int i = mesDelFORINICIO-1 ; i < mesDelFORFINAL ; i++){
            cout<<"Mes:: "<<i+1<<endl;

              if( k == anio_devolucion  ){
            mesDelFORFINAL = mes_enquese_devolvio;
            if(  i == mes_enquese_devolvio-1 ){
            segundo = true;
            }
            }

       if( primero == false && segundo == false ){
        acumulador += vMes[i];

            variable_cout = vMes[i];
        cout<<"El mes " <<meses[i]<<"  "<<i+1<<" tiene "<<variable_cout<<"   (IF = false-false | anio intermedios)"<<endl;
        cout<<"El ACUMULADOR VALE : "<<acumulador<<endl;

       }

       if(primero == true ){
        acumulador += vMes[i] - PrimerDiaAlquiler;
        variable_cout = vMes[i];
        cout<<"El mes " <<meses[i]<<"  "<<i+1<<" tiene "<<variable_cout<<"   (IF = primer anio)"<<endl;
        cout<<"El ACUMULADOR VALE : "<<acumulador<<endl;
        primero = false;
       }
       if( segundo == true  ){
        acumulador += UltimosDiasAlquiler ;
        segundo = false;

            variable_cout = vMes[i];
            cout<<"Esto forma parte del ultimo anio '"<<k<<"'."<<endl;
        cout<<"El mes " <<meses[i]<<"  "<<i+1<<" tiene "<<variable_cout<<"   (IF = ultio anio)"<<endl;
        cout<<"El ACUMULADOR VALE : "<<acumulador<<endl;

       }
}

                }
            }


///Hacer el codigo si el a�o de devoluciony alquiler es el mismo
///NO LLLAMAR MUCUHO A FUNCIONES, DEJARLAS EN VARIABLES
primero = true;
segundo = true;
int bandera = false;
if( diferencia_de_anios == 0 ){
   for(int i = mes_enquese_alquilo -1 ; i <= mes_enquese_devolvio -1 ; i++){



       if( primero == true ){
    acumulador += vMes[i] - PrimerDiaAlquiler;
    primero = false;

        variable_cout = vMes[i];
        cout<<"El mes " <<meses[i]<<"  "<<i+1<<" tiene "<<variable_cout<<"   (IF = comienzo mes)"<<endl;
        cout<<"El ACUMULADOR VALE : "<<acumulador<<endl;
    bandera = true;
    if( i == mes_enquese_devolvio-1 ){
        acumulador = 0;
        acumulador += UltimosDiasAlquiler - PrimerDiaAlquiler;
        return acumulador; }
   }

   if( i == mes_enquese_devolvio-1 ){
    acumulador += UltimosDiasAlquiler ;
        variable_cout = vMes[i];
        cout<<"El mes " <<meses[i]<<"  "<<i+1<<" tiene "<<variable_cout<<"   (IF = final mess)"<<endl;
        cout<<"El ACUMULADOR VALE : "<<acumulador<<endl;
    segundo = false;
    bandera = true;
   }else{   if(primero == false && segundo==true && bandera==false){
       acumulador += vMes[i] ;
               variable_cout = vMes[i];
            cout<<"El mes " <<meses[i]<<"  "<<i+1<<" tiene "<<variable_cout<<"   (IF = meses intermedios)"<<endl;
        cout<<"El ACUMULADOR VALE : "<<acumulador<<endl;

            }
        }

        bandera = false;
    }
}
return acumulador;

}

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

#include "validaciones.h"
#include "cargarCadena.h"
#include "Alquiler.h"
#include "ArchivoVideo.h"
#include "ArchivoAlquiler.h"
#include "Horario.h"
#include "Fecha.h"
#include "ArchivoCliente.h"
#include "ArchivoEmpleado.h"
#include "ArchivoCategoria.h"


Alquiler::Alquiler(){

}


Alquiler::Alquiler(bool estado){
_estado = false;
}

Alquiler::Alquiler(Fecha fecha, Horario horario){
_fechaDeAlquiler.setFecha(fecha);
_fechaDeAlquiler.setHorario(horario);
}

void Alquiler::setFechaDeAlquiler(FechaHorario momento_de_alquiler){
_fechaDeAlquiler = momento_de_alquiler;
}
void Alquiler::setFechaDeAlquilerSoloConDia(int dia){
_fechaDeAlquiler.setFecha(dia,10,2023);
_fechaDeAlquiler.setHorario(0,1,2);
}

void Alquiler::setIDAlquiler(int idAlquiler){
 _idAlquiler = idAlquiler;
}


void Alquiler::setIDVideoAlquilado(int id){
 _idVideoAlquilado = id;
}

     void Alquiler::setDevolucion(bool devolucion){
        _devolucion = devolucion;
     }

     bool Alquiler::getDevolucion(){
     return _devolucion;
     }

 void Alquiler::setIDEmpleado(int idEmpleado){
 _idEmpleado = idEmpleado;
}

 int Alquiler::getIDEmpleado(){
 return _idEmpleado;
}


 int Alquiler::getIDVideoAlquilado(){
 return _idVideoAlquilado;
 }


void Alquiler::setIDCliente(int id){
_idCliente = id;
}


  int Alquiler::getIDCliente(){
  return _idCliente;
  }

    int Alquiler::getIDAlquiler(){
  return _idAlquiler;
  }

  float Alquiler::getInteresComun(){
  return _interes;
  }

  float Alquiler::getInteresCompuesto(){
  return _interesCompuesto;
  }

   void Alquiler::setInteresComun(float interes_comun){
   _interes = interes_comun;
   }

     void Alquiler::setInteresCompuesto(float interes_compuesto){
     _interesCompuesto = interes_compuesto;
     }

   void Alquiler::setImporte(float dinero){
     _importe = dinero;
    }


/*
void Alquiler::modificarFecha(Fecha &Inventada){

Inventada.setDia(1);
Inventada.setMes(10);
Inventada.setAnio(2023);
//setFechaDeAlquiler(AlquilerFalso);
}
*/

    FechaHorario Alquiler::getFechaHorarioAlquiler(){
    return _fechaDeAlquiler;
    }

    void Alquiler::setRetraso(bool retraso){
    _retraso = retraso;
    }

    bool Alquiler::getRetraso(){
    return _retraso;
    }

    float Alquiler::getImporte(){
    return _importe;
    }

        void Alquiler::setApellidoYNombre(char apellidoYNombre[50]){
        strcpy(_nombreYapellido ,  apellidoYNombre);
        }

        const char* Alquiler::getApellidoYNombre(){
        return _nombreYapellido;
        }

    void Alquiler::setFechaHorarioDevolucion(FechaHorario dia_devolucion){
  _fechaDeDevolucion = dia_devolucion;
  //  _fechaDeDevolucion.setFecha.(dia_devolucion.getFecha());
  //  _fechaDeDevolucion.setHorario(dia_devolucion.getHorario());
    }

    FechaHorario Alquiler::getFechaHorarioDevolucion(){
    return _fechaDeDevolucion;
    }

    void Alquiler::setEstado(bool estado){
    _estado = estado;
    }

    bool Alquiler::getEstado(){
    return _estado;
    }



    void  Alquiler::cargarAlquiler( int &idCliente , int &id_aux){
cout<<"EL ID-CLIENTE ES '"<<idCliente<<"' y el ID-ALQUILER ES '"<<id_aux<<"'"<<endl<<endl;
ArchivoVideo DisponibilidadPelicula;
ArchivoCliente DoyID;
ArchivoEmpleado ArcEmpleado;
ArchivoCategoria ArcCategoriaYInteres;
ArchivoAlquiler ArcAlquiler;
///Si tiene de deuda pagar un interes tiene que pagarlo para alquilar y tambien devolver lo que posee
//int id_aux;
//    cout<<"Ingrese el ID de la pelicula a ALQUILAR: ";
//cin>>id_aux;
 _idVideoAlquilado = id_aux;
 DisponibilidadPelicula.alquilerPorID(id_aux);
 char nombrePelicula[50];
strcpy( nombrePelicula ,DisponibilidadPelicula.devuelveNombrePeliculaACambioDeID(id_aux).c_str());
   cout<<"El nombre de la pelicula es: '"<<nombrePelicula<<"'"<<endl;
   //  setIDVideoAlquilado(id_aux);
///cout<<endl;cout<<"Apellido y Nombre del Cliente:    ";
///cargarCadena(_nombreYapellido, 50);
///setIDCliente( DoyID.devuelveIDClienteACambioDeName(_nombreYapellido));

//cout<<"Ingrese el ID-Cliente: ";
//cin>>idCliente;
_idCliente = idCliente;

if(_idCliente != -1 && _idCliente != -2){
    strcpy( _nombreYapellido , DoyID.devuelveNombreYApellidoAcambioDeID(_idCliente));

}

/*
  int puede_alquilar =  ArcAlquiler.noPuedeAlquilar(_idCliente);
  cout<<"El cliente puede alquilar ?????????????? RTA: "<<puede_alquilar<<endl;
    if(puede_alquilar == -1){
        system("cls");
        cout<<"No existe el ArchivoAlquiler. Restaure el Backup Alquiler por favor para seguir Administrando Alquileres."<<endl;
        system("pause");
    }
    if( puede_alquilar == -2){
    system("cls");
cout << "El cliente '" << _nombreYapellido << "' no puede alquilar mas peliculas hasta que devuelva las que tiene en su posesion. Por favor, realice la devolucion para proceder con un nuevo alquiler." << endl;
    ArcAlquiler.cancelarAlquilerEnProceso(_idCliente , _idVideoAlquilado);
    system("pause");

    return;
    }
 */

if(_idCliente != -1){
cout<<"El ID-Cliente es : "<<_idCliente<<endl;
}
/*
else if(_idCliente!= -2){
//cout<<"Por favor ingrese el ID-Cliente  : ";
DoyID.agregarRegistro();
//cin>>_idCliente;
//Aca tiene que cargar el cliente porque no existe, noe sta registrado
}
*/

cout<<"Y el nombre del cliente es "<<_nombreYapellido<<endl;
    cout<<"Esta alquilando la pelicula... ";// Ingrese el ''Id-Alquiler'' : ";
  //  cin>>_idAlquiler;
    cout<<DisponibilidadPelicula.devuelveNombrePeliculaACambioDeID(_idVideoAlquilado)<<endl;
//Alquiler normal. Significa que no la tiene alquilada
//Fecha DiaRetiro;
Horario HoraDeRetiro;
Fecha FechaActual;
//FechaHorario MomentoDeRetiro(DiaRetiro , HoraDeRetiro);
int v_normal[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int v_biesto[12] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
cout<<"Desea Cargar Una fecha de alquiler diferente a la de hoy o la actual ?"<<endl;
cout<<"1. Fecha De Hoy"<<endl;
cout<<"2. Fecha ingresada por el usuario"<<endl;
int dia5, mes5, anio5;
int opc;
bool si = true;
while(si==true){
        cin>>opc;
switch(opc){

            case 1:
              _fechaDeAlquiler.setFecha(FechaActual);
              _fechaDeAlquiler.setHorario(HoraDeRetiro);
            cout<< _fechaDeAlquiler.toStringSinHorario();
            cout<<endl;
            cout<< _fechaDeDevolucion.toStringSinHorario();
            system("pause");

              si = false;
                break;

            case 2:
cout<<"Anio:";
 anio5 = getIntegerSinComa(1950 , 2050) ;
cout<<"Mes:";
 mes5 = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio5) && mes5 == 2){
cout<<"Dia:";
 dia5 = getIntegerSinComa(1 , v_biesto[ mes5 - 1 ]) ;
}else{
cout<<"Dia:";
 dia5 = getIntegerSinComa(1 , v_normal[ mes5 - 1 ]) ;
}
_fechaDeAlquiler.setFecha(dia5, mes5, anio5);
_fechaDeAlquiler.setHorario(HoraDeRetiro);
  cout<< _fechaDeAlquiler.toStringSinHorario();
  cout<<endl;
  cout<< _fechaDeDevolucion.toStringSinHorario();
            system("pause");
            si = false;
                break;

            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
}



//_importe =  DisponibilidadPelicula.devolverImporteAcambioIDVideo(_idVideoAlquilado);
int nro_categoria;
 nro_categoria =  DisponibilidadPelicula.devolverObjVideo(_idVideoAlquilado).getTipoDeCategoria();
 cout<<"EL NRO. de CATEGORIA ES : "<<nro_categoria<<endl;
_importe = ArcCategoriaYInteres.devolverObjCategoriaYInteres(nro_categoria).getPrecioCategoria();
cout<<"El importe $ de la pelicula $ es de $"<<_importe<<"."<<endl;
_interes = ArcCategoriaYInteres.devolverObjCategoriaYInteres(nro_categoria).getInteresComun();
_interesCompuesto = ArcCategoriaYInteres.devolverObjCategoriaYInteres(nro_categoria).getInteresCompuesto();

_retraso = 0;
_devolucion = 0;

_fechaDeDevolucion.setFecha(1, 1, 1951);

///Validar que el id del empleado ingresado sea valido
int maxIDEmpleado , minIDEmpleado;
 maxIDEmpleado = ArcEmpleado.devolverIDMaximo();
 minIDEmpleado = ArcEmpleado.devolverIDMinimo();

cout<<"Ingrese su 'ID' de Empleado: ";
_idEmpleado = getIntegerSinComa( minIDEmpleado , maxIDEmpleado );
while(ArcEmpleado.empleadoExiste(_idEmpleado) != 1){
    cout<<"ID-Empleado inexistente"<<endl;
    _idEmpleado = getIntegerSinComa( 0 , maxIDEmpleado );
}
char nombreDelEmpleado[50];
strcpy( nombreDelEmpleado , ArcEmpleado.devuelveNameACambioDeIDEmpleado(_idEmpleado));
cout<<"Nombre del empleado: "<<nombreDelEmpleado;
///cout<<"NO HAY STOCK DE...Explicar poruqe no hay stock .
///Ej nombre de pelicula sin stock y su 'id' para verificar
///que se ingreso correctamente yno fue un error
_estado=true;
    }


void  Alquiler::cargarDevolucion(){
ArchivoAlquiler ArcAlquiler;
ArchivoVideo DisponibilidadPelicula;
ArchivoCliente DoyID;
Alquiler AlquilerInicial;
ArchivoCategoria ArcCategoriaYInteres;

int id_aux;

 int maxIDVideo, minIDVideo;
 int valor_funcion_video;
 maxIDVideo = DisponibilidadPelicula.devolverIDMaximo();
 minIDVideo = DisponibilidadPelicula.devolverIDMinimo();
   cout<<"Ingrese el ID de la pelicula a DEVOLVER: ";
     id_aux =  getIntegerSinComa( minIDVideo , maxIDVideo );
 valor_funcion_video = DisponibilidadPelicula.buscarPeliculaPorIDVideoParametro(id_aux) ;
   while( valor_funcion_video != 1 && valor_funcion_video != -1){
    cout<<"ID-Pelicula inexistente"<<endl;
     id_aux =  getIntegerSinComa( minIDVideo , maxIDVideo );
    valor_funcion_video = DisponibilidadPelicula.buscarPeliculaPorIDVideoParametro(id_aux) ;
   }
  _idVideoAlquilado = id_aux;
 if(valor_funcion_video == -1){
    system("cls");
    system("pause");
    cout<<endl;
    cout<<"EL ARCHIVO 'Videos.dat' NO EXISTE. POR FAVOR RESTAURE EL BACKUP"<<endl<<endl<<endl;
    return;
   }


  int maxIDCliente, minIDCliente;
int valor_funcion_cliente ;
 maxIDCliente = DoyID.devolverIDMaximo();
 minIDCliente = DoyID.devolverIDMinimo();
   cout<<"Ingrese el ID-Cliente: ";
     _idCliente =  getIntegerSinComa( minIDCliente , maxIDCliente );
valor_funcion_cliente = DoyID.clienteExiste(_idCliente);
   while( valor_funcion_cliente != 1 && valor_funcion_cliente != -1){
    cout<<"ID-Cliente inexistente"<<endl;
     _idCliente =  getIntegerSinComa( minIDCliente , maxIDCliente );
     valor_funcion_cliente = DoyID.clienteExiste(_idCliente);
   }
   if(valor_funcion_cliente == -1){
    system("cls");
    system("pause");
    cout<<endl;
    cout<<"EL ARCHIVO 'Clientes.dat' NO EXISTE. POR FAVOR RESTAURE EL BACKUP"<<endl<<endl<<endl;
    return ;
   }
 // cout<<"Por favor ingrese el ID-Cliente: ";
// cin>>_idCliente;
///cout<<endl;cout<<"Apellido y Nombre del Cliente:    ";
///cargarCadena(_nombreYapellido, 50);
///setIDCliente( DoyID.devuelveIDClienteACambioDeName(_nombreYapellido));
///if(_idCliente != -1){
///cout<<"El ID-Cliente es : "<<_idCliente<<endl;
///}else{
///cout<<"Por favor ingrese el ID-Cliente  : ";
///cin>>_idCliente;
//Aca tiene que cargar el cliente porque no existe, noe sta registrado
///}

///
 _fechaDeAlquiler.setFechaHorario( ArcAlquiler.devuelveAlquilerInicial(_idCliente  , id_aux).getFechaHorarioAlquiler() );
///

if(ArcAlquiler.laTieneAlquilada( _idCliente , _idVideoAlquilado )  == 1){
    //tambien puede servir la siguiente linea
    //int  nro_categoria =  DisponibilidadPelicula.devolverObjVideo(_idVideoAlquilado).getTipoDeCategoria();
///CHEQUEAR QUE SEA UNA PELICULA QUE SE ENCEUNTRE ALQUILADA POR EL CLIENTE
///EN POSESION . ACTUALMENTE PERMITE DEVOLVER UNA PELICULA QUE NO TIENE. SIN EMBARGO
///NO LO REGISTRA COMO UN ALQUILER DEVUELVO EN 'Alquiler.dat'
cout<<"La pelicula '";
cout<<DisponibilidadPelicula.devuelveNombrePeliculaACambioDeID(_idVideoAlquilado);
cout<<"' se encuentra ya alquilada por ";
 strcpy ( _nombreYapellido , DoyID.devuelveNombreYApellidoAcambioDeID(_idCliente));
cout<<_nombreYapellido<<"."<<endl;

cout<<"Y su ID-Pelicula es: ";
cout<<_idVideoAlquilado;
cout<<"."<<endl;

  int dia1, mes1,anio1;
Fecha FechaActual;
Horario HoraDeDevolucion;
///FALTA VALIDAR LAS FECHAS
///VALIDAR QUE SEAN DIAS Y MESES , ANIOS REALES
///QUE DEVOLUCION SEA MAYOR A ALQUILER
int opc;
bool si = true;
int v_normal[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int v_biesto[12] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
while(si==true){
cout<<"Desea Cargar Una fecha de Devolucion diferente a la de hoy o la actual ??"<<endl;
cout<<"1. Fecha De Hoy"<<endl;
cout<<"2. Fecha ingresada por el usuario"<<endl;
        cin>>opc;
switch(opc){

            case 1:
              _fechaDeDevolucion.setFecha(FechaActual);
              _fechaDeDevolucion.setHorario(HoraDeDevolucion);
    if ( ArcAlquiler.esMayorFechaHorario(_fechaDeDevolucion , _fechaDeAlquiler)){
            cout<< _fechaDeAlquiler.toStringSinHorario();
            cout<<endl;
            cout<< _fechaDeDevolucion.toStringSinHorario();
            system("pause");
        si = false;}
                break;

            case 2:
cout<<"Anio:";
 anio1 = getIntegerSinComa(1950 , 2050) ;
cout<<"Mes:";
 mes1 = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio1) && mes1 == 2){
cout<<"Dia:";
 dia1 = getIntegerSinComa(1 , v_biesto[ mes1 - 1 ]) ;
}else{
cout<<"Dia:";
 dia1 = getIntegerSinComa(1 , v_normal[ mes1 - 1 ]) ;
}
_fechaDeDevolucion.setFecha(dia1, mes1, anio1);
_fechaDeDevolucion.setHorario(HoraDeDevolucion);
    if ( ArcAlquiler.esMayorFechaHorario(_fechaDeDevolucion , _fechaDeAlquiler)){
            cout<< _fechaDeAlquiler.toStringSinHorario();
            cout<<endl;
            cout<< _fechaDeDevolucion.toStringSinHorario();
            system("pause");
            si = false;}

                break;

            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
}


//_fechaDeAlquiler(hoy, ahora);
Fecha Hoy;
FechaHorario diferencia_de_dias;
int posesion_De_Dias = 0;
///Restar los dias de alquiler permitidos segun categoria. Para que no se cuenten como retraso.
posesion_De_Dias = diferencia_de_dias.DiferenciaDeDias(  _fechaDeAlquiler , _fechaDeDevolucion );
cout<<"El tiempo transcurrido desde el alquiler a la devolucion es de : "<<posesion_De_Dias<<" dias."<<endl<<endl<<endl;

int  nro_categoria =  DisponibilidadPelicula.devolverObjVideo(_idVideoAlquilado).getTipoDeCategoria();

int dias_Demora_Categoria = ArcCategoriaYInteres.devolverObjCategoriaYInteres(nro_categoria).getDiaDeDemoraPorCategoria();
float comun_Categoria = ArcAlquiler.devuelveAlquilerInicial(_idCliente , _idVideoAlquilado).getInteresComun();
float compuesto_Categoria = ArcAlquiler.devuelveAlquilerInicial(_idCliente , _idVideoAlquilado).getInteresCompuesto();
 comun_Categoria = comun_Categoria * ArcAlquiler.devuelveAlquilerInicial(_idCliente , _idVideoAlquilado).getImporte();
 compuesto_Categoria = compuesto_Categoria * ArcAlquiler.devuelveAlquilerInicial(_idCliente , _idVideoAlquilado).getImporte();
 if( posesion_De_Dias > dias_Demora_Categoria){
    posesion_De_Dias = posesion_De_Dias - dias_Demora_Categoria;
 }
 int anio;
 if(esBisiesto( anio1 ) ){
    anio = 366;
        /*
    system("cls");
 cout<<"El anio bisiesto tiene "<<anio<<" dias"<<endl;
 system("pause");
 */
 }else{
 anio  = 365;
/*
 system("cls");
 cout<<"El anio tiene "<<anio<<" dias"<<endl;
 system("pause");
 */
 }

cout<<"Importe "<< AlquilerInicial.getImporte() <<endl;
cout<<"Interes comun "<< ArcCategoriaYInteres.devolverObjCategoriaYInteres(nro_categoria).getInteresComun() ;
cout<<"Interes compuesto "<< ArcCategoriaYInteres.devolverObjCategoriaYInteres(nro_categoria).getInteresCompuesto() ;
cout<<"--------"<<endl<<"LA categoria es el numero : "<<nro_categoria<<endl<<"-------"<<endl;
cout<<"Importe de la pelicula es : "<<_importe<<endl;
cout<<"EL INTERES COMUN VALE $" <<comun_Categoria<<endl;
cout<<"EL INTERES COMPUESTO VALE $"<<compuesto_Categoria<<endl;
if( posesion_De_Dias > dias_Demora_Categoria){
    _retraso = 1;
   _devolucion = 0;
}else{
    if( posesion_De_Dias <=
       dias_Demora_Categoria){
_retraso = 0;

Horario HorarioSinCargo;
/*
Fecha FechaSinCargo;
_fechaDeDevolucion.setFecha(FechaSinCargo);
*/

_fechaDeDevolucion.setHorario(HorarioSinCargo);
_devolucion=1;
///ES una devolucion común, no se paga nada.

DisponibilidadPelicula.devolucionPorID(_idVideoAlquilado);
ArcAlquiler.terminarDevolucionAlquiler(_idCliente, *this , _idVideoAlquilado);

    }
}

if(_retraso == 1){
cout<<"El tiempo transcurrido desde el alquiler a la devolucion es de : "<<posesion_De_Dias<<" dias.";

  ///Verificar que id_aux exista

if ( posesion_De_Dias  > dias_Demora_Categoria ){

 int  posesion_De_Dias_en_Comun = 0;

if(posesion_De_Dias > anio){
  posesion_De_Dias_en_Comun = anio;
}else{
    posesion_De_Dias_en_Comun = 0;
// posesion_De_Dias = posesion_De_Dias - dias_Demora_Categoria;
}

        //DisponibilidadPelicula.devolverObjVideoConDiasDeDemora(id_aux)){
    ///Hacer un metodo que devuelva el retraso y calcularlo de alguna manera
     //   DisponibilidadPelicula.
 Categoria InteresAux;
        ///Falta calcular el interes segun la categoria y el retraso correspondiente
        if(posesion_De_Dias_en_Comun == 0){
        cout<<comun_Categoria<<"    vale el interes comun........."<<endl;
        cout<<posesion_De_Dias<<"    fue la cantidad de dias que la tuvo alquilada............"<<endl<<endl<<endl<<endl;
     InteresAux.setInteresComun( comun_Categoria * posesion_De_Dias );
    }else{
InteresAux.setInteresComun( comun_Categoria * anio );
    }
    cout<<"El importe del interes Comun es de :$"<<InteresAux.getInteresComun()<<".";
cout<<endl;
    system("pause");

    _interes = InteresAux.getInteresComun();
    _devolucion=1;

Categoria InteresCompVacio;
InteresCompVacio.setInteresCompuesto(0);
_interesCompuesto = InteresCompVacio.getInteresCompuesto();

    DisponibilidadPelicula.devolucionPorID(_idVideoAlquilado);
/// ArcAlquiler.terminarDevolucionAlquiler(_idCliente, *this , _idVideoAlquilado);



Horario HorarioSinCargo2;
/*
    Fecha FechaSinCargo2;
_fechaDeDevolucion.setFecha(FechaSinCargo2);
*/
_fechaDeDevolucion.setHorario(HorarioSinCargo2);

///Fecha DiaDevolucion111;
///Horario MomentoDeDevolucion222;
///_fechaDeDevolucion(DiaDevolucion111 , MomentoDeDevolucion222);
}
if( posesion_De_Dias  > anio){
   // cout<<"Ingrese la fecha de devolucion ene l sigeuinte orden (dia,mes,anio)  ";
   // int dia4,mes4,anio4;
   // _fechaDeDevolucion(dia4,mes4,anio4);

 int un_Anio = anio;
 un_Anio =  posesion_De_Dias - anio;

    Categoria InteresAux2;
    InteresAux2.setInteresCompuesto( compuesto_Categoria * un_Anio );

    _interesCompuesto = InteresAux2.getInteresCompuesto();
    cout<<"El importe del interes Compuesto es de :$"<<_interesCompuesto<<".";
    system("pause");
    _devolucion=1;

  //quitar:  DisponibilidadPelicula.devolucionPorID(_idVideoAlquilado);
///ArcAlquiler.terminarDevolucionAlquiler(_idCliente, *this , _idVideoAlquilado);



 //   Fecha FechaSinCargo3;
//Horario HorarioSinCargo3;
//_fechaDeDevolucion.setFecha(FechaSinCargo3);
//_fechaDeDevolucion.setHorario(HorarioSinCargo3);

}

ArcAlquiler.terminarDevolucionAlquiler(_idCliente, *this , _idVideoAlquilado);

}

}else{
if(ArcAlquiler.laTieneAlquilada( _idCliente , _idVideoAlquilado)  == -2){
cout<<"---------------------------------------------------------------------------------------"<<endl;
cout<<"La pelicula no esta alquilada por el cliente"<<endl<<endl<<endl;
cout<<"---------------------------------------------------------------------------------------"<<endl;

}else{
cout<<"NO EXISTE EL ARCHIVO 'Alquiler.dat'.Por favor restaure el backup."<<endl;
}
}
}



/*
void Alquiler::cargar(){
ArchivoAlquiler ArcAlquiler;
ArchivoVideo DisponibilidadPelicula;
ArchivoCliente DoyID;
Fecha hoy;
Horario ahora;
//Fecha DiaEnQueFueAlquilado;

int id_aux;
cout<<"Ingrese el ID de la pelicula a alquilar o devolver: ";
cin>>id_aux;
int condicional = DisponibilidadPelicula.alquilerPorID(id_aux);
if( condicional == id_aux || condicional == -3 || condicional == -1){

        _idVideoAlquilado = id_aux;
 char nombrePelicula[50];
        ///Agregar idEmpleado para efectuar quien hizo el alquiler o devolucion
strcpy( nombrePelicula ,DisponibilidadPelicula.devuelveNombrePeliculaACambioDeID(id_aux).c_str());
   cout<<"El nombre de la película es: '"<<nombrePelicula<<"'"<<endl;
   //  setIDVideoAlquilado(id_aux);
cout<<endl;

cout<<"Apellido y Nombre del Cliente:    ";
cargarCadena(_nombreYapellido, 50);
setIDCliente( DoyID.devuelveIDClienteACambioDeName(_nombreYapellido));
if(_idCliente != -1){
cout<<"El ID-Cliente es : "<<_idCliente<<endl;
}else{
cout<<"Por favor ingrese el ID-Cliente  : ";
cin>>_idCliente;
//Aca tiene que cargar el cliente porque no existe, noe sta registrado
}
if(ArcAlquiler.laTieneAlquilada(_idCliente , _idVideoAlquilado)  == 1){
///cout<<"La película '"<<_nombrePelicula
cout<<_idVideoAlquilado;
cout<<"' se encuentra ya alquilada por ";
cout<<_nombreYapellido<<"."<<endl;

//_idAlquiler = ArcAlquiler.devuelveAlquilerInicial(_idCliente).getIDAlquiler();
//_idCliente = ArcAlquiler.devuelveAlquilerInicial(_idCliente).getIDCliente();
_fechaDeAlquiler.setFechaHorario(ArcAlquiler.devuelveAlquilerInicial(_idCliente, id_aux).getFechaHorarioAlquiler());

///Falta hacer la clase persona-->Cliente para obtener el idCliente a traves de su nombre.
///Sin que lo ingrese, el id
//cin>>_retraso;
//DiaEnQueFueAlquilado.setHorario(ahora);
//modificarFecha(DiaEnQueFueAlquilado);
  int dia1, mes1,anio1;
  cout<<"Ingrese en el siguiente orden la fecha de devolucion (dia, mes, anio) [TEXTO 1] " ;

cin>>dia1>>mes1>>anio1;
_fechaDeDevolucion.setFecha(dia1, mes1, anio1);

//_fechaDeAlquiler(hoy, ahora);
Fecha Hoy;
Fecha diferencia_de_dias;
///Restar los dias de alquiler permitidos segun categoria. Para que no se cuenten como retraso.
diferencia_de_dias.setDia(( _fechaDeDevolucion.getFecha().getDia() + 1) - _fechaDeAlquiler.getFecha().getDia() );

if(diferencia_de_dias.getDia() > DisponibilidadPelicula.devolverObjVideoConDiasDeDemora(_idVideoAlquilado)){
    _retraso = 1;
   _devolucion = 0;
}else{
    if(diferencia_de_dias.getDia() <=
       DisponibilidadPelicula.devolverObjVideoConDiasDeDemora(_idVideoAlquilado)){
_retraso = 0;

Horario HorarioSinCargo;

//Fecha FechaSinCargo;
//_fechaDeDevolucion.setFecha(FechaSinCargo);


_fechaDeDevolucion.setHorario(HorarioSinCargo);
_devolucion=1;
///ES una devolucion común, no se paga nada.

DisponibilidadPelicula.devolucionPorID(_idVideoAlquilado);
    }
}

if(_retraso == 1){
cout<<"El tiempo transcurrido desde el alquiler a la devolución es de : "<<diferencia_de_dias.getDia()<<" dias.";

  ///Verificar que id_aux exista
if (diferencia_de_dias.getDia()  > DisponibilidadPelicula.devolverObjVideoConDiasDeDemora(_idVideoAlquilado ) ){

 diferencia_de_dias.setDia(diferencia_de_dias.getDia() - DisponibilidadPelicula.devolverObjVideoConDiasDeDemora(_idVideoAlquilado ));

//    cout<<"Ingrese la fecha de devolucion ene l sigeuinte orden (dia,mes,anio) [TEXTO 2] ";
//int dia3,mes3,anio3;
//_fechaDeDevolucion.setFecha(dia3,mes3,anio3);

        //DisponibilidadPelicula.devolverObjVideoConDiasDeDemora(id_aux)){
    ///Hacer un metodo que devuelva el retraso y calcularlo de alguna manera
     //   DisponibilidadPelicula.
 Categoria InteresAux;
        ///Falta calcular el interes segun la categoria y el retraso correspondiente
     InteresAux.setInteresComun( DisponibilidadPelicula.devolverPropIntereseComun(id_aux) * diferencia_de_dias.getDia() );

    cout<<"El importe del interés Comun es de :$"<<InteresAux.getInteresComun()<<".";
cout<<endl;
    _interes = InteresAux.getInteresComun();
    _devolucion=1;

Categoria InteresCompVacio;
InteresCompVacio.setInteresCompuesto(0);
_interesCompuesto = InteresCompVacio.getInteresCompuesto();

    DisponibilidadPelicula.devolucionPorID(_idVideoAlquilado);


Horario HorarioSinCargo2;

 //   Fecha FechaSinCargo2;
//_fechaDeDevolucion.setFecha(FechaSinCargo2);

_fechaDeDevolucion.setHorario(HorarioSinCargo2);

///Fecha DiaDevolucion111;
///Horario MomentoDeDevolucion222;
///_fechaDeDevolucion(DiaDevolucion111 , MomentoDeDevolucion222);
}
if(diferencia_de_dias.getDia()  > 10){
   // cout<<"Ingrese la fecha de devolucion ene l sigeuinte orden (dia,mes,anio)  ";
   // int dia4,mes4,anio4;
   // _fechaDeDevolucion(dia4,mes4,anio4);

    Categoria InteresAux2;
    InteresAux2.setInteresCompuesto( DisponibilidadPelicula.devolverPropInteresCompuesto(id_aux) * diferencia_de_dias.getDia() );

    cout<<"El importe del interés Compuesto es de :$"<<InteresAux2.getInteresCompuesto()<<".";
    _interesCompuesto = InteresAux2.getInteresCompuesto();
    _devolucion=1;

    DisponibilidadPelicula.devolucionPorID(_idVideoAlquilado);


 //   Fecha FechaSinCargo3;
//Horario HorarioSinCargo3;
//_fechaDeDevolucion.setFecha(FechaSinCargo3);
//_fechaDeDevolucion.setHorario(HorarioSinCargo3);

}

}

}else{
    ///Revisar como hacer el _idAlquiler incrementador
    cout<<"Esta alquilando la película... Ingrese el ''Id-Alquiler'' : ";
    cin>>_idAlquiler;


//Alquiler normal. Significa que no la tiene alquilada
//Fecha DiaRetiro;
Horario HoraDeRetiro;

//FechaHorario MomentoDeRetiro(DiaRetiro , HoraDeRetiro);
cout<<"Ingrese la Fecha de Alquiler en el siguiente orden (dia,mes,anio) [TEXTO 3] ";
int dia5, mes5, anio5;
cin>>dia5>>mes5>>anio5;
_fechaDeAlquiler.setFecha(dia5, mes5, anio5);
_fechaDeAlquiler.setHorario(HoraDeRetiro);
_importe =  DisponibilidadPelicula.devolverImporteAcambioIDVideo(_idVideoAlquilado);

_retraso = 0;
_devolucion = 0;
}

cout<<"Ingrese su 'ID' de Empleado: ";
cin>>_idEmpleado;

///cout<<"NO HAY STOCK DE...Explicar poruqe no hay stock .
///Ej nombre de pelicula sin stock y su 'id' para verificar
///que se ingreso correctamente yno fue un error
_estado=true;
}
//_estado = false; Es un ejemplo para que no se guarde el registro caundo no se esta seguro de la carga por equivocarse en IDVideo
}
*/

///}

void  Alquiler::mostrarAlquilerMenosInfo(){

    cout << setw(4) << _idAlquiler << "\t      ";
    cout  << _nombreYapellido << "\t";
    cout << setw(4) << _idCliente << "\t\t";
 if(_devolucion == 1){

    cout << setw(2) <<"SI"  << "\t\t";
    }else{
    cout << setw(2) <<"NO"  << "\t\t";
    }
    if(_retraso == 1){

    cout << setw(2) <<"SI"  << "\t\t";
    }else{
    cout << setw(2) <<"NO"  << "\t\t";
    }
    cout << setw(4) << _idVideoAlquilado << endl;
}


void  Alquiler::mostrarAlquilerMasInfo(){
    cout << setw(4) << _idAlquiler << "\t      ";
    cout  << _nombreYapellido << "\t";
    cout << setw(4) << _idCliente << "\t\t";
    if(_devolucion == 1){

    cout << setw(2) <<"SI"  << "\t\t";
    }else{
    cout << setw(2) <<"NO"  << "\t\t";
    }
  //  cout << setw(1) << _retraso<<"\t\t" ;
  //  cout << setw(4) << _idVideoAlquilado << endl;
   cout<<setw(10)<<_fechaDeAlquiler.toStringSinHorario()<<"\t";

   if(_fechaDeDevolucion.getFecha().getAnio() > 1951){
   cout<<setw(10)<< _fechaDeDevolucion.toStringSinHorario()<<"\t";
   }else{
   cout<<"\t-\t";
   }

   cout<<setw(5)<<"$"<< _importe<<"\t";
  //  cout << setw(4) << _idVideoAlquilado << "\t";
  if( _interes < 1  && _interes >= 0 ){
        cout<<"\t-"<<"\t\t";
  }else{
 cout<<setw(8)<<"$"<<_interes<<"\t";
  }
 if( _interesCompuesto < 1 && _interesCompuesto >= 0  ){
        cout<<"\t-";
 }else{
cout<<setw(8)<<"$"<<_interesCompuesto<<"\t";
 }
      }


void  Alquiler::mostrarObjetoCompleto(){
    cout<<_fechaDeAlquiler.toString()<<endl;
   cout<< _fechaDeDevolucion.toString()<<endl;
   cout<<"El ID-Alquiler es: "<<_idAlquiler<<endl;
   cout<<"El ID-Empleado es: "<<_idEmpleado<<endl;
cout<<"El ID-Cliente es: "<<_idCliente<<endl;
cout<<"El ID-Pelicula es: "<<_idVideoAlquilado<<endl;
 cout<<"Con un Interes Comun de $"<<_interes<<endl;
cout<<"Con un Interes Compuesto de $"<<_interesCompuesto<<endl;
 cout<<"El importe es de $"<< _importe<<endl;
  cout<<"Retraso: "<<_retraso<<endl;
  cout<<"Devolucion: "<< _devolucion<<endl;
cout<<"Nombre y Apellido del cliente = "<<_nombreYapellido<<endl;
 cout<<"Estado: "<< _estado<<endl;


}





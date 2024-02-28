# include<iostream>
#include <iomanip>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "ArchivoAlquiler.h"
#include "Alquiler.h"
#include "ArchivoVideo.h"
#include "ArchivoCategoria.h"
#include "ArchivoCliente.h"
#include "validaciones.h"


 ArchivoAlquiler::ArchivoAlquiler(){
            strcpy(nombre , "Alquileres.dat");
        }

        /*
void ArchivoAlquiler::agregarRegistro(){
     Fecha Fechavalores01;
    Fechavalores01.setDia(0);
 //   Fechavalores01.setHorario(0,0,0);

    Alquiler obj;
    ArchivoAlquiler objArc;
    FILE *pIng;
    pIng=fopen(nombre, "ab+");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    obj.cargar();
    if(objArc.existeFechaDeAlquiler(obj.getIDAlquiler())
       != Fechavalores01.getDia()){
        obj.setFechaDeAlquilerSoloConDia(objArc.existeFechaDeAlquiler(obj.getIDAlquiler()));
    if(objArc.existeIDAlquiler(obj.getIDAlquiler()) != -1
    &&  objArc.existeIDAlquiler(obj.getIDAlquiler()) != -2 ){
            obj.setIDCliente(objArc.existeIDAlquiler(obj.getIDAlquiler()));
  //  obj.set_Id(ultimoPelicula()+1);
	fwrite(&obj, sizeof(obj), 1, pIng);
	fclose(pIng);
    }
    }
    fwrite(&obj, sizeof(obj), 1, pIng);
	fclose(pIng);
}
*/


void ArchivoAlquiler::agregarRegistro(){
    Alquiler obj;
    ArchivoAlquiler ArcAlquiler;
    ArchivoCliente ArcCliente;
    ArchivoVideo ArcVideo;

    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO 'Alquileres.dat'"<<endl;
        return;
    }
    int total=0;
    total = cantidadRegistros();
    if(cantidadRegistros() == -1){
    obj.setIDAlquiler(1);
    }else{
    obj.setIDAlquiler(total + 1);
    }
    //obj.cargar();
    int id_aux;
    int idCliente;
    int maxIDVideo;
   maxIDVideo = ArcVideo.devolverIDMaximo();
    cout<<"Ingrese el ID de la pelicula a ALQUILAR: ";
     id_aux =  getIntegerSinComa( 0 , maxIDVideo );
   while( ArcVideo.buscarPeliculaPorIDVideoParametro(id_aux) != 1){
    cout<<"ID-Pelicula inexistente"<<endl;
     id_aux =  getIntegerSinComa( 0 , maxIDVideo );
   }


   int maxIDCliente;
   maxIDCliente = ArcCliente.devolverIDMaximo();
    cout<<"Ingrese el ID-Cliente: ";
    idCliente = getIntegerSinComa( 0 , maxIDCliente );
      while( ArcCliente.clienteExiste(idCliente) != 1){
    cout<<"ID-Cliente inexistente"<<endl;
    idCliente = getIntegerSinComa( 0 , maxIDCliente );
   }


int puede_alquilar =  ArcAlquiler.noPuedeAlquilar(idCliente);
  cout<<"El cliente puede alquilar ?????????????? ( 1 = SI ) RTA: "<<puede_alquilar<<endl;
    if(puede_alquilar == -1){
        system("cls");
        cout<<"No existe el 'ArchivoAlquiler.dat'.Por favor, restaure el Backup Alquiler para seguir Administrando Alquileres."<<endl;
        system("pause");
    }
    if( puede_alquilar == -2){
    system("cls");
    cout<<endl<<endl;
cout << "El cliente '" ;
char nombreCliente[50];
strcpy(nombreCliente , ArcCliente.devuelveNombreYApellidoAcambioDeID(idCliente));
cout<<nombreCliente;
cout<<"' no puede alquilar mas peliculas hasta que devuelva las que tiene en su posesion. Por favor, realice la devolucion para proceder con un nuevo alquiler." << endl;
    ArcAlquiler.cancelarAlquilerEnProceso(idCliente , id_aux);
      cout<<endl<<endl;
    system("pause");

    return;
    }
    cout<<"EL ID-CLIENTE ES '"<<idCliente<<"' y el ID-PELICULA ES '"<<id_aux<<"'"<<endl<<endl;
    obj.cargarAlquiler( idCliente , id_aux );

	fwrite(&obj, sizeof (obj), 1, pIng);
	fclose(pIng);
}



int ArchivoAlquiler::bajaLogicaRegistro(){
  Alquiler obj;
  ArchivoAlquiler objAModificar;
  ArchivoVideo objVideo;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
           cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return -1;
    }
int id_Alquiler;
cout<<"Para eliminar un Alquiler ingrese el ID-Alquiler: ";
cin>>id_Alquiler;
int c=-1;
char correcto;
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDAlquiler() == id_Alquiler
           && obj.getEstado() == true){
           cout<<"El Alquiler que desea eliminar posee el ID: '"<<obj.getIDAlquiler();
           cout<<" y pertenece al Cliente '"<<obj.getApellidoYNombre()<<"' ?."<<endl;
           cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){
    objVideo.devolucionPorID(obj.getIDVideoAlquilado());
        obj.setEstado(0);
        objAModificar.guardarCambioDeProp(obj, c);
        fclose(p);
        return 1;
}
        }
	}
	fclose(p);
    return -2;
}




int ArchivoAlquiler::cancelarAlquilerEnProceso(int id_Cliente, int id_PeliculaAAlquilar){
  Alquiler obj;
  ArchivoAlquiler objAModificar;
  ArchivoVideo objVideo;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
           cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return -1;
    }

int c=-1;
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDCliente() == id_Cliente
           && obj.getEstado() == true
           && obj.getIDVideoAlquilado() == id_PeliculaAAlquilar
           && obj.getDevolucion() == false){
    objVideo.devolucionPorID( id_PeliculaAAlquilar );
        obj.setEstado(0);
        objAModificar.guardarCambioDeProp(obj, c);
        fclose(p);
        return 1;
}
        }
	fclose(p);
    return -2;
	}



/*
int ArchivoAlquiler::existeFechaDeAlquiler(int idAlquiler){
    Alquiler obj;
    Fecha Fechavalores;
    Fechavalores.setDia(0);
   // Fecha.setHorario(0,0,0);
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){

        return -1;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
            if(obj.getIDAlquiler() == idAlquiler && obj.getDevolucion() == 0
                    && obj.getEstado()  == true){
        fclose(p);
        return obj.getFechaHorarioAlquiler().getFecha().getDia();
        cout<<endl;


            }
	}
	fclose(p);
	return Fechavalores.getDia();
}
*/

int ArchivoAlquiler::existeIDAlquiler(int idAlquiler){
      Alquiler obj;

    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return -1;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
            if(obj.getIDAlquiler() == idAlquiler  && obj.getDevolucion() == 0
                && obj.getEstado()  == true  ){
        fclose(p);
        return obj.getIDAlquiler();

            }
	}
	fclose(p);
        return -2;
}


void ArchivoAlquiler::mostrarRegistros(){
    Alquiler obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true){

     obj.mostrarObjetoCompleto();
        cout<<endl;

        }
	}
	fclose(p);
}


void ArchivoAlquiler::mostrarRegistrosMenosInfo(){
    Alquiler obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true){

       obj.mostrarAlquilerMenosInfo();
        cout<<endl;

        }
	}
	fclose(p);
}



void ArchivoAlquiler::mostrarRegistrosMasInfo(){
    Alquiler obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true){

       obj.mostrarAlquilerMasInfo();
        cout<<endl;

        }
	}
	fclose(p);
}



    bool ArchivoAlquiler::esMayorFechaHorario(  FechaHorario otra,   FechaHorario Inicio) const {
        if (otra.getFecha().getAnio() > Inicio.getFecha().getAnio())
            return true;
        else if (otra.getFecha().getAnio() == Inicio.getFecha().getAnio() && otra.getFecha().getMes() > Inicio.getFecha().getMes())
            return true;
        else if (otra.getFecha().getAnio()  == Inicio.getFecha().getAnio() &&
                 otra.getFecha().getMes() == Inicio.getFecha().getMes() && otra.getFecha().getDia() >= Inicio.getFecha().getDia())
            return true;
        return false;
    }


bool ArchivoAlquiler::esMenorFechaHorario(  FechaHorario otra ,   FechaHorario Final) const  {
             if (otra.getFecha().getAnio() < Final.getFecha().getAnio())
            return true;
        else if (otra.getFecha().getAnio() == Final.getFecha().getAnio() && otra.getFecha().getMes() < Final.getFecha().getMes())
            return true;
        else if (otra.getFecha().getAnio()  == Final.getFecha().getAnio() &&
                 otra.getFecha().getMes() == Final.getFecha().getMes() && otra.getFecha().getDia() <= Final.getFecha().getDia())
            return true;
        return false;
    }


    int ArchivoAlquiler::noPuedeAlquilar(int IDCliente){
    Alquiler obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }

int contador=0;
	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true
           && obj.getIDCliente() == IDCliente
           && obj.getDevolucion() == false){
        contador++;

        }
	}
	fclose(p);

if( contador < 2  && contador > -1){
    return 1;
}else{
    return -2;}
}


    void ArchivoAlquiler::mostrarAlquilerPorIDCliente(int IDCliente, FechaHorario Inicio, FechaHorario Final){
    Alquiler obj;
    bool no_hay = false;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'. Por favor, restaure el Backup.'"<<endl;
        return;
    }


	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true
           && obj.getIDCliente() == IDCliente){

           if(esMenorFechaHorario(obj.getFechaHorarioDevolucion() , Final )
              && esMayorFechaHorario(obj.getFechaHorarioDevolucion() , Inicio) ){
            obj.mostrarAlquilerMasInfo();
              cout<<endl<<endl;
               no_hay = true;
           }

        }
	}

	fclose(p);
	if( no_hay == false){
    system("cls");
	cout<<endl;
cout<<"No hay alquileres en ese RANGO de fechas."<<endl<<endl;
	}
}



void ArchivoAlquiler::mostrarAlquilerPorIDVideo(int idVideo, FechaHorario Inicio, FechaHorario Final){
        Alquiler obj;
    bool no_hay = false;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true
           && obj.getIDVideoAlquilado() == idVideo){

           if(esMenorFechaHorario(obj.getFechaHorarioDevolucion() , Final )
              && esMayorFechaHorario(obj.getFechaHorarioDevolucion() , Inicio) ){
            obj.mostrarAlquilerMasInfo();
              cout<<endl<<endl;
               no_hay = true;
           }

        }
	}

	fclose(p);
	if( no_hay == false){
    system("cls");
	cout<<endl;
cout<<"No hay alquileres en ese RANGO de fechas."<<endl<<endl;
	}

    }




void ArchivoAlquiler::mostrarAlquilerPorCategoria(int IDCategoria, FechaHorario Inicio, FechaHorario Final){
    Alquiler obj;
    ArchivoVideo ArcVideo;
    bool no_hay = false;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return;
    }


	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true
           && ArcVideo.devolverIDCategoria(obj.getIDVideoAlquilado()) == IDCategoria){

           if(esMenorFechaHorario(obj.getFechaHorarioDevolucion() , Final )
              && esMayorFechaHorario(obj.getFechaHorarioDevolucion() , Inicio) ){
            obj.mostrarAlquilerMasInfo();
              cout<<endl<<endl;
               no_hay = true;
           }

        }
	}

	fclose(p);
	if( no_hay == false){
    system("cls");
	cout<<endl;
cout<<"No hay alquileres en ese RANGO de fechas."<<endl<<endl;
	}
}



void ArchivoAlquiler::mostrarAlquilerPorGenero(int IDGenero, FechaHorario Inicio, FechaHorario Final){
    Alquiler obj;
    ArchivoVideo ArcVideo;
    bool no_hay = false;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'"<<endl;
        return;
    }


while(fread(&obj, sizeof(obj), 1, p)==1){
  if( obj.getEstado()  == true
    && ArcVideo.devolverIDGenero(obj.getIDVideoAlquilado()) == IDGenero){

           if(esMenorFechaHorario(obj.getFechaHorarioDevolucion() , Final )
              && esMayorFechaHorario(obj.getFechaHorarioDevolucion() , Inicio) ){
            obj.mostrarAlquilerMasInfo();
              cout<<endl<<endl;
               no_hay = true;
           }

        }
	}

	fclose(p);
	if( no_hay == false){
    system("cls");
	cout<<endl;
cout<<"No hay alquileres en ese RANGO de fechas."<<endl<<endl;
	}
}


 void ArchivoAlquiler::mostrarRecaudacionDeAlquileres( FechaHorario Inicio, FechaHorario Final){
    Alquiler obj;
    bool no_hay = false;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Alquileres.dat'. Por favor, restaure el Backup.'"<<endl;
        return;
    }

float valor_pelicula=0;
float int_comun_total = 0;
float int_compuesto_total = 0;
	while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getEstado()  == true ){

           if(esMenorFechaHorario(obj.getFechaHorarioDevolucion() , Final )
              && esMayorFechaHorario(obj.getFechaHorarioDevolucion() , Inicio) ){
             valor_pelicula += obj.getImporte();
             int_comun_total += obj.getInteresComun();
             if( obj.getInteresCompuesto() > 1 ){
             int_compuesto_total += obj.getInteresCompuesto();
             }
               no_hay = true;
           }

        }
	}

	fclose(p);
	if( no_hay == false){
    system("cls");
	cout<<endl;
cout<<"No hubo alquileres en ese RANGO de fechas."<<endl<<endl;
return;
	}

cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tRecaudacion:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<endl<<endl;
cout<<"Total importe peliculas $"<<valor_pelicula<<endl;
cout<<"Total Interes comun $"<<int_comun_total<<endl;
cout<<"Total Interes compuesto $"<<int_compuesto_total<<endl<<endl<<endl;

}



     int ArchivoAlquiler::laTieneAlquilada( int idCliente , int idVideo ){
     Alquiler obj;
  FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO EXISTE EL ARCHIVO 'Alquileres.dat'. POR FAVOR RESTAURE EL BACKUP."<<endl;
        return -1;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getIDCliente() == idCliente
           && obj.getIDVideoAlquilado() == idVideo
           && obj.getDevolucion() == 0
            && obj.getEstado()  == true  ){
        	fclose(p);
        	return 1;


        }
	}
	fclose(p);
    return -2;
   }



 Alquiler ArchivoAlquiler::devuelveAlquilerInicial(int idCliente, int idVideoAlquilado){
  Alquiler obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    obj.setImporte(-100);
    obj.setInteresCompuesto(99);
    obj.setInteresComun(99);
        cout<<"NO -EXISTE- EL ARCHIVO 'Alquileres.dat'"<<endl;
        return obj ;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getIDCliente() == idCliente &&
           obj.getIDVideoAlquilado() == idVideoAlquilado){
            if(obj.getDevolucion() == 0
               && obj.getEstado()  == true  ){
        fclose(p);
        return obj;


            }
        }
	}
	obj.setImporte(1);
    obj.setInteresCompuesto(99);
    obj.setInteresComun(99);
    fclose(p);
    return obj;
   }

int ArchivoAlquiler::terminarDevolucionAlquiler(int idCliente,  Alquiler &objCargar, int idVideoAlquilado){
 Alquiler obj;
 int pos=-1;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO -EXISTE- EL ARCHIVO 'Alquileres.dat'"<<endl;
        return -1;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        pos++;
        if(obj.getIDCliente() == idCliente &&
           obj.getIDVideoAlquilado() == idVideoAlquilado){

            if(obj.getDevolucion() == 0
                && obj.getEstado()  == true  ){

     obj.setDevolucion( objCargar.getDevolucion() );
      obj.setRetraso( objCargar.getRetraso() );
      obj.setInteresComun( objCargar.getInteresComun() );
     obj.setInteresCompuesto( objCargar.getInteresCompuesto() );
      obj.setFechaHorarioDevolucion( objCargar.getFechaHorarioDevolucion() );


        guardarCambioDeProp(obj, pos );
        return 1;
           fclose(p);

            }
        }
	}
    fclose(p);
    return -2;

}


   int ArchivoAlquiler::guardarCambioDeProp(Alquiler &obj, int pos){

     FILE *p = fopen ("Alquileres.dat" , "rb+");
     if(p == NULL){
            cout<<endl;
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
        return -1;
     }

   if( fseek(p, sizeof(Alquiler) * pos, 0) == 0){
  //  cout<<" VERDADERO 001 "<<endl<<endl<<endl;
 if(fwrite(&obj, sizeof (obj), 1, p) == 1){
//cout<<" VERDADERO 002 "<<endl<<endl<<endl;

  //          cout<<"SI EL ALQUILER FUE DEVUELTO MUESTRA ''1'' SINO ''0'' : ...";
    cout<<obj.getDevolucion()<<"."<<endl<<endl;
        fclose(p);
        return 1;
        }
   }

//cout<<" VERDADERO 003 "<<endl<<endl<<endl;


    fclose(p);
    return -2;
 }


 void ArchivoAlquiler::listadoDeAlquileresPendientes(){
Alquiler NoDevuelto;
FechaHorario diferencia_de_dias;
Fecha fechaSistema;
Horario horarioSistema;
FechaHorario fSistema(fechaSistema , horarioSistema);
ArchivoVideo Pelicula;
ArchivoCategoria IDCategoria;

 FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO -EXISTE- EL ARCHIVO 'ALQUILERES'"<<endl;
        return ;
    }

int posesion_De_Dias;
int ID_Pelicula_determinada;
int dias_demora_permitido;
bool hito=true;
int c=0;
	while(fread(&NoDevuelto, sizeof(NoDevuelto), 1, p)==1){
    if(NoDevuelto.getEstado() == true &&
       NoDevuelto.getDevolucion() == false){

    posesion_De_Dias = diferencia_de_dias.DiferenciaDeDias( NoDevuelto.getFechaHorarioAlquiler() , fSistema);
        ID_Pelicula_determinada =  NoDevuelto.getIDVideoAlquilado();
      dias_demora_permitido = IDCategoria.devolverObjCategoriaYInteres(ID_Pelicula_determinada).getDiaDeDemoraPorCategoria();

cout<<"Dias de demora permitido : "<<dias_demora_permitido<<endl;
cout<<"Posesion de dias de la pelicula que hay que pagar: "<<posesion_De_Dias<<endl;
system("pause");

      posesion_De_Dias= posesion_De_Dias - dias_demora_permitido;
    if(posesion_De_Dias > dias_demora_permitido ){
        c++;
    if(c>0 && hito == true){

    cout<<"Nom. y Apell.";
cout<<"\tID-Cliente";
cout<<"\tID-Pelicula";
cout<<"\tDias de Retraso";
cout<<"\t\tTitulo Pelicula";
cout<<endl;
cout << "--------------------------------------------------------------------------------------------" << endl;
    hito = false;
    }
     cout << setw(4) << NoDevuelto.getApellidoYNombre() << "\t      ";
    cout  << setw(4) <<NoDevuelto.getIDCliente() << "\t";
    cout << setw(4) <<ID_Pelicula_determinada<< "\t";
    cout << setw(4) << posesion_De_Dias << "\t";
    cout  << Pelicula.devuelveNombrePeliculaACambioDeID(ID_Pelicula_determinada)<< "\t";

    cout<<endl;

    }

       }
	}

	if(c ==0){
            cout<<endl;
        cout<<"NO HAY ALQUILERES CON RETRASO."<<endl<<endl;
    system("pause");
	}
	fclose(p);
                cout<<endl<<endl;

 }

 void ArchivoAlquiler::ordenarDeMayorAMenorTresVectores(int *vecCant, int *vecID, bool *vecHecho, int dimension) {
    for (int i = 0; i < dimension - 1; ++i) {
        for (int j = 0; j <dimension-i-1; ++j) {
            if (vecCant[j] < vecCant[j + 1]) {
                // Intercambiar elementos si están en el orden incorrecto
                std::swap(vecCant[j], vecCant[j + 1]);
                std::swap(vecID[j], vecID[j + 1]);
                std::swap(vecHecho[j], vecHecho[j + 1]);
            }
        }
    }
}



 int ArchivoAlquiler::RankingGenereral(FechaHorario Inicio , FechaHorario Final){
    Alquiler obj;
    ArchivoVideo ArcObj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO EXISTE EL ARCHIVO ALQUILER"<<endl;
        return -1;
    }

    int *vIDPeliculas;
    int *vCantAlquileres;
    bool *vHecho;
    int dimension;
  dimension =  ArcObj.cantidadRegistros();

  vIDPeliculas = new int[dimension];
  vCantAlquileres = new int[dimension];
  vHecho = new bool[dimension];

  if(vIDPeliculas == NULL){ return -2; }
  if(vCantAlquileres == NULL){ return -2; }
  if(vHecho == NULL){ return -2; }

  for(int i=0;i<dimension;i++){
     vIDPeliculas[i] = 0;
  vCantAlquileres[i] = 0;
  vHecho[i] = false;
  }

  while(fread(&obj, sizeof(obj), 1, p)==1){
    if( obj.getEstado()  == true){
     if(esMenorFechaHorario(obj.getFechaHorarioDevolucion() , Final )
        && esMayorFechaHorario(obj.getFechaHorarioDevolucion() , Inicio) ){
    vIDPeliculas[obj.getIDVideoAlquilado() - 1 ] = obj.getIDVideoAlquilado();
    vCantAlquileres[obj.getIDVideoAlquilado() - 1 ]++;
    vHecho[obj.getIDVideoAlquilado() - 1 ] = true;
           }
        }
	}

 ordenarDeMayorAMenorTresVectores(vCantAlquileres, vIDPeliculas, vHecho, dimension);


//int contador10=0;
cout<<endl;
	cout<<"...................................................................................................................."<<endl;
	cout<<"\t\t\t\tRANKING"<<endl;
	cout<<"...................................................................................................................."<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\tPuesto\t\tAlquileres realizados\t\tTitulo"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	  for (int i = 0; i < 10; ++i) {
            if(i<10){
        cout<<"\t#"<< i + 1<<" \t| ";
            }else{
               cout<<"       #"<< i + 1<<"\t\t| ";
            }
 cout<<"\t\t"<<vCantAlquileres[i]<<" \t\t|";
 cout<<"\t'"<<ArcObj.devuelveNombrePeliculaACambioDeID(vIDPeliculas[i])<<"'"<<endl;

 }
 cout<<endl<<endl;

	/*
	int maximo = 0;
  for(int i=0;i<dimension;i++){
  for(int k=0;k<dimension;k++){
	if(vCantAlquileres[i] != 0 &&
    vCantAlquileres[i] > maximo &&
    vHecho[i] == false){
       maximo = vCantAlquileres[i];
 cout<<"Puesto #"<<contador10 + 1<<" | le pertenece a la pelicula '";
 if(vIDPeliculas[k] > 0){
 cout<<ArcObj.devuelveNombrePeliculaACambioDeID(vIDPeliculas[k]);
 }
 cout<<"' . Con la cantidad de "<<vCantAlquileres[k]<<" alquileres realizados."<<endl;
    vHecho[k] = true;
    contador10++;
    if(contador10 == 10){
        break;
    }
        }
      }
    }
*/

	fclose(p);

   delete[] vIDPeliculas ;
   delete[] vCantAlquileres ;
   delete[] vHecho ;

   return 1;
 }



int ArchivoAlquiler::hacerCopiaDeSeguridad(){
    ArchivoAlquiler ArcAlquiler;
  int cantidad_registros = cantidadRegistros();
  Alquiler *vec = new Alquiler[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al realizar backup." << endl;
    return -1;
  }

  ArcAlquiler.leer(vec, cantidad_registros);
  ArcAlquiler.vaciarBackup();
  if ( ArcAlquiler.guardarBackup(vec, cantidad_registros) ){
        cout<<endl;
    cout << "Backup: 'AlquileresBackup.bkp' realizado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al realizar backup: 'AlquileresBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;
}

int ArchivoAlquiler::restaurarBackup(){
ArchivoAlquiler ArcAlquiler;
  int cantidad_registros = ArcAlquiler.cantidadRegistrosBackup();
  system("pause");
  cout<<"La cantidad de registros del archivo Alquiler (base) es de : "<<cantidad_registros<<endl;
  system("pause");
  Alquiler *vec = new Alquiler[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al restaurar backup." << endl;
    return -1;
  }
  ArcAlquiler.leerBackup(vec, cantidad_registros);
  ArcAlquiler.vaciar();
  if (ArcAlquiler.guardar(vec, cantidad_registros)){
        cout<<endl;
    cout << "Backup: 'AlquileresBackup.bkp' restaurado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al restaurar el backup: 'AlquileresBackup.bkp'." << endl;
    return -2;
  }

  delete []vec;


}

bool ArchivoAlquiler::guardar(Alquiler *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(nombre, "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Alquiler), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


bool ArchivoAlquiler::guardarBackup(Alquiler *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen("AlquileresBackup.bkp" , "wb");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Alquiler), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ArchivoAlquiler::leer(Alquiler *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("Alquileres.dat" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Alquiler), cantidadRegistrosALeer, p);
  fclose(p);
}

void ArchivoAlquiler::leerBackup(Alquiler *vec, int cantidadRegistrosALeer){
  FILE *p = fopen( "AlquileresBackup.bkp" , "rb" );
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Alquiler), cantidadRegistrosALeer, p);
  fclose(p);
}


int ArchivoAlquiler::cantidadRegistros(){
    FILE *p;
    p=fopen("Alquileres.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Alquiler);
}



int ArchivoAlquiler::cantidadRegistrosBackup(){
    FILE *p;
    p=fopen( "AlquileresBackup.bkp" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO 'AlquileresBackup.bkp'"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Alquiler);
}

void ArchivoAlquiler::vaciar(){
  FILE *p = fopen(nombre, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoAlquiler::vaciarBackup(){
  FILE *p = fopen(bkp, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}





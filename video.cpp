///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>
//Español
#include <clocale>
#include <vector>
#include <string>
using namespace std;

#include "video.h"
#include "ArchivoCategoria.h"
#include "ArchivoGenero.h"
#include "validaciones.h"

Video::Video()
{
//    cargarCadena(_nombre,"Se uso un construcor vacío");
    //ctor
}

/*
     Video& Video::operator = (const Categoria& obj){
         char aux[15];
    _tipoDeCategoria.setIDCategoria( obj.getIDCATEG());
   strcpy( aux, obj.getNombreCategoria());
   _tipoDeCategoria.setNombreCategoria(aux);
   _tipoDeCategoria.setPrecioPorCategoria( obj.getPrecioCategoria());
   _tipoDeCategoria.setDiaDeDemoraPorCategoria(obj.getDiaDeDemoraPorCategoria());
 //  bool _estado;  //Agregar

      return *this;
      }
*/


void Video::cargar(){
cout<<"Titulo del Film: ";
cargarCadena(_nombre, 50);
cout<<endl;
cout<<"Descripcion: ";
cargarCadena(_descripcion, 1500);
cout<<endl;
cout<<"Anio de Estreno: ";
_anioEstreno = getIntegerSinComa(1900, 2050);
 ///Ponerlo para que sea automatico
/*
_stock = getIntegerSinComa( 0 , 4 );
//cin>>_stock;
_stockLimite = _stock;
*/
cout<<endl;
cout<<"Duracion ";
//cin>>_duracion;
_duracion = getIntegerSinComa( 29 , 241 );
cout<<endl;
    cout<<"Ingrese el tipo de Categoria ('Viejo= 1' ,'Normal= 2' ,'Clasico= 3' ,'Estreno= 4'): ";
cin>>_tipoDeCategoria;
// _tipoDeCategoria = getIntegerSinComa ( 1 , 4 );
  _tipoDeCategoria = getIDCategoria( _tipoDeCategoria );
if(_tipoDeCategoria == -1){return ;}
 //_tipoDeCategoria = getIntegerSinComa(1, 4);
 ArchivoCategoria TodaLaInfo;
cout<<TodaLaInfo.devolverObjCategoriaYInteres(_tipoDeCategoria).getNombreCategoria();
///SE va a pisar la siguiente linea de codigo: CORREGIR
 // TodaLaInfo.devolverObjCategoriaYInteres(_tipoDeCategoria).mostrar();
cout<<endl;
_stock = _tipoDeCategoria;
_tipoDeInteres = _tipoDeCategoria;
_stockLimite = _stock;
cout<<"Stock : ";
cout<<_stock<<"/"<<_stockLimite<<endl;
/*
 cout<<"Con un interes de: "<<endl;
 TodaLaInfo.devolverObjCategoriaYInteres(_tipoDeCategoria).getInteresComun();
 TodaLaInfo.devolverObjCategoriaYInteres(_tipoDeCategoria).getInteresCompuesto();
*/
 cout<<"Ingrese Un Genero ('Accion= 1' ,'Romance= 2' ,'Comedia= 3' ,'Drama= 4' ,'Aventura= 5') : ";
 Genero Objgen;
 ArchivoGenero ArcGen;
 cin>>_tipoDeGenero;
  _tipoDeGenero = getIDGenero( _tipoDeGenero );
if(_tipoDeGenero == -1){return ;}
 //_tipoDeGenero = getIntegerSinComa(1, 5);
 cout<<ArcGen.devolverUnObjetoGenero(_tipoDeGenero).getNombreGenero();
 /*
 Objgen.setIDGenero(ArcGen.devolverUnObjetoGenero(var_genero).getIDGenero());
 strcpy(aux , ArcGen.devolverUnObjetoGenero(var_genero).getNombreGenero());
 Objgen.setNombreGenero(aux);

 Objgen.mostrar();
*/

_estado=true;
cout<<endl;

}



void Video::mostrar(){
cout<<"Titulo del Film: ";
cout<<_nombre;
cout<<endl;
cout<<"Descripcion: ";
cout<<_descripcion;
cout<<endl;
cout<<"Anio de Estreno: ";
cout<<_anioEstreno;
cout<<"."<<endl;
cout<<"ID-VIDEO: ";
cout<<_idVideo;
cout<<endl;
cout<<"Stock: ";
cout<<_stock;
cout<<"/"<<_stockLimite<<".";
cout<<endl;
cout<<"Duracion ";
cout<<_duracion;
cout<<" mins.";
cout<<endl;

ArchivoCategoria Prueba;
     cout<<"TIPO de Categoria ('Viejo= 1' ,'Normal= 2' ,'Clasico= 3' ,'Estreno= 4'): ";

 //const char* categoriaNOMBRE= _tipoDeCategoria.NombreDeUnaCategoria(Prueba.DevolverIDDeBandera());
 //cout<<categoriaNOMBRE;
 ///----------------------------
 Prueba.devolverObjCategoriaYInteres(_tipoDeCategoria).mostrarNombreCategoria();

 cout<<"Genero ('Accion= 1' ,'Romance= 2' ,'Comedia= 3' ,'Drama= 4' ,'Aventura= 5') : ";
ArchivoGenero ArcGen;
  cout<<ArcGen.devolverUnObjetoGenero(_tipoDeGenero).getNombreGenero()<<endl;
 /*
 const char* generoNOMBRE= _tipoDeGenero.generoSeleccionado(_tipoDeGenero.);
 cout<<generoNOMBRE;
 */
_estado=true;
cout<<"---------------------------------------------------------------------------------------------";
cout<<endl<<endl<<endl;


}


int Video::getIDVideo(){
return _idVideo;
}

 void Video::setStock(int stock){
    _stock = stock;
 }

int Video::getStock(){
return _stock;
}

void Video::MenosStock(int menosuno){
    _stock = _stock - menosuno;
 }

 void Video::MasStock(int masuno){
    _stock = _stock + masuno;
 }

 int Video::getStockLimite(){
 return _stockLimite;
 }

  void Video::setStockLimite(int stockLimite){
   _stockLimite = stockLimite ;
 }

  const char* Video::getNombreChar(){
    return _nombre;
  }

    void Video::setNombre(char nombre[50]){
    strcpy(_nombre , nombre);
     }

    const char* Video::getDescripcion(){
    return _descripcion;
    }

    void Video::setDescripcion(char descripcion[1500]){
     strcpy(_descripcion , descripcion);
    }

     int Video::getAnioEstreno(){
    return _anioEstreno;
     }

     void Video::setAnioEstreno(int anioEstreno){
      _anioEstreno = anioEstreno;
     }

     int Video::getDuracion(){
     return _anioEstreno;
     }

    void Video::setDuracion(int duracion){
    _duracion = duracion;
    }

    void Video::setTipoDeCategoria(int tipodeCategoria){
     _tipoDeCategoria = tipodeCategoria;
    }

    int Video::getTipoDeCategoria(){
    return _tipoDeCategoria;
    }

     int Video::getTipoDeInteres(){
    return _tipoDeInteres;
    }

    void Video::setTipoDeInteres(int tipo_de_interes){
    _tipoDeInteres = tipo_de_interes ;
    }

    void Video::setTipoDeGenero(int tipodeGenero){
    _tipoDeGenero = tipodeGenero;
    }

    int Video::getTipoDeGenero(){
    return _tipoDeGenero;
    }


std::string Video::getNombre() const{
return _nombre;
}

void Video::setIDVideo(int id_video){
 _idVideo = id_video;

}


       int Video::obtenerDiasDeRetraso()  {
              Categoria obj;
        return obj.getDiaDeDemoraPorCategoria();
    }

      float Video::obtenerImporteCategoria(){
             Categoria obj;
      return obj.getPrecioCategoria();
      }

    /*
      float Video::obtenerInteresCompuesto(){
          Categoria obj;

    return  obj.getInteresCompuesto();
      }

      float Video::obtenerInteresComun(){
             Categoria obj;
      return obj.getInteresComun();
      }
    */

      int Video::obtenerIDCategoria(){
             Categoria obj;
      return obj.getIDCATEG();
      }


    void Video::setEstado(bool estado){
        _estado = estado;
     }

    bool Video::getEstado(){
    return _estado;
    }



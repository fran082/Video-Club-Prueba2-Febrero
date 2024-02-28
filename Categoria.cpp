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
#include "Categoria.h"
#include "cargarCadena.h"


Categoria::Categoria(){

}

  void Categoria::cargar(){
      int nro_categoria = -100, nro_demora= -100;
      float nro_precio = -100, nro_comun = -100, nro_compuesto= -100;
  cout<<"Id de Categoria (1 al 4): ";
  while(nro_categoria < 1 || nro_categoria > 4 ){
  cin>>nro_categoria;

  }
  _idCategoria = nro_categoria;

  cout<<"Ingrese el Nombre de la categoria:  ";
  cargarCadena(_NombreCategoria, 15);
  cout<<"Ingrese el precio por alquilar una pelicula de la Categoria nombrada por ud. $";
 while(nro_precio < 0 ){
  cin>>nro_precio;

  }
  _PrecioPorCategoria = nro_precio;
  cout<<"Ingrese los dias minimos aceptados de demora para la devolucion: ";
   while(nro_demora > 5 || nro_demora < 3 ){
  cin>>nro_demora;

  }
  _DiaDeDemoraPorCategoria = nro_demora;
  cout<<endl<<"Ingrese el porcentaje que corresponde a Interes Comun %";
    while(nro_comun < 0 || nro_comun > 1){
  cin>>nro_comun;

  }
  /*
  if(nro_comun >= 1){
  nro_comun = nro_comun / 100;
  }
  */
  _InteresComun = nro_comun;
  cout<<endl<<"Ingrese el porcentaje que corresponde a Interes Compuesto %";
    while(nro_compuesto < 0 || nro_compuesto > 1 ){
  cin>>nro_compuesto;

  }
  /*
   if(nro_compuesto >= 1){
  nro_compuesto = nro_compuesto / 100;
  }
  */
 _InteresCompuesto = nro_compuesto;

  cout<<endl;
 _estado = true;
}

    void Categoria::mostrar(){
  cout<<"El id de Categoria es(1 al 4): ";
  cout<<_idCategoria;
  cout<<endl;
  cout<<"El Nombre de la categoria es '";
  cout<<_NombreCategoria<<"'";
  cout<<endl;
  cout<<"El precio por alquilar una pelicula de la Categoria nombrada es $";
  cout<<_PrecioPorCategoria;
  cout<<"."<<endl;
  cout<<"La cantidad de dias minimos de demora recomendados para la devolucion es de : ";
  cout<<_DiaDeDemoraPorCategoria;
  cout<<".";
 cout<<endl<<"Ingrese el Interes Comun $";
   cout<<_InteresComun * _PrecioPorCategoria;
   cout<<endl<<"Ingrese el Interes Compuesto $";
   cout<<_InteresCompuesto * _PrecioPorCategoria;
  cout<<endl;
 // cout<<"Estado : "<<_estado<<endl;

    }

    void Categoria::mostrarNombreCategoria(){
  cout<<_NombreCategoria;
  cout<<endl;
    }

 int Categoria::getIDCATEG(){
 return _idCategoria;
 }
    void Categoria::setIDCategoria(int id){
    _idCategoria = id;
    }

      const char* Categoria::getNombreCategoria(){
        return _NombreCategoria;
    }

        void Categoria::setNombreCategoria(char name[15]){
     //  strcpy( _NombreCategoria , name );

      // Usamos strncpy para copiar la cadena y asegurarnos de no desbordar el búfer
    // El segundo argumento es la fuente (name), el tercer argumento es el destino (_NombreCategoria)
    // El cuarto argumento es el tamaño máximo del destino
    strncpy(_NombreCategoria, name, sizeof(_NombreCategoria));
    _NombreCategoria[sizeof(_NombreCategoria) - 1] = '\0'; // Asegura que la cadena esté terminada con nulo
        }

   float  Categoria::getPrecioCategoria(){
   return _PrecioPorCategoria;
   }

    void Categoria::setPrecioPorCategoria(float precio){
    _PrecioPorCategoria = precio;
    }

  int Categoria::getDiaDeDemoraPorCategoria(){
  return _DiaDeDemoraPorCategoria;
  }

  void Categoria::setDiaDeDemoraPorCategoria(int dia){
  _DiaDeDemoraPorCategoria = dia;
  }

    /*
    float Categoria::UNINTERESCOMUN(int id){
        for(int i=0;i<4;i++){
         if(id-1 == i){
    return _InteresComun;

            }
        }
        return -3.14;
    }


    float Categoria::UNINTERESCOMPUESTO(int id){
        for(int i=0;i<4;i++){
         if(id-1 == i){
    return _InteresCompuesto;

            }
        }
        return -3.14;
    }
*/

      void Categoria::setInteresComun(float int_comun){
        _InteresComun = int_comun;
      }

    float Categoria::getInteresComun(){
    return _InteresComun;
    }


      void Categoria::setInteresCompuesto(float int_compuesto){
    _InteresCompuesto = int_compuesto;
    }

    float Categoria::getInteresCompuesto(){
    return _InteresCompuesto;
    }


    void Categoria::setEstado(bool estado){
    _estado = estado;
     }

    bool Categoria::getEstado(){
    return _estado;
    }




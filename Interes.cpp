///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cmath>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "Interes.h"
#include "ArchivoCategoria.h"

Interes::Interes(){
    /*
    ArchivoCategoria Precios;
    for(int i=0;i<4;i++){
 _vInteresComun[i] = Precios.cadaPrecioDeCategoria(i)   *0.20    ;
 _vInteresCompuesto[i] = Precios.cadaPrecioDeCategoria(i)    *0.40   ;
    }
*/
}

void Interes::cargar(){
cout<<"Ingrese el ID del interes:";
cin>>_idInteresesGeneral;
cout<<endl<<"Ingrese el Interes Comun $";
cin>>_InteresComun;
cout<<endl<<"Ingrese el Interes Compuesto $";
cin>>_InteresCompuesto;
cout<<endl;
}

void Interes::mostrar(){
cout<<endl;

    cout<<"DESPUES DE UNA DEMORA DE (Viejo=5 dias ,Clasico=4 dias ,Normal=3 dias ,Estreno=3 dias ) SE COBRA UN INTERES COMUN Y PASADO EL MES UN INTERES COMPUESTO, COMO MUESTRA EL SIGUIENTE TEXTO:"<<endl;
    cout<<endl;
    std::string v_categ[4]= {"Viejo","Normal","Clasico","Estreno"};
    for(int k=0;k<4;k++){
if(_idInteresesGeneral == k+1){
cout<<"Por cada dia transcurrido de no devolver la pelicula de Categoria ("<<v_categ[k]<<") se cobro un interes con el monto de Interes Comun de $"<< _InteresComun<<"."<<endl;

cout<<endl;

cout<<"Por cada dia transcurrido de no devolver la pelicula de Categoria ("<<v_categ[k]<<") se cobro un interes con el monto de Interes Compuesto de $"<< _InteresCompuesto<<"."<<endl;

cout<<endl;
cout<<"---------------------------------------------------------------------"<<endl;
}
}
}
    int Interes::retornarIDValido(int id){
    for(int i=1;i<5;i++){
        if(id == getIDInteresGeneral()){
            return id;
        }

    }
    return -1;
    }

    float Interes::UNINTERESCOMUN(int id){
        for(int i=0;i<4;i++){
         if(id-1 == i){
    return _InteresComun;

            }
        }
        return -3.14;
    }


    float Interes::UNINTERESCOMPUESTO(int id){
        for(int i=0;i<4;i++){
         if(id-1 == i){
    return _InteresCompuesto;

            }
        }
        return -3.14;
    }


      void Interes::setInteresComun(float int_comun){
        _InteresComun = int_comun;
      }

    float Interes::getInteresComun(){
    return _InteresComun;
    }


      void Interes::setInteresCompuesto(float int_compuesto){
    _InteresCompuesto = int_compuesto;
    }

    float Interes::getInteresCompuesto(){
    return _InteresCompuesto;
    }


      void Interes::setIDInteresGeneral(int id){
    _idInteresesGeneral = id;
    }

    int Interes::getIDInteresGeneral(){
    return _idInteresesGeneral;
    }


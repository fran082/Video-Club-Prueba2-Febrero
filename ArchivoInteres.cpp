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

#include "ArchivoInteres.h"
#include "Interes.h"

ArchivoInteres::ArchivoInteres(){
            strcpy(nombre , "Intereses.dat");
        }


void ArchivoInteres::agregarRegistro(){
    Interes obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    obj.cargar();
  //  obj.set_Id(ultimoPelicula()+1);
	fwrite(&obj, sizeof (obj), 1, pIng);
	fclose(pIng);
}




void ArchivoInteres::mostrarRegistros(){
    Interes obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, p)==1){
        obj.mostrar();
        /*
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"----------------------------"<<endl;
            cout<<endl;
        }
        */
	}
	fclose(p);
}

 Interes ArchivoInteres::leerRegistro(int pos){
        Interes reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    Interes ArchivoInteres::devolverUnObjetoInteres(int id){
     Interes obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
       // return "NO SE PUDO CREAR EL ARCHIVO";
cout<<"NO SE PUDO CREAR EL ARCHIVO";
system("pause");
    }

	while(fread(&obj, sizeof obj, 1, p)==1){

    if(obj.retornarIDValido(id) == id){
    fclose(p);
    return obj;

    }
	}
    fclose(p);
    return obj; //Cambiar algo del obj para que se note la diferencia del error. Buscar una alternativa. Validaciones !
   }







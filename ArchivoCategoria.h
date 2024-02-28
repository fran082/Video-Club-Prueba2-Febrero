#ifndef ARCHIVOCATEGORIA_H
#define ARCHIVOCATEGORIA_H

#include "Categoria.h"

class ArchivoCategoria
{   //MISMA CANTIDAD DE 'H' Y 'CPP'
    public:
        ArchivoCategoria();

    void agregarRegistro();
 Categoria leerRegistro(int pos);
    void mostrarRegistros();
    int modificarRegistro();

    int guardarCambioDeProp(Categoria &obj, int pos, int idCategoria);

        bool guardar(Categoria *vec, int cantidadRegistrosAEscribir);
         bool guardarBackup(Categoria *vec, int cantidadRegistrosAEscribir);
         int hacerCopiaDeSeguridad();
         int restaurarBackup();
         void leer(Categoria *vec, int cantidadRegistrosALeer);
         void leerBackup(Categoria *vec, int cantidadRegistrosALeer);
         void vaciar();
         void vaciarBackup();
         int cantidadRegistros();
         int cantidadRegistrosBackup();

 //  Categoria unNombreDeCategoria(int id); //Fue modificada, se le puede quitar el if si se hace una validacion

    Categoria devolverObjCategoriaYInteres(int id);

    int devolverIDMinimo();
    int devolverIDMaximo();
    int buscarIDCategoriaPorParametro(int idCategoria);

   private:
    char nombre[30];
    char bkp[30]="CatYIntBackup.bkp";
};

#endif // ARCHIVOCATEGORIA_H

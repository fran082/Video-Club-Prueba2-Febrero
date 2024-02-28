#ifndef ARCHIVOGENERO_H
#define ARCHIVOGENERO_H

#include "Genero.h"

class ArchivoGenero
{   //MISMA CANTIDAD DE FUNCIONES EN EL 'H' Y EL 'CPP'
    public:
        ArchivoGenero();
    void agregarRegistro();
    void mostrarRegistros();

         bool guardar(Genero *vec, int cantidadRegistrosAEscribir);
         bool guardarBackup(Genero *vec, int cantidadRegistrosAEscribir);
         int hacerCopiaDeSeguridad();
         int restaurarBackup();
         void leer(Genero *vec, int cantidadRegistrosALeer);
         void leerBackup(Genero *vec, int cantidadRegistrosALeer);
         void vaciar();
         void vaciarBackup();
         int cantidadRegistros();
         int cantidadRegistrosBackup();

    int devolverIDMinimo();
    int devolverIDMaximo();
    int buscarIDGeneroPorParametro(int idGenero);

   // const char* devolverGenero(int numero);
    Genero devolverUnObjetoGenero(int id);


    private:
    char nombre[30];
    char bkp[30]="GenerosBackup.bkp";
};

#endif // ARCHIVOGENERO_H

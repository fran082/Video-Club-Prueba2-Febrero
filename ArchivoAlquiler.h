#ifndef ARCHIVOALQUILER_H
#define ARCHIVOALQUILER_H

#include "FechaHorario.h"
#include "Alquiler.h"

class ArchivoAlquiler{
    //MISMA CANTIDAD DE FUNCINOES EN 'H' Y 'CPP'
    public:
        ArchivoAlquiler();
        void agregarRegistro();
        void mostrarRegistros();
        int bajaLogicaRegistro();
        void mostrarRegistrosMenosInfo();
        void mostrarRegistrosMasInfo();
            void mostrarAlquilerPorIDCliente(int IDCliente, FechaHorario Inicio, FechaHorario Final);
            void mostrarAlquilerPorCategoria(int genero, FechaHorario Inicio, FechaHorario Final);
            void mostrarAlquilerPorGenero(int categoria, FechaHorario Inicio, FechaHorario Final);
            void mostrarAlquilerPorIDVideo(int idVideo, FechaHorario Inicio, FechaHorario Final);
            void mostrarRecaudacionDeAlquileres( FechaHorario Inicio, FechaHorario Final);

         bool guardar(Alquiler *vec, int cantidadRegistrosAEscribir);
         bool guardarBackup(Alquiler *vec, int cantidadRegistrosAEscribir);
         int hacerCopiaDeSeguridad();
         int restaurarBackup();
         void leer(Alquiler *vec, int cantidadRegistrosALeer);
         void leerBackup(Alquiler *vec, int cantidadRegistrosALeer);
         void vaciar();
         void vaciarBackup();
         int cantidadRegistros();
         int cantidadRegistrosBackup();

    int cancelarAlquilerEnProceso(int id_Cliente, int id_PeliculaAAlquilar);
    int noPuedeAlquilar(int IDCliente);
    int laTieneAlquilada(int idCliente , int idVideo);
    //int existeFechaDeAlquiler(int idAlquiler);
    int existeIDAlquiler(int idAlquiler);

    Alquiler devuelveAlquilerInicial(int idCliente, int idVideoAlquilado);
    int terminarDevolucionAlquiler(int idCliente, Alquiler &objCargar, int idVideoAlquilado );

    int guardarCambioDeProp(Alquiler &obj, int pos);

    int RankingGenereral(FechaHorario Inicio , FechaHorario Final);
    void listadoDeAlquileresPendientes();

    bool esMayorFechaHorario( FechaHorario otra , FechaHorario Inicio ) const ;
    bool esMenorFechaHorario( FechaHorario otra , FechaHorario Final ) const ;

    void ordenarDeMayorAMenorTresVectores(int *vecCant, int *vecID, bool *vecHecho, int dimension);

    private:
     char nombre[30];
     char bkp[30]="AlquileresBackup.bkp";
};

#endif // ARCHIVOALQUILER_H

#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H

#include "Cliente.h"

class ArchivoCliente
{   //MISMA CANTIDAD DE 'H' Y 'CPP'
    public:
        ArchivoCliente();
        void agregarRegistro();
        void mostrarRegistros();
        void buscarClientePorName();
        void buscarClientePorID();
        int modificarRegistro();
        int bajaLogicaRegistro();

         bool guardar(Cliente *vec, int cantidadRegistrosAEscribir);
         bool guardarBackup(Cliente *vec, int cantidadRegistrosAEscribir);
         int hacerCopiaDeSeguridad();
         int restaurarBackup();
         void leer(Cliente *vec, int cantidadRegistrosALeer);
         void leerBackup(Cliente *vec, int cantidadRegistrosALeer);
         void vaciar();
         void vaciarBackup();
         int cantidadRegistros();
         int cantidadRegistrosBackup();


        int devuelveIDClienteACambioDeName(const char* name);
        const char* devuelveNombreYApellidoAcambioDeID(int id);
        int guardarCambioDeProp(Cliente &obj, int pos, int idCliente);
        int banearCliente();
        int devolverIDMinimo();
        int devolverIDMaximo();
        int clienteExiste(int id_cliente);

    private:
     char nombre[30];
     char bkp[30]="ClientesBackup.bkp";
};

#endif // ARCHIVOCLIENTE_H

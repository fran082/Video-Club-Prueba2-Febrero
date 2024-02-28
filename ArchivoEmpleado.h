#ifndef ARCHIVOEMPLEADO_H
#define ARCHIVOEMPLEADO_H

#include "Empleado.h"

class ArchivoEmpleado
{   //MISMA CANTIDAD DE 'H' Y 'CPP'
    public:
        ArchivoEmpleado();
        void agregarRegistro();
        void mostrarRegistros();
        void buscarEmpleadoPorName();
        void buscarEmpleadoPorID();
        int modificarRegistro();
        int bajaLogicaRegistro();

         bool guardar(Empleado *vec, int cantidadRegistrosAEscribir);
         bool guardarBackup(Empleado *vec, int cantidadRegistrosAEscribir);
         int hacerCopiaDeSeguridad();
         int restaurarBackup();
         void leer(Empleado *vec, int cantidadRegistrosALeer);
         void leerBackup(Empleado *vec, int cantidadRegistrosALeer);
         void vaciar();
         void vaciarBackup();
         int cantidadRegistros();
         int cantidadRegistrosBackup();

//        int devuelveIDEmpleadoACambioDeName(const char* name);
const char* devuelveNameACambioDeIDEmpleado(int id);

        int guardarCambioDeProp(Empleado &obj, int pos, int idEmpleado);

        int devolverIDMinimo();
        int devolverIDMaximo();
        int empleadoExiste(int id_empleado);


    private:
     char nombre[30];
     char bkp[30]="EmpleadosBackup.bkp";
};

#endif // ARCHIVOEMPLEADO_H

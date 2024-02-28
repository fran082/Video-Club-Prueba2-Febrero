#ifndef ARCHIVOINTERES_H
#define ARCHIVOINTERES_H

#include "Interes.h"

class ArchivoInteres
{
    public:
        ArchivoInteres();
    void agregarRegistro();
    void mostrarRegistros();
    Interes leerRegistro(int pos);
     devolverUnObjetoInteres(int id);


    private:
    char nombre[30];
    char bkp[30]="Intereses.bkp";
};

#endif // ARCHIVOINTERES_H

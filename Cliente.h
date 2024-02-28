#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona{
    public:
    void cargar();
    void mostrar();

    int getIDCliente();
    void setIDCliente(int idCliente);
    bool getBaneado();
    void setBaneado(bool baneado);
    void setEstado(bool estado);
    bool getEstado();

    private:
    int _idCliente;
    bool _baneado;
    bool _estado;
};

#endif // CLIENTE_H

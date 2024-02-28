#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona
{   //FALTAN SOLAMENTE VALIDACIONES , NO HAY FUNCIONES DUPLICADAS O EN DESUSO/VIEJAS
    public:
    void cargar();
    void mostrar();

    int getIDEmpleado();
    void setIDEmpleado(int idEmpleado);
    void setEstado(bool estado);
    bool  getEstado();

    private:
    int _idEmpleado;
    bool _estado;
};

#endif // EMPLEADO_H

#ifndef PERSONA_H
#define PERSONA_H

#include "Fecha.h"

class Persona
{   //MISMA CANTIDAD DE FUNCIONES EN EL 'H' Y EL 'CPP'
    public:
    Persona();

    void cargar();
    void mostrar();

    void setDNI(int dni);
    int getDNI();
    void setSexo(char sexo);
    const char* getSexo();
    void setApellidoYNombre(char apellidoYNombre[50]);
    const char* getApellidoYNombre();
    void setNacimiento(int dia, int mes, int anio);
    Fecha getNacimiento();
    void setDomicilio(char domicilio[50]);
    const char* getDomicilio();
    void setTelefono(long long telefono);
    long long getTelefono();
    void setEmail(char email[50]);
    const char* getEmail();


    private:
    int _dni;
    char _sexo;
    char _apellidoYNombre[50];
    Fecha _nacimiento;
    char _domicilio[50];
    long long _telefono;
    char _email[50];

};

#endif // PERSONA_H

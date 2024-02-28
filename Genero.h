#ifndef GENERO_H
#define GENERO_H


class Genero
{   //MISMA CANTIDAD DE 'H' Y 'CPP' DE FUNCIONES
    public:
        Genero();
    void cargar();
    void mostrar();
  //  const char* generoSeleccionado(int eleccion);

    const char* getNombreGenero();
    void setNombreGenero(char name[50]);
    void setIDGenero(int id);
    int  getIDGenero();
    void setEstado(bool estado);
    bool  getEstado();

    private:
        ///Agregar _igGenero;
    char _NombreGenero[50];
    int _idGenero;
    bool _estado;
};

#endif // GENERO_H

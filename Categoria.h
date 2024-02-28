#ifndef CATEGORIA_H
#define CATEGORIA_H


class Categoria
{   //FALTAN SOLAMENTE LAS VALIDACIONES, NO HAY FUNCIONES DE MAS
    public:
        Categoria();

    void cargar();
    void mostrar();
    void mostrarNombreCategoria();

    int getIDCATEG();
    void setIDCategoria(int id);
    const char* getNombreCategoria();
    void setNombreCategoria(char name[15]);
    float getPrecioCategoria();
    void setPrecioPorCategoria(float precio);
    int getDiaDeDemoraPorCategoria();
    void setDiaDeDemoraPorCategoria(int dia);
    void setInteresComun(float int_comun);
    float getInteresComun();
    void setInteresCompuesto(float int_compuesto);
    float getInteresCompuesto();
    void setEstado(bool estado);
    bool getEstado();

  //  float UNINTERESCOMUN(int id);
  //  float UNINTERESCOMPUESTO(int id);

    private:
    int _idCategoria;
   char  _NombreCategoria[15];
   float _PrecioPorCategoria;
   int _DiaDeDemoraPorCategoria;
   float _InteresComun;
   float _InteresCompuesto;
   bool _estado;

};

#endif // CATEGORIA_H

#ifndef INTERES_H
#define INTERES_H


class Interes
{
    public:
        Interes();

    void cargar();
    void mostrar();
    float UNINTERESCOMUN(int id);
    float UNINTERESCOMPUESTO(int id);
    int retornarIDValido(int id);

    void setInteresComun(float int_comun);
    float getInteresComun();

    void setInteresCompuesto(float int_compuesto);
    float getInteresCompuesto();

    void setIDInteresGeneral(int id);
    int getIDInteresGeneral();


    private:
    int  _idInteresesGeneral;
    float _InteresComun;
    float _InteresCompuesto;
};

#endif // INTERES_H

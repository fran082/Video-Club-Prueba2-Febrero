#ifndef PALABRACLAVE_H
#define PALABRACLAVE_H


class PalabraClave
{   //MISMA CANTIDAD DE FUNCIONES EN EL 'H' Y EL 'CPP'
    public:
    PalabraClave();

    void cargar();
    void mostrar();


    void setIDPalabraClave(int idPalabraClave);
    int getIDPalabraClave();

    void setIDVideo(int idvideo);
    int getIDVideo();

    void setPalabraClave(char wordClave[50]);
    const char* getPalabraClave();

    void setEstado(int estado);
    bool getEstado();


    private:
    int _idPalabraClave;
    int _idVideo;
    char _palabraClave[50];
    bool _estado;
};

#endif // PALABRACLAVE_H

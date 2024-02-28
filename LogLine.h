#ifndef LOGLINE_H
#define LOGLINE_H


class LogLine
{
    public:

    LogLine();

    void cargar();
    void mostrar();

    void setIDVideoLogLine(int idVideoLogLine);
    int getIDVideoLogLine();
    void setPalabraRecomendacion(char palabraRecomendacion[50]);
    const char* getPalabraRecomendacion();


    private:
    int _idVideoLogLine;
    char _palabraRecomendacion[50];

};

#endif // LOGLINE_H

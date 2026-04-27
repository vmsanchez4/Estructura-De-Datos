#ifndef IMATRIZ_H
#define IMATRIZ_H

class IMatriz {
public:
    virtual ~IMatriz() {}
    virtual void setElemento(int, int, int, float) = 0;
    virtual float getElemento(int, int, int) const = 0;
    virtual void setMatriz(float***) = 0;
    virtual float*** getMatriz() const = 0;
    virtual int getCapa() const = 0;
    virtual void setCapa(int) = 0;
    virtual int getFila() const = 0;
    virtual void setFila(int) = 0;
    virtual int getColumna() const = 0;
    virtual void setColumna(int) = 0;
    virtual void encerar(float***, int, int, int) = 0;
};
#endif
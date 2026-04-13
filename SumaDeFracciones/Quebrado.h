/***********************************************************************
 * Module:  Quebrado.h
 * Author:  Vicente
 * Modified: jueves, 9 de abril de 2026 21:24:16
 * Purpose: Declaration of the class Quebrado
 ***********************************************************************/

#if !defined(__SumaFracciones_Quebrado_h)
#define __SumaFracciones_Quebrado_h

class Quebrado
{
public:
    Quebrado();
    float getDenominador();
    void setNumerador(float num);   
    float getNumerador();
    void setDenominador(float den); 
    Quebrado sumar(Quebrado sum);  

protected:
private:
    float numerador;
    float denominador;
};

#endif
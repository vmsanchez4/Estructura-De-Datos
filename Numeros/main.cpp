#include <cstdlib>
#include <iostream>
#include <conio.h> 
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int ingresarNumeros(char *);

int ingresarNumeros(char *msj){
    printf("%s", msj);
    char dat[10];
    char c;
    int i = 0, valor;
    while((c = _getch()) != 13){ 
        if(c >= '0' && c <= '9' && i < 9){ 
            printf("%c", c);
            dat[i++] = c;
        }
    }
    dat[i] = '\0';
    valor = atoi(dat);
    return valor;  
}

int main(int argc, char *argv[])
{
    int valor; 
    valor = ingresarNumeros("Ingrese el valor entero!: ");
    printf("\nEl dato ingresado es: %d\n", valor);
    
    return 0;
}
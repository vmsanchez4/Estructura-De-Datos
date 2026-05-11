#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int ingresarNumeros(char*);
int ingresarNumeros(char *msj){
    printf("%s",msj);
    char datos[10];
    char c;
    int i=0;
    while((c=getch())!=13){
        if(c>'0'&& c<'9'){
            printf("%c",c);
            datos[i++]=c;
        }
    }
    datos[i]='\0';
    int valor=atoi(datos);
    return valor;
}

int main()
{
    int valor;
    valor=ingresarNumeros("Ingrese el valor entero!: ");
    cout<<valor;
    return 0;
}

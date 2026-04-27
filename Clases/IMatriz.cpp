#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
//Prototipo
void encerar(float**, int , int );
void ingresar(float**,int , int  );
void imprimir(float**,int , int  );
void procesar(float**,float**,float***, int , int );


//pr
void encerar(float **mat,int fila, int columna){
    int i,j;
    for(i=0;i<fila;i++){
        for(j=0;j<columna;j++){
            mat[i][j]=0;
        }
    }
}

void ingresar(float **mat,int fila, int columna){
    int i,j;
    for(i=0;i<fila;i++){
        for(j=0;j<columna;j++){
            cout<<"ingrese ["<<i<<"]["<<j<<"]:"<<endl;
            //scanf("%f",mat[i][j]);
            scanf("%f",*(*(&mat)+i)+j);
        }
    }
}

void imprimir(float **mat, int fila, int columna) {
    for (int i = 0; i < fila; i++) {
        cout << "[ "; 
        for (int j = 0; j < columna; j++) {
            cout << *(*(mat + i) + j);
            if (j < columna - 1) {
                cout << "\t";
            }
        }
        cout << " ]\n"; 
    }
}

int main(int argc, char** argv){
    int fila=3,col=3;
    //ingresar datos aparte nunca mezclar
    //float mat[3][3];
    //funcion llamada segmentar mandar
    float **mat;
    //reservando
    mat = (float**)malloc(4*sizeof(int*));
    
    for(int i=0;i<fila;i++){
        mat[i]=(float*)malloc(sizeof(float)*col);
    }

    encerar(mat,fila,col);
    //ingresar(mat,fila,col);
    imprimir(mat,fila,col);
    ingresar(mat,fila,col);
    imprimir(mat,fila,col);

    return 0;
}
//poner en clases con getters y setters
//segmentacion sin corchetez
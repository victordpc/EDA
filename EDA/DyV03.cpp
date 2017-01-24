//
//  DyV03.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 24/1/17.
//  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void llenarDatos(int& numerosCarton, int& cantado, int* vector, istream& sin);
int bingo(int numerosCarton, int cantado, int* vector);
int bingo(int n, int buscado, int* vector,int i, int j);

int bingo(int n, int buscado, int* vector,int i, int j){
    int medio=(j+i)/2;
    
    if (j-i == 0){
        if (vector[medio] == buscado + medio) {
            return vector[medio];
        }else{
            return -1;
        }
    }else if(vector[medio] == buscado + medio){
        return vector[medio];
    }else if(vector[medio] > buscado + medio){
        return bingo(n,buscado,vector,i,medio);
    }else{
        return bingo(n, buscado, vector,medio+1,j);
    }
}

int bingo(int numerosCarton, int cantado, int* vector){
    if (numerosCarton == 1){
        if(vector[0] == cantado)
            return cantado;
        else
            return -1;
    }else{
        return bingo(numerosCarton, cantado, vector,0,numerosCarton-1);
    }
}

void llenarDatos(int numerosCarton, int* vector, istream& sin){
    for (int i=0; i<numerosCarton; i++) {
        sin>>vector[i];
    }
}

int main(){
    int casos=0;
    cin >> casos;
    
    while (casos>0){
        int numerosCarton=0, cantado=0;
        int * v=nullptr;
        int valor=0;
        
        cin>> numerosCarton >> cantado;
        v = new int[numerosCarton];
        
        llenarDatos(numerosCarton,v,cin);
        
        valor = bingo(numerosCarton, cantado, v);
        
        if (valor == -1) {
            cout << "NO";
        }else{
            cout << valor;
        }
        cout << endl;
        
        delete[] v;
        numerosCarton=0;
        cantado=0;
        valor=0;
        casos--;
    }
}

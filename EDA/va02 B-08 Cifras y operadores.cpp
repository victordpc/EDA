//
//  va02.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 31/1/17.
//  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
//

#include <stdio.h>
#include "iostream"

using namespace std;

void rellenar(int* numeros, istream& sin);
string calcular(int* numeros, int resultado);
bool calcular(int k, int* numeros, int resultado, int acumulado);

bool calcular(int k, int* numeros, int resultado, int acumulado){
    if(k == 5){
        if(acumulado == resultado)
            return true;
        return false;
    }else{
        if(calcular(k + 1, numeros, resultado, acumulado + numeros[k]))
            return true;
        if(calcular(k + 1, numeros, resultado, acumulado - numeros[k]))
            return true;
        if(calcular(k + 1, numeros, resultado, acumulado * numeros[k]))
            return true;
        if((acumulado % numeros[k])==0
           && (calcular(k + 1, numeros, resultado, acumulado / numeros[k])))
            return true;
        return false;
    }
}

string calcular(int* numeros, int resultado){
    if(calcular(1, numeros, resultado, numeros[0]))
        return "SI";
    return "NO";
}

void rellenar(int* numeros, istream& sin){
    for (int i = 0; i < 5; i++) {
        sin >> numeros[i];
    }
}

int main(){
    int resultado=0;
    int* numeros;
    
    while(cin >> resultado){
        numeros = new int[5];
        rellenar(numeros, cin);
 
        cout << calcular(numeros, resultado) <<  endl;
        
        delete [] numeros;
        resultado = 0;
    }
}

//
//  iter16.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 11/11/16.
//  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void leerVector(int* v, int n, istream& sin);
void calcular(int* a, int n, int &p, int &v);


void leerVector(int* v, int n, istream& sin) {
    for (int i = 0; i < n; i++)
        sin >> v[i];
}

int main() {
    int n,p=0,v=0;
    int* a;
    
    cin >> n;
    while  (n!=0){
        // Lectura de otros parametros
        a = new int[n];
        leerVector(a, n, cin);
        
        // Llamada a la funcion que implementa el algoritmo que se pide
        calcular(a,n,v,p);
        
        // Salida
        cout << p << " " << v << endl;
        delete[] a;
        p = v = 0;
        
        cin >> n;
    }
    return 0;
}

void calcular(int* a, int n, int &p, int &v){
    int i = 0, k = -2;
    while (i < n){
        if(k >= 0)
        {
            if(a[i]%2 == 0 && a[k]%2 ==0)
                v++;
            if(a[i]%2 != 0 && a[k]%2 != 0)
                p++;
        }
        i++; k++;
    }
}

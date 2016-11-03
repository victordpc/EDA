//
//  182.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 3/11/16.
//  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
//

#include <iostream>

using namespace std;

int persistenciaMultiplicativa(int numero);

int main(){
    int casos = 0;
    int numero;
    
    cin >> casos;
    
    while (casos > 0){
        
        numero =0;
        cin >> numero;

        if (numero/10 != 0)
            cout << persistenciaMultiplicativa(numero);
        else
            cout << "0";
        
        cout  << "\n";
        casos--;
    }
    return 0;
}

int persistenciaMultiplicativa(int numero)
{
    int resultado=1;
    int nuevoNumero=1;
    bool salir = false;
    
    while(!salir){
        nuevoNumero*=numero%10;
        numero/=10;
        salir = numero == 0;
    }
    
    if (nuevoNumero/10 != 0)
        resultado += persistenciaMultiplicativa(nuevoNumero);
    
    return resultado;
}


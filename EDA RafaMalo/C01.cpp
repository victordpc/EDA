//
//  C01.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 3/3/17.
//  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

unsigned long long log(unsigned long long b, unsigned long long n);

int main(){
    unsigned long long b = 0, n = 0;
    unsigned long long casos = 0;
    
    cin >> casos;
    
    while(casos > 0){
        cin >> b >> n;
        
        cout << log(b,n) << endl;
        --casos;
    }
}

unsigned long long log(unsigned long long b, unsigned long long n){
    if (n==1)
        return 0;
    
    unsigned long long acumulado=1;
    int resultado=0;
    //n=n/b;
    
    while (acumulado < n){
        acumulado *=b;
        resultado++;
    }
    
    return resultado;
}

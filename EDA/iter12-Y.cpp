//
//  main.cpp
//  Iter12
//
//  Created by Yhondri on 21/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void numPatronRepetido(string cadena, string patron);

int main(int argc, const char * argv[]) {
    string line;
    while (getline(cin, line))
    {
        //    cout << "Introduce cadeta de texto: " << endl;
//        getline(cin, line);
        //    cout << "Introduce patrón: " << endl;
        string pattern;
        getline(cin, pattern);
        numPatronRepetido(line, pattern);
    }
    return 0;
}

void numPatronRepetido(string cadena, string patron) {
    int contador = 0;
    string acumulador;

    for (int i = 0; i < (int)cadena.length(); i++) {
        if (i < (int)cadena.length()) {
            acumulador += cadena[i];
        }
        
        if (acumulador == patron) {
            contador++;
        }
        
        if (acumulador.length() == patron.length()) {
            if (acumulador.length() > 1) {
                i -= (acumulador.length() - 1);
            }
            acumulador = "";
        }
    }
    cout << contador << endl;
}

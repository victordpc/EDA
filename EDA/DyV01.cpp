////
////  DyV01.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 8/2/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//#include <fstream>
//#include <cstdlib>
//
//using namespace std;
//
//void leerVector(char* v, int n, istream& sin);
//char Presos(char* v, int n, char inicial);
//char Presos(char* v, int i, int j,char inicial);
//
//void leerVector(char* v, int n, istream& sin) {
//    for (int i = 0; i < n; i++)
//        sin >> v[i];
//}
//
//int main() {
//    int numCasos, n;
//    char ini, fin;
//    char* v;
//    cin >> numCasos;
//    
//    for (int i = 0; i < numCasos; i++) {
//        cin >> ini >> fin;
//        n = fin - ini;
//        
//        // Lectura de otros parametros
//        v = new char[n];
//        leerVector(v, n, cin);
//        
//        // Llamada a la funcion que implementa el algoritmo que se pide
//        cout << Presos(v, n, ini) << endl;
//
//        // Salida
//        delete[] v;
//    }
//}
//
//char Presos(char* v, int n, char inicial){
//    if (n == 1){
//        if(v[0] != inicial){
//            return inicial;
//        }else{
//            return inicial + 1;
//        }
//    }
//    return Presos(v, 0, n-1, inicial);
//}
//
//char Presos(char* v, int i, int j,char inicial){
//    int mitad = (j + i) / 2;
//    
//    if(i==j)
//    {
//        if (v[i] == inicial + i)
//            return inicial + i + 1;
//        else
//            return inicial + i;
//    }else if(v[mitad] == inicial + mitad){
//        return Presos(v, mitad + 1, j, inicial);
//    }else{
//        return Presos(v, i, mitad, inicial);
//    }
//}

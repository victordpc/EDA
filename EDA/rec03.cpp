////
////  rec03.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 1/12/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//
//using namespace std;
//
//void leerVector(int* v, int n, istream& sin);
//int ingresosFinal(int* v,int n);
//int ingresosFinalAux(int* v,int n,int i,int mult,int acu);
//int ingresosNoFinal(int* v,int n);
//int ingresosNoFinalAux(int* v,int n,int i,int mult);
//
//void leerVector(int* v, int n, istream& sin) {
//    for (int i = 0; i < n; i++)
//        sin >> v[i];
//}
//
//int main() {
//    int numCasos, n;
//    int* v;
//    cin >> numCasos;
//    for (int i = 0; i < numCasos; i++) {
//        cin >> n;
//        // Lectura de otros parametros
//        v = new int[n];
//        leerVector(v, n, cin);
//        // Llamada a la funcion que implementa el algoritmo que se pide
//        cout << ingresosFinal(v, n);
//        cout << ingresosNoFinal(v,n);
//        
//
//        // Salida
//        delete[] v;
//    }
//}
//
//int ingresosNoFinal(int* v, int n){
//    return ingresosNoFinalAux(v, n, 0, 1);
//}
//
//int ingresosNoFinalAux(int* v, int n,int i,int mult){
//    int resultado=0;
//    if(i<=n/2) resultado = ingresosNoFinalAux(v, n,i+1,mult*2);
//    return resultado + (v[i]+v[n-i])*mult;
//}
//
//
//int ingresosFinal(int* v, int n){
//    return ingresosFinalAux(v, n, 0, 1,0);
//}
//
//int ingresosFinalAux(int* v, int n,int i,int mult,int acu){
//    int resultado=0;
//    if(i<=n/2) resultado = ingresosFinalAux(v, n,i+1,mult*2,acu);
//    return resultado + (v[i]+v[n-i])*mult;
//    
//    if(i>n) return 0;
//    else return ingresosFinalAux(v, n, i+1, mult*2, acu)
//}
//
//
//
//
//
//

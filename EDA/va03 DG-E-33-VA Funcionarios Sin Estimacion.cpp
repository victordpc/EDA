////
////  va03.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 8/2/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//
//using namespace std;
//
//void rellenar(bool* marcado, int** matriz, int numero,istream& sin, int& mejorSolucion);
//int vueltaAtras(int**matriz, int numero);
//void vueltaAtras(int k, int**matriz, int numero, int acumulado, int& mejorSolucion, bool* marcado);
//bool esSolucion(int k,int n);
//bool esMejorSolucion(int acumulado, int mejorSolucion);
//bool esPosible(bool* marcado, int i);
//
//bool esPosible(bool* marcado, int i){
//    return !marcado[i];
//}
//
//bool esMejorSolucion(int acumulado, int mejorSolucion){
//    return acumulado<mejorSolucion;
//}
//
//bool esSolucion(int k, int n){
//    return k==n-1;
//}
//
//void vueltaAtras(int k, int**matriz, int numero, int acumulado, int& mejorSolucion, bool* marcado){
//    for (int i =0; i < numero; i++) {
//        acumulado+=matriz[k][i];
//        if(esPosible(marcado,i)){
//            if(esSolucion(k,numero)){
//                if(esMejorSolucion(acumulado,mejorSolucion)){
//                    mejorSolucion=acumulado;
//                }
//            }else{
//             
//                marcado[i]=true;
//                vueltaAtras(k+1, matriz, numero, acumulado, mejorSolucion,marcado);
//
//                marcado[i]=false;
//            }
//        
//        }
//        acumulado-=matriz[k][i];
//    }
//}
//
//int vueltaAtras(int**matriz, int numero){
//    int mejorSolucion=0;
//    bool* marcado;
//    
//    matriz = new int*[numero];
//    marcado = new bool[numero];
//    
//    rellenar(marcado, matriz, numero, cin, mejorSolucion);
//    
//    vueltaAtras(0, matriz, numero, 0, mejorSolucion, marcado);
//    
//    return mejorSolucion;
//}
//
//
//void rellenar(bool* marcado, int** matriz, int numero,istream& sin, int& mejorSolucion){
//    for (int i=0 ; i<numero; i++) {
//        matriz[i]=new int[numero];
//        marcado[i] = false;
//        
//        for (int j=0; j<numero; j++) {
//            sin >> matriz[i][j];
//            mejorSolucion+=matriz[i][j];
//        }
//    }
//}
//
//int main(){
//    int numero =0;
//    int** matriz;
//    cin >> numero;
//    
//    while ( numero!=0) {
//        
//        cout << vueltaAtras(matriz, numero) << endl;
//        
//        cin >> numero;
//    }
//    
//    
//}

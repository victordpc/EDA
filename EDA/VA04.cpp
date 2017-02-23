////
////  VA04.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 9/2/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//#include "string"
//
//using namespace std;
//
//struct tCasilla{
//    int fila;
//    int columna;
//};
//
//void camino(int n);
//void caminoVA(tCasilla actual, int** mapa, int hMax, tCasilla fin, bool** marcado, tCasilla* camino, int coste, tCasilla* mejorCamino, int& mejorCoste, int n);
//void direccion(tCasilla& actual, int dir, int& coste);
//void desDireccion(tCasilla& actual, int dir, int& coste);
//void copiaSolucion(int coste,int& mejorCoste,tCasilla* camino,tCasilla* mejorCamino);
//bool esSolucion(tCasilla actual, tCasilla fin);
//bool esValido(tCasilla actual,bool** marcado,int alturaAntes,int** mapa, int hMax, tCasilla fin, int coste, int mejorCoste, int n);
//
//bool esValido(tCasilla actual,bool** marcado,int alturaAntes,int ** mapa, int hMax, tCasilla fin, int coste, int mejorCoste, int n){
//    int sumarCasillas=0;
//    
//    if(actual.fila >=0 && actual.fila < n &&
//       actual.columna >=0 && actual.columna < n ){
//    if(actual.fila > fin.fila)
//        sumarCasillas += actual.fila-fin.fila;
//    else
//        sumarCasillas += fin.fila - actual.fila;
//    
//    if(actual.columna > fin.columna)
//        sumarCasillas += actual.columna-actual.fila;
//    else
//        sumarCasillas += fin.columna - actual.columna;
//    
//    int alturaMovida = mapa[actual.fila][actual.columna];
//    
//    return ((alturaMovida - alturaAntes <= hMax) && (alturaAntes - alturaMovida <= hMax))
//        &&(!marcado[actual.fila][actual.columna]) && (coste + sumarCasillas < mejorCoste) ;
//    }else{
//        return false;
//    }
//}
//
//bool esSolucion(tCasilla actual, tCasilla fin){
//    return actual.fila==fin.fila && actual.columna== fin.columna;
//}
//
//void copiaSolucion(int coste,int& mejorCoste,tCasilla* camino,tCasilla* mejorCamino){
//    if(coste<mejorCoste){
//        for (int i=0; i<coste; i++) {
//            mejorCamino[i]=camino[i];
//        }
//        mejorCoste=coste;
//    }
//}
//
//void desDireccion(tCasilla& actual, int dir, int& coste){
//    if (dir==0) {
//        actual.fila++;
//    }else if (dir==1){
//        actual.columna--;
//    }else if (dir==2){
//        actual.fila--;
//    }else if (dir==3){
//        actual.columna++;
//    }
//    coste--;
//}
//
//void direccion(tCasilla& actual, int dir, int& coste){
//    if (dir==0) {
//        actual.fila--;
//    }else if (dir==1){
//        actual.columna++;
//    }else if (dir==2){
//        actual.fila++;
//    }else if (dir==3){
//        actual.columna--;
//    }
//    coste++;
//}
//
//void caminoVA(tCasilla actual, int** mapa, int hMax, tCasilla fin, bool** marcado, tCasilla* camino, int coste, tCasilla* mejorCamino, int& mejorCoste, int n){
//    int alturaAntes = mapa[actual.fila][actual.columna];
//    for (int dir=0; dir <4; dir++) {
//        direccion(actual,dir, coste);
//        
//        if(esValido(actual, marcado, alturaAntes, mapa, hMax, fin, coste, mejorCoste, n)){
//            if (esSolucion(actual,fin)) {
//                copiaSolucion(coste,mejorCoste,camino,mejorCamino);
//            }else{
//                marcado[actual.fila][actual.columna]=true;
//                caminoVA(actual, mapa, hMax, fin, marcado, camino, coste, mejorCamino, mejorCoste, n);
//                marcado[actual.fila][actual.columna]=false;
//            }
//        }
//        desDireccion(actual, dir, coste);
//    }
//}
//
//
//void camino(int n){
//    tCasilla inicio;
//    int** mapa;
//    int hMax=0;
//    tCasilla fin;
//    bool** marcado;
//    tCasilla* camino;
//    tCasilla* mejorCamino;
//    int mejorSolucion = n * n + 1;
//    
//    mapa= new int*[n];
//    marcado = new bool*[n];
//    mejorCamino= new tCasilla[n];
//    camino= new tCasilla[n];
//    
//    cin >> hMax >> inicio.fila >> inicio.columna >> fin.fila >> fin.columna;
//    
//    for (int i=0; i<n; i++) {
//        mapa[i] = new int[n];
//        marcado[i] = new bool[n];
//
//        for (int j=0; j<n; j++) {
//            cin >>  mapa[i][j];
//            marcado[i][j]=false;
//        }
//    }
//    caminoVA(inicio, mapa, hMax, fin, marcado, camino, 0, mejorCamino, mejorSolucion, n);
//   
//    if(mejorSolucion==(n*n+1))
//        cout << "NO"<< endl;
//    else
//        cout << mejorSolucion + 1 << endl;
//}
//
//
//
//
//
//int main(){
//
//    int n;
//    
//    while(cin >> n){
//         camino(n);
//    }
//}

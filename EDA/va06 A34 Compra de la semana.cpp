////
////  va06.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 12/1/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//
//using namespace std;
//
//int compra(int** sp,int s,int p);
//void compra(int** sp,int &comprados, int* compradosSupermercado,int s,int p,int* solucion, int &coste,int* mejorSolucion, int &mejorCoste);
//bool esSolucion(int comprados,int productos);
//void tratarSolucion(int* solucion, int coste,int* mejorSolucion, int &mejorCoste, int p);
//bool esPosible(int coste,int mejorCoste);
//
//int compra(int** sp, int s,int p){
//    int comprados = 0;
//    int mejorCoste = -1;
//    int coste = 0;
//    int* compradosSupermercado = new int[s];
//    int* mejorSolucion = new int[p];
//    int* solucion= new int[p];
//    
//    for (int i= 0; i<s; i++ ) {
//        compradosSupermercado[i]=0;
//    }
//    
//    compra(sp,comprados, compradosSupermercado, s, p,solucion,  coste,mejorSolucion,  mejorCoste);
//    
//    delete[]compradosSupermercado;
//    coste=0;
//    comprados=0;
//    
//    return mejorCoste;
//}
//
//void compra(int** sp,int &comprados, int* compradosSupermercado,int s,int p,int* solucion, int &coste,int* mejorSolucion, int &mejorCoste){
//    for (int i=0; i<s; i++) {
//        if (compradosSupermercado[i] < 3) {
//            
//            solucion[comprados]=i;
//            coste+=sp[i][comprados];
//            compradosSupermercado[i]++;
//            comprados++;
//            
//            if (esSolucion(comprados,p)) {
//                tratarSolucion(solucion,coste,mejorSolucion,mejorCoste,p);
//            }
//            else{
//                if(esPosible(coste,mejorCoste)){
//                    compra(sp,comprados,compradosSupermercado,s,p,solucion,coste,mejorSolucion,mejorCoste);
//                }
//            }
//            comprados--;
//            compradosSupermercado[i]--;
//            coste -= sp[i][comprados];
//        }
//    }
//}
//
//bool esPosible(int coste,int mejorCoste){
//    return(coste<mejorCoste || mejorCoste==-1);}
//
//void tratarSolucion(int* solucion, int coste,int* mejorSolucion, int &mejorCoste,int p){
//    if (coste < mejorCoste || mejorCoste == -1) {
//        mejorCoste=coste;
//        for (int i=0; i<p; i++) {
//            mejorSolucion[i]=solucion[i];
//        }
//    }
//}
//
//bool esSolucion(int comprados,int productos){
//    return comprados==productos;
//}
//
//int main(){
//    int n=0;
//    int s=0,p=0;
//    int** sp;
//    cin >>n;
//    
//    for (; n>0; n--) {
//        cin >>s >>p;
//        sp = new int*[s];
//        for (int i=0; i<s; i++) {
//            sp[i]=new int[p];
//            for (int j=0; j<p; j++) {
//                cin>>sp[i][j];
//            }
//        }
//        
//        cout << compra(sp, s, p)<<endl;
//        
//        for (int i=0; i<s; i++) {
//            delete[]sp[i];
//        }
//        delete [] sp;
//        s=0;
//        p=0;
//    }
//}

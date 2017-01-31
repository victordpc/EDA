////
////  DyV04.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 26/1/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//
//using namespace std;
//
//string DyV(int* v, int n);
//bool DyV(int* v, int i, int j, int& max, int& min);
//
//bool DyV(int* v, int i, int j, int& max, int& min){
//    int medio=(i+j)/2;
//    
//    int maximoI=0;
//    int minimoI=0;
//    int maximoD=0;
//    int minimoD=0;
//    
//    if(j==i){
//        max = v[i];
//        min = v[i];
//        return true;
//    }else if(DyV(v, i, medio, maximoI, minimoI) && DyV(v, medio+1, j, maximoD, minimoD)){
//        
//        if(maximoI > maximoD) max = maximoI;
//        else max = maximoD;
//        
//        if(minimoI < minimoD) min = minimoI;
//        else min = minimoD;
//        
//        return (maximoD >= maximoI && minimoI <= minimoD);
//    }else{
//        return false;
//    }
//}
//
//string DyV(int* v, int n){
//    int maximo=0;
//    int minimo=0;
//    
//    if(DyV(v, 0, n-1, maximo, minimo))
//        return "SI";
//    else
//        return "NO";
//}
//
//int main(){
//    bool segir=true;
//    int n=0;
//    int* v= new int[100000];
//    int numero;
//    
//    while (segir){
//        cin >> numero;
//        while (numero!=0) {
//            v[n++]=numero;
//            cin >> numero;
//        }
//        
//        if(n!=0){
//            cout << DyV(v,n) << endl;
//            n=0;
//        }else
//            segir=false;
//    }
//    
//    delete[] v;
//}

////
////  rec06.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 13/12/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//
//using namespace std;
//
//void polidivisibleRec(unsigned long n, int d);
//void polidivisibleRec(unsigned long n, int d, int aux);
//
//int main(){
//    unsigned long n = 0;
//    int d = 0;
//    
//    while (cin >> n) {
//        cin >> d;
//        
//        polidivisibleRec(n,d );
//        
//        cout << "---" << endl;
//        n=0;d=0;
//    }
//}
//
//void polidivisibleRec(unsigned long n, int d){
//    int i =0;
//    unsigned long aux=n;
//    for (; aux > 0; i++) {aux/=10;}
//    
//    polidivisibleRec(n, d, i);
//}
//// Divide y venceras --> Coste Lineal
//void polidivisibleRec(unsigned long n, int d, int aux){
//    if (aux <= d){
//        if(n % aux == 0){
//            cout << n << endl;
//            n *= 10;
//            for (int j=0; j<10; j++) {
//                polidivisibleRec(n+j, d,aux+1);
//            }
//        }
//    }
//}

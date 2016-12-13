////
////  rec05.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 11/12/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//int recursivo(int arriba, int abajo, int** m);
//
//int main(){
//    int arriba=0, abajo=0;
//    int** m;
//
//    while (cin >> arriba){
//        cin >> abajo;
//        
//        m=new int*[arriba+1];
//
//        for (int i=0; i<=arriba; i++) {
//            m[i]=new int[abajo+1];
//
//            for (int j=0; j<=abajo; j++) {
//                m[i][j]=-1;
//            }
//        }
//
//        cout << recursivo(arriba,abajo,m) << endl;
//
//        for (int i=0; i<arriba; i++) {
//            delete m[i];
//        }
//        delete m;
//        ariba = 0;
//        abajo = 0;
//    }
//}
//
//
//int recursivo(int arriba, int abajo, int** m){
//    if(m[arriba][abajo] != -1)return m[arriba][abajo];
//    else if (abajo == 0) return 1;
//    else if (arriba == 0) return 0;
//    else{
//        m[arriba][abajo] = recursivo(arriba - 1, abajo - 1, m) + recursivo(arriba - 1, abajo, m);
//        return m[arriba][abajo];
//    }
//}

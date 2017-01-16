////
////  Rec10.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 15/12/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//
//using namespace std;
//
//void leerVector(char* v, int n, istream& sin);
//char fugaPrision(char* v, int i, int j, char x1);
//
//void leerVector(char* v, int n, istream& sin) {
//    for (int i = 0; i < n; i++)
//        sin >> v[i];
//}
//
//int main(){
//    int casos=0, letras=0;
//    char x1='a';
//    char x2='a';
//    char* presos;
//    
//    cin >> casos;
//    while (casos>0){
//        cin >> x1 >> x2;
//        letras = x2-x1;
//        
//        presos = new char[letras];
//        
//        leerVector(presos, letras, cin);
//        
//        cout << fugaPrision(presos, 0, letras,x1) << endl;
//        
//        delete presos;
//        x1='a'; x2='a';
//        letras=0;
//        casos--;
//    }
//    
//    return 0;
//}
//
////
//char fugaPrision(char* v, int i, int j, char x1){
//    if(j-i==1){
//        if(v[i]==x1) return x1+1;
//        else return x1;
//    }
//    
//    int mitad = i+(j-i)/2;
//    char letraMitad=x1+((j-i)/2);
//    
//    if(v[i]==x1 && v[mitad]==letraMitad)
//        return fugaPrision(v, mitad, j, letraMitad);
//    else
//        return fugaPrision(v, i, mitad, x1);
//
//
//}
//

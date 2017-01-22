////
////  DyV02.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 16/1/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//int exponencial(int b, int e);
//int combinar(int r, int b, int e);
//
//int main(){
//
//    int b=0;
//    int e=0;
//    int r=0;
//
//    cin >> b >> e;
//    while (b != 0 || e != 0){
//
//        r = exponencial(b % 31543,e);
//
//        cout << r << endl;
//
//        r = 0;
//        cin >> b >> e;
//    }
//}
//
//int exponencial(int b, int e){
//    if (e == 0)
//        return 1;
//    else if (e == 1)
//        return b;
//
//    int r=0;
//    r = exponencial(b,e / 2);
//    r = combinar(r,b,e);
//    return r;
//}
//
//int combinar(int r, int b, int e){
//    r = (r * r) % 31543;
//    if (e % 2 == 1)
//        r = (r * b) % 31543 ;
//    return r ;
//}

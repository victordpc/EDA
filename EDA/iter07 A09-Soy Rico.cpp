////
////  iter7.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 27/10/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//int cuantosDias(int quiero, int tengo, int anterior1, int anterior2);
//int cuantosDias1(int quiero, int tengo, int anterior1, int anterior2);
//int cuantosDias2(int quiero, int tengo, int anterior1, int anterior2);
//
//int main(){
//    int casos = 0;
//    int querido = 0;
//
//    cin >> casos;
//
//    while (casos > 0){
//
//        cin>>querido;
//
//        if (querido==0)
//            cout << 0 << "\n";
//        else
//            cout << cuantosDias(querido, 1, 1, 0) << "\n";
//
//        casos--;
//    }
//    return 0;
//}
//
//int cuantosDias(int quiero, int tengo, int anterior1, int anterior2){
//    int dias = 1;
//    int cantidadHoy = anterior2 * 2 + anterior1;
//
//    if (tengo < quiero){
//        tengo += cantidadHoy;
//        dias += cuantosDias(quiero, tengo, cantidadHoy, anterior1);
//    }
//    return dias;
//}

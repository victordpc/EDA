////
////  va01.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 31/1/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//
//using namespace std;
//
//string cucurucho(int c, int v);
//void cucurucho(int c, int v, int usadosC, int usadosV, string acumulado, string& resultado);
//bool esSolucion(int c, int v, int usadosC, int usadosV);
//
//bool esSolucion(int c, int v, int usadosC, int usadosV){
//    return (c == usadosC) && (v == usadosV);
//}
//
//void cucurucho(int c, int v, int usadosC, int usadosV, string acumulado, string& resultado){
//    
//    usadosC++;
//    
//    if(usadosC <= c){
//        if(esSolucion(c, v, usadosC, usadosV)){
//            if(resultado == "") resultado = acumulado + "C";
//            else resultado += " " + acumulado + "C";
//        }else{
//            cucurucho(c, v, usadosC, usadosV, acumulado + "C", resultado);
//        }
//    }
//    
//    usadosC--;
//    usadosV++;
//    
//    if(usadosV <= v){
//        if(esSolucion(c, v, usadosC, usadosV)){
//            if(resultado == "") resultado = acumulado + "V";
//            else resultado += " " + acumulado + "V";
//        }else{
//            cucurucho(c, v, usadosC, usadosV, acumulado + "V", resultado);
//        }
//    }
//    
//    usadosV--;
//}
//
//
//string cucurucho(int c, int v){
//    string resultado="";
//    cucurucho(c, v, 0, 0, "", resultado);
//    return resultado;
//}
//
//int main(){
//    int casos=0;
//    int c=0;
//    int v=0;
//    
//    cin >> casos;
//    
//    while (casos != 0){
//        cin >> c >> v;
//        
//        cout << cucurucho(c,v) << endl;
//        
//        casos--;
//        c = 0;
//        v = 0;
//    }
//}

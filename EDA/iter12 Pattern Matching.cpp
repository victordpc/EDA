////
////  iter12.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 14/11/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <string>
//
//using namespace std;
//
//int patronEnCadena(string cadena, string patron);
//
//int main() {
//    string cadena="", patron="";
//    
//    while(getline(cin,cadena)){
//        getline(cin, patron);
//        cout << patronEnCadena(cadena,patron);
//    }
//    return 0;
//}
//
//int patronEnCadena(string cadena,string patron){
//    int contador=0, i=0, j=0;
//    bool reconoce=false;
//    
//    while(i<cadena.length()) {
//        if(cadena[i]==patron[0]){
//            reconoce=true;
//            j=0;
//            while(j<patron.length() && reconoce){
//                if(cadena[i+j] != patron[j])
//                    reconoce=false;
//                j++;
//            }
//            if (reconoce){
//                contador++;
//            }
//            //Con o sin solapamiento
//            i += --j;
//        }
//        i++;
//    }
//    return contador;
//}

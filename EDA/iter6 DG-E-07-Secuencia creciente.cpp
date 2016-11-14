////
////  iter6.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 27/10/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(){
//    string n="";
//    bool ordenado = true;
//    char letra;
//    
//    getline(cin,n);
//    
//    while (n != "XXX"){
//
//        letra=n[0];
//        for (long i=1; i<n.length(); i++) {
//            if(letra < n[i]){
//                ordenado=true;
//                letra=n[i];
//            }
//            else{
//                ordenado=false;
//                i=n.length();
//            }
//        }
//        
//        if (ordenado)
//            cout << "SI" << "\n";
//        else
//            cout << "NO" << "\n";
//
//        getline(cin,n);
//        ordenado=true;
//    }
//    return 0;
//}

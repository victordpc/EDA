////
////  284.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 28/10/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <iostream>
//
//using namespace std;
//
//int main(){
//    int casos = 0;
//    int coste = 0;
//    int paga = 0;
//    int moneda = 0;
//   
//    cin >> casos;
//
//    while (casos > 0){
//
//        cin >> coste >> paga;
//        paga -= coste;
//        
//        if (paga<0)
//            cout << "DEBE " << -paga << "\n" ;
//        else
//        {
//            moneda = paga/200;
//            paga %= 200;
//            cout << moneda << " ";
//        
//            moneda = paga/100;
//            paga = paga%100;
//            cout << moneda << " ";
//            
//            moneda = paga/50;
//            paga = paga%50;
//            cout << moneda << " ";
//            
//            moneda = paga/20;
//            paga = paga%20;
//            cout << moneda << " ";
//            
//            moneda = paga/10;
//            paga = paga%10;
//            cout << moneda << " ";
//            
//            moneda = paga/5;
//            paga = paga%5;
//            cout << moneda << " ";
//            
//            moneda = paga/2;
//            paga = paga%2;
//            cout << moneda << " ";
//            
//            cout << paga << endl;
//        }
//        casos--;
//    }
//    return 0;
//}

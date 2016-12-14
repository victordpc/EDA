//
//  Rec07.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 14/12/16.
//  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
//

//#include <stdio.h>
//#include "iostream"
//
//using namespace std;
//
//bool movil();
//bool movil(int& peso, bool& equilibrio);
//
//int main(){
//    bool equilibrio = true;
//    int a = 0;
//    
//    while( movil(a,equilibrio)){
//        if(equilibrio){
//            cout << "SI" << endl;
//        }else {
//            cout << "NO" << endl;
//        }
//        
//    }
//}
//
//bool movil(int& peso, bool& equilibrio){
//    bool resI=true, resD=true;
//    int pi = 0, di = 0, pd = 0, dd = 0;
//    
//    cin >> pi >> di >> pd >> dd ;
//    
//    if(0==pi && 0==di && 0==pd && 0==dd){
//        return false;
//    } else {
//        if(pi==0){
//            movil(pi,resI);
//        }
//        peso = pi;
//        pi *= di;
//        
//        if (pd == 0){
//            movil(pd,resD);
//        }
//        peso +=pd;
//        pd *=dd;
//        
//        
//        equilibrio= (resI == resD && pi == pd );
//        return true;
//    }
//}

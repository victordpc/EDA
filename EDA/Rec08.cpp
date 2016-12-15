////
////  Rec08.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 14/12/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include "iostream"
//
//using namespace std;
//
//long long int fob(int n, long long int x, long long int y);
//long long int fob(int n, int i, long long int x, long long int y);
//int fob2(int n, int* v);
//int fob2(int n, int x, int y);
//
//int main(){
//    int n = 0, x = 0, y = 0;
//    
//    cin >> n;
//    
//    while (n != -1){
//        cin >> x >> y;
//        
//        if(n == 0){
//            cout << x;
//        } else if (n == 1) {
//            cout << y;
//        } else {
////            cout << fob(n,x,y);
//            cout << fob2(n,x,y);
//        }
//        cout << endl;
//        
//        n = 0; x = 0; y = 0;
//        cin >> n;
//    }
//}
//
////recursion no final, lineal
//int fob2(int n, int x, int y){
//    if (n==0) return x;
//    else if(n==1) return y;
//    else
//    {
//        int* v = new int[n];
//
//        v[0]=x;
//        v[1]=y;
//        for (int i = 2; i<=n; i++) {
//            v[i]=-1;
//        }
//        return fob2(n, v);
//    }
//}
//
//int fob2(int n, int* v){
//    if(v[n] != -1) return v[n];
//    else{
//        v[n] = fob2(n-1,v)+fob2(n-2,v);
//        return v[n];
//    }
//}
//
////recursion final, lineal en tiempo
//long long int fob(int n, long long int x, long long int y){
//    if (n==0) return x;
//    else if(n==1) return y;
//    else
//        return fob(n,1,y,x);
//}
//
//long long int fob(int n, int i, long long int x,long long int y){
//    if (n==i) return x;
//    else
//        return fob(n,i+1,x+y,x);
//}

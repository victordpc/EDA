////
////  rec04 fibonacci.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 10/12/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int fib(int n);
//int fib(int n,int i, int n1, int n2);
//
//int main() {
//    int n;
//    cin >> n;
//
//    while(n>=0)
//    {
//        cout << fib(n) << endl;
//        
//        cin>>n;
//    }
//}
//
//////coste cuadratico no final
////int fib(int n){
////    if(n==0) return 0;
////    else if(n==1) return 1;
////    else
////        return fib(n-1)+fib(n-2);
////}
//
////recursion final, lineal en tiempo
//int fib(int n){
//    if (n==0) return 0;
//    else if(n==1) return 1;
//    else
//        return fib(n,1,1,0);
//}
//
//int fib(int n, int i, int n1,int n2){
//    if (n==i) return n1;
//    else
//        return fib(n,i+1,n1+n2,n1);
//}
//

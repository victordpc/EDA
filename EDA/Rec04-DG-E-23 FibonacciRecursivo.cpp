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
//#include <cstdlib>
//
//using namespace std;
//
//long long int fib(int n);
//long long int fib(int n, long long int* v);
////unsigned long fib(int n,int i, unsigned long n1, unsigned long n2);
//
//int main() {
//    int n;
//
//    while(cin >> n)
//    {
//        cout << fib(n) << endl;
//        n=0;
//    }
//}
//
////recursion no final, lineal
//long long int fib(int n){
//    if (n < 2) return n;
//    else
//    {
//        long long int* v;
//        v = new long long int[n];
//        
//        v[0]=0;
//        v[1]=1;
//        for (int i = 2; i<=n; i++) {
//            v[i]=-1;
//        }
//        
//        return fib(n, v);
//    }
//}
//
//long long int fib(int n, long long int* v){
//    if(v[n] != -1) return v[n];
//    else{
//        v[n] = fib(n-1,v)+fib(n-2,v);
//        return v[n];
//    }
//}
//
//
////
//////recursion final, lineal en tiempo
////unsigned long fib(int n){
////    if (n==0) return 0;
////    else if(n==1) return 1;
////    else
////        return fib(n,1,1,0);
////}
////
////unsigned long fib(int n, int i, unsigned long n1,unsigned long n2){
////    if (n==i) return n1;
////    else
////        return fib(n,i+1,n1+n2,n1);
////}
////

////
////  iter8.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 27/10/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool xxxx(int a[], int n, int p);
//
//int main(){
//    int casos;
//    bool resultado = false;
//    int n;
//    int p;
//    int a[10000];
//    cin >> casos;
//    
//    while (casos > 0){
//        
//        cin >> n;
//        cin >> p;
//        
//        for (int i = 0; i < n; i++){
//            cin >> a[i];
//        }
//        
//        resultado = xxxx(a, n, p);
//        
//        casos--;
//        if (resultado)
//            cout << "SI" << "\n";
//        else
//            cout << "NO" << "\n";
//    }
//}
//
//bool xxxx(int a[],int n, int p)
//{
//    bool resultado=true;
//    int max = a[0];
//    int k = p+1;
//    
//    for (int i = 0; i <= p ; i++)
//    {
//        if (a[i] > max)
//            max = a[i];
//    }
//    
//    
//    while(k < n && resultado){
//        if (a[k]<= max)
//            resultado = false;
//        k++;
//    }
//    
//    return resultado;
//}

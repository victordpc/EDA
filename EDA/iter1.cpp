////
////  iter1.cpp
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
//string maximos(int a[], int n);
//
//int main(){
//    int casos;
//    int n;
//    int a[20000];
//    
//    cin >> casos;
//
//    while (casos > 0){
//
//        cin >> n;
//
//        for (int i = 0; i < n; i++){
//            cin >> a[i];
//        }
//
//        cout << maximos(a, n);
//
//        casos--;
//    }
//    return 0;
//}
//
//string maximos(int a[],int n)
//{
//    string resultado = "";
//    int max = a[0];
//    int contador = 1;
//    for (int i = 1; i < n ; i++)
//    {
//        if (a[i] > max)
//        {
//            max = a[i];
//            contador=1;
//        }
//        else if(a[i]==max)
//            contador++;
//    }
//    
//    resultado = to_string(max) + " " + to_string(contador) + "\n";
//    
//    return resultado;
//}

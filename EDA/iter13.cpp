////
////  iter13.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 11/11/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//
//using namespace std;
//
//void leerVector(int* v, int n, istream& sin);
//void calcular(int* a, int n, int &p, int &v);
//
//
//void leerVector(int* v, int n, istream& sin) {
//    for (int i = 0; i < n; i++)
//        sin >> v[i];
//}
//
//int main() {
//    int numCasos, n,p=0,v=0;
//    int* a;
//    cin >> numCasos;
//    for (int i = 0; i < numCasos; i++) {
//        cin >> n;
//        // Lectura de otros parametros
//        a = new int[n];
//        leerVector(a, n, cin);
//        
//        // Llamada a la funcion que implementa el algoritmo que se pide
//        calcular(a,n,p,v);
//        
//
//        // Salida
//     //   cout << endl<< endl;
//       cout << p << " " << v << endl;
//        delete[] a;
//        p = v = 0;
//    }
//    return 0;
//}
//
//void calcular(int* a, int n, int &p, int &v){
//    int i = 0;  //-> i +1
//    int j = -1; //-> i
//    int k = -2; //-> i-1
//    while (i < n){
//        if(k >= 0)
//        {
//            if(a[i] > a[j] && a[j] < a[k])
//                v++;
//            if(a[i] < a[j] && a[j] > a[k])
//                p++;
//        }
//        i++;j++;k++;
//      //  cout << k << " " << j << endl;
//        /*
//         pico v[i - 1] < v[i] > v[i + 1]
//         
//         */
//    }
//}

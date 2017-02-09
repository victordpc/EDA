////
////  va05.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 12/1/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//void llenarVector(int n, int*c, int*v, istream& sin);
//int elegirCanciones(int n, int tiempoCinta, int* tiempos, int* puntuaciones);
//void elegirCancionesVA(int n, int k, int restnateA, int restanteB, int* tiempos, int* puntuaciones, bool* mejorElegidas, bool* elegidas, int& mejorSolucion, int solucion, int maxPuntuacion, int minTiempo,int& numero);
//void tratarSolucion(int& mejorSolucion, int solucion, int* mejorElegidas, int* elegidas, int n);
//bool esSolucion(int n , int k, int restanteA, int restanteB, int minTiempo);
//bool esPosible(int restanteA, int restanteB, int puntuacion, int maxPuntuacion, int n, int k, int mejorSolucion);
//
//void mergeSort(int p[], int c[], int a, int b);
//void mergeSort ( int p[],int c[], int n);
//void mezcla(int p[], int c[], int a, int m, int b );
//
//
//
//
//bool esSolucion(int n , int k, int restanteA, int restanteB, int minTiempo){
//    return (n==k + 1) || (
//                          (restanteA - minTiempo < 0)
//                          &&
//                          (restanteB - minTiempo < 0)
//                          );
//}
//
//bool esPosible(int restanteA, int restanteB, int solucion, int maxPuntuacion, int n, int k, int mejorSolucion, int minTiempo){
//    return ( restanteA >= 0
//            && restanteB >= 0
//            )
//    && (solucion + maxPuntuacion) >= mejorSolucion;
//}
//
//
//void tratarSolucion(int& mejorSolucion, int solucion, bool* mejorElegidas, bool* elegidas, int n){
//    if(mejorSolucion < solucion){
//        mejorSolucion = solucion;
////        for (int i = 0; i <= n; i++) {
////            mejorElegidas[i] = elegidas[i];
////        }
//    }
//}
//
//void elegirCancionesVA(int n, int k, int restanteA, int restanteB, int* tiempos, int* puntuaciones, bool* mejorElegidas, bool* elegidas, int& mejorSolucion, int solucion, int maxPuntuacion, int minTiempo,int& numero){
//    
//    elegidas[k]=true;
//    //if (n==k+1) cout<< "rama"<<endl;
//    
//    numero++;
//    maxPuntuacion -= puntuaciones[k];
//    //CaraA
//    restanteA -= tiempos[k];
//    
//    solucion += puntuaciones[k];
//    
//    if(esPosible(restanteA, restanteB, solucion, maxPuntuacion,n,k,mejorSolucion, minTiempo)){
//        if(esSolucion(n, k, restanteA, restanteB, minTiempo)){
//            tratarSolucion(mejorSolucion, solucion, mejorElegidas, elegidas, n);
//        }else{
//            elegirCancionesVA(n, k+1, restanteA, restanteB, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion, solucion, maxPuntuacion, minTiempo,numero);
//        }
//    }
//    
//    restanteA += tiempos[k];
//    
//    //CaraB
//    restanteB -= tiempos[k];
//    
//    if(esPosible(restanteA, restanteB, solucion, maxPuntuacion,n,k,mejorSolucion,minTiempo)){
//        if(esSolucion(n, k, restanteA, restanteB, minTiempo)){
//            tratarSolucion(mejorSolucion, solucion, mejorElegidas, elegidas, n);
//        }else{
//            elegirCancionesVA(n, k+1, restanteA, restanteB, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion, solucion, maxPuntuacion, minTiempo,numero);
//        }
//    }
//    
//    restanteB += tiempos[k];
//    solucion -= puntuaciones[k];
//    
//    
//    if(esSolucion(n, k, restanteA, restanteB, minTiempo)){
//        tratarSolucion(mejorSolucion, solucion, mejorElegidas, elegidas, n);
//    }else{
//        //No elegida
//        elegidas[k]=false;
//        elegirCancionesVA(n, k+1, restanteA, restanteB, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion, solucion, maxPuntuacion, minTiempo,numero);
//    }
//}
//
//
//void mezcla(int p[], int c[], int a, int m, int b ){
//    int *uP = new int[b-a+1];
//    int *uC = new int[b-a+1];
//    
//    int i, j, k;
//    
//    for ( k = a; k <= b; k++ ){
//        uP[k-a] = p[k];
//        uC[k-a] = c[k];
//    }
//
//    i = 0; j = m-a+1; k = a;
//    
//    while ( (i <= m-a) && (j <= b-a) ) {
//        if ( uP[i] > uP[j] ){
//            p[k] = uP[i];
//            c[k] = uC[i];
//            i = i + 1;
//        } else {
//            p[k] = uP[j];
//            c[k] = uC[j];
//            j = j + 1;
//        }
//        k = k + 1;
//    }
//    
//    while ( i <= m-a ) {
//        p[k] = uP[i];
//        c[k] = uC[i];
//        i = i+1;
//        k = k+1;
//    }
//    
//    while ( j <= b-a ) {
//        p[k] = uP[j];
//        c[k] = uC[j];
//        j = j+1;
//        k = k+1;
//    }
//    
//    delete[] uP;
//    delete[] uC;
//}
//
//void mergeSort(int p[], int c[], int a, int b) {
//    int m;
//    if ( a < b ) {
//        m = (a+b) / 2;
//        mergeSort(p, c, a, m);
//        mergeSort(p, c, m+1, b);
//        mezcla(p, c, a, m, b);
//    }
//}
//
//void mergeSort ( int p[],int c[], int n) {
//    mergeSort(p, c, 0, n-1);
//}
//
//    
//int elegirCanciones(int n, int tiempoCinta, int* tiempos, int* puntuaciones){
//    bool* elegidas = new bool[n];
//    bool* mejorElegidas = new bool[n];
//    int maxPuntuacion = 0;
//    int minTiempo = tiempoCinta;
//    int mejorSolucion = 0;
//    
//    mergeSort(puntuaciones, tiempos, n);
//    
//    for (int i = 0; i <  n; i++) {
//        maxPuntuacion += puntuaciones[i];
//        
//        if(tiempos[i] < minTiempo)
//            minTiempo = tiempos[i];
//        
//        elegidas[i]=false;
//        mejorElegidas[i]=false;
//    }
//    int numero=0;
//    elegirCancionesVA(n, 0, tiempoCinta, tiempoCinta, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion,0, maxPuntuacion, minTiempo,numero);
//    
//  //  cout << numero<<endl;
//    
//    delete [] elegidas;
//    delete [] mejorElegidas;
//    return mejorSolucion;
//}
//
//int main(){
//    int n;
//    int t;
//    int* c;
//    int* p;
//    cin >> n;
//    
//    while(n!=0){
//        cin >> t;
//        
//        c = new int[n];
//        p = new int[n];
//        
//        llenarVector(n,c,p,cin);
//        
//        cout << elegirCanciones(n,t,c,p) << endl;
//        
//        delete[] c;
//        delete[] p;
//        cin >> n;
//    }
//}
//
//void llenarVector(int n, int*c,int*v,istream& sin){
//    for (int i=0; i<n; i++) {
//        cin>>c[i];
//        cin>>v[i];
//    }
//}
//
//
////
////
////
//////
//////  va05.cpp
//////  EDA
//////
//////  Created by Victor del Pino Castilla on 12/1/17.
//////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
//////
////
////#include <stdio.h>
////#include <iostream>
////
////using namespace std;
////
////void llenarVector(int n, int*c, int*v, istream& sin);
////int elegirCanciones(int n, int tiempoCinta, int* tiempos, int* puntuaciones);
////void elegirCancionesVA(int n, int k, int restnateA, int restanteB, int* tiempos, int* puntuaciones, bool* mejorElegidas, bool* elegidas, int& mejorSolucion, int solucion, int maxPuntuacion, int minTiempo);
////void tratarSolucion(int& mejorSolucion, int solucion, int* mejorElegidas, int* elegidas, int n);
////bool esSolucion(int n , int k, int restanteA, int restanteB, int minTiempo);
////bool esPosible(int restanteA, int restanteB, int puntuacion, int maxPuntuacion, int n, int k, int mejorSolucion);
////
////
////bool esSolucion(int n , int k, int restanteA, int restanteB, int minTiempo){
////    return (n==k+1) || ((restanteA - minTiempo < 0) && (restanteB - minTiempo < 0));}
////
////bool esPosible(int restanteA, int restanteB, int solucion, int maxPuntuacion, int n, int k, int mejorSolucion, int minTiempo){
////    return ( restanteA >= 0
////            && restanteB >= 0
////            )
////    && (solucion + maxPuntuacion) > mejorSolucion;
////}
////
////
////void tratarSolucion(int& mejorSolucion, int solucion, bool* mejorElegidas, bool* elegidas, int n){
////    if(mejorSolucion < solucion){
////        mejorSolucion = solucion;
//////        for (int i = 0; i <= n; i++) {
//////            mejorElegidas[i] = elegidas[i];
//////        }
////    }
////}
////void elegirCancionesVA(int n, int k, int restanteA, int restanteB, int* tiempos, int* puntuaciones, bool* mejorElegidas, bool* elegidas, int& mejorSolucion, int solucion, int maxPuntuacion, int minTiempo){
////
////    elegidas[k]=true;
////    maxPuntuacion -= puntuaciones[k];
////    //CaraA
////    restanteA -= tiempos[k];
////    
////    solucion += puntuaciones[k];
////    
////    if(esPosible(restanteA, restanteB, solucion, maxPuntuacion,n,k,mejorSolucion, minTiempo)){
////        if(esSolucion(n, k, restanteA, restanteB, minTiempo)){
////            tratarSolucion(mejorSolucion, solucion, mejorElegidas, elegidas, n);
////        }else{
////            elegirCancionesVA(n, k+1, restanteA, restanteB, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion, solucion, maxPuntuacion, minTiempo);
////        }
////    }
////
////    restanteA += tiempos[k];
////
////    //CaraB
////    restanteB -= tiempos[k];
////    
////    if(esPosible(restanteA, restanteB, solucion, maxPuntuacion,n,k,mejorSolucion,minTiempo)){
////        if(esSolucion(n, k, restanteA, restanteB, minTiempo)){
////            tratarSolucion(mejorSolucion, solucion, mejorElegidas, elegidas, n);
////        }else{
////            elegirCancionesVA(n, k+1, restanteA, restanteB, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion, solucion, maxPuntuacion, minTiempo);
////        }
////    }
////    
////    restanteB += tiempos[k];
////    solucion -= puntuaciones[k];
////
////    
////    if(esPosible(restanteA, restanteB, solucion, maxPuntuacion,n,k,mejorSolucion,minTiempo)){
////        if(esSolucion(n, k, restanteA, restanteB, minTiempo)){
////            tratarSolucion(mejorSolucion, solucion, mejorElegidas, elegidas, n);
////        }else{
////            //No elegida
////            elegidas[k]=false;
////            elegirCancionesVA(n, k+1, restanteA, restanteB, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion, solucion, maxPuntuacion, minTiempo);
////        }
////    }
////}
////
////int elegirCanciones(int n, int tiempoCinta, int* tiempos, int* puntuaciones){
////    bool* elegidas = new bool[n];
////    bool* mejorElegidas = new bool[n];
////    int maxPuntuacion = 0;
////    int minTiempo = tiempoCinta;
////    int mejorSolucion = 0;
////    
////    for (int i = 0; i <  n; i++) {
////            maxPuntuacion += puntuaciones[i];
////
////        if(tiempos[i] < minTiempo)
////            minTiempo = tiempos[i];
////
////        elegidas[i]=false;
////        mejorElegidas[i]=false;
////    }
////    
////    elegirCancionesVA(n, 0, tiempoCinta, tiempoCinta, tiempos, puntuaciones, mejorElegidas, elegidas, mejorSolucion,0, maxPuntuacion, minTiempo);
////    
////    delete [] elegidas;
////    delete [] mejorElegidas;
////    return mejorSolucion;
////}
////
////int main(){
////    int n;
////    int t;
////    int* c;
////    int* p;
////    cin >> n;
////    
////    while(n!=0){
////        cin >> t;
////        
////        c = new int[n];
////        p = new int[n];
////        
////        llenarVector(n,c,p,cin);
////        
////        cout << elegirCanciones(n,t,c,p) << endl;
////        
////        delete[] c;
////        delete[] p;
////        cin >> n;
////    }
////}
////
////void llenarVector(int n, int*c,int*v,istream& sin){
////    for (int i=0; i<n; i++) {
////        cin>>c[i];
////        cin>>v[i];
////    }
////}
//

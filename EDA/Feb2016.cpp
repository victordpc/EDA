////
////  Feb2016.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 19/1/17.
////  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
////
//
////1. (3 puntos) Dise˜nar y verificar, o bien derivar, un algoritmo iterativo eficiente que cumpla la
////siguiente especificaci´on:
////    {0 ≤ n ≤ longitud(v) ∧ ∀k : 0 ≤ k < n : v[k] ≥ 0}
////    fun parImpar (int v[ ], int n) return int p
////    {p = # i, j : 0 ≤ i < j < n : v[i] %2 = 0 ∧ v[j] %2 = 1}
////Indicar y justificar la complejidad del algoritmo.
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//struct posicion{int fila;int columna;};
//
//int parImpar (int* v, int n);
//void llenarVector(int* v,int& n);
//
//int isbnNoFinal(int n);
//int isbnRecursivoNoFinal(int n, int& multiplicar);
//
//int isbnFinal(int n);
//int isbnRecursivoFinal(int n,int suma1,int suma2,int posiciones);
//
//void llenarMatriz(int** v,int n,istream& sin);
//void buscarCamino(int** m,int n,int hmax,posicion salida,posicion llegada,int& costeResultado, posicion* vectorResultado);
//void buscarCaminoVA(int** m,int n,int hmax,posicion salida,posicion llegada,bool** marcas,int& costeResultado, posicion* vectorResultado, int& mejorCosteResultado, posicion* mejorVectorResultado);
//posicion siguientePosicion(int direccion, posicion actual);
//void copiaVector(posicion* origen,posicion* destino,int posiciones);
//bool esSolucion(posicion llegada,posicion ahora);
//bool esValida(int**m,posicion ahora,posicion antes,bool** marca,int n,int hmax);
//
//
//
//
//int parImpar (int v[ ], int n){
//    int p=0;
//    int i=0;
//    int pares=0;
//    
//    while (i<n){
//        if(v[i]%2==0)
//            pares++;
//        else// (v[i]%2==1)
//            p+=pares;
//        i++;
//    }
//    
//    return p;
//}
////  Coste
////  Ya que el coste dentro del bucle es constante, la complejidad viene dada por el bucle,
////  como solo hacemos una pasada por el vector el coste es O=(n)
//
////  Invariante
////  I= 0<=i<n ∧ p = # m, n : 0 ≤ m < n < i : v[m] %2 = 0 ∧ v[n] %2 = 1
////  ∧ pares = # k : O <= k < i : v[k] % 2 = 0
//
////  P={0 ≤ n ≤ longitud(v) ∧ ∀k : 0 ≤ k < n : v[k] ≥ 0}
////  Q={p = # i, j : 0 ≤ i < j < n : v[i] %2 = 0 ∧ v[j] %2 = 1}
//
////  Verifiar
////
////  Antes del bucle
////  {P}p=0;i=0;pares=0;{I}
////
////  pmd(p=0;i=0;pares=0;,I)= {0 ≤ n ≤ longitud(v) ∧ ∀k : 0 ≤ k < n : v[k] ≥ 0
////  ∧ 0<=0<n ∧ 0 = # m, n : 0 ≤ m < n < 0 : v[m] %2 = 0 ∧ v[n] %2 = 1 ∧ pares = # k : O <= k < i : v[k] % 2 = 0}
////
////  En cada vuelta del bucle
////  {I∧B}A{I}
////
////  { 0<=i<n ∧ p = {# m, n : 0 ≤ m < n < i : v[m] %2 = 0 ∧ v[n] %2 = 1} ∧ pares = # k : O <= k < i : v[k] % 2 = 0 ∧ i < n}
////  if(v[i]%2==0) pares++;  else p+=pares;i++;
////  { 0<=i<n ∧ p = {# m, n : 0 ≤ m < n < i : v[m] %2 = 0 ∧ v[n] %2 = 1}}
////
////  ( (v[i]%2==0) ∧ pmd(pares++;i++;,I) v (v[i]%2!=0) ∧ pmd(p+=pares;i++;,I) )
////
////  ( (v[i+1]%2==0) ∧ 0<=i+1<n ∧ p = (# m, n : 0 ≤ m < n < i+1 : v[m] %2 = 0) ∧ v[n] %2 = 1 ∧ pares = (# k : 0 <= k < i+1 : v[k] % 2 = 0)+1
////  v (v[i+1]%2!=0) ∧ 0<=i+1<n ∧ p = (# m, n : 0 ≤ m < n < i+1 : v[m] %2 = 0)+1 ∧ v[n] %2 = 1 ∧ pares = (# k : 0 <= k < i+1 : v[k] % 2 = 0))
////  => (O incrementamos el valor de pares por que el numero es par, o incrementamos el valor de p por que es impar por lo que)
////  ( 0<=i<n ∧ p = # m, n : 0 ≤ m < n < i : v[m] %2 = 0 ∧ v[n] %2 = 1 ∧ pares = # k : O <= k < i : v[k] % 2 = 0 )
////
////  Fuera del bucle
////  {I∧¬B} => {Q}
////
////  { 0<=i<n ∧ p = {# m, n : 0 ≤ m < n < i : v[m] %2 = 0 ∧ v[n] %2 = 1} ∧ pares = # k : O <= k < i : v[k] % 2 = 0 ∧ i < n}
////  => (Como la postcondicion esta contenida en el invariante, es directo demotrar que se implica desde este)
////  {p = # i, j : 0 ≤ i < j < n : v[i] %2 = 0 ∧ v[j] %2 = 1}
////
//
//
//void llenarVector(int v[], int& n,istream& sin) {
//    sin>> n;
//    for(int i=0; i<n;i++){
//        sin>>v[i];
//    }
//}
//
//int isbnNoFinal(int n){
//    int mult=0;
//    int res=0;
//    res= isbnRecursivoNoFinal(n, mult);
//    
//    return (10-(res%10))%10;
//}
//
//
//int isbnRecursivoNoFinal(int n, int& multiplicar){
//    if(n<10){
//        multiplicar=3;
//        return n;
//    }else{
//        int mult = 0;
//        int num = n%10;
//        int res=0;
//        res=isbnRecursivoNoFinal(n/10,mult);
//        multiplicar=4-mult;
//        return res+(num*mult);
//    }
//
//}
//
//
//
//int isbnFinal(int n){
//    int res=0;
//    res=isbnRecursivoFinal(n, 0, 0, 0);
//    return (10-(res%10))%10;
//}
//
//int isbnRecursivoFinal(int n,int suma1,int suma2,int posiciones){
//    if (posiciones%2==0) suma1+=n%10;
//    else suma2+=n%10;
//    
//    if(n<10)
//    {
//        if(posiciones%2==0) return suma1+suma2*2;
//        else    return suma1*3+suma2;
//    }
//    else
//        return isbnRecursivoFinal(n/10, suma1, suma2, posiciones+1);
//}
//
//
//
//
//
//
//int main(){
//    int n=0;
////    int casos=0;
////    int* v=0;
////    
////    
////    cout << "Ejercicio 1"<< endl<< endl;
////    
////    cin >> casos;
////    
////    while(casos>0){
////        llenarVector(v,n,cin);
////       
////        cout << parImpar(v,n) << endl;
////        
////        delete v;
////        n=0;
////        casos--;
////    }
////    
////    cout << "Ejercicio 2 No Final"<< endl<< endl;
////    
////    cin >> casos;
////    while(casos>0){
////        cin >> n;
////        
////    cout << isbnNoFinal(n) << endl;
////        
////        casos--;
////    }
////    
////    
////    cout << "Ejercicio 2 Final"<< endl<< endl;
////    
////    cin >> casos;
////    while(casos>0){
////        cin >> n;
////        
////        cout  << isbnFinal(n) << endl;
////        
////        casos--;
////    }
//
//    cout << "Ejercicio 3";
//    
//    int** matriz;
//    int hmax=0;
//    posicion salida,llegada;
//    salida.fila=0;salida.columna=0;
//    llegada.fila=0;llegada.columna=0;
//    
//    cout << "Matriz Dimensión n:"; cin >> n;
//    
//    matriz=new int*[n];
//    for (int i=0; i<n; i++) {
//        matriz[i]=new int[n];
//    }
//    
//    cout<<endl<<"Matriz:"<<endl;
//    llenarMatriz(matriz, n,cin);
//    
//    cout<<"Altura maxima"; cin>> hmax;
//    cout <<endl;
//    
//    cout<<"Fila de salida"; cin>> salida.fila;cout<<"Columna de salida";cin>>salida.columna;
//    cout <<endl;
//    
//    cout<<"Fila de llegada"; cin>> llegada.fila;cout<<"Columna de llegada";cin>>llegada.columna;
//    cout <<endl;
//    
//    posicion* resultado= new posicion[n*n];
//    int coste=0;
//    
//    buscarCamino(matriz, n,hmax,salida,llegada,coste,resultado);
//    
//    if(coste==n*n+1)
//        cout<<"No hay solucion";
//    else
//        for (int i=0; i<coste; i++)
//            cout<<"("<<resultado[i].fila<<","<<resultado[i].columna<<")";
//
//    for (int i=0; i<n; i++) {
//        delete[] matriz[i];
//    }
//
//    delete[] matriz;
//    delete[] resultado;
//
//}
//
//void buscarCamino(int** m,int n,int hmax,posicion salida,posicion llegada,int& costeResultado, posicion* vectorResultado){
//    
//    if(salida.columna == llegada.columna && salida.fila == llegada.fila)
//        return;
//    
//    int casillas=n*n;
//    int mejorCoste=casillas+1;
//    posicion* mejorVector=new posicion[casillas];
//    bool** marcas= new bool*[n];
//    
//    vectorResultado[0].fila=salida.fila;
//    vectorResultado[0].columna=salida.columna;
//    costeResultado=1;
//    
//    for (int i=0; i<n; i++) {
//        marcas[i]=new bool[n];
//        for (int j=0; j<n; j++) {
//            marcas[i][j]=false;
//        }
//    }
//    
//    buscarCaminoVA(m, n, hmax, salida,llegada, marcas,costeResultado, vectorResultado, mejorCoste, mejorVector);
//    
//    if(mejorCoste!= casillas+1){
//        costeResultado=mejorCoste;
//        for (int i = 0; i<mejorCoste; i++) {
//            vectorResultado[i]=mejorVector[i];
//        }
//    }
//}
//
//void buscarCaminoVA(int** m,int n,int hmax,posicion salida,posicion llegada,bool** marcas,int& costeResultado, posicion* vectorResultado, int& mejorCosteResultado, posicion* mejorVectorResultado){
//    
//    for (int avanza=0; avanza<4; avanza++) {
//        
//        vectorResultado[costeResultado] =  siguientePosicion(avanza,vectorResultado[costeResultado-1]);
//        posicion posicionAhora;
//        posicionAhora.fila=vectorResultado[costeResultado].fila;
//        posicionAhora.columna=vectorResultado[costeResultado].columna;
//        
//        int faltan=abs(llegada.fila-posicionAhora.fila)+abs(llegada.columna-posicionAhora.columna);
//        
//        cout<<"Paso a ("<< vectorResultado[costeResultado].fila<<","<<vectorResultado[costeResultado].columna<<")";
//        cout<<" prueba a ("<< posicionAhora.fila<<","<<posicionAhora.columna<<")"<<endl;
//        
//        if(esValida(m, posicionAhora, vectorResultado[costeResultado-1], marcas, n, hmax)
//           && (costeResultado+1+faltan<mejorCosteResultado)){
//            
//            cout<<"Valida a ("<<posicionAhora.fila<<","<<posicionAhora.columna<<")"<<endl;
//            
//            costeResultado++;
//            
//            if(esSolucion(llegada,posicionAhora)
//               && (costeResultado<mejorCosteResultado)){
//            
//                cout<< "Solucion encontrada: "<<endl;
//                for (int i=0; i<costeResultado; i++) {
//                    cout<<"("<<vectorResultado[i].fila<<","<<vectorResultado[i].columna<<") ";
//                    
//                }
//                cout<<endl;
//                
//                mejorCosteResultado=costeResultado;
//                copiaVector(vectorResultado,mejorVectorResultado,costeResultado);
//            
//            }else{
//            
//                marcas[posicionAhora.fila][posicionAhora.columna]=true;
//                buscarCaminoVA(m, n, hmax, salida, llegada,  marcas, costeResultado, vectorResultado, mejorCosteResultado, mejorVectorResultado);
//                marcas[posicionAhora.fila][posicionAhora.columna]=false;
//            
//            }
//            costeResultado--;
//        }
//    }
//}
//
//bool esValida(int**m,posicion ahora,posicion antes,bool** marca,int n,int hmax){
//    return (ahora.fila >= 0 && ahora.columna >= 0 && ahora.fila < n && ahora.columna < n)
//    && (abs(m[ahora.fila][ahora.columna]-m[antes.fila][antes.columna])<=hmax)
//    && (!marca[ahora.fila][ahora.columna]);
//}
//
//bool esSolucion(posicion llegada,posicion ahora){
//    return (llegada.columna== ahora.columna) && (llegada.fila== ahora.fila);
//}
//
//void copiaVector(posicion* origen,posicion* destino,int posiciones){
//    for (int pos=0; pos<posiciones; pos++) {
//        destino[pos]=origen[pos];
//    }
//}
//
//posicion siguientePosicion(int direccion, posicion actual){
//    if (direccion==0) {
// actual.fila--;
//    }else if (direccion==1){
//        actual.columna++;
//    }else if (direccion==2){
//        actual.fila++;
//    }else if (direccion==3){
//        actual.columna--;
//    }
//    return actual;
//}
//
//
//void llenarMatriz(int** m,int n,istream& sin){
//    for(int fila=0; fila<n;fila++){
//        cout<<"Introduzca la fila " << fila<<" de la matriz";
//        for (int columna=0; columna<n; columna++) {
//            sin>>m[columna][fila];
//        }
//    }
//}

//
//  Feb2015.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 22/1/17.
//  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void ejercicio1();
void ejercicio2();
void ejercicio3();
void llenarVector(int n, int* v,istream& sin);
int sumaPares(int n, int* v);

int main(){
    ejercicio1();
    ejercicio2();
    ejercicio3();
}

//Dado un vector de n elementos (n ≥ 0), se desea obtener la suma de todos los
//productos de valores situados en parejas de posiciones distintas (con una complejidad O(n)).
//Ejemplo: para el array con contenido: [1, 3, 5, 7] se debe devolver 1∗3+1∗5+1∗7+3∗5+3∗7+5∗7.
//Para el array con contenido [6, 2, 5, 9, 1, 2] se debe devolver:
//6 ∗ 2 + 6 ∗ 5 + 6 ∗ 9 + 6 ∗ 1 + 6 ∗ 2 + 2 ∗ 5 + 2 ∗ 9 + 2 ∗ 1 + 2 ∗ 2 + 5 ∗ 9 + 5 ∗ 1 + 5 ∗ 2 + 9 ∗ 1 + 9 ∗ 2 + 1 ∗ 2
//Se pide:
//1. Especificación del algoritmo.
//2. Diseño y verificación (o derivación) e implementación del algoritmo iterativo.
//3. Justificación de la complejidad

void ejercicio1(){
    int casos=0;
    int n=0;
    int* v;
    int resultado=0;
    cin >> casos;
    
    while (casos >0){
        cin >> n;
        v= new int[n];

        llenarVector(n,v,cin);

        if(n>0)
            resultado = sumaPares(n,v);

        cout << resultado << endl;

        casos--;
        delete[] v;
        n=0;
        resultado=0;
    }
}

//1. P={ n>0 ^ longitud(v) >= n ^ (forall x : 0 <= x < n : v[x] >= 0  ) } longitud={#i : 0 <= i < n: i }
//1. Q={ suma i,j : 0 <= i < j < n: v[i]*v[j] }
int sumaPares(int n, int* v){
    int resultado=0;
    int i=1;
    int suma=v[0];
    while(i < n){
        resultado += v[i] * suma;
        suma += v[i];
        i++;
    }
    return resultado;
}
//2. I = { 0 <= i < n ^ suma=( suma k : 0 <= k < i : v[k] ) ^ resultado = ( suma i,j : 0 <= i < j < n: v[i]*v[j] ) }

//3. Las operaciones dentro y fuera del bucle tiene coste constante por lo que la complejidad de la función viene de la
//   complejidad del bucle, como solo se realiza una pasada por los datos tiene conste lineal sobre el número de elementos
//   del bucleluego pertenece al O(n)

void llenarVector(int n, int*v, istream& sin){
    for (int i=0; i<n; i++) {
        cin>> v[i];
    }
}


int especularNoFinal(int n);
int especularFinal(int n);

void ejercicio2(){
    int casos=0;
    int numero=0;
    cin >> casos;
    
    while (casos > 0){
        
        cin >> numero;
        
        cout << especularNoFinal(numero) << endl;
        cout << especularFinal(numero) << endl;
        
        casos--;
        numero=0;
    }
}
//2. (3 puntos) La imagen especular de un número natural es el número que resulta al invertir el
//orden de sus dígitos. Por ejemplo, la imagen especular de 13492 es 29431 y la imagen especular
//del 1000 es el 1. Implementa dos algoritmos recursivos, uno final y otro no final, que calculen la
//imagen especular de un número natural representado como unsigned int. Indicar la llamada
//inicial a cada algoritmo con los valores iniciales de cada parámetro. Justifica el coste de cada
//algoritmo.
//NOTA: Ten en cuenta que no se pide la especificación, ni la derivación / verificación formal
//de los algoritmos.

int recNoFinal(int numero, int& potencia);

int especularNoFinal(int numero){
    int resultado=0;
    int potencia=0;
    resultado = recNoFinal(numero,potencia);
    return resultado;
}

int recNoFinal(int numero, int& potencia){

    if(numero < 10){
        potencia = 10;
        return numero;
    }else{
        int guardo = numero % 10;
        int acumulado = recNoFinal(numero / 10, potencia);
        
        acumulado += guardo * potencia;
        potencia *= 10;
        return acumulado;
    }
}

int recFinal(int numero, int especular);

int especularFinal(int numero){
    int resultado=0;
    resultado = recFinal(numero,0);
    return resultado;
}

int recFinal(int numero, int especular){
    if (numero < 10)
        return especular*10+numero;
    else{
        especular = especular * 10 + (numero % 10);
        return recFinal(numero/10, especular);
    }
}

struct producto {
    int precio;
    int calorias;
    int proteinas;
};

void llenarProductos(int n, producto* v);

void ejercicio3(){
    int numero=0, precioMax=0,proteinaMin=0;
    producto* productos;
    cout << "Numero de productos"; cin >> numero;
    llenarProductos(numero, productos);
    cout << "Precio maximo"; cin >> precioMax;
    cout << "Proteina minimo"; cin >> proteinaMin;
    
    
}
//3. (3,5 puntos) Se dispone de una lista de n productos alimenticios entre los que se quiere escoger
//algunos para seguir una dieta adecuada. Para cada producto i (0 ≤ i < n) se conoce su precio
//pi ≥ 0, su contenido en proteinas qi ≥ 0 y su cantidad de calorías ci ≥ 0. Se desea seleccionar
//algunos de estos productos (a lo sumo uno de cada) de forma que el precio total no supere un
//presupuesto M, el contenido proteico total sea al menos de Q y el valor calórico sea lo menor
//posible. Diseñar un algoritmo de vuelta atrás para encontrar la selección óptima, es decir, la
//que minimiza la cantidad de calorías. Se valorarán las podas realizadas.

void llenarProductos(int n, producto* v){
    for (int i=0; i<n; i++){
        cout << endl << "Precio " << i+1; cin >> v[i].precio;
        cout << endl << "Calorias " << i+1; cin >> v[i].calorias;
        cout << endl << "Proteinas " << i+1; cin >> v[i].proteinas;
    }
}












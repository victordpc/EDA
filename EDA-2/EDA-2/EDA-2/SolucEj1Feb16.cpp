
// Solucion al ejercicio 1 del examen de EDA de febrero del curso 15-16

#include <iostream>
using namespace std;

#include <stdio.h>

// Precondicion: 0<=n<=longitud(v) && forall k:0<=k<n:v[k]>=0
// para evitar problemas con los negativos
int parImpar(int v[], int n){
  int p = 0, l = 0, npares = 0;
/* Invariante:
 0<= l<= n
 && p = # i,j : 0 <=i <j <l: v[i]%2=0 && v[j]%2=1 
 && npares = # z:0<= z <l : v[z]%2 =0
*/
  while (l < n){
    if (v[l]%2 == 0) npares = npares+1;
    else p = p + npares;
    l++;
  }
  return p;
}
//Postcondicion:
//p = # i,j : 0 <=i <j <n: v[i] % 2=0 && v[j] % 2=1

void resuelve(){
  int nElems;
  cin >> nElems;
  int v[100];
  for (int i = 0;i < nElems;i++)
    cin >> v[i];  
  cout << parImpar(v,nElems) << endl;
}


int main() {
  resuelve();
  return 0;
}

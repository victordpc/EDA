
// Soluciones al ejercicio 2 del examen de EDA de febrero del curso 15-16

#include <iostream>
using namespace std;

#include <stdio.h>

//Version no final que calcula la suma
long long int suma(long long int isbn, int& ndigitos){
  int s,m;
  if (isbn <= 9) {
    ndigitos = 1; s = isbn;
  } else {
    s = suma(isbn/10,ndigitos);
    if (ndigitos%2 == 1) s = s + isbn%10*3;
    else s = s + isbn%10;
    ndigitos = ndigitos + 1;
  }
  return s;
}


void resuelve(){
  long long int isbn,s;
  int ndigitos;
  cin >> isbn;
  s = suma(isbn,ndigitos);
  cout << "Suma " << s;
  cout << " Digito " << (10-s%10)%10;
  //system("pause");
}

//Version final que calcula la suma
//suma1 lleva la suma de los digitos desde el menos significativo
//suma2 lleva la suma de los digitos desde el a
long long int sumaFinal(long long isbn,int ndigitos,int suma1,int suma2){ 
  int res;
  if (isbn <= 9){
    if (ndigitos%2 == 0) res = suma1*3+suma2+isbn;
    else res = suma2*3+suma1+isbn;
  } else {
    if (ndigitos%2 == 0)
      res = sumaFinal(isbn/10,ndigitos+1,suma1,suma2+isbn%10);
    else res = sumaFinal(isbn/10,ndigitos+1,suma1+isbn%10,suma2); 
  }
  return res;
}

void resuelveFinal(){
  long long int isbn, s;
  int ndigitos = 1;
  long long int suma1 = 0, suma2 = 0;
  cin >> isbn;
  s = sumaFinal(isbn,ndigitos,suma1,suma2);
  cout << "Suma " << s;
  cout << " Digito " << (10-s%10)%10;
  //system("pause");
}


int main() {
  //resuelve(); //Version no final
  resuelveFinal(); //Version final que solo calcula la suma
  return 0;
}

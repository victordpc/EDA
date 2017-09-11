#include <iostream>
using namespace std;

#include <climits>
#include <cstdlib>


const int N = 5;

struct casilla{
  int fila;
  int columna;
};

bool esValida(int terreno[N][N], int hmax, casilla ant, casilla c, int n, const bool marcas[N][N]){
  return c.fila >= 0 && c.columna >= 0 && c.fila < n && c.columna < n && 
	 abs(terreno[ant.fila][ant.columna]-terreno[c.fila][c.columna]) <= hmax && 
         !marcas[c.fila][c.columna];
}

bool esSolucion(casilla pos, casilla final){
  return pos.fila == final.fila && pos.columna == final.columna;
}

casilla sigDireccion(int dir, casilla pos){
  switch (dir) {
  case 0:
    ++ pos.columna;
    break;
  case 1:
    ++ pos.fila;
    break;
  case 2:
    -- pos.columna;
    break;
  case 3:
    -- pos.fila;
    break;
  default:
    break;
  }
  return pos;
}

void copiarSolucion(casilla solucion[],casilla mejorSol[],int n){
  for (int i = 0;i < n;i++) 
    mejorSol[i]=solucion[i];
}

void carretera(int terreno[N][N], casilla final, int hmax, casilla solucion[], int &longitud, int k, int n, 
	       bool marcas[N][N], casilla mejorSol[], int &mejorLong){
  for (int dir = 0; dir < 4; dir++){
    solucion[k] = sigDireccion(dir, solucion[k-1]); 
    int longEstimada = longitud + 1 + abs(final.fila-solucion[k].fila) + abs(final.columna-solucion[k].columna);
    if (esValida(terreno, hmax, solucion[k-1],solucion[k], n, marcas) && longEstimada < mejorLong){
      longitud++;
      if (esSolucion(solucion[k],final)){
	// if (longitud < mejorLong) No es necesario. Ya se ha chequeado en la condicion de longEstimada
	  copiarSolucion(solucion,mejorSol,longitud);
	  mejorLong = longitud;
      } else {
	marcas[solucion[k].fila][solucion[k].columna] = true; 
	carretera(terreno, final, hmax, solucion, longitud, k + 1, n, marcas,mejorSol,mejorLong);
	marcas[solucion[k].fila][solucion[k].columna] = false;     
      }
      longitud--;
    }
  }
}

int main(){   
  int terreno[N][N];
  int n;
  cout << "Dimension del terreno: ";
  cin >> n;
  for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++){
      cout << "Casilla " << i << " , " << j << " : ";
      cin >> terreno[i][j];
    }
  bool marcas[N][N];
  int hmax;
  casilla comienzo,final;
  for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++)
      marcas[i][j] = false;
  
  //Casilla Inicio y final: supuestamente validas
  cout << "Casilla de comienzo: ";
  cin >> comienzo.fila >> comienzo.columna;
  
  cout << "Casilla destino: ";
  cin >> final.fila >> final.columna;
  
  cout << "Altura máxima: ";
  cin >> hmax;
  
  casilla sol[N*N]; int longitud = 1;
  casilla mejorSol[N*N]; int longMejor = INT_MAX;
  sol[0].fila = comienzo.fila;
  sol[0].columna = comienzo.columna;
  marcas[comienzo.fila][comienzo.columna] = true;
  
  if (comienzo.fila != final.fila || comienzo.columna != final.columna)
    carretera(terreno,final, hmax, sol, longitud, 1, n, marcas,mejorSol,longMejor);
  else { 
    mejorSol[0].fila = comienzo.fila; 
    mejorSol[0].columna = comienzo.columna; 
    longMejor = 1;
  }
  
  if (longMejor < INT_MAX){
    cout << "Longitud mejor: " << longMejor << endl;
    for (int i = 0;i < longMejor;i++)
      cout << mejorSol[i].fila << ", " << mejorSol[i].columna << endl;
  } else
    cout << "No hay solucion" << endl;
  
  system("pause");
  return 0;
}

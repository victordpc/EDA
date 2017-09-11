/* Soluciones de Miguel Gomez-Zamalloa a los tres ejercicios del
   examen de EDA de febrero de 2017 (3a sesion).
 */

#include <iostream>

using namespace std;


void leerVector(int* v, int n, istream& sin) {
	for (int i = 0; i < n; i++)
		sin >> v[i];
}

/*
 * Feb. 17, Ejerc. 1. Quitar los impares de un vector

 P: ord(v,0,n) /\ n >= 0 /\ v = V /\ n = N
 Q: ord(v,0,n) /\ forall i: 0 <= i < N /\ par(V[i]): exists j: 0 <= j < n: V[i] = v[j] /\
	n = #i: 0 <= i < N : par(V[i])
 I: ord(v,0,numPares) /\ forall k: 0 <= k < i /\ par(V[k]): exists j: 0 <= j < numPares: V[i] = v[j] /\
	0 <= i <= n /\ (numPares = #k: 0 <= k < i : par(V[k])) /\ ord(v,i,n) /\
	((0 < numPares < i < n) => v[numPares-1] < v[i])

 * donde:
 *   ord(v,a,b) = forall i: a <= i < b-1: v[i] < v[i+1]
 *   par(x) = (x%2 == 0)

 */
void quitarImpares(int* v,int& n){
	int i = 0;
	int numPares = 0;
	while (i < n){
		if (v[i]%2 == 0){
			v[numPares] = v[i];
			numPares++;
		}
		i++;
	}
	n = numPares;
}


/*
 * Feb. 17, Ejerc. 2. Contar elementos distintos (los iguales aparecen consecutivos)
 */
int contarDistintos(int* v, int a, int b){
	if (v[a] == v[b]) return 1;
	else if (a == b-1) return 2;
	else {
		int m = (a+b)/2;
		return contarDistintos(v,a,m) + contarDistintos(v,m,b) - 1;
	}
}


/*
 * Feb. 17, Ejerc. 3. Torre de colores. Formar todas las posibles torres con fichas de
 * tres colores (azul, rojo y verde) con estas restricciones:
 *   - No dos verdes seguidas.
 *   - En todo momento no mas verdes que azules
 *   - Al final, más de la mitad son rojas
 */
const int NUMCOLS = 3;
typedef enum {azul,rojo,verde} Color;

void imprimirSoluc(Color* soluc, int n){
	string colores[NUMCOLS] = {"azul","rojo","verde"};
	for (int i = 0; i < n-1; i++)
		cout << colores[soluc[i]] << " ";
	cout << colores[soluc[n-1]] << endl;
}

bool esFactible(Color* soluc, int k, int n, const int numPiezas[NUMCOLS], int frecsTorre[NUMCOLS]){
	if (frecsTorre[soluc[k]] > numPiezas[soluc[k]]) return false;
	else if ((soluc[k-1] == verde) && (soluc[k] == verde)) return false;
	else if (frecsTorre[verde] > frecsTorre[azul]) return false;
	// Esto ultimo estima cuántas rojas pueden colocarse aún y mira si con eso no superas n/2
	else if (frecsTorre[rojo] + min((n-k-1),(numPiezas[rojo]-frecsTorre[rojo])) <= n/2) return false;
	else return true;
}

void torresColoresVA(Color* soluc, int k, int n, int numPiezas[NUMCOLS], int frecsTorre[NUMCOLS],int& numSols){
	// 0->azul; 1->rojo; 2->verde
	for (Color c = azul; c <= verde; c = Color(c+1)){
		soluc[k] = c;
		frecsTorre[c]++;
		if (esFactible(soluc,k,n,numPiezas,frecsTorre)){
	        if (k == n-1){
	        	if (frecsTorre[1] > n/2){// Redundante (se pregunta en esFactible)
	        		imprimirSoluc(soluc,n);
	        		numSols++;
	        	}
	        } else
	        	torresColoresVA(soluc,k+1,n,numPiezas,frecsTorre,numSols);
		}
		frecsTorre[c]--;
	}
}

void torresColores(int n, int a, int r, int v){
	int numPiezas[NUMCOLS] = {a,r,v};
	int frecsTorre[NUMCOLS] = {0};
	Color* soluc = new Color[n];
	int numSols = 0;
	soluc[0] = rojo; // Primera roja
	frecsTorre[1]++;
	torresColoresVA(soluc,1,n,numPiezas,frecsTorre,numSols);
	if (numSols == 0) cout << "SIN SOLUCION" << endl;
	delete[] soluc;
}


// Mains

void mainQI() {
	int n;
	int* v;
	cin >> n;
	while (n >= 0){
		v = new int[n];
		leerVector(v, n, cin);
		quitarImpares(v,n);
		for (int j = 0; j < n-1; j++)
			cout << v[j] << " ";
		if (n > 0) cout << v[n-1];
		cout << endl;
		delete[] v;
		cin >> n;
	}
}

void mainCD() {
	int n;
	int* v;
	cin >> n;
	while (n > 0){
		v = new int[n];
		leerVector(v, n, cin);
		cout << contarDistintos(v,0,n-1) << endl;
		delete[] v;
		cin >> n;
	}
}

void mainTC() {
	int n, a, r, v;
	cin >> n >> a >> r >> v;
	while (!(n == 0 && a == 0 && r == 0 && v == 0)){
		torresColores(n,a,r,v);
		cout << endl;
		cin >> n >> a >> r >> v;
	}
}

int main(){
	//mainQI();
	//mainCD();
	mainTC();
}

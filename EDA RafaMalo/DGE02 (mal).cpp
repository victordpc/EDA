#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void leerVector(int* v, int n, istream& sin);
bool zzz(int* v, int n, int p);

int main()
{
  int numPruebas = 0, n = 0, p = 0;
  int* v;
  bool r = false;
  
  cin >> numPruebas;

    while (numPruebas > 0)
     {
        cin >> n;
        cin >> p;
        
        v = new int[n];
        leerVector(v, n, cin);
        
        r = zzz(v, n, p);
        delete[] v;
        
        if(r)
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
        
        numPruebas--;
     }
 
 return 0;
}

void leerVector(int* v, int n, istream& sin)
{
	for (int i = 0; i < n; i++)
		sin >> v[i];
}

bool zzz(int* v, int n, int p)
{
    bool resultado = true;
    int max = v[0], j = p + 1;
    
    for(int i = 0; i <= p; i++)
    {
        if(v[i] > max)
            max = v[i];
    }
    
    while (resultado && j < n)
    {
        if(max > v[j])
            resultado = false;
            
        j++;
    }
    
    return resultado;
}
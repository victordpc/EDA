#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numPruebas = 0, b = 0, n = 0, resultado = 0, z = 0;
    
    cin >> numPruebas;

    while (numPruebas > 0)
     {
         cin >> b;
         cin >> n;
        
        z = b;
        
        while(z <= n)
        {
            z *= b;
            ++resultado;
        }
        
        cout << resultado << endl;
        resultado = 0;
        
         numPruebas--;
     }
     
     return 0;
}
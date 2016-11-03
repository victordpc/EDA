#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numPruebas = 0, n = 0, numero = 0, resultado = 0;
    
    cin >> numPruebas;

    while (numPruebas > 0)
     {
         cin >> n;
        
        while(n> 0)
        {
            cin >> numero;
            
            if(numero % 2 == 0)
            ++resultado;
            
            --n;
        }
        
        cout << resultado << endl;
        resultado = 0;
        
         numPruebas--;
     }
     
     return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numPruebas = 0, obj = 0, dias = 0, d1 = 0, d2 = 1, d3 = 0, lleva = 1;
    
    cin >> numPruebas;

    while (numPruebas > 0)
     {
        cin >> obj;
        
        if(obj >0)
        {
            ++dias;
            while (lleva < obj)
            {
                d3 = 2*d1 + d2;
                lleva += d3;
                d1 = d2;
                d2 = d3;
                
                ++dias;
            }    
        }    
      
        cout << dias << endl;
        d1 = d3 = dias = 0;
        d2 = lleva = 1;
        
         numPruebas--;
     }
     
     return 0;
}
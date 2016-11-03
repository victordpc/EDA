#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numPruebas = 0, t1 = 0, t2 = 0, t3 = 0, n = 0, p = 0, v = 0;
    
    cin >> numPruebas;

    while (numPruebas > 0)
     {
        cin >> n;
                 
        if(n < 3)
        {
            while(n >0)
            {
                cin >> t1;
                --n;
            }
        }
        else
        {
            cin >> t1;
            cin >> t2;
            cin >> t3;
            
            if(t1 > t2 && t2 < t3)
            {
                ++v;
            }
            else if(t1 < t2 && t2 > t3)
            {
                ++p;
            }    
            
            n -= 3;
            
            while(n > 0)
            {
                t1 = t2;
                t2 = t3;
                cin >> t3;
                
                 if(t1 > t2 && t2 < t3)
                {
                    ++v;
                }
                else if(t1 < t2 && t2 > t3)
                {
                    ++p;
                } 
                
               --n;
            }
        }
        
        cout << p << " " << v << endl;
        t1 = t2 = t3 = v = p = 0;
        
         numPruebas--;
     }
     
     return 0;
}
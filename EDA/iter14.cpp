//
//  iter14.cpp
//  EDA
//
//  Created by Victor del Pino Castilla on 12/11/16.
//  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string n = "";
    int ordenadas = 0, max = 0;
    getline(cin,n);
    
    while (n != "XXX"){
        int i = 1;
        int lon =n.length();
        
        while (i< lon) {
            char a = n[i-1];
            char b = n[i];
            a = toupper(a);
            b = toupper(b);
            
            if (a < b){
                ordenadas++;
            }
            else {
                if (ordenadas > max){
                    max = ordenadas;
                }
                ordenadas = 0;
            }
            i++;
        }
        
        if (ordenadas > max){
            max = ordenadas;
        }

        if (lon > 1){
            if (max != 0)
                max++;
        } else{
            if (lon ==1)
                max++;
        }
        
        cout << lon << " " << max << endl;

        ordenadas = 0;
        max = 0;
        getline(cin,n);
    }
    return 0;
}

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
        int i = 0;
        
        while (i< n.length() - 1) {
            char a = n[i];
            char b = n[i+1];
            
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
        if (max != 0)
            max++;
        
        cout << n.length() << " " << max << endl;

        getline(cin,n);
        ordenadas = 0;
        max = 0;
    }
    return 0;
}

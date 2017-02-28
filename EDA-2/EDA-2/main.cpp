
//#include "DateTests.h"
//#include "SetTests.h"

#include <stdio.h>
#include "SetOfInts3.h"

using namespace std;

void ejercicio1Tema7();

int main(){
    //testSmallSet();
	//testSetOfInts();
	//testGenericSet();
    //testDate1A();
    //testDate1B();
    //testDate2();
    //testDate4();
    ejercicio1Tema7();
}

void ejercicio1Tema7(){
    int sizeSet = 0, valor = 0, n=0;
    SetOfInts3 set;
    cin >> sizeSet;
    while (sizeSet != 0) {
        n=sizeSet;
        set = SetOfInts3();
        cin >> valor;
        while (valor != -1) {
            
            set.add(valor);
            
            if(set.getSize() > sizeSet){
                set.removeMax();
            }
            cin >> valor;
        }

        cout << set << endl;

        cin >> sizeSet;
        set = SetOfInts3();
    }
    
}


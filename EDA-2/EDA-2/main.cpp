
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
    int sizeSet = 0, valor = 0;
    SetOfInts3 set = SetOfInts3();
    cin >> sizeSet;
    while (sizeSet != 0) {
        cin >> valor;
        while (valor != -1) {
            set.add(valor);
            cin >> valor;
        }

        for (int i = set.getSize()-sizeSet; i>0; i--) {
            set.removeMax();
        }

        cout << set << endl;

        cin >> sizeSet;
        set = SetOfInts3();
    }
    
    //    Escribe una funci´on (fuera del TAD) que dada una serie de n n´umeros enteros (en un array o vector),
    //    encuentre los k n´umeros menores distintos, devolviendo el resultado en un conjunto SetOfInts3
    //    (como par´ametro por referencia).
}


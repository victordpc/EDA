
//#include "DateTests.h"
//#include "SetTests.h"

#include <stdio.h>
//#include "SetOfInts3.h"
#include "Set.h"
#include "string"

using namespace std;

void ejercicio1Tema7();
void ejercicio2Tema7();
void extInt(istream& sin , Set<int> *result, int k );
void extStr(istream& sin , Set<string> *result, int k );

int main(){
    //testSmallSet();
	//testSetOfInts();
	//testGenericSet();
    //testDate1A();
    //testDate1B();
    //testDate2();
    //testDate4();
    //ejercicio1Tema7();
    ejercicio2Tema7();
}

void ejercicio2Tema7(){
    char O;
    int k=0;
    cin >> O;
    while(!cin.fail())
    {
        cin >> k;
        if(O == 'N'){
            Set<int> *result= new Set<int>();
            
            extInt(cin, result, k);
            
            cout << (* result)<< endl;
            
            delete result;
        }
        else if (O=='P'){
            Set<string> *result= new Set<string>();
     
            extStr(cin, result, k);
            
            cout << (* result)<< endl;
            
            delete result;
        }
        
        cin >> O;
    }
}

void extInt(istream& sin , Set<int> *result, int k ){
    int valor=0;
    for (int i = 0; i<k; i++) {
        cin >> valor;
        if(result->contains(valor))
            i--;
        else
            result->add(valor);
    }

    cin >> valor;
    while (valor != -1){
        
        if (valor > (*result->getMin()) && !result->contains(valor)){
            result->add(valor);
            result->removeMin();
        }
        
        cin >> valor;
    }
}


void extStr(istream& sin , Set<string> *result, int k ){
    string valor="";
    for (int i = 0; i<k; i++) {
        cin >>valor;
        if(result->contains(valor))
            i--;
        else
            result->add(valor);
    }
    
    cin >>valor;
    while (valor != "FIN"){
        
        if (valor > (*result->getMin()) && !result->contains(valor)){
            result->add(valor);
            result->removeMin();
        }
        
        cin >>valor;
    }
}

//void ejercicio1Tema7(){
//    int sizeSet = 0, valor = 0, n=0;
//    SetOfInts3 set;
//    cin >> sizeSet;
//    while (sizeSet != 0) {
//        n=sizeSet;
//        set = SetOfInts3();
//        cin >> valor;
//        while (valor != -1) {
//            
//            if(valor < set.getMax()){
//                set.add(valor);
//            
//                if(set.getSize() > sizeSet){
//                    set.removeMax();
//                }
//            }
//            cin >> valor;
//        }
//
//        cout << set << endl;
//
//        cin >> sizeSet;
//        set = SetOfInts3();
//    }
//    
//}
//

//
//  SetTests.cpp
//  EDA_2
//
//  Created by Victor del Pino Castilla on 23/2/17.
//  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
//

#include "SetTests.h"

void testSmallSet(){
    //SetOfInts1 sTest1 = SetOfInts1();
    SetOfInts2 sTest2 = SetOfInts2();
    SetOfInts2 sTest2_1 = SetOfInts2();
    //SetOfInts3 sTest3 = SetOfInts3();
    
    cin >> sTest2;
    cin >> sTest2_1;
    
    if(sTest2 == sTest2_1)
        cout << "iguales";
    else
        cout << "diferentes";
    
    
}

void testSetOfInts(){
    
}

void testGenericSet(){
    
}


/*
 
 SetOfInts3();
 bool isEmpty() const;
 void add(int x) throw (Error);
 bool contains(int x) const;
 void remove(int x);
 friend istream& operator>>(istream& sIn,SetOfInts3& set);
 friend ostream& operator<<(ostream& sOut,SetOfInts3& set);
*/


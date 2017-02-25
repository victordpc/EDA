//
//  SetTests.cpp
//  EDA_2
//
//  Created by Victor del Pino Castilla on 23/2/17.
//  Copyright © 2017 Victor del Pino Castilla. All rights reserved.
//

#include "SetTests.h"

void testSmallSet(){
}

void testSetOfInts(){
    
}

void testGenericSet(){
    
}

void testCompareSet1(){
    SetOfInts1 sTest1_0 = SetOfInts1();
    SetOfInts1 sTest1_1 = SetOfInts1();
    
    cin >> sTest1_0;
    cin >> sTest1_1;
    
    if(sTest1_0 == sTest1_1)
        cout << "iguales";
    else
        cout << "diferentes";
    cout << endl;
}

void testCompareSet2(){
    SetOfInts2 sTest2_0 = SetOfInts2();
    SetOfInts2 sTest2_1 = SetOfInts2();
    
    cin >> sTest2_0;
    cin >> sTest2_1;
    
    if(sTest2_0 == sTest2_1)
        cout << "iguales";
    else
        cout << "diferentes";
    cout << endl;
}

void testCompareSet3(){
    SetOfInts3 sTest3_0 = SetOfInts3();
    SetOfInts3 sTest3_1 = SetOfInts3();
    
    cin >> sTest3_0;
    cin >> sTest3_1;
    
    if(sTest3_0 == sTest3_1)
        cout << "iguales";
    else
        cout << "diferentes";
    cout << endl;
}

void testLessSet3(){
    SetOfInts3 sTest3_0 = SetOfInts3();
    SetOfInts3 sTest3_1 = SetOfInts3();
    
    cin >> sTest3_0;
    cin >> sTest3_1;
    
    if(sTest3_0 < sTest3_1)
        cout << "contiene";
    else
        cout << "no contiene";
    cout << endl;
}

void testLessEqualSet3(){
    SetOfInts3 sTest3_0 = SetOfInts3();
    SetOfInts3 sTest3_1 = SetOfInts3();
    
    cin >> sTest3_0;
    cin >> sTest3_1;
    
    if(sTest3_0 <= sTest3_1)
        cout << "contiene";
    else
        cout << "no contiene";
    cout << endl;
}

void testGreaterSet3(){
    SetOfInts3 sTest3_0 = SetOfInts3();
    SetOfInts3 sTest3_1 = SetOfInts3();
    
    cin >> sTest3_0;
    cin >> sTest3_1;
    
    if(sTest3_0 > sTest3_1)
        cout << "contiene";
    else
        cout << "no contiene";
    cout << endl;
}

void testGreaterEqualSet3(){
    SetOfInts3 sTest3_0 = SetOfInts3();
    SetOfInts3 sTest3_1 = SetOfInts3();
    
    cin >> sTest3_0;
    cin >> sTest3_1;
    
    if(sTest3_0 >= sTest3_1)
        cout << "contiene";
    else
        cout << "no contiene";
    cout << endl;
}

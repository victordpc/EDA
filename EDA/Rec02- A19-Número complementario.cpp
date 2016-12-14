////
////  rec2.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 24/11/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int complementarioFinal(int num);
//int complementarioNoFinal(int num);
//
//int recursivoFinal(int num,int acumulado,int auxiliar);
//
//
//int main(){
//    int num =0;
//    
//    cin >> num;
//
//    while (num != -1){
//        cout << complementarioFinal(num) << endl;
////        cout << complementarioNoFinal(num) << endl;
//        
//        cin >> num;
//    }
//}
//
//
//int complementarioFinal(int num){
//    if (num/10 < 1)
//        return 9-(num % 10);
//    else
//        return recursivoFinal(num, 0, 1);
//}
//
//int recursivoFinal(int num, int acumulado, int auxiliar){
//    if (num / 10 < 1)
//        return (9 - (num % 10)) * auxiliar + acumulado;
//    else
//        return recursivoFinal(num / 10, (9 - (num % 10)) * auxiliar + acumulado, auxiliar * 10);
//}
//
//int complementarioNoFinal(int num){
//    if (num/10 < 1)
//        return 9-(num % 10);
//    else{
//        return ((9 - (num % 10)) + (10 * complementarioNoFinal(num / 10)));
//    }
//}

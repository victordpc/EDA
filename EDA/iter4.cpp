////
////  iter4.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 27/10/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <iostream>
//
//using namespace std;
//
//int carniceriaChachi(int a[], int n);
//
//int main(){
//    int casos;
//    int n;
//    int a[100000];
//    cin >> casos;
//    
//    while (casos > 0){
//        cin >> n;
//        if(n != 0){
//            for (int i = 0; i < n; i++){
//                cin >> a[i];
//            }
//            cout << carniceriaChachi(a, n) << endl;
//        }
//        else
//            cout << 0 << endl;
//
//        casos--;
//    }
//    return 0;
//}
//
//int carniceriaChachi(int a[],int n)
//{
//    int r = 0;
//    int min = a[n - 1];
//
//    for (int i = n - 2; i >= 0; i--)
//    {
//        if (a[i] > min)
//            r++;
//        else if (a[i] < min)
//            min = a[i];
//    }
//
//    return r;
//}

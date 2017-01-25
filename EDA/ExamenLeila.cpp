////
////  aaa.cpp
////  EDA
////
////  Created by Victor del Pino Castilla on 21/12/16.
////  Copyright © 2016 Victor del Pino Castilla. All rights reserved.
////
//
//#include <stdio.h>
//
//
//
//
//int distancia(int v[], int n){
//    int r=0;
//    int l=0;
//    bool primerUno = true;
//    bool ahoraCeros = false;
//    
////I = { (0<=i<=n)
////    ^ (l=(#p: 0<=p<=N : v[p]=0 ^ (noExiste q : 0<=q<j : V[q]=1 )))
////    ^(r=(#r: 0<=r<=N : v[r]=1 ^ (noExiste s : i<s<n : V[s]=0 )) -1 )
////    ^ primerUno = ( ¬(Existe) t : 0 <= t < N : V[t]=1 ^ ( (ParaTodo) u : 0<= u < t : V[u]=1 ))
////    ^ ahoraCeros = V[i] = 0
//    
//    for(int i=0; i<n;i++){
//         if (v[i]==0){
//            ahoraCeros= true;
//             if(primerUno){
//                 l=i;
//             }
//         }
//        if (v[i]==1 && ahoraCeros){
//            r=i-1;
//            primerUno=false;
//        }
//    }
//    return r-l;
//}
//    

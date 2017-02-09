//#include <iostream>
//using namespace std;
//
//typedef struct{
//    //bool anadida;
//    int duracion;
//    int puntuacion;
//} tCancion;
//
//const int N = 50;
//
//bool esValida(const tCancion cinta[], int k, int tamCinta, int durIni);
//bool esMejor(const tCancion cinta[], int k, int puntMax);
//bool esRepetida(const tCancion cinta[], int k);
//int duracionLista(const tCancion cinta[], int k, int durIni);
//int puntuacionLista(const tCancion cinta[], int k);
//void va(const tCancion lista[], tCancion cinta[], int n, int k, int tamCinta, int &puntMaxima, int durIni, int& nk, tCancion mejorCinta[]);
//void copiarCinta(tCancion cinta[], tCancion mejorCinta[], int k);
//
//int main(){
//    int n = 0;
//    int tamCinta = 0;
//    int maxPunt = 0;
//    int nk = 0;
//    tCancion lista[N];
//    tCancion cinta[N];
//    tCancion mejorCinta[N];
//    
//    cin >> n;
//    cin >> tamCinta;
//   
//    for (int i = 0; i < n; i++){
//        cin >> lista[i].duracion >> lista[i].puntuacion;
//    }
//    va(lista, cinta, n, 0, tamCinta, maxPunt, 0, nk, mejorCinta);
//    int durIni = tamCinta - duracionLista(mejorCinta, nk, 0);
//    //va(lista, cinta, n, nk, tamCinta, maxPunt, durIni, 0);
//    va(lista, mejorCinta, n, nk, tamCinta*2, maxPunt, durIni, nk, mejorCinta);
//    cout << maxPunt;
//}
//
//
//
//void va(const tCancion lista[], tCancion cinta[], int n, int k, int tamCinta, int &puntMaxima, int durIni, int& nk, tCancion mejorCinta[])
//{
//    int i = 0;
//    
//    while(i < n){
//        cinta[k++] = lista[i];
//        if( esValida(cinta, k, tamCinta, durIni) ){
//            if( esMejor(cinta, k, puntMaxima) ){
//                puntMaxima = puntuacionLista(cinta, k);
//                nk = k;
//                copiarCinta(cinta, mejorCinta, k);
//                va(lista, cinta, n, k, tamCinta, puntMaxima, durIni, nk, mejorCinta);
//            }
//
//        }
//        k--;
//        i++;
//        
//    }
// 
//    
//}


//#include <stack>
//#include <iostream>
//#include "string"
//
//using namespace std;
//
//
//int main() {
//	string car;
//	getline(cin, car);
//	while (car != ".") {
//		comprobar(car);
//		getline(cin, car);
//	}
//
//}
//
//void comprobar(const string &car) {
//
//}
//
#include <iostream>
#include <fstream>
#include "Queue.h"

void ejercicio0801() {
	int numCasos;
	int n;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		Queue<int>* q = new Queue<int>();
		cin >> n;
		while (n != -1) {
			q->push_back(n);
			cin >> n;
		}
		cin >> n;
		cout << *q;
		q->reverseFirstK(n);
		cout << *q;
		delete q;
	}
}
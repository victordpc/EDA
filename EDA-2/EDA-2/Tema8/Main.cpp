#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

int main() {
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
//	system("PAUSE");
}


//#include "Tests.h"
//
//int main(){
//	//testStack();
//	//testLinkedListStack();
//	testQueue();
//	//testList();
//}

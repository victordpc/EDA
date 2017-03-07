
#ifndef Set_H_
#define Set_H_

#include <iostream>
using namespace std;

#include "Error.h"


template<class T>
class Set {
	// Conjuntos genéricos representados mediante un array dinámico ordenado sin repeticiones
private:
	static const int DEFAULT_CAPACITY = 5;

	T* elems;
	int i,j;
	int capacity;

	bool isFull() const;
	void binSearch(const T& x, bool& found, int& pos) const;
	int binSearchAux(const T& x, int a, int b) const;
	void shiftRightFrom(int ini);
	void shiftLeftFrom(int ini);
	void shiftLeftFromTo(int ini, int fin);
	void shiftRightFromTo(int ini, int fin);
	void reallocate();

public:
	Set(int initCapacity = DEFAULT_CAPACITY);
	Set(const Set<T>& set);
	~Set();
	bool isEmpty() const;
	void add(const T& x);
	bool contains(const T& x) const;
	void remove(const T& x);
	void erase();
	void write(ostream& sOut);
	void read(istream& sIn);
	void removeMax();
	void removeMin();
	const T &getMax();
	const T &getMin();
};


// Constructors

template<class T>
Set<T>::Set(int initCapacity) {
	i = j = 0;
	capacity = initCapacity;
	elems = new T[capacity];
}

template<class T>
Set<T>::Set(const Set<T>& set) {
	i = set.i;
	j = set.j;
	capacity = set.capacity;
	elems = new T[capacity];
	for (int ii = i; ii <= j; ii++)
		elems[ii] = set.elems[ii];
}

template<class T>
Set<T>::~Set() {
	delete[] elems;
	elems = NULL;
}

// Public methods

template<class T>
bool Set<T>::isEmpty() const{
	return (i == j);
}

template<class T>
void Set<T>::add(const T& x){
	bool found;
	int pos;

	binSearch(x, found, pos);
	if (!found){
		if (i > 0)
			shiftLeftFromTo(--i, pos);
		else
			shiftRightFromTo(pos + 1, ++j);
		elems[pos + 1] = x;
		if (isFull()) reallocate();
	}
}

template<class T>
void Set<T>::remove(const T& x){
	bool found;
	int pos;

	binSearch(x, found, pos);
	if (found) {
		shiftLeftFromTo(pos,j--);
	}
	if (i == j) 
		erase();
}

template<class T>
bool Set<T>::contains(const T& x) const {
	bool found;
	int pos;

	binSearch(x, found, pos);
	return found;
}

template<class T>
void Set<T>::erase(){
	i= j = 0;
}

template<class T>
void Set<T>::write(ostream& sOut){
	//	sOut << "{";
	for (int ii = 0; ii < j - 1; ii++)
		sOut << elems[ii] << " ";
	if (j > i) sOut << elems[j-1];
	//	sOut << "}";
}

template<class T>
void Set<T>::read(istream& sIn){
	int n;
	T d;
	sIn >> n;
	erase();
	for (int ii = 0; ii < n; ii++){
		sIn >> d;
		add(d);
	}
}

template<class T>
istream& operator>>(istream& sIn, Set<T>& set) {
	set.read(sIn);
	return sIn;
}

template<class T>
ostream& operator<<(ostream& sOut, Set<T>& set) {
	set.write(sOut);
	return sOut;
}

template<class T>
void Set<T>::removeMax(){
	j--;
	if (i == j)
		erase();
}

template<class T>
void Set<T>::removeMin(){
	shiftLeftFrom(0);
	j--;
	if (i == j)
		erase();
}

template<class T>
const T &Set<T>::getMin(){
	return elems[i];
}

template<class T>
const T &Set<T>::getMax(){
	return elems[j];
}


// Private methods

template<class T>
bool Set<T>::isFull() const {
	return j+1 == capacity;
}

template<class T>
int Set<T>::binSearchAux(const T& x, int a, int b) const {
	// Pre: elems está ordenado entre 0 .. size-1
	//      ( 0 <= a <= size ) && ( -1 <= b <= size ) && ( a <= b+1 )
	//      todos los elementos a la izquierda de 'a' son <= x
	//      todos los elementos a la derecha de 'b' son > x

	int p, m;

	if (a == b + 1)
		p = a - 1;
	else if (a <= b) {
		m = (a + b) / 2;
		if (elems[m] <= x)
			p = binSearchAux(x, m + 1, b);
		else
			p = binSearchAux(x, a, m - 1);
	}
	return p;
	// Post: devuelve el mayor índice i (0 <= i <= size-1) que cumple
	//       elems[i] <= x
	//       si x es menor que todos los elementos de elems, devuelve -1
}

template<class T>
void Set<T>::binSearch(const T& x, bool& found, int& pos) const {
	// Pre: los size primeros elementos de elems están ordenados
	//      size >= 0

	pos = binSearchAux(x, i, (j-i) - 1);
	found = (pos >= i) && (pos <= j) && (elems[pos] == x);

	// Post : devuelve el mayor índice i (0 <= i <= size-1) que cumple
	//        elems[i] <= x
	//        si x es menor que todos los elementos de elems, devuelve -1
	//        found es true si x esta en elems[0..size-1]
}

template<class T>
void Set<T>::shiftRightFrom(int ini){
	for (int jj = j + 1; jj > ini; jj--)
		elems[jj] = elems[jj - 1];
}

template<class T>
void Set<T>::shiftRightFromTo(int ini, int fin){
	for (int jj = fin; jj > ini; jj--)
		elems[jj] = elems[jj - 1];
}

template<class T>
void Set<T>::shiftLeftFrom(int ini){
	for (; ini < j; ini++)
		elems[ini] = elems[ini + 1];
}

template<class T>
void Set<T>::shiftLeftFromTo(int ini, int fin){
	for (; ini < fin; ini++)
		elems[ini] = elems[ini + 1];
}

template<class T>
void Set<T>::reallocate(){
	capacity = capacity * 2;
	T* newElems = new T[capacity];
	for (int ii = i; ii <= j; ii++)
		newElems[ii] = elems[ii];
	delete[] elems;
	elems = newElems;
}

#endif /* Set_H_ */
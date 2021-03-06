
#ifndef SETOFINTS3_H_
#define SETOFINTS3_H_

#include "Error.h"
#include <iostream>

using namespace std;

class SetOfInts3 {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
	private:
		static const int MAXSIZE = 50;

		int elems[MAXSIZE];
		int size;

		bool isFull() const;
		void binSearch(int x,bool& found,int& pos) const;
		int binSearchAux(int x, int a, int b) const;
		void shiftRightFrom(int i);
		void shiftLeftFrom(int i);

	public:
		SetOfInts3();
		bool isEmpty() const;
		void add(int x) throw (Error);
		bool contains(int x) const;
		void remove(int x);
        int getSize() const;

        int getMax() const throw (Error);
        void removeMax();
    
		friend istream& operator>>(istream& sIn,SetOfInts3& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts3& set);
        bool operator==(const SetOfInts3& set) const;
        bool operator<(const SetOfInts3& set) const;
        bool operator<=(const SetOfInts3& set) const;
        bool operator>(const SetOfInts3& set) const;
        bool operator>=(const SetOfInts3& set) const;
};

#endif /* SETOFINTS3_H_ */

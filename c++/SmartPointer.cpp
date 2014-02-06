#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

// smart pointer is a C++ class for wrapping pointers
template <typename T>
class SmartPointer{
	T* t;

public:
	SmartPointer(T* t){ assert(t != NULL); this->t = t; }
	
	SmartPointer& operator= (const SmartPointer& sp){ return *this; }
	T* operator-> () const { return t; }
	friend ostream& operator<< (ostream& out, const SmartPointer& sp) { out << *(sp.t); return out; } 
};

class Alpha{ 
public:
	int a;
	friend ostream& operator<< (ostream& out, const Alpha& obj) { out << "Alpha@" << &obj << " : a = " << obj.a; return out; } 
};

int main(){
	//SmartPointer<Alpha> sp;	--- invalid ... deliberately avoid default constructor
	Alpha a1;
	SmartPointer<Alpha> sp1(&a1);
	sp1->a = 32;
	cout << sp1 << endl;
	
	Alpha *a2;
	SmartPointer<Alpha> sp2(a2);
	cout << sp2 << endl;
	
	a2 = NULL;
	sp2 = SmartPointer<Alpha>(a2);
	cout << sp2 << endl;
	
	return 0;
}
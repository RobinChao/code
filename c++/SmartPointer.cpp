#include <iostream>

using namespace std;

class RefCount {
	int count;

public:
	RefCount() : count(0) { }
	void addRef() { ++count; }
	int release() { return --count; }
};

// smart pointer 
template <typename T>
class SmartPointer {
	T* pointer;
	RefCount* reference;

public:
	SmartPointer() : pointer(NULL), reference(NULL) { 
		reference = new RefCount;
		reference->addRef();
	}

	SmartPointer(T* pointer) : pointer(pointer), reference(NULL) { 
		reference = new RefCount();
		reference->addRef();
	}

	// copy constructor
	SmartPointer(const SmartPointer<T>& sp) : pointer(sp.pointer), reference(sp.reference) {
		reference->addRef();
	}

	// destructor
	~SmartPointer() {
		if (reference->release() == 0) {
			delete pointer;
			delete reference;
		}
	}
	
	// assignment operator
	SmartPointer<T>& operator= (const SmartPointer<T>& sp) { 
		// avoid self assignment 
		if (this != &sp) {
			if (reference->release() == 0) {
				delete pointer;
				delete reference;
			}

			pointer = sp.pointer;
			reference = sp.reference;
			reference->addRef();
		}

		return *this;
	}
	
	T& operator* () { return *pointer; }
    T* operator-> () { return pointer; }
	
	friend ostream& operator<< (ostream& out, const SmartPointer& sp) {
		out << *(sp.pointer);
		return out; 
	} 
};


class Alpha{ 
public:
	int data;
	
	friend ostream& operator<< (ostream& out, const Alpha& obj) { 
		out << "Alpha@" << &obj << " : data = " << obj.data;
		return out; 
	} 
	
	~Alpha() { cout << "Destroying ... Alpha@ " << this << endl; }
};

int main() {
	Alpha* a1 = new Alpha;
	SmartPointer<Alpha> sp1(a1);
	sp1->data = 32;
	cout << "sp1 = " << sp1 << endl;
	
	SmartPointer<Alpha> sp2 = sp1;
	cout << "sp2 = " << sp2 << endl;

	SmartPointer<Alpha> sp3 = sp2;
	cout << "sp3 = " << sp3 << endl;

	sp3 = NULL;

	sp1 = SmartPointer<Alpha>(new Alpha);
	sp1->data = 33;
	cout << "sp1 = " << sp1 << endl;

	sp2 = sp1;
	cout << "sp2 = " << sp2 << endl;

	sp3 = sp2;
	cout << "sp3 = " << sp2 << endl;
	
	return 0;
}
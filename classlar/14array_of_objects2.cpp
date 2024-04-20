#include <iostream>

using namespace std;

class myN {
private:
	int N;
	
public:
	// Default Constructor
	myN(){
		cout << "Default Constructor\n";
		N=0;
	}
	// Constructor with a paramater
	myN(int n){
		cout << "Overloaded Constructor\n";
		N=n;
	}
	~myN(){
		cout << "Destructor...\n";
	}


	// Member function
	int getN(){
		return N;
	}
	void setN(int y){
		N=y;
	}
};

int main ()  {

	// Array of objects

	cout << "-------------array of objects--------------\n";

	myN *p = new myN[10];	// Default Constructor is called 10 times. It is an array of objects of type myN.

	p[0].setN(2); 			// first array location
	
	cout << p[0].getN() << endl;		//Burada pointer olarak değil de array elemanı olarak kullandık. Bu yüzden "." ile yazıyoruz.
	
	// different style using pointer arithmetic
	(p+1)->setN(4); // Second array location
	
	cout << (p+1)->getN() << endl;
	
	delete [ ] p; // destructor is called 10 times


}


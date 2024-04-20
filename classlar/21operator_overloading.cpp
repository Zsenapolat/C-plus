#include <iostream>
using namespace std;

class Number{
	friend ostream& operator<<(ostream &out, Number& num);
	public:
		int n;
		
		Number(int n):n(n){}
		
		Number operator+(const Number& num){			//Burada num.n a oluyor. a objesini kopyalamak veya değerini değiştirmek istemiyoruz.
			cout<<"this->n = "<<this->n<<endl;			//b ise this olur.
			cout<<"num.n = "<<num.n<<endl;
			return Number(this->n + num.n);
		}
		
		bool operator==(const Number& num){				//Normal operatörlere etki etmez. Class ile bu işlem yapıldığında etki eder.
			if (num.n == this->n){
				return true;
			}
			else return false;
		}
};

ostream& operator<<(ostream &a, Number& num){
	a<<num.n;
	return a;
}


int main(){
	Number a = 5; 		//Şeklinde de tanımlanabilir.
	Number b(4);
	
	Number c = b + a;	//Böyle bir işlem yapamayız. Çünkü '+' operatörü Number objeleri için tanımlı değildir. 
						//Bunu tanımlı yapmak için overload yaparız.
	Number d(8);
	cout<<d<<endl;
	return 0;
}

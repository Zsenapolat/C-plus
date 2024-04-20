#include <iostream>

using namespace std;

class Counter{
	private:
		int count;
	
	public:
		Counter(){
			count=0;
		}
		
		void print(){
			cout<<"count: "<<count<<endl;
		}
		
		void increment(){					//Class dışındaki herhangi bir fonksiyonla class içindeki fonksiyonun adları aynı olabilir.
			count++;
		}
};
void increment(int x){
	x++;
	cout<<"x: "<<x<<endl;
}

void increment_3x(Counter &counter){	//Oluşturduğumuz kopya stack içinde depolanıyorsa büyük bir sıkıntı olmaz. Fakat heap içinde depoluyorsak
										//çok fazla yer kapladığı için büyük problemler yaratabilir. Bu yüzden pass by reference ile depolamamız
	counter.increment();				//daha mantıklıdır. (Parametre olarak referans ya da pointer kullanabilirsin.)
	counter.increment();
	counter.increment();
}
int main (){
	int a=4;
	
	cout<<"before the function: "<<a<<endl;
	increment(a);
	cout<<"after the function: "<<a<<endl;
	
	Counter* counter = new Counter;
	
	counter->print();
	increment_3x(*counter);		
	counter->print();
	
	return 0;
}


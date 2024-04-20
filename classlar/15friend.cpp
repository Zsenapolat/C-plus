#include <iostream>

using namespace std;
					//Friend fonksiyonlar class'ın private özelliklerine ve metodlarına erişebilir. Aynı zamanda birden fazla class'a erişebilirler.
					//Bir class'ın member function'ını da friend function yapabiliriz. Bir fonksiyonu başka class'larda da kullanmak istiyorsak bu 
					//fonksiyonu friend fonksiyon olarak yazarız.
					
class MyClass{
	
	friend void double_x(MyClass& object);	//Bu fonksiyon bir member function olmayacağı için private ya da public değildir. 
											//Member function olmadığı için x değerine doğrudan erişemez.
	private:
		int x;
			
		void add(int n);
		
	public:
		MyClass(int x): x(x){}
		
		void print();	
};

void MyClass::add(int n){	//Private ya da public olması farketmez. Her türlü dışarda tanımlanabilir. Main fonksiyonun içinde tanımlanamaz.
	x += n;
}

void MyClass::print(){		//Bu bir member functiondur. O yüzden burada bu şekilde tanımlanır. (Dönüş tipini yine belirtmemiz gerekir.)
	cout<<"x: "<<x<<endl;
}

void double_x(MyClass& object){	// x=x*x; şeklinde yazamayız. Parametre olarak objeleri almalıyız. Kopyalamamak içinse referans olarak yazmalıyız.

	object.add(object.x);	
}

class Costs;
int b;							//Aynı buradaki b global variable'ı gibi Costs class'ını da aşağıdaki class için kullanabiliriz.
void rand(){					//Fonksiyonlar için de geçerlidir.
	int c=c+1;
}

class Revenue{
	friend bool Compare(Revenue& rev, Costs& cost);	//Burada aşağıdaki Costs class'ına da erşimeye çalıştığımız için bu class'ın üzerinde Costs 
	private:										//classını tanımlamamız gerekiyor.
		int revenue;
		rand();
	public:
		Revenue(int revenue) : revenue(revenue){}
};

class Costs{
	friend bool Compare(Revenue& rev, Costs& cost);
	private:
		int costs;
	public:
		Costs(int costs) : costs(costs){}		
};

bool Compare(Revenue& rev, Costs& cost){
	if (rev.revenue>cost.costs) return true;
	else return false;
}
int main(){
	
	MyClass myobject(7);
	
	myobject.print();
									//myobject.double_x(myobject); şeklinde ulaşamayız. Çünkü double_x member function değildir. 
									
	double_x(myobject);				//şeklinde erişmeliyiz. Aslında normal bir fonksiyondur ama MyClass objelerine erişebilen bir fonksiyondur.
	myobject.print();
	
	Revenue revenue(1000);
	Costs costs(500);
	
	if (Compare(revenue,costs)) cout<<"True"<<endl;
	else cout<<"False"<<endl;
	return 0;
}

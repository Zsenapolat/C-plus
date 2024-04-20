#include <iostream>

using namespace std;

class MenuItem{
	public:
		string name;
		int ab;
		MenuItem(){					//Eğer base class'ın default constructor'unu yazmazsak çalışmaz. Mutlaka default constructor olmalı.
			name="unknown";
			cout<<"Base constructor"<<endl;
		}
		
		MenuItem(int ab){			//Bir fonksiyonu override edebilmemiz için o fonksiyonun bir base class'tan derive edilmesi gerek.
									//Bir base class'ın fonksiyonu başka bir base classta override edilemez.
			cout<<"Base param constructor"<<endl;
		}
};

class Drink : public MenuItem{
	public:
		int ounces;
		
		using MenuItem::MenuItem;	//Bu şekilde yazdığımızda base class'ın bütün constructor'ları inherit edilecektir. Drink objesi oluştururken
									//eğer MenuItem parametresini de kullanabilmek istiyorsak bu şekilde yazarız.
		
		Drink() {			//Derived class'ın default constructor'unu çağırdığımızda eğer yanında base class'ı da tanımlamadıysak
							//base class'ın default constructor'u çağrılacaktır. Eğer tanımladıysak param constructor'u çağrılacaktır.
			ounces = 9;
			cout<<"Derived constructor"<<endl;
		}											
		Drink (int set_ounces) : MenuItem(3)	
		{						//Bu şekilde çalıştırdığımızda base class'ın param constructor'u çalışır.
			ounces = set_ounces;
			cout<<"Derived param constructor"<<endl;
		}
};
int main(){
	MenuItem soup;		//Base class'tan bir obje üretirsek sadece base class'ın constructor'u çalışır.

	Drink soda(8);		//Derived class'tan bir obje ürettiğimizde ise ikisinin de constructor'u çalışır. Çünkü Derived class Base class'ın da 
						//özelliklerine erişebilir. Eğer int bir değer girersek drink class'ının param constructor'ı çalışır.
						//String girersek MenuItem'ın constructor'larını inherit ettiğimiz için base class param constructor'u çalışacaktır.
	Drink coke;
	return 0;					
}

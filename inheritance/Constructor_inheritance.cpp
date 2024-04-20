#include <iostream>

using namespace std;

class MenuItem{
	public:
		string name;
		int ab;
		MenuItem(){							//Eðer base class'ýn default constructor'unu yazmazsak çalýþmaz. Mutlaka default constructor olmalý.
			name="unknown";
			cout<<"Base constructor"<<endl;
		}
		
		MenuItem(int ab){				//Bir fonksiyonu override edebilmemiz için o fonksiyonun bir base class'tan derive edilmesi gerek.
									//Bir base class'ýn fonksiyonu baþka bir base classta override edilemez.
			cout<<"Base param constructor"<<endl;
		}
};

class Drink : public MenuItem{
	public:
		int ounces;
		
		using MenuItem::MenuItem;					//Bu þekilde yazdýðýmýzda base class'ýn bütün constructor'larý inherit edilecektir.Drink objesi oluþtururken
													//eðer MenuItem parametresini de kullanabilmek istiyorsak bu þekilde yazarýz.
		
		Drink(){									//Derived class'ýn default constructor'unu çaðýrdýðýmýzda eðer yanýnda base class'ý da tanýmlamadýysak
													//base class'ýn default constructor'u çaðrýlacaktýr. Eðer tanýmladýysak param constructor'u çaðrýlacaktýr.
			ounces = 9;
			cout<<"Derived constructor"<<endl;
		}											
		Drink (int set_ounces)	
		{											//Bu þekilde çalýþtýrdýðýmýzda base class'ýn default constructor'u çalýþýr. Drink (double set_ounces)
													//Eðer base class'ýn param constructor'u çalýþsýn istiyorsak 
			ounces = set_ounces;
			cout<<"Derived param constructor"<<endl;
		}
};
int main(){
	MenuItem soup;					//Base class'tan bir obje üretirsek sadece base class'ýn constructor'u çalýþýr.
	Drink soda(8);					//Derived class'tan bir obje ürettiðimizde ise ikisinin de constructor'u çalýþýr. Çünkü Derived class Base class'ýn da 
									//özelliklerine eriþebilir. Eðer int bir deðer girersek drink class'ýnýn param constructor'ý çalýþýr.
									//String girersek MenuItem'ýn constructor'larýný inherit ettiðimiz için base class param constructor'u çalýþacaktýr.
	return 0;					
}

#include <iostream>
#include <string>

using namespace std;
class Employee{							
	private:
		int age;
		int salary;
	
	public:
		Employee(){					
			age=0;
			salary=0;
		}
		Employee(int age){				
			this->age=age;
				
		}
		Employee(int age, int salary){	
			this->age=age;
			this->salary=salary;		
		}
		
		int getAge(){
			return age;
		}
		int getSalary(){
			return salary;
		}
		void showInfos(){				
			cout<<age<<endl;
			cout<<salary<<endl;

		}
};
void samp(Employee* emp){				//Pointer parametre oluþturuyoruz.
	emp->showInfos();
}
int main(){
	Employee employee1(35,3000);
	samp(&employee1);					//Oluþturduðumuz objeyi samp fonksiyonunun içine gönderdik ama pointer kullanmadan gönderdiðimiz için
										//týpký deðiþkenlerde olduðu gibi fonksiyonumuz için ayrý bir obje daha oluþturmuþ oluyoruz. 
										//Girdiðimiz employee1 objesini kopyalayýp emp objesi oluþturuyoruz. Bu da gereksiz bellek harcamamýza neden oluyor.
										//Bu yüzden objeyi deðil objenin adres bilgisini gönderiyoruz. Direkt olarak objenin kendisine fonksiyonumuz üzerinden
										//ulaþýp ekrana bu þekilde yazdýrýyoruz.
										
	return 0;
}

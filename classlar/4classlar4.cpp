#include <iostream>
#include <string>

using namespace std;

class Employee{			//Set metodlarının sayısı çok fazla olursa bu değerleri girmemiz hem çok zamanımızı alır hem de kod karmaşası olmuş olur.
						//Bu sorunu önlemek için CONTSTRUCTOR kullanıyoruz. Member variable'ları constructor ile başlatırız.
	private:
		int age;		//Eğer fonksiyonumuz dışarda çalıştırılacaksa public olarak oluşturulur. Dışarıyla bir işi yoksa private oluşturulabilir.
		int salary;
	
	public:
		Employee(){				  //Eğer hiç constructor yazmazsak ve değişkenlerimize değer vermezsek C++ default constructor'ını kullanır.
			age=0;
			salary=0;
		}
		Employee(int age){			//Constructor overloading: Eğer bir constructor'ı birden fazla kez farklı şekillerde tanımlarsak 
									//çok fonksiyonlu hale getirmiş oluruz.
			this->age=age;
				
		}
		Employee(int, int);				//Constructor class'ın adıyla aynı ada sahiptir. Bir dönüş değeri yoktur. Amacı obje oluşturulduğunda  	
										//değerleri kullanıcıdan almaktır.
			
		
		int getAge(){
			return age;
		}
		int getSalary(){
			return salary;
		}
		void showInfos(){		//Class fonksiyonları class'ta oluşturulan değişkenleri kullanabildiği için parametre girmemize gerek yok.
								//Constructor'da ise dışarıdan girilen değeri class değişkenlerine eşitleyeceğimiz için parametre yazmalıyız.
								//Kısaca eğer dışarıdan alınan bir girdiyi class içindeki bir değişkene eşitleyeceksek parametre girmemiz gerekir.
			cout<<age<<endl;
			cout<<salary<<endl;

		}
};
Employee::Employee(int age,int salary){
	this->age=age;
	this->salary=salary;		//this pointer'ı sayesinde constructor dışında tanımladığımız değişkenlerle parametrelerin adını aynı yapabiliriz. 
								//Sol kısım class'ın değişkeni. Sağ taraf constructor parametresi.
}
int main(){
	Employee employee1(21,3000);			//Parametreler obje oluşturulurken verilir.
	employee1.showInfos();
	Employee employee2(22);
	employee2.showInfos();
	Employee employee3;						//Eğer constructor boşsa bu şekilde çağırırız.
	employee3.showInfos();
	Employee employee4;
	employee4 = Employee(12);				//Constructor'u direkt olarak çağırıyoruz. Obje kopyalanmış oluyor.
	employee4.showInfos();
	return 0;
}

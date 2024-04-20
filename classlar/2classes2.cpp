#include <iostream>
#include <string>

using namespace std;

class Employee{											//set komutları kullanıcıdan girdi almak için kullanılır.
														//get komutları dışarıya değer döndürmek için kullanılır.
	private:
		int age;
	
	public:
		void setAge(int age){
			this->age=age;								//this keyword'ü static olmayan member function'larda kullanılır.
		}
		
		int getAge(){
			return age;
		}
};

int main(){
	
	Employee* employee = new Employee();	/*employee adında bir obje oluşturduk ve bu obje için bir yer ayırdık. Bu ayrılan yeri daha sonradan
											silmek istediğimizde adresini kaybetmeyelim diye pointer olarak oluşturuyoruz. (Sonuna parantez aç.)*/
														
	cout<<sizeof(Employee)<<endl;						//Employee class'ı 
	cout<<sizeof(employee)<<endl;						//Pointer
	cout<<sizeof(*employee)<<endl;						//Pointer'ın gösterdiği obje
	
	employee->setAge(5);								//Objemiz bir pointer olduğu için -> işareti ile çağırmamız gerekiyor.		
	cout<<employee->getAge()<<endl;
	return 0;
}

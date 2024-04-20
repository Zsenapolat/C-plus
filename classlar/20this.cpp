#include <iostream>

using namespace std;

class Student{	
	public:
		string name;
		int age;
		
		Student(string name, int age){
			
			cout<<"this memory address: "<<this<<endl;			//Buradaki this pointer'ı student1 objesinin adresine eşit.
			this->name=name;
			this->age=age;
			report(this);										//Objenin kendisini bu fonksiyona atayacağımız için this yazmamız gerekiyor.
		}
		
		void report(Student* student){							//this bir pointer olduğu için parametre de pointer olmak zorunda.
			cout<<student->name<<" "<<student->age<<endl;
		}

};
int main(){
	
	Student student1("sena",21);									
	
	cout<<"student1's memory address: "<<&student1<<endl;
	return 0;
}

#include <iostream>

using namespace std;

class Student{
	public:
		string name;
		
		Student(string name): name(name){}
		
		void print(){
			cout<< "name: "<<name<<endl;
		}
};

class MedStudent : public Student{
	public:
		string speciality;
												//Student base class olduğu için constructor'ını kullanabiliriz.
		MedStudent(string name, string speciality) : Student(name), speciality(speciality){}
		
		void print(){
			cout<<"name: "<<name<<" speciality: "<<speciality<<endl;
		}
		
};
int main(){
	Student *students[]={		//Print fonksiyonu artık virtual olduğu için hangi durumda hangi print fonksiyonunun kullanılacağına dinamik olarak
								//karar verilir. 
	new Student("sena"),
	new MedStudent("taha", "neurology")
	};
	for(int i=0 ; i<2 ; i++){
		students[i]->print();
	}
	
	for(int j=0 ; j<2 ; j++){
		delete students[j] ;
	}
	return 0;
}

// Compile time polymorphism : Program compile edilirken neyin neyi çalıştıracağına karar verilir. 
// Run time polymorphism : Program çalışırken hangi fonksiyonun kullanılacağına karar verilir.
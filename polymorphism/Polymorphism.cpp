#include <iostream>

using namespace std;

class Student{
	public:
		string name;
		
		Student(string name): name(name){}
		
		virtual void print(){
			cout<< "name: "<<name<<endl;
		}
};

class MedStudent : public Student{
	public:
		string speciality;
												//Student base class olduðu için constructor'ýný kullanabiliriz.
		MedStudent(string name, string speciality) : Student(name), speciality(speciality){}
		
		void print(){
			cout<<"name: "<<name<<" speciality: "<<speciality<<endl;
		}
		
};
int main(){
	Student *students[]={
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

#include <iostream>
#include <string>

using namespace std;
					//Destructor'lar objemiz silinirken otomatik olarak çağırılırlar. Eğer delete yazmazsak program kapanana kadar silinmeyecektir.
class Employee{
	public:
		Employee(){
			cout<<"Constructor cagirildi."<<endl;
		}
		
		~Employee(){		//Destructor yazımı. Destructor parametre almaz. Bu yüzden de overload edilemez.
			cout<<"Destructor cagirildi."<<endl;
		}
};

void Print(){	//Burada heap'te oluşturmak yerine stack içerisinde oluşturduk. Normalde delete diyene kadar silinmemesi gerek. Fakat bu obje local 
				//variable olduğu için fonksiyon bittiğinde otomatik olarak silinecektir. Bu yüzden fonskiyon bittiğinde destructor çağırılır.
	Employee employee1;	
}

int main(){

	Print();

	Employee* employee2 = new Employee();
	
	delete employee2;		//Yazarak oluşturulan objeyi silebiliriz. Bu şekilde destructor da devreye girmiş olur.
							//Fakat burada employee pointer'ını silmedik. Bu pointer'ın gösterdiği adresteki objeyi sildik. Pointer hala o adresi 
							//göstermeye devam ediyor.
								
	return 0;
}

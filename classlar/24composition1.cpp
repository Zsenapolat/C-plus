#include <iostream>

using namespace std;

class Engine{
	protected:
		int a;
	public:
		void runE(){
			cout<<"Engine started"<<endl;
}
};

class Car : public Engine{
	public:	
		a=2;
		void runC(){
			runE();
			cout<<"Car started"<<endl;
		}
		

};

int main(){
	Car myCar;
	myCar.runC();
	return 0;
}

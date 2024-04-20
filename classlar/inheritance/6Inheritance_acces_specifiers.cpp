#include <iostream>

using namespace std;

class BaseClass{
	private:
		int private_member;
	protected:
		int protected_member;
	public:
		int public_member;	
};

class DerivedClass1 : public BaseClass{		//Public yaptığımızda private dışındakilere erişimi vardır.
	public:
		void function1(){
			//private_member=0;
			protected_member=0;
			public_member=0;
		}
};

class DerivedClass2 : protected BaseClass{
	public:
		void function2(){
			//private_member=2;
			protected_member=2;
			public_member=2;
			
		}
};

class DerivedClass3 : private BaseClass{
	public:
		void function3(){
			//private_member=4;
			protected_member=4;
			public_member=4;
		}
};

class NextLevel1 : public DerivedClass2{	//Protected olarak Derive edilen class'tan derive edilen class baseclass'ın public dışında hiçbir 
	public:									//member'ına ulaşamaz.
		void function4(){
			//private_member=6;
			//protected_member=6;
			public_member=6;
		}
};

class NextLevel2 : public DerivedClass3{	//Private olarak Derive edilmiş class'tan derive edilmiş class base class'ın hiçbir member'ına ulaşamaz.
	public:
		void function5(){
			//private_member=6;
			//protected_member=6;
			//public_member=6;
		}
};
int main(){
	DerivedClass1 derived1;					//Public yaptığımzda dışardan private ve protected member'lara erişemeyiz.
	//derived1.private_member=1;
	//derived1.protected_member=1;
	derived1.public_member=1;
	
	DerivedClass2 derived2;					//Protected yaptığımızda base class'ın public member'ına da erişemeyiz.
	//derived2.private_member=3;
	//derived2.protected_member=3;
	//derived2.public_member=3;
	
	DerivedClass3 derived3;
	//derived3.private_member=5;
	//derived3.protected_member=5;
	//derived3.public_member=5;
	return 0;
}

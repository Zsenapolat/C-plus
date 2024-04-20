#include <iostream>

using namespace std;

class BaseClass{				//Derived class'ı public olarak tanımlarsak içindeki private elemana bir sonraki derived class erişemez.
	private:					//Protected ve public elemanna erişebilir. Bir sonraki derived class'lar da erişebilir.
		int private_member;		//Derived class protected olarak tanımlanırsa base class'ının protected ve public elemanlarına erişebilir.
	protected:					//Bu class'tan türeyen derived class'lar ise bu class'ın sadece public elemanlarına erişebilir.
		int protected_member;	//Derived class private olarak tanımlanırsa base class'ının protected ve public elemanlarına erişebilir.
	public:						//Bu class'tan türeyen derived class'lar ise bu class'ın hiçbir elemanına erişemez.
		int public_member;	
};

class DerivedClass1 : public BaseClass{		//Public yapt���m�zda private d���ndakilere eri�imi vard�r.
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

class NextLevel1 : public DerivedClass2{	//Protected olarak Derive edilen class'tan derive edilen class baseclass'�n public d���nda hi�bir member'�na ula�amaz.
	public:
		void function4(){
			//private_member=6;
			//protected_member=6;
			public_member=6;
		}
};

class NextLevel2 : public DerivedClass3{	//Private olarak Derive edilmi� class'tan derive edilmi� class base class'�n hi�bir member'�na ula�amaz.
	public:
		void function5(){
			//private_member=6;
			//protected_member=6;
			//public_member=6;
		}
};
int main(){
	DerivedClass1 derived1;					//Public yapt���mzda d��ardan private ve protected member'lara eri�emeyiz.
	//derived1.private_member=1;
	//derived1.protected_member=1;
	derived1.public_member=1;
	
	DerivedClass2 derived2;					//Protected yapt���m�zda base class'�n public member'�na da eri�emeyiz.
	//derived2.private_member=3;
	//derived2.protected_member=3;
	//derived2.public_member=3;
	
	DerivedClass3 derived3;
	//derived3.private_member=5;
	//derived3.protected_member=5;
	//derived3.public_member=5;
	return 0;
}

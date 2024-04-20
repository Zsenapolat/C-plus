#include <iostream>

using namespace std;

class BaseClass{
	public:
		int public_member;
	private:
		int private_member;				//private member'lara derived class dahil hiçbir yerden ulaşılamaz.
	protected:
		int protected_member;			//protected member'lara ise derived class erişebilir ama programın geri kalanı erişemez.
};

class DerivedClass : public BaseClass {
	public:
		void member_function(){
			public_member=0; 	
			protected_member=5;			//Fakat sadece class içerisinden erişilebilir. Aynı private member'lar gibi.
				
			cout<<"public_member: "<<public_member<<endl;
			cout<<"protected_member: "<<protected_member<<endl;
		}
};

class AnotherClass : public DerivedClass{	//Aynı şekilde derived class'tan derive edilmiş class'lar da protected class'lara erişebilir.
	public:
		void member_function(){
			public_member=3; 	
			protected_member=6;								
				
			cout<<"public_member: "<<public_member<<endl;
			cout<<"protected_member: "<<protected_member<<endl;
		}
};
int main(){
	DerivedClass derived;
	derived.member_function();
	
	AnotherClass anotherderived;
	anotherderived.member_function();
	return 0;
}

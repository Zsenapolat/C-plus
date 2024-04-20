#include <iostream>

using namespace std;

class CommonBaseClass{
	public:
		int common_value;
		int m;
		CommonBaseClass(){
			cout<<"CommonBaseClass default"<<endl;
			common_value=10;
		}
		CommonBaseClass(int common_val){
			cout<<"CommonBaseClass param"<<endl;
			common_value=common_val;
			cout<<common_val<<endl;
		}
};
class BaseClass1 :public virtual CommonBaseClass{
	public:
		int base1_value;
		
		BaseClass1():CommonBaseClass(80){
			cout<<"BaseClass1 default"<<endl;
		}
		BaseClass1(int base1_val){
			cout<<"BaseClass1 param"<<endl;
			base1_value=base1_val;
			cout<<base1_val<<endl;
		}
};
class BaseClass2 : public virtual CommonBaseClass{
	public:
		int base2_value;
		
		BaseClass2():CommonBaseClass(15){
			cout<<"BaseClass2 default"<<endl;
		}
		BaseClass2(int base2_val){
			cout<<"BaseClass2 param"<<endl;
			base2_value=base2_val;
			cout<<base2_val<<endl;
		}
};
class DerivedClass:public BaseClass1, public BaseClass2{
	public:
		int derived_value;
		
		DerivedClass(){								//Constructor tercihi yapmak istediğimizde class1():class2()
			cout<<"DerivedClass default"<<endl;
			BaseClass2::CommonBaseClass();			//DerivedClass'ın default constructor'u çağrıldığında commonbaseclass'ın default'u da 
		}											//tekrar çağrılır.
		DerivedClass(int derived_val){		
			cout<<"DerivedClass param"<<endl;
			derived_value=derived_val;
			cout<<derived_val<<endl;
		}
};
int main(){
	DerivedClass derivedclass1;		//Default constructor'ını kullanmak için baseclasslarının constructor'larını kullandı. Onlar da 
									//commonbase'inkini kullandı. Commonbase'in default'u common_value'yu 10 olarak ayarladı. Diğerleri de 
									//kendi default constructor'larıyla bu değeri değiştirmeye çalıştı. Ancak geçerli olan commonclass'ınkidir.  
									//Ama virtual olarak yazdığımızda tekrardan commonclass'a uğramaz.
											
	DerivedClass derivedclass2(5);
	
	derivedclass1.common_value=6;	//Bu şekilde çağırdığımızda hangi base class'tan commonbaseclass'a gideceğini bilemediği i�in hata verir. Bunu 
									//önlemek için base class'lara commonbaseclass'ı virtual olarak ekleriz.
										
	derivedclass1.m=3;		//Burada bütün class'larımızda m değişkeni var. Fakat derived class içerisinde bunu override ettiğimiz için derived
							//üzerinden işlem yapar. Eğer derived'da olmasaydı diğerlerinin hepsinde olsaydı hata verirdi. Belirtmemiz gerekirdi.
							//Eğer hiçbirinde yoksa sadece commonbaseclass içinde varsa onu değiştirirdi.
	
	derivedclass1.BaseClass1::m=4;	//Bu şekilde ayarlayabiliriz.		Bir class'ın değerini değiştirmek için class1.class2::m=?
	
	
	return 0;
}

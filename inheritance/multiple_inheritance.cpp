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
		
		DerivedClass(){										//Constructor tercihi yapmak istediðimizde class1():class2()
			cout<<"DerivedClass default"<<endl;
			BaseClass2::CommonBaseClass();					//DerivedClass'ýn default constructor'u çaðrýldýðýnda commonbaseclass'ýn default'u da tekrar çaðrýlýr.
		}
		DerivedClass(int derived_val){		
			cout<<"DerivedClass param"<<endl;
			derived_value=derived_val;
			cout<<derived_val<<endl;
		}
};
int main(){
	DerivedClass derivedclass1;			//Kendi default constructor'ýný kullanmak için baseclasslarýnýn constructor'larýný kullandý. Onlar da commonbase'inkini
										//kullandý. Commonbase'in default'u common_value'yu 10 olarak ayarladý. Diðerleri de kendi default constructor'larýyla
										//bu deðeri deðiþtirmeye çalýþtý. Ancak geçerli olan commonclass'ýnkidir.  
										//Ama virtual olarak yazdýðýmýzda tekrardan commonclass'a uðramaz.
											
	DerivedClass derivedclass2(5);
	
	derivedclass1.common_value=6;		//Bu þekilde çaðýrdýðýmýzda hangi base class'tan commonbaseclass'a gideceðini bilemediði için hata verir. Bunu 
										//önlemek için base class'lara commonbaseclass'ý virtual olarak ekleriz.
											
	derivedclass1.m=3;					//Burada bütün class'larýmýzda m deðiþkeni var. Fakat derived class içerisinde bunu override ettiðimiz için derived
										//üzerinden iþlem yapar. Eðer derived'da olmasaydý diðerlerinin hepsinde olsaydý hata verirdi. Belirtmemiz gerekirdi.
										//Eðer hiçbirinde yoksa sadece commonbaseclass içinde varsa onu deðiþtirirdi.
	
	derivedclass1.BaseClass1::m=4;		//Bu þekilde ayarlayabiliriz.		Bir class'ýn deðerini deðiþtirmek için class1.class2::m=?
	
	
	return 0;
}

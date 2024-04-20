#include <iostream>
#include <string>

using namespace std;
								//new keyword'ünü bir şeyi heap'te depolamak istediğimizde kullanırız.
								//Yazım şekli new <type>
class Employee{
	public:
		Employee(){
			cout<<"Constructor cagirildi."<<endl;
		}
};


int main(){
	new int;			//Burada heap içerisine bir integer'lık yer oluşturduk. Adresi belli fakat bir ismi yok. İçerisinde bir değer de yok.
	int* p = new int;	//Burada ise aynı işlemi bu ayrılan alanı gösteren bir pointer kullanarak yaptık. İçerisinde hala bir değer yok.
						//Bu şekilde istediğimizde pointer yardımı ile ayırdığımız alanın adresini öğrenebiliriz. Aynı zamanda değer atayabiliriz.
						//Pointer p heap içerisinde bulunmaz. Stack içerisinde bulunur ve heap içerisine oluşturduğumuz değişkenin adresini taşır.
	*p = 3;				//Ayırdığımız alanın içerisindeki değer artık 3.
	p = new int(10);	//Aynı işlemi bu şekilde daha kısa yazabiliriz.(Yukarda tanımladığımız için aynı pointer'a başka bir adres atayabiliriz.)
						//Pointer'a farklı bir adres atadığımızda bir önceki adrese artık ulaşamayız. Bu yüzden o adres artık garbage olmuştur.
						//Bu istemediğimiz bir durumdur.
	
	int* r = new int(5);	//Bu sefer pointer'a yeni bir adres atamadan önce bir önceki adresteki değeri sildik. 
	delete r;				//Bu şekilde garbage value'dan kurtulduk.	
	r = new int(10);
	
	int a;			//Burada oluşturduğumuz pointer'da da aynı olay geçerlidir. Fakat burada new keyword'ünü kullanmadığımız için pointer'ı da 
	int *t=&a;		//değişkeni de heap yerine stack'te depolayacaktır.
	
	Employee* employee = new Employee();	//employee adında bir pointer oluşturduk ve heap içerisinde oluşturulan bir Employee class'ının
	return 0;								//adresini taşıyor.
}

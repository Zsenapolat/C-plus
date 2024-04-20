#include <iostream>
#include <string>
using namespace std;
						//Bir değişkeni static yaptığımızda özellik objelere özgü değil class'a özgü olur.
						//Normalde global variable bir dosyamızın içerisindeyse diğer dosyalara extern int var; şeklinde aktarabiliriz. Fakat 
						//Eğer bu global variable static ise sadece bu dosyada kullanılabilir.
						//Static olarak yazmak yerine direkt global variable olarak da yazabiliriz. int total=0; Fakat aşağıdaki gibi 
						//tanımladığımızda class ile alakalı olduğunu belirtmiş oluruz. Sadece class işlemleri için kullanırız. 
						//Static fonksiyonlar da static değişkenlere erişmek için kullanılır. Normal class fonksiyonları 
						//static değişkene ulaşabilir.
class Animals{
	public:
	string species;
	static int total;			//Class'a ait olduğunu belirtmek için class içerisinde başlatılır. 
	
	Animals(string species):species(species){
		total++;
	}
	static int count(){		//Tanımlandıktan sonra class içindeki herhangi bir fonksiyon tarafından kullanılabilir. Her kullanıldığında yani yeni 
		return total;		//obje üretildiğinde değeri değişecektir. Static olduğu için private static değişkene erişebilir.
	}						//Static bir function class değişkenlerine ulaşamaz. Aynı zamanda this-> pointer'ını da kullanamazlar.
	~Animals(){
		total--;
	}						
};

int Animals::total = 0;			//Dışarda başlatılmak zorundadır. İçerde başlatılamaz.
//myCircle::pi şeklinde yazarsak otomatik olarak 0 değerini verecektir.
int dene(){
	
	static int gVar = 0 ; //Fonksiyon çağırıldığında sabit kalacaktır. Örneğin bu fonksiyonu iki kere çağırırsak sayı son çağrıda 2 olacaktır.
		int u = ++gVar;   //u burada static olmaz. Sadece gVar'ın değerini alır. 
		return u; 					
	}
int main(){
	
	
	cout<<dene()<<endl;   //1
	cout<<dene()<<endl;   //2
	
	Animals* lion = new Animals("lion");
	cout<<"Total: "<<Animals::total <<endl;
	
	Animals* tiger = new Animals("tiger");
	cout<<"Total: "<<Animals::total <<endl;
	
	Animals* bear = new Animals("bear");
	cout<<"Total: "<<Animals::total <<endl;
	
	delete lion;
	cout<<"Total: "<<Animals::total <<endl;
	
	delete tiger;
	cout<<"Total: "<<Animals::total <<endl;
	cout<<"Total: "<<Animals::count()<<endl; 	//Static member function olarak da çağrılabilir. Ayrıca bir obje oluşturmadan da çalışabilir.
	return 0;
}

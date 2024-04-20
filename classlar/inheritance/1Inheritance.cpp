#include <iostream>

using namespace std;
						//Kod tekrarını önlemek için kullanılır.
						
class MenuItem{				//Aynı zamanda içecekler için de bir class oluşturmamız gerekiyor. Bu yüzden de bu class'ı kopyalayacağız.
	public:
		string name;
		double calories;
		
		void print(){
			cout<<"Name: "<<name<<endl;
			cout<<"Calories: "<<calories<<endl;
		}
};
									//Drinks class inherit from MenuItem class. 
class Drinks: public MenuItem		//MenuItem burada base(parent) class olmuş olur. Drinks class ise derived(child) class olur. 
									//Member function'lar ve member variable'lar inherit edilir. Bu yüzden bunu yazdığımğızda MenuItem'da da 
{									//bulunan elemanları sil.

		public:				//Bu class menuitem class'ının çoğu elemanını içinde barındırıyor. Bu yüzden çok fazla kod tekrarı oluyor.(Code Clone)			
							//Örnek olarak bir class içindeki bir kısmı değiştirmek istiyoruz. Bunu diğer class'larda da değiştirmemiz gerekiyor.									//Bu durumu ��zmek i�inse inheritance kullan�yoruz.
		double ounces;
		double cal_per_ounce(){		
			return calories/ounces;
		}
};

int main(){
	MenuItem french_fries;					
	french_fries.name="french_fries";	
	french_fries.calories=400;
	
	french_fries.print();
	
	Drinks hot_chocolate;
	hot_chocolate.name="hot chocolate";
	hot_chocolate.calories=300;
	hot_chocolate.ounces=8;
	
	cout<<"Calories per ounce: "<<hot_chocolate.cal_per_ounce()<<endl;
	
	MenuItem *ptr;					//Normalde sadece MenuItem class'ına ait olan objeleri gösterebilir.
	ptr=&hot_chocolate;				//Fakat burada drinks class'ına ait bir objeyi gösteriyor. 
	
	ptr->print();
	return 0;
}

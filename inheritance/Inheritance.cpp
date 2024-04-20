#include <iostream>

using namespace std;
						//Kod tekrarýný önlemek için kullanýlýr.
						
class MenuItem{					//Ayný zamanda içecekler için de bir class oluþturmamýz gerekiyor. Bu yüzden de bu class'ý kopyalayacaðýz.
	public:
		string name;
		double calories;
		
		void print(){
			cout<<"Name: "<<name<<endl;
			cout<<"Calories: "<<calories<<endl;
		}
};
									//Drinks class inherit from MenuItem class. 
class Drinks: public MenuItem		//MenuItem burada base(parent) class olmuþ olur. Drinks class ise derived(child) class olur. 
									//Member function'lar ve member variable'lar inherit edilir. Bu yüzden bunu yazdýðýmýzda MenuItem'da da bulunan elemanlarý sil.
{						
		public:						//Bu class menuitem class'ýnýn çoðu elemanýný içinde barýndýrýyor. Bu yüzden çok fazla kod tekrarý olmuþ oluyor.(Code Clone)			
									//Örnek olarak bir class'ýn içindeki bir kýsmý deðiþtirmek istiyoruz. Bunu diðer class'larda da deðiþtirmemiz gerekiyor.									//Bu durumu çözmek içinse inheritance kullanýyoruz.
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
	
	MenuItem *ptr;					//Normalde sadece MenuItem class'ýna ait olan objeleri gösterebilir.
	ptr=&hot_chocolate;				//Fakat burada drinks class'ýna ait bir objeyi gösteriyor. 
	
	ptr->print();
	return 0;
}

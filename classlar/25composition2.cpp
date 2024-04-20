#include <iostream>
#include <string>

using namespace std;

class Food{
	private:
		string name;
		int porsion;
	public:
		void setFoodName(string name){
			this->name=name;
			}
		
		void setFoodPorsion(int porsion){
			this->porsion=porsion;
		}
		
		string getFoodName(){
			return name;
		}
		
		int getFoodPorsion(){
			return porsion;
		}
};
class Drink{
	private:
		string name;
	public:
		void setDrinkName(string name){
			this->name=name;
		}
		
		string getDrinkName(){
			return name;
		}
		
};
class Menu{
	friend void showInfos(Menu& menu);
	private:
		string name;
		Drink drink;						//Kod tekrarı olmasın diye bu şekilde yazılabilir.
		Food food;
	public:
		Menu(string name, string foodName , string drinkName, int porsion){
			this->name=name;
			food.setFoodName(foodName);
			food.setFoodPorsion(porsion);
			drink.setDrinkName(drinkName);
		}		
};

void showInfos(Menu& menu){					//Bir fonksiyonun başka class'larda da kullanılabilir olmasını istiyorsak friend fonksiyon olarak 
	cout<<menu.name<<": "<<endl;			//yazabiliriz. Eğer fonksiyon içerisinde bir değiştirme yapılmayacaksa referans olarak almamıza gerek yoktur. 
	cout<<"Your orders are: "<<endl;		//Fakat bellek içerisinde gereksiz yer harcamamıza neden olur. O yüzden bir fonksiyon parametre 
	cout<<menu.drink.getDrinkName()<<endl;	//olarak obje alıyorsa referans olarak alınması daha doğrudur.
	cout<<menu.food.getFoodName()<<endl;
	cout<<menu.food.getFoodPorsion()<<endl;	
}
int main(){
	Menu sena_menu("sena", "fries", "cola", 1);
	Menu ela_menu("ela", "chicken", "sprite", 2);
	
	sena_menu = ela_menu;
	
	showInfos(sena_menu);
	return 0;
}

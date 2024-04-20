#include <iostream>
#include <string>

using namespace std;

class Rectangle{
	private:
		int length;
		int width;
		
		int area();							//Private member function'lara direkt olarak ulanamayız. Information Hiding için kullanılır.
	
	public:
		void setDimensions(int l, int w){	//Setter'lar main fonksiyondan alınan object değerlerini class değerlerine eşitlemek için kullanılır.
			length=l;						//Herhangi bir değer döndürmezler. Member functionların parametreleri sadece onlara özeldir.
			width=w;
		}
		
		int perimeter();
		
		int getArea(){			//Getter metodları private değişkenlerin değerlerini class dışına aktarmamızı sağlar. Parametre almazlar.
			cout<<area()<<endl;
		}					
};

int Rectangle::perimeter(){						//Fonksiyonu class içinde başlatıp, class dışında tanımlayabiliriz.
	return (length+width)*2;
}

int Rectangle::area(){
	return length*width;

}
int main(){
	Rectangle rectangle1;
	
	rectangle1.setDimensions(2,4);

	
	cout<<rectangle1.perimeter()<<endl;
	
	rectangle1.getArea();
	
	return 0;
}

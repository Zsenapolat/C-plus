#include <iostream>
#include <string>

using namespace std;			/*
								Class fonksiyonları class içerisinde oluşturulan bir değişkene ulaşabilir.  
								 */
class Kare{	
	private:					//Access Specifier
		int num=3;
		
	public:
		
		int alanHesapla(){
			int alan=num*num;	//Burada hata almayız.
			return alan;
		}
		int cevreHesapla(){
			int cevre=num*4;
			return cevre;
		}
		int degistir(){
			num++;
			return num;
		}
	
};

int main(){
	Kare kare;
	cout<<"Alan: "<<kare.alanHesapla()<<endl;
	cout<<"Cevre: "<<kare.cevreHesapla()<<endl;
	
	cout<<"Yeni deger: "<<kare.degistir()<<endl;	//Private değişkenin değerini değiştirmek için fonksiyonu çağırmalıyız. 
													//kare.num ile erişemeyiz.
	return 0;
}

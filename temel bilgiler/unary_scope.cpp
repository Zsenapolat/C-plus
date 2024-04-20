#include <iostream>
#include <string>

using namespace std;		//Bunu kullanmak yerine her satýrýn baþýna std:: yazabiliriz.
							//Global variable'lar fonksiyon dýþýnda tanýmlanýr ve program içindeki bütün fonksiyonlar tarafýndan eriþilebilir.
							//Local variable'lar fonksiyon içinde tanýmlanýr ve sadece o fonksiyon içinde kullanýlabilir.
				
int x=2; 					//Global variable
int main(){
	int x=4;				//Local variable
	
	cout<<x<<endl;			//Burada 4 çýktýsýný alýrýz. Çünkü local variable'ýn önceliði vardýr. Eðer global variable çýktýsý almak istiyorsak;
	cout<<::x<<endl;		//Yazmalýyýz.
	return 0;
}

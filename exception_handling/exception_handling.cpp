#include <iostream>

using namespace std;
									//Hatalar sýnýflar tarafýndan temsil edilir. Hata açýsýndan izlemek istediðimiz kodlarý try bloðuna yazmalýyýz. 
									//Try bloðu içerisinde bir hata oluþursa bu hata fýrlatýlýr. Fýrlatýlan hatayý catch bloðu yakalar.
int main () {
	try {
		int a,b;					//Mesela 2 ve 1 girersek catch bloðuna uðramayacak. 2/1 = 2 yazdýracak ve kod satýrýna devam edecek.
									//Eðer 2 ve 0 girersek catch bloðuna 2 deðerini gönderecek ve buna uygun çýktý verecek. Ardýndan kod satýrýna devam edecek.
		cin >>a >>b;

		if ( b==0) throw(2);		//Eðer b'ye 0 deðerini girersek program catch bloðuna atlayacak. cout'u yazdýrmayacak.
		cout << a/b << endl;
		
	} catch (int t){ 
		cout << "Exception=" << t << endl;
	}

	cout << "After try-catch" << endl;
	
	int divErr=2;
	try {
	    int c,d;
	    cin >>c >>d;
	    if ( c==100) throw('A'); 
	    if ( c==1000) throw(3.4); 
	    if ( d==0) throw(divErr); 
	    cout << c/d << endl;
	} catch (int t){
		cout << "Exception=" << t << endl;
	} catch (char t){
		cout << "A=100" << endl;
	} catch (double t){
		cout << "A=1000" << endl;
	}catch (...) { 								//else gibi düþünebiliriz.
		cout << "General Exception" << endl;
	}

	cout << "After try-catch" << endl;
}




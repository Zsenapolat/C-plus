#include <iostream>

using namespace std;
//Ýki türü vardýr. By Value ve By reference.

void test1(int a, int b){	//Pass by value. Burada a ve b diye iki tane deðiþken oluþturduk ve fonksiyon çaðrýldýðýnda c ve d deðiþkenlerini kopyalayacaklar.
	a = a+b;
	cout<<a<<" "<<b<<endl;
}

void test2(int *a, int b){	//Pass by value (pointers 1). a deðiþkenimiz bir pointer. b deðiþkenimiz ise normal deðiþken. Ýkisi de local variablelar. 
	int y=7;				//y diye bir local variable oluþturduk ve buna 7 deðerini verdik.
	a=&y; 					//a pointer'ýmýz y'nin adresini gösteriyor. Artýk *a=7 olmuþ oldu.                         
}


void test3(int *a, int b){	//Pass by value (pointers 2)
	int y=7;				
	*a=y; 					//y local variable'ýný a pointer'ýnýn deðerine eþitledik. a'nýn gösterdiði adres s deðiþkeninin adresiydi. Bu yüzden s deðiþkeninin
}							//deðeri deðiþmiþ oldu. Fonksiyon bittikten sonra a pointer'ý ve y deðiþkeni silinir.



void test4(int &a, int b){	//Pass by reference. a parametresi bir referans alýyor.
	int y=7;				
	a=y; 					//Fonksiyon bittiðinde a, b ve y deðiþkenleri silinir.
}


int main() {

	int a=4;
	int b=6;
	test1(a,b);						//a ve b, c ve d deðiþkenlerini kopyaladý ve fonksiyon çaðrýldýðýnda a ve b için iþlem yapýldý. Bunlar local variable'lar
									//olduðu için fonksiyon çaðrýldýktan sonra bellekten silinirler. Herhangi bir yer de iþgal etmezler.
	cout << a << " " << b << endl; 	//Tekrar c ve d'yi yazdýrmak istediðimizde kendileri silinmediði ve deðiþtirilmediði için kendi deðerleriyle yazdýrýlýrlar.

	int x=4;
	int y=6;
	test2(&x,y);					//x deðiþkeninin adresini a pointer'ýna atadýk. a pointer'ý x'in adresini gösteriyor. Ama fonksiyon çaðrýldýðýnda artýk x'in
	cout << x << " " << y << endl; 	//adresini deðil y'nin adresini gösteriyor. Bu yüzden herhangi bir deðiþiklik yapýlmadan a pointer'ý da y deðiþkeni de 
									//siliniyor. x ve y'nin deðerlerinde herhangi bir deðiþiklik olmaz.
	int s=4;
	int t=6;
	test3(&s,t);					//s'in adresini a pointer'ýna gönderdik. 
	
	cout << s << " " << t << endl; 	//s deðiþkeninin deðeri deðiþti. s=7, t=6
	
	int e=4;						
	int f=6;

	test4(e,f);						//a parametresi bir referans olduðu için e deðiþkeniyle ayný deðer ve adrese sahip. a parametresinde yapýlan deðiþiklikler
	cout << e << " " << f << endl; 	//e deðiþkeninde de yapýlacaktýr. En kullanýþlý yol budur. Çünkü bellekte herhangi yeni bir deðiþken oluþturmuyoruz.


	return 0;
}


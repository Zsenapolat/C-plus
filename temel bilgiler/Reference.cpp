#include <iostream>

using namespace std;

int main(){
	int a = 5;
	cout<<"a'nýn adresi: "<<&a<<endl;
	cout<<"a'nýn deðeri: "<<a<<endl;
	
	int* ptr;	
	ptr=&a;
	cout<<"ptr'nin yeni adresi: "<<ptr<<endl;
	cout<<"ptr'nin yeni deðeri: "<<*ptr<<endl;
	
	int& ref = a;
	cout<<"ref'in adresi: "<<&ref<<endl;				//Referans'ýn adresi artýk a'dýr. Yani a ve ref aslýnda ayný deðiþkendir. Ýki isimle de çaðrýlabilirler.
	cout<<"ref'in deðeri: "<<ref<<endl;
	return 0;
}

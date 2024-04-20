#include <iostream>
#include <string>

using namespace std;

int main(){
	int *ptr;
	int a=5;
	ptr=&a;
	
	cout<<&ptr<<endl;			//Pointer'ýmýzýn bulunduðu adres.
	cout<<ptr<<endl;			//Pointer'ýmýzýn gösterdiði adres.
	cout<<&a<<endl;				//Pointer'ýmýzýn gösterdiði adres yani a deðiþkeninin adresi.
	return 0;
}

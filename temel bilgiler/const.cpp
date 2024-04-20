#include <iostream>
#include <string>

using namespace std;
					//Const anahtar kelimesi kullanýlarak tanýmlanan bir deðiþkenin ya da array'in herhangi bir elemanýnýn deðerini daha sonradan deðiþtiremeyiz.
void printArray(const int *ptr1,const int *ptr2){	//Array'imizin elemanlarýný const yaptýk.
													//*(ptr1+1)=2; yazamayýz. Çünkü buradaki parametre yazýmýnda array'imizin sadece 2. ve 5. elemanýný deðil,
													//bütün elemanlarýný const yapmýþ olduk.
	for(;ptr1!=ptr2;ptr1++){	
		cout<<*ptr1<<endl;							//Bu þekilde hata almayýz. Çünkü const bir pointer tanýmladýðýmýzda sadece gösterdiði adresteki deðer deðiþemez.
													//Pointer'ýn gösterdiði adres deðiþebilir.
	}
} 
int main(){
	int x;
	int *p1=&x;				//Daha sonradan pointer'ýn gösterdiði adres de, içindeki deðer de deðiþtirilebilir.
	const int *p2=&x;		//Daha sonradan pointer'ýn gösterdiði adres deðiþtirilebilir ama içindeki deðer deðiþtirilemez.
	int *const p3=&x;		//Daha sonradan pointer'ýn gösterdiði adres deðiþtirilemez ama içindeki deðer deðiþtirilebilir.
	const int *const p4=&x;	//Daha sonradan pointer'ýn gösterdiði adres de, içindeki deðer de deðiþtirilemez.
	
	
	int array[]={1,2,3,4,5};	
	printArray(array+1,array+4);
	array[2]=5;				//Burada array'in elemanýný deðiþtirebiliriz. Çünkü sadece fonksiyon içerisinde elemanlarý const yaptýk.				
	return 0;
}

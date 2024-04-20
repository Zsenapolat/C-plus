#include <iostream>
#include <string>

using namespace std;
						/*
						TANIMLAMA ÞEKÝLLERÝ
						1) int ary[10];  
						2) int ary[5]={1,2,3,4,5};
						3) int ary[]={1,2,3,4,5};
						4) int matris[2][3]={{1,2,3},{4,5,6}};   //Ýlk kýsým satýr, son kýsým sütun olarak düþünülebilir.
						
						Array boyutundan fazla deðer giremezsin ama eksik deðer girebilirsin.
						*/
						
void printArray(int *p, int size){		//Pointer parametreye bir array atarsak pointer o array'in yerini alýr.
	for (int i=0; i<size; i++){
		cout << i << "indexindeki deger: "<< *(p+i)<< endl;
	} 
}



void printArry(int array[], int size){	//Burada parametre olarak tanýmladýðýmýz array'in içine boyut deðerini girmemize gerek yok. (array[]=a) 
										//a array'i ile parametre olan array'in adresini eþitledik. Fonksiyonun içerisinde de bu deðerleri sýrasýyla giriyoruz. 
	for (int i=0; i<size; i++){
		cout << i << "indexindeki deger: "<< array[i] <<endl; //ya da *(array+i);
	}
}



int main(){
	int array[]={1,2,3,4,5};
	
	cout<<array[5]<<endl; //Garbage deðer alýrýz çünkü array içerisinde tanýmlanmayan bir index deðeri girdik.
	int ar[3]={1,2};	  //Eksik eleman girebiliriz. 3. eleman için bellekte yer ayrýlmýþ olur.
	
	cout << array <<endl; //Array'in baþlangýç adresi çýktýmýz olur. Burada array pointer deðil, baþlangýç adresini taþýyan bir deðiþkendir.
	cout << array+1 <<endl; //Bir sonraki elemanýn adresi çýktýmýz olur.
	
	int a[]={1,2,3,4,5};   //Bu array'in deðerlerini sýrasý ile ekrana yazdýrmak istersek üstte tanýmlanan gibi iki fonksiyon yazabiliriz.
	printArray(a,5);
	printArry(a,5);
	
	int c=3;
	int *ptr=&c;

	cout<<ptr[0]<<endl;
	cout<<ptr[1]<<endl;		//Eðer pointer'ý bir array'in adresine eþitlemediysek ptr[0] yazýmýndan pointer'ý eþitlediðimiz deðiþkenin deðerini,
							//ptr[1],ptr[2] gibi yazýmlardan ise 1,2... çýktýlarýný alýrýz.
	
	int *d=&(c+1);			//Eðer c deðiþkeninin adresinden bir sonraki adrese bir deðer atamak istiyorsak (&c+1)=4; bu þekilde yazamayýz. 
	*d=4;					//Bu iþlemi bir pointer'la yapmamýz gerekir.
	
	cout<<ptr[1]<<endl;		//Burada ise pointer'ý array gibi kullanabiliriz. Çünkü bir sonraki elemana bir deðer atadýk. Bir önceki örnekte bu eleman boþtu.			
	
	return 0;
}

#include <iostream>
#include <string>

using namespace std;
								//Belleðimizde gereksiz yer iþgalini önlemek için kullanýrýz.
int main(){
	int age=10;
	
	cout<<sizeof(age)<<endl;	//Sizeof operatörü veri yapýmýzýn bellekte ne kadar yer kapladýðýný gösterir.
								
	int *ptr1= new int;			//Burada new anahtar kelimesiyle birlikte pointer'ýmýza göstermesi için bir integer'lýk yer ayýrmýþ olduk.
	*ptr1=5;
	
	cout<<ptr1<<endl;			
	cout<<&ptr1<<endl;
	
	delete ptr1;					//Eðer ptr'nin gösterdiði tüm alanlarý belleðe geri vermek istiyorsak delete anahtar kelimesini kullanýrýz.
	
	cout<<ptr1<<endl;			//Yukarda aslýnda pointer'ýmýzý silmedik. Sadece pointer'ýmýzýn gösterdiði adresi belleðe geri verdik.	
	cout<<&ptr1<<endl;			//Fakat pointer hala ayný adresi göstermeye devam eder. Bu adrese yeni bir deðer atayabiliriz.
	
	
	int *ptr2 = new int[5];		//Burada 5 integer'lýk yer ayýrmýþ olduk.
	
	for(int i=0;i<5;i++){
		cin>>ptr2[i];
	}
	
	for (int i=0;i<5;i++){
		cout<<ptr2[i]<<endl;
	}
	
	delete [] ptr2;				//Baþýna köþeli parantez koyduðumuzda ptr2 için ayrýlan bütün adresleri belleðe geri vermiþ oluruz.
	
		for (int i=0;i<5;i++){	//Tekrardan adreslerdeki deðerleri yazdýrmak istediðimizde garbage deðerler alýrýz.
		cout<<ptr2[i]<<endl;
	}
		
	int *ptr3 = new int[3];
	
	for(int i=0;i<3;i++){
		cin>>ptr3[i];
	}
	
	cout<<&(ptr3[2])<<endl;
	
	for (int i=0;i<3;i++){
		cout<<ptr3[i]<<endl;
	}
	
	delete ptr3;				//[] koymadýðýmýzda da ayný sonucu alýrýz. Ne olur ne olmaz parantez koy.
	
	for (int i=0;i<3;i++){
		cout<<ptr3[i]<<endl;
	}
	
	cout<<&(ptr3[2])<<endl;		//Pointer'ýn gösterdiði 3. elemanýn adresi deðiþmedi. Sadece deðeri deðiþti.
	return 0;
}

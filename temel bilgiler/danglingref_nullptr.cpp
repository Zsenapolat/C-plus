#include <iostream>
#include <string>

using namespace std;

int main(){
	int *r=NULL;	//Eðer pointer'ýmýzýn hiçbir adresi iþaret etmesini istemiyorsak null pointer olarak ayarlayabiliriz.
					//Bir pointer'ý bu þekilde baþlatmak çok daha güvenlidir. 
					
	cout << r << endl;	//Böyle yazdýðýmýzda 0 deðerini alýrýz.
					
	r=new int;		//Pointer'ýmýz için 1 integer'lýk yer ayýrýyoruz.
	*r=10;			//Bu yere 10 deðerini atýyoruz.
	
	delete r;		//Pointer'ýn gösterdiði adresi tekrardan belleðe verirsek pointer'ýmýz artýk bir "dangling pointer" olur. 
					//Yani belleðe ait olan bir yeri göstermiþ olur. Runtime hatasý alýrýz.
	
	cout<<*r;		
	return 0;
}

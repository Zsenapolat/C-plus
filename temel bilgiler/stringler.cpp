#include <iostream>
#include <string>

using namespace std;
							//NOT: cin komutunun sonuna endl yazamazsýn.
int main(){

	string str1;			//Getline komutu sayesinde bütün bir cümleyi kullanýcýdan alabiliriz. Bu komut sadece stringlerde kullanýlabilir.
	getline(cin,str1);
	cout << str1 <<endl;

	string str2;
	cin >> str2;			//Bu þekilde string' i almaya çalýþýrsak eðer string içerisinde boþluk içeriyorsa boþluktan sonrasýný almayacaktýr.
	cout << str2 <<endl;	
	
	string str3;			//Eðer getline'ý cin komutunu kullandýktan sonra kullanýrsak bir önceki cin komutunun girdisi ile birleþecektir.
	getline(cin,str3);		//Deðiþken farklý bir deðiþken olsa bile cin içinde kullanýlan cümlenin boþluktan öncesini yazdýrýp 
	cout << str3 <<endl;	//boþluktan sonrasýný da ardýndan yazdýracaktýr. 3. kere girdi almayacaktýr. 
	return 0;				//Bu hatanýn önüne geçebilmek için stringlerde cin komutu yerine getline komutunu kullan.
}


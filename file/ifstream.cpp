#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream outFile("file2.txt");		//file2 adýnda bir dosya oluþturduk ve içerisine aþaðýdaki deðerleri girdik.
	outFile << 3 <<endl;
	outFile << 4 <<endl;
	outFile << 5 <<endl;
	outFile << 6 <<endl;
	outFile << 7 <<endl;
	outFile.close();
	
	ifstream inFile("file2.txt");		//ifstream objesi oluþturuyoruz. Daha önceden varolan bir dosyayý okumak için kullanýlýr.				
	int x;								//Bir x deðiþkeni oluþturduk. Bu deðiþken sýrasýyla dosyadaki bütün integer'larýn deðerini alacak. Her seferinde
	while(!(inFile.eof())){				//ekrana yazdýracak. eof komutu sayesinde dosyanýn sonuna gelip gelmediðimizi öðrenebiliriz. Eðer geldiysek "true" döndürür.
		inFile >> x ;
		cout << x << endl;
	}
	/*
	string a;							//Eðer string alacaksak boþluklarý bitiþ olarak almamasý için getline komutunu kullanmamýz gerekir.
	getline(inFile,a);
	*/
	inFile.close();
	return 0;
}

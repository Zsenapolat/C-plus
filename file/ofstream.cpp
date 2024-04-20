#include <iostream>
#include <fstream> 				//ifstream ve ofstream'i kullanabilmek için ekliyoruz.
using namespace std;

int main(){											//ofstream dosya oluþturma iþlemi için kullanýlýr.
	ofstream outFile("file3.txt", ofstream::app);	//Bir ofstream objesi oluþturuyoruz ve isim veriyoruz. Bu þekilde yazarsak aþaðýda yazýlanlarý her açtýðýmýzda
													//ekleyecektir.
	if (outFile.fail()){							//Eðer dosya açýlýrken hata olursa bu mesajý yazdýracaðýz.
		cout<<"ERROR"<<endl;				
		return 1;
	}
	if ( outFile.is_open() ){						//is_open komutu ile dosyanýn açýk olup olmadýðýný kontrol edebiliriz.
    outFile << 3 << endl;
  }
	outFile << "content" << endl;				//Bu dosyayý her açtýðýmýzda bu yazý tekrar yazýlmayacak. Eðer daha önceden yazýlmýþsa ayný þekilde duracak. Eðer
												//yazýlmamýþsa bu sefer yazacak.
	
	outFile.close();
	return 0;
}

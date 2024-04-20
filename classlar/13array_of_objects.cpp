#include <iostream>

using namespace std;
							
class Square{
	public:
		int side;
		string color;
		
		void print()
		{
			cout<<"side: "<<side<<" color:"<<color<<endl;
		}
		
		Square(int, string);
		
		Square(){
			side=3;
			color="black";
		}
		
		Square(int side){
			this->side=side;
			color="black";
		}
};

Square::Square(int side, string color){
	this->side=side;
	this->color=color;
}
int main(){
	
	//Square squares[3];	  Bir constructor'ımız olmadığı için class otomatik olarak bir constructor oluşturacaktır. Eğer kendimiz constructor
							//giriyorsak objeleri oluştururken hepsinin değerlerini atamamız gerekir.
	/*
	int length;
	cout<<"array'in kac elemanli olacagini giriniz: "<<endl;
	cin>>length;
	int side[length];
	string color[length];

	
	for(int j = 0 ; j < length ; j++){

		cout<<j<<". index'in degerlerini giriniz: "<<endl;
		cin>>side[j];
		cin>>color[j];
		}
	*/ 

	//Bu yazımda arrayin kaç tane obje içerdiğini bilemediğimiz için bir for döngüsüne sokmamız gerek. Fakat objelerle array oluşturduğumuz 
	//için oluşturduğumuz yerde tanımlamamız gerekiyor. Bu yüzden array'in uzunluğunu bilmeden obje array'i yapamayız.
	//Objemizi direkt olarak yazdıramayız. Bunun için bir fonksiyon kullanmamız gerek. Bu fonkisyon da print fonksiyonudur. cout<<square1<<endl;

	Square squares2[3]={{1},{2,"red"},{}};
	
		for(int i=0;i<3;i++){
		squares2[i].print();		
	}
	
	return 0;
}

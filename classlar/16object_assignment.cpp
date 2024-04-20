#include <iostream>

using namespace std;

class Simple{					//Bu class'tan üretilen objelerin kaç tane değişkeni olursa olsun hepsinde eşit sayıda olacağı için
	public:						//Değişken değerleri hep birbirine eşitlenebilir.
		int x;
		
		void deneme(int z){		//İçerisinde fonksiyon olması sonucu değiştirmez.
			int y=3;
		}
};


class Stack{
	public:
		Simple simple;			//Member variable olarak bir obje alabiliriz.
};

class Heap{
	public:
		Simple* simple;
		
		Heap(int x){
			simple= new Simple;
			simple->x=x;
		}
};
int main(){
	
	Simple simple1;
	simple1.x=4;
	Simple simple2;
	simple2.x=0;
	
	simple1 = simple2;
	
	cout<<"simple1 = "<<simple1.x<<" simple2 = "<<simple2.x<<endl; 	//Simple2 objesinin x değeri 0'dı. Atama yaptığımızda Simple1'nin de 
																	//x değeri 0 oldu. Fakat hala birbirlerinden ayrı objeler.
	simple2.x=15;
	
	cout<<"simple1 = "<<simple1.x<<" simple2 = "<<simple2.x<<endl;
	
	Stack stack1;
	
	stack1.simple.x = 3;					//stack1 objesi içindeki simple objesinin x değerini 3 yapmış olduk.
	
	Stack stack2;
	
	stack2.simple.x = 5;
	
	stack2 = stack1;			//stack1'in simple objesini stack2'nin simple objesine atadık. stack2'nin simple'ının x değeri artık 3.
	
	cout<<"stack1.simple.x= "<<stack1.simple.x<<endl;
	cout<<"stack2.simple.x= "<<stack2.simple.x<<endl;
	
	stack1.simple.x=4;		//Bu sefer stack class'ındaki objeleri pointer yaptığımız için bunlar heap'te depolanacaktır.
							//stack1' in pointer'ı heap'teki bir objeyi gösteriyordu. Bu objenin x değerini 3 yaptık.
							//stack2' in pointer'ı da heap'teki başka bir objeyi gösteriyordu. Bu objenin de x değerini 5 yaptık.
							//Bu iki stack objesini birbirine eşitlediğimizde stack2'nin pointer'ı artık stack1'in pointer'ının gösterdiği
							//yeri gösterir. Bu yüzden stack1'in x'inde yaptığımız değişiklikler stack2'yi de etkileyecektir. 
	
	cout<<"stack1.simple.x= "<<stack1.simple.x<<endl;
	cout<<"stack2.simple.x= "<<stack2.simple.x<<endl;
	
	Heap heap1(4);
	Heap heap2(6);
	
	cout<<"heap1.simple->x: "<<heap1.simple->x<<endl;
	cout<<"heap2.simple->x: "<<heap2.simple->x<<endl;

	heap1 = heap2;
	
	cout<<"heap1.simple->x: "<<heap1.simple->x<<endl;
	cout<<"heap2.simple->x: "<<heap2.simple->x<<endl;
	
	heap2.simple->x=7;
	
	cout<<"heap1.simple->x: "<<heap1.simple->x<<endl;
	cout<<"heap2.simple->x: "<<heap2.simple->x<<endl;
	
	return 0;
}

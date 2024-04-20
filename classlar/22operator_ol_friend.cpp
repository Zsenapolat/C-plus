#include <iostream>

using namespace std;

class Counter{
	friend int operator-(const Counter& count1,const Counter& count2);														
	private:
		int counter;
	public:
		Counter(int counter):counter(counter){}
		int getCounter(){
			return counter;
		}
};


int operator-(const Counter& count1,const Counter& count2){		//Friend function'lar member olmadığı için this pointer'ını kullanamazlar.
	int result=count1.counter - count2.counter;
	return result;
}

/*
Counter operator-(const Counter& count1,const Counter& count2){
	Counter count=count1.counter - count2.counter;
	return ount;
}
*/


int main(){
	Counter counter1(4);
	Counter counter2(3);
	
	Counter counter3(counter1 - counter2);			//Buraya obje de int de döndürebilirsin. Sonuç aynı olacaktır.
	cout<<counter3.getCounter()<<endl;
	return 0;
}

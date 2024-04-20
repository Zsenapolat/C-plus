#include <iostream>

using namespace std;

class myN {
private:
	int N;

public:
	myN();

	myN(int n);
		
	~myN();

	int getN();

	void setN(int y);
	
};

myN::myN(){
	cout << "Default Constructor\n";
	N=0;
}
		
myN::myN(int n){
	cout << "Overloaded Constructor\n";
	N=n;
}
myN::~myN(){
	cout << "Destructor...\n";
}

// Member function
int myN::getN(){
	return N;
}
void myN::setN(int y){
	N=y;
}
// Pass the object by-value. Object is copied.
void test(myN u){							//u objesi m objesini fonksiyon içerisinde kopyalayacak.
	u.setN(10);
} // u, fonksiyon bittikten sonra silinir.

// Pass the object as a reference
void testRef(myN &u){
	u.setN(10);
}

// Pass the object as a pointer
void testPnt(myN *u){
	u->setN(10); 			// We are not modifying u itself, but the memory location pointed by u.
} //Ardından u pointer'ı silinir.

// Pass the object as a pointer, but modify u itself
void testPntMod(myN *u){
	u = new myN(); // This is a local copy. Any change to u itself is local. 
	u->setN(10);
}//Oluşturduğumuz u pointer'ı silinir. Fakat u'nun heap üzerinde gösterdiği obje silinmez. (Memory leak)

int main(){
	myN m(6);									//Overloaded constructor kullanarak bir m objesi üretiyoruz. N değeri 6.
	cout << "before:" << m.getN() << endl;		//Çıktısı da bu yüzden 6 oluyor.
	test(m);									//test fonksiyonunun içine gönderdiğimizde u adında yeni bir obje üretiyoruz. Bu obje m objemizin
	cout << "after:" << m.getN() << endl;		//kopyası oluyor. Bu yüzden fonksiyon içerisinde yalnızca u objesinin değerini değiştirmiş
												//oluyoruz. 

	cout << "before:" << m.getN() << endl;		//Referans olarak gönderdiğimizde u objesi m objesiyle aynı adreste olduğu için yaptığımız 
	testRef(m);									//değişiklikler m'de de yapılmış olur.        
	cout << "after:" << m.getN() <<endl;		//U referans'ı fonksiyon bittikten sonra silinir.

	m.setN(45);
	cout << "before:" << m.getN() << endl;
	testPnt(&m);								//Oluşturduğumuz u pointer'ı m objesinin adresini gösteriyor. Bu yüzden m'in N değerini 10 ile
	cout << "after:" << m.getN() << endl;		//değiştirmiş oluyoruz.

	myN *p = new myN(4); 						//p pointer'ı heap üzerinde yeni oluşturduğumuz N değeri 4 olan bir objeyi gösteriyor.
	cout << "before:" << p->getN() << endl;						
	testPnt(p); 								//p ve u pointer'larının gösterdiği adresleri eşitledik. u artık heap'te oluşturduğumuz class'ın
	cout << "after:" << p->getN() << endl;		//adresini gösteriyor. Bu yüzden u üzerinde yaptığımız değişiklikler p'yi de etkiler. 
	delete p; 									//Pointer ile işimiz bitti. Bu yüzden silebiliriz.												

	m.setN(45);
	cout << "before:" << m.getN() << endl;		//Burada sıralama çok önemli. öncesinde u pointer'ını m objesinin adresine eşitliyoruz.
	testPntMod(&m);								//Ardından u pointer'ı heap'te yeni oluşturduğumuz objenin adresini gösteriyor.
	cout << "after:" << m.getN() << endl;		//Bu yüzden yaptığımız değişiklikler m'i etkilemiyor. N değeri hala 45.
	
	return 0;
}

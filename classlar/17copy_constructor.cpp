#include <iostream>

using namespace std;
							//Bir nesne oluşturduğumuzda constructor çağrılır. Eğer bu nesneden başka bir nesne türetiyorsak
							//Bu yeni nesnede constructor değil copy constructor çağrılır. Parametremiz ise m1'dir. 
            				//m1'in içeriği kopyalanacağı ve değişiklik yapılmayacağı için const keyword'ünü kullanırız.
							//Referans olarak almamızın sebebi ise bu constructor çağrıldığında parametre olarak obje alacağı
    						//için call by value yapmak istemeyiz.
class Myclass {
public:
	int n;
    Myclass() {
        cout << "default constructor" << endl;
}
    															

    Myclass(const Myclass &r){		
        cout << "***********************************" << endl;
        cout << "copy constructor" << endl;
        cout << "this  = " << this << endl;						//Bu kısım m2 oluşturulduktan sonra çalıştırılacağı için this = &m2
        cout << "&r    = " << &r << endl;						//Burası ise referans olduğu için m1'in adresidir.
        cout << "***********************************" << endl;
    }

};

int main()
{
    Myclass m1;								//m1 objemizi oluşturduk ve default constructor çağrıldı.
    Myclass m2 = m1;   						//Burada m1'den m2 objesini türetiyoruz. Bu yüzden copy constructor çağrılıyor.

    cout << "&m1  = " << &m1 << endl;
    cout << "&m2  = " << &m2 << endl;
    
    cout<<&(m1.n)<<endl;
    cout<<&(m2.n)<<endl;

	Myclass m3;
	m3.n=4;
	Myclass m4;
	m4.n=5;

	m3 = m4;					//Copy constructor object assignment'la aynı şey değildir. 
    return 0;
}
							                                    
//Const olmayan ve referans olmayan bir class parametresi yazsaydık bu CC çağrıldığında bir tane daha m1 oluşturulmuş olacaktı ve bu CC ile 
//işimiz bittiğinde  silinecekti. Fakat const olmadığı için ama call by value olduğu için m1 üzerinde herhangi bir değişiklik yapılmamış olur. 
//Const olursa CC içinde oluşturulan m1 üzerinde de değişiklik yapılamaz.

//Const olmayan ama referans olan bir class parametresi yazsaydık bir tane daha m1 oluşturmak yerine direkt olarak m1'i parametre almış oluruz.
//Fakat m1 burada const olmadığı için m1 üzerinde bu CC üzerinden değişiklikler yapılabilir. Bu da istemediğimiz bir durumdur.

				
/*
default constructor
***********************************
copy constructor
this  = 0x6ffe1e
&r    = 0x6ffe1f  (r = m1)
***********************************
&m1  = 0x6ffe1f
&m2  = 0x6ffe1e
*/

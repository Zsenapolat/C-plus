#include <iostream>

using namespace std;
class myTest
{
public:
	const int x = 0;			//Objemizi const yapıp oluşturduğumuzda default constructor x'e rastgele bir değer atayacağı için hata alırız. 
	int a;						//Bu yüzden class içerisinde bu değişkeni başlatmamız gerekir. Eğer objemiz const olacaksa içerisinde tanımlanmayan
                                //değişken bırakmamalıyız.
    myTest(int a) : a(a){}
    void foo(int x) const		//SADECE CLASS FONKSİYONLARI CONST OLABİLİR.
    {
    	x = 6;					//Const fonksiyonun içerisinde herhangi bir değişkenin değerini değiştiremeyiz.
        cout << "num: " << x << endl;
    }

    void func(void)                 //Objemiz const ise bu fonksiyon içerisinde a üzerinde değişiklik yapamayız.
    {
        cout <<" func " << endl;
    }    
};

int main()
{
    const myTest my(5);				//Eğer objemizi const olarak tanımladıysak obje içindeki değerleri değiştiremeyiz ve sadece const olan 
									//fonksiyonları çağırabiliriz.								
    my.foo(5);
    
    return 0;
}

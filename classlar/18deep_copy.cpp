#include <iostream>

using namespace std;

class Number{
	public:
		int *n;					//Class içerisinde bir değişken oluşturulacaksa constructor içinde oluşturamayız. Ama önceden oluşturulmuş
								//pointer'ı bir adrese atayabiliriz.
		
		Number(int set_n){
			n = new int;		//int *n = new int; ile aynı görevi görür. Sadece yerleri farklıdır. Burada *n üzerinde yapılan değiiklikler
			*n = set_n;			//Class içerisindeki n için de geçerli olur. 
		}
		
		~Number(){				//Destructor çağrıldığında sadece objemizi silerse pointer da silinir fakat gösterdiği yer bellekte yer
			cout<<"Pointer'lar silindi."<<endl;
			delete n;			//kaplamaya devam eder. Bu yüzden bu pointer'ı da siliyoruz.
			
		}
		
		Number(const Number& num){		//Bu işleme deep copy denir. 
			n = new int;				//Aşağıdaki işlemi düşünürsek şuanda num1'in kopyasını alıyoruz. Yani num2'nin içerisindeyiz. 
			*n=*(num.n);				//Buradaki num parametresi num1 olacak. num1 ve num2'nin n pointer'ları şuanda aynı yeri gösteriyor.
										//Eğer bu satırı yazmazsak pointerlar hala aynı yeri göstermiş olacak ve burada da sadece 
										//değerlerini birbirine eşitlemiş olacağız. Değişikliği burada yapacağımız için num1'in pointer'ına 
										//başka bir adresi göstertiyoruz. Böylece ikisi de artık farklı yerleri gçsteriyor ama değerleri eşit.
		}
		int get(){
			return *n;
		}
};
int main(){
	Number num1(8);
	
	cout<<"&num1: "<<&num1<<endl;
	
	cout<<num1.get()<<endl;
	
	cout<<"num1.n: "<<num1.n<<endl;		//-> ile gösterebilmemiz için nesnenin pointer olması gerekir. Yine de n pointer olduğu için adres verir. 
	
	Number num2 = num1;					//Burada default copy constructor devreye girecektir. 
			
	cout<<"num2.n: "<<num2.n<<endl;
											
	cout<<num2.get()<<endl;
	
	cout<<&num1<<endl;					//num1 ve num2 objelerinin farklı bellek adreslerinde olduklarını biliyoruz.
	cout<<&num2<<endl;
	
	cout<<&(num1.n)<<endl;				//İçlerinde bulunan n pointer'ları da num1 ve num2'nin kendi bellek adreslerinde tutuluyor.
	cout<<&(num2.n)<<endl;
	
	cout<<num1.n<<endl;					//Fakat num1'in kopyası olan num2 artık num1'in pointer'ının gösterdiği bellek adresini gösteriyor.
	cout<<num2.n<<endl;					//Programı çalıştırdığımızda ise çökecektir. Çünkü iki objemiz için de destructor çağrılıyor.
	
	return 0;
}

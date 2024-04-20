#include <iostream>
#include <string>

using namespace std;

class Employee{
	private:
		int age;
	
	public:
		void setAge(int age){
			this->age=age;
		}
		
		int getAge(){
			return age;
		}
};

int main(){
						/*Buradaki işlemlerin hepsinde bir pointer için yer ayırıyoruz. Değişken türü ne olursa olsun oluşturulan
						pointer'ımızın bellekte kapladığı alan aynıdır. Çünkü biz burada pointer'ımızın gösterdiği adrese oluşturmak
						istediğimiz değişken türünün kapladığı alan kadar yer ayırmak istiyoruz. Pointer'ımıza bu değişkenin türü
						kadar yer ayırmıyoruz. Yazım şekli olarak pointer'ımızı oluştururken göstereceği adresteki değişken türüyle
						aynı türde yazmamız gerekiyor.
						*/
	Employee* employee = new Employee;	//Veri tipi burada Employee class'ı olur.		
														
	cout<<sizeof(Employee)<<endl;		//Employee class tipinde bir objenin kapladığı alan 4 byte.		
	cout<<sizeof(employee)<<endl;		//employee objesini işaret eden pointer'ın kapladığı alan 4 byte.
	cout<<sizeof(*employee)<<endl;		//employee objesinin kapladığı alan 4 byte.
	
	cout<<employee<<endl;				//Bu yüzden artık employee objesini kullanırken -> işareti ile kullanmamız gerekiyor.
										//Pointer'ın gösterdiği adres.
	cout<<&employee<<endl;				//Pointer'ın adresi.
	
	int *ptr1 = new int;
	
	cout<<sizeof(int)<<endl;		//Int veri tipinin kapladığı alan 4 byte.
	cout<<sizeof(ptr1)<<endl;		//Int türündeki değişkeni gösteren pointer'ın kapladığı alan 4 byte.
	cout<<sizeof(*ptr1)<<endl;		//Değişkenimizin kapladığı alan 4 byte.
	
	double *ptr2 = new double;
	
	cout<<sizeof(double)<<endl;			//Double veri tipinin kapladığı alan 8 byte.
	cout<<sizeof(ptr2)<<endl;			//Double veri tipinde değişkeni işaret eden pointer'ın kapladığı alan 4 byte. 
	cout<<sizeof(*ptr2)<<endl;			//Değişkenimizin kapladığı alan 8 byte.
	
	float *ptr3 = new float;
	
	cout<<sizeof(float)<<endl;			//Float veri tipinin kapladığı alan 4 byte.
	cout<<sizeof(ptr3)<<endl;			//Float veri tipinde değişkeni işaret eden pointer'ın kapladığı alan 4 byte. 
	cout<<sizeof(*ptr3)<<endl;			//Değişkenimizin kapladığı alan 4 byte.
	
	char *ptr4 = new char;
	
	cout<<sizeof(char)<<endl;			//Char veri tipinin kapladığı alan 1 byte.
	cout<<sizeof(ptr4)<<endl;			//Char veri tipinde değişkeni işaret eden pointer'ın kapladığı alan 4 byte. 
	cout<<sizeof(*ptr4)<<endl;			//Değişkenimizin kapladığı alan 1 byte.
		
	return 0;
}

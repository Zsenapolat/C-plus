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
											/*Buradaki iþlemlerin hepsinde bir pointer için yer ayýrýyoruz. Deðiþken türü ne olursa olsun oluþturulan
											pointer'ýmýzýn bellekte kapladýðý alan aynýdýr. Çünkü biz burada pointer'ýmýzýn gösterdiði adrese oluþturmak
											istediðimiz deðiþken türünün kapladýðý alan kadar yer ayýrmak istiyoruz. Pointer'ýmýza bu deðiþkenin türü
											kadar yer ayýrmýyoruz. Yazým þekli olarak pointer'ýmýzý oluþtururken göstereceði adresteki deðiþken türüyle
											ayný türde yazmamýz gerekiyor.
											*/
	Employee* employee = new Employee;	//Veri tipi burada Employee class'ý olur.		
														
	cout<<sizeof(Employee)<<endl;		//Employee class tipinde bir objenin kapladýðý alan 4 byte.		
	cout<<sizeof(employee)<<endl;		//employee objesini iþaret eden pointer'ýn kapladýðý alan 8 byte. Pointer'ýmýz employee objesinin adresini taþýyor.
	cout<<sizeof(*employee)<<endl;		//employee objesinin kapladýðý alan 4 byte.
	
	cout<<employee<<endl;				//Bu yüzden artýk employee objesini kullanýrken -> iþareti ile kullanmamýz gerekiyor.
										//Pointer'ýn gösterdiði adres.
	cout<<&employee<<endl;				//Pointer'ýn adresi.
	
	int *ptr1 = new int;
	
	cout<<sizeof(int)<<endl;			//Int veri tipinin kapladýðý alan 4 byte.
	cout<<sizeof(ptr1)<<endl;			//Int veri tipinde deðiþkeni iþaret eden pointer'ýn kapladýðý alan 8 byte. Pointer burada deðiþkenin adresini taþýyor.
	cout<<sizeof(*ptr1)<<endl;			//Deðiþkenimizin kapladýðý alan 4 byte.
	
	double *ptr2 = new double;
	
	cout<<sizeof(double)<<endl;			//Double veri tipinin kapladýðý alan 8 byte.
	cout<<sizeof(ptr2)<<endl;			//Double veri tipinde deðiþkeni iþaret eden pointer'ýn kapladýðý alan 8 byte. Pointer burada deðiþkenin adresini taþýyor.
	cout<<sizeof(*ptr2)<<endl;			//Deðiþkenimizin kapladýðý alan 8 byte.
	
	float *ptr3 = new float;
	
	cout<<sizeof(float)<<endl;			//Float veri tipinin kapladýðý alan 4 byte.
	cout<<sizeof(ptr3)<<endl;			//Float veri tipinde deðiþkeni iþaret eden pointer'ýn kapladýðý alan 8 byte. Pointer burada deðiþkenin adresini taþýyor.
	cout<<sizeof(*ptr3)<<endl;			//Deðiþkenimizin kapladýðý alan 4 byte.
	
	char *ptr4 = new char;
	
	cout<<sizeof(char)<<endl;			//Char veri tipinin kapladýðý alan 1 byte.
	cout<<sizeof(ptr4)<<endl;			//Char veri tipinde deðiþkeni iþaret eden pointer'ýn kapladýðý alan 8 byte. Pointer burada deðiþkenin adresini taþýyor.
	cout<<sizeof(*ptr4)<<endl;			//Deðiþkenimizin kapladýðý alan 1 byte.
		
	return 0;
}

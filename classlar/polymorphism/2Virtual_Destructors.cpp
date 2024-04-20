#include <iostream>

using namespace std;

class BaseData{
	public:
		int *data;
		
		BaseData(int size){
			data=new int[size];
			cout<<"BaseData constructor"<<endl;
		}
		
		virtual ~BaseData(){
			cout<<"BaseData destructor"<<endl;
			delete [] data;
		}
};

class DerivedData : public BaseData {
	public:
		int *extra_data;
		
		DerivedData(int extra_size,int size):BaseData(size){		//Baseclass'ın default constructor'ı olmadığı için bunu eklememiz gerek.
			extra_data=new int[extra_size];
			cout<<"DerivedData constructor"<<endl;
		}
		~DerivedData(){
			cout<<"DerivedData destructor"<<endl;
			delete [] extra_data;
		}
};
int main(){
	BaseData *datas[] ={
		new BaseData(5),
		new DerivedData(2,3)
	};
	for(int j=0 ; j<2 ; j++){
		delete datas[j] ;
	}
	return 0;
}

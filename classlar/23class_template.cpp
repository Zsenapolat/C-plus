#include <iostream>

using namespace std;

template <typename T>
class Array{
	public:
		T array[10];
		
		void fill(T value){
			for(int i=0 ; i<10 ; i++){
				array[i]=value;
			}
		}
		
		T& at(int index){				//Eğer return reference yaparsak bu fonksiyonun değerini dışardan değiştirebiliriz.
			return array[index];
		}
};
int main(){
	Array <int>array;
	
	array.fill(5);
	
	array.at(3)=6;
	
	cout<<array.at(3)<<endl;
	
	return 0;
}

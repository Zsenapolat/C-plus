#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swp(T& x, T& y){		//Parametrelerin ayný tür olmasý gerek.
	T z = x;
	x = y;
	y = z;
	cout<<x<<" "<<y<<endl;
}
int main(){
	int a=5;
	int b=4;
	
	swp(a, b);	//ya da swp<int>(a,b)
	swp(a, b);	
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(){
	int foo1 = 0;
	auto bar1 = foo1;  // ya da int bar1;
  					   //cout<<bar1<<endl; yazamayýz çünkü burada sadece bar1 ve foo1' in deðiþken tipini eþitledik. Deðerlerini birbirine eþitlemedik.	
	int foo2 = 0;
	decltype(foo2) bar2;  // ya da int bar
						
	return 0;
}

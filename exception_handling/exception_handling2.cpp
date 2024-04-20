#include <iostream>

using namespace std;

class Div0{
	public:
		string msg;
		Div0(string msg) : msg(msg){}
};
double divisor(int a, int b){
	if (b==0){
		throw(Div0("error 0"));
	}
	else{
		return a/b;
	}
}
int main(){
	try{
	int a, b;
	cin>>a>>b;
	double c = divisor(a,b);
	cout<<c<<endl;
	}
	catch(Div0& e)
	{
		cout<<e.msg<<endl;
	}
	return 0;
}

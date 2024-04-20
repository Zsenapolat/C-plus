#include <iostream>
#include <string>
using namespace std;
							//Chaining kodu basitleştirmek için kullanılır. Genelde setter metod serileri ile yapılır.
class Rectangle{
	public:
		int length;
		int width;
		string color;
		
		Rectangle &print();
		
		Rectangle& get_L(){
			cout<<"length: "<<length<<endl;
			return *this;						//this return ettiğimizde adresi verir. Ancak *this return edersek o adresteki değeri verir.
		}
		Rectangle& get_W(){
			cout<<"width: "<<width<<endl;
			return *this;
		}
		Rectangle& get_C(){
			cout<<"color: "<<color<<endl;
			return *this;
		}
		
		Rectangle& set_L(int l){
			length=l;
			return *this;
		}
		Rectangle& set_W(int w){
			width=w;
			return *this;
		}
		Rectangle& set_C(string c){
			color=c;
			return *this;
		}
};

Rectangle& Rectangle::print(){
	cout<<"rectangle has:"<<endl;
	return *this;
}
int main(){
	Rectangle rectangle1;
	rectangle1.set_W(5).set_L(4).set_C("red");
	rectangle1.print().get_L().get_W().get_C();
	return 0;
}

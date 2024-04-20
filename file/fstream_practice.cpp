#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream outfile1("file1.txt");
	if(outfile1.fail()){
		cout<<"ERROR1"<<endl;
		return 1;
	}
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	outfile1 << num1 << " " << num2 << " " << num3 << endl;
	outfile1.close();
	
	ofstream outfile2("file.txt");
	if(outfile2.fail()){
		cout<<"ERROR2"<<endl;
		return 1;
	}
	
	ifstream infile("file1.txt");
	if(infile.fail()){
		cout<<"ERROR3"<<endl;
		return 1;
	}
	int x;
	while(true){
		if(!(infile.eof())){
			infile >> x;
			outfile2 << x <<endl;
		}
		else{
			break;
		}
	}
	
	infile.close();
	outfile2.close();
	return 0;
}

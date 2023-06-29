#include<iostream>
using namespace std;
int main(){
	//If statement
	double marks;
	cout<<"Enter marks of the student to calcuate the grade:"<<endl;
	cin>>marks;
	if(marks>90){
		cout<<"A"<<endl;
	}
	else if(marks>80){
		cout<<"B"<<endl;
	}
	else if(marks>70){
		cout<<"C"<<endl;
	}
	else if(marks>30){
		cout<<"pass"<<endl;
	}
	else{
		cout<<"Fail"<<endl;
	}
	//Switch Statment
	int a;
	cout<<"Enter a value"<<endl;
	cin>>a;
	switch(a){
	
	case 1:
		cout<<"The value of a is 1"<<endl;
	case 2:
		cout<<"The value of a is 2"<<endl;
	case 3:
		cout<<"The value of a is 3"<<endl;
	default:
		cout<<"default will be printed";
}
}


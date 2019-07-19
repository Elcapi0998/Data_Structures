#include <iostream>
#include <stdlib.h>


//Basic exception handling

using namespace std;

double ReadArray(double *arg, int n){
	double avg=0;
	cout<<"Enter "<<n<<" numbers: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>arg[i];
		if (cin.fail()) throw i; //throw the error
		avg+=arg[i];
	}
	return avg/n;
}

int main(){
	int n;
	double avg;
	double a[10];
	cout<<"How many number do you want to store?"<<endl;
	cin>>n;
	cout<<"Check what happens if an invalid character is introduced."<<endl;
	try{// try-catch to get the error
		avg=ReadArray(a,n);
		cout<<"The "<<n<<" numbers were stored, its average is: "<<avg<<endl;
	}catch (int pos){
		cout<<endl<<"Invalid character introduced!!"<<endl;
		cout<<"Only read "<<pos<<" character(s)"<<endl;
	}
	cout<<"End of execution"<<endl;
	return 0;
}
#include<iostream>
#include<stdlib.h>

using namespace std;

//Progam with exception handling for division by zero (0)

double dividend, divisor;

void GetAndVerifyInput(){
	cout<<"Introduce the dividend: ";
	cin>>dividend;
	if (cin.fail()) throw 0;
	cout<<"Introduce the divisor: ";
	cin>>divisor;
	if (cin.fail()) throw 1;
}


double division(){
	if(divisor==0) throw 0;
	return dividend/divisor;
}

int main(){
	try{//exception handling for invalid inputs
		GetAndVerifyInput();
		try{//exception handling for division by zero
			double aux=division();
			cout<<"The division of "<<dividend<<"/"<<divisor<<" is "<<aux<<endl;
		}catch(int z){
			cout<<"The division by zero is not possible."<<endl;
		}
		
	}catch(int k){
		if(k==0) cout<<"Invalid input in the dividend, only numbers please."<<endl;
		else cout<<"Invalid input in the divider, only numbers please."<<endl;
	}
	return 0;

}
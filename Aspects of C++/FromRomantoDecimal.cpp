#include<iostream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

//Converts Roman Number to Decimal Numbers

class FromRomantoDecimal{

public:
	FromRomantoDecimal(const char *s);
	int num;
private:
	int val(char ch);
};


FromRomantoDecimal::FromRomantoDecimal(const char *s){
	num=0;
	int i=0, si, siplus;
	while(s[i]){
		si=val(s[i]);
		siplus=val(s[i+1]);
		if(siplus>si){
			num+=siplus;
			num-=si;
			i+=2;
		}else{
			num+=si;
			i++;
		}
	}
}


int FromRomantoDecimal::val(char ch){
	switch(toupper(ch)){
		case 'M': return 1000;
		case 'D': return 500;
		case 'C': return 100;
		case 'L': return 50;
		case 'X': return 10;
		case 'V': return 5;
		case 'I': return 1;
	}

	cout<<"Invalid Roman Number."<<endl;
	exit(1);
	return 0;
}

int main(){
	char str[100];
	cout<<"Enter a Roman Number: ";
	cin>>str;
	cout<<"Decimal Value: "<<FromRomantoDecimal(str).num<<endl;
	return 0;
}

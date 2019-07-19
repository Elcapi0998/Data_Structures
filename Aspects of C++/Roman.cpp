#include<iostream>
#include<stdlib.h>

using namespace std;

class Roman{
	private:
		enum{L=100};
	public:
		Roman(unsigned n);
		char number[L];
};

Roman::Roman(unsigned n){
	int values[]={1000, 900, 500, 400, 100, 90, 50,40, 10, 9, 5, 4,1};
	int length=sizeof(values)/sizeof(*values);
	char *text[]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int pos=0;
	strcpy(number,"");
	for (int i = 0; i < length; i++)
	{
		if (pos+3>L)
		{
			cout<<"Number too large"<<endl;
			exit(1);
		}
		while(values[i]<=n){
			number[pos++]=text[i][0];
			if (text[i][1]) number[pos++]=text[i][1];
			//strcat(number,text[i]);
			n-=values[i];
		}
	}
	number[pos]='\0';
}

int main(){
	unsigned num;
	cout<<"Enter a decimal number: ";
	cin>>num;
	cout<<"Roman: "<<Roman(num).number<<endl;
	return 0;
}

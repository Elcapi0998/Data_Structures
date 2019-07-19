#include<iostream>
#include<stdlib.h>

using namespace std;

class arithmetic_algorithms{
public:
	void static algorithms_menu();
	int static verify_input();
	int static gcd_iterative(int x, int y);
	int static gcd_recursive(int x, int y);
	double static horners_rule(const double x, const double *coefficients, int degree);
	int static toNum(const char *arg, int base);
};

void arithmetic_algorithms::algorithms_menu(){
	cout<<endl<<"Select the algorithm of your choice"<<endl<<endl;
	cout<<"1. Euclid's algorithm for GCD (iterative)."<<endl;
	cout<<"2. Euclid's algorithm for GCD (recursive)."<<endl;
	cout<<"3. Horner's Rule."<<endl;
	cout<<"4. Radix Conversion for Inputs (from chars to int)."<<endl;
}

int arithmetic_algorithms::verify_input(){
	int n;
	cin>>n;
	if (cin.fail()){cout<<"Invalid character introduced, only numbers please."<<endl; exit(1);}
	return n;
}


int arithmetic_algorithms::gcd_iterative(int x, int y){
	int aux;
	while(y){
		aux=x%y;
		x=y;
		y=aux;
	}
	return x;
}

int arithmetic_algorithms::gcd_recursive(int x, int y){
	if(y==0) return x;
	else return arithmetic_algorithms::gcd_recursive(y,x%y);
}

double arithmetic_algorithms::horners_rule(const double x,  const double *coefficients, int degree){
	double answer=coefficients[degree];
	for (degree--; degree >=0; degree--) answer=answer*x+coefficients[degree];
	return answer;
}


int arithmetic_algorithms::toNum(const char *arg, int base){
	int answer=0, i=0;
	int numaux=arg[i]-'0';
	while(numaux>=0 && numaux<base){
		answer=answer*base+numaux;
		i++;
		numaux=arg[i]-'0';
	}
	return answer;
}

int main(){
	int a, b;
	double x, *arg;
	char *str;
	arithmetic_algorithms::algorithms_menu();
	int n=arithmetic_algorithms::verify_input();
	switch(n){
		case 1:
			cout<<"Introduce the first number: ";
			a=arithmetic_algorithms::verify_input();
			cout<<"Introduce the second number: ";
			b=arithmetic_algorithms::verify_input();
			cout<<"The gcd("<<a<<","<<b<<") is: "<<arithmetic_algorithms::gcd_iterative(a,b)<<endl;
			break;
		case 2:
			cout<<"Introduce the first number: ";
			a=arithmetic_algorithms::verify_input();
			cout<<"Introduce the second number: ";
			b=arithmetic_algorithms::verify_input();
			cout<<"The gcd("<<a<<","<<b<<") is: "<<arithmetic_algorithms::gcd_recursive(a,b)<<endl;
			break;
		case 3:
			cout<<"Introduce the value of x: ";
			x=(double) arithmetic_algorithms::verify_input();
			cout<<"Introduce the coefficients of the polynomial (only fifth degree): ";
			arg=new double[6];
			for (int i = 0; i <6; ++i) arg[i]=(double) arithmetic_algorithms::verify_input();
			cout<<"The evaluated polynomial is: "<<arithmetic_algorithms::horners_rule(x,arg,5)<<endl;
			delete[]arg;
			break;
		case 4:
			cout<<"Introduce the base of the number ";
			a=arithmetic_algorithms::verify_input();
			cout<<"Introduce an up to ten digit number in the selected base: ";
			str=new char[11];
			cin>>str;
			cout<<"The number in base 10 is: "<<arithmetic_algorithms::toNum(str,a)<<endl;
			delete[]str;
			break;
	}
	return 0;
}
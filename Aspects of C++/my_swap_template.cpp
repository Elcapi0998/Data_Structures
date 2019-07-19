#include <iostream>

using namespace std;

//NOT WORKING

struct numbers
{
	float p,q;
};

template <class T> 
void my_swap(T &x, T &y){
	T w=x;
	x=y;
	y=w;
}

int main(){
	//Assign the data
	int x=1, y=2;
	char *month1="November", *month2="December";
	numbers P={9,8}, Q={66,77};

	//Print the data
	cout<<"Value of X: "<<x<<"\t"<<"Value of Y: "<<y<<endl;
	cout<<"Month 1: "<<month1<<"\t"<<"Month 2: "<<month2<<endl;
	cout<<"Values of P: ("<<P.p<<","<<P.q<<")"<<"\t"<<"Values of Q: ("<<Q.p<<","<<Q.q<<")"<<endl;


	//Make the swaps
	my_swap(x,y);
	my_swap(month1,month2);
	my_swap(P,Q);

	//Print the data
	cout<<"Value of X: "<<x<<"\t"<<"Value of Y: "<<y<<endl;
	cout<<"Month 1: "<<month1<<"\t"<<"Month 2: "<<month2<<endl;
	cout<<"Values of P: ("<<P.p<<","<<P.q<<")"<<"\t"<<"Values of Q: ("<<Q.p<<","<<Q.q<<")"<<endl;
	return 0;
}
#include<iostream>

using namespace std;

// class for dynamic arrays

class ints
{
private:
	int *p;
	int length;

public:
	ints(){p=NULL, length=0;}
	ints(int *a, int n);
	ints(const ints &r);
	~ints(){delete[] p;}
	ints &operator=(const ints &r);
	int len() const {return length;}
};

//Constructor
ints::ints(int *a, int n){
	p=new int[n];
	for (int i = 0; i < n; ++i) p[i]=a[i];
	length=n;
}


//Construtor
ints::ints(const ints &r){
	length=r.length;
	p=new int[length];
	for (int i = 0; i < length; ++i) p[i]=r.p[i];
}


//Override operator =
ints &ints::operator= (const ints &r){
	if (&r!=this)
	{
		delete[] p;
		length=r.length;
		p=new int [length];
		for (int i = 0; i < length; ++i) p[i]=r.p[i];
	}
	return *this;
}

int main (){
	int a[3]={1,2,3};
	int b[5]={4,5,6,7,8};
	ints A(a,3), B=A;
	cout<<"Size A: "<<A.len()<<endl;
	cout<<"Size B: "<<B.len()<<endl;
	B=ints(b,5);
	cout<<"Size A (after): "<<A.len()<<endl;
	cout<<"Size B: (after): "<<B.len()<<endl;
	return 0;
}
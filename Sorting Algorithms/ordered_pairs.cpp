#include <iostream>
#include<string.h>
#include<math.h>

//Template class to sort list of two elements

using namespace std;

template <class T>
void my_swap(T &x, T &y){
	T aux=x;
	x=y;
	y=aux;
}

template <class T>
void my_sort(T &x, T &y){
	if(x>y) my_swap(x,y);
}

class record{
public:
	char *name;
	int number;
	record(char *s, int i){
		number=i;
		name=s;
	}

	friend ostream &operator<<(ostream &os, record &r){
		return os<<r.name<<" "<<r.number;
	}

	//operator by number
	int operator>(record &s){
		return number>s.number;
	}
	/*
	//operator by name
	int operator>(record &s){
		return strcmp(name,s.name)>0;
	}
	*/
	
};

class point{
public:
	float x, y;
	point(float a, float b){
		x=a;
		y=b;
	}
	int operator>(point &Q){
		return pow(x,2)+pow(y,2)>pow(Q.x,2)+pow(Q.y,2);
	}

	friend ostream &operator<<(ostream &os, point &P){
		return os<<"("<<P.x<<","<<P.y<<")";
	}
};

int main(){
	char *name=new char[10];
	name="Ulises";
	record U(name,1998);
	name="Lupillo";
	record L(name,1996);
	point P(9.9,7.8), Q(3.9,9.0);
	cout<<"U: "<<U<<"	"<<"L: "<<L<<endl;
	cout<<"P: "<<P<<"	"<<"Q: "<<Q<<endl;
	my_sort(U,L);
	my_sort(P,Q);
	cout<<"U: "<<U<<"	"<<"L: "<<L<<endl;
	cout<<"P: "<<P<<"	"<<"Q: "<<Q<<endl;
	return 0;
}





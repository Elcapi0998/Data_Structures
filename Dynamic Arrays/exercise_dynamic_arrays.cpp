#include<iostream>
#include<stdlib.h>

//Read a sequence of nonzero integer number followed by 0 and print them backwards

using namespace std;

int ChunkSize=3;

class exercise_dynamic_arrays
{
private:
	int physicalLEN, logicalLEN;
	int *arg;

public:
	exercise_dynamic_arrays();
	~exercise_dynamic_arrays(){
		delete[] arg;
		physicalLEN=0;
		logicalLEN=0;
	}
	void addNumber(int num);
	void printBackwards();
	
};

exercise_dynamic_arrays::exercise_dynamic_arrays(){
	physicalLEN=ChunkSize;
	logicalLEN=0;
	arg=new int [physicalLEN];
	if (arg==NULL)
	{
		cout<<"Memory allocation failure"<<endl;
		exit(1);
	}
}

void exercise_dynamic_arrays::addNumber(int num){
	if (physicalLEN==logicalLEN)
	{
		int *arg_aux=arg;
		arg=new int [physicalLEN+ChunkSize];
		for (int i = 0; i < logicalLEN; ++i)
		{
			arg[i]=arg_aux[i];
		}
		physicalLEN+=ChunkSize;//Physical size of the array is updates by the ChunkSize
	}
	arg[logicalLEN]=num;
	logicalLEN++;//Logical size of the array is update by 1
}

void exercise_dynamic_arrays::printBackwards(){
	cout<<endl<<"The nonzero numbers stored in backwards are: ";
	for (int i = logicalLEN-1; i >= 0; i--)
	{
		cout<<arg[i]<<" ";
	}
	cout<<endl;
}

int main(){
	exercise_dynamic_arrays list;
	int num;
	cout<<"Enter the list of integer numbers you want followed by a zero (0): ";
	while(cin>>num,num!=0){
		list.addNumber(num);
	}
	list.printBackwards();
	return 0;
}
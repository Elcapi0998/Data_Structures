#include<iostream>

using namespace std;

template <class T>
void selection_sort(T *arg, int n){
	int i,j,k;
	T min;
	for (i = 0; i < n-1; ++i)
	{
		min=arg[i];
		k=i;
		for (j=i+1; j < n; ++j)
		{
			if (arg[j]<min)
			{
				min=arg[j];
				k=j;
			}
		}
		arg[k]=arg[i];
		arg[i]=min;
	}
}

template <class T>
void printArray(T *arg, int size){
	for (int i = 0; i < size; ++i) cout<<arg[i]<<" ";
	cout<<endl;
}


int main (){	
	int arg[10]={21,65,3,2,90,65,12,3,66,61};
	int size=sizeof(arg)/sizeof(int);
	cout<<"Original Array:";
	printArray(arg,size);
	selection_sort(arg,size);
	cout<<"Ordered Array (selection sort):";
	printArray(arg,size);
	return 0;
}
#include<iostream>

using namespace std;

template <class T>
void bubblesort(T *arg, int size){
	int j,k;
	int right=size-1;
	T aux;
	while(right>0)
	{
		k=0;//considering that the array is ordered 
		for(j=0;j<right;j++){
			if (arg[j]>arg[j+1])//if a greater number is found, make the swap and update the right limit
			{
				aux=arg[j];
				arg[j]=arg[j+1];
				arg[j+1]=aux;
				k=j;
			}
		}
		right=k;//update the right limit of the last ordered element
	}
}

template <class T>
void printArray(T *arg, int size){
	for (int i = 0; i < size; ++i) cout<<arg[i]<<" ";
	cout<<endl;
}

int main(){
	int arg[10]={21,65,3,2,90,65,12,3,66,61};
	int size=sizeof(arg)/sizeof(int);
	cout<<"Original Array:";
	printArray(arg,size);
	bubblesort(arg,size);
	cout<<"Ordered Array (bubblesort):";
	printArray(arg,size);
	return 0;
}
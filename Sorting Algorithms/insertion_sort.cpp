#include<iostream>

using namespace std;

template <class T>
void insertion_sort(T *arg, int size){
	int i, j;
	T aux;
	for (i = 0; i<size; i++){
		aux=arg[i];
		for (j=i-1; j>=0; j--)//swap the element backwars if it is bigger
			if (aux<arg[j]) arg[j+1]=arg[j];
			else break;//break the loop to get the index of the last moved element to store the smallest value in such position
		arg[j+1]=aux;
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
	insertion_sort(arg,size);
	cout<<"Ordered Array (insertion sort):";
	printArray(arg,size);
	return 0;
}
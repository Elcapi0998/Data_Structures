#include<iostream>
#include<stdlib.h>

using namespace std;


//Dynamic array using a default ChunkSize with Templates


int ChunkSize=5;

template <class T>
class ChunkList{
private:
	int len, length; //logical and physical lenght
	T *arg;
public:
	ChunkList(){
		length=ChunkSize;
		arg=new T[length];
		len=0;
	}
	~ChunkList(){
		delete[] arg;
		length=0;
		len=0;
	}
	void addItem(T number);
	T &operator[] (unsigned number) const{ //overloading the access operator []
		if (number>=len)
		{
			cout<<"Index out Of Bounds";
			exit(1);
		}
		return arg[number];
	}
	int GetLogicalLenght() const{
		return len;
	}

	int GetPhysicalLenght() const{
		return length;
	}
};


template <class T>
void ChunkList<T>::addItem(T number){
	if (length==len)
	{
		T *arg_aux=arg; //auxiliary pointer
		arg=new T[len+ChunkSize];//new array with the ChunkSize added
		for (int i = 0; i < len; ++i)
		{
			arg[i]=arg_aux[i];
		}
		delete[] arg_aux;
		length+=ChunkSize; //increase the physical size
	}
	arg[len]=number;
	len++; //increase the logical size
}

int main(){
	ChunkList<double> list;
	double number;
	int size;
	cout<<"Enter nonzero number, the last one followed by 0: ";
	cin>>number;
	while(number!=0) {
		list.addItem(number);
		cin>>number;
	}
	size=list.GetLogicalLenght();
	cout<<"The nonzero numbers stored are: ";
	for (int i = 0; i < size; i++) cout<<list[i]<<" ";
	cout<<endl<<"The PHYSICAL size is: "<<list.GetPhysicalLenght();
	cout<<endl<<"The LOGICAL size is: "<<list.GetLogicalLenght()<<endl;
	return 0;
}
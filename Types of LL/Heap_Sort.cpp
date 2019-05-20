//HEAP SORT

#include<iostream>
using namespace std;

void insert(int H2[], int &n, int k){
	static int i=0;
	H2[i]=k;
	int j=i, temp=0;
	++i;
	while(j>0){
		if(H2[(j-1)/2] > H2[j]){
			temp=H2[(j-1)/2];
			H2[(j-1)/2]=H2[j];
			H2[j]=temp;
		}
		j=(j-1)/2;
	}
	n=i;
}

void swap(int &a, int &b){
	int temp=0;
	temp=a;
	a=b;
	b=temp;
}

void Heap_Sort(int H[], int n){
	int i=0;
	while(n>0){
		cout<<H[0]<<" ";
		H[0]=H[--n];
		while(i<n){
			if(H[2*i+1]<H[2*i+2] && 2*i+1<n){
				if(H[i]>=H[2*i+1]) swap(H[i],H[2*i+1]);
				i=2*i+1;
			}
			else if(H[2*i+1]>H[2*i+2] && 2*i+2<n){
				if(H[i]>=H[2*i+2]) swap(H[i],H[2*i+2]);
				i=2*i+2;
			}
			else break;
		}
		i=0;
	}
}

int main()
{
	int H[9]={93,8,7,66,5,4,30,2,101};
	int H2[9]={0};
	int n=0;
	for(int i=0; i<9; i++){
		insert(H2,n,H[i]);
	}
	cout<<"The array is : ";
	for(int i=0; i<9; i++){
		cout<<H2[i]<<" ";
	}
	cout<<"\nSorted Array is : ";
	Heap_Sort(H2,n);
	return 0;
}

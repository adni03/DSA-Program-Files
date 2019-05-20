//DISJOINT SET

#include<iostream>
using namespace std;

int find(int a[], int key){
	return a[key];
}

void Union(int a[], int key, int root){
	a[key]=a[root];
}

void reset(int a[], int n){
	for(int i=0; i<n; i++){
		a[i]=i;
	}
}

int main()
{
	int a[10];
	reset(a,10);
	cout<<find(a,4)<<"\n";
	for(int i=0; i<10; i++) cout<<a[i]<<" ";
	cout<<"\n";
	Union(a,3,5);
	Union(a,4,8);
	Union(a,8,9);
	Union(a,7,9);
	Union(a,6,8);
	Union(a,1,6);
	Union(a,2,6);
	for(int i=0; i<10; i++) cout<<a[i]<<" ";
	cout<<"\nThe root is : "<<find(a,5);
	return 0;
}

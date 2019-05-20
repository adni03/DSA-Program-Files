// MERGE SORT

#include<iostream>
using namespace std;

void merge(int a[], int m, int l, int h){
	int L[10]={0}, R[10]={0};
	for(int i=0; i<m-l+1; i++){
		L[i]=a[l+i];
	}
	for(int i=0; i<h-m; i++){
		R[i]=a[m+1+i];
	}
	int i=0, j=0, k=l;
	while( i<(m-l+1) && j<(h-m) ){
		if(L[i] <= R[j]){
			a[k++]=L[i++];
		}
		else{
			a[k++]=R[j++];
		}
	}
	while(i < (m-l+1)){
		a[k++]=L[i++];
	}
	while(j < (h-m)){
		a[k++]=R[j++];
	}
}

void Merge_Sort(int a[], int n, int l, int h) {
	if(l < h)
	{
		int mid = (l+h)/2;
		Merge_Sort(a,n,l,mid);
		Merge_Sort(a,n,mid+1,h);
		merge(a,mid,l,h);
	}
}

int main()
{
	int a[7]={38,27,43,3,9,82,10};
	int n=7;
	cout<<"Unsorted array : ";
	for(int i=0 ; i<n ; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\nSorted array : ";
	Merge_Sort(a,n,0,n-1);
	for(int i=0 ; i<n ; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

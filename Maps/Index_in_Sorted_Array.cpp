// INDEX OF ELEMENTS IN THE SORTED ARRAY

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Index(int a[], int n){
	map<int,int> sort;
	map<int,int> final;
	map<int,int> :: iterator itr;
	int i=0;
	for(int i=0; i<n; i++){
		sort.insert(make_pair(a[i],i));
	}
	cout<<"Sorted array with index : \n";
	cout<<"ELEMENT\tINDEX\n";
	for(itr=sort.begin(), i=0; itr!=sort.end(), i<n; itr++, i++){
		cout<<itr->first<<"\t"<<i<<"\n";
	}
	for(itr=sort.begin(), i=0; itr!=sort.end(); itr++, i++){
		final.insert(make_pair(itr->second,i));
	}
	cout<<"The index of array element in the sorted array is : \n";
	cout<<"ELEMENT\tINDEX\n";
	for(itr=final.begin(), i=0; itr!=final.end(), i<n; itr++, i++){
		cout<<a[i]<<"\t"<<itr->second<<"\n";
	}
}

int main()
{
	int a[5]={2,33,6,92,1};
	cout<<"Unsorted array with index : \n";
	cout<<"ELEMENT\tINDEX\n";
	for(int i=0; i<5; i++){
		cout<<a[i]<<"\t"<<i<<"\n";
	}
	Index(a,5);
	return 0;
}

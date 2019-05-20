//MAPS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Max_Freq(int a[], int n){
	map<int,int> freq;
	int i=0;
	for(int i=0; i<n; i++){
		if(freq.find(a[i])!=freq.end()) freq[a[i]]++;
		else freq.insert(make_pair(a[i],1)); 
	}
	cout<<"NUMBER\tFREQUENCY\n";
	map<int,int>::iterator itr;
	for(itr=freq.begin(); itr!=freq.end(); itr++){
		cout<<itr->first<<"\t"<<itr->second<<"\n";
	}
}

int main()
{
	int a[10]={8,8,7,7,7,9,9,9,9,10};
	cout<<"The frequencies of the numbers in the array are: \n";
	Max_Freq(a,10);
	return 0;
}

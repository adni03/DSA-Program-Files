// QUADRAPLES PROBLEM

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Quad(int a1[], int a2[], int a3[], int a4[], int n1, int n2, int n3, int n4){
	map<int,int> tu;
	map<int,int> :: iterator i, j;
	int sum=0, cnt=0;
	cout<<"Enter sum : ";
	cin>>sum;
	for(int i=0; i<n1; i++){
		for(int j=0; j<n2; j++){
			if(tu.find(a1[i]+a2[j])!=tu.end()) tu[a1[i]+a2[j]]++;
			else tu.insert(make_pair(a1[i]+a2[j],1));
		}
	}
	for(int i=0; i<n3; i++){
		for(int j=0; j<n4; j++){
			if(tu.find(sum-(a3[i]+a4[j]))!=tu.end()) cnt+=tu[sum-(a3[i]+a4[j])];
		}
	}
	cout<<"Quadaples : "<<cnt;
}

int main()
{
	int a1[4] = {1,4,5,6}; 
    int a2[4] = {2,3,7,8}; 
    int a3[4] = {1,4,6,10}; 
    int a4[4] = {2,4,7,8};
    cout<<"The arrays are : \n";
    cout<<"A1 : ";
    for(int i=0; i<4; i++) cout<<a1[i]<<" ";
    cout<<"\n";
    cout<<"A2 : ";
    for(int i=0; i<4; i++) cout<<a2[i]<<" ";
    cout<<"\n";
    cout<<"A3 : ";
    for(int i=0; i<4; i++) cout<<a3[i]<<" ";
    cout<<"\n";
    cout<<"A4 : ";
    for(int i=0; i<4; i++) cout<<a4[i]<<" ";
    cout<<"\n";
	Quad(a1,a2,a3,a4,4,4,4,4);
	return 0; 
}

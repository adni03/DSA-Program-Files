#include<iostream>
using namespace std;

void print(int n){
	int i=0, j=0;
	for(i=0; i<n; i++){
		for(j=n-i-1; j>=0 ; j--)
			cout<<" ";
		for(j=n-i-1; j<n+1; j++)
			cout<<"#";
		cout<<endl;
	}
}

int main()
{
	cout<<"Pyramid is : \n";
	print(25);
	return 0;
}

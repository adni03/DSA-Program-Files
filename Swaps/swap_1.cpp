//SWAP-1

#include<iostream>
using namespace std;

void swap(int &c, int &d);

int main()
{
	int a=4, b=9;
	cout<<a<<" "<<b<<endl;
	swap(a,b);
	cout<<a<<" "<<b;
	return 0;
}

void swap(int &c, int &d)
{
	int temp;
	temp=c;
	c=d;
	d=temp;
	cout<<c<<" "<<d<<endl;
}

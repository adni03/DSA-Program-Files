//SWAP-3

#include<iostream>
using namespace std;

void swap(int *c, int *d);

int main()
{
	int a=5, b=6;
	cout<<a<<" "<<b<<endl;
	swap(&a,&b);
	cout<<a<<" "<<b;
	return 0;
}

void swap(int *c, int *d)
{
	*c = *c + *d;
	*d = *c - *d;
	*c = *c - *d;
	cout<<*c<<" "<<*d<<endl;
}

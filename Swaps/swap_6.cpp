//SWAP-6

#include<iostream>
using namespace std;

void swap(int *c, int *d);

int main()
{
	int a=4, b=9;
	cout<<a<<" "<<b<<endl;
	swap(&a,&b);
	cout<<a<<" "<<b;
	return 0;
}

void swap(int *c, int *d)
{
	*c = *c * *d;
	*d = *c / *d;
	*c = *c / *d;
		
	cout<<*c<<" "<<*d<<endl;
}

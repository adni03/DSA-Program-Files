#include<iostream>
using namespace std;

void input(int* a, int* b)
{
	cout<<"\nEnter number: ";
	cin>>*a>>*b;
}
void output(int* a, int* b)
{
	cout<<*a<<" "<<*b;
}

int main()
{
	int p,q;
	int *a, *b;
	a=&p;
	b=&q;
	input(a,b);
	cout<<p<<" "<<q;
	output(a,b);
	cout<<p<<" "<<q;
	return 0;
}
	

#include<iostream>
using namespace std;

int OR(int* q, int* w);
int AND(int* q, int* w);

int x,y;

int main()
{
	int *a, *b;
	cout<<"\nEnter the numbers : ";
	cin>>x>>y;
	a=&x;
	b=&y;
	cout<<"\n"<<OR(a,b);
	cout<<"\n"<<AND(a,b);
	return 0;	
}
int OR(int* p, int* q)
{
	if(*p || *q)
		return 1;
	else 
		return 0;
}
int AND(int* p, int* q)
{
	if(*p && *q)
		return 1;
	else
		return 0;
}


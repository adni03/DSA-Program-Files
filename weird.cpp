//triangle of numbers

#include<iostream>
using namespace std;

void print(int n);

int main()
{
	int a;
	cout<<"\nENTER SIZE : ";
	cin>>a;
	print(a);
	return 0;
}

void print(int n)
{
	int i=0, j=0;
	for(i=0; i<n; i++)
	{
		for(j=n-1-i; j>0; j--)
		{
			cout<<"  ";
		}
		for(j=1; j<=i+1; j++)
		{
			cout<<j<<" ";
		}
		if(i!=0)
		{
			for(j=i; j>0; j--)
			{
				cout<<j<<" ";
			}	
		}
		cout<<endl;
	}
}

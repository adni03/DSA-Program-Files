#include<iostream>
using namespace std;

void letter(int n);

int main()
{
	int n;
	cout<<"\nEnter size : ";
	cin>>n;
	letter(n);
	return 0;
}

void letter(int n)
{
	int i=0, j=0;
	for(i=0; i<n; i++)
	{
		cout<<"O";
		if(i!=0)
		{
			if((2*i)-1 != n)
			{
				for(j=1; j<i; j++)
				{
					if(j != i)
					{
						cout<<" ";
					}
				}
				cout<<"O";
			}
			else
			{
				for(j=1; j<i; j++)
					cout<<" ";
				cout<<"O";
				for(j=1; j<i; j++)
					cout<<" ";
			}
		}
		if((2*i)-1 != n)
		{
			for(j=n; j>2*i; --j)
				cout<<" ";
		}
		if(i!=0)
		{
			if((2*i)-1 != n)
			{
				cout<<"O";
				for(j=1; j<i; j++)
				{
					if(j!=i)
					{
						cout<<" ";
					}
				}
			}
		}
		cout<<"O";
		if((2*i)-1 == n)
			break;
		cout<<endl;
	}
}

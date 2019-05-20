#include<iostream>
using namespace std;

void pallindromechk();

char a[50];
int n;

int main()
{
	cout<<"\nEnter order: ";
	cin>>n;
	for(int i=0; i<50; i++)
	{
		cin>>a[i];
	}
	pallindromechk();
	return 0;
}

void pallindromechk()
{
	char ch[50];
	int flag=-1;
	for(int i=0; i<=(50-n); ++i)
	{
		for(int j=i; j<(n+i); ++j)
		{
			ch[j-i]=a[j];
		}
		for(int j=0; j<n/2; j++)
		{
			if(ch[j]!=ch[n-1-j])
			{
				flag=0;
				break;
			}
			else
				flag=1;		
		}
		if(flag==1)
		{
			cout<<ch<<endl;
		}
	}
}

#include<iostream>
using namespace std;

void convert(char c[]);

int main()
{
	char time_12[10];
	cin>>time_12;
	convert(time_12);
	return 0;
}

void convert(char t12[])
{
	char ch;
	int h1, h2, hh;
	h1 = char(t12[0]) - '0';
	h2 = char(t12[1]) - '0';
	hh = char(h1)*10 + char(h2);

	if(t12[8] == 'A')
	{
		if(hh == 12)
		{
			cout<<"00";
			for(int i=2; i<8; i++)
				cout<<t12[i];	
		}
		else 
		{
			for(int i=0; i<8; i++)
			{
				cout<<t12[i];
			}
		}
	}
	else 
	{
		if(hh == 12)
		{
			cout<<"12";
			for(int i=2; i<8; i++)
			{
				cout<<t12[i];
			}
		}
		else
		{
			hh+=12;
			cout<<hh;
			for(int i=2; i<8; i++)
				cout<<t12[i];
		}
	}
	
}

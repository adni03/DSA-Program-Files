#include<iostream>
#include<math.h>
using namespace std;

void dec_base(int num, int base);

int main()
{
	int num, base;
	cout<<"\nEnter the number : ";
	cin>>num;
	cout<<"\nEnter base (2 or 8 or 16) : ";
	cin>>base;
	dec_base(num,base);
	return 0;
}

void dec_base(int num, int base)
{
	int power=0, i;
	char c[10];
	for(;pow(base,power)<num; power++);
	for(i=power-1; i>-1; i--)
	{
		if(num%base > 9)
		{
			switch(num%base)
			{
				case 10: c[i]='A'; break;
				case 11: c[i]='B'; break;
				case 12: c[i]='C'; break;
				case 13: c[i]='D'; break;
				case 14: c[i]='E'; break;
				case 15: c[i]='F'; break;
			}
		}
		else
			c[i] = num%base + '0';
		num/=base;
	}
	cout<<"\nThe number is : ";
	for(i=0; i<power; i++)
	{
		cout<<c[i];
	}
}

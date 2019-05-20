#include<iostream>
#include<math.h>
using namespace std;

void dec_hex(int num);

int main()
{
	int num;
	cout<<"\nEnter the number : ";
	cin>>num;
	dec_hex(num);
	return 0;
}

void dec_hex(int num)
{
	int power=0, i=0, n=0;
	char hex[10];
	for( ;pow(16,power)<num; )
		power++;
	cout<<"\nPower is : "<<power<<endl;
	for(i=0; i<power; i++)
	{
		if(num>pow(16,power-1-i))
		{
			if(num<16 && num>10)
			{
				switch(num)
				{
					case 10: hex[i]=char(17+num);
								break;
						
					case 11: hex[i]=char(17+num);
								break;
								
					case 12: hex[i]=char(17+num);
								break;
								
					case 13: hex[i]=char(17+num);
								break;
								
					case 14: hex[i]=char(17+num);
								break;
								
					case 15: hex[i]=char(17+num);
								break;
					default : break;
					cout<<hex[i]<<endl;
				}
			}
			else
			{	
				n = (num/pow(16,power-1-i));
				cout<<n<<endl;
				hex[i] = char(n+48);
				cout<<char(n+48);
				num-= n*pow(16,power-1-i);
				cout<<num<<endl;
			}
		}
		else if(num<pow(16,power-1-i) && num>16)
		{
			hex[i]='0';
		}
	}
	cout<<"\nThe number in Hexadecimal is :";
	for(i=0; i<power; i++)
	{
		cout<<hex[i];
	}
}

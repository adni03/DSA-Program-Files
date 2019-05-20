#include<iostream>
#include<string.h>
using namespace std;

struct athlete
{
	int gmedal, smedal, bmedal, sum, flag;
	char name[20], country[30];
}s[20];

int main()
{
	int i=0, pos=0, small=0, c[20], add=0, f=0, size=0;
	cout<<"\nEnter the number of atheles : ";
	cin>>size;
	cout<<"\nEnter the details of the athletes : ";
	for(i=0; i<size; i++)
	{
		cout<<"\nName : ";
		cin>>s[i].name;
		cout<<"\nCountry : ";
		cin>>s[i].country;
		cout<<"\nNumber of gold, silver and bronze medals in that order : ";
		cin>>s[i].gmedal>>s[i].smedal>>s[i].bmedal;
		s[i].sum=s[i].bmedal+ s[i].gmedal+s[i].smedal;
	}
	for(i=0; i<size; i++)
	small=s[0].gmedal;
	{
		if(s[i].gmedal>small)
		{
			small=s[i].gmedal;
			pos=i;
		}
	}
	cout<<pos;
	cout<<"\nThe athlete with the most number of gold medals is : ";
	cout<<s[pos].name;
	for(i=0; i<size; i++)
	{
		f=0;
		for(int j=i; j<size; j++)
		{
			if(strcmpi(s[i].country, s[j].country)==0 && s[j].flag!=1)
			{
				add+=s[j].sum;
				s[j].flag=1;
				small=1;
			}
		}
		if(small==1)
		{
			c[i]=add;
			pos++;
		}
	}
	small=c[0];
	for(i=0; i<pos; i++)
	{
		if(c[i]<small)
		{
			small=c[i];
			f=i;
		}
	}
	cout<<"\nThe country with most number of medals is : "<<s[f].country;
	return 0;
}

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{
	char string[100], chk[30], subs[30], copy[30];
	int cnt=0, i, n1, n2, n, j, k, l, pos, flag=0;;
	
	cout<<"\nEnter the main string : ";
	cin.getline(string,100);
	n=strlen(string);
	cout<<"\nEnter the string that you want to replace : ";
	cin.getline(chk,30);
	n1=strlen(chk);
	cout<<"\nEnter the replacement : ";
	cin.getline(subs,30);
	n2=strlen(subs);
	if(n2<n1)
		flag=-1;
	
	for(i=0; i<(n-n1+1); i++)    //responsible for character movement 
	{
		for(j=i; j<(n1+i); j++)   //copies the array into another array
		{
			copy[j-i] = string[j];
			pos=j;
		}
		if( strcmpi(copy,chk) == 0 )   //compares to see if it is a match
		{
			cnt++;
			if(flag==0)
			{
				for(k=n; k>pos; k--)    //creates space essentially
				{
					string[(n2-n1)+k] = string[k];
					n++;
				}
				for(k=(pos-n1+1), l=0; k<=(pos-n1+n2), l<n2; k++, l++)   //replaces the old sub-string with the new one
				{
					string[k] = subs[l];
				}
			}
			else if(flag==-1)
			{
				for(k=pos; k>=(pos-n1); k--)
				{
					string[k-(n2-n1)] = string[k];
					n--;
				}
				for(k=(pos-n1+1), l=0; k<=(pos-n1+n2), l<n2; k++, l++)   //replaces the old sub-string with the new one
				{
					string[k] = subs[l];
				}
			}
		}
	}
	cout<<"\nThe new string is : "<<string;
	cout<<"\nThe number of substrings is : "<<cnt;
	return 0;
}

#include <iostream>
using namespace std;

int bcimhappy(int a);
int n;

int main() 
{
    int ch;
    cin>>ch;
    while(ch>0)
    {
	    cin>>n;
	    cout<<bcimhappy(n+1);
	    --ch;
    }
	return 0;
}

int bcimhappy(int a)
{
    int digit=0, p=0, copy=0;
    static int cnt, mul;
    copy=a;
    for(;copy>0;)
    {
        digit=copy%10;
        p+=digit*digit;
        copy/=10;
    }
    if(p==1)
        return a;
    else if(p!=1 && cnt<5*mul)
    {
        cnt++;
        return bcimhappy(p);
    }
    else
    {
    	mul++;
		return bcimhappy(n+mul);
	}
}

#include<iostream>
using namespace std;

int birthdayCakeCandles(long a, long b[]);

int main()
{
    long x, y[100000], i=0;
    cin>>x;
    for(i=0; i<x; i++)
    {
        cin>>y[i];
    }
    cout<<birthdayCakeCandles(x,y);
    return 0;
}
int birthdayCakeCandles(long a, long b[])
{
    int i=0, j=0, dummy, cnt=0;
    dummy = b[0];
    for(i=0; i<a; i++)
    {
        if(b[i] > dummy)
            dummy = b[i];
        else
            continue;
    }
    for(i=0; i<a; i++)
    {
        if(dummy == b[i])
            cnt++;
    }
    return cnt;
}

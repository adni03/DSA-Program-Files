// PERMUTATIONS AND COMBINATIONS

#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void permute(int ch[], int l, int h){
	if(l==h){
		for(int i=0; ch[i]!='\0'; i++) cout<<ch[i]<<" ";
		cout<<"\n";
	}
	else{
		for(int i=l; i<=h; i++){
			swap(ch[l],ch[i]);
			permute(ch,l+1,h);
			swap(ch[l],ch[i]);	
		}
	}
}

int main()
{
	int ch[3]={1,2,3};
	cout<<"Permutations are : \n";
	permute(ch,0,2);
	return 0;
}

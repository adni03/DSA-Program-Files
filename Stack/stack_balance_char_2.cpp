#include<iostream>
#include<string.h>
using namespace std;

struct stack{
	char c[20];
	int top, size;
};

void push(stack &m, char x){
	if(m.top == m.size-1) cout<<"Overflow";
	else{
		m.c[++m.top]=x;
	}
}

char pop(stack &m){
	if(m.top == -1) cout<<"Underflow";
	else return m.c[m.top--];
}

int isEmpty(stack &m){
	if(m.top == -1) return 1;
	else return 0;
}

int balanced(stack m, char ch[],int n){
	for(int i=0; i<n; i++){
		if(ch[i] == '{') push(m,ch[i]);
		else{
			if(isEmpty(m)) return 0;
			else pop(m);
		}
	}
	if(isEmpty(m)) return 1;
	else return 0;
}

int main()
{
	stack m; m.top=-1; m.size=20;
	char ch[]={'{','{','{','}','{','}','}','}','}'};
	int n=9;
	if(balanced(m,ch,n)) cout<<"Balanced!";
	else cout<<"Unbalanced!";
	return 0;
}

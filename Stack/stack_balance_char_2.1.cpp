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

int isBraket(char x){
	if(x == '{' || x == '(' || x == '[' || x == '}' || x == ')' || x ==']') return 1;
	else return 0;
}

char death(char ch){
	char x;
	if(isBraket(ch)) x=ch;
	else x='q';
	switch(x){
		case '}' : return '{';
		case ']' : return '[';
		case ')' : return '(';
		case 'q' : return ch;
		default : return '\0';
	}
}

int balanced(stack m, char ch[], int n){
	for(int i=0; i<n; i++){
		if(isEmpty(m)) push(m,ch[i]);
		else{
			char a = death(ch[i]);
			if(a == '\0') push(m,ch[i]);
			else{
				char b = pop(m);
				if(a == b);
				else{
					push(m,b);
					push(m,a);
				}
			}
		}
	}
	if(isEmpty(m)) return 1;
	else return 0;
}

int main()
{
	stack m; m.top=-1; m.size=20;
	char ch[]={'{','(','[',']',')','}','a','a','a','{','}'};
	int n=11;
	if(balanced(m,ch,n)) cout<<"Balanced!";
	else cout<<"Unbalanced!";
	return 0;
}

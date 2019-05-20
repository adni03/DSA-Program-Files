//5(D)

#include<iostream>
#include<ctype.h>
using namespace std;

int check_tree(char ch[]){
	int count=1;
	for(int i=0; ch[i]!='\0'; i++){
		if(isalpha(ch[i])) count=count-1+2;
		else if(ch[i]=='#') --count;
	}
	if(count==0) return 1;
	else return 0;
}

int main()
{
	char c[]={'A','J','R','T','#','#','S','#','#','#','M','#','P','Q','#','#','#'};
	if(check_tree(c)==1) cout<<"Correct!";
	else cout<<"Nope, mate";
	return 0;
}

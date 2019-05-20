//TARGET V_2

#include<iostream>
#include<string.h>
using namespace std;

struct node{
	char data;
	struct node *next[10];
	int num;
};

typedef struct node *MLPTR;

MLPTR insert(MLPTR &L, char c[]){
	static int i=0;
	if(c[i]!='\0'){
		if(c[i]=='{'){
			int n=0;
			L=new(node);
			L->data=c[++i];
			L->num=++n;
			++i;
			L->next[L->num-1]=insert(L->next[L->num-1],c);
			return L;
		}
		else if(c[i]=='}'){
			++i;
			return NULL;
		}
		else{
			L=new(node);
			L->data=c[i];
			if(c[i+1]!='{'){
				L->num=0;
				++i;
				L->next[0]=insert(L->next[0],c);
				return L;
			}
			else{
				int n=0;
				++i;
				L->num=++n;
				L->next[L->num-1]=insert(L->next[L->num-1],c);
				return L;
			} 
		}
	}
}



MLPTR insert_2(MLPTR &L, int i){
	if(i!=-1){
		static int ch=0;
		L=new(node);
		cout<<"Routes : ";
		cin>>L->num;
		
		}
		return L;
	}
	else
		return NULL;
}

int find_path(MLPTR T, char c, char a[], int i){
	if(T){
		if(T->data==c){
			a[++i]=c; return 1;
		}
		else{
			a[++i]=T->data;
			if(T->num==1){
				if(find_path(T->next[0],c,a,i)==1)
					return 0;
			}
			else{
				for(int j=0; j<T->num; j++){
					if(find_path(T->next[j],c,a,i)==1) break;
				}
			}
		}
	}
}

int main()
{
	MLPTR L=NULL;
	char a[]={'a','b','c','d','{','e','}','{','f','}','{','g','}'};
	char b[]={'a','b','c'};
	char ab[10], ch;
	//L=insert(L,a);
	//cout<<L->data;
	L=insert_2(L,0);
	cout<<"Enter destination : ";
	cin>>ch;
	find_path(L,ch,ab,-1);
	cout<<"Path is : ";
	for(int i=0; i<strlen(ab); i++)
		cout<<ab[i]<<" ";
	return 0;
}

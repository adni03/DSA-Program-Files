//Tries

#include<iostream>
#include<cstring>
using namespace std;

const int lang=3;

union u{
    char data[50];
    struct tnode * ptr[lang+1];
};

struct tnode{
    int tag;
    union u un;
};

typedef struct tnode* TRPTR;

TRPTR create(TRPTR &R, char ch[], int &i, char temp[], int flag=0){
	if(ch[i]!='\0'){
		if(!R){
			R=new(tnode);
			TRPTR T=new(tnode);
			R->tag=1;
			T->tag=0;
			for(int j=0; j<=lang; j++) R->un.ptr[j]=NULL;
			strcpy(T->un.data,ch);
			R->un.ptr[ch[i] - 'a'] = T;
			if(flag){
				TRPTR P=new(tnode);
				P->tag=0;
				strcpy(P->un.data,temp);
				R->un.ptr[temp[i]-'a']=P;
			}
			return R;
		}
		else{
			if(R->tag==0){ //string node
				char x[20];
				strcpy(x,R->un.data);
				R=NULL; i++;
				R=create(R,ch,i,x,1);
				return R;
			}
			else{
				TRPTR X=R->un.ptr[ch[i]-'a'];
				X=create(X,ch,i,temp,flag);
				R->un.ptr[ch[i]-'a']=X;
				return R;
			}
		}
	}
	return R;
}

void print(TRPTR T){
    if(T){
        if(T->tag){
            for(int i=0; i<=lang; i++){
            	if(T->un.ptr[i]) print(T->un.ptr[i]);	
			}
        }
        else{
            cout<<T->un.data<<" ";
        }   
    } 
}

int main(){
    TRPTR R=NULL;
    char temp[10];
    int i=0;
    char c[6][6]={{"aab"},{"abbbc"},{"baa"},{"bccaa"},{"bc"},{"cabb"}};
    for(int j=0; j<6; j++){
    	R=create(R,c[j],i,temp);
	    print(R);
	    cout<<"\n";
	    i=0;
	}
    return 0;
}

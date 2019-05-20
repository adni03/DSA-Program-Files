//Tries

#include<iostream>
#include<cstring>

using namespace std;

int lang=3;

struct trnode{
    int tag;
    union u{
        char data[50];
        struct trnode * ptr[4];
    }un;
};

typedef struct trnode * trptr;

int i=0;
trptr create(trptr Root, trptr &T, char key[], char temp[]){
    char ch=key[i];
    if (ch!='\0'){
        if (!T){
            trptr P,K=NULL;
            
            T=new(trnode);
            T->tag=1;
            for (int k=0; k<lang+1; k++)
                T->un.ptr[k]=NULL;
            P=T->un.ptr[int(ch)-97]=new(trnode);
            P->tag=0;
            
            strcpy(P->un.data,key);
            
            
            if (temp!="0"){
                char c=temp[i];
                K=T->un.ptr[int(c)-97];
                if (K){
                    K=T->un.ptr[lang]=new(trnode);
                    K->tag=0;
                    strcpy(K->un.data,temp);
                }
                else{
                    K=new(trnode);
                    K->tag=0;
                    strcpy(K->un.data,temp);
                    T->un.ptr[int(c)-97]=K;
                }
            }
        }
        else{
            if(T->tag){
                trptr P=T->un.ptr[int(ch)-97];
                i++;
                P=create(Root,P,key,temp);
                T->un.ptr[int(ch)-97]=P;
                return T;
            }
            else{
                //if its a string node
                char tempo[50];
                strcpy(tempo,T->un.data);
                T=NULL;
                T=create(Root,T,key,tempo);
            }
        }
    }
    return T;
}


void print(trptr T){
    
    if (T){
        if (T->tag){
            //cout<<T->tag<<endl;
            for (int i=0; i<lang+1; i++) print(T->un.ptr[i]);
        }
        else{
            int j=0;
            while (T->un.data[j]!='\0'){
                cout<<T->un.data[j];
                j++;
            }
            cout<<" ";
        }
        
    }
    
}


int main(){
    trptr T;
    T=NULL;
    char c[6][6]={{"aab"},{"abbbc"},{"baa"},{"bccaa"},{"bc"},{"cabb"}};
    for(int j=0; j<6; j++){
    	//create(T,c[j],i,temp);
    	T=create(T,T,c[j],"0");
	    print(T);
	    cout<<"\n";
	    i=0;
	}
	return 0;
}

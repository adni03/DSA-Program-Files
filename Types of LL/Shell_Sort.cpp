// Shell Sort

#include<iostream>
using namespace std;

/*void Shell_Sort(int a[], int n){
	int gap=n/2, min=62000, pos=0;
	while(gap>0)
	{
		for(int i=0; gap+i < n; i++){
			if(a[i] > a[gap+i]){
				int temp=a[i];
				a[i]=a[gap+i];
				a[gap+i]=temp;
				for(int j=i; j>=gap && a[j] < a[j-gap]; j-=gap){
					int temp=a[j];
					a[j]=a[j-gap];
					a[j-gap]=temp;
				}	
			}
		}
		gap=gap/2;
	}
}*/

void Shell_Sort(int a[], int n){
	int gap=n/2, min=62000, pos=0;
	while(gap>0)
	{
		for(int i=0; gap+i < n; i++){
			if(a[i] > a[gap+i]){
				int temp=a[i];
				a[i]=a[gap+i];
				a[gap+i]=temp;	
			}
			else{
				for(int j=i+gap; j>=gap && a[j] > a[j-gap]; j-=gap){
					int temp=a[j];
					a[j]=a[j-gap];
					a[j-gap]=temp;
				}
			}
		}
		gap=gap/2;
	}
}

int main()
{
	int a[12]={38,27,43,3,9,82,10,1,56,8,63,12};
	int n=12;
	cout<<"Unsorted array : ";
	for(int i=0 ; i<n ; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\nSorted array : ";
	Shell_Sort(a,n);
	for(int i=0 ; i<n ; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

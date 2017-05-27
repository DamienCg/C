#include <iostream>
using namespace std;
/*

 */
 
int Partition(int*A,int p,int r){
	int x=A[r-1];
	int i=p-1;
	
	for(int j=p; j<r-1; j++){
		if(A[j]<=x){
			i++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	
	int temp=A[i+1];
	A[i]=A[r];
	A[r]=temp;
	return i+1;
}


void QuickSort(int*A,int p,int r){
	if(p<r){
	 int q=Partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
}

main(){
int A[10]={33,1,0,-15,1,54,3,12,99,-1};
int n=10;

QuickSort(A,0,n);

for(int i=0; i<10; i++)
cout<<A[i]<<" ";

}

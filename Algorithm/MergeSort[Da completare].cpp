#include <iostream>
using namespace std;
/*
  Insertion Sort si divide in 2 parti:
  
 
 */
 
void Merge(int*A,int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1];
	int R[n2];
	
	for(int i=0; i<n1; i++)
	{L[i]=A[p+i-1];}
	
		
	for(int j=0; j<n2; j++)
	{R[j]=A[q+j];}
		
	int i=0;
	int j=0;
	
	for(int k=p; k<=r; k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i=i+1;
		}
		else{
			A[k]=R[j];
			j=j+1;
		}
	}
}
 
void MergeSort(int*A,int p,int r){
	
	if(p<r){
		int q=(p+r)/2; //arrotondamento per difetto
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
	
}

main(){
int A[10]={33,1,0,-15,1,54,3,12,99,-1};
int r=10;


	MergeSort(A,0,r);


for(int i=0; i<10; i++)
cout<<A[i]<<" ";

}

// Example program
#include <iostream>
#include <string>
using namespace std;

int Partition(int *A,int p,int r){
    int x=A[r];
    int i=p-1;
    
    for(int j=p; j<r-1; j++){
        if (A[j]<x){
         i++;
         int temp=A[i];
         A[i]=A[j];
         A[j]=temp;
        }
    }
     int temp=A[i+1];
         A[i+1]=A[r];
         A[r]=temp;
         
         return i+1;
}

void Quicksort (int*A,int p,int r){  // Complessità massima      
 if(p < r){          
 int q= Partition(A,p,r);         
 Quicksort(A,p,q-1);        
 Quicksort(A,q+1,r);
 }
}

int main(){
    int A[10]={3,4,1,7,9,8,5,2,10,6};
    Quicksort(A,0,9);
    for(int i=0; i<10; i++)
    cout<<A[i]<<" ";
}

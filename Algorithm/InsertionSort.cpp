#include <iostream>
using namespace std;
/*
  Insertion Sort si divide in 2 parti:
  
  1)-La prima parte Scorre (con J) dal secondo elemento 
	 dell'Array fino al suo ultimo, e associa ad ogni 
	 iterazione una key che conserva elemento corrente di j,
	 i invece sarà elemento precedente.
  
  2)-La seconda parte se l'elemento precedente alla Key è
     maggiore della Key (Ciè se ci sono elementi maggiori che stanno dietro la key)
     allora gli elementi maggiori vengono slittati avanti e la key prende il posto
     dietro di essi, assicurando Invariante che a sinistra della Key gli elementi sono sempre
     ordinati.
 */

void InsertionSort(int *A, int n){
    for(int j=1; j<n; j++){
        int key=A[j];
        int i=j-1;
        
        while(i>=0 && A[i]>key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}

void F(int* A,int j,int key){
    if(j>=0 && A[j]>key){
        A[j+1]=A[j];
        F(A,j-1,key);
    }
    else
    A[j+1]=key;
}

void InsertionSortRicorsivo(int *A,int n){
    if(n>1){
     InsertionSortRicorsivo(A,n-1);
     int key=A[n-1];   
     int j=n-2;
     F(A,j,key);
    }
}

main(){
int A[10]={33,1,0,-15,1,54,3,12,99,-1};
int n=10;

/*
	InsertionSort(A,n);
	InsertionSortRicorsivo(A,n);
*/

for(int i=0; i<10; i++)
cout<<A[i]<<" ";

}

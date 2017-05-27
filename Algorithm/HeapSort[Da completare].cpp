#include<iostream>
using namespace std;

/*
 Un Max Heap è un albero dove ciascun nodo (I) ha una chiave >= a tutte le chiavi
 del sottoalbero radicato in (I). 
	
			 9
			/ \
		   8   7
				\
				 4
 */

struct nodo{int key; nodo*left; nodo*right; nodo(int a=0,nodo*b=0,nodo*c=0) {key=a; left=b; right=c;} };

void Max_HeapiFY(int*A,int i,int size){
	
	
}

void Build_Max_Heap(int*A,int size){
	for(int i=size/2; i--)
	Max_HeapiFY(A,i,size);
}

int main(){
	int A[10];
	
	Build_Max_Heap(A,10);
	
	return 0;
}

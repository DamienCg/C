#include<iostream>
using namespace std;

main(){
	int dimA;
cin>>dimA;
int A[dimA];
for(int i=0; i<dimA; i++)
cin>>A[i];

 for (int i=0; i<dimA/2; i++) {
 int tmp = A[i];
  A[i]=A[dimA-1-i];
  A[dimA-1-i]=tmp;
 }

for(int i=0; i<dimA; i++)
cout<<A[i]<<" ";
cout<<endl;

}
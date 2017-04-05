#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo* x)
{
 if(x)
 {cout<<x->info<<' '; stampa(x->next);}
 else
  cout<<endl;
}

nodo*F(int n_el){
	if(!n_el)
	 return 0;
	 
	 int a;cin>>a;
	 return new nodo(a,F(n_el-1));
}

nodo* A(nodo*&Q, int k,int z, int& ck){
	
	if(!Q){ //eseguito solo una volta all ultimo nodo.
		if(ck >= k)
		{ck=k; return 0;} // ck indica quanti nodi bisogna staccare ancora
		
		
	  else{ ck=0; return 0;} // altrimenti non c'e' nulla da staccare
	}

if(Q->info == z){
  ck++; 
  
	nodo*r= A(Q->next, k, z, ck);	
	
     if(ck > 0){ 
	    nodo*a=Q; 
	    Q=Q->next; 
	    a->next=r;//importante capire!
	    //creo una lista r ogni volta aggiungo in testa a R nodo che stacco! 
	     ck--; 
	     return a;
	}
  return r;
} 
	else 
	 return A(Q->next, k, z, ck); // se non e' un nodo interessato dallo staccamento non ci interessa cosa ritorna
}

int main()
{
 int n_el, k, z, ck=0;
 cin>>n_el>>k>>z;
 nodo* x=F(n_el);//esercizio 0 11/5
 cout<<"lista originale= ";
 stampa(x);
 nodo*y=A(x,k,z,ck);//da fare 
 cout<<"nodi staccati= ";
 stampa(y);
 cout<<"lista originale con i nodi staccati= ";
 stampa(x);
 cout<<"end"<<endl;
 
 return 0;
}
#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next;nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo*x){
	if(!x)
	 return;
	 
	cout<<x->info<<"-";
	stampa(x->next);
}

nodo*ins_end(nodo*a,nodo*Q)
{
 if(!a) 
 {Q->next=0; return Q;}
 
 a->next=ins_end(a->next,Q); 
 return a;
}
//Scorro a, ed inserisco alla fine Q.

//PRE=(L(Q) lista corretta)
nodo* G(nodo* Q){
	
if(!Q) 
return 0;

nodo* a=G(Q->next); //arrivo alla fine!
nodo*b=ins_end(a,Q); //inserisco alla fine di a, Q.
return b;
}
//POST=(restituisce L(Q) rovesciata)

nodo*F(int n_el){
	if(!n_el)
	 return 0;
	 
	 else{
	 int a; cin>>a;
	 return new nodo(a,F(n_el-1));
	}
}


 main()
{
	int n_el;
	cin>>n_el;
	nodo*a=F(n_el);
	stampa(a);
	cout<<endl;
	nodo* X=G(a);
	stampa(X);
	cout<<endl;
}

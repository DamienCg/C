#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* G(nodo*x){
	//PRE=(riceve lista x contenente >=0 elementi)
	//primo nodo diventa ultimo e puntatore salvato!
	if(!x||!x->next)//se lista contiene 0 o 1 elemnti mi fermo!
	return x;
   
   nodo *coda = 0;//coda della lista
   if((x->next)->next) //se NON sono al penultimo nodo AVANZO!
      coda = G(x->next);
 
   else //sono al penultimo nodo
      coda = x->next;
   
   (x->next)->next = x; //il 2° nodo avanti punterà al nodo corrente!
   x->next = 0;  //se sono il primo, il mio campo next dovrà diventare 0,
                        //se non sono il primo ci penseranno gli altri con il backtracking a sistemarmi
   return coda;

}/*
Scorro fino al penultimo nodo, 
* raggiungo penultimo e 
un puntatore coda punterà a ultimo nodo
ed esso diventerà il primo nodo della lista,
al ritorno, 
quindi torno indietro di 1 e il terzultimo nodo
puntera al 4 ultimo
ritorno
e il 5° ultimo punterà al 6°ultimo ecc ecc
ogni ritorno il puntatore corrente punterà a zero, ma poi verra re-inizializzato
e punterà al nodo precedente!
*/
//POST=(Stampa all'incontrario la lista)
nodo* F(int n_el){
	//PRE=(riceve n_el>=0, poi esegue n_el letture da cin) 
	if(n_el){//caso base, finchè n_el>0 crea nodo successivo
	int a; cin>>a;
	nodo*x=new nodo(a,F(n_el-1));
	}
	else
	return 0;
}
//POST=crea una lista in base alle letture da cin,
//dove primo elemento di n_el == primo nodo della lista creata e così via.
nodo*F(int n_el){
	if(!n_el)
	 return 0;
	 
	 int a;cin>>a;
	 return new nodo(a,F(n_el-1));
}


void stampa(nodo* x)
{
 if(x)
 {cout<<x->info<<' '; stampa(x->next);}
 
 else
  cout<<endl;
}

main()
{
 int n_el;
 cin>>n_el;
 nodo* x=F(n_el);
 cout<<"x= ";
 stampa(x);
 nodo*y=G(x);
 cout<<"y= ";
 stampa(y);
 cout<<"end"<<endl;
}

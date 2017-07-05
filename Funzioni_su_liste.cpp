#include <iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int x=0,nodo*y=0){info=x; next=y;}};

nodo*del_end(nodo*Q){
	
	if(!Q->next)
	return 0;
	
	Q->next=del_end(Q->next);
	return Q;
	
}//elimina ultimo nodo della lista!

nodo*ins_end(nodo*Q,nodo*x){
	if(!Q){
		x->next=0;
		return x;
	}
	Q->next=ins_end(Q->next,x);
	return Q;
}
//inserisco x alla fine di Q

int del_end2(nodo*&Q){
	if(!Q->next){
	int a=Q->info;
	Q=Q->next;
	return a;
	}
	
	return del_end2(Q->next);
	
}//elimina ultimo nodo della lista, ritorna il campo info del nodo eliminato

nodo*pop(nodo*Q){
	
	if(!Q)
	return 0;
	
	nodo*temp=Q;
	Q=Q->next;
	delete temp;
	return Q;
	
}//elimina primo nodo da una lista, restituendo quello che ne resta

int pop2(nodo*& Q){
	
	if(!Q)
	return -1; //indica che la lista sia vuota, assumiamo valori di Q>=0
	
	nodo*temp=Q;
	Q=Q->next;
	int a=temp->info;
	delete temp;
	return a;
	
}
//elimina primo nodo di Q, restituisce campo info primo nodo.

void stampa(nodo*x){
	
	if(x){
		cout<<x->info<<"-";
		stampa(x->next);	
	}
	cout<<endl;
}

nodo* build(int n){
	
	if(n==0)
	return 0;
	
	int k=0;
	cin>>k;
	
	return new nodo(k,build(n-1));
}

nodo*dealloco(nodo*x,int k){
	if(!x)
	return 0;
	
	if(k!=0){
		nodo*temp=x;
		x=x->next;
		delete temp;
		x=dealloco(x,k-1);
		return x;
	}
	return x;
}//dealloco i primi k nodi di x


nodo*concateno(nodo*x,nodo*y){
	if(!x)
	 return y;
	 
	 else
	 x->next=concateno(x->next,y);
	 
	 return x;
	
}//concateno x e y


nodo*stacco_primi_k_nodi(nodo*&P,int k){

if(!P->next){
  if(k<=0){
		nodo*temp=P;
		P=P->next;
		return temp;
  }
 else
  return 0;
}

nodo*x=stacco_primi_k_nodi(P->next,k-1);

	if(x && k<=0){
		nodo*temp=P;
		P=P->next;
		temp->next=x;
		x=temp;
		return x;
	}	
	else
	return x;
}//P è composta dai primi k nodi
//ritorno la lista composta dai k+1 nodi fino alla fine

int lung(nodo*x,int n){

	if(!x)
	return n;
	
	return lung(x->next,n+1);
}//ritorna n la lunghezza della lista x

nodo*stacco_primi_k_nodi2(nodo*&P,int k){
	
	if(!P || k==0)
	return 0;
	
	nodo*x=0;
	
	if(lung(P,0) >= k){
		nodo*temp=P;
		P=P->next;
		temp->next=x;
		x=temp;
		x->next=stacco_primi_k_nodi2(P,k-1);
		return x;
	}
	return x;
}
// P e composta dai k+1 nodi fino alla fine
// ritorno i primi k nodi


nodo*concatenazione_alternata(nodo*x,nodo*y){
	if(!x && !y)
	 return 0;
	 
	 if(x && !y)
	 return x;
	 
	 if(!x && y)
	 return y;
	 
	 if(!x->next && !y->next || !x->next && y->next){
	 x->next=y;
	 return x;
	 }
	 
	 else{
		nodo*temp=x->next;
		nodo*temp2=y->next;
		x->next=y;
		y->next=temp;
		temp=concatenazione_alternata(temp,temp2);
		return x;
	}
}//concateno x e y x1->y1->x2->y2

//Q è una lista ordinata tipo: 10-9-4-2-0
nodo* ins_ord(nodo*Q,int x){
	
	if(!Q)
	return new nodo(x,0);
	
	if(Q->info <= x)
	return new nodo(x,Q);
	
	Q->next=ins_ord(Q->next,x);
	return Q;
}
//inserisco un nuovo nodo con campo info == x in Q
//Q dopo l inserimento è ordinata

//Q è una lista ordinata tipo: 10-9-4-2-0
void ins_ord2(nodo*&Q,int x){
	
	if(Q){
	
	if(Q->info <= x)
	Q=new nodo(x,Q);
	else
	ins_ord2(Q->next,x);
	
	}
	else
	Q=new nodo(x,0);
}
//inserisco un nuovo nodo con campo info == x in Q
//Q dopo l inserimento è ordinata

nodo*del_ord(nodo*Q,int x){
	
	if(!Q)
	 return 0;
	 
	 nodo*rit=del_ord(Q->next,x);
	 
	 if(Q->info != x){
		 Q->next=rit;
		 rit=Q;
	 }
	 return rit;
}
//eliminano da una lista ordinata, tutti i nodi con campo info == x

void del_ord2(nodo*&Q,int x){
	
	if(Q){
		
		del_ord2(Q->next,x);
		
		if(Q->info == x){
		  nodo*temp=Q;
		  Q=Q->next;
		  delete temp;
		}
	}
}

nodo*del_ord_iter(nodo*Q,int x){
	nodo*rit=0;
	
	while(Q){
		if(Q->info != x){
			nodo*temp=Q;
			Q=Q->next;
			rit=ins_end(rit,temp);
		}
		else
		Q=Q->next;
	}
	return rit;
}

int main(){
int n=8; int k=2;
nodo*x=build(n);
nodo*y=0;


x=del_ord_iter(x,1);

stampa(x);


return 0;
}

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



bool esiste(nodo*Q,int k){
    if(!Q)
    return false;
    
    if(Q->info == k)
    return true;
    else
    return esiste(Q->next,k);
}
//true sse k esiste in Q

//PRE=(L(Q) è una lista corretta e vL(Q)=L(Q))
FIFO tieni_ultimo_ric(nodo*&Q){
    if(!Q)
     return FIFO();
    
    FIFO x=tieni_ultimo_ric(Q->next);//(!)
    if(esiste(Q->next,Q->info)){//allora lo inserisco nella lista da ritornare
        nodo*t=Q;
        Q=Q->next;
        x=push_begin(x,t);
    }
    return x;
}
/*POST=(L(Q) è ottenuta da vL(Q) eliminando i nodi con info ripetuto mantenendo solo l'ultimo nodo per
ciascun campo info e mantenendo l'ordine relativo che questi nodi hanno in vL(Q). Inoltre restituisce un
valore FIFO f tale che f.primo è la lista dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q))
esempio: : sia vL(Q)= 0->1->0->2->1->0->0->2->0, allora vL(Q) deve diventare L(Q) =1->2->0.

Prova induttiva:
Caso base: Q lista vuota, allora ritorno un valore da costruttore FIFO, cioè una lista vuota,
nessun nodo di uguale campo info, regolare =>POST.
Passo induttivo:
Q non è vuota Chiamo ricorsivamente con (!),
al ritorno valuto se il nodo in cui mi trovo è un nodo che è presente in Q->next,
se è presente allora lo aggiungo alla lista da eliminare poichè devo tenere solo gli ultimi nodi
aggiungo Q a x e sposto Q con Q=Q->next, possibile poichè Q è passato come riferimento a puntatore,
quindi tale istruzione cambia il nodo puntato da Q.
alla fine ritorno x che contiene i nodi doppi eliminati da Q, e Q per ipotesi induttiva contiene
gli ultimi campi info (tutti diversi di vQ) =>POST.
*/
 
//stessa cosa di quella sopra.
FIFO tieni_ultimo_iter(nodo*&Q){
    
    FIFO x;
    FIFO y; //nodi doppi
    
    while(Q){
        if(esiste(Q->next,Q->info)){//aggiungo a y
            nodo*t=Q;
            Q=Q->next;
            t->next=0;
            y=push_end(y,t);
        }
        else{
            nodo*t=Q;
            Q=Q->next;
            t->next=0;
            x=push_end(x,t);
        }
    }
    
    Q=x.primo;
    return y;
}
/*POST=(L(Q) è ottenuta da vL(Q) eliminando i nodi con info ripetuto mantenendo solo l'ultimo nodo per
ciascun campo info e mantenendo l'ordine relativo che questi nodi hanno in vL(Q). Inoltre restituisce un
valore FIFO f tale che f.primo è la lista dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q))*/




// PRE = (L è una lista ordinata in modo crescente)
nodo* inserisci_in_ordine(int k, nodo *L){
    if(!L)
     return new nodo(k,0);
     
     if(!L->next && k >= L->chiave){//(1)
         nodo*z=new nodo(k,0);
         L->next=z;
         return L;
     }
     
     if(k >= L->chiave && L->next->chiave >= k){ //(2)
     nodo*z=new nodo(k,L->next);
     L->next=z;
     return L;
     }
     
     if(k <= L->chiave){//(3)
         nodo*z=new nodo(k,L);
         return z;
     }
     
     else//(4)
     L->next=inserisci_in_ordine(k,L->next);
}
// POST = (inserisce k in L mantenendo l'ordine e ritorna la lista aggiornata)
/*
Caso Base:
lista vuota inserisco k e ritorno un nuovo nodo
la lista è corretta e ordinata => POST (OK)
passo induttivo:
lista non vuota, caso 

1: 
sono nel punultimo nodo
k >= L->key
allora inserisco un nuovo nodo z dopo L,
z->next=0
Ritorno L che punta a z, lista ordinata =>POST

2:
k >= key e sapendo grazie al caso 1 che non mi trovo nel penultimo nodo
accedo alla key di L->next, inserendo k (come nuovo nodo) tra L e L->next
ritornando L che punta ad una lista ordinata=>POST

3:
k <= key, k viene posizionato in testa e viene ritornato poichè punta ad una lista corretta.

4:
Passo induttivo:
chiamo ricorsivamente con l istruzione
L->next=Chiamata ricorsiva
da caso base e da 1,2,3 so di per carto che mi verra restituita una lista corretta
e ordinata, quindi L punterà ad essa =>POST
*/

//---------------------------------------------------------------

bool trovamatch(nodo*x,int*p,int dimP){
    
    if(!dimP)
     return true;
    
    if(!x)
     return false;
    
     if(x->info == *p)
      return trovamatch(x->next,p+1,dimP-1);
     
      else
      return false;
}

nodo*inshead(nodo*a,nodo*x){
    if(!a){
        x->next=0;
        return x;
    }
    else
        x->next=a;
    
}//inserisco x in testa ad a


nodo*match(nodo*& n,int*P,int dimP){
    
    if(!n || !dimP)
    return 0;
    
    if(trovamatch(n,P,dimP)){
        nodo*x=n;
        nodo*L2=match(n->next,P+1,dimP-1);//(!)
        n=n->next;
        L2=inshead(L2,x);//(!!)
        return L2;
    }
    
    return match(n->next,P,dimP);
}
/*

POST:
POST=(in L(n) c’è un match CONTIGUO! di P, allora la funzione restituisce col return match(vL(n),P[0..dimP-1]) e
L(n)=resto_mach(vL(n),P[0..dimP-1], se invece non c’è il match allora la funzione restituisce 0 e L(n)=vL(n))

Correttezza:

Caso base:
n lista vuota, OR il match da cercare è nullo.
ritorno 0 =>POST

Passo induttivo:
La chiamata (!) viene effettuata solo se è presente un match,

Andata: 
memorizzo in puntatore x il valore di n,
quindi alla fine delle chiamate in tutti gli stack ancora attivi ci saranno
puntatori x che punteranno a i nodi che sono un match,

Ritorno:
dato che ritorno solo da chiamate contenenti un match, n attuale al ritorno
punterà a gli stessi nodi che punta x, cioè a nodi di match
n=n->next, elimina gli n dalla lista originale, e con la chiamata (!!)
inserisco in testa a L2 tutti i nodi match, creando la lista da restituire con il return.
*/

//--------------------------------------------------------------

nodo*inshead(nodo*L,nodo*x){
    if(!L)
    {x->next=0; return x;}
    else
    x->next=L;
}

/*PRE=(L(T) è corretta, dimP>0, P ha dimP elementi definiti)*/
nodo* match (nodo* & T, int * P, int dimP){
    
    if(!T)
    return 0;
    
    if(dimP==1 && T->info == *P){//(!!)
    nodo*x=T; T=T->next; x->next=0; return x; }
    
    if(T->info == *P){//(!)
        nodo*x=T;
        nodo*L=match(T->next,P+1,dimP-1);
        if(L){
        T=T->next;
        L=inshead(L,x);
        return L;
        }

     }
    else
    return match(T->next,P,dimP);
}
/*POST=(se c’è un match (anche non contiguo) di P in L(T) allora la funzione restituisce col return la lista del match e in T la lista
restante, altrimenti, restituisce 0 col return e T punta alla stessa lista cui puntava all’inizio).
Correttezza:

Caso base:
se !T allora il match non esiste, ritorno 0,
se il match da trovare è li lunghezza 1, allora mi salvo
la posizione dell unico nodo da rimuovere elimino da T (T=T->next) 
mi assicuro che il nodomatch punti a 0 e restituisco x nodomatch

Passo induttivo:
(!) viene eseguito solo se in posizione T esiste un nodo che è uguale a *P,
allora all andata vengono salvati in x, tutti i nodi con campo info uguali a P,
al ritorno il caso base (!!), ci garantisce che se abbiamo trovato il match completo
allora L sarà uguale alla coda del match, quindi al ritorno valuto L, 
se L vero (contiene la coda del caso (!!)),
allora elimino i nodi T che sono sicuramente nodi match, e inserisco in testa i valori x che sono
i nodi match.
inshead mi garantisce che la coda non viene toccata, inserendo sempre in testa.
*/


//--------------------------------------------------


doppialista*inshead(doppialista*L,nodo*x){
    if(!L){
     x->next=0;
     return new doppialista(x,0);
    }
    else{
    x->next=L->listamatch;
    L->listamatch=x;
    return L;
    }
}
//inserisco x in testa a L
doppialista*match(nodo*T,int*P,int dimP){
    
    if(!T){
        if(dimP != 0)
            return 0;
            else
    return new doppialista(0,0);
    }
    
    doppialista*L=0; nodo*x=0; nodo*y=0; 
    
      if(T->info == *P)
        x=T; //x è nodo match
        else
        y=T; //y è restante
    
    if(x){
        L=match(T->next,P+1,dimP-1);
          if(!L)
        return 0;
        else
           L=inshead(L,x); 
    }
    else if(y){
        L=match(T->next,P,dimP);
        if(!L)
        return 0;
        else
        L=insheadR(L,y);
    }
  
}
/*POST=(se esiste match di P in L(T) allora match2 restituisce il puntatore X ad un valore di tipo doppialista
tale che X->listamatch sia la lista del match trovato e X->restante sia la lista restante, se invece non c’è
match, match2 restituisce il puntatore 0 e L(T) resta inalterata).*/



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

#include <iostream>
using namespace std;

struct nodo{char info; nodo*left; nodo*right; nodo(char a=0,nodo*b=0,nodo*c=0){info=a; left=b; right=c;}};

struct nodox{int info; nodox*left; nodox*right; nodox(int a=0,nodox*b=0,nodox*c=0){info=a; left=b; right=c;}};


void stampa(nodo*r){
	if(r){
		cout<<r->info<<"(";
		stampa(r->left);
		cout<<",";
		stampa(r->right);
		cout<<")";
	}
	else
	cout<<"_";
}

void stampa2(nodox*r){
	if(r){
		cout<<r->info<<"(";
		stampa2(r->left);
		cout<<",";
		stampa2(r->right);
		cout<<")";
	}
	else
	cout<<"_";
}

void dealloca_albero(nodo*x){
	if(x){
		dealloca_albero(x->left);
		dealloca_albero(x->right);
		delete x;
	}
}

int conta_nodi_di_un_albero(nodo*x){
	
	if(x){
		return 1+conta_nodi_di_un_albero(x->left)+conta_nodi_di_un_albero(x->right);
	}
	else
	return 0;
}

int conta_nodi_di_un_albero(nodox*x){
	
	if(x){
		return 1+conta_nodi_di_un_albero(x->left)+conta_nodi_di_un_albero(x->right);
	}
	else
	return 0;
}

int altezza(nodo *x){
  if(!x) 
   return -1;
 else {
   int a=altezza(x->left);
   int b=altezza(x->right);
   if(a>b) return a+1;
   return b+1;
 }
}//restituisce altezza di un albero


//PRE=(albero(x) corretto, lung >=0, C[0..lung-1] def e 0/1)
nodo * trova(nodo *x, int* C, int lung){ 
   if(!x) 
    return 0; // fallito
if(!lung) 
	return x; //trovato
if(*C==0) 
	return trova(x->left, C+1, lung-1);
else
return trova(x->right,C+1, lung-1);
}
/*POST=(restituisce punt. a nodo alla fine del
cammino C[0..lung-1], se c’è in albero(x), e
altrimenti 0*/

nodo*ricerca(nodo*r,char z){
	if(!r)
	return 0;
	
	if(r->info == z)
	return r;
	
	nodo*p=ricerca(r->left,z);
	if(p)
	return p;
	else
	return ricerca(r->right,z);
}
//ritorna puntatore al nodo cercato z

void build(nodo*&n,char x){
	if(!n)
	n=new nodo(x,0,0);
	
	else{
	if( conta_nodi_di_un_albero(n->left) <= conta_nodi_di_un_albero(n->right))
	build(n->left,x);
	else
	build(n->right,x);
	}
}//inserisce un nodo x in maniere bilanciata in n

void build2(nodox*&n,int x){
	if(!n)
	n=new nodox(x,0,0);
	
	else{
	if( conta_nodi_di_un_albero(n->left) <= conta_nodi_di_un_albero(n->right))
	build2(n->left,x);
	else
	build2(n->right,x);
	}
}//inserisce un nodo x in maniere bilanciata in n

int altezza(nodo*n){
	if(!n)
	return -1;
	else{
		int h1=altezza(n->left);
		int h2=altezza(n->right);
		if(h1>=h2)
		return h1+1;
		else
		return h2+1;		
	}
}

//nodox contiene in campo info un intero invece che un char
void altezza_radicata(nodox* r){
  if(r){
	  altezza_radicata(r->left);
	  altezza_radicata(r->right);
	  int a=0;
	  int b=0;
	  if(r->left)
		  a=r->left->info;
	  if(r->right)
		  b=r->right->info;
	  r->info = a+b+1;
	}
  }

//ogni nodo n dell albero, contiene nel suo campo info,
//il numero di nodi radicati nel suo sottoalbero compreso se stesso!


/*PRE=(albero(r) corretto, k>=1, C è un array di interi con un numero di elementi maggiore della
profondità di albero*/
nodo* cerca1_infix(nodo*r, int& k, int *C){

    if(!r){//(!)
        *C=-1;
        return r;
    }

    nodo*x=cerca1_infix(r->left,k,C+1);//(!!)
       if(k==1){
        *C=-1;
         k=0;
        return r;
    }
    else
    k=k-1;
    
    if(x)
    *C=0;
    else{
    x=cerca1_infix(r->right,k,C+1);//(!!!)
    if(x)
    *C=1;
    }

    return x;//(*)
}
/*
POST=(se albero(r) ha almeno k nodi, allora la funzione restituisce col return il nodo k rispetto
all’ordine infisso dei suoi nodi, e inoltre in C restituisce il cammino che da r porta a questo nodo)
&& (se invece albero(r) ha, diciamo, m nodi, con m <k, allora il valore finale di k sarà vk-m e la
funzione restituisce 0 col return)*/

/*
void completa(nodo*r){
    if(r){

        if(!r->left && !r->right)
        r->n=1;

        else{

        completa(r->left);
        completa(r->right);


        if(!r->left && r->right)
        r->n=r->right->n+1;
        else if(r->left && !r->right)
        r->n=r->left->n+1;
        else
        r->n=r->right->n+r->left->n+1; //(!)
        }
    }
}
*/
//albero che contiene nei suoi nodi un campo n
//dove viene memorizzato il numero dei nodi presente nel suo sottoalbero radicato
//foglia ha come n==1, albero con nodo dx e sx ha come n della radice ==3

nodo*build_ric(int*C,nodo*r){
	
	if(*C==-1){
		if(!r){
			return new nodo('$',0,0);
		}
		else
		cout<<"troppo Corto"<<endl;
	}
	else{
		if(r){
			if(*C==0)
			r->left=build_ric(C+1,r->left);
			else
			r->right=build_ric(C+1,r->right);
		}
		else
		cout<<"troppo lungo"<<endl;
	}
	return r;
}
//a r sono stati aggiunti i nodi che corrispondo al cammino in C
//Es C: 0 0 -1 se possibile aggiungo un nodo in posizione 0 0

nodo*build_iter(int*C,nodo*r){
	nodo*rit=r;
	int i=0;
	bool stop=false;
	
	while(!stop){
		if(r && C[i]==-1){
			cout<<"troppo Corto"<<endl;
			stop=true;
		}
		
		if(r){
			if(C[i]==0){
				nodo*t=r->left;
				i++;
				if(!t && C[i]==-1){
					t=new nodo('$',0,0);
					r->left=t;
					stop=true;
				}
				else
				r=r->left;
			}
			else{
				nodo*t=r->right;
				i++;	
				if(!t && C[i]==-1){
					t=new nodo('$',0,0);
					r->right=t;
					stop=true;
				}
				else
				r=r->right;
			}
		}
		else{
		cout<<"troppo lungo"<<endl;
		stop=true;
		}
	}	
		return rit;
}

FIFO pickric_infix(nodot*R, int &n, int k){
    if(!R)
    return FIFO();
    
    FIFO x=pickric_infix(R->left,n,k);
    
    if(n==k){
        nodo*t=new nodo(R->info,0);
        x=push_end(x,t);
        n=1;
    }
    else
    n++;
    
    FIFO y=pickric_infix(R->right,n,k);
    
    return concF(x,y);
}
/*
POST=(restituisce un valore FIFO f tale che f.primo sia una lista L tale che i nodi abbiano i campi info di
valore uguale ai campi info dei nodi dell'albero Tree(R) che si trovano nella posizione vn, vn+k, vn+2*k,
eccetera rispetto all'ordine infisso, inoltre n-1 è il numero di nodi presenti nell'albero che seguono, rispetto
all'ordine infisso, il nodo dell'albero in corrispondenza del quale si è creato l'ultimo nodo di L).
INFISSO S-N-D
*/
nodo* max(nodo*r){
if(!r) return 0;
nodo*a=max(r->left);
nodo*b=max(r->right);
  if(a&&b){
	nodo*c=maggiore(a,r); return maggiore(c,b); 
  }
 else
  if(a)
    return maggiore(a,r);
  else if(b) 
    return maggiore(r,b);
else
return r;
}
/*POST=(restituisce il puntatore al primo nodo con
info max rispetto all’ordine infisso e 0 se r=0)*/

int cncuf(nodo *x){ 
if(x)
if(!x->left && x->right || x->left &&!x->right)
return 1+ cncuf(x->left)+cncuf(x->right);
else
return cncuf(x->left)+cncuf(x->right);
else
return 0;
}//contare i nodi con esattamente un figlio

nodo * prof_data(nodo * r, int k){
if(! r ) 
	return 0;
if(k==0) 
	return r;
	
nodo * p=prof_data(rleft,k-1);
if(p) 
	return p;
	
return prof_data(rright,k-1);
}
/*POST=(restituisce nodo a prof k se c’è e 0
altrimenti*/

int prof_min(nodo*x, int prof){
	if(leaf(x)) 
		return prof;
int a=-1,b=-1;
if(x->left)
a=prof_min(x->left,prof+1);
if(x->right)
b=prof_min(x->right,prof+1);
	
if(a!=-1 && b!=-1)
if(a <= b)
return a;
else
return b;
if(a!=-1) 
	return a;
return b;
}

int main(){

nodo*quarto=new nodo('r',0,0);
nodo*terzo=new nodo('d',0,0);
nodo*secondo=new nodo('b',quarto,0);
nodo*primo=new nodo('a',secondo,terzo);

int C[10]={0,1,-1};
primo=build_iter(C,primo);
stampa(primo);

return 0;
}

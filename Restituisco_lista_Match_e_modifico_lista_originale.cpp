#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo*L2){
      if(L2){
          cout<<L2->info<<" ";
          stampa(L2->next);
      }
}

nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}


void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>*P;
    leggi(dim-1,P+1);
   }

}

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
        L2=inshead(L2,x);(!!)
        return L2;
    }
    
    return match(n->next,P,dimP);
}
/*

POST:
POST=(in L(n) c’è un match di P, allora la funzione restituisce col return match(vL(n),P[0..dimP-1]) e
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

main()
{
  int dim, dimP, P[20];
  cout<<"start"<<endl;
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);
  nodo* L2= match(L1,P, dimP);//da fare
  stampa(L2); //da fare 
  cout<<endl;
  stampa(L1);
  cout<<"end"<<endl;
}


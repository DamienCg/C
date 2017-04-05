/*
 Data una lista concatenata   C  vogliamo eliminare da C quei  nodi che sono preceduti 
 (anche non immediatamente) da nodi con uguale campo info. La cosa è spiegata nel seguente esempio. 
 Esempio: se la lista è C= 2->0->1->1->0->3->2 allora vogliamo farla diventare 2->0->1->3 
 */
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct FIFO{nodo* primo, *fine; FIFO(nodo*a=0, nodo*b=0){primo=a; fine=b;}}; 

FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
   {a.primo=a.fine=b; return a;}
  else
   {
    a.fine->next=b; 
    a.fine=b;
    return a;
   }
}

void stampa_L(nodo* x)
{
  if(x)
  {cout<<x->info<<' '; stampa_L(x->next);}
  else
   cout<<endl;
}

nodo* costruisci(int dim)
{
  if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,costruisci(dim-1));
 
  }
 else
  return 0;
}

//PRE=(lista(C) è corretta e y è definito) iterativa
  nodo*  togli(nodo*C, int y) {
	  
	  FIFO A;
	 
	  while(C){
		  
		  if(C->info==y){
			nodo* aux=C;
			C=C->next;
			delete aux;
			}
		  else{
		  A=push_end(A,C);//aggiungo in fondo sse il nodo corrente non è da eliminare
		  //in modo da crearmi una lista con soli nodi corretti (non da eliminare)
		C=C->next;
		}
	}
 if(A.fine)//A.inizio e A.fine mai inizializzati di default a 0, quindi abbiamo eliminato tutti gli elementi trovati
	A.fine->next=0;// dopo la fine non deve esserci il resto della lista ma 0
	return A.primo;//ovviamente ritorno inizio lista!
}
/*POST=(restituisce la lista che resta eliminando da C i nodi con campo info=y. 
  I nodi tolti da C sono deallocati. Nessun nodo nuovo rispetto a C è allocato) 
*/

//PRE=(lista(C) è corretta)  ricorsiva
nodo* no_rip(nodo*C) {

  if(!C)
   return 0;
	
	nodo*A=no_rip(C->next);
	//scorro intera lista, così posso eliminare i nodi al ritorno così da lasciare i primi nodi corretti!

   if(C->next)//Evito il sagmentation fault
    C->next=togli(C->next,C->info);	
 
}
/*POST=(restituisce quello che resta di C mantenendo solo il primo nodo con un dato campo info ed eliminando i nodi successivi con lo stesso campo info. I nodi tolti da C sono deallocati. Nessun nuovo nodo rispetto a C è allocato) 
  L'idea è che la funzione no_rip, per fare quello che deve fare,  invoca la funzione togli. 
  Consiglio: l'uso della seguente struttura FIFO (vista in classe)  :  
  struct FIFO{nodo* primo,*fine; FIFO(nodo*a=0, nodo*b=0){primo=a; fine=b;}}; 
  */
  
 void  elim(nodo*&T, nodo*C){
	 
	  while(C && T){
		  T=togli(T,C->info);
		  C=C->next;
	  }	  
  }
  
  //unica funzione cha fa tutto!
  FIFO  tieni_primo(nodo*& Q){
  
  nodo*C=Q; FIFO a,b;
  
  while(C){
      nodo*z=C->next;
      while(z){
          int x=z->info;
          nodo*n=z;
          z=z->next;
          n->next=0;
          
          if(x==C->info)
            a=push_end(a,n);
            else
            b=push_end(b,n);
      }
      C->next=b.primo;
      C=b.primo;
      b.primo=b.ultimo=0;
  }
  return a;
  //ritorno lista nodi eliminati!   
 }
/*POST=(L(Q) è vL(Q) in cui sono stati eliminati i nodi che hanno un campo info tale che un nodo alla loro 
  sinistra abbia lo stesso campo info. Quindi per ogni valore info resta solo il primo nodo con 
  quel valore. La lista dei nodi eliminati va gestita da un valore FIFO restituito col return)
*/

main()
{
   int dimT, dimC;
   
   cin>>dimC;
   nodo*C=costruisci(dimC);//data
   
   stampa_L(C); //data
   nodo*Y=no_rip(C);//da fare, essa usa togli (che usa FIFO)
   stampa_L(Y);

     cin>>dimT;
     nodo* T=costruisci(dimT);
     stampa_L(T);
   
     elim(T,Y); //da fare, esercizio finale
   
     stampa_L(T);
   cout<<endl<<"end";  
   }
/*   
Esercizio finale: 
 Si chiede anche si scrivere una funzione iterativa che, 
 date 2 liste concatenate T e C, elimina da T (deallocandoli) 
 tutti quei nodi che hanno campo info uguale ad un nodo di C. 
 La funzione deve restituire la nuova lista T. 
 La funzione può usare una o entrambe le funzioni no_rip e togli e deve avere la seguente segnatura: 
void  elim(nodo*&T, nodo*C);
*/

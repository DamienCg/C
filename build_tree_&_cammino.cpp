/*
Crea albero non banale con elementi inseriti da cin
non banale=cerca sempre di riempire completamente i livelli
da sinistra verso destra, poi, restituisce true stampando un cammino
dato sse in R(albero) esiste un cammino da r(radice) ad una foglia
//con esattamente k nodi con campo info=y e false altrimenti, 

*/

#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

void stampa_l(nodo *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}
int conta_n(nodo*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo*r, int y)
{
  if(!r) 
  return new nodo(y);
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}

nodo* rep_ins(nodo*r, int dim)
{
  if(dim)
   {
    int z;
    cin>>z;
    nodo*x=insert(r,z);
    return rep_ins(x,dim-1);
   }
  return r;
}
void sc(int*C)
{
  if(*C!=-1)
   {cout<<*C<<' '; sc(C+1);}
  else
    cout<<"fine cammino"<<endl;
}

//PRE_cerca=(albero(r) è corretto e non vuoto, k>=0 e y valore qualsiasi, 
//C ha almeno tanti elementi quanta è l'altezza di albero(r)) 
bool cerca_cam(nodo*r, int k, int y, int*C){
    
    if(!r)//caso base!
    return false;
 
    if(r->info==y)
       k--;   
    
    if(!r->left &&!r->right){//Siamo in una foglia
     if(k==0){*C=-1;return true;}
//siamo in una foglia ed abbiamo trovato il cammino contenente k nodi==y
    }
 
 if(r->left){     
 *C=0;
 if(cerca_cam(r->left,k,y,C+1))
  return true;//trovato un cammino con k nodi==y parte sinistra
}
 if(r->right){
 *C=1;
   if(cerca_cam(r->right,k,y,C+1))
     return true;//trovato un cammino con k nodi==y parte destra
 }
}
//POST_cerca=(restituisce true sse in r esiste un cammino da r ad una foglia
//con esattamente k nodi con campo info=y e false altrimenti, 
//in caso restituisca true, C contiene una sequenza (anche vuota) 
//di 0/1 che termina con -1 e che individua il cammino più a sinistra 
//in albero(r) con esattamente k y).  

main()
{
   int dim, k,y;
   cin>>dim;
   nodo* R=rep_ins(0,dim);//data
      
   cin>>k>>y;
   int C[30];
   bool b=cerca_cam(R,k,y,C);//da fare
   if(b)
    {cout<<"true con cammino= "; sc(C); cout<<endl;} //sc data
   else
    cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
    cout<<"end"<<endl;
}
  

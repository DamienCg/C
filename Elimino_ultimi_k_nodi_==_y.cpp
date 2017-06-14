int G(nodo*&L,int y,int k){

if(!L)
return k;

int x=G(L->next,y,k);

if(L->info == y && x>0){
	nodo*t=L;
	L=L->next;
	delete t;
	x--;
}
return x;
}
/*Elimino gli ultimi k nodi == y*/

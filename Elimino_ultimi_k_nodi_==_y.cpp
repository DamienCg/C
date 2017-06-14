/*L corretta, y>=0, k e count hanno lo stesso r valore all inizio della funzione
ogni volta che all andata incontri un campo info uguale a y incrementi count alla fine
se count-k sarà maggiore di k, cioè se abbiamo trovato almeno k nodi allora x=k, sennò x=0,
al ritorno staco x nodi, decrementanto x ogni nodo staccato*/
int G(nodo*&L,int y,int k,int count){

if(!L){
	if((count-k)>=k)
return k;
else
return 0;
}

if(L->info == y)
count++;

int x=G(L->next,y,k,count);

if(L->info == y && x>0){
	nodo*t=L;
	L=L->next;
	delete t;
	x--;
}
return x;
}
/*Elimino gli ultimi k nodi == y solo se L contiene almeno k nodi==y*/

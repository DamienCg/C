nodo*ins_end(nodo*x,nodo*y){
	if(!x)
	return y;
	
	x->next=ins_end(x->next,y);
}
//inserisce y alla fine di x.


//PRE=(L(Q) è lista corretta, k>=0, z def., ck def, vL(Q)=L(Q), vk=k e vck=ck)
nodo* sUK(nodo*&Q, int k, int z, int & ck){ //sUk sta per stacca ultimi k (nodi)
	if(k==0 || !Q)
	 return 0;
	 
	if(Q->info==z)
		ck++;
		
		if(!Q->next){ //(!)
		if(ck>=k)
		ck=k;
		else
		ck=0;
		}
	
	nodo*a=sUK(Q->next,k,z,ck);
	
	if(ck && Q->info==z){
	  nodo*y=Q;
	  Q=Q->next;
	  y->next=0;
	  a=ins_end(a,y);
	  ck--;
	}
	return a;
}
/*
POST=(se vL(Q) contiene x nodi con info=z e vck+x >=k, allora viene restituito col return la lista che consiste
degli ultimi k-ck nodi di vL(Q) che contengono info=z ed L(Q) è vL(Q) meno i nodi restituiti col return)
&&(se vL(Q) contiene x nodi con info=z e vck+x<k, allora L(Q)=vL(Q) e viene restituito 0 col return)
* Prova Induttiva:
* 
* Caso base: vale PRE, if k==0 || !Q lista vuota, ritorno 0,
* nessun nodo da staccare in lista o lista vuota, vale PRE e Vale POST.

*Passo induttivo:
* invocazione ricorsiva valida rispetto a PRE e POST,
* Q lista corretta, k>0, invocazioni ricorsive garantite
* limiti garantiti dai casi base, chiamata ricorsiva sul resto della lista,
* k>0, z valore albitrario ck incrementato se riscontrato valore Q->info==0,
* al passo (!) ci troviamo ultimo nodo di Q, controlliamo se ci sono almeno
* k nodi con campo info=z, e se vero ck=k, altrimenti LQ non possiede almeno k
* nodi con campo info==z, ck=0, non vengono staccati nodi, 
* 
* al ritorno ck=k se ci sono almeno k nodi campo info=z in LQ
* o ck=0, se NON ci sono almeno k nado con campo info=z in LQ,
* 
* se ck=k, e ad ogni stack di ritorno dove Q->info=z,
* allora stacco nodo di Q==z, avanzo puntatore Q=Q->next, ed
*  inserisco in fondo alla lista a il nodo staccato da Q
* con ins_end. ritorno a, a sarà uguale alla lista di nodi staccati se
* ci sono almeno k nodi campo info=z in LQ, altrimenti a=0;
* ritorno a rispettando POST.
*/

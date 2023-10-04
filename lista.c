#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct lista {
 int info;
 Lista *prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria(){
 return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l){
 return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info){
 Lista* ln = (Lista*)malloc(sizeof(Lista));
 ln->info = info;
 ln->prox = l;
 return ln;
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
 Lista* lAux = l;
 while(lAux!=NULL){
 	if(lAux->info == info)
 		return lAux;
 	lAux = lAux->prox;
 }
 return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
 Lista* lAux = l;
 while(lAux!=NULL){
 	printf("Info = %d\n",lAux->info);
 	lAux = lAux->prox;
 }
}

Lista* lst_remove(Lista *l, int info){
if(l!=NULL){
 	Lista* lAux = l->prox;
 	if(l->info==info){
 		free(l);
 		return lAux;
 	}
 	else{
 		Lista* lAnt = l;
 		while(lAux!=NULL ){
 			if(lAux->info == info){
 				lAnt->prox = lAux->prox;
		 		free(lAux);
 				break;
 			}
			else{
 				lAnt = lAux;
 				lAux = lAux->prox;
 			}
 		}
 	}
}
return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
 Lista* lProx;
 while(l!=NULL){
 	lProx = l->prox;
 	free(l);
 	l = lProx;
 }
}
void lst_imprime_rec(Lista* l){
	if(lst_vazia(l))
	return;
	else{
		printf("info: %d\n",l->info);
		lst_imprime_rec(l->prox);
	}
}

void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
	return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
 	}
}

Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l))
 		if(l->info==info){
			Lista* lAux = l;
 			l = l->prox;
		free(lAux);
 		}
 		else{
		l->prox = lst_remove_rec(l->prox,info);
		}
	return l; 
}

int comprimento(Lista* l){
	Lista* lAux = l;
	int comprimento=0;
 	while(lAux!=NULL){
 		comprimento++;
 		lAux = lAux->prox;
 	}
	return comprimento;	
}

int menores(Lista* l, int n){
	int contador = 0;
	Lista* lAux = l;
	while(lAux!=NULL){
		if((lAux->info)<n){
			contador++;
		}
 		lAux = lAux->prox;		 
	}
	return contador;
}

int soma(Lista* l){
	int contador = 0;
	Lista* lAux = l;
	while(lAux!=NULL){
		contador=contador+lAux->info;
		lAux = lAux->prox;
	}
	return contador;
}

int primos(Lista* l){
	Lista* lAux = l;
	int contador = comprimento(l); // considerar inicialmente todos como primos e ir tirando.
	while(lAux!=NULL){
		int n= lAux->info;
		if(n<= 1){
			lAux = lAux->prox;	
			contador--;
		}
		else{
			int i;
			for (i = 2; i < n; i++) {
        		if (n % i == 0) {
            		contador--; 
            		i=n;
        		}
    		}
    		lAux = lAux->prox;
    	}
	}
	return contador;
}

Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* ln = lst_cria();
	Lista* lAux1 = l1;
	Lista* lAux2 = l2;
	while(lAux1!=NULL){
		ln= lst_insere(ln,lAux1->info);
		lAux1=lAux1->prox;
	}
	while(lAux2!=NULL){
		ln= lst_insere(ln,lAux2->info);
		lAux2=lAux2->prox;
		
	}
	return ln;
}

Lista* lst_diferenca(Lista* l1, Lista* l2){
	Lista* ln = lst_cria();
	ln = l1;
	Lista* Aux = l2;
	int i;
	while(Aux!=NULL){
        int n = Aux->info;
        if(lst_busca(ln,n)!=NULL){
            ln =lst_remove(ln,n);
        }
        Aux=Aux->prox;
    }
	return ln;
}




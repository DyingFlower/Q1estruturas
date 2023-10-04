
typedef struct lista Lista;
 /* Cria uma lista vazia.*/
Lista* lst_cria();
/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l);
/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info);
/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);
/* Imprime uma lista.*/
void lst_imprime(Lista *l);
/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);
/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l);
/* Imprime uma lista de forma recursiva.*/
void lst_imprime_rec(Lista* l);
/* Imprime uma lista de forma invertida.*/
void lst_imprime_invertida_rec(Lista* l);
/* Remove um elemento de uma lista de forma recursiva.*/
Lista* lst_remove_rec(Lista *l, int info);
/* função que calcule o número de nós de uma lista */
int comprimento(Lista* l);
/*  função para retornar o número de nós da lista que possuem o campo info com valor menor que n. */
int menores(Lista* l, int n);
/* função para somar os valores do campo info de todos os nós. */
int soma(Lista* l);
/* função para retornar o número de nós da lista que possuem o campo info com número primo. */
int primos(Lista* l);
/* função para criar uma lista que é a concatenação de uma lista l2 no final de uma lista l1. */
Lista* lst_conc(Lista* l1, Lista* l2);
/*  função que faça a diferença de duas listas L1 e L2 */
Lista* lst_diferenca(Lista* l1, Lista* l2);

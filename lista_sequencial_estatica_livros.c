/*Programa: Lista encadeada estatica
  Autor: Gabriel Correia Granja
  AED-1    26/05/2021*/

#include <stdio.h>

struct listaES{
    int lista[10];
    int tamanholista;
    int posicao_ultimo;
};
typedef struct listaES LISTA;

void inicializaLista(LISTA *l){
  int i;
  l->tamanholista = 0;
  for(i=0; i<10; i++);
  l->lista[i]=0;
}

int inserirlista(LISTA *l, int res){
  if(l->tamanholista==10)
    return 1;  
  else
    l->tamanholista++;
    l->lista[l->tamanholista-1] = res;
    l->posicao_ultimo = l->tamanholista-1;
    return 0;
}

int buscalista(LISTA *l, int ret){
  int i=0;
  while(i<l->tamanholista){
    if(ret==l->lista[i]){
      return i;
    }else{
      i++;
    }
  }
  return -1;
}

int removelista(LISTA *l, int ret){
  int pos, k;
  pos = buscalista(l, ret);
  if(pos==-1){
    return -1;
  }
  for(k=pos; k<l->tamanholista-1; k++){
    l->lista[k] = l->lista[k+1];
  }
  l->tamanholista--;
  return 0;
}

int main(){
  LISTA Livros;
  int L, variavel1, variavel2, j, reservas=0, retiradas=0;
  inicializaLista(&Livros);
  scanf("%d", &L);
  for(j=0; j<L; j++){
    scanf("%d %d", &variavel1, &variavel2);
    switch(variavel1){
      case 1:
      if(inserirlista(&Livros, variavel2)){
        printf("Lista de reserva cheia\n");
      }else{
        printf("Sua reserva foi realizada\n");
        reservas++;
      }
      break;

      case 2:
      if(removelista(&Livros, variavel2)){
        printf("Voce nao possui reserva desse livro\n");
      }else{    
        printf("O livro foi retirado com sucesso\n");
        retiradas++;
      }
      break;
    }
  }
  printf("Voce realizou %d reservas e %d retiradas\n", reservas, retiradas);
  return 0;
}
 
    



/*Programa: Pilha Dinâmica lab_06
  Autor: Gabriel Correia Granja
  AED-1    17/07/2021*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct elemento{
  int info;
  struct elemento *prox;
};
typedef struct elemento tipoElemento;
typedef tipoElemento* PONT;

struct pilha{
  PONT topo;
};
typedef struct pilha PILHA;

void inicializapilha(PILHA *p){
  p->topo=NULL;
}

int tamanhopilha(PILHA *p){
  PONT cont=p->topo;
  int tamanho=0;
  while(cont!=NULL){
    tamanho++;
    cont=cont->prox;
  }
  return tamanho;
}

int pilhavazia(PILHA *p){
  if(p->topo==NULL){
    return 1;
  }else{
    return 0;
  }
}

void exibirpilha(PILHA *p){
  PONT cont=p->topo;
  while(cont!=NULL){
    printf("%i", cont->info);
    cont=cont->prox;
  }
  printf(" ");
}

int inserirpilha(PILHA *p, int v){
  PONT novo= (PONT)malloc(sizeof(tipoElemento));
  novo->info=v;
  novo->prox=p->topo;
  p->topo=novo;
  return 0;
}

int removepilha(PILHA *p){
  if(p->topo==NULL){
    return 1;
  }else{
    PONT novo=p->topo;
    p->topo=novo->prox;
    free(novo);
    return 0;
  }
}

int consultapilha(PILHA *p){
  return p->topo->info;
}

void TransformadorBinario(PILHA *p){
  PONT cont=p->topo;
  while(cont!=NULL){
    if(cont->info==0){
      cont->info=1;
    }else if(cont->info==1){
      cont->info=0;
    }
    cont=cont->prox;
  }
}

int main(){
  PILHA pilha;
  int L;
  int num;
  int j;
  int z;
  int x;
  int y;

  inicializapilha(&pilha);
  scanf("%d", &L);
  for(j=0; j<L; j++){
    scanf("%d", &num);
    x=num;
    while(num/2>0){
      z=num%2;
      inserirpilha(&pilha, z);
      num=num/2;
    }
    if(num/2==0){
      z=num%2;
      inserirpilha(&pilha, z);
    }
    printf("%d ", x);
    exibirpilha(&pilha);

    TransformadorBinario(&pilha);
    exibirpilha(&pilha);
    while(tamanhopilha(&pilha)>0){
      z=consultapilha(&pilha);
      y+=(z*pow(2,tamanhopilha(&pilha)-1));
      removepilha(&pilha);
    }
    printf("%d\n", y);
    y=0;
  }
  return 0;
}
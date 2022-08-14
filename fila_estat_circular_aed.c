/*Programa: Fila Estática Circular
  Autor: Gabriel Correia Granja
  AED-1    11/07/2021*/

#include <stdio.h>
#include <stdlib.h>

struct filaCircular {
  int primeiro;
  int ultimo;
  int tamanhofila;
  int A[100];
};
typedef struct filaCircular tipoFC;

void inicializafila (tipoFC *f){
  int i;
  f->primeiro=0;
  f->ultimo=-1;
  f->tamanhofila=0;
}

int tamanho(tipoFC *f){
  return f->tamanhofila;
}

void exibirfila(tipoFC *f){
  int i = f->primeiro;
  int t;
  for(t=0; t<f->tamanhofila; t++){
    printf("%i ", f->A[i]);
    i=(i+1)%100;
  }
  printf("\n");
}

void inverterfila(tipoFC *f){
  int i = f->ultimo;
  int t;
  for(t=0; t<f->tamanhofila; t++){
    printf("%i ", f->A[i]);
    i=((100+i)-1)%100;
  }
  printf("\n");
}

void inserefila(tipoFC *f, int info){ 
  if(tamanho(f)==100){ 
    
  }else{
  f->ultimo=(f->ultimo+1)%100;
  f->A[f->ultimo]=info;
  f->tamanhofila++;
  }
}

void removefila(tipoFC *f){
  if(tamanho(f)==0){
    
  }else if(tamanho(f)>0){
    f->primeiro=(f->primeiro+1)%100;
    f->tamanhofila--;
  }
}

void operacao3(tipoFC *f){
  if(tamanho(f)==0){
    
  }else{
    int g;
    g=f->A[f->primeiro];
    removefila(f);
    inserefila(f, g);
  }
}

int main(void) {
  tipoFC fila;
  int L;
  int OP;
  int V;
  int j;
  int cont=0;

  inicializafila(&fila);
  scanf("%d", &L);
  for(j=0; j<L; j++){
   scanf("%d", &OP);
   if(OP==1){
     scanf("%d", &V);
     inserefila(&fila, V);
   }
   if(OP==2){
     if(tamanho(&fila)==0){
       cont++;
     }
     removefila(&fila);
   }
   if(OP==3){
     if(tamanho(&fila)==0){
       operacao3(&fila);
       cont++;
     }
     operacao3(&fila);
   }
  }
  for(j=0; j<cont; j++){
    printf("vazia\n");
  }
  inverterfila(&fila);
  return 0;
}
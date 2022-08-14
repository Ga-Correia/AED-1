/*Programa: Lista encadeada estatica
  Autor: Gabriel Correia Granja
  AED-1    29/05/2021*/

#include <stdio.h>

struct ra{
  int RA;
};
typedef struct ra REGISTRO;

struct elem{
  REGISTRO reg;
  int prox;
};
typedef struct elem ELEMENTO;

struct lista{
  ELEMENTO A[10];
  int inicio;
  int dispo;
};
typedef struct lista tipoListaEE;


void inicializarLista(tipoListaEE *l){
  int i;
  for(i=0; i<10-1; i++){
    l->A[i].prox = i+1;
  }
  l->A[10-1].prox = -1;
  l->inicio= -1;
  l->dispo=0;
}

int tamanho(tipoListaEE *l){
  int i= l->inicio;
  int tam = 0;
  while(i!=-1){
    tam++;
    i=l->A[i].prox;
  }
  return tam;
}

void exibirLista(tipoListaEE *l){
  int i= l->inicio;
  while(i!=-1){
    printf("%i ", l->A[i].reg.RA);
    i=l->A[i].prox;
  }
  printf("\n");  
}

int obterNO(tipoListaEE *l){
  int resultado= l->dispo;
  if(l->dispo!=-1){
    l->dispo= l->A[l->dispo].prox;
  }
  return resultado;
}

int inserirRA(tipoListaEE *l, int registro){
  if(l->dispo==-1){
    return 1;
  }
  int ant=-1;
  int i= l->inicio;
  while((i!=-1)&&(l->A[i].reg.RA<registro)){
    ant=i;
    i= l->A[i].prox;
  }
  i=obterNO(l);
  l->A[i].reg.RA=registro;
  if(ant==-1){
    l->A[i].prox= l->inicio;
    l->inicio= i;
  }else{
    l->A[i].prox=l->A[ant].prox;
    l->A[ant].prox= i;
  }
  return 0;
}

void devolverNO(tipoListaEE *l, int k){
  l->A[k].prox= l->dispo;
  l->dispo= k;
}

int retirarRA(tipoListaEE *l, int retirado){
  int ant=-1;
  int i= l->inicio;
  while((i!=-1)&&(l->A[i].reg.RA<retirado)){
    ant=i;
    i= l->A[i].prox;
  }
  if(i==-1 || l->A[i].reg.RA!=retirado){
    return 1;
  }
  if(ant==-1){
    l->inicio= l->A[i].prox;
  }else{
    l->A[ant].prox= l->A[i].prox;
  }
  devolverNO(l, i);
  return 0;
}


int main(){
  tipoListaEE LISTA;
  int L;
  int variavel1;
  int variavel2;
  int ANO=2011;
  int ano;
  int j;
  int t;
  int quantidade;
  int qtd[8]={0, 0, 0, 0, 0, 0, 0, 0};

  inicializarLista(&LISTA);
  scanf ("%d", &L);
  for(j=0; j<L; j++){
    scanf ("%d %d" , &variavel1, &variavel2);
    if(variavel1==1){
      if((variavel2>=60000)&&(variavel2<=140000)){
        if(inserirRA(&LISTA, variavel2)){
          printf("lista cheia\n");
          exibirLista(&LISTA);
        }else{
          exibirLista(&LISTA);
          if((variavel2/1000>=66)&&(variavel2/1000<76)){
            qtd[0]++;
          }
          if((variavel2/1000>=76)&&(variavel2/1000<86)){
            qtd[1]++;
          }
          if((variavel2/1000>=86)&&(variavel2/1000<96)){
            qtd[2]++;
          }
          if((variavel2/1000>=96)&&(variavel2/1000<106)){
            qtd[3]++;
          }
          if((variavel2/1000>=106)&&(variavel2/1000<116)){
            qtd[4]++;
          }
          if((variavel2/1000>=116)&&(variavel2/1000<126)){
            qtd[5]++;
          }
          if((variavel2/1000>=126)&&(variavel2/1000<136)){
            qtd[6]++;
          }
          if((variavel2/1000>=136)&&(variavel2/1000<=140)){
            qtd[7]++;
          }
        }
      }
    }
    if(variavel1==2){
      if((variavel2>=60000)&&(variavel2<=140000)){
        if(retirarRA(&LISTA, variavel2)){
          printf("nao existe\n");
          exibirLista(&LISTA);
        }else{
          exibirLista(&LISTA);
        }
      }
    }
  } 
  for(t=0; t<8; t++){
    ano=ANO+t;
    quantidade=qtd[t];
    printf("%d: %d\n", ano, quantidade);
  } 
  return 0;
}
/*Programa: Lista Dinâmica Duplamente Encadeada
  Autor: Gabriel Correia Granja
  AED-1    26/06/2021*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct elemento {
  int info;
  struct elemento *prox;
  struct elemento *ant;
};

typedef struct elemento
tipoElemento;

struct estruturaLDDE{
  tipoElemento *primeiro;
  tipoElemento *ultimo;
  int tamanhoLista;
};
typedef struct estruturaLDDE
tipoLDDE;

void inicializaLista(tipoLDDE *l){
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->tamanhoLista=0;
}

int tammanhoLISTA(tipoLDDE *l){
  return l->tamanhoLista;
}

void exibir(tipoLDDE *l){
  tipoElemento *cont=l->primeiro;
  while(cont != NULL){
    printf("%d ", cont->info);
    cont=cont->prox;
  }
  printf("\n");
}

void insereElementoFinal(tipoLDDE *l, int valor){ 
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  novo->info=valor;
  if(l->tamanhoLista == 0){
    novo->prox = NULL;
    novo->ant = NULL;
    l->primeiro=novo;
    l->ultimo=novo;
  }else{
    novo->prox = NULL;
    novo->ant = l->ultimo;
    l->ultimo->prox = novo;
    l->ultimo=novo; 
  }
  l->tamanhoLista++; 
}

void insere(tipoLDDE *l, int v, int pos){
  int i;
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  tipoElemento *g;
  novo->info=v;
  g=l->primeiro;
  if(pos==0){
    if(l->tamanhoLista == 0){
      novo->prox = NULL;
      novo->ant = NULL;
      l->primeiro=novo;
      l->ultimo=novo;
    }else{
      novo->ant=NULL;
      novo->prox=l->primeiro;
      l->primeiro->ant=novo;
      l->primeiro=novo;
    }
  }else{
    for(i=1; i<pos; ++i){
      g = g->prox;
    }
    novo->prox = g->prox;
    novo->ant = g;
    if(g->prox==NULL){
      l->ultimo=novo;
    }else{
      g->prox->ant=novo;
    }
    g->prox=novo;
  }
  l->tamanhoLista++;
}

int consulta(tipoLDDE *l, int pos){
  if(pos<-2 || pos>l->tamanhoLista+2){
   return -10; 
  }
  if(pos==-1){
    pos=l->tamanhoLista-1;
  }
  if(pos==-2){
    pos=l->tamanhoLista-2;
  }
  if(pos==l->tamanhoLista){
    pos=0;
  }
  if(pos==l->tamanhoLista+1){
    pos=1;
  }
  tipoElemento *cont=l->primeiro;
  int i=0;
  while(cont != NULL && i<pos){
    cont=cont->prox;
    i++;
  }
  if(cont==NULL){
    return -10;
  }else{
    return cont->info;
  }
}

tipoElemento* busca(tipoLDDE *l, int *pos, tipoElemento** ANT){
  if(*pos<-2 || *pos>l->tamanhoLista+2){
    return NULL;
  }
  if(*pos==-1){
    *pos=l->tamanhoLista-1;
  }
  if(*pos==-2){
    *pos=l->tamanhoLista-2;
  }
  if(*pos==l->tamanhoLista){
    *pos=0; 
  }
  if(*pos==l->tamanhoLista+1){
    *pos=1;
  }
  *ANT=NULL;  
  tipoElemento *cont=l->primeiro;
  int i=0;
  while(cont != NULL && i<*pos){
    *ANT=cont;
    cont=cont->prox;
    i++;
  }
  if(cont==NULL){
    return NULL;
  }else{
    return cont;
  }
}

int retira(tipoLDDE *l, int pos){
  tipoElemento *remov, *ANT;
  remov=busca(l, &pos, &ANT);
  if(l->tamanhoLista==0){
    return 1;
  }
  if(pos==0){
    l->primeiro=remov->prox;
  }else if(pos==l->tamanhoLista-1){
    ANT->prox=NULL;
    l->ultimo=ANT;
  }else{
    ANT->prox=remov->prox;
    remov->prox->ant=ANT;
  }
  free(remov);
  l->tamanhoLista--;
  return 0;
}

int main(){
  tipoLDDE LISTA;
  int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
  int P;
  int posicao;
  int j;
  int x;
  int y;
  int z;
  int a;
  int b, c, d, e, f, g;

  inicializaLista(&LISTA);
  scanf("%d %d %d %d %d %d %d %d %d %d", &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9);
  insereElementoFinal(&LISTA, n0);
  insereElementoFinal(&LISTA, n1);
  insereElementoFinal(&LISTA, n2);
  insereElementoFinal(&LISTA, n3);
  insereElementoFinal(&LISTA, n4);
  insereElementoFinal(&LISTA, n5);
  insereElementoFinal(&LISTA, n6);
  insereElementoFinal(&LISTA, n7);
  insereElementoFinal(&LISTA, n8);
  insereElementoFinal(&LISTA, n9);
  exibir(&LISTA);
  
  for(j=0; j<5; j++){
    scanf("%d %d", &P, &posicao);
    insere(&LISTA, P, posicao);
    x=consulta(&LISTA, posicao-1);
    y=consulta(&LISTA, posicao+1);
    z=consulta(&LISTA, posicao-2);
    a=consulta(&LISTA, posicao+2);
    if(x+P+y==10){
      if(posicao==0){
        retira(&LISTA, posicao);
        retira(&LISTA, posicao);
        retira(&LISTA, posicao-1);
        b=consulta(&LISTA, posicao);
        c=consulta(&LISTA, posicao-1);
        d=consulta(&LISTA, posicao-2);
        f=consulta(&LISTA, posicao+1);
        if(tammanhoLISTA(&LISTA)>=3){
          if(b+f+c==10){
            retira(&LISTA, posicao);
            retira(&LISTA, posicao);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
          if(d+c+b==10){
            retira(&LISTA, posicao);
            retira(&LISTA, posicao-2);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
        }
        if(j<4){
          exibir(&LISTA);
        }
        if(j==4){
          if(tammanhoLISTA(&LISTA)==0){
            printf("ganhou\n");
          }else{
            exibir(&LISTA);
            printf("perdeu\n");
          }
        }
      }else{
        retira(&LISTA, posicao-1);
        retira(&LISTA, posicao-1);
        retira(&LISTA, posicao-1);
        b=consulta(&LISTA, posicao);
        c=consulta(&LISTA, posicao-1);
        d=consulta(&LISTA, posicao-2);
        e=consulta(&LISTA, posicao-3);
        f=consulta(&LISTA, posicao-4);
        if(tammanhoLISTA(&LISTA)>=3){
          if(d+c+b==10){
            if(posicao==tammanhoLISTA(&LISTA)+1 || posicao==tammanhoLISTA(&LISTA)){
              retira(&LISTA, posicao);
              retira(&LISTA, posicao-2);
              retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            }else{
              retira(&LISTA, posicao);
              retira(&LISTA, posicao-1);
              retira(&LISTA, posicao-2);
            }
          }
          if((d+c+b!=10) && (e+d+c==10)){
            if(posicao-3==-2){
              retira(&LISTA, posicao-3);
              retira(&LISTA, tammanhoLISTA(&LISTA)-1);
              retira(&LISTA, 0);
            }
             if(posicao-3==-1 || posicao==tammanhoLISTA(&LISTA)+2){
              retira(&LISTA, posicao-3);
              retira(&LISTA, 0);
              retira(&LISTA, 0);
            } 
            if((posicao-3!=-2) && (posicao-3!=-1)){
              retira(&LISTA, posicao-3);
              retira(&LISTA, posicao-3);
              retira(&LISTA, posicao-3);
            }
          }
          if(posicao==tammanhoLISTA(&LISTA)+2 && (d+c+b!=10) && (e+d+c!=10)&&(f+e+d==10)){
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            retira(&LISTA, 0);
          }  
        }
        if(j<4){
          exibir(&LISTA);
        }
        if(j==4){
          if(tammanhoLISTA(&LISTA)==0){
            printf("ganhou\n");
          }else{
            exibir(&LISTA);
            printf("perdeu\n");
          }
        }
      }
    }
    if((x+P+y!=10)&&(z+x+P==10)){
      if(posicao==0){
        retira(&LISTA, posicao);
        retira(&LISTA, posicao-1);
        retira(&LISTA, posicao-1);
        b=consulta(&LISTA, posicao);
        c=consulta(&LISTA, posicao-1);
        d=consulta(&LISTA, posicao-2);
        e=consulta(&LISTA, posicao-3);
        f=consulta(&LISTA, posicao+1);
        if(tammanhoLISTA(&LISTA)>=3){
          if((f+b+c==10)){
            retira(&LISTA, posicao);
            retira(&LISTA, posicao);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
          if((f+b+c!=10)&&(b+c+d==10)){
            retira(&LISTA, posicao);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
        }
        if(j<4){
          exibir(&LISTA);
        }
        if(j==4){
          if(tammanhoLISTA(&LISTA)==0){
            printf("ganhou\n");
          }else{
            exibir(&LISTA);
            printf("perdeu\n");
          }
        }
      }else{
        retira(&LISTA, posicao);
        retira(&LISTA, posicao-1);
        retira(&LISTA, posicao-2);
        b=consulta(&LISTA, posicao);
        c=consulta(&LISTA, posicao-1);
        d=consulta(&LISTA, posicao-2);
        e=consulta(&LISTA, posicao-3);
        f=consulta(&LISTA, posicao+1);
        g=consulta(&LISTA, posicao-4);
        if(tammanhoLISTA(&LISTA)>=3){
          if(c+d+e==10){
            if(posicao==tammanhoLISTA(&LISTA)+1){
              retira(&LISTA, posicao-1);
              retira(&LISTA, posicao-4);
              retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            }
            if(posicao==tammanhoLISTA(&LISTA)+2){
              retira(&LISTA, posicao-1);
              retira(&LISTA, posicao-4);
              retira(&LISTA, 0);
            }
            if(posicao>1 && posicao<tammanhoLISTA(&LISTA)+1){
              retira(&LISTA, posicao-1);
              retira(&LISTA, posicao-2);
              retira(&LISTA, posicao-3);
            }
          }
          if(((c+d+e!=10)&&(d+c+b==10)&&(posicao==1))||((c+d+e!=10)&&(posicao==3)&&(g+e+d==10))){
            retira(&LISTA, 0);
            retira(&LISTA, 0);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
          if((c+d+e!=10)&&(posicao>3)&&(g+e+d==10)){
            retira(&LISTA, posicao-4);
            retira(&LISTA, posicao-4);
            retira(&LISTA, posicao-4);
          }
          if(((posicao==1)&&(c+d+e==10))||((c+d+e!=10)&&(posicao==2)&&(g+e+d==10))){
            retira(&LISTA, 0);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
        }
        if(j<4){
          exibir(&LISTA);
        }
        if(j==4){
          if(tammanhoLISTA(&LISTA)==0){
            printf("ganhou\n");
          }else{
            exibir(&LISTA);
            printf("perdeu\n");
          }
        }
      }
    }
    if((x+P+y!=10)&&(z+x+P!=10)&&(P+y+a==10)){
      if(posicao==tammanhoLISTA(&LISTA)-1){
        retira(&LISTA, 0);
        retira(&LISTA, 0);
        retira(&LISTA, tammanhoLISTA(&LISTA)-1);
        b=consulta(&LISTA, posicao);
        c=consulta(&LISTA, posicao-1);
        d=consulta(&LISTA, posicao-2);
        e=consulta(&LISTA, posicao-3);
        f=consulta(&LISTA, posicao+1);
        g=consulta(&LISTA, posicao-4);
        if(tammanhoLISTA(&LISTA)>=3){
          if(c+d+e==10){
            retira(&LISTA, 0);
            retira(&LISTA, 0);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
          if((c+d+e!=10)&&(g+e+d==10)){
            retira(&LISTA, 0);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
        }
        if(j<4){
          exibir(&LISTA);
        }
        if(j==4){
          if(tammanhoLISTA(&LISTA)==0){
            printf("ganhou\n");
          }else{
            exibir(&LISTA);
            printf("perdeu\n");
          }
        }
      }else{
        retira(&LISTA, posicao);
        retira(&LISTA, posicao);
        retira(&LISTA, posicao);
        b=consulta(&LISTA, posicao);
        c=consulta(&LISTA, posicao-1);
        d=consulta(&LISTA, posicao-2);
        e=consulta(&LISTA, posicao-3);
        f=consulta(&LISTA, posicao+1);
        if(tammanhoLISTA(&LISTA)>=3){
          if(b+c+f==10){
            if(posicao==tammanhoLISTA(&LISTA)||posicao==0){
              retira(&LISTA, 0);
              retira(&LISTA, 0);
              retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            }else{
              retira(&LISTA, posicao-1);
              retira(&LISTA, posicao-1);
              retira(&LISTA, posicao-1);
            }
          }
          if((posicao==tammanhoLISTA(&LISTA)+1)&&(b+c+d==10)){
            retira(&LISTA, 0);
            retira(&LISTA, 0);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
          if((b+c+f!=10)&&(b+c+d==10)){
            if(posicao==0||posicao==1){
              retira(&LISTA, posicao);
              retira(&LISTA, posicao-1);
              retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            }else{
              retira(&LISTA, posicao-1);
              retira(&LISTA, posicao-2);
              retira(&LISTA, posicao-2);
            }
          }
          if((b+c+f!=10)&&(b+c+d!=10)&&(c+d+e==10)&&posicao==9){
            retira(&LISTA, 0);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
            retira(&LISTA, tammanhoLISTA(&LISTA)-1);
          }
        }
        if(j<4){
          exibir(&LISTA);
        }
        if(j==4){
          if(tammanhoLISTA(&LISTA)==0){
            printf("ganhou\n");
          }else{
            exibir(&LISTA);
            printf("perdeu\n");
          }
        }
      }
    }
    if(x+P+y!=10 && z+x+P!=10 && P+y+a!=10){
      if(j<4){
        exibir(&LISTA);
      }
      if(j==4){
        if(tammanhoLISTA(&LISTA)==0){
          printf("ganhou\n");
        }else{
          exibir(&LISTA);
          printf("perdeu\n");
        }
      }
    }      
  }
  return 0;
}

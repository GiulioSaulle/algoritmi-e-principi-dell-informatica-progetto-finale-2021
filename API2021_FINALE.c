#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>


long contatoreClassifica=0;
long contatoreStampa=0;

static void swap(long *Array_A, long* Array_B){
  long temp = *Array_A;
  *Array_A = *Array_B;
  *Array_B = temp;
}

static long left(long i){
  return 2*i+1;
}

static long right(long i){
  return 2*i+2;
}

static long parent(long i){
  return (i-1)/2;
}

static void MaxHeapify(long* Array, long* classifica ,long i, long k) {
  long l = left(i);
  long r = right(i);
  long max;
  if(l < k && Array[l]>Array[i]){
    max = l;
  }else{
    max = i;
  }if(r < k && Array[r]>Array[max]){
    max = r;
  }
  if(max != i){
    swap(&Array[i], &Array[max]);
    swap(&classifica[i], &classifica[max]);
    MaxHeapify(Array, classifica, max, k);
  }
}


static void InsertHeap(long* distanze_classifica, long* classifica, double  n){
  long i = contatoreStampa-1;
  distanze_classifica[i] = n;
  classifica[i] = contatoreClassifica-1;
  while(i != 0 && distanze_classifica[parent(i)] < distanze_classifica[i]){
    swap(&distanze_classifica[parent(i)], &distanze_classifica[i]);
    swap(&classifica[parent(i)], &classifica[i]);
    i = parent(i);
  }
}

static void ReplaceMaxHeap(long* distanze_classifica, long* classifica, double n, long k){
  long i=contatoreStampa-1;
  distanze_classifica[0]=distanze_classifica[i];
  classifica[0]=classifica[i];
  MaxHeapify(distanze_classifica, classifica, 0, k);
}

static double Dijkstra(long d, long *matrice, long *visitato, long *distanza){
  long verticeattuale, distanzaminima, i=0, j=0, trovato=1, nullo=0;
  double sum=0;
  for(i=0;i<d;i++){
    if(matrice[i]!=0){
      distanza[i]=matrice[i];
      if(i>0){
      nullo++;
      }
    }else{
      distanza[i]=INT_MAX;
    }
    visitato[i]=0;
  }
  if(nullo==0){
        return 0;
    }
  distanza[0]=0;
  visitato[0]=1;
  while(trovato<d){
    verticeattuale = 0;
    distanzaminima = INT_MAX;
    for (j = 1; j < d; j++){
      //trovo il vertice non visitato e con distanza minima dal precedente
      if(visitato[j]!=1 && distanza[j] < distanzaminima){
        verticeattuale=j;
        distanzaminima=distanza[j];
        }
      }
      visitato[verticeattuale]=1;
      for (j = 1; j < d; j++) {
        if((distanza[j] > (/*distanza[verticeattuale]*/ distanzaminima + matrice[verticeattuale*d+j])) && matrice[verticeattuale*d+j]>0){
          distanza[j] = /*distanza[verticeattuale]*/ distanzaminima + matrice[verticeattuale*d+j];
        }
      }
      trovato++;
  }
  for (i = 0; i < d; i++) {
    sum+=distanza[i];
  }
  return sum;
}

static long Parse(){
  long i=0, t=0;
  char c;
  c=getchar();
  //printf("%c", c);
  while(c!=',' && c!='\n'){
    t=(t*10+(c-'0'));
    //printf("%ld",t);
    i++;
    c=getchar();
  }
  return t;
}

static void TopK(long* classifica, long k){
  //se non c'è classifica stampa direttamente \n
  long i;
  if(contatoreClassifica==0){
    printf("\n");
  }else{
    for (i = 0; i < contatoreStampa-1; i++) {
      printf("%ld ", classifica[i]);
    }
    printf("%ld", classifica[i]);
    printf("\n");
  }
}

static void Aggiungi_nodo_classifica(double n, long k, long* classifica, long* distanze_classifica){
  if(contatoreClassifica <= k){
    InsertHeap(distanze_classifica, classifica, n);
  }else{
    if(n<distanze_classifica[0]){
      ReplaceMaxHeap(distanze_classifica, classifica, n, k);
      InsertHeap(distanze_classifica, classifica, n);
      /*for (i = 0; i < contatoreStampa; i++) {
      printf("%ld ", classifica[i]);

        }
        printf("\n");
         for (i = 0; i < contatoreStampa; i++) {
        printf("%ld ", distanze_classifica[i]);}*/
    }
  }
}

//implementazione matrice di adiacenza
static void Aggiungi_grafo(long d, long k, long* classifica, long* distanze_classifica){
  long *distanza = (long*)calloc(d, sizeof(long*));
  long *visitato = (long*)calloc(d, sizeof(long*));
  long *matrice = (long*)calloc(d*d, sizeof(long*));
  long i=0, j=0;
  double n=0;
  for (j=0;j<d;j++){
    for (i=0;i<d;i++){
      matrice[j*d+i] = Parse();
      //printf("%ld\n", matrice[j*d+i]);
    }
  }
  n=Dijkstra(d, matrice, visitato, distanza);
  //printf("somma dei cammini minimi: %f\n", n);
  contatoreClassifica++; //andrò a stampare la classifica togliendo uno
  if(contatoreStampa<k){
    contatoreStampa++;
  }
  Aggiungi_nodo_classifica(n, k, classifica, distanze_classifica);
  /*for (i=0;i<d*d;i++){
    free(&matrice[i]);
  }*/
  free(matrice);
  matrice=NULL;
  free(visitato);
  visitato=NULL;
  free(distanza);
  distanza=NULL;
}

int main(int argc, char const *argv[]) {
  //D: numero nodi nei grafi
  //K: dimensione classifica
  long d=0,k=0;
  char c;
  if(scanf("%ld %ld\n", &d, &k)!=EOF){
    long *distanze_classifica = (long*)calloc(k, sizeof(long*));
    long *classifica = (long*)calloc(k, sizeof(long*));
    c=getchar();
    while(c!=EOF){
      if(c=='o'){
        if(getchar()=='\n'){
          Aggiungi_grafo(d, k, classifica, distanze_classifica);
          //printf("ciclo %ld\n", count);
        }
      }
      if(c=='K'){
        if(getchar()=='\n'){
          TopK(classifica, k);
        }
      }
      c=getchar();
    }
    free(classifica);
    free(distanze_classifica);
    return 0;
  }
}

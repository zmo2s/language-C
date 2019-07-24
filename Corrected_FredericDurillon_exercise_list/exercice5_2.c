#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct elem
  {
   //  int val;
     char s[80];
     struct elem* suiv;
  }t_elem;

t_elem* init(int taille,char *n);
void parcourir(t_elem* prem);
t_elem* ajoutDebut(t_elem*prem,t_elem*e);
void printTab(char T1[],int taille);
   int taille(t_elem* prem);

char* init1(t_elem *prem)
{
int cpt=0;
  char *T=NULL;
        T=malloc(taille(prem)-1);
//(char*)malloc(100*sizeof(char));
 cpt=0;
  char *b=NULL;
        b=malloc(taille(prem)-1);
//char *a="b";

//printf("a");
 while(prem != NULL)
 {
 strcpy(b,prem->s);

  /*

Tu n'as pas besoin de retourner la chaine, vu que tu la passe en paramètre, tu utilises donc un pointeur.
Donc les modifications apportées a la chaine dans la fonction sont repercutées sur la variable donnée en paramètre.

C'est pour cela, si tu l'as remarqué, que les fonctions de manipulation de chaine de caractère ne retournent pas de chaine.


strcpy ecrase la valeur précédente dnas T prend différente valeur
  */
 //T[cpt]=prem->s;
 prem=prem->suiv;
//  T[cpt]=prem->s;
//  b[cpt]=T;
//printf("%c",T[cpt]);
//printf("%s",prem->s);
// cpt++;
//
 }

//printf("%c",T[1]);
//printTab(b,6);
//strcpy(T,prem->s);


//printf("%s",T[0]);
 return b;

}

 int taille(t_elem* prem)
 {
   int cpt=0;
   if(prem==NULL)
   printf("liste vide");
   while(prem!=NULL)
   {

     prem=prem->suiv;
     cpt++;

   }
        printf("taille de la liste %d",cpt);
   return cpt;
 }

void printTab(char T1[],int taille)
{
 for( int i=0;i<taille-1;i++)
 {
 printf("%c",T1[i]);
  }
}



int main()
 {
t_elem *prem=NULL;
t_elem *nouveau;

char *n[]={"A","B","C","D","E"};
int taille= sizeof(n)/sizeof(char*);

//printf("%d",taille);

for(int i=taille-1 ; i>=0 ; i--)
{

   nouveau=init(taille,n[i]);
   prem=ajoutDebut(prem,nouveau);

  }
   parcourir(prem);

   char* T1=NULL;
   T1=malloc(sizeof(char));
//printTab(init1(prem),6);
T1=init1(prem);
printTab(T1,6);

//   printTab(T1,taille);
   return 0;
 }

t_elem* init(int taille,char *n)//taille,lettre,indice tableau(commence par dernier case du tableau puis on ajoute avec ajout debut
{

  t_elem*e=malloc(sizeof(t_elem));
 // printf("%s",n);
 strcpy(e->s,n);

  e->suiv=NULL;
  return e;
}

void parcourir(t_elem* prem)
 {
   if(prem==NULL)
   printf("liste vide");
   while(prem!=NULL)
   {
     printf("[%s] --",prem->s);
     prem=prem->suiv;
   }
   printf("NULL");
   putchar('\n');
 }

t_elem* ajoutDebut(t_elem*prem,t_elem*e)
 {
   e->suiv=prem;
   prem=e;
   return prem;
 }

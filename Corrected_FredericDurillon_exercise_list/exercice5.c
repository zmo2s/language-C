#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct elem
  {
     int val;
     char s[80];
     struct elem* suiv;
  }t_elem;

t_elem* init(int taille,char *n);
void parcourir(t_elem* prem);
t_elem* ajoutDebut(t_elem*prem,t_elem*e);

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
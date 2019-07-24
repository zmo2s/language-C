

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem
  {
     int val;
     char s[80];
     struct elem* suiv;
  }t_elem;



t_elem* init1()
{
  int n;
 scanf("%d", &n); 

  t_elem*e=malloc(sizeof(t_elem));
  e->val=n;
  
  e->suiv=NULL;
  return e;
}

t_elem* ajout_debut1(t_elem*prem,t_elem*e)
 {
   e->suiv=prem;
   prem=e;
   return prem;
 }

 void parcourir(t_elem* prem)
 {
   if(prem==NULL)
   printf("liste vide");
   while(prem!=NULL)
   {
     printf("[%d%s] --",prem->val,prem->s);
     prem=prem->suiv;
   }
   printf("NULL");
   putchar('\n');
 }



t_elem* creerListe(t_elem *premier,t_elem *premier2)
{
int n;
 scanf("%d", &n); 

          for(int i=0;i<n;i++)
          {
            premier2=init1();
            premier=ajout_debut1(premier,premier2);
          }
    return premier;
}

t_elem* reverseList(t_elem* prem)
{
 if(prem==NULL){
  printf("liste vide");
               }
  t_elem *prev=NULL; 
  t_elem *current=prem;
  t_elem *next=NULL;
  while(current != NULL)
 {
  
  next=current->suiv;
  current->suiv=prev;
  prev=current;
  current=next;
 }

  return prev;
}


int main()
{
  t_elem *prem=NULL;
  t_elem *prem2=NULL;
  prem=creerListe(prem,prem2);
  parcourir(prem);
    printf("liste renversé ");
  prem=reverseList(prem);
  parcourir(prem);
  
}



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

//on peut pas utilsié de bouléeen en C comem en C++

void tri(t_elem* prem)
{
int a = 1;t_elem *next = NULL;
if (prem == NULL)
 printf("liste vide");
while(prem->suiv != NULL)
{
next=prem->suiv;
if(prem->val > next->val)
{
a=0;
}
prem=prem->suiv;
}
if(a==1)
printf("la liste est trie");
else 
printf("la lsitee n'est pas trie");

}

t_elem* insert(t_elem *prem,t_elem *e)
{
  if(prem == NULL)
  printf("liste vide");
  if(prem-> val >= e->val)
   {
    e->suiv=prem;
    prem=e; 
   }
else {
t_elem *p;
p=prem;
t_elem *prec=prem;
 while( p != NULL && p->val < e->val)
   {
   prec=p;
   p=p->suiv;
  
   }
 e->suiv=p;
 prec->suiv=e;
 }
return prem;
}

int main()
{
  t_elem *prem1=NULL;
  t_elem *prem2=NULL;
  
  prem1=creerListe(prem1,prem2);
  parcourir(prem1);

 tri(prem1);
  prem2=init1();
  prem1=insert(prem1,prem2);
   parcourir(prem1);
  
 
  
}

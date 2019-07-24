

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

t_elem* concatenation(t_elem* prem1,t_elem *prem2)
{
/* if(prem1 ==NULL && prem2 == NULL)
 printf("les lsite sont vide");
*/
t_elem *p=NULL;
 if(prem1==NULL)
  return prem2;
 if(prem2==NULL)
{
  return prem1;
 }    
 
p=prem1;         
  while(p->suiv != NULL)
 {
  
  p=p->suiv;
  
 }

 p->suiv=prem2;

  return prem1;
}


int main()
{
  t_elem *prem1=NULL;
  t_elem *prem2=NULL;
  
  t_elem *prem3=NULL;
  t_elem *prem4=NULL;

  t_elem *prem5=NULL;
  prem1=creerListe(prem1,prem2);
 parcourir(prem1);
  prem3=creerListe(prem3,prem4);
 
  parcourir(prem3);
  
    printf("liste renversé ");
  prem5=concatenation(prem1,prem3);
  parcourir(prem5);
  
}

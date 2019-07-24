

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


t_elem* init2()
{
 

  t_elem*e=malloc(sizeof(t_elem));
  e->val=0;

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


// Main function that inserts nodes of linked list q into p at  
// alternate positions. Since head of first list never changes  
// and head of second list may change, we need single pointer  
// for first list and double pointer for second list.  
void fusion(t_elem *p,t_elem **q)  
{  
   t_elem *p_curr = p, *q_curr = *q;  
   t_elem *p_next, *q_next;  
  
    // While therre are avialable positions in p  
    while (p_curr != NULL && q_curr != NULL)  
    {  
        // Save next pointers  
        p_next = p_curr->suiv;  
        q_next = q_curr->suiv;  
  
        // Make q_curr as next of p_curr  
        q_curr->suiv = p_next; // Change next pointer of q_curr  
        p_curr->suiv = q_curr; // Change next pointer of p_curr  
  
        // Update current pointers for next iteration  
        p_curr = p_next;  
        q_curr = q_next;  
    }  
  
    *q = q_curr; // Update head pointer of second list  
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

void parite(t_elem *prem,t_elem *pair,t_elem *impair)
{
   t_elem *e=prem;
   t_elem *nouveau;


int a;
   while (e != NULL)
  {
   nouveau=init2();
   nouveau->val=e->val;
a=e->val;
   if(a %2 ==0)
  impair= ajout_debut1(impair,nouveau);
   else
  pair= ajout_debut1(pair,nouveau);

 e=e->suiv;

//printf(" a val %d",a);

  }

parcourir(pair);

parcourir(impair);
}

int main()
{
  t_elem *prem1=NULL;
  t_elem *prem2=NULL;

  t_elem *prem3=NULL;
  t_elem *prem4=NULL;
    t_elem *prem5=NULL;

  prem1=creerListe(prem1,prem5);
    parcourir(prem1);
 // prem3=creerListe(prem3,prem4);
 // parcourir(prem3);


  parite(prem1,prem2,prem3);//on peut faire un void car on ne renvoei pas de nouvelle liste on change jsute les valeur des lsites 
  parcourir(prem2);
   parcourir(prem3);


}

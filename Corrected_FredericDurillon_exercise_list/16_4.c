//principe on créer un maillon en plus dnas la lsite qui remeterra la liste au début pour chaque nouvelle itération puis on supprime ce maillon

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



t_elem* initRight()
{
   char *n[]={"->"};

  t_elem*e=malloc(sizeof(t_elem));
  strcpy(e->s,n[0]);
 e->val =5;
  e->suiv=NULL;
  return e;
}


t_elem* initLeft()
{
   char *n[]={"<-"};

  t_elem*e=malloc(sizeof(t_elem));
  strcpy(e->s,n[0]);
 e->val=4;
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



t_elem* creerListe(t_elem *premier,int n)
{
  n=n+2;
  double a=pow(2,n-3);
  for(int i=0;i<a;i++)

   {
        t_elem *premier2=initRight();
        t_elem *premier3=initLeft();
            premier=ajout_debut1(premier,premier2);
            premier=ajout_debut1(premier,premier3);

   }

    return premier;
}

void afficher(t_elem* prem,int n)
{
  while()

  printf("")
}

int main()
{
  t_elem *prem1=NULL;
  //t_elem *prem2=NULL;

  int n;
   scanf("%d", &n);

   if( n>=1)
  prem1=creerListe(prem1,n);
  afficher(prem,n);
  //int occ=0;
  //occ=occurrence(prem1,n);
//printf("occ %d",occ);

  //if(n>1)

    parcourir(prem1);


 return 0;


}

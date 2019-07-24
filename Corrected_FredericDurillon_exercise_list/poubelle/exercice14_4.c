
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem
  {
     int val;
     char s[80];
     struct elem* suiv;
     struct elem* prec;
  }t_elem;



t_elem* init1()
{
  int n;
 scanf("%d", &n);

  t_elem*e=malloc(sizeof(t_elem));
  e->val=n;

  e->suiv=NULL;
  e->prec=NULL;
  return e;
}

t_elem* ajout_debut1(t_elem*prem,t_elem*e)
 {
   e->suiv=prem;
   prem->prec=e;
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


t_elem* josepheFlavius(t_elem **prem)
{
 int cpt=1;
 t_elem* n=*prem;
 t_elem *prec=NULL;
 t_elem *supp=NULL;
int j=taille(*prem);
 
    while( j != 1)
     {
  // printf("j %d",j);
         if( j % 2 == 0)
         {

            while(n != NULL)
            {

   if(cpt %2 ==0)
                {
                   prec->suiv=n->suiv;
                   supp=n;
                   free(supp);
             
                }


                 prec=n;
                   n=n->suiv;
            
                 printf("ok");
           
                      cpt++;
        }
           
       }

               
         else {
                  while( n!=NULL)
                       {
                    if(prec==NULL)
                {
                 // supp=*prem;
                   //*prem=NULL;
                   *prem=n->suiv;
                  //  free(supp);
                   prec=*prem;
                n=n->suiv;
cpt++;
    
                 }
        
   if(cpt %2 !=0 && cpt !=0)
                {
                   prec->suiv=n->suiv;
                   supp=n;
                   free(supp);
             
                }


                 prec=n;
                   n=n->suiv;
            
                 printf("ok");
           
                      cpt++;
        }

    
              }
    t_elem *c;
        c=*prem;
       *prem=c;
      j=j-1;
    parcourir(*prem);
  }

 return *prem;
}

int main()
{
  t_elem *prem1=NULL;
  t_elem *prem2=NULL;

  prem1=creerListe(prem1,prem2);
  parcourir(prem1);

  prem1= josepheFlavius(&prem1);

   parcourir(prem1);



}

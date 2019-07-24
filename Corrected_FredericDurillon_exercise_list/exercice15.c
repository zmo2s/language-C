
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

t_elem* pairListe(t_elem **prem)
{

 int cpt=1;
 t_elem* n=*prem;
 t_elem *prec=NULL;
 t_elem *supp=NULL;
int j=taille(*prem);


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
           
       
 return *prem;

}

t_elem* impairListe(t_elem **prem)
{


 int cpt=1;
 t_elem* n=*prem;
 t_elem *prec=NULL;
 t_elem *supp=NULL;
int j=taille(*prem);

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
        
   if(cpt %2 !=0)
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
    return *prem;
              }




t_elem* supprimeMaillon(t_elem* prem)
{
  t_elem* prec;
  if(prem!=NULL)
   {
     prec=prem;
     prem=prem->suiv;

     free(prec);

   }
   return prem;
}


int decalageList(t_elem *prem, int n)
{

  t_elem *e=prem;
  int cpt=0;
  int decalage=0;
  int decompte=0;
  while (e!=NULL)
   {
    e=e->suiv;
    cpt++;
    if(cpt % n ==0)
     {
      decalage += cpt;
      cpt=0;
     } 
   }
 printf("decalage est de %d", decalage);


   decompte=taille(*prem)-decalage;

  return decompte;
}

t_elem* josepheSupprimeMaillon(t_elem ** prem,int n,int decompte)
{

  t_elem* e=*prem;
  
  while(decompte !=0)
   {
    decalage--;
    e=e>suiv;
   }

   int cpt=1;
 t_elem* n=*prem;
 t_elem *prec=NULL;
 t_elem *supp=NULL;
int j=taille(*prem);

                  while( n!=NULL)
                       {
                    if(decompte ==0)
                {
                 // supp=*prem;
                   //*prem=NULL;
                   *prem=n->suiv;
                  //  free(supp);
                   prec=*prem;
                n=n->suiv;
cpt++;
    
                 }
        
   if(cpt % n ==0)
                {
                   prec->suiv=n->suiv;
                   supp=n;
                   free(supp);
             
                }


                 prec=n;
                   n=n->suiv;
            
                 printf("ok");
           
                      cpt++;

return *prem;
 
}

t_elem* josephe(t_elem **prem, int n)
{


 t_elem* n=*prem;

int j=taille(*prem);
int decalage =decalageList(t_elem *prem, int n)
 *prem=pairListe(&(*prem));



    while( j > n)
     {


 j=taille(*prem);
        *prem=josepheSupprimeMaillon(&(*prem),n,decalage);

  parcourir(*prem);

   }  
   j<=n
 .....

 return *prem;
}


}

int main()
{
  t_elem *prem1=NULL;
  t_elem *prem2=NULL;

  prem1=creerListe(prem1,prem2);
  parcourir(prem1);

  decalageList(prem1,3);

   parcourir(prem1);



}

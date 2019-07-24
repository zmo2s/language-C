//principe on créer un maillon en plus dnas la lsite qui remeterra la liste au début pour chaque nouvelle itération puis on supprime ce maillon

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
   char *n[]={"p1","p2","p3","p4","p5","p6","p7","p8","p9","p10","pj","pq","pr", "t1","t2","t3","t4","t5","t6","t7","t8","t9","t10","tj","tq","tr","c1","c2","c3","c4","c5","c6","c7","c8","c9","c10","cj","cq","cr","ca1","ca2","ca3","ca4","ca5","ca6","ca7","ca8","ca9","ca10","caj","caq","car"};

  t_elem*e=malloc(sizeof(t_elem));
  strcpy(e->s,n[rand()%52]);

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


   char* concat(char* str1, char* str2)
   {
      char * str3 = (char *) malloc(1 + strlen(str1)+ strlen(str2) );
      strcpy(str3, str1);
      strcat(str3, str2);
    //  printf("%s", str3);
      strcpy(str1,str3);
   }

t_elem* creerListe(t_elem *premier,t_elem *premier2)
{
int n;
 scanf("%d", &n);
 n=n+1;

          for(int i=0;i<n;i++)
          {
            premier2=init1();
            premier=ajout_debut1(premier,premier2);
          }
    return premier;
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


t_elem* distribution(t_elem * prem)
{

 t_elem *n=prem;
t_elem *next;
t_elem *e=prem;
t_elem *next1=e;
  t_elem *nouveau;
 int a = 0;
 int j=taille(prem);


printf("valeru de j %d",j);
   char *K[]={"p1","p2","p3","p4","p5","p6","p7","p8","p9","p10","pj","pq","pr", "t1","t2","t3","t4","t5","t6","t7","t8","t9","t10","tj","tq","tr","c1","c2","c3","c4","c5","c6","c7","c8","c9","c10","cj","cq","cr","ca1","ca2","ca3","ca4","ca5","ca6","ca7","ca8","ca9","ca10","caj","caq","car"};

  while(a<52)
  {
         if(a<j)
          {
            nouveau=init1();
            n=ajout_debut1(n,nouveau);
            n=n->suiv;
          }
             else{
                    concat(n->s,K[rand()%52]);

                    n=n->suiv;
                    next=n->suiv;
                        if(next==NULL)
                         {
                           n=prem;
                          }



                 }

              a++;

  }
/*  t_elem *prec;t_elem* supp;
while(prem != NULL)
{

  prec=e;
  e=e->suiv;

/*  if(e->suiv=NULL)
{
  prec->suiv=e->suiv;
  supp=e;
  free(supp);



}
*/
int i=1;
t_elem *prec;t_elem * supp;t_elem* arr;
n=prem;
while(i<j){
prec=n;
n=n->suiv;
i++;

}
printf("leee %s",n->s);

prec->suiv=n->suiv;
supp=n;
free(supp);



   return prem;
}
int main()
{
  t_elem *prem1=NULL;
  t_elem *prem2=NULL;


  prem1=creerListe(prem1,prem2);
    parcourir(prem1);


 prem1=distribution(prem1);
   parcourir(prem1);



}

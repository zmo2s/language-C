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
   char *n[]={"->","1"};

  t_elem*e=malloc(sizeof(t_elem));
  strcpy(e->s,n[0]);

  e->suiv=NULL;
  return e;
}


t_elem* init2()
{
   char *n[]={"0","<-"};

  t_elem*e=malloc(sizeof(t_elem));
  strcpy(e->s,n[1]);

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
     printf("[%s] --",prem->s);
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
void cell(t_elem **prem,int pos)
{
  t_elem* e=*prem;
  int cpt =1;
  char *h[]={"->","<-"} ;


 while(e!=NULL && pos >0)
{
 pos--;
e=e->suiv;

}


  while(e!= NULL && cpt >=0)
   {

  //printf("ahhh");
  if( cpt <=4)
      strcpy(e->s,h[0]);
  if( cpt > 4 && cpt <=9)
       strcpy(e->s,h[1]);
if(cpt ==9)
cpt=-1;

cpt++;
e=e->suiv;

  }

}

void cell2(t_elem **prem,int pos)
{
  t_elem* e=*prem;
  int cpt =1;
  char *h[]={"->","<-"} ;


 while(e!=NULL && pos >0)
{
 pos--;
 e=e->suiv;

}


  while(e!= NULL && cpt >=0)
   {

  //printf("ahhh");
  if( cpt <=4)
      strcpy(e->s,h[0]);
  if( cpt > 4 && cpt <=9)
       strcpy(e->s,h[1]);
if(cpt ==9)
cpt=-1;

cpt++;
e=e->suiv;

  }

}


void ajoutFin(t_elem **prem)
{
  t_elem *e=*prem;
 t_elem *prec;
t_elem *nouveau=init2();
while(e->suiv!=NULL)
 {
    prec=e;
    e=e->suiv; 
 
 }
e->suiv=nouveau;
prec->suiv=e;


}


void compte(t_elem **prem)
{

 t_elem *e=*prem;
 t_elem *next=*prem;
 t_elem *v;
 t_elem *b;
t_elem *prec=*prem;
 char *h[]={"->","<-"} ;
 next=next->suiv;
 while(next->suiv!= NULL)
  {
    if(strcmp(e->s,next->s) == 0)
       {
          printf("error");
       }
   else {
 printf("aaaaaaahhhhhhh");
     if(strcmp(e->s,h[0])==0)
       {
              b=init1();
             b->suiv=e;
         prec->suiv=b;
  printf("aaaaaaahhhhhhh");
       }

    else {         v=init2();
v->suiv=next;
         prec->suiv=v;}

         }




prec=e;
 e=e->suiv;
 next=next->suiv;
}
       }

int identique(t_elem *prem)
{
  t_elem *e=prem;
  t_elem* next= prem;
next=next->suiv;
  int occurrence=0;
   int cpt=1;
  int save =0;
int g=0;
int draget=0;

 while (next!=NULL)
 {
 if(strcmp(e->s,next->s)==0)
  {
  cpt++;
  if(cpt>save)
{
save =cpt;
//g=draget;
} 
  }
else {

cpt=2; }
  next=next->suiv;
  draget++;
e=e->suiv;
 }
g=g-9;
printf("la valeur de save %d",save);

 return save;
}

int position(t_elem *prem)
{
t_elem *e=prem;
  t_elem* next= prem;
next=next->suiv;
  int occurrence=0;
   int cpt=1;
  int save =0;
int g=0;
int draget=1;
int r=0;

 while (next!=NULL)
 {
 if(strcmp(e->s,next->s)==0)
  {
  cpt++;
  if(cpt>save)
{
save =cpt;
//g=draget;
} 
  }
else {

cpt=2; }
  next=next->suiv;
  draget++;
e=e->suiv;

 if( cpt ==9)
{
 r=draget-9;
break;
}
 }
g=g-9;
printf("la valeur de save %d",save);
printf("la valeur de r %d",r);

 return r;
}



t_elem* creation(t_elem **prem,int n)
{
 int elem=4;
  t_elem* prem2;
  t_elem *e=*prem;

int j =4;
int a=0;
int g=0;
int k=5;
int pos=0;

     for(int i=0;i<elem;i++)
          {
            prem2=init2();
            *prem=ajout_debut1(*prem,prem2);
          }

      for(int h=0;h<k;h++)
 {
             prem2=init2();
          *prem=ajout_debut1(*prem,prem2);

        }


  while(a<=n)
      {



  parcourir(*prem);
if(identique(*prem)>=9){
pos=position(*prem);
printf("position %d",pos);

if(a<10)
cell(&(*prem),pos);
else
cell2(&(*prem),pos);
  parcourir(*prem);
                      }



if( a >9)
{


compte(&(*prem));
ajoutFin(&(*prem));

}

a++;
pos=0;
   }


 // parcourir(*prem);
 return *prem;
}



int main()
{
  t_elem *prem1=NULL;
  int n;
 scanf("%d", &n);

  prem1=creation(&prem1,n);
    parcourir(prem1);






}

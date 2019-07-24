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


t_elem* init()
{
  
  t_elem*e=malloc(sizeof(t_elem));
  e->val=rand()%1000;
  
  e->suiv=NULL;
  return e;
}


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

 void ajout_debut2(t_elem** prem,t_elem* e) //attentino c'est un void pas besoin de return
 {
   e->suiv=*prem;
   *prem=e;

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

void DeleteListe(t_elem **prem)
{
  t_elem*prec;
  while(*prem!=NULL)
   {
     prec=*prem;
    *prem=(*prem)->suiv;

     free(prec);
   }

}

void sommeListe(t_elem *prem)
{
  int som=0;

  if(prem==NULL)
   {printf("liste vide ");}
  

  while(prem != NULL)
  {
    som+=prem->val;
    prem=prem->suiv;
  }
    printf("La somme de la lsite est de = %d \n",som);
    
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

t_elem* milieuListe(t_elem *prem)
 {
 int longueur=ceil(( taille(prem)-2)/2.0);
 
 printf("longueur =%d",longueur);
 int cpt=0;
   if(prem == NULL)
    printf("erreur liste nulle");
   while(cpt<longueur)
   {
     prem=prem->suiv;
     cpt++;
   }
  
    prem->val=-1;
     
return prem;
 }

t_elem* maillonInferieur(t_elem *prem)
{

  if(prem==NULL)
  {
    printf("liste vide");
  }
  while ( prem != NULL)
   {

    if( prem->val <=500)
     {
       prem->val=-prem->val;
 
     } 
       prem=prem->suiv;
   }
    return prem;
 
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

t_elem* intervalleMaillon(t_elem *prem)
{

 t_elem *prec=NULL;
 t_elem *e=prem;
 t_elem *n;
 
 /*
  if(prem==NULL)
  {
    printf("liste vide");
  }*/
 while (e!=NULL)
  {
 n=NULL;
    if( e->val <=500 && e->val >=300)
     {
       n=e;
   if(prec==NULL)  {    
      prem=e->suiv;
    //  free(n);
}

    else{
              prec->suiv=e->suiv;
           }
    }
     else{ 
              prec=e;
         }  
              e=e->suiv;
        
    if(n!=NULL)
   free(n);
   }
    return prem;

  
}

t_elem* dupliqueMaillon(t_elem *prem)
{
t_elem *b=init1();
t_elem *e;
t_elem *prec;

 //int n;
// scanf("%d", &n); 


  if(prem == NULL)
    printf("liste vide");
  if(b->val== prem->val)
   {
     b->suiv=prem;
     prem=b;
  
   }
e=prem;
int c = taille(prem)-2;
e=e->suiv;int i=0;
 while( i<c )//longueur liste n-1
      {
i++;
//b=init1();
     prec=e;
     e=e->suiv;
    if(b->val==e->val)
   {
     b->suiv=e;
    prec->suiv=b;
   
        printf("la val de e  %d la val de b %d",e->val,b->val);
   }
  
}
   return prem;

}

void saveListe(t_elem*prem)
{
  FILE*f;
  if(prem!=NULL)
   {
     if((f=fopen("save liste.bin","wb"))!=NULL)
     {
       while(prem!=NULL)
         {
           fwrite(prem,sizeof(t_elem),1,f);
           prem=prem->suiv;
         }

         fclose(f);
     }
     else
      printf("erreur création fichier \n");
   }
   else
    printf("pas de sauvegarde pour une lsite vide \n");
}

t_elem* chargeListe()
{
  FILE*f;
  t_elem*prem=NULL,*p,e;
  if((f=fopen("save liste.bin" ,"rb"))!=NULL)
  {
    prem=malloc(sizeof(t_elem));
    fread(prem,sizeof(t_elem),1,f);
   p=prem;
   while(fread(&e,sizeof(t_elem),1,f))
   {
   p->suiv=malloc(sizeof(t_elem));
   p=p->suiv;
   *p=e;
   p->suiv=NULL;
 }
 fclose(f);
}
else
   printf("erreur ou fichier inexcistent ");
  return prem;

}

void selection()
{
   t_elem* premier = NULL;
   t_elem* premier2;
   int a;
  while(a!=0)
   {

printf("\n Veuillez choisir parmis les options proposé \n \n  1-remplir la liste \n  2-afficher la lsite  \n  3-detruire la liste \n  4-somme de la liste \n  5-milieuListe \n  6-maillonInferieur \n  7-creerListe \n  8-intervalleMaillon \n  9-dupliquerMaillon \n  10-saveListe   \n  11-chargeListe \n \n saisir la valeur de a : ");
     scanf("%d", &a); 


    

     if(a ==1)
       {
         for(int i=0;i<5;i++)
          {
            premier2=init();
            ajout_debut2(&premier,premier2);
          }

 
       }
     if(a==2)
      { parcourir(premier); }


     if(a==3)
     { DeleteListe(&premier); }

     if( a==4)
      {sommeListe(premier);}
      
    if(a==5)
     {milieuListe(premier);}

    if(a==6)
     {maillonInferieur(premier);}
     if(a==7)
      {premier=creerListe(premier,premier2);} // !!!!!!!!! on ne peut pas utiliser ajoutdebut 2 dnas une fonction meme par adresse sa reste dnas la fonction
     if(a==8)
     {premier=intervalleMaillon(premier);} // !!!!!!!  idem ici la valeur de premier n'est pas changer sa reste 
//une copie donc la lsite reste de la meme taille pour pouvoir changer la taille de la liste il faut mettre premier = fonction cela réecrit complétement la lsite de plus lafonctino est réutilsié par la fonctino parcourir

     if(a==9)
     {premier=dupliqueMaillon(premier);}
      
       if(a==10)
     {saveListe(premier);}
       
      if(a==11)
     {premier=chargeListe(premier);}
  }
    
}
int main()
 {
 

selection();
 

   return 0;
 }
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct elem
  {
     int val;
     char s[80];
     struct elem* suiv;
  }t_elem;


t_elem* init()
{
  char* n[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  t_elem*e=malloc(sizeof(t_elem));
  e->val=rand()%26;
  strcpy(e->s,n[rand()%26]);
  e->suiv=NULL;
  return e;
}

t_elem* init1(int i)
{
  char* n[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  t_elem*e=malloc(sizeof(t_elem));
  //int a=0;
  //a=sizeof(&n)/sizeof(char[0]);
  strcpy(e->s,n[i]);
  e->suiv=NULL;


  return e;
}

t_elem* init2(int i)
{

  t_elem*e=malloc(sizeof(t_elem));
e->val=i*2;

  e->suiv=NULL;


  return e;
}
t_elem* init3(int i)
{
t_elem*e=malloc(sizeof(t_elem));
e->val=i*2+1;

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

t_elem* ajout_debut3(t_elem*prem,t_elem*e)
 {
   e->suiv=prem;
   prem=e;
   return e;
 }

 void parcourir(t_elem* prem)
 {
   if(prem==NULL)
   printf("liste vide");
   while(prem!=NULL)
   {
     printf("%d%s --",prem->val,prem->s);
     prem=prem->suiv;
   }
   putchar('\n');
 }


 void parcourir1(t_elem* prem)
 {
   if(prem==NULL)
   printf("liste vide");
   while(prem!=NULL)
   {
     printf("%d --",prem->val);
     prem=prem->suiv;
   }
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

 t_elem* insert(t_elem* prem,t_elem* e)
 {
   t_elem*n,*prec;
   if(prem==NULL || e->val <= prem->val)
   {
     e->suiv=prem;
     prem=e;

   }
   else{
     n=prec=prem;
     while(n!=NULL && e->val > n->val)
     {
     prec=n;
     n=n->suiv;
   }
   e->suiv=n;
   prec->suiv=e;
 }
 return prem;
}

t_elem* insert1(t_elem** prem,t_elem* e)
{
  t_elem*n,*prec;
  if(prem==NULL)
  {

    *prem=e;

  }
  else if (e->val >(*prem)->val){
    e->suiv=*prem;
    *prem=e;
  }
    else{
    n=prec=*prem;
    while(n!=NULL && e->val < n->val)
    {
    prec=n;
    n=n->suiv;
  }
  e->suiv=n;
  prec->suiv=e;
}

}


t_elem* insert2(t_elem** prem,t_elem* e)
{
  t_elem*n,*prec;
  if(prem==NULL)
  {

    *prem=e;

  }
  else if (e->val <(*prem)->val){
    e->suiv=*prem;
    *prem=e;
  }
    else{
    n=prec=*prem;
    while(n!=NULL && e->val > n->val)
    {
    prec=n;
    n=n->suiv;
  }
  e->suiv=n;
  prec->suiv=e;
}

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

t_elem* SupprimeMaillonPrecis(t_elem* prem,int val)
{

t_elem*e =prem,*prec=NULL,*n;
 while(e!=NULL)
 {
   n=NULL;
   if(e->val==val)
   {
     n=e;

     if(prec==NULL)
     {
       prem=e->suiv;//si pas de précèdant  le second element devient premier
     }
       else{
             prec->suiv=e->suiv;
           }
      }
           else {
             prec=e;
           }
           e=e->suiv;
            if(n!=NULL)
            free(n);

   }
   return prem;
 }




t_elem* DeleteListe(t_elem *prem)
{
  t_elem*prec;
  while(prem!=NULL)
   {
     prec=prem;
     prem=prem->suiv;

     free(prec);
   }

}

void sauver_liste(t_elem*prem)
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

t_elem* load_liste()
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

t_elem* copie_liste(t_elem*prem)
{
  t_elem*prem2=NULL,*e,*p;
  if(prem != NULL){
   prem2=(t_elem*)malloc(sizeof(t_elem));
   prem2->val=prem->val;
   strcpy(prem2->s,prem->s);
   prem2->suiv=NULL;
   p=prem2;
   prem=prem->suiv;

  while(prem!=NULL)
   {
    e=(t_elem*)malloc(sizeof(t_elem));
    e->val=prem->val;
    strcpy(e->s,prem->s);
    e->suiv=NULL;
    p->suiv=e;

    p=e;
    prem=prem->suiv;
   }
                  }
                  return prem2;
}
/*


t_elem* triliste(t_elem* prem)
{
  t_elem*e,*n,*save;


n=n->suiv;

  if(prem->val>n->val)
  {
    save=prem;
    supprimeMaillon(prem);
    insert(save,save);

  }


while(n!=NULL)
{
n=prem;
if(n!=NULL && e->val < n->val)
{
n=n->suiv;
}
else if (e->val > n->val && n!=NULL)
  {
    save =e;
    SupprimeMaillonPrecis(e->val);
    insert(save,save);
    n=n->suiv;
    e=e->suiv;
  }

}

*/
int main()
 {
   t_elem* premier = NULL;
   t_elem* premier2=NULL;
   t_elem* nouveau;
   t_elem* premier1 = NULL;
   t_elem* nouveau1;
   t_elem* nouveau2;
   t_elem*nouveau3;
   t_elem*premier3=NULL;
   t_elem*premier4=NULL;
   t_elem* nouveau4;
   t_elem* premier5=NULL;
   t_elem* premier6=NULL;
   t_elem* nouveau6;
   t_elem* premier7=NULL;
   t_elem* premier8=NULL;
 t_elem* premier9=NULL;
   //t_elem*premier4={1,2,3,4,5};
   int i;
   for(i=0;i<10;i++)
   {
     nouveau=init();//ajout1
     nouveau1=init();//ajout2
     premier=ajout_debut1(premier,nouveau);//
     nouveau2=init1(-i+9);
       //nouveau5=init3();
       nouveau3=init2(i+9);
       premier2=ajout_debut1(nouveau1,nouveau2);
         //premier3=init3(3);
      premier3=ajout_debut1(premier3,nouveau3);



           premier4=init3(i-4);
//premier4=insert(premier4,premier3);
   }

   for(int i=10;i>0;i--)
   {
       nouveau6=init2(i);
       premier6=ajout_debut1(premier6,nouveau6);
   }


   nouveau4=init3(12);

  insert1(&premier3,nouveau4);
  ajout_debut2(&premier,nouveau);//on peut pas utilise fonction debut1 et début2 sur une meme liste initialisé nouveau mais on peut utiliser premier pour les 2
  insert2(&premier6,nouveau4);
    premier6=supprimeMaillon(premier6);
premier6=SupprimeMaillonPrecis(premier6,8);
//premier6=DeleteListe(premier6);
sauver_liste(premier6);
premier7=load_liste();
premier8=copie_liste(premier7);

//premier9=ajout_debut3(premier9,premier8)
parcourir(premier8);

  taille(premier3);

//  parcourir2(nouveau3);
   return 0;
 }

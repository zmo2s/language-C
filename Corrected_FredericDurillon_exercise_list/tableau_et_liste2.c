#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node *next;
} Node;
 
 
Node *current[20];
 
void insert_beg_of_list(int data,int i);
 
void print_list(int i);
 
 
 
void insert_beg_of_list(int data,int i) {
 
 
    /*First create a new node  head */
    Node *head;
    head=(Node*)malloc(sizeof(Node));
    head->data=data;
    head->next=current[i];
    current[i]=head;

     }
 
 
 
void print_list(int i) {
 
 
    Node *temp;
    temp=current[i];
    while(temp!=NULL)
    {
    	  printf("%d ",temp->data);
    	  temp=temp->next;
    }

}
 
 
 
int main() {
 
 
    int data = 0 ;
    int usr_input = 0;
    int i;
    int m;
    int j;
    int cpt=0;
    int a;


        printf("saisir taille tableau");


        scanf("%d", &a);


        for(int k=0;k<a;k++)
        {
         current[k]=0;
         }

    while (cpt <a){

        printf("saisir taille de la liste en clonne");

        scanf("%d", &usr_input);
 


        for (i=0; i<usr_input; i++)
       
           {
               
             
            printf("saisir  les nombre de la liste en colonne");              

            scanf("%d", &data);
    
            insert_beg_of_list(data,cpt);
     
            }
       cpt++;

               }

            printf("The list is ");
      for( j=0;j<a;j++){

           print_list(j);

                      }

            printf("\n\n");
 
           return 0;
}
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node *next;
} Node;
 
 
Node *current[20];
 
void insert_beg_of_list(int data);
 
void print_list();
 
 
 
void insert_beg_of_list(int data) {
 
 
    /*First create a new node  head */
    Node *head;
    head=(Node*)malloc(sizeof(Node));
    head->data=data;
    head->next=current[0];
    current[0]=head;
     }
 
 
 
void print_list() {
 
 
    Node *temp;
    temp=current[0];
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
 
        scanf("%d", &usr_input);
 
        current[0]=NULL;
        for (i=0; i<usr_input; i++) {
 
            scanf("%d", &data);
            insert_beg_of_list(data);
 
        }
 
            printf("The list is ");
            print_list();
            printf("\n\n");
 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 256
#define LIST_MAX 10

struct node {
	char name[NAME_MAX];
	node *link;
};

struct node* createNode(const char *name);
struct node* createCircularList(const char *names[], int numNames);
void printCircularList(struct node* head, int nums);
void deleteNodeAfter(struct node *theNode);
void printNode(struct node *theNode);

int main()
{
	//typically this is set to three
	//every third is killed
	int n = 3;
	
	const char *soldiers[LIST_MAX];
	struct node* listHead;
	struct node* position;

	soldiers[0] = "Aaron";
	soldiers[1] = "Benjamin";
	soldiers[2] = "Samuel";
	soldiers[3] = "Caleb";
	soldiers[4] = "Daniel";
	soldiers[5] = "Jacob";
	soldiers[6] = "Elliot";
	soldiers[7] = "Gabriel";
	soldiers[8] = "John";
	soldiers[9] = "Michael";

	//create the list
	listHead = createCircularList(soldiers, LIST_MAX);
	//test to make sure list works
	printCircularList(listHead, LIST_MAX + 4);

	//eliminate every third soldier
	position = listHead;
	do {
		for (int i = 0; i < n-1; i++) { 			
                    position = position->link;
		}
		printf("We will kill ");
		printNode(position->link);
		printf("\n");
		deleteNodeAfter(position);
	} while (position->link != position);

	printNode(position);
	printf(" is left...\n");
	return 0;
}

void deleteNodeAfter(struct node *theNode) {
	struct node*temp = theNode->link;
	theNode->link = temp->link;
	free(temp);
}

void printNode(struct node *theNode) {
	printf("%s", theNode->name);
}

struct node* createCircularList(const char *names[], int numNames) {
	int i = 0;
	node *head, *temp, *tail;
	head = createNode(names[i++]);
	tail = head;
	for (i; i < numNames; i++) { 		
                 temp = createNode(names[i]); 		
                //make the current tail link to the new node 		
                 tail->link = temp;
		//make the new node link back to the head
		temp->link = head;
		//make the new node the tail
		tail = temp;
	}

	return head;

}

void printCircularList(struct node* head, int nums) {
	struct node*temp = head;
	for (int i = 0; i < nums; i++) { 		
                printf("Name: \t%s\n", temp->name);
		temp = temp->link;
	}
}

struct node* createNode(const char *name) {
	node * newNode = (node*)malloc(sizeof(node));
	//copy name to new node
	if (strlen(name) < NAME_MAX) { 		
           strcpy_s(newNode->name, NAME_MAX, name);
	}
	//initialize link to point to itself
	newNode->link = newNode;
	return newNode;
}
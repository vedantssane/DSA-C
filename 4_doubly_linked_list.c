#include<stdio.h>
#include<stdlib.h>

void insertBegg(int value);
void insertEnd(int value);
void deleteBegg();
void deleteEnd();
void display();
void displayrev();

void main() {
    int value , choice;

    while (1) {
        printf("\n===== Doubly Linked List Menu =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Reverse\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertBegg(value);     
            break;
        
        case 2 :
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);     
            break;

        case 3:
            deleteBegg();     
            break;

        case 4:
            deleteEnd();     
            break;

        case 5:
            display();
            break;

        case 6:
            displayrev();
            break;

        case 7:
            printf("Thanks for using us!!!!");

        default:
            printf("Invalid choice!");
            break;
        }
    }
}

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNewNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode ->data = value;
    newNode ->prev = NULL;
    newNode -> next = NULL;
    return newNode;
};

void insertBegg(int value) {

    struct Node *newNode = createNewNode(value);
        if(head == NULL)
            {
            head = newNode;
            }
        else
            {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            }
    printf("%d inserted at beginning.\n", value);};

void insertEnd(int value) {
    struct Node *newNode = createNewNode(value);
    if(head == NULL)
        {
        head = newNode;
        }
    else
        {
        struct Node *temp = head;
        while(temp->next != NULL)
            {
            temp = temp->next;
            }
        temp->next = newNode;
        newNode->prev = temp;
        }
    printf("%d inserted at end.\n", value);};


void deleteBegg() {
    if(head == NULL)
        {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
        }
    struct Node *temp = head;
    head = head->next;
    if(head != NULL)
        {
        head->prev = NULL;
        }
    free(temp);
    printf("Node deleted from beginning.\n");};


void deleteEnd() {
    if(head == NULL)
        {
        printf("List is empty. Cannot delete from end.\n");
        return;
        }
    struct Node *temp = head;
    while(temp->next != NULL)
        {
        temp = temp->next;
        }
    if(temp->prev != NULL)
        {
        temp->prev->next = NULL;
        }
    else
        {
        head = NULL;
        }
    free(temp);
    printf("Node deleted from end.\n");};

void display() {
    if(head == NULL)
        {
        printf("List is empty.\n");
        return;
        }
    struct Node *temp = head;
    printf("Doubly Linked List (Forward): ");
    while(temp != NULL)
        {
        printf("%d ", temp->data);
        temp = temp->next;
        }
    printf("\n");};

void displayrev() {
    if(head == NULL)
        {
        printf("List is empty.\n");
        return;
        }
    struct Node *temp = head;
    while(temp->next != NULL)
        {
        temp = temp->next;
        }
    printf("Doubly Linked List (Reverse): ");
    while(temp != NULL)
        {
        printf("%d ", temp->data);
        temp = temp->prev;
        }
    printf("\n");};
    
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL , *temp , *prev , *newnode ;

void create();
void insertbeginning();
void insertend();
void deletebeginning();
void deleteend();
void display();


void main() {
    int choice = 0;

    printf("SINGLY LINKED LIST\n1. CREATE\n2. INSERT AT BEGINNING\n3. INSERT AT END\n4. DELETE FROM BEGINNING\n5. DELETE FROM END\n6. DISPLAY\n7. EXIT");
    
    while (choice!=7) {
        printf("\nEnter your choice = ");
        scanf("%d" , &choice);

        switch (choice)
        {
            case 1:
            create();
            break;

            case 2:
            insertbeginning();
            break;

            case 3:
            insertend();
            break;

            case 4:
            deletebeginning();
            break;

            case 5:
            deleteend();
            break;

            case 6:
            display();
            break;

            case 7:
            printf("thanks for using!");
            break;

        }
    }
}

void create() {
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter number to create node : ");
    scanf("%d",  &newnode->data);

    if(head == NULL)
    {
    head = newnode;
    }
    else
        {
            temp = head;
            while(temp->next != NULL)
            {
            temp = temp->next;
            }
            temp->next = newnode;
         }
        }

void insertbeginning() {
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter number to insert at beginning : ");
    scanf("%d",  &newnode->data);

    if(head == NULL)
    {
        head = newnode;
    }
    else
        {
            newnode->next = head;
            head = newnode;
         }
        }

void insertend() {
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void deletebeginning() {
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteend() {
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void display() {
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}
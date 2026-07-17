#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int front = -1;
int rear = -1;
int queue [MAX];

void enque();
void deque();
void display();

void main() {

int choice;
printf("\nQUEUE USING ADT\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
while(choice !=4) {


printf("\nEnter your choice = ");
scanf("%d" , &choice);

switch (choice) {

    case 1:
    enque();
    break;

    case 2:
    deque();
    break;

    case 3:
    display();
    break;

    case 4:
    printf("Thanks for using!!\n");
    break;

}

}
}

void enque() {

    int num;

    if(rear==MAX-1){
        printf("\nQUEUE IS FULL\n");
    }

    else {
        printf("Enter number you want to add : ");
        scanf("%d" , &num);

        if(front==-1) {
            front=0;
            rear++;
            queue[rear] = num;
            printf("Inserted element is : %d\n" , queue[rear]);
        }

        else {
            rear++;
            queue[rear] = num;
            printf("Inserted element is : %d\n" , queue[rear]);
        }
    }
}

void deque () {
    if (front==-1||front>rear){
        printf("QUEUE IS EMPTY!!\n");
    }

    else {
        printf("Deleted element is : %d\n" , queue[front]);
        front++;

        if(front>rear) {
            front=-1;
            rear =-1;
        }
    }
}

void display() {
    if (front==-1){
        printf("QUEUE IS EMPTY!!\n");
    }

    else {
        for(int i = front ; i <= rear ; i++) {
            printf("%d ",queue[i]);
            printf("\n");
        }
    }
}

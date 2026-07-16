#include <stdio.h>
#include <stdlib.h>
# define MAX 6

void push();
void pop();
void peek();
void display();

int stack[MAX];
int top = -1;

void main() {
int choice;
printf("***ARRAY STACK***\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");

do{

   printf("Enter your choice : ");
   scanf("%d" , &choice);

   switch (choice) {

   case 1 :
   push();
   break;

   case 2:
   pop();
   break;

   case 3 :
   peek();
   break;

   case 4:
   display();
   break;

   case 5:
   printf("Thank you for choosing us!!!!\n");

   }

} while(choice!=5); system("clear"); }

void push() {

   int num;
   if(top == MAX -1) {
   printf("STACJK OVERFLOWED\n");
   }
   else {
   printf("Enter number you want to add to stack : ");
   scanf("%d" ,&num);
   top++;
   stack[top]= num;
   printf("The added element is : %d\n", stack[top]);
   }

}

void pop() {

   if(top==-1) {printf("Stack is empty\n");}
   else {
   printf("THe removed element is : %d\n", stack[top]);
   top--;
   }

}

void peek() {

   if(top==-1) {printf("Stack is empty\n");}
   else {
   printf("The top most element is : %d\n", stack[top]);
   }

}

void display () {

   if(top==-1) {printf("Stack is empty\n");}
   else {
   for(int i = top ; i >=0 ; i--){
   printf("%d\n",stack[i]);
   }
   }

}

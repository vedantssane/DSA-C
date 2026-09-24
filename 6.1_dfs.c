#include <stdio.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top =-1;
int n;

void push(int value) {
    if(top==MAX-1) {
        printf("STACK OVERFLOW\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if(top==-1) {
        return -1;
    }
    else {
        return stack[top--];
    }
}

int isEmpty(){
    return (top==-1);
}

void DFS (int start) {
    int i , vertex;
    push(start);

    while(!isEmpty()) {
        vertex = pop();
        
        if(!visited[vertex])  {
            visited[vertex] = 1;

            printf("%d ", vertex);

            for(i=n-1;i>=0;i--) {
                if(graph[vertex][i]==1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
}

void main() {
    int i , j, start;

    printf("Enter number of vertices : ");
    scanf("%d" , &n);

    printf("Enter adjacency matrix : ");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i=0;i<n;i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex : ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

}

